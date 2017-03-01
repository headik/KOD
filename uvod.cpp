//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "uvod.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_uvod *Form_uvod;
//---------------------------------------------------------------------------
__fastcall TForm_uvod::TForm_uvod(TComponent* Owner)
  : TForm(Owner)
{
	Form_uvod->Color=(TColor)RGB(44,82,157);
}
//---------------------------------------------------------------------------
//redefinice, vytvoøí pop-up okno
void __fastcall TForm_uvod::CreateParams(TCreateParams &Params)
{
 TForm::CreateParams(Params);
 Params.Style=WS_POPUP|WS_DISABLED;
 Form_uvod->Color=(TColor)RGB(44,82,157);
}
//---------------------------------------------------------------------------
void __fastcall TForm_uvod::Timer1Timer(TObject *Sender)
{
		Timer1->Enabled=false;//nezapomenout vypnout timer (potom mùžu hledat chybu pùl dne...)
		Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_uvod::FormClose(TObject *Sender,
			TCloseAction &Action)
{
	Form1->Show();
}
//---------------------------------------------------------------------------










