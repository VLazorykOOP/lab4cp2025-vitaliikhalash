#pragma once

namespace BakeryManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BakeryManagementForm
	/// </summary>
	public ref class BakeryManagementForm : public System::Windows::Forms::Form
	{
	public:
		BakeryManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BakeryManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(114, 178);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 38);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Insert data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BakeryManagementForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(114, 134);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 38);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Retrieve data";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BakeryManagementForm::button2_Click);
			// 
			// BakeryManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 353);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"BakeryManagementForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bakery Management Form";
			this->Load += gcnew System::EventHandler(this, &BakeryManagementForm::BakeryManagementForm_Load);
			this->ResumeLayout(false);

		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
#pragma endregion
	private: System::Void BakeryManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

};
}
