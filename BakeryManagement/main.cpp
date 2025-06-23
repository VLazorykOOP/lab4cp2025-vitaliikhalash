#include "BakeryManagementForm.h"

using namespace BakeryManagement;

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew BakeryManagementForm());
	return 0;
}
