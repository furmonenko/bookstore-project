#pragma once

namespace BookStore
{
	public enum class BookGenre
	{
		Elemental_Magic,
	};

	public interface class Book
	{
		virtual System::String^ GetName() = 0;
		virtual void SetName(System::String^ name) = 0;

		virtual System::String^ GetAuthor() = 0;
		virtual void SetAuthor(System::String^ author) = 0;

		virtual double GetPrice() = 0;
		virtual void SetPrice(double price) = 0;

		virtual System::String^ GetGenre() = 0;
		virtual void SetGenre(BookGenre genre) = 0;

		virtual System::String^ GetImageLink() = 0;
		virtual void SetImageLink(System::String^ link) = 0;

		virtual int GetID() = 0;
	};
}

