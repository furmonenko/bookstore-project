#pragma once
#include "IBook.h"

namespace BookStore
{
	ref class Book : public IBook
	{
	private:
		static int NextId = 1;
		int ID;

		System::String^ Name;
		System::String^ Author;
		double Price;
		BookGenre Genre;
		System::String^ ImageLink;

	public:
		Book(System::String^ Name, System::String^ Author, double Price, BookGenre Genre, System::String^ ImageLink);
		~Book() {};

		virtual System::String^ GetName() override { return Name; }
		virtual void SetName(System::String^ name) override { Name = name; }

		virtual System::String^ GetAuthor() override { return Author; }
		virtual void SetAuthor(System::String^ author) override { Author = author; }

		virtual double GetPrice() override { return Price; }
		virtual void SetPrice(double price) override { Price = price; }

		virtual System::String^ GetGenre() override 
		{ 
			System::String^ genreString = System::Enum::GetName(BookGenre::typeid, Genre);
			return genreString;
		}

		virtual void SetGenre(BookGenre genre) override { Genre = genre; }

		virtual System::String^ GetImageLink() override { return ImageLink; }
		virtual void SetImageLink(System::String^ link) override { ImageLink = link; }

		virtual int GetID() override { return ID; };
    };
}


