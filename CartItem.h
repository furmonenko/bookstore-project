#pragma once
#include "Book.h"

namespace BookStore
{
	ref class CartItem
	{
	private:	
		unsigned int Quantity;

	public:
		BookStore::Book^ m_Book;

		CartItem(Book^ InBook)
		{
			m_Book = InBook;
		}
		~CartItem() {};

		System::String^ GetName() { return m_Book->GetName(); };
		System::String^ GetAuthor() { return m_Book->GetAuthor(); };
		System::String^ GetGenre() { return m_Book->GetGenre(); };

		int GetID() { return m_Book->GetID(); };

		double GetPrice() { return m_Book->GetPrice(); };

		void IncrementQuantity() { Quantity++; };
		void DecrementQuantity() { Quantity--; };
		void SetQuantity(double NewQuantity) { Quantity = NewQuantity; };

		unsigned int GetQuantity() { return Quantity; };
	};
}


