#include "MyForm.h"

void BookStore::MyForm::InitializeStore()
{
	db = Database::Instance;
	// ShopCatalogue = gcnew Catalogue();
	ShopCart = gcnew Cart();
	NumberFields = gcnew Dictionary<int, NumericUpDown^>;

	TotalPrice = 0.0f;

	//BookStore::PaperBook^ FireBook = gcnew BookStore::PaperBook("Book Of Fire", "Fire Man", 200.f, BookStore::BookGenre::Elemental_Magic, "Images/FireBook.png");
	//BookStore::PaperBook^ EarthBook = gcnew BookStore::PaperBook("Book Of Earth", "Earth Man", 200.f, BookStore::BookGenre::Elemental_Magic, "Images/EarthBook.png");
	//BookStore::PaperBook^ WaterBook = gcnew BookStore::PaperBook("Book Of Water", "Water Man", 200.f, BookStore::BookGenre::Elemental_Magic, "Images/WaterBook.png");

	//ShopCatalogue->AddNewBook(FireBook);
	//ShopCatalogue->AddNewBook(EarthBook);
	//ShopCatalogue->AddNewBook(WaterBook);

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
			// fileName->Concat(LinkToImage);

			Console::WriteLine(fileName);

			ShopImageList->Images->Add(System::Drawing::Image::FromFile(fileName));
		}
	}

	storeList->SmallImageList = ShopImageList;
	CartList->SmallImageList = CartImageList;

	for (size_t i = 0; i < ShopCatalogue->GetSize(); i++)
	{
		BookStore::Book^ currentBook = ShopCatalogue->GetBook(i);
		ListViewItem^ item = gcnew ListViewItem(currentBook->GetName(), i);

		item->SubItems->Add(currentBook->GetAuthor());
		item->SubItems->Add(currentBook->GetGenre());
		item->SubItems->Add(currentBook->GetPrice().ToString("C"));
		item->Tag = currentBook;
		storeList->Items->Add(item);
	}
}
