#pragma once
#include "Catalogue.h"
#include "PaperBook.h"
#include "CartItem.h"
#include "Cart.h"
#include "ListViewItemSorter.h"
#include "Database.h"

namespace BookStore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace iTextSharp::text;
	using namespace iTextSharp::text::pdf;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			InitializeStore();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		void InitializeStore();

	private:
		BookStore::Catalogue^ ShopCatalogue;
		BookStore::Cart^ ShopCart;

		ImageList^ ShopImageList;
		ImageList^ CartImageList;

		double TotalPrice;

		Dictionary<int, NumericUpDown^>^ NumberFields;

		Database^ db;

	private:
		System::Windows::Forms::Label^ ChosenBookLabel;
		System::Windows::Forms::Button^ AddToCart;
		System::Windows::Forms::Label^ TotalPriceLabel;
		System::Windows::Forms::Button^ goToCart;
		System::Windows::Forms::Panel^ MainPanel;
		System::Windows::Forms::TabControl^ Tab;
		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::ListView^ storeList;
		System::Windows::Forms::ColumnHeader^ Book;
		System::Windows::Forms::ColumnHeader^ Author;
		System::Windows::Forms::ColumnHeader^ Category;
		System::Windows::Forms::ColumnHeader^ Price;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::ListView^ CartList;
		System::Windows::Forms::Panel^ ShopPanel;
		System::Windows::Forms::Panel^ CartPanel;
		System::Windows::Forms::Button^ PurchaseButton;
		System::Windows::Forms::Button^ GoToShopButton;
		System::Windows::Forms::ColumnHeader^ columnHeader1;
		System::Windows::Forms::ColumnHeader^ columnHeader2;
		System::Windows::Forms::ColumnHeader^ columnHeader3;
		System::Windows::Forms::ColumnHeader^ columnHeader4;
		System::Windows::Forms::ColumnHeader^ columnHeader5;

		System::Windows::Forms::Button^ RemoveItemButton;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ChosenBookLabel = (gcnew System::Windows::Forms::Label());
			this->AddToCart = (gcnew System::Windows::Forms::Button());
			this->TotalPriceLabel = (gcnew System::Windows::Forms::Label());
			this->goToCart = (gcnew System::Windows::Forms::Button());
			this->MainPanel = (gcnew System::Windows::Forms::Panel());
			this->Tab = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->storeList = (gcnew System::Windows::Forms::ListView());
			this->Book = (gcnew System::Windows::Forms::ColumnHeader());
			this->Author = (gcnew System::Windows::Forms::ColumnHeader());
			this->Category = (gcnew System::Windows::Forms::ColumnHeader());
			this->Price = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->CartList = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->ShopPanel = (gcnew System::Windows::Forms::Panel());
			this->CartPanel = (gcnew System::Windows::Forms::Panel());
			this->RemoveItemButton = (gcnew System::Windows::Forms::Button());
			this->GoToShopButton = (gcnew System::Windows::Forms::Button());
			this->PurchaseButton = (gcnew System::Windows::Forms::Button());
			this->Tab->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->ShopPanel->SuspendLayout();
			this->CartPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ChosenBookLabel
			// 
			this->ChosenBookLabel->AutoSize = true;
			this->ChosenBookLabel->BackColor = System::Drawing::Color::White;
			this->ChosenBookLabel->Location = System::Drawing::Point(334, 479);
			this->ChosenBookLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ChosenBookLabel->MinimumSize = System::Drawing::Size(188, 32);
			this->ChosenBookLabel->Name = L"ChosenBookLabel";
			this->ChosenBookLabel->Size = System::Drawing::Size(188, 32);
			this->ChosenBookLabel->TabIndex = 1;
			this->ChosenBookLabel->Text = L"Chose Your Book!";
			this->ChosenBookLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddToCart
			// 
			this->AddToCart->Location = System::Drawing::Point(4, 2);
			this->AddToCart->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AddToCart->Name = L"AddToCart";
			this->AddToCart->Size = System::Drawing::Size(188, 50);
			this->AddToCart->TabIndex = 2;
			this->AddToCart->Text = L"Add to Cart";
			this->AddToCart->UseVisualStyleBackColor = true;
			this->AddToCart->Click += gcnew System::EventHandler(this, &MyForm::AddToCart_Click);
			// 
			// TotalPriceLabel
			// 
			this->TotalPriceLabel->AutoSize = true;
			this->TotalPriceLabel->BackColor = System::Drawing::Color::White;
			this->TotalPriceLabel->Location = System::Drawing::Point(525, 479);
			this->TotalPriceLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TotalPriceLabel->MinimumSize = System::Drawing::Size(75, 32);
			this->TotalPriceLabel->Name = L"TotalPriceLabel";
			this->TotalPriceLabel->Size = System::Drawing::Size(75, 32);
			this->TotalPriceLabel->TabIndex = 3;
			this->TotalPriceLabel->Text = L"Total Price";
			this->TotalPriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// goToCart
			// 
			this->goToCart->Location = System::Drawing::Point(195, 2);
			this->goToCart->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->goToCart->Name = L"goToCart";
			this->goToCart->Size = System::Drawing::Size(76, 50);
			this->goToCart->TabIndex = 4;
			this->goToCart->Text = L"Go to Cart";
			this->goToCart->UseVisualStyleBackColor = true;
			// 
			// MainPanel
			// 
			this->MainPanel->Location = System::Drawing::Point(9, 10);
			this->MainPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Size = System::Drawing::Size(606, 452);
			this->MainPanel->TabIndex = 0;
			this->MainPanel->Visible = false;
			// 
			// Tab
			// 
			this->Tab->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->Tab->Controls->Add(this->tabPage1);
			this->Tab->Controls->Add(this->tabPage2);
			this->Tab->Location = System::Drawing::Point(9, 10);
			this->Tab->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Tab->Name = L"Tab";
			this->Tab->SelectedIndex = 0;
			this->Tab->Size = System::Drawing::Size(606, 466);
			this->Tab->TabIndex = 1;
			this->Tab->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Tab_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->storeList);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage1->Size = System::Drawing::Size(598, 437);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Shop";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// storeList
			// 
			this->storeList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->storeList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Book, this->Author,
					this->Category, this->Price
			});
			this->storeList->HideSelection = false;
			this->storeList->Location = System::Drawing::Point(-3, 0);
			this->storeList->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->storeList->Name = L"storeList";
			this->storeList->Size = System::Drawing::Size(604, 486);
			this->storeList->TabIndex = 0;
			this->storeList->UseCompatibleStateImageBehavior = false;
			this->storeList->View = System::Windows::Forms::View::Details;
			this->storeList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MyForm::CartList_ColumnClick);
			this->storeList->Click += gcnew System::EventHandler(this, &MyForm::storeList_Click);
			this->storeList->DoubleClick += gcnew System::EventHandler(this, &MyForm::StoreList_DoubleClick);
			// 
			// Book
			// 
			this->Book->Text = L"Book";
			this->Book->Width = 200;
			// 
			// Author
			// 
			this->Author->Text = L"Author";
			this->Author->Width = 150;
			// 
			// Category
			// 
			this->Category->Text = L"Category";
			this->Category->Width = 150;
			// 
			// Price
			// 
			this->Price->Text = L"Price";
			this->Price->Width = 100;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->CartList);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabPage2->Size = System::Drawing::Size(598, 437);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Cart";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// CartList
			// 
			this->CartList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CartList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5
			});
			this->CartList->HideSelection = false;
			this->CartList->Location = System::Drawing::Point(-3, 0);
			this->CartList->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CartList->Name = L"CartList";
			this->CartList->Size = System::Drawing::Size(606, 486);
			this->CartList->TabIndex = 1;
			this->CartList->UseCompatibleStateImageBehavior = false;
			this->CartList->View = System::Windows::Forms::View::Details;
			this->CartList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MyForm::CartList_ColumnClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Book";
			this->columnHeader1->Width = 150;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Author";
			this->columnHeader2->Width = 125;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Category";
			this->columnHeader3->Width = 125;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Price";
			this->columnHeader4->Width = 125;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"#";
			this->columnHeader5->Width = 75;
			// 
			// ShopPanel
			// 
			this->ShopPanel->BackColor = System::Drawing::Color::Transparent;
			this->ShopPanel->Controls->Add(this->AddToCart);
			this->ShopPanel->Controls->Add(this->goToCart);
			this->ShopPanel->Location = System::Drawing::Point(329, 512);
			this->ShopPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ShopPanel->Name = L"ShopPanel";
			this->ShopPanel->Size = System::Drawing::Size(273, 58);
			this->ShopPanel->TabIndex = 1;
			// 
			// CartPanel
			// 
			this->CartPanel->BackColor = System::Drawing::Color::Transparent;
			this->CartPanel->Controls->Add(this->RemoveItemButton);
			this->CartPanel->Controls->Add(this->GoToShopButton);
			this->CartPanel->Controls->Add(this->PurchaseButton);
			this->CartPanel->Location = System::Drawing::Point(273, 512);
			this->CartPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CartPanel->Name = L"CartPanel";
			this->CartPanel->Size = System::Drawing::Size(329, 58);
			this->CartPanel->TabIndex = 2;
			this->CartPanel->Visible = false;
			// 
			// RemoveItemButton
			// 
			this->RemoveItemButton->BackColor = System::Drawing::Color::IndianRed;
			this->RemoveItemButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RemoveItemButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->RemoveItemButton->Location = System::Drawing::Point(3, 2);
			this->RemoveItemButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RemoveItemButton->Name = L"RemoveItemButton";
			this->RemoveItemButton->Size = System::Drawing::Size(53, 50);
			this->RemoveItemButton->TabIndex = 5;
			this->RemoveItemButton->Text = L"Remove Item";
			this->RemoveItemButton->UseVisualStyleBackColor = false;
			this->RemoveItemButton->Click += gcnew System::EventHandler(this, &MyForm::RemoveItemButton_Click);
			// 
			// GoToShopButton
			// 
			this->GoToShopButton->Location = System::Drawing::Point(251, 2);
			this->GoToShopButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GoToShopButton->Name = L"GoToShopButton";
			this->GoToShopButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->GoToShopButton->Size = System::Drawing::Size(76, 50);
			this->GoToShopButton->TabIndex = 4;
			this->GoToShopButton->Text = L"Go to Shop";
			this->GoToShopButton->UseVisualStyleBackColor = true;
			// 
			// PurchaseButton
			// 
			this->PurchaseButton->Location = System::Drawing::Point(61, 2);
			this->PurchaseButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PurchaseButton->Name = L"PurchaseButton";
			this->PurchaseButton->Size = System::Drawing::Size(188, 50);
			this->PurchaseButton->TabIndex = 2;
			this->PurchaseButton->Text = L"Purchase";
			this->PurchaseButton->UseVisualStyleBackColor = true;
			this->PurchaseButton->Click += gcnew System::EventHandler(this, &MyForm::PurchaseButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(624, 571);
			this->Controls->Add(this->CartPanel);
			this->Controls->Add(this->TotalPriceLabel);
			this->Controls->Add(this->Tab);
			this->Controls->Add(this->ChosenBookLabel);
			this->Controls->Add(this->MainPanel);
			this->Controls->Add(this->ShopPanel);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"BookStore";
			this->Tab->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ShopPanel->ResumeLayout(false);
			this->CartPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		void AddNewCartItem(BookStore::Book^ selectedBook)
		{
			CartItem^ newCartItem = gcnew CartItem(selectedBook);
			ShopCart->AddNewItem(newCartItem);

			AddCartItemToListView(newCartItem, selectedBook);
		}

		void AddCartItemToListView(CartItem^ newCartItem, BookStore::Book^ selectedBook)
		{
			ListViewItem^ listViewItem = CreateListViewItemForCartItem(newCartItem, selectedBook);
			CartList->Items->Add(listViewItem);
			AddNumericUpDownToNumberField(listViewItem);
		}

		void AddNumericUpDownToNumberField(ListViewItem^ Item)
		{
			int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();

			if (NumberFields->ContainsKey(ItemID) == false)
			{
				NumericUpDown^ numericUpDown = gcnew NumericUpDown();
				numericUpDown->Minimum = 1;

				numericUpDown->Tag = ItemID;

				NumberFields->Add(ItemID, numericUpDown);
				Controls->Add(NumberFields[ItemID]);

				NumberFields[ItemID]->ValueChanged += gcnew System::EventHandler(this, &MyForm::OnNumericUpDownValueChanged);
			}

			NumberFields[ItemID]->Value = Convert::ToInt32(Item->SubItems[4]->Text);
			NumberFields[ItemID]->Visible = false;
			NumberFields[ItemID]->BringToFront();

			int columnIndex = 4;
			int xPos = GetColumnPosition(CartList, columnIndex) + 15;
			int yPos = Item->Bounds.Y + 45;
			NumberFields[ItemID]->SetBounds(xPos, yPos, 45, 30);
		}

		void ProcessCartItem(ListViewItem^ item)
		{
			BookStore::Book^ selectedBook = dynamic_cast<BookStore::Book^>(item->Tag);
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

		void UpdateExistingCartItem(ListViewItem^ existingItem)
		{
			CartItem^ cartItem = dynamic_cast<CartItem^>(existingItem->Tag);
			cartItem->IncrementQuantity();

			UpdateNumericUpDownValue(cartItem->GetID(), cartItem->GetQuantity());
			TotalPrice += cartItem->GetPrice();
		}

		void UpdateCartItemQuantity(int itemId, int newQuantity)
		{
			CartItem^ cartItem = ShopCart->FindByID(itemId);

			if (cartItem != nullptr)
			{
				cartItem->SetQuantity(newQuantity);
			}
		}

		void UpdateNumericUpDownValue(int ID, int NewValue)
		{
			NumberFields[ID]->Value = NewValue;
		}

		void UpdateTotalPrice()
		{
			TotalPrice = 0.0f;
			for each (CartItem ^ item in ShopCart->Items)
			{
				TotalPrice += item->GetPrice() * item->GetQuantity();
			}
			UpdateTotalPriceLabel();
		}

		void UpdateTotalPriceLabel()
		{
			TotalPriceLabel->Text = TotalPrice.ToString("C");
		}

		void UpdateCartDisplay()
		{
			ChosenBookLabel->Text = "Chose Your Book!";
			UpdateTotalPriceLabel();
		}

		void RemoveCartItem(const int ID)
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

		void RedrawNumericUpDowns()
		{
			for each (ListViewItem ^ Item in CartList->Items)
			{
				CartItem^ cartItem = safe_cast<CartItem^>(Item->Tag);
				int itemId = cartItem->GetID(); // Assuming the Tag stores the item ID

				if (NumberFields->ContainsKey(itemId))
				{
					NumericUpDown^ numericUpDown = NumberFields[itemId];
					PositionNumericUpDown(numericUpDown, Item);
				}
			}
		}

		void PositionNumericUpDown(NumericUpDown^ numericUpDown, ListViewItem^ listViewItem)
		{
			int columnIndex = 4;
			int xPos = GetColumnPosition(CartList, columnIndex) + 15;
			int yPos = listViewItem->Bounds.Y + 45;
			numericUpDown->SetBounds(xPos, yPos, numericUpDown->Width, numericUpDown->Height);
		}

		ListViewItem^ FindCartItemByID(const int id)
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

		ListViewItem^ CreateListViewItemForCartItem(CartItem^ cartItem, BookStore::Book^ selectedBook)
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

		int GetColumnPosition(ListView^ listView, int columnIndex)
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

		void SortListView(ListView^ listView, int column)
		{
			static bool ascending = true;

			ascending = !ascending;

			listView->ListViewItemSorter = gcnew ListViewItemComparer(column, ascending);

			Console::WriteLine(column);
			listView->Sort();

			RedrawNumericUpDowns();
		}

		// Events:
		System::Void AddToCart_Click(System::Object^ sender, System::EventArgs^ e)
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
		System::Void OnNumericUpDownValueChanged(System::Object^ sender, System::EventArgs^ e)
		{
			NumericUpDown^ numericUpDown = safe_cast<NumericUpDown^>(sender);

			if (numericUpDown != nullptr)
			{
				CartItem^ SelectedItem = ShopCart->FindByID(static_cast<int>(numericUpDown->Tag));

				if (SelectedItem != nullptr)
				{
					UpdateCartItemQuantity(SelectedItem->GetID(), Convert::ToInt32(numericUpDown->Value));
					UpdateTotalPrice();
				}
			}
		}
		System::Void RemoveItemButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			for each (ListViewItem ^ Item in CartList->SelectedItems)
			{
				int Item_ID = safe_cast<CartItem^>(Item->Tag)->GetID();
				RemoveCartItem(Item_ID);
			}
		}
		System::Void Tab_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (Tab->SelectedIndex == 1)
			{
				CartPanel->Visible = true;

				for each (ListViewItem ^ Item in CartList->Items)
				{
					int ItemID = safe_cast<CartItem^>(Item->Tag)->GetID();

					if (NumberFields->ContainsKey(ItemID) == true)
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

					if (NumberFields->ContainsKey(ItemID) == true)
					{
						NumberFields[ItemID]->Visible = false;
					}
				}
			}
		}
		System::Void CartList_ColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e)
		{
			ListView^ listView = safe_cast<ListView^>(sender);
			SortListView(listView, e->Column);
		}
		System::Void PurchaseButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ Meesage = "Your Receipt is ready! Get it there - " + "C:\\Users\\zfurm\\Downloads\\";
			MessageBox::Show(Meesage);
			CreatePDFReceipt("C:\\Users\\zfurm\\Downloads\\Receipt_");
		}


		// Debugging Functions:
		System::Void StoreList_DoubleClick(System::Object^ sender, System::EventArgs^ e)
		{
			BookStore::Book^ CurrentBook = dynamic_cast<BookStore::Book^>(storeList->SelectedItems[0]->Tag);
			ChosenBookLabel->Text = CurrentBook->GetName();
		}
		System::Void storeList_Click(System::Object^ sender, System::EventArgs^ e)
		{
			BookStore::Book^ book = dynamic_cast<BookStore::Book^>(storeList->SelectedItems[0]->Tag);
			ChosenBookLabel->Text = book->GetID().ToString();
		}

		//
		void CreatePDFReceipt(String^ filePath)
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

	};
};

