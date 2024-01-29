#include <Windows.h>
#include <iostream>

#include "MyForm.h"
#include "PaperBook.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    // Allocate a console window
    AllocConsole();

    // Start the WinForms application
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew BookStore::MyForm);
    return 0;
}