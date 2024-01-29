#pragma once

namespace BookStore
{
    using namespace System;
    using namespace System::Windows::Forms;

    ref class ListViewItemComparer : public System::Collections::IComparer
    {
    private:
        int column;
        bool ascending;

    public:
        ListViewItemComparer(int column, bool ascending)
        {
            this->column = column;
            this->ascending = ascending;
        }

        virtual int Compare(Object^ x, Object^ y)
        {
            ListViewItem^ item1 = dynamic_cast<ListViewItem^>(x);
            ListViewItem^ item2 = dynamic_cast<ListViewItem^>(y);

            String^ text1 = item1->SubItems[column]->Text;
            String^ text2 = item2->SubItems[column]->Text;
            int result = String::Compare(item1->SubItems[column]->Text, item2->SubItems[column]->Text);

            if (!ascending)
            {
                return -result;
            }

            return result;
        }
    };
}



