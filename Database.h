#pragma once
#include <libpq-fe.h>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>

#include "Book.h"

namespace BookStore
{
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace msclr::interop;

    public ref class Database
    {
    private:
        static Database^ instance;

    private:
        Database() {}

    public:
        // Static property to get the instance
        static property Database^ Instance
        {
            Database^ get()
            {
                if (instance == nullptr)
                {
                    instance = gcnew Database();
                }
                return instance;
            }
        }

        System::Collections::Generic::List<IBook^>^ GetBooks()
        {
            System::Collections::Generic::List<IBook^>^ books = gcnew System::Collections::Generic::List<IBook^>();

            System::String^ cnnString = "host=localhost port=5432 dbname=book_store user=postgres password=Dertin00";
            std::string connStr = msclr::interop::marshal_as<std::string>(cnnString);

            Console::WriteLine(marshal_as<String^>(connStr));

            PGconn* conn = PQconnectdb(connStr.c_str());

            if (PQstatus(conn) != CONNECTION_OK)
            {
                Console::WriteLine("Connection to database failed: ");
                Console::WriteLine(PQerrorMessage(conn));
                PQfinish(conn);
                return books;
            }

            PGresult* res = PQexec(conn, "SELECT * FROM books");

            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                Console::WriteLine("No data retrieved: ");
                Console::WriteLine(PQerrorMessage(conn));
                PQclear(res);
                PQfinish(conn);
                return books;
            }

            int rows = PQntuples(res);
            for (int i = 0; i < rows; i++)
            {
                String^ title = marshal_as<String^>(PQgetvalue(res, i, 1));
                String^ author = marshal_as<String^>(PQgetvalue(res, i, 2));
                double price = atof(PQgetvalue(res, i, 3));

                // TODO: String from DataBase conversion to BookGenre ENUM.

                String^ imageLink = marshal_as<String^>(PQgetvalue(res, i, 5));

                books->Add(gcnew Book(title, author, price, BookGenre::Elemental_Magic, imageLink));
            }

            PQclear(res);
            PQfinish(conn);

            return books;
        }
    };
}



