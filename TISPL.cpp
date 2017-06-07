//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("TT_kalkulator.cpp", Form_TT_kalkulator);
USEFORM("voziky.cpp", Form_vozik_nastaveni);
USEFORM("Unit1.cpp", Form1);
USEFORM("uvod.cpp", Form_uvod);
USEFORM("dopravniky.cpp", Form_dopravnik);
USEFORM("parametry.cpp", Form_parametry);
USEFORM("MyMessageBox.cpp", MyMessageBox);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TMyMessageBox), &MyMessageBox);
		Application->CreateForm(__classid(TForm_uvod), &Form_uvod);
		Application->CreateForm(__classid(TForm_parametry), &Form_parametry);
		Application->CreateForm(__classid(TForm_TT_kalkulator), &Form_TT_kalkulator);
		Application->CreateForm(__classid(TForm_dopravnik), &Form_dopravnik);
		Application->CreateForm(__classid(TForm_vozik_nastaveni), &Form_vozik_nastaveni);
		Application->ShowMainForm=false;//zabránìní zobrazení hlavního formu
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
