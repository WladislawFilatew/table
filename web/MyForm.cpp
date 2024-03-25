#include "MyForm.h"
#include "DialogToch.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	CppWinForm1::MyForm form;
	//CppWinDialogTochForm::DialogTochForm form;
	Application::Run(% form);
}
