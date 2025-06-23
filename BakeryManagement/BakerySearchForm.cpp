#include "BakerySearchForm.h"

using namespace BakeryManagement;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;

System::Void BakerySearchForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ connectstr = "Server=localhost\\SQLEXPRESS;Database=bakery_db;Trusted_Connection=True;";
        SqlConnection^ con = gcnew SqlConnection(connectstr);

        String^ sqlquery = "SELECT * FROM Inventory WHERE 1=1";
        SqlCommand^ command = gcnew SqlCommand();
        command->Connection = con;

        if (!String::IsNullOrWhiteSpace(this->textBox1->Text))
        {
            sqlquery += " AND Type LIKE @Type";
            command->Parameters->AddWithValue("@Type", "%" + textBox1->Text + "%");
        }
        if (!String::IsNullOrWhiteSpace(this->textBox2->Text))
        {
            sqlquery += " AND Grade LIKE @Grade";
            command->Parameters->AddWithValue("@Grade", "%" + textBox2->Text + "%");
        }
        if (!String::IsNullOrWhiteSpace(this->textBox3->Text))
        {
            sqlquery += " AND Material LIKE @Material";
            command->Parameters->AddWithValue("@Material", "%" + textBox3->Text + "%");
        }
        if (!String::IsNullOrWhiteSpace(this->textBox4->Text))
        {
            sqlquery += " AND Supplier LIKE @Supplier";
            command->Parameters->AddWithValue("@Supplier", "%" + textBox4->Text + "%");
        }
        if (!String::IsNullOrWhiteSpace(this->textBox5->Text))
        {
            try {
                DateTime expDate = DateTime::Parse(this->textBox5->Text);
                sqlquery += " AND ExpirationDate = @ExpirationDate";
                command->Parameters->AddWithValue("@ExpirationDate", expDate);
            }
            catch (FormatException^) {
                MessageBox::Show("Invalid expiration date format.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
        }
        if (!String::IsNullOrWhiteSpace(this->textBox6->Text))
        {
            try {
                Decimal price = Convert::ToDecimal(this->textBox6->Text);
                sqlquery += " AND Price = @Price";
                command->Parameters->AddWithValue("@Price", price);
            }
            catch (FormatException^) {
                MessageBox::Show("Invalid price format.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
        }

        command->CommandText = sqlquery;

        con->Open();
        SqlDataReader^ reader = command->ExecuteReader();

        String^ results = "";
        while (reader->Read())
        {
            results += String::Format(
                "Type: {0}, Grade: {1}, Material: {2}, Supplier: {3}, Expiration: {4}, Price: {5}\n",
                reader["Type"], reader["Grade"], reader["Material"],
                reader["Supplier"], reader["ExpirationDate"], reader["Price"]
            );
        }
        con->Close();

        if (String::IsNullOrEmpty(results))
        {
            MessageBox::Show("No matching records found.", "Search Results", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else
        {
            MessageBox::Show(results, "Search Results", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        ClearFields();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Search error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void BakerySearchForm::ClearFields()
{
    textBox1->Clear();
    textBox2->Clear();
    textBox3->Clear();
    textBox4->Clear();
    textBox5->Clear();
    textBox6->Clear();
    textBox1->Focus();
}
