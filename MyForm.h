#pragma once
#include "Catalogue.h"
#include "PaperBook.h"
#include "CartItem.h"
#include "Cart.h"

namespace BookStore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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


	private: System::Windows::Forms::Label^ ChosenBookLabel;

		   System::Windows::Forms::Button^ AddToCart;
	private: System::Windows::Forms::Label^ TotalPriceLabel;

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
	private: System::Windows::Forms::ListView^ CartList;
	private: System::Windows::Forms::Panel^ ShopPanel;
	private: System::Windows::Forms::Panel^ CartPanel;
	private: System::Windows::Forms::Button^ PurchaseButton;
	private: System::Windows::Forms::Button^ GoToShopButton;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::Label^ DebugLabel;
	private:
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
			this->GoToShopButton = (gcnew System::Windows::Forms::Button());
			this->PurchaseButton = (gcnew System::Windows::Forms::Button());
			this->DebugLabel = (gcnew System::Windows::Forms::Label());
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
			this->ChosenBookLabel->Location = System::Drawing::Point(445, 590);
			this->ChosenBookLabel->MinimumSize = System::Drawing::Size(250, 40);
			this->ChosenBookLabel->Name = L"ChosenBookLabel";
			this->ChosenBookLabel->Size = System::Drawing::Size(250, 40);
			this->ChosenBookLabel->TabIndex = 1;
			this->ChosenBookLabel->Text = L"Chose Your Book!";
			this->ChosenBookLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddToCart
			// 
			this->AddToCart->Location = System::Drawing::Point(6, 3);
			this->AddToCart->Name = L"AddToCart";
			this->AddToCart->Size = System::Drawing::Size(250, 61);
			this->AddToCart->TabIndex = 2;
			this->AddToCart->Text = L"Add to Cart";
			this->AddToCart->UseVisualStyleBackColor = true;
			this->AddToCart->Click += gcnew System::EventHandler(this, &MyForm::AddToCart_Click);
			// 
			// TotalPriceLabel
			// 
			this->TotalPriceLabel->AutoSize = true;
			this->TotalPriceLabel->BackColor = System::Drawing::Color::White;
			this->TotalPriceLabel->Location = System::Drawing::Point(700, 590);
			this->TotalPriceLabel->MinimumSize = System::Drawing::Size(100, 40);
			this->TotalPriceLabel->Name = L"TotalPriceLabel";
			this->TotalPriceLabel->Size = System::Drawing::Size(100, 40);
			this->TotalPriceLabel->TabIndex = 3;
			this->TotalPriceLabel->Text = L"Total Price";
			this->TotalPriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// goToCart
			// 
			this->goToCart->Location = System::Drawing::Point(260, 3);
			this->goToCart->Name = L"goToCart";
			this->goToCart->Size = System::Drawing::Size(101, 61);
			this->goToCart->TabIndex = 4;
			this->goToCart->Text = L"Go to Cart";
			this->goToCart->UseVisualStyleBackColor = true;
			// 
			// MainPanel
			// 
			this->MainPanel->Location = System::Drawing::Point(12, 12);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Size = System::Drawing::Size(808, 556);
			this->MainPanel->TabIndex = 0;
			this->MainPanel->Visible = false;
			// 
			// Tab
			// 
			this->Tab->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->Tab->Controls->Add(this->tabPage1);
			this->Tab->Controls->Add(this->tabPage2);
			this->Tab->Location = System::Drawing::Point(12, 12);
			this->Tab->Name = L"Tab";
			this->Tab->SelectedIndex = 0;
			this->Tab->Size = System::Drawing::Size(808, 573);
			this->Tab->TabIndex = 1;
			this->Tab->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Tab_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->storeList);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(800, 541);
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
			this->storeList->Location = System::Drawing::Point(-4, 0);
			this->storeList->Name = L"storeList";
			this->storeList->Size = System::Drawing::Size(805, 598);
			this->storeList->TabIndex = 0;
			this->storeList->UseCompatibleStateImageBehavior = false;
			this->storeList->View = System::Windows::Forms::View::Details;
			this->storeList->Click += gcnew System::EventHandler(this, &MyForm::storeList_Click);
			this->storeList->DoubleClick += gcnew System::EventHandler(this, &MyForm::StoreList_DoubleClick);
			// 
			// Book
			// 
			this->Book->Text = L"Book";
			this->Book->Width = 250;
			// 
			// Author
			// 
			this->Author->Text = L"Author";
			this->Author->Width = 250;
			// 
			// Category
			// 
			this->Category->Text = L"Category";
			this->Category->Width = 200;
			// 
			// Price
			// 
			this->Price->Text = L"Price";
			this->Price->Width = 100;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->CartList);
			this->tabPage2->Location = System::Drawing::Point(4, 28);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(800, 541);
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
			this->CartList->Location = System::Drawing::Point(-4, 0);
			this->CartList->Name = L"CartList";
			this->CartList->Size = System::Drawing::Size(808, 598);
			this->CartList->TabIndex = 1;
			this->CartList->UseCompatibleStateImageBehavior = false;
			this->CartList->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Book";
			this->columnHeader1->Width = 225;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Author";
			this->columnHeader2->Width = 225;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Category";
			this->columnHeader3->Width = 200;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Price";
			this->columnHeader4->Width = 100;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"#";
			// 
			// ShopPanel
			// 
			this->ShopPanel->BackColor = System::Drawing::Color::Transparent;
			this->ShopPanel->Controls->Add(this->AddToCart);
			this->ShopPanel->Controls->Add(this->goToCart);
			this->ShopPanel->Location = System::Drawing::Point(439, 630);
			this->ShopPanel->Name = L"ShopPanel";
			this->ShopPanel->Size = System::Drawing::Size(364, 71);
			this->ShopPanel->TabIndex = 1;
			// 
			// CartPanel
			// 
			this->CartPanel->BackColor = System::Drawing::Color::Transparent;
			this->CartPanel->Controls->Add(this->GoToShopButton);
			this->CartPanel->Controls->Add(this->PurchaseButton);
			this->CartPanel->Location = System::Drawing::Point(439, 630);
			this->CartPanel->Name = L"CartPanel";
			this->CartPanel->Size = System::Drawing::Size(364, 71);
			this->CartPanel->TabIndex = 2;
			this->CartPanel->Visible = false;
			// 
			// GoToShopButton
			// 
			this->GoToShopButton->Location = System::Drawing::Point(260, 3);
			this->GoToShopButton->Name = L"GoToShopButton";
			this->GoToShopButton->Size = System::Drawing::Size(101, 61);
			this->GoToShopButton->TabIndex = 4;
			this->GoToShopButton->Text = L"Go to Shop";
			this->GoToShopButton->UseVisualStyleBackColor = true;
			// 
			// PurchaseButton
			// 
			this->PurchaseButton->Location = System::Drawing::Point(6, 3);
			this->PurchaseButton->Name = L"PurchaseButton";
			this->PurchaseButton->Size = System::Drawing::Size(250, 61);
			this->PurchaseButton->TabIndex = 2;
			this->PurchaseButton->Text = L"Purchase";
			this->PurchaseButton->UseVisualStyleBackColor = true;
			// 
			// DebugLabel
			// 
			this->DebugLabel->AutoSize = true;
			this->DebugLabel->Location = System::Drawing::Point(52, 594);
			this->DebugLabel->MinimumSize = System::Drawing::Size(100, 100);
			this->DebugLabel->Name = L"DebugLabel";
			this->DebugLabel->Size = System::Drawing::Size(100, 100);
			this->DebugLabel->TabIndex = 4;
			this->DebugLabel->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(832, 703);
			this->Controls->Add(this->DebugLabel);
			this->Controls->Add(this->CartPanel);
			this->Controls->Add(this->TotalPriceLabel);
			this->Controls->Add(this->Tab);
			this->Controls->Add(this->ChosenBookLabel);
			this->Controls->Add(this->MainPanel);
			this->Controls->Add(this->ShopPanel);
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
		System::Void StoreList_DoubleClick(System::Object^ sender, System::EventArgs^ e)
		{
			BookStore::Book^ CurrentBook = dynamic_cast<BookStore::Book^>(storeList->SelectedItems[0]->Tag);
			ChosenBookLabel->Text = CurrentBook->GetName();
		}

		System::Void AddToCart_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (storeList->SelectedItems->Count > 0)
			{
				for each (ListViewItem ^ Item in storeList->SelectedItems)
				{
					BookStore::Book^ SelectedBook = dynamic_cast<BookStore::Book^>(Item->Tag);
					int BookIndex = storeList->SelectedItems[0]->Index;

					ListViewItem^ ExistingItem = FindCartItemByID(SelectedBook->GetID());

					if (ExistingItem)
					{
						CartItem^ cartItem = dynamic_cast<CartItem^>(ExistingItem->Tag);
						cartItem->IncrementQuantity();

						UpdateNumericUpDownValue(cartItem->GetID(), cartItem->GetQuantity());
						TotalPrice += cartItem->GetPrice();
					}
					else
					{
						CartItem^ NewCartItem = gcnew CartItem(SelectedBook);
						ShopCart->AddNewItem(NewCartItem);

						DebugLabel->Text = ShopCart->GetSize().ToString();

						ListViewItem^ Item = gcnew ListViewItem(NewCartItem->GetName(), CartList->Items->Count);

						String^ LinkToImage = SelectedBook->GetImageLink();
						CartImageList->Images->Add(Image::FromFile(LinkToImage));

						Item->SubItems->Add(NewCartItem->GetAuthor());
						Item->SubItems->Add(NewCartItem->GetGenre());
						Item->SubItems->Add(NewCartItem->GetPrice().ToString("C"));
						Item->SubItems->Add(NewCartItem->GetQuantity().ToString());

						Item->Tag = NewCartItem;

						TotalPrice += NewCartItem->GetPrice();

						CartList->Items->Add(Item);

						AddNumericUpDownToNumberField(Item);
					}

					ChosenBookLabel->Text = "Chose Your Book!";
					TotalPriceLabel->Text = TotalPrice.ToString("C");
				}
			}
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

		System::Void storeList_Click(System::Object^ sender, System::EventArgs^ e)
		{
			BookStore::Book^ book = dynamic_cast<BookStore::Book^>(storeList->SelectedItems[0]->Tag);
			ChosenBookLabel->Text = book->GetID().ToString();
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

		void MyForm::OnNumericUpDownValueChanged(System::Object^ sender, System::EventArgs^ e)
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

		int GetColumnPosition(ListView^ listView, int columnIndex)
		{
			int position = 0;

			// Ensure the columnIndex is within the range
			if (columnIndex < 0 || columnIndex >= listView->Columns->Count)
			{
				throw gcnew ArgumentOutOfRangeException("columnIndex");
			}

			// Sum the widths of all columns before the specified one
			for (int i = 0; i < columnIndex; i++)
			{
				position += listView->Columns[i]->Width;
			}

			return position;
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
		
		void MyForm::UpdateTotalPrice()
		{
			TotalPrice = 0.0f;
			for each (CartItem^ item in ShopCart->Items)
			{
				TotalPrice += item->GetPrice() * item->GetQuantity();
			}
			TotalPriceLabel->Text = TotalPrice.ToString("C");
		}
	};
};
