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

	public ref class MainPage : public System::Windows::Forms::Form
	{
	public:
		MainPage(void)
		{
			InitializeComponent();
			InitializeStore();
		}
	protected:
		~MainPage()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainPage::typeid));
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
			this->ChosenBookLabel->Location = System::Drawing::Point(445, 590);
			this->ChosenBookLabel->MinimumSize = System::Drawing::Size(251, 39);
			this->ChosenBookLabel->Name = L"ChosenBookLabel";
			this->ChosenBookLabel->Size = System::Drawing::Size(251, 39);
			this->ChosenBookLabel->TabIndex = 1;
			this->ChosenBookLabel->Text = L"Chose Your Book!";
			this->ChosenBookLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AddToCart
			// 
			this->AddToCart->Location = System::Drawing::Point(5, 2);
			this->AddToCart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AddToCart->Name = L"AddToCart";
			this->AddToCart->Size = System::Drawing::Size(251, 62);
			this->AddToCart->TabIndex = 2;
			this->AddToCart->Text = L"Add to Cart";
			this->AddToCart->UseVisualStyleBackColor = true;
			this->AddToCart->Click += gcnew System::EventHandler(this, &MainPage::AddToCart_Click);
			// 
			// TotalPriceLabel
			// 
			this->TotalPriceLabel->AutoSize = true;
			this->TotalPriceLabel->BackColor = System::Drawing::Color::White;
			this->TotalPriceLabel->Location = System::Drawing::Point(700, 590);
			this->TotalPriceLabel->MinimumSize = System::Drawing::Size(100, 39);
			this->TotalPriceLabel->Name = L"TotalPriceLabel";
			this->TotalPriceLabel->Size = System::Drawing::Size(100, 39);
			this->TotalPriceLabel->TabIndex = 3;
			this->TotalPriceLabel->Text = L"Total Price";
			this->TotalPriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// goToCart
			// 
			this->goToCart->Location = System::Drawing::Point(260, 2);
			this->goToCart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->goToCart->Name = L"goToCart";
			this->goToCart->Size = System::Drawing::Size(101, 62);
			this->goToCart->TabIndex = 4;
			this->goToCart->Text = L"Go to Cart";
			this->goToCart->UseVisualStyleBackColor = true;
			// 
			// MainPanel
			// 
			this->MainPanel->Location = System::Drawing::Point(12, 12);
			this->MainPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->Tab->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Tab->Name = L"Tab";
			this->Tab->SelectedIndex = 0;
			this->Tab->Size = System::Drawing::Size(808, 574);
			this->Tab->TabIndex = 1;
			this->Tab->SelectedIndexChanged += gcnew System::EventHandler(this, &MainPage::Tab_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->storeList);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage1->Size = System::Drawing::Size(800, 542);
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
			this->storeList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->storeList->Name = L"storeList";
			this->storeList->Size = System::Drawing::Size(805, 598);
			this->storeList->TabIndex = 0;
			this->storeList->UseCompatibleStateImageBehavior = false;
			this->storeList->View = System::Windows::Forms::View::Details;
			this->storeList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainPage::CartList_ColumnClick);
			this->storeList->Click += gcnew System::EventHandler(this, &MainPage::storeList_Click);
			this->storeList->DoubleClick += gcnew System::EventHandler(this, &MainPage::StoreList_DoubleClick);
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
			this->tabPage2->Location = System::Drawing::Point(4, 28);
			this->tabPage2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tabPage2->Size = System::Drawing::Size(800, 542);
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
			this->CartList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CartList->Name = L"CartList";
			this->CartList->Size = System::Drawing::Size(808, 598);
			this->CartList->TabIndex = 1;
			this->CartList->UseCompatibleStateImageBehavior = false;
			this->CartList->View = System::Windows::Forms::View::Details;
			this->CartList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainPage::CartList_ColumnClick);
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
			this->ShopPanel->Location = System::Drawing::Point(439, 630);
			this->ShopPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ShopPanel->Name = L"ShopPanel";
			this->ShopPanel->Size = System::Drawing::Size(364, 71);
			this->ShopPanel->TabIndex = 1;
			// 
			// CartPanel
			// 
			this->CartPanel->BackColor = System::Drawing::Color::Transparent;
			this->CartPanel->Controls->Add(this->RemoveItemButton);
			this->CartPanel->Controls->Add(this->GoToShopButton);
			this->CartPanel->Controls->Add(this->PurchaseButton);
			this->CartPanel->Location = System::Drawing::Point(364, 630);
			this->CartPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CartPanel->Name = L"CartPanel";
			this->CartPanel->Size = System::Drawing::Size(439, 71);
			this->CartPanel->TabIndex = 2;
			this->CartPanel->Visible = false;
			// 
			// RemoveItemButton
			// 
			this->RemoveItemButton->BackColor = System::Drawing::Color::IndianRed;
			this->RemoveItemButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RemoveItemButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->RemoveItemButton->Location = System::Drawing::Point(4, 2);
			this->RemoveItemButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RemoveItemButton->Name = L"RemoveItemButton";
			this->RemoveItemButton->Size = System::Drawing::Size(71, 62);
			this->RemoveItemButton->TabIndex = 5;
			this->RemoveItemButton->Text = L"Remove Item";
			this->RemoveItemButton->UseVisualStyleBackColor = false;
			this->RemoveItemButton->Click += gcnew System::EventHandler(this, &MainPage::RemoveItemButton_Click);
			// 
			// GoToShopButton
			// 
			this->GoToShopButton->Location = System::Drawing::Point(335, 2);
			this->GoToShopButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->GoToShopButton->Name = L"GoToShopButton";
			this->GoToShopButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->GoToShopButton->Size = System::Drawing::Size(101, 62);
			this->GoToShopButton->TabIndex = 4;
			this->GoToShopButton->Text = L"Go to Shop";
			this->GoToShopButton->UseVisualStyleBackColor = true;
			// 
			// PurchaseButton
			// 
			this->PurchaseButton->Location = System::Drawing::Point(81, 2);
			this->PurchaseButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PurchaseButton->Name = L"PurchaseButton";
			this->PurchaseButton->Size = System::Drawing::Size(251, 62);
			this->PurchaseButton->TabIndex = 2;
			this->PurchaseButton->Text = L"Purchase";
			this->PurchaseButton->UseVisualStyleBackColor = true;
			this->PurchaseButton->Click += gcnew System::EventHandler(this, &MainPage::PurchaseButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(832, 703);
			this->Controls->Add(this->CartPanel);
			this->Controls->Add(this->TotalPriceLabel);
			this->Controls->Add(this->Tab);
			this->Controls->Add(this->ChosenBookLabel);
			this->Controls->Add(this->MainPanel);
			this->Controls->Add(this->ShopPanel);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
		void AddNewCartItem(BookStore::Book^ selectedBook);
		void AddCartItemToListView(CartItem^ newCartItem, BookStore::Book^ selectedBook);
		void AddNumericUpDownToNumberField(ListViewItem^ Item);
		void ProcessCartItem(ListViewItem^ item);
		void UpdateExistingCartItem(ListViewItem^ existingItem);
		void UpdateCartItemQuantity(int itemId, int newQuantity);
		void UpdateNumericUpDownValue(int ID, int NewValue);
		void UpdateTotalPrice();
		void UpdateTotalPriceLabel();
		void UpdateCartDisplay();
		void RemoveCartItem(const int ID);
		void RedrawNumericUpDowns();
		void PositionNumericUpDown(NumericUpDown^ numericUpDown, ListViewItem^ listViewItem);
		ListViewItem^ FindCartItemByID(const int id);
		ListViewItem^ CreateListViewItemForCartItem(CartItem^ cartItem, BookStore::Book^ selectedBook);
		int GetColumnPosition(ListView^ listView, int columnIndex);
		void SortListView(ListView^ listView, int column);
		void CreatePDFReceipt(String^ filePath);

		// Event handlers declaration
		System::Void AddToCart_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void OnNumericUpDownValueChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void RemoveItemButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Tab_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void CartList_ColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e);
		System::Void PurchaseButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void StoreList_DoubleClick(System::Object^ sender, System::EventArgs^ e);
		System::Void storeList_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

