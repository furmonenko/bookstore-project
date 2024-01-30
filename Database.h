#pragma once
#include <libpq-fe.h>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "PaperBook.h"

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

        System::Collections::Generic::List<Book^>^ GetBooks()
        {
            System::Collections::Generic::List<Book^>^ books = gcnew System::Collections::Generic::List<Book^>();

            System::String^ cnnString = "host=localhost port=5432 dbname=book_store user=postgres password=Dertin00";
            std::string connStr = msclr::interop::marshal_as<std::string>(cnnString);

            Console::WriteLine(marshal_as<String^>(connStr));

            PGconn* conn = PQconnectdb(connStr.c_str());

            if (PQstatus(conn) != CONNECTION_OK)
            {
                Console::WriteLine("Connection to database failed: ");
                Console::WriteLine(PQerrorMessage(conn));
                // std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
                PQfinish(conn);
                return books;
            }

            PGresult* res = PQexec(conn, "SELECT * FROM books");

            if (PQresultStatus(res) != PGRES_TUPLES_OK)
            {
                std::cerr << "No data retrieved: " << PQerrorMessage(conn) << std::endl;
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
                String^ imageLink = marshal_as<String^>(PQgetvalue(res, i, 5));

                books->Add(gcnew PaperBook(title, author, price, BookGenre::Elemental_Magic, imageLink));
            }

            PQclear(res);
            PQfinish(conn);

            return books;
        }
    };
}



