#pragma once
#include "CartItem.h"

namespace BookStore
{
    using namespace System;
    using namespace System::Collections::Generic;

	ref class Cart
	{
    public:
        List<CartItem^>^ Items;

    private:
        Dictionary<int, CartItem^>^ ItemDic;

    public:
        Cart()
        {
            Items = gcnew List<CartItem^>();
            ItemDic = gcnew Dictionary<int, CartItem^>();
        }

        void AddNewItem(CartItem^ NewItem)
        {
            Items->Add(NewItem);
            NewItem->IncrementQuantity();
        }

        bool DeleteBook(CartItem^ bookToDelete)
        {
            bookToDelete->DecrementQuantity();
            return Items->Remove(bookToDelete);
        }

        CartItem^ GetBook(int index)
        {
            return Items[index];
        }

        CartItem^ FindByID(int ID)
        {
            for each (CartItem^ Item in Items)
            {
                if (Item->GetID() == ID)
                {
                    return Item;
                }
            }
            return nullptr;
        }


        int GetSize()
        {
            return Items->Count;
        }

        void Sort()
        {
            // Implement sorting logic here
            // For example, you might want to sort by book title or author
        }
    };
}

