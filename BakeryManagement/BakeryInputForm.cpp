#include "BakeryInputForm.h"

using namespace BakeryManagement;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;

System::Void BakeryInputForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ msg = "Error: Missing fields: ";
	bool fieldInput = true;

	if (String::IsNullOrWhiteSpace(this->textBox1->Text))
	{
		fieldInput = false;
		msg += "Type, ";
	}
	if (String::IsNullOrWhiteSpace(this->textBox2->Text))
	{
		fieldInput = false;
		msg += "Grade, ";
	}
	if (String::IsNullOrWhiteSpace(this->textBox3->Text))
	{
		fieldInput = false;
		msg += "Material, ";
	}
	if (String::IsNullOrWhiteSpace(this->textBox4->Text))
	{
		fieldInput = false;
		msg += "Supplier, ";
	}
	if (String::IsNullOrWhiteSpace(this->textBox5->Text))
	{
		fieldInput = false;
		msg += "Expiration Date, ";
	}
	if (String::IsNullOrWhiteSpace(this->textBox6->Text))
	{
		fieldInput = false;
		msg += "Price, ";
	}

	if (!fieldInput)
	{
		msg = msg->TrimEnd(',', ' ') + ". Please fill them.";
		MessageBox::Show(msg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try
	{
		String^ connectstr = "Server=localhost\\SQLEXPRESS;Database=bakery_db;Trusted_Connection=True;";
		SqlConnection^ con = gcnew SqlConnection(connectstr);
		String^ sqlquery = "INSERT INTO Inventory (Type, Grade, Material, Supplier, ExpirationDate, Price) "
			"VALUES (@Type, @Grade, @Material, @Supplier, @ExpirationDate, @Price)";
		SqlCommand^ command = gcnew SqlCommand(sqlquery, con);

		command->Parameters->AddWithValue("@Type", textBox1->Text);
		command->Parameters->AddWithValue("@Grade", textBox2->Text);
		command->Parameters->AddWithValue("@Material", textBox3->Text);
		command->Parameters->AddWithValue("@Supplier", textBox4->Text);
		command->Parameters->AddWithValue("@ExpirationDate", DateTime::Parse(textBox5->Text));
		command->Parameters->AddWithValue("@Price", Convert::ToDecimal(textBox6->Text));

		con->Open();
		command->ExecuteNonQuery();
		con->Close();

		MessageBox::Show("Record added successfully.", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);

		ClearFields();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Database error: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void BakeryInputForm::ClearFields()
{
	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	textBox4->Clear();
	textBox5->Clear();
	textBox6->Clear();
	textBox1->Focus();
}
