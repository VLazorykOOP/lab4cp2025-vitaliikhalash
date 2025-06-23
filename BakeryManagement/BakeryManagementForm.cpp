#include "BakeryManagementForm.h"
#include "BakeryInputForm.h"
#include "BakerySearchForm.h"

using namespace BakeryManagement;

void BakeryManagementForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	BakeryInputForm^ inputForm = gcnew BakeryInputForm();
	inputForm->ShowDialog();
}

void BakeryManagementForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	BakerySearchForm^ searchForm = gcnew BakerySearchForm();
	searchForm->ShowDialog();
}
