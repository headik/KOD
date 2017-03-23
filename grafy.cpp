// ---------------------------------------------------------------------------

#pragma hdrstop

#include "grafy.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void Cgrafy::ShowGrafy(bool stav) {
	if (stav) {
		graf1();
		graf2();
		graf3();
		graf4();
		graf5();
	}
	Form1->Chart1->Visible = stav;
	Form1->Chart2->Visible = stav;
	Form1->Chart3->Visible = stav;
	Form1->Chart4->Visible = stav;
	Form1->Chart5->Visible = false;
	// Form1->CheckBox1->Visible = stav;
	// Form1->CheckBox2->Visible = stav;

	// Form1->CheckBox1->Top = 610;
	// Form1->CheckBox1->Left = Form1->Chart1->Width + Form1->Chart2->Width;
	// Form1->CheckBox2->Top = 610;
	// Form1->CheckBox2->Left = Form1->Chart1->Width;

}

void Cgrafy::graf1() {

	Form1->Chart1->Left = 0;
	Form1->Chart1->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart1->Height = Form1->ClientHeight / 3 * 1, 5;
	Form1->Series1->Clear();
	Form1->Chart1->LeftAxis->Title->Caption = "plán";
	Form1->Chart1->BottomAxis->Title->Caption = "min";
	Form1->Chart1->Title->Caption = "Èasové stavy zakázek";

	if (Form1->Memo1->Visible) {
		Form1->Chart1->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart1->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}
	Form1->Chart1->Title->Font->Size = 14;

	// Form1->Chart1->Legend->Title="Èas";

	/* FDQuery1->Open("select distinct(id_planu) from casy_objektu");
	 FDQuery1->Active = True;
	 for(int i=1;i<=FDQuery1->RecordCount;i++)
	 {

	 FDQuery2->Active = False;
	 FDQuery2->Open("select sum(cas/60) FROM VOZIKY v JOIN casy_objektu c on c.id_planu=v.id_planu JOIN objekty o on o.id=c.id_objektu where v.id_planu =:id_planu");

	 FDQuery2->ParamByName("id_planu")->AsInteger = StrToInt(FDQuery1->Fields->Fields[0]->AsFloat);
	 FDQuery2->Active = True;
	 ShowMessage(FDQuery1->Fields->Fields[0]->AsFloat);
	 Series1->Add(FDQuery2->Fields->Fields[0]->AsFloat,FDQuery1->Fields->Fields[0]->AsFloat,clRed);

	 FDQuery1->Next();
	 FDQuery2->Next();
	 }
	 */
	// Form1->Series1->AddGantt(90, 100, 5, "z5:90-100");
	// Series1->AddGantt();
	Form1->Series1->Legend->Text = "legenda";

	Form1->Series1->Legend->Visible = false;
	Form1->Series2->Legend->Visible = false;

	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku
	while (ukaz != NULL) {
		TPointD z = Form1->d.v.vrat_zacatek_a_konec_zakazky(ukaz);

		Form1->Series1->AddGanttColor(z.x, z.y, ukaz->n,
			AnsiString(z.x) + "-" + AnsiString(z.y) + "", ukaz->barva);
		// Form1->Series1->Legend->Text=AnsiString(ukaz->n);
		// Form1->Series2->Color=ukaz->barva;
		// posun na další prvek v seznamu
		ukaz = ukaz->dalsi;
	}

}

//// ---------------------------------------------------------------------------
void Cgrafy::graf2() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

	if (Form1->Memo1->Visible) {
		Form1->Chart2->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart2->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}
	Form1->Chart2->Legend->Visible = false;
	Form1->Chart2->Title->Font->Size = 14;
	Form1->Chart2->Title->Caption = "TT zakázek";
	Form1->Chart2->LeftAxis->Title->Caption = "min";
	Form1->Chart2->BottomAxis->Title->Caption = "plán";

	Form1->Chart2->Left = Form1->Chart1->Width;
	Form1->Chart2->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart2->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Series3->Clear();
	Form1->Series4->Clear(); // souèet technolog.èasù - celý plán výroby

	Form1->Series3->Marks->Visible = true;
	// tohle se nezobrazi, nevim Form1->Series3->Marks->Text="text";
	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;

	while (ukaz != NULL) {

		Form1->Series3->Add(Form1->d.v.vrat_prumerne_TT_zakazky(ukaz), ukaz->n,
			ukaz->barva);

		// Form1->Series3->Marks->St;

		ukaz = ukaz->dalsi;

	}

}

//// ---------------------------------------------------------------------------
void Cgrafy::graf3() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

	if (Form1->Memo1->Visible) {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}
	Form1->Chart3->Legend->Visible = false;
	Form1->Chart3->LeftAxis->Title->Caption = "min";
	Form1->Chart3->BottomAxis->Title->Caption = "plán";

	Form1->Chart3->Title->Font->Size = 14;
	Form1->Chart3->Title->Caption = "Technologické èasy";

	Form1->Chart3->Left = Form1->Chart1->Width + Form1->Chart2->Width;
	Form1->Chart3->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart3->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Series5->Clear();
	Form1->Series6->Clear();

	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	Cvektory::TVozik *ukaz1 = Form1->d.v.VOZIKY->dalsi;
	while (ukaz != NULL) {

		int ve_vyrobe = Form1->d.v.vrat_sumPT_voziku(ukaz1);
		int cekani = Form1->d.v.vrat_WT_voziku(ukaz1);
		double j=Form1->d.v.vrat_sumPT_voziku(ukaz1);
			 //	Form1->Chart3->LeftAxis->Items->Add(j,UnicodeString(j));

		Form1->Series5->Add(ve_vyrobe, ukaz->n, ukaz->barva);
		Form1->Series6->Add(cekani, ukaz->n, clWhite);
		ukaz = ukaz->dalsi;
	}

}

//// ---------------------------------------------------------------------------
//
void Cgrafy::graf4() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)
	if (Form1->Memo1->Visible) {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}
	Form1->Chart4->Title->Font->Size = 14;
	Form1->Chart4->Title->Caption = "Graf prostojù";

	Form1->Chart4->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width;
	Form1->Chart4->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart4->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Series7->Clear();
	Form1->Series8->Clear();

	// souèet technolog. èasù vs souèet prostojù dle zakázek
	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	Cvektory::TVozik *ukaz1 = Form1->d.v.VOZIKY->dalsi;
	while (ukaz != NULL) {

		Form1->Series7->Add(Form1->d.v.vrat_sumPT_voziku(ukaz1), ukaz->n,
			ukaz->barva);
			
		Form1->Series8->Add(Form1->d.v.vrat_WT_voziku(ukaz1), ukaz->n,
			ukaz->barva);
		ukaz = ukaz->dalsi;
	}

	// Form1->Series7->Add(20, "Zak1", clBlue);
	// Form1->Series8->Add(5, "prostoj", clRed);

	// Form1->Series7->Add(74, "Zak2", clBlue);
	// Form1->Series8->Add(30, "prostoj", clRed);

}

//// ---------------------------------------------------------------------------
//
void Cgrafy::graf5() { // WIP stats

	if (Form1->Memo1->Visible) {
		Form1->Chart5->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart5->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}

	Form1->Chart5->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width + Form1->Chart4->Width;
	Form1->Chart5->Width = Form1->ClientWidth / 5 * 1, 5; ;
	Form1->Chart5->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Chart5->AxisVisible = false;
	// Form1->Chart5->Visible = false;


	Form1->Label6->Visible = true;
	Form1->Label6->Font->Size = 25;
	Form1->Label6->Top = Form1->Chart5->Top + 70;
	Form1->Label6->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width + Form1->Chart4->Width + 70;

	Form1->Label7->Top = Form1->Chart5->Top + 70 - Form1->Label6->Font->Size;
	Form1->Label7->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width + Form1->Chart4->Width + 70;

	Form1->Label7->Visible = true;
	Form1->Label7->Font->Size = 25;
	Form1->Label7->Caption = "WIP";
	Form1->Label6->Caption = Form1->d.v.WIP();

	// Form1->Chart5->Title->Caption= Form1->d.v.WIP();

}
//// ---------------------------------------------------------------------------
//
// void Cgrafy::graf6() { // Buffery
//
// // defaultní vykreslení grafu (checkbox reší událost onclick)
// Form1->Chart5->Top = 500;
// Form1->Chart5->Left = Chart1->Width + Chart2->Width + Chart3->Width +
// Form1->Chart4->Width + 30;
// Form1->Chart5->Width = 200;
// Form1->Chart5->Height = 400;
//
// Form1->Chart5->AxisVisible = false;
//
// }

// ---------------------------------------------------------------------------
