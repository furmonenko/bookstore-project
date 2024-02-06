#include "MainPage.h"

namespace BookStore
{
	void MainPage::InitializeStore()
	{
		db = Database::Instance;

		ShopCart = gcnew Cart();
		NumberFields = gcnew Dictionary<int, NumericUpDown^>;

		TotalPrice = 0.0f;

		ShopCatalogue = gcnew Catalogue(db->GetBooks());

		ShopImageList = gcnew ImageList();
		ShopImageList->ImageSize = Drawing::Size(30, 30);

		CartImageList = gcnew ImageList();
		CartImageList->ImageSize = Drawing::Size(30, 30);

		for (size_t i = 0; i < ShopCatalogue->GetSize(); i++)
		{
			if (ShopCatalogue->GetBook(i))
			{
				System::String^ LinkToImage = ShopCatalogue->GetBook(i)->GetImageLink();

				String^ fileName = String::Format("Images/{0}", LinkToImage);

				ShopImageList->Images->Add(System::Drawing::Image::FromFile(fileName));
			}
		}

		storeList->SmallImageList = ShopImageList;
		CartList->SmallImageList = CartImageList;

		for (size_t i = 0; i < ShopCatalogue->GetSize(); i++)
		{
			BookStore::IBook^ currentBook = ShopCatalogue->GetBook(i);
			ListViewItem^ item = gcnew ListViewItem(currentBook->GetName(), i);

			item->SubItems->Add(currentBook->GetAuthor());
			item->SubItems->Add(currentBook->GetGenre());
			item->SubItems->Add(currentBook->GetPrice().ToString("C"));
			item->Tag = currentBook;
			storeList->Items->Add(item);
		}
	}
	void MainPage::AddNewCartItem(BookStore::IBook ^ selectedBook)
	{
		CartItem^ newCartItem = gcnew CartItem(selectedBook);
		ShopCart->AddNewItem(newCartItem);
		AddCartItemToListView(newCartItem, selectedBook);
	}
	void MainPage::AddCartItemToListView(CartItem^ newCartItem, BookStore::IBook^ selectedBook)
	{
		ListViewItem^ listViewItem = CreateListViewItemForCartItem(newCartItem, selectedBook);
		CartList->Items->Add(listViewItem);
		AddNumericUpDownToNumberField(listViewItem);
	}
	void MainPage::AddNumericUpDownToNumberField(ListViewItem^ Item)
	{
		int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();
		if (NumberFields->ContainsKey(ItemID) == false)
		{
			NumericUpDown^ numericUpDown = gcnew NumericUpDown();
			numericUpDown->Minimum = 1;
			numericUpDown->Tag = ItemID;
			NumberFields->Add(ItemID, numericUpDown);
			Controls->Add(NumberFields[ItemID]);
			NumberFields[ItemID]->ValueChanged += gcnew System::EventHandler(this, &MainPage::OnNumericUpDownValueChanged);
		}
		NumberFields[ItemID]->Value = Convert::ToInt32(Item->SubItems[4]->Text);
		NumberFields[ItemID]->Visible = false;
		NumberFields[ItemID]->BringToFront();
		int columnIndex = 4;
		int xPos = GetColumnPosition(CartList, columnIndex) + 15;
		int yPos = Item->Bounds.Y + 45;
		NumberFields[ItemID]->SetBounds(xPos, yPos, 45, 30);
	}
	void MainPage::ProcessCartItem(ListViewItem^ item)
	{
		BookStore::IBook^ selectedBook = dynamic_cast<BookStore::IBook^>(item->Tag);
		ListViewItem^ existingItem = FindCartItemByID(selectedBook->GetID());
		if (existingItem)
		{
			UpdateExistingCartItem(existingItem);
		}
		else
		{
			AddNewCartItem(selectedBook);
		}
	}
	void MainPage::UpdateExistingCartItem(ListViewItem^ existingItem)
	{
		CartItem^ cartItem = dynamic_cast<CartItem^>(existingItem->Tag);
		cartItem->IncrementQuantity();
		UpdateNumericUpDownValue(cartItem->GetID(), cartItem->GetQuantity());
		TotalPrice += cartItem->GetPrice();
	}
	void MainPage::UpdateCartItemQuantity(int itemId, int newQuantity)
	{
		CartItem^ cartItem = ShopCart->FindByID(itemId);
		if (cartItem != nullptr)
		{
			cartItem->SetQuantity(newQuantity);
		}
	}
	void MainPage::UpdateNumericUpDownValue(int ID, int NewValue)
	{
		NumberFields[ID]->Value = NewValue;
	}
	void MainPage::UpdateTotalPrice()
	{
		TotalPrice = 0.0f;
		for each (CartItem ^ item in ShopCart->Items)
		{
			TotalPrice += item->GetPrice() * item->GetQuantity();
		}
		UpdateTotalPriceLabel();
	}
	void MainPage::UpdateTotalPriceLabel()
	{
		TotalPriceLabel->Text = TotalPrice.ToString("C");
	}
	void MainPage::UpdateCartDisplay()
	{
		ChosenBookLabel->Text = "Choose Your Book!";
		UpdateTotalPriceLabel();
	}
	void MainPage::RemoveCartItem(const int ID)
	{
		if (ShopCart->RemoveByID(ID))
		{
			ListViewItem^ itemToRemove = nullptr;
			for each (ListViewItem ^ item in CartList->Items)
			{
				CartItem^ cartItem = dynamic_cast<CartItem^>(item->Tag);
				if (cartItem && cartItem->GetID() == ID)
				{
					itemToRemove = item;
					break;
				}
			}
			if (itemToRemove != nullptr)
			{
				CartList->Items->Remove(itemToRemove);
				if (NumberFields->ContainsKey(ID))
				{
					Controls->Remove(NumberFields[ID]);
					NumberFields->Remove(ID);
				}
			}
			RedrawNumericUpDowns();
			UpdateTotalPrice();
		}
	}
	void MainPage::RedrawNumericUpDowns()
	{
		for each (ListViewItem ^ Item in CartList->Items)
		{
			CartItem^ cartItem = safe_cast<CartItem^>(Item->Tag);
			int itemId = cartItem->GetID();
			if (NumberFields->ContainsKey(itemId))
			{
				NumericUpDown^ numericUpDown = NumberFields[itemId];
				PositionNumericUpDown(numericUpDown, Item);
			}
		}
	}
	void MainPage::PositionNumericUpDown(NumericUpDown^ numericUpDown, ListViewItem^ listViewItem)
	{
		int columnIndex = 4;
		int xPos = GetColumnPosition(CartList, columnIndex) + 15;
		int yPos = listViewItem->Bounds.Y + 45;
		numericUpDown->SetBounds(xPos, yPos, numericUpDown->Width, numericUpDown->Height);
	}
	ListViewItem^ MainPage::FindCartItemByID(const int id)
	{
		for each (ListViewItem ^ item in CartList->Items)
		{
			if (item->Tag)
			{
				CartItem^ SelectedItem = safe_cast<CartItem^>(item->Tag);
				if (SelectedItem->GetID() == id)
				{
					return item;
				}
			}
		}
		return nullptr;
	}
	ListViewItem^ MainPage::CreateListViewItemForCartItem(CartItem^ cartItem, BookStore::IBook^ selectedBook)
	{
		ListViewItem^ item = gcnew ListViewItem(cartItem->GetName());
		item->SubItems->Add(cartItem->GetAuthor());
		item->SubItems->Add(cartItem->GetGenre());
		item->SubItems->Add(cartItem->GetPrice().ToString("C"));
		item->SubItems->Add(cartItem->GetQuantity().ToString());
		item->Tag = cartItem;
		String^ linkToImage = String::Format("Images/{0}", selectedBook->GetImageLink());
		CartImageList->Images->Add(System::Drawing::Image::FromFile(linkToImage));
		item->ImageIndex = CartImageList->Images->Count - 1;
		TotalPrice += cartItem->GetPrice();
		return item;
	}
	int MainPage::GetColumnPosition(ListView^ listView, int columnIndex)
	{
		int position = 0;
		if (columnIndex < 0 || columnIndex >= listView->Columns->Count)
		{
			throw gcnew ArgumentOutOfRangeException("columnIndex");
		}
		for (int i = 0; i < columnIndex; i++)
		{
			position += listView->Columns[i]->Width;
		}
		return position;
	}
	void MainPage::SortListView(ListView^ listView, int column)
	{
		static bool ascending = true;
		ascending = !ascending;
		listView->ListViewItemSorter = gcnew ListViewItemComparer(column, ascending);
		Console::WriteLine(column);
		listView->Sort();
		RedrawNumericUpDowns();
	}
	void MainPage::CreatePDFReceipt(String^ filePath)
	{
		{
			try
			{
				DateTime now = DateTime::Now;
				String^ dateTimeStr = now.ToString("yyyy-MM-dd_HH-mm-ss");
				String^ formattedDateTime = now.ToString("yyyy-MM-dd HH:mm:ss");

				String^ newFilePath = String::Format("{0}_{1}.pdf", filePath, dateTimeStr);

				Document^ document = gcnew Document(PageSize::LETTER);

				PdfWriter::GetInstance(document, gcnew System::IO::FileStream(newFilePath, System::IO::FileMode::Create));

				document->Open();

				document->Add(gcnew Paragraph("Receipt"));
				document->Add(gcnew Paragraph("-------------------------------"));

				document->Add(gcnew Paragraph("Date and Time: " + formattedDateTime));
				document->Add(gcnew Paragraph("-------------------------------"));

				for each (CartItem ^ item in ShopCart->Items)
				{
					String^ itemLine = String::Format("{0} - {1} PLN x {2}", item->GetName(), item->GetPrice(), item->GetQuantity());
					document->Add(gcnew Paragraph(itemLine));
				}

				document->Add(gcnew Paragraph("-------------------------------"));

				float VAT = TotalPrice * .23;
				String^ totalPriceLine = String::Format("Total Price: {0} PLN (Included 23% VAT - {1} PLN)", TotalPrice, VAT);
				document->Add(gcnew Paragraph(totalPriceLine));

				MessageBox::Show("PDF receipt created successfully at " + newFilePath);

				document->Close();
			}
			catch (DocumentException^ de)
			{
				MessageBox::Show("IOException: " + de->Message);
			}
			catch (System::IO::IOException^ ioe)
			{
				MessageBox::Show("IOException: " + ioe->Message);
			}
			catch (System::IO::FileNotFoundException^ ex)
			{
				MessageBox::Show("FileNotFoundException: " + ex->Message);
			}
		}
	}


	// Event Handlers
	System::Void MainPage::AddToCart_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (storeList->SelectedItems->Count > 0)
		{
			for each (ListViewItem ^ item in storeList->SelectedItems)
			{
				ProcessCartItem(item);
			}
			UpdateCartDisplay();
		}
	}
	System::Void MainPage::OnNumericUpDownValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		NumericUpDown^ numericUpDown = safe_cast<NumericUpDown^>(sender);
		if (numericUpDown != nullptr)
		{
			int ID = static_cast<int>(numericUpDown->Tag);
			CartItem^ SelectedItem = ShopCart->FindByID(ID);
			if (SelectedItem != nullptr)
			{
				UpdateCartItemQuantity(SelectedItem->GetID(), Convert::ToInt32(numericUpDown->Value));
				UpdateTotalPrice();
			}
		}
	}
	System::Void MainPage::RemoveItemButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		for each (ListViewItem ^ Item in CartList->SelectedItems)
		{
			int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();
			RemoveCartItem(ItemID);
		}
	}
	System::Void MainPage::Tab_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (Tab->SelectedIndex == 1)
		{
			CartPanel->Visible = true;
			for each (ListViewItem ^ Item in CartList->Items)
			{
				int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();
				if (NumberFields->ContainsKey(ItemID))
				{
					NumberFields[ItemID]->Visible = true;
				}
			}
		}
		else
		{
			CartPanel->Visible = false;
			for each (ListViewItem ^ Item in CartList->Items)
			{
				int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();
				if (NumberFields->ContainsKey(ItemID))
				{
					NumberFields[ItemID]->Visible = false;
				}
			}
		}
	}
	System::Void MainPage::CartList_ColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e)
	{
		ListView^ listView = safe_cast<ListView^>(sender);
		SortListView(listView, e->Column);
	}
	System::Void MainPage::PurchaseButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		CreatePDFReceipt("C:\\Users\\zfurm\\Downloads\\Receipt_");
	}
	System::Void MainPage::StoreList_DoubleClick(System::Object^ sender, System::EventArgs^ e)
	{
		BookStore::IBook^ CurrentBook = dynamic_cast<BookStore::IBook^>(storeList->SelectedItems[0]->Tag);
		ChosenBookLabel->Text = CurrentBook->GetName();
	}
	System::Void MainPage::storeList_Click(System::Object^ sender, System::EventArgs^ e)
	{
		BookStore::IBook^ book = dynamic_cast<BookStore::IBook^>(storeList->SelectedItems[0]->Tag);
		ChosenBookLabel->Text = book->GetID().ToString();
	}
}
