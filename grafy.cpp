// ---------------------------------------------------------------------------

#pragma hdrstop

#include "grafy.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

void Cgrafy::ShowGrafy(bool stav) {
	if (stav) {
		nastaveni();
		graf1();
		graf2();
		graf3();
		graf4();
		graf5();
		graf6();
		nastaveni();
	}
	Form1->Chart1->Visible = stav;
	Form1->Chart2->Visible = stav;
	Form1->Chart3->Visible = stav;
	Form1->Chart4->Visible = stav;
	Form1->Chart5->Visible = false;
	Form1->Chart6->Visible = stav;
	Form1->Label6->Visible = stav;

}


void Cgrafy::nastaveni()
{
		//globalni nastaveni grafu
		Form1->Chart1->Legend->Visible = false;
		Form1->Chart1->Color = clWhite;
		Form1->Chart1->Title->Font->Size = 14;
		Form1->Chart1->LeftAxis->Title->Font->Size = 14;
		Form1->Chart1->BottomAxis->Title->Font->Size = 14;
		Form1->Chart1->Title->Color = clGray;
		Form1->Chart1->LeftAxis->Items->Format->Font->Size = 12;
		Form1->Chart1->BottomAxis->Items->Format->Font->Size = 12;
		Form1->Chart1->Border->Visible = false;
		//Form1->Chart3->LeftAxis->Items->Format->Width=1;
		Form1->Chart1->LeftAxis->Axis->Width=1;
		Form1->Chart1->BottomAxis->Axis->Width=1;

		 ///////////////////////////

		Form1->Chart2->Legend->Visible=Form1->Chart1->Legend->Visible;
		Form1->Chart2->Color=Form1->Chart1->Color;
		Form1->Chart2->Title->Font->Size=Form1->Chart1->Title->Font->Size;
		Form1->Chart2->LeftAxis->Title->Font->Size=Form1->Chart1->LeftAxis->Title->Font->Size;
		Form1->Chart2->BottomAxis->Title->Font->Size=Form1->Chart1->BottomAxis->Title->Font->Size;
		Form1->Chart2->Title->Color=Form1->Chart1->Title->Color;
		Form1->Chart2->LeftAxis->Items->Format->Font->Size=Form1->Chart1->LeftAxis->Items->Format->Font->Size;
		Form1->Chart2->BottomAxis->Items->Format->Font->Size=Form1->Chart1->BottomAxis->Items->Format->Font->Size;
		Form1->Chart2->Border->Visible=Form1->Chart1->Border->Visible;
		Form1->Chart2->LeftAxis->Axis->Width=Form1->Chart1->LeftAxis->Axis->Width;
		Form1->Chart2->BottomAxis->Axis->Width=Form1->Chart1->BottomAxis->Axis->Width;

		Form1->Chart3->Legend->Visible=Form1->Chart1->Legend->Visible;
		Form1->Chart3->Color=Form1->Chart1->Color;
		Form1->Chart3->Title->Font->Size=Form1->Chart1->Title->Font->Size;
		Form1->Chart3->LeftAxis->Title->Font->Size=Form1->Chart1->LeftAxis->Title->Font->Size;
		Form1->Chart3->BottomAxis->Title->Font->Size=Form1->Chart1->BottomAxis->Title->Font->Size;
		Form1->Chart3->Title->Color=Form1->Chart1->Title->Color;
		Form1->Chart3->LeftAxis->Items->Format->Font->Size=Form1->Chart1->LeftAxis->Items->Format->Font->Size;
		Form1->Chart3->BottomAxis->Items->Format->Font->Size=Form1->Chart1->BottomAxis->Items->Format->Font->Size;
		Form1->Chart3->Border->Visible=Form1->Chart1->Border->Visible;
		Form1->Chart3->LeftAxis->Axis->Width=Form1->Chart1->LeftAxis->Axis->Width;
		Form1->Chart3->BottomAxis->Axis->Width=Form1->Chart1->BottomAxis->Axis->Width;

		Form1->Chart4->Legend->Visible=Form1->Chart1->Legend->Visible;
		Form1->Chart4->Color=Form1->Chart1->Color;
		Form1->Chart4->Title->Font->Size=Form1->Chart1->Title->Font->Size;
		Form1->Chart4->LeftAxis->Title->Font->Size=Form1->Chart1->LeftAxis->Title->Font->Size;
		Form1->Chart4->BottomAxis->Title->Font->Size=Form1->Chart1->BottomAxis->Title->Font->Size;
		Form1->Chart4->Title->Color=Form1->Chart1->Title->Color;
		Form1->Chart4->LeftAxis->Items->Format->Font->Size=Form1->Chart1->LeftAxis->Items->Format->Font->Size;
		Form1->Chart4->BottomAxis->Items->Format->Font->Size=Form1->Chart1->BottomAxis->Items->Format->Font->Size;
		Form1->Chart4->Border->Visible=Form1->Chart1->Border->Visible;
		Form1->Chart4->LeftAxis->Axis->Width=Form1->Chart1->LeftAxis->Axis->Width;
		Form1->Chart4->BottomAxis->Axis->Width=Form1->Chart1->BottomAxis->Axis->Width;

		Form1->Chart5->Legend->Visible=Form1->Chart1->Legend->Visible;
		Form1->Chart5->Color=Form1->Chart1->Color;
		Form1->Chart5->Title->Font->Size=Form1->Chart1->Title->Font->Size;
		Form1->Chart5->LeftAxis->Title->Font->Size=Form1->Chart1->LeftAxis->Title->Font->Size;
		Form1->Chart5->BottomAxis->Title->Font->Size=Form1->Chart1->BottomAxis->Title->Font->Size;
		Form1->Chart5->Title->Color=Form1->Chart1->Title->Color;
		Form1->Chart5->LeftAxis->Items->Format->Font->Size=Form1->Chart1->LeftAxis->Items->Format->Font->Size;
		Form1->Chart5->BottomAxis->Items->Format->Font->Size=Form1->Chart1->BottomAxis->Items->Format->Font->Size;
		Form1->Chart5->Border->Visible=Form1->Chart1->Border->Visible;
		Form1->Chart5->LeftAxis->Axis->Width=Form1->Chart1->LeftAxis->Axis->Width;
		Form1->Chart5->BottomAxis->Axis->Width=Form1->Chart1->BottomAxis->Axis->Width;

		Form1->Chart6->Legend->Visible=Form1->Chart1->Legend->Visible;
		Form1->Chart6->Color=Form1->Chart1->Color;
		Form1->Chart6->Title->Font->Size=Form1->Chart1->Title->Font->Size;
		Form1->Chart6->LeftAxis->Title->Font->Size=Form1->Chart1->LeftAxis->Title->Font->Size;
		Form1->Chart6->BottomAxis->Title->Font->Size=Form1->Chart1->BottomAxis->Title->Font->Size;
		Form1->Chart6->Title->Color=Form1->Chart1->Title->Color;
		Form1->Chart6->LeftAxis->Items->Format->Font->Size=Form1->Chart1->LeftAxis->Items->Format->Font->Size;
		Form1->Chart6->BottomAxis->Items->Format->Font->Size=Form1->Chart1->BottomAxis->Items->Format->Font->Size;
		Form1->Chart6->Border->Visible=Form1->Chart1->Border->Visible;
		Form1->Chart6->LeftAxis->Axis->Width=Form1->Chart1->LeftAxis->Axis->Width;
		Form1->Chart6->BottomAxis->Axis->Width=Form1->Chart1->BottomAxis->Axis->Width;



}

void Cgrafy::graf1() {

	Form1->Chart1->Left = 0;
   //	Form1->Chart1->Color = clWhite;
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

	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku
	while (ukaz != NULL) {
		TPointD z = Form1->d.v.vrat_zacatek_a_konec_zakazky(ukaz);

		Form1->Series1->AddGanttColor(z.x, z.y, ukaz->n,
			AnsiString(z.x) + "-" + AnsiString(z.y) + "", ukaz->barva);

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

		Form1->Series3->Add(Form1->d.v.vrat_AVG_TT_zakazky(ukaz), ukaz->n,
			ukaz->barva);

		// Form1->Series3->Marks->St;

		ukaz = ukaz->dalsi;

	}

}

//// ---------------------------------------------------------------------------
void Cgrafy::graf3() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

	Form1->Chart3->Color = clWhite;

	if (Form1->Memo1->Visible) {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}

	Form1->Chart3->LeftAxis->Title->Caption = "min";
	Form1->Chart3->BottomAxis->Title->Caption = "plán";
	Form1->Chart3->Title->Caption = "Vytíženost zakázky";

	Form1->Chart3->Left = Form1->Chart1->Width + Form1->Chart2->Width;
	Form1->Chart3->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart3->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Series5->Clear();
	Form1->Series6->Clear();

	// Form1->Chart1->SaveToBitmapFile("obr");

	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	while (ukaz != NULL) {

		// int ve_vyrobe = Form1->d.v.vrat_AVGsumPT_zakazky(ukaz);
		// int cekani = Form1->d.v.vrat_AVGsumWT_zakazky(ukaz);

		Form1->Series5->Add(Form1->d.v.vrat_AVGsumPT_zakazky(ukaz), ukaz->n,
			ukaz->barva);
		Form1->Series6->Add(Form1->d.v.vrat_AVGsumWT_zakazky(ukaz), ukaz->n,
			clWhite);
		ukaz = ukaz->dalsi;
	}

}

//// ---------------------------------------------------------------------------
//
void Cgrafy::graf4() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

	Form1->Chart4->Color = clWhite;

	if (Form1->Memo1->Visible) {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}
	Form1->Chart4->Title->Caption = "Pomìr vozíkù";
	Form1->Chart4->LeftAxis->Title->Caption = "min";
	Form1->Chart4->BottomAxis->Title->Caption = "plán";

	Form1->Chart4->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width;
	Form1->Chart4->Width = Form1->ClientWidth / 5 * 1, 5;
	Form1->Chart4->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Series7->Clear();

	// souèet technolog. èasù vs souèet prostojù dle zakázek
	Cvektory::TSeznam_cest *ukaz = Form1->d.v.CESTY->dalsi;
	// Cvektory::TVozik *ukaz1 = Form1->d.v.VOZIKY->dalsi;
	while (ukaz != NULL) {

		Form1->Series7->Add(Form1->d.v.vrat_pocet_voziku_zakazky(ukaz), ukaz->n,
			ukaz->barva);

		ukaz = ukaz->dalsi;
	}

}

//// ---------------------------------------------------------------------------
//
void Cgrafy::graf5() {

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

	Form1->Label6->Visible = true;
	Form1->Label6->Font->Size = 25;
	Form1->Label6->Top = Form1->Chart5->Top - 35;
	Form1->Label6->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width + Form1->Chart4->Width + 70;

	Form1->Label6->Caption = "WIP: " + AnsiString(Form1->d.v.WIP());


}

//// ---------------------------------------------------------------------------
//
void Cgrafy::graf6() { // Kapacity

	if (Form1->Memo1->Visible) {
		Form1->Chart6->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart6->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height -
			Form1->Chart1->Height;
	}

	Form1->Chart6->Left = Form1->Chart1->Width * 4;
	Form1->Chart6->Width = Form1->ClientWidth / 5 * 1, 5; ;
	Form1->Chart6->Height = Form1->ClientHeight / 3 * 1, 5;

	Form1->Chart5->AxisVisible = true;

	Form1->Chart6->Title->Caption = "Doporuèené kapacity";
	Form1->Chart6->LeftAxis->Title->Caption = "kapacity";
	Form1->Chart6->BottomAxis->Title->Caption = "objekty";

	Form1->Label6->Visible = true;
	Form1->Label6->Font->Size = 25;
	Form1->Label6->Top = Form1->Chart5->Top - 35;
	Form1->Label6->Left = Form1->Chart1->Width + Form1->Chart2->Width +
		Form1->Chart3->Width + Form1->Chart4->Width + 70;

	Form1->Series9->Clear();

	Cvektory::TObjekt *ukaz = Form1->d.v.OBJEKTY->dalsi;
	// Cvektory::TVozik *ukaz1 = Form1->d.v.VOZIKY->dalsi;
	while (ukaz != NULL) {

		Form1->Series9->Add(ukaz->dop_kapacita_objektu, ukaz->short_name,
			clBlue);

		ukaz = ukaz->dalsi;
	}

}

// ---------------------------------------------------------------------------

