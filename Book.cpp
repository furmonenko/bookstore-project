#include "Book.h"


BookStore::Book::Book(System::String^ BookName, System::String^ BookAuthor, double BookPrice, BookGenre BookGenre, System::String^ BookImageLink)
    :Name(BookName), Author(BookAuthor), Price(BookPrice), Genre(BookGenre), ImageLink(BookImageLink)
{
    ID = NextId++;
}
