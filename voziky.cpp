// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "voziky.h"
#include "unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzGrids"
#pragma resource "*.dfm"
TForm_vozik_nastaveni *Form_vozik_nastaveni;

// ---------------------------------------------------------------------------
__fastcall TForm_vozik_nastaveni::TForm_vozik_nastaveni(TComponent* Owner)
	: TForm(Owner) {

	offset = 0;

}

void TForm_vozik_nastaveni::hlavicka_barva() {
	TBarva *novy_uzel = new TBarva;

	novy_uzel->id_radek = 0;
	novy_uzel->barva_voziku = ColorDialog1->Color;

	novy_uzel->predchozi = novy_uzel; // ukazuje sam na sebe
	novy_uzel->dalsi = NULL;
	BARVY = novy_uzel;

}

void TForm_vozik_nastaveni::uloz_barvu() {
	TBarva *novy = new TBarva;

	novy->id_radek = RzStringGrid1->Row; // navýším poèítadlo prvku o jednièku
	novy->barva_voziku = ColorDialog1->Color;

	BARVY->predchozi->dalsi = novy;
	// poslednímu prvku pøiøadím ukazatel na nový prvek
	novy->predchozi = BARVY->predchozi;
	// novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi = NULL;
	BARVY->predchozi = novy;
	// nový poslední prvek zápis do hlavièky,body->predchozi zápis do hlavièky odkaz na poslední prvek seznamu "predchozi" v tomto pøípadì zavádìjicí

}

void TForm_vozik_nastaveni::uloz_barvu(TColor barva, int i) {
	TBarva *novy = new TBarva;

	// ShowMessage(barva);

	novy->id_radek = i; // navýším poèítadlo prvku o jednièku
	novy->barva_voziku = barva;

	BARVY->predchozi->dalsi = novy;
	// poslednímu prvku pøiøadím ukazatel na nový prvek
	novy->predchozi = BARVY->predchozi;
	// novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi = NULL;
	BARVY->predchozi = novy;
	// nový poslední prvek zápis do hlavièky,body->predchozi zápis do hlavièky odkaz na poslední prvek seznamu "predchozi" v tomto pøípadì zavádìjicí

}

void TForm_vozik_nastaveni::aktualizuj_barvu(TColor barva, int row) {
	TBarva *ukaz = BARVY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku
	// uloží do "spojáèku"



	while (ukaz != NULL) {
	  //	ShowMessage(ukaz->id_radek);
		//	ShowMessage(row);

		if (ukaz->id_radek == row) {
			ukaz->barva_voziku = barva;
		  //	ShowMessage(ukaz->id_radek);
          //  ShowMessage(row);

			break;
		}

		ukaz = ukaz->dalsi;
	}

}

// smaze bod ze seznamu
void TForm_vozik_nastaveni::smaz_barvu_radku(TBarva *Barva) {
	// vyøazení prvku ze seznamu a napojení prvku dalšího na prvek pøedchozí prku mazaného
	if (Barva->dalsi != NULL) // ošetøení proti poslednímu prvku
	{
		Barva->predchozi->dalsi = Barva->dalsi;
		Barva->dalsi->predchozi = Barva->predchozi;
	}
	else // poslední prvek
	{
		if (Barva->id_radek == 1) // pokud je mazaný prvek hned za hlavièkou
		{
			BARVY->predchozi = Barva->predchozi;
			// popø hlavièka bude ukazovat sama na sebe
			BARVY->dalsi = NULL;
		}
		else {
			Barva->predchozi->dalsi = NULL;
			BARVY->predchozi = Barva->predchozi;
			// zapis do hlavièky poslední prvek seznamu
		}
	}
}

void TForm_vozik_nastaveni::sniz_indexy(TBarva *Barva) {
	while (Barva != NULL) {
		Barva = Barva->dalsi; // posun na další prvek
		if (Barva != NULL)
			Barva->id_radek--;
		// sníží indexy nasledujicích bodù,protože optimalizace seznamu nefungovalo, navíc ušetøím strojový èas
	}

}

void TForm_vozik_nastaveni::vymaz_barvu() {
	long pocet_smazanych_objektu = 0;
	while (BARVY != NULL) {
		pocet_smazanych_objektu++;
		BARVY->predchozi = NULL;
		delete BARVY->predchozi;
		BARVY = BARVY->dalsi;
	};

};

// ---------------------------------------------------------------------------
void __fastcall TForm_vozik_nastaveni::FormShow(TObject *Sender)
{
 nacti_voziky();
}
// ---------------------------------------------------------------------------
void TForm_vozik_nastaveni::nacti_voziky()
{
	hlavicka_barva();

	OK_status = false;
	RowMoved = false;
	data_nalezena = false;
	// pokud je false - ve spojaku nejsou data, takze nize nastavim defaultni hodnoty pro pridani prvniho voziku
	Button_DEL->Visible = false;

	RzStringGrid1->Cols[0]->Add("Vozík");
	RzStringGrid1->Cols[0]->Add("1");
	RzStringGrid1->Rows[0]->Add("ID");
	RzStringGrid1->Rows[0]->Add("Délka");
	RzStringGrid1->Rows[0]->Add("Šíøka");
	RzStringGrid1->Rows[0]->Add("Cesta"); //použito pro trasu vozíku
	RzStringGrid1->Rows[0]->Add("Rotace");
	RzStringGrid1->Rows[0]->Add("Název");
	RzStringGrid1->Rows[0]->Add("Max ks");
	RzStringGrid1->Rows[0]->Add("Poèet ks");
	RzStringGrid1->Rows[0]->Add("Délka Max");
	RzStringGrid1->Rows[0]->Add("Šíøka Max");
	RzStringGrid1->Rows[0]->Add("Výška Max");
	RzStringGrid1->Rows[0]->Add("Barva");
	RzStringGrid1->Rows[0]->Add("Stav");

	Color_status = false;

	if (!data_nalezena) // ve spojaku nejsou data, pripravim si novy radek
	{ // default hodnoty
		RzStringGrid1->RowCount = 1;

		RzStringGrid1->Cells[0][1] = RzStringGrid1->RowCount++;
		RzStringGrid1->Cells[1][1] = RzStringGrid1->RowCount + 1;
		RzStringGrid1->Cells[2][1] = "1";
		RzStringGrid1->Cells[3][1] = "1";
		RzStringGrid1->Cells[4][1] = "1";
		RzStringGrid1->Cells[5][1] = "0";
		RzStringGrid1->Cells[6][1] = "název";
		RzStringGrid1->Cells[7][1] = "30";
		RzStringGrid1->Cells[8][1] = "30";
		RzStringGrid1->Cells[9][1] = "1";
		RzStringGrid1->Cells[10][1] = "1";
		RzStringGrid1->Cells[11][1] = "1";

		// defaultni barvy kreslim ve drawcell metode
	}

	Cvektory::TVozik *ukaz = Form1->d.v.VOZIKY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku
	if (ukaz != NULL) {

		RzStringGrid1->RowCount = Form1->d.v.VOZIKY->predchozi->n + 1;

		for (int i = 1; i < RzStringGrid1->RowCount; i++) {

			data_nalezena = true;
			// Memo3->Lines->Add(AnsiString("HlSpojak id disabled:") + ukaz->n);
			// akce s ukazatelem
			RzStringGrid1->Cells[0][i] = ukaz->n;
			RzStringGrid1->Cells[1][i] = ukaz->id;
			RzStringGrid1->Cells[2][i] = ukaz->delka;
			RzStringGrid1->Cells[3][i] = ukaz->sirka;
			RzStringGrid1->Cells[4][i] = ukaz->vyska;  //cesta vozíku  prozatím
			RzStringGrid1->Cells[5][i] = ukaz->rotace;
			RzStringGrid1->Cells[6][i] = ukaz->nazev_vyrobku;
			RzStringGrid1->Cells[7][i] = ukaz->max_vyrobku;
			RzStringGrid1->Cells[8][i] = ukaz->akt_vyrobku;
			RzStringGrid1->Cells[9][i] = ukaz->delka_vcetne_vyrobku;
			RzStringGrid1->Cells[10][i] = ukaz->sirka_vcetne_vyrobku;
			RzStringGrid1->Cells[11][i] = ukaz->vyska_vcetne_vyrobku;

			uloz_barvu(ukaz->barva, i);

			// posun na další prvek v seznamu
			ukaz = ukaz->dalsi;
		}
	}
	else { // když ve spojáku nic není, nastavím do ID defaultnì ID=1

		RzStringGrid1->Cells[1][1] = RzStringGrid1->RowCount - 1;
		RzStringGrid1->RowCount = 1;

	}
}
// ---------------------------------------------------------------------------
void __fastcall TForm_vozik_nastaveni::Button_OKClick(TObject *Sender)
{
	if(Form1->d.v.CESTY!=NULL && Form1->d.v.CESTY->predchozi->n>0) //pouze provizorní ošetøení
	OK_status = true;
	else
	Form1->S("Projekt je nutné naèíst z výpisu poslednì otevøených souboru v menu projekt, aby obsahoval cesty!");//pouze provizorní ošetøení
}
// -------------------------------------- -------------------------------------
void __fastcall TForm_vozik_nastaveni::FormCloseQuery(TObject *Sender,	bool &CanClose)
{
	if (OK_status && RzStringGrid1->RowCount >= 2)
	{
		uloz_voziky_a_nastav_zakazky();
	}
	vymaz_barvu();
}
// ---------------------------------------------------------------------------
void TForm_vozik_nastaveni::uloz_voziky_a_nastav_zakazky()
{
		Form1->d.v.vymaz_seznam_voziku();// smazu stary spojak pred ulozenim noveho
		Form1->d.v.hlavicka_voziky();// vytvorim si hlavicku pro zavedeni noveho spojaku

		TBarva *ukaz = BARVY->dalsi;
		for (int i = 1; i < RzStringGrid1->RowCount; i++)
		{
			//uložení parametrù vozíkù
			Form1->d.v.vloz_vozik(RzStringGrid1->Cells[0][i].ToInt(),
			RzStringGrid1->Cells[1][i],
			Form1->ms.MyToDouble(RzStringGrid1->Cells[2][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[3][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[4][i]), //sem ukladám výšku
			Form1->ms.MyToDouble(RzStringGrid1->Cells[5][i]),
			RzStringGrid1->Cells[6][i],
			Form1->ms.MyToDouble(RzStringGrid1->Cells[7][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[8][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[9][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[10][i]),
			Form1->ms.MyToDouble(RzStringGrid1->Cells[11][i]),
			ukaz->barva_voziku,
			Form1->d.v.vrat_cestu(Form1->ms.MyToDouble(RzStringGrid1->Cells[4][i]))
			);

			//uloží do cesty barvu cesty-zakázky dle vozíku
			Form1->d.v.vrat_cestu(Form1->ms.MyToDouble(RzStringGrid1->Cells[4][i]))->barva=ukaz->barva_voziku;

			//posun na další prvek v seznamu
			ukaz = ukaz->dalsi; //posun na další prvek v seznamu
		}
		Form1->Invalidate();
}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::RzStringGrid1MouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	int Column, Row;

	Column = RzStringGrid1->Col;
	Row = RzStringGrid1->Row;

	if (Column == 12 && Row >= 1) {

		if (ColorDialog1->Execute()) {

			if (RzStringGrid1->RowCount == 2) {

				// Memo2->Lines->Add(AnsiString("RADEK_ID_uloz:") + RzStringGrid1->Row);

				RzStringGrid1->Canvas->Brush->Color = ColorDialog1->Color;
				RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(12,
					RzStringGrid1->Row));
				// ShowMessage(ColorDialog1->Color);
				aktualizuj_barvu(ColorDialog1->Color, RzStringGrid1->Row);
			}
			else {
				// aktualizuj_barvu(ColorDialog1->Color, RzStringGrid1->Row);
				RzStringGrid1->Canvas->Brush->Color = ColorDialog1->Color;
				RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(12,
					RzStringGrid1->Row));
				aktualizuj_barvu(ColorDialog1->Color, RzStringGrid1->Row);

				Color_status = true;
			}
		}

	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::RzStringGrid1DrawCell(TObject *Sender,
	int ACol, int ARow, TRect &Rect, TGridDrawState State) {

	RzStringGrid1->FixedCols = 1;

	RzStringGrid1->FocusColor = clWhite;

	TForm_vozik_nastaveni::TBarva *ukaz2 = BARVY->dalsi;

	if (ukaz2 == NULL && RzStringGrid1->RowCount == 2)
		// pokracovani defaultnich hodnot pro novy vozik
	{

		RzStringGrid1->Canvas->Brush->Color = clBlue;
		uloz_barvu(RzStringGrid1->Canvas->Brush->Color, 1);
		RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(12, 1));

		RzStringGrid1->Canvas->Brush->Color = clWhite;
		RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(13, 1));

	}

	if (RowMoved) {
		for (int i = 1; i < RzStringGrid1->RowCount; i++)
			RzStringGrid1->Cells[0][i] = i;
		RowMoved = false;
	}

	TForm_vozik_nastaveni::TBarva *ukaz = BARVY->dalsi;
	Cvektory::TVozik *ukaz1 = Form1->d.v.VOZIKY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku

	while (ukaz != NULL) {

		// ShowMessage("uka barvu");
		RzStringGrid1->Canvas->Brush->Color = ukaz->barva_voziku;
		RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(12,
			ukaz->id_radek));

		if (ukaz1 != NULL) {
			switch (ukaz1->stav) {

			default:
				RzStringGrid1->Canvas->Brush->Color = clWhite;
				break;
			case 0:
				RzStringGrid1->Canvas->Brush->Color = clRed;
				break;
			case 1:
				RzStringGrid1->Canvas->Brush->Color = clYellow;
				break;
			case 2:
				RzStringGrid1->Canvas->Brush->Color = clGreen;
				break;
			}

			RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(13,
				ukaz->id_radek));
			ukaz1 = ukaz1->dalsi;
		}
		else {

			RzStringGrid1->Canvas->Brush->Color = clWhite;
			// natvrdo nastavena bila pri nove zadanem voziku
			RzStringGrid1->Canvas->FillRect(RzStringGrid1->CellRect(13,
				ukaz->id_radek));
		}

		ukaz = ukaz->dalsi; // posun na další prvek v seznamu

	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::Button1Click(TObject *Sender) {
	RzStringGrid1->ColCount++;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::Button2Click(TObject *Sender) {
	RzStringGrid1->ColCount--;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::Button3Click(TObject *Sender)

{

	RzStringGrid1->RowCount++;
	RzStringGrid1->Cols[0]->Add(RzStringGrid1->RowCount - 1);

	if (RzStringGrid1->RowCount > 2) {
		TBarva *ukaz = BARVY->predchozi;

		int i = RzStringGrid1->RowCount - 1;

		RzStringGrid1->Cells[1][i] = i;
		RzStringGrid1->Cells[2][i] = RzStringGrid1->Cells[2][i - 1];
		RzStringGrid1->Cells[3][i] = RzStringGrid1->Cells[3][i - 1];
		RzStringGrid1->Cells[4][i] = RzStringGrid1->Cells[4][i - 1];
		RzStringGrid1->Cells[5][i] = RzStringGrid1->Cells[5][i - 1];
		RzStringGrid1->Cells[6][i] = RzStringGrid1->Cells[6][i - 1];
		RzStringGrid1->Cells[7][i] = RzStringGrid1->Cells[7][i - 1];
		RzStringGrid1->Cells[8][i] = RzStringGrid1->Cells[8][i - 1];
		RzStringGrid1->Cells[9][i] = RzStringGrid1->Cells[9][i - 1];
		RzStringGrid1->Cells[10][i] = RzStringGrid1->Cells[10][i - 1];
		RzStringGrid1->Cells[11][i] = RzStringGrid1->Cells[11][i - 1];
		RzStringGrid1->Cells[12][i] = RzStringGrid1->Cells[12][i - 1];
		uloz_barvu(ukaz->barva_voziku, i);

	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm_vozik_nastaveni::RzStringGrid1RowMoved(TObject *Sender,
	int FromIndex, int ToIndex) {
	TColor ColorFromIndex, ColorToIndex;
	TBarva *ukaz = BARVY->dalsi;

	while (ukaz != NULL) {
		if (ukaz->id_radek == FromIndex)
			ColorFromIndex = ukaz->barva_voziku;
		if (ukaz->id_radek == ToIndex)
			ColorToIndex = ukaz->barva_voziku;
		ukaz = ukaz->dalsi; // posun na další prvek v seznamu
	}

	TBarva *ukaz1 = BARVY->dalsi;
	while (ukaz1 != NULL) {
		if (ukaz1->id_radek == FromIndex)
			ukaz1->barva_voziku = ColorToIndex;
		if (ukaz1->id_radek == ToIndex)
			ukaz1->barva_voziku = ColorFromIndex;
		ukaz1 = ukaz1->dalsi; // posun na další prvek v seznamu
	}

	RowMoved = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::Memo_spojakClick(TObject *Sender) {

	TBarva *ukaz = BARVY->dalsi;
	while (ukaz != NULL) {
		Memo1->Lines->Add(AnsiString("id_radek: ") + ukaz->id_radek +
			AnsiString(" barva: ") + ukaz->barva_voziku);

		ukaz = ukaz->dalsi;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm_vozik_nastaveni::RzStringGrid1GetEditMask(TObject *Sender,
	int ACol, int ARow, UnicodeString &Value)

{ // maska pro validaci zaznamu

	if (RzStringGrid1->Col == 1) // ID   - rùzné alfanumerické znaky
			Value = "AAAAAAAAAA";

	if (RzStringGrid1->Col == 2) // Delka  - sežere pouze èíslo
			Value = "0000";

	if (RzStringGrid1->Col == 3) // Sirka
			Value = "0000";

	if (RzStringGrid1->Col == 4) // Vyska
			Value = "0000";

	if (RzStringGrid1->Col == 5) // Rotace
			Value = "00";

	if (RzStringGrid1->Col == 6) // Nazev
			Value = "AAAAAAA";

	if (RzStringGrid1->Col == 7) // Max ks
			Value = "0000";

	if (RzStringGrid1->Col == 8) // Akt kusu
			Value = "0000";

	if (RzStringGrid1->Col == 9) // Max delka
			Value = "0000";
	if (RzStringGrid1->Col == 10) // Max sirka
			Value = "0000";
	if (RzStringGrid1->Col == 11) // Max vyska
			Value = "0000";

}
// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::Button_DELClick(TObject *Sender) {

	// Tlaèítko na smazání øádku
	RzStringGrid1->Rows[RzStringGrid1->Row]->Clear();

	TForm_vozik_nastaveni::TBarva *ukaz = BARVY->dalsi;
	// ukazatel na první objekt v seznamu OBJEKTU, pøeskoèí hlavièku
	while (ukaz != NULL) {

		if (ukaz->id_radek == RzStringGrid1->Row) {
			smaz_barvu_radku(ukaz);
			sniz_indexy(ukaz);

			// ukaz=NULL;
			// delete ukaz;  //smazani ukazatele nejak nefungovalo
			break;

		}
		// posun na další prvek v seznamu
		ukaz = ukaz->dalsi;
	}

	// posun øádkù

	for (int row = RzStringGrid1->Row; row < RzStringGrid1->RowCount - 1; ++row)

	{
		RzStringGrid1->Rows[row] = RzStringGrid1->Rows[row + 1];
		//  Memo1->Lines->Add(row);
		//  Memo1->Lines->Add(RzStringGrid1->Row+1);
	  // aktualizuj_barvu(ukaz->barva_voziku,RzStringGrid1->Row+1);

	}

	RzStringGrid1->RowCount--;
	// vykrleseni noveho poradi (n)
	for (UINT i = 1; i < RzStringGrid1->RowCount; i++)
		RzStringGrid1->Cells[0][i] = i;

}
// */

// ---------------------------------------------------------------------------

void __fastcall TForm_vozik_nastaveni::RzStringGrid1Click(TObject *Sender) {

	Button_DEL->Visible = true;
	Button_DEL->Top = RzStringGrid1->Top + RzStringGrid1->Row * 19 + 1;

}
// ---------------------------------------------------------------------------


void __fastcall TForm_vozik_nastaveni::Button_OKKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	UINT funkcni_klavesa=0;
	switch(Key)
	{
		//BACKSPACE
		case 8: break;
		//ENTER
		case 13:break;
		//ESC
		case 27:Close();break;
		//MEZERNÍK
		case 32:break;
		//PAGE UP
		case 33:;break;
		//PAGE DOWN
		case 34:break;
		//END
		case 35:break;
		//HOME
		case 36:break;
		//ŠIPKA DOLÙ
		case 40:break;
		//ŠIPKA LEVÁ
		case 37:break;
		//ŠIPKA PRAVÁ
		case 39:break;
		//ŠIPKA NAHORU
		case 38:break;
		//ŠIPKA DOLÙ
		case 98:break;
		//ŠIPKA LEVÁ
		case 100:break;
		//ŠIPKA PRAVÁ
		case 102:break;
		//ŠIPKA NAHORU
		case 104:break;
		//CTRL, SHIFT
		default:
		{
			if(Shift.Contains(ssShift) && Shift.Contains(ssCtrl)){funkcni_klavesa=3;}//SHIFT + CTRL
			else
			{
				if(Shift.Contains(ssShift)){funkcni_klavesa=2;}//SHIFT
				if(Shift.Contains(ssCtrl)){funkcni_klavesa=1;}//CTRL
			}
			break;
		}
	}
}
//---------------------------------------------------------------------------

