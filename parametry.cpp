//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "parametry.h"
#include "unit1.h"
#include "dopravniky.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_parametry *Form_parametry;
//---------------------------------------------------------------------------
__fastcall TForm_parametry::TForm_parametry(TComponent* Owner)
	: TForm(Owner)
{
	SG="PT - èistý technologický výrobní èas=0\nMT - èas pøesouvání produktu=0\nWT - doba èekání vozíku=0\nIT - doba kontroly vozíku=0\nQT - doba èekání ve frontì=0\n...=""";
	K="délka dopravníku [m]=0";
	P="WT - doba èekání vozíku=0";

	novy_parametr_n=0;
	offset=0;


}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::FormShow(TObject *Sender)
{
	minsec=MIN;//formuláø bude po zobrazení v minutách

	//Form_paremetry->Edit1->SetFocus();
	//Form_paremetry->Edit1->SelectAll();

	/*
	pøednastavení na Postprocesní režím, již nastavuji pøi tvorbì nového objektu viz vektory.cpp
	if(Form_paremetry->Caption=="vytìkání - parametry" || Form_paremetry->Caption=="sušení - parametry" || Form_paremetry->Caption=="chlazení - parametry")
	{ComboBox_druh_objektu->ItemIndex=2;ComboBox_druh_objektuChange(Sender);}
	*/

	ComboBox_dopravnik->Items->Clear();
	Form_dopravnik->ValueListEditor->Strings->SetText(Form1->d.v.seznam_dopravniku.c_str());
	unsigned int n=Form_dopravnik->ValueListEditor->Strings->Count;
	UnicodeString S=Form1->d.v.seznam_dopravniku; //Form_dopravnik->ValueListEditor->Strings->Text;
	for(unsigned int i=0;i<n;i++)
	{
		ComboBox_dopravnik->Items->Add(Form1->ms.TrimRightFrom(S,"=")+" - "+Form1->ms.EP(S,"=","\n").TrimRight()+" [metrù/min]");
		S=Form1->ms.delete_repeat(S,"\n",1);
	}
	ComboBox_dopravnik->ItemIndex=dopravnik_typ;
	if(ComboBox_dopravnik->ItemIndex==-1){ComboBox_dopravnik->ItemIndex=0;dopravnik_typ=0;}//v pøípadì, že byl dopravník smazán odkáže se na hlavní dopravník

	ValueListEditorStringsChange(Sender);
}
//---------------------------------------------------------------------------
void TForm_parametry::vykresli_vozik(bool na_delku)
{
	Image_vozik->Canvas->Pen->Color=clBtnFace;
	Image_vozik->Canvas->Pen->Width=1;
	Image_vozik->Canvas->Brush->Color=clBtnFace;
	Image_vozik->Canvas->Rectangle(0,0,Image_vozik->Width,Image_vozik->Height);//vybarvení celého
	TPoint stred; stred.x=Image_vozik->Width/2;stred.y=Image_vozik->Height/2;
	double D,S;
	unsigned short meritko=(Image_vozik->Width-6)/Form1->PP.delka_voziku;
	if(meritko>(Image_vozik->Width-6)/Form1->PP.sirka_voziku)meritko=(Image_vozik->Width-6)/Form1->PP.sirka_voziku;
	if(meritko>(Image_vozik->Height-6)/Form1->PP.delka_voziku)meritko=(Image_vozik->Height-6)/Form1->PP.delka_voziku;
	if(meritko>(Image_vozik->Height-6)/Form1->PP.sirka_voziku)meritko=(Image_vozik->Height-6)/Form1->PP.sirka_voziku;

	if(na_delku){D=Form1->PP.delka_voziku;S=Form1->PP.sirka_voziku;}
	else{S=Form1->PP.delka_voziku;D=Form1->PP.sirka_voziku;}

	//packy
	Image_vozik->Canvas->Pen->Color=clBlack;
	Image_vozik->Canvas->Pen->Width=1;
	Image_vozik->Canvas->MoveTo(stred.x-D/2*meritko,stred.y);
	Image_vozik->Canvas->LineTo(stred.x-D/2*meritko-20,stred.y);
	Image_vozik->Canvas->MoveTo(stred.x+D/2*meritko,stred.y);
	Image_vozik->Canvas->LineTo(stred.x+D/2*meritko+20,stred.y);
	//sipka -levá
	Image_vozik->Canvas->Brush->Color=clGray;
	Image_vozik->Canvas->Pen->Color=clBlack;
	Image_vozik->Canvas->Pen->Width=1;
	POINT bodyL[3]={{stred.x-D/2*meritko-13,stred.y-3},{stred.x-D/2*meritko-7,stred.y},{stred.x-D/2*meritko-13,stred.y+3}};
	Image_vozik->Canvas->Polygon((TPoint*)bodyL,2);
	//sipka - pravá
	POINT bodyP[3]={{stred.x+D/2*meritko+7,stred.y-3},{stred.x+D/2*meritko+13,stred.y},{stred.x+D/2*meritko+7,stred.y+3}};
	Image_vozik->Canvas->Polygon((TPoint*)bodyP,2);
	//vozík
	Image_vozik->Canvas->Pen->Width=2;
	Image_vozik->Canvas->Brush->Color=clWhite;
	Image_vozik->Canvas->Rectangle(stred.x-D/2*meritko,stred.y-S/2*meritko,stred.x+D/2*meritko,stred.y+S/2*meritko);
	//popisek
	Image_vozik->Canvas->Font->Size=7;
	Image_vozik->Canvas->TextOutW(stred.x-Image_vozik->Canvas->TextWidth(D)/2,stred.y+S/2*meritko-Image_vozik->Canvas->TextHeight(D)-2,D);
	Image_vozik->Canvas->TextOutW(stred.x-D/2*meritko+2,stred.y-Image_vozik->Canvas->TextHeight(S)/2,S);
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::Edit_CTKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key==13)//ENTER
 {
		 Form_parametry->ModalResult=idOK;//vrátí stejnou hodnotu jako tlaèítko
		 Form_parametry->VisibleChanging();//skryje form, stejné jako visible=false
 }
}
//---------------------------------------------------------------------------
double TForm_parametry::get_sum()
{
	 double sum=0;
	 for(int i=1;i<=ValueListEditor->RowCount;i++)
	 {
		 try
		 {
			 sum+=ValueListEditor->Cells[1][i].ToDouble();
		 }
		 catch(...){}
	 }
	 return sum;
}
//---------------------------------------------------------------------------
void TForm_parametry::get_capacity(unsigned int input)
{
		try
		{
			switch (input)
			{
				case 1://kontinual, line tracking
				{
					if(Form1->PP.delka_voziku!=0)
					{
						double sirka_delka=Form1->PP.sirka_voziku;if(RadioButton_na_delku->Checked)sirka_delka=Form1->PP.delka_voziku;//podle nastavene orientace vozíku
						if(ValueListEditor->Cells[1][1].ToDouble()>=sirka_delka)
						{
							Label_kapacita_hodnota->Font->Color=clBlack;
							try{Edit_vzdalenost_voziku->Text.ToDouble();}catch(...){Edit_vzdalenost_voziku->Text=0;}
							Label_kapacita_hodnota->Caption=UnicodeString((ValueListEditor->Cells[1][1].ToDouble()+Edit_vzdalenost_voziku->Text.ToDouble())/(sirka_delka+Edit_vzdalenost_voziku->Text.ToDouble()));
						}
						else
						{
							Label_kapacita_hodnota->Font->Color=clRed;
							Label_kapacita_hodnota->Caption="Nepl. délka!";
						}
					}
					else {Label_kapacita_hodnota->Font->Color=clBlack;Label_kapacita_hodnota->Caption="Parametry vozík!";}
				}break;

				case 2://postprocesní
				{
					if(Form1->PP.TT!=0)
					{
						unsigned short sm=1;if(minsec==SEC)sm=60;//pouze pro zkrácení zapisu
						if(ValueListEditor->Cells[1][1].ToDouble()>=Form1->PP.TT*sm){Label_kapacita_hodnota->Font->Color=clBlack;Label_kapacita_hodnota->Caption=UnicodeString(ValueListEditor->Cells[1][1].ToDouble()/(Form1->PP.TT*sm));}
						else	{Label_kapacita_hodnota->Font->Color=clRed;/*Label_kapacita_hodnota->Caption="Nepl. doba!";*/Label_kapacita_hodnota->Caption=UnicodeString(ValueListEditor->Cells[1][1].ToDouble()/(Form1->PP.TT*sm));}

						if(Label_kapacita_hodnota->Caption=="0")Label_delka_prepravniku_hodnota->Caption="0";
						else
						{
							if(RadioButton_na_delku->Checked)
								Label_delka_prepravniku_hodnota->Caption=(Label_kapacita_hodnota->Caption.ToDouble()*Form1->PP.delka_voziku)+(Label_kapacita_hodnota->Caption.ToDouble()-1)*Edit_vzdalenost_voziku->Text.ToDouble();
							else
								Label_delka_prepravniku_hodnota->Caption=(Label_kapacita_hodnota->Caption.ToDouble()*Form1->PP.sirka_voziku)+(Label_kapacita_hodnota->Caption.ToDouble()-1)*Edit_vzdalenost_voziku->Text.ToDouble();
            }
					}
					else {Label_kapacita_hodnota->Font->Color=clRed;Label_kapacita_hodnota->Caption="Zadejte TT!";}
				}break;
			}


		}catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::ValueListEditorStringsChange(TObject *Sender)
{
	Label_vypis->Visible=false;
	unsigned short sm=1;if(minsec==SEC)sm=60;//pouze pro zkrácení zapisu
	switch(ComboBox_druh_objektu->ItemIndex)
	{
		case 0://stop and go
		{
			Label_CT_hodnota->Caption=get_sum();Label_kapacita_hodnota->Font->Color=clBlack;
			Label_TT_hodnota->Caption=Label_CT_hodnota->Caption;
			if(Label_TT_hodnota->Caption.ToDouble()!=Form1->PP.TT*sm)Label_vypis->Visible=true;
		}
		break;
		case 1://kontinual
		{
			try
			{                                                                                  //zvážit zda to nebrat pøímo z form
					Label_CT_hodnota->Caption=ValueListEditor->Cells[1][1].ToDouble()/Form1->ms.EP(ComboBox_dopravnik->Items->operator[](ComboBox_dopravnik->ItemIndex),"- "," [").ToDouble();
					get_capacity(1);
					Label_TT_hodnota->Caption=Label_CT_hodnota->Caption.ToDouble()/Label_kapacita_hodnota->Caption.ToDouble();
					if(Label_TT_hodnota->Caption.ToDouble()!=Form1->PP.TT*sm)Label_vypis->Visible=true;
			}catch(...){;};
		}
		break;
		case 2://postprocesní
		{
			get_capacity(2);
			Label_CT_hodnota->Caption=get_sum();
			Label_TT_hodnota->Caption=Form1->PP.TT*sm;
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::ComboBox_druh_objektuChange(TObject *Sender)
{
	 setForm4Rezim(ComboBox_druh_objektu->ItemIndex);
}
//---------------------------------------------------------------------------
void TForm_parametry::setForm4Rezim(unsigned short rezim,bool default_text)
{
	switch(rezim)
 {
		 case 0://STOP & GO
		 {
			ComboBox_dopravnik->Visible=false;
			GroupBox_vzdalenost->Left=0;
			GroupBox_vzdalenost->Visible=false;
			GroupBox_orientace_voziku->Width=262;
			Button_DEL->Visible=false;
			Image_vozik->Width=185;if(RadioButton_na_delku->Checked)vykresli_vozik();else vykresli_vozik(false);
			if(default_text)ValueListEditor->Strings->SetText(SG.c_str());
			Label_CT->Top=296+offset;Label_CT_hodnota->Top=296+offset;
			Label_TT->Top=315+offset;Label_TT_hodnota->Top=315+offset;
			Label_kapacita->Top=334+offset;Label_kapacita_hodnota->Top=334+offset;
			Label_kapacita_hodnota->Caption=1;
			Label_delka_prepravniku->Visible=false;Label_delka_prepravniku_hodnota->Visible=false;
			Button_min_sec->Top=388+offset-6;
			Form_parametry->Height=429+offset;Button_OK->Top=374+offset;Label_vypis->Top=355+offset;
		 }break;
		 case 1://KONTINUÁLNÍ
		 {
			ComboBox_dopravnik->Visible=true;
			GroupBox_vzdalenost->Visible=true;
			GroupBox_vzdalenost->Left=195;
			GroupBox_orientace_voziku->Width=187;
			Button_DEL->Visible=false;
			Image_vozik->Width=107;if(RadioButton_na_delku->Checked)vykresli_vozik();else vykresli_vozik(false);
			if(default_text)ValueListEditor->Strings->SetText(K.c_str());
			Label_CT->Top=296-19*5;Label_CT_hodnota->Top=296-19*5;
			Label_TT->Top=315-19*5;Label_TT_hodnota->Top=315-19*5;Label_TT_hodnota->Caption=0;
			Label_kapacita->Top=334-19*5;Label_kapacita_hodnota->Top=334-19*5;
			Label_delka_prepravniku->Visible=false;Label_delka_prepravniku_hodnota->Visible=false;
			Button_min_sec->Top=388-19*5-6;
			Form_parametry->Height=429-19*5;Button_OK->Top=374-19*5;Label_vypis->Top=355-19*5;
		 }break;
		 case 2://POSTPROCESNÍ
		 {
			GroupBox_vzdalenost->Visible=true;
			GroupBox_vzdalenost->Left=195;
			ComboBox_dopravnik->Visible=false;
			GroupBox_orientace_voziku->Width=187;
			Button_DEL->Visible=false;
			Image_vozik->Width=107;if(RadioButton_na_delku->Checked)vykresli_vozik();else vykresli_vozik(false);
			if(default_text)ValueListEditor->Strings->SetText(P.c_str());
			Label_delka_prepravniku->Visible=true;Label_delka_prepravniku_hodnota->Visible=true;
			Label_delka_prepravniku->Top=296-19*5;Label_delka_prepravniku_hodnota->Top=296-19*5;
			Label_CT->Top=296-19*4;Label_CT_hodnota->Top=296-19*4;
			Label_TT->Top=315-19*4;Label_TT_hodnota->Top=315-19*4;
			Label_kapacita->Top=334-19*4;Label_kapacita_hodnota->Top=334-19*4;
			Form_parametry->Height=429-19*4;Button_OK->Top=374-19*4;
			Label_vypis->Top=355-19*4;Button_min_sec->Top=388-19*4-6;
		 }break;
 }
 ValueListEditor->Height=19*ValueListEditor->RowCount;
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::ComboBox_dopravnikChange(TObject *Sender)
{
	ValueListEditorStringsChange(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::RadioButton_na_delkuClick(TObject *Sender)
{
	 vykresli_vozik(true);//na délku
	 ValueListEditorStringsChange(Sender);//zajistí pøepoèítání hodnot
}
//---------------------------------------------------------------------------

void __fastcall TForm_parametry::RadioButton_na_sirkuClick(TObject *Sender)
{
	 vykresli_vozik(false);//na šíøku
	 ValueListEditorStringsChange(Sender);//zajistí pøepoèítání hodnot
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::Image_vozikClick(TObject *Sender)
{
	 if(RadioButton_na_delku->Checked){RadioButton_na_sirku->Checked=true;RadioButton_na_sirkuClick(Sender);}
	 else {RadioButton_na_delkuClick(Sender);RadioButton_na_delku->Checked=true;}
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::ValueListEditorClick(TObject *Sender)
{
	//požadavek na pøidání øetìzce
	if(ValueListEditor->Col==0 && ValueListEditor->Row==ValueListEditor->RowCount-1)
	{
		offset+=19;

		ValueListEditor->KeyOptions>>keyUnique;
		ValueListEditor->Strings->Add("nový parametr "+ UnicodeString(++novy_parametr_n)+"=0");
		ValueListEditor->Strings->Add("...=""");
		ValueListEditor->Strings->Delete(ValueListEditor->RowCount-4);
		ValueListEditor->KeyOptions<<keyUnique;

		setForm4Rezim(0,false);
	}

	if(ValueListEditor->Row!=ValueListEditor->RowCount-1)//pouze pokud se netýká posledního øádku
	{
		Button_DEL->Visible=true;
		Button_DEL->Top=ValueListEditor->Top+ValueListEditor->Row*19+1;
	}

}
//---------------------------------------------------------------------------
//smaže daný øádek
void __fastcall TForm_parametry::Button_DELClick(TObject *Sender)
{
	ValueListEditor->DeleteRow(ValueListEditor->Row);
	offset-=19;
	setForm4Rezim(0,false);
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::Edit_vzdalenost_vozikuChange(TObject *Sender)
{
	 ValueListEditorStringsChange(Sender);
}
//---------------------------------------------------------------------------
//pøepínání zobrazení min vs. sec
void __fastcall TForm_parametry::Button_min_secClick(TObject *Sender)
{
 if(minsec==MIN)
 {
		minsec=SEC;
		Label_CT->Caption="CYCLE TIME [sec/vozík] :";
		Label_CT_hodnota->Caption=Label_CT_hodnota->Caption.ToDouble()*60;
		Label_TT->Caption="TAKT TIME objektu [sec/vozík] :";
		Label_TT_hodnota->Caption=Label_TT_hodnota->Caption.ToDouble()*60;
		ValueListEditor->TitleCaptions->Insert(1,"èas [sec/vozík]");
		if(ComboBox_druh_objektu->ItemIndex!=1)//pokud se nejedná o kontinuál
		{
			for(unsigned short i=1;i<=ValueListEditor->RowCount-1;i++)
			try{ValueListEditor->Cells[1][i]=ValueListEditor->Cells[1][i].ToDouble()*60;}catch(...){;}
		}
 }
 else
 {
		minsec=MIN;
		Label_CT->Caption="CYCLE TIME [min/vozík] :";
		Label_CT_hodnota->Caption=Label_CT_hodnota->Caption.ToDouble()/60;
		Label_TT->Caption="TAKT TIME objektu [min/vozík] :";
		Label_TT_hodnota->Caption=Label_TT_hodnota->Caption.ToDouble()/60;
		ValueListEditor->TitleCaptions->Insert(1,"èas [min/vozík]");
		if(ComboBox_druh_objektu->ItemIndex!=1)//pokud se nejedná kontinuál
		{
			for(unsigned short i=1;i<=ValueListEditor->RowCount-1;i++)
			try{ValueListEditor->Cells[1][i]=ValueListEditor->Cells[1][i].ToDouble()/60.0;}catch(...){;}
		}
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::FormClose(TObject *Sender, TCloseAction &Action)
{
	//v pøípadì pøepnutí na SEC zajistí pøevod zpìt na MIN
	if(minsec==SEC)Button_min_secClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm_parametry::Edit_nameChange(TObject *Sender)
{
	 Form_parametry->Caption=Edit_name->Text+" - parametry";
	 Edit_shortname->Text=Edit_name->Text.SubString(1,3);
}
//---------------------------------------------------------------------------
//pøi stisku Enteru do editu vzdálenosti
void __fastcall TForm_parametry::Edit_vzdalenost_vozikuKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	 if(Key==13)
	 ComboBox_dopravnik->SetFocus();
}
//---------------------------------------------------------------------------

