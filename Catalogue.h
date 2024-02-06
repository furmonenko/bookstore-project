#pragma once
#include "Book.h"

namespace BookStore
{
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Catalogue
    {
    private:
        System::Collections::Generic::List<IBook^>^ Books;

    public:
        Catalogue()
        {
            Books = gcnew System::Collections::Generic::List<IBook^>();
        }
        Catalogue(System::Collections::Generic::List<IBook^>^ bookList)
        {
            Books = bookList;
        }

        void AddNewBook(IBook^ newBook)
        {
            Books->Add(newBook);
        }

        bool DeleteBook(IBook^ bookToDelete)
        {
            return Books->Remove(bookToDelete);
        }

        IBook^ GetBook(int index)
        {
            return Books[index];
        }

        int GetSize()
        {
            return Books->Count;
        }
    };
}


