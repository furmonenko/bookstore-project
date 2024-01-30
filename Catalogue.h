#pragma once
#include "Book.h"

namespace BookStore
{
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Catalogue
    {
    private:
        System::Collections::Generic::List<Book^>^ Books;

    public:
        Catalogue()
        {
            Books = gcnew System::Collections::Generic::List<Book^>();
        }
        Catalogue(System::Collections::Generic::List<Book^>^ bookList)
        {
            Books = bookList;
        }

        void AddNewBook(Book^ newBook)
        {
            Books->Add(newBook);
        }

        bool DeleteBook(Book^ bookToDelete)
        {
            return Books->Remove(bookToDelete);
        }

        Book^ GetBook(int index)
        {
            return Books[index];
        }

        int GetSize()
        {
            return Books->Count;
        }

        void Sort()
        {
            // Implement sorting logic here
            // For example, you might want to sort by book title or author
        }
    };
}


