//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TT_kalkulator.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_TT_kalkulator *Form_TT_kalkulator;
//---------------------------------------------------------------------------
__fastcall TForm_TT_kalkulator::TForm_TT_kalkulator(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::FormShow(TObject *Sender)
{
    OK_status=false;
		//nahraje původní hodnoty
		Edit_hodin->Text=Form1->PP.hodin;
		Edit_smen->Text=Form1->PP.smen;
		Edit_dni->Text=Form1->PP.dni;
		Edit_produktu_na_vozik->Text=Form1->PP.produktu_vozik;
		Edit_TT->Text=Form1->PP.TT;editTT();

		if(Form1->PP.produktu_vozik==1){Label_nerelev->Visible=false;/*Edit_TT_produktu->Enabled=false;Edit_TP_produktu->Enabled=false;*/}else{Label_nerelev->Visible=true;/*Edit_TT_produktu->Enabled=true;Edit_TP_produktu->Enabled=true;*/}
		if(TT==0){Button_TT_sec->Visible=false;Button_TP_sec->Visible=false;}else{Button_TT_sec->Visible=true;Button_TP_sec->Visible=true;}
		kontrola_zadani();
}
//---------------------------------------------------------------------------
void TForm_TT_kalkulator::getTT()
{
	 try
	 {
			if(Edit_produkty->Text.ToDouble()>0 && Edit_produktu_na_vozik->Text.ToDouble()>0)
			{
				//výpočet TT
				TT=Edit_hodin->Text.ToDouble()*Edit_smen->Text.ToDouble()*Edit_dni->Text.ToDouble()*60/Edit_produkty->Text.ToDouble()/Edit_produktu_na_vozik->Text.ToDouble();
				//vyplnění hodnot vstupně výstupních EditBoxů
				Edit_TT->Text=TT;
				Edit_TT_produktu->Text=TT/Edit_produktu_na_vozik->Text.ToDouble();
				Edit_TP->Text=1/TT;
				Edit_TP_produktu->Text=1/TT*Edit_produktu_na_vozik->Text.ToDouble();
				//zobrazení tlačítek
				Button_TT_sec->Visible=true;Button_TP_sec->Visible=true;
				if(Edit_produktu_na_vozik->Text.ToInt()==1){Label_nerelev->Visible=false;/*Edit_TT_produktu->Enabled=false;Edit_TP_produktu->Enabled=false;*/}else{Label_nerelev->Visible=true;/*Edit_TT_produktu->Enabled=true;Edit_TP_produktu->Enabled=true;*/}
			}
			else {Edit_TT->Text=0;Edit_TP->Text=0;Edit_TT_produktu->Text=0;Edit_TP_produktu->Text=0;Button_TT_sec->Visible=false;Button_TP_sec->Visible=false;}
	 }
	 catch(...)
	 {
			Edit_TT->Text="neplatná hodnota!";Edit_TT_produktu->Text="neplatná hodnota!";Button_TT_sec->Visible=false;
			Edit_TP->Text="neplatná hodnota!";Edit_TP_produktu->Text="neplatná hodnota!";Button_TP_sec->Visible=false;
	 }
}
//---------------------------------------------------------------------------
void TForm_TT_kalkulator::getProductCount()// při změně TT nebo TP
{
	Edit_produkty->Text=Edit_hodin->Text.ToDouble()*Edit_smen->Text.ToDouble()*Edit_dni->Text.ToDouble()*60/TT/Edit_produktu_na_vozik->Text.ToDouble();
}
//---------------------------------------------------------------------------
void TForm_TT_kalkulator::getDays()
{
	Edit_dni->Text=(TT*Edit_produkty->Text.ToDouble()*Edit_produktu_na_vozik->Text.ToDouble())/(Edit_hodin->Text.ToDouble()*Edit_smen->Text.ToDouble()*60);
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Zadani_Change(TObject *Sender)
{
	if(!Edit_produkty->Focused() && Button_zamek_TT->Down)//pří zamčeném TT se přepočítají produkty
	{
     getProductCount();
  }
	else
	{
		if(Edit_produkty->Focused() && Button_zamek_TT->Down)//pří zamčeném TT a změně produktů se přepočítají dny
			getDays();
		else
		{ //provede se pouze v případě zadání z hodnot
			if(Edit_hodin->Focused() || Edit_smen->Focused() || Edit_dni->Focused() || Edit_produkty->Focused() || Edit_produktu_na_vozik->Focused())
				getTT();//při změně libovolného editboxu dojde k přepočítání TT
		}
	}

	kontrola_zadani();
}
//---------------------------------------------------------------------------
void TForm_TT_kalkulator::editTT()
{
	try
	{
			TT=Form1->ms.MyToDouble(Edit_TT->Text.ToDouble());
			if(TT!=0)
			{
				Edit_TT_produktu->Text=TT/Edit_produktu_na_vozik->Text.ToDouble();
				Edit_TP->Text=1/TT;
				Edit_TP_produktu->Text=1/TT*Edit_produktu_na_vozik->Text.ToDouble();
				if(!Button_zamek_produkty->Down)getProductCount();//pokud je dovoleno editovat množství produktů
				else getDays();
			}
	}
	catch(...){;}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Edit_TTChange(TObject *Sender)
{
	 kontrola_zadani();
	 //provede se pouze v případě změny TT jinak by se cyklilo
		if(Edit_TT->Focused() && Edit_TT->Text.ToDouble()>0)
		{
			editTT();
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Edit_TPChange(TObject *Sender)
{
	kontrola_zadani();

	try
	{
		if(Edit_TP->Focused() && Edit_TP->Text.ToDouble()>0)
		{
			TT=1/Edit_TP->Text.ToDouble();
			Edit_TT->Text=TT;
			Edit_TT_produktu->Text=TT/Edit_produktu_na_vozik->Text.ToDouble();
			Edit_TP_produktu->Text=1/TT*Edit_produktu_na_vozik->Text.ToDouble();
			if(!Button_zamek_produkty->Down)getProductCount();//pokud je dovoleno editovat množství produktů
			else getDays();
		}
	}
	catch(...){;}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Edit_TT_produktuChange(TObject *Sender)
{
	kontrola_zadani();
	try
	{
		if(Edit_TT_produktu->Focused() && Edit_TT_produktu->Text.ToDouble()>0)
		{
			TT=Edit_TT_produktu->Text.ToDouble()*Edit_produktu_na_vozik->Text.ToDouble();//další již pořeší Edit_TTChange()
			Edit_TT->Text=TT;
			Edit_TP->Text=1/TT;
			Edit_TP_produktu->Text=1/TT*Edit_produktu_na_vozik->Text.ToDouble();
			if(!Button_zamek_produkty->Down)getProductCount();//pokud je dovoleno editovat množství produktů
			else getDays();
		}
	}
	catch(...){;}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Edit_TP_produktuChange(TObject *Sender)
{
	kontrola_zadani();

	try
	{
		if(Edit_TP_produktu->Focused() && Edit_TP_produktu->Text.ToDouble()>0)
		{
			TT=1/Edit_TP_produktu->Text.ToDouble()*Edit_produktu_na_vozik->Text.ToDouble();//další již pořeší Edit_TTChange()
			Edit_TT->Text=TT;
			Edit_TP->Text=1/TT;
			Edit_TT_produktu->Text=TT/Edit_produktu_na_vozik->Text.ToDouble();
			if(!Button_zamek_produkty->Down)getProductCount();//pokud je dovoleno editovat množství produktů
			else getDays();
		}
	}
	catch(...){;}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Button_TT_secClick(TObject *Sender)
{
	ShowMessage(UnicodeString(TT/60)+" [sec/vozík]\n"+UnicodeString(TT/Edit_produktu_na_vozik->Text.ToDouble()/60)+" [sec/produkt]");
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Button_TP_secClick(TObject *Sender)
{
	ShowMessage(UnicodeString(1/TT/60)+" [vozík/sec]\n"+UnicodeString(1/TT/Edit_produktu_na_vozik->Text.ToDouble()/60)+" [produkt/sec]");
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::OKClick(TObject *Sender)
{
	OK_status=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(OK_status)
	{
		if(Form1->ms.MyToDouble(Edit_hodin->Text)==0 || Form1->ms.MyToDouble(Edit_smen->Text)==0 || Form1->ms.MyToDouble(Edit_dni->Text)==0 || Form1->ms.u2i(Edit_produktu_na_vozik->Text)==0 || Form1->ms.MyToDouble(Edit_TT->Text)==0)
		{
				MessageBeep(0);
				CanClose=false;
				OK_status=false;
		}
		else
		{
			Form1->PP.hodin=Form1->ms.MyToDouble(Edit_hodin->Text);
			Form1->PP.smen=Form1->ms.MyToDouble(Edit_smen->Text);
			Form1->PP.dni=Form1->ms.MyToDouble(Edit_dni->Text);
			Form1->PP.produktu_vozik=Form1->ms.u2i(Edit_produktu_na_vozik->Text);
			Form1->PP.TT=TT;
			Form1->Edit_takt_time->Text=TT;
			Form1->DuvodUlozit(true);
			CanClose=true;
		}
	}
	else CanClose=true;//zavře bez uložení
}
//---------------------------------------------------------------------------
void TForm_TT_kalkulator::kontrola_zadani()
{
 	//červené zvýraznění textu v případě chybového zadání
	if(Form1->ms.MyToDouble(Edit_TT->Text)==0)Edit_TT->Font->Color=clRed;else Edit_TT->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_hodin->Text)==0)Edit_hodin->Font->Color=clRed;else Edit_hodin->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_smen->Text)==0)Edit_smen->Font->Color=clRed;else Edit_smen->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_dni->Text)==0)Edit_dni->Font->Color=clRed;else Edit_dni->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_produkty->Text)==0)Edit_produkty->Font->Color=clRed;else Edit_produkty->Font->Color=clBlack;
	if(Form1->ms.u2i(Edit_produktu_na_vozik->Text)==0)Edit_produktu_na_vozik->Font->Color=clRed;else Edit_produktu_na_vozik->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_TP->Text)==0)Edit_TP->Font->Color=clRed;else Edit_TP->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_TT_produktu->Text)==0)Edit_TT_produktu->Font->Color=clRed;else Edit_TT_produktu->Font->Color=clBlack;
	if(Form1->ms.MyToDouble(Edit_TP_produktu->Text)==0)Edit_TP_produktu->Font->Color=clRed;else Edit_TP_produktu->Font->Color=clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Button_zamek_TTClick(TObject *Sender)
{
	Form1->Edit_takt_time->Enabled=!Form1->Edit_takt_time->Enabled;
	Edit_TT->Enabled=!Edit_TT->Enabled;
	Edit_TP->Enabled=!Edit_TP->Enabled;
	Edit_TT_produktu->Enabled=!Edit_TT_produktu->Enabled;
	Edit_TP_produktu->Enabled=!Edit_TP_produktu->Enabled;
	if(Button_zamek_produkty->Down && Button_zamek_TT->Down){Button_zamek_produkty->Down=false;Button_zamek_produktyClick(Sender);}
}
//---------------------------------------------------------------------------
void __fastcall TForm_TT_kalkulator::Button_zamek_produktyClick(TObject *Sender)
{
	Edit_produkty->Enabled=!Edit_produkty->Enabled;
	if(Button_zamek_produkty->Down && Button_zamek_TT->Down){Button_zamek_TT->Down=false;Button_zamek_TTClick(Sender);}
}
//---------------------------------------------------------------------------

