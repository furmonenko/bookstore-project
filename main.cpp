#include <Windows.h>
#include <iostream>

#include "MainPage.h"
#include "Book.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew BookStore::MainPage);
    return 0;
}