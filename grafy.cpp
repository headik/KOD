// ---------------------------------------------------------------------------

#pragma hdrstop

#include "grafy.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
void Cgrafy::ShowGrafy(bool stav)
{
		if (stav)
		{
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
		Form1->Chart5->Visible = stav;
	   //	Form1->CheckBox1->Visible = stav;
	   //	Form1->CheckBox2->Visible = stav;

	   //	Form1->CheckBox1->Top = 610;
	   //	Form1->CheckBox1->Left = Form1->Chart1->Width + Form1->Chart2->Width;
	   //	Form1->CheckBox2->Top = 610;
	   //	Form1->CheckBox2->Left = Form1->Chart1->Width;

}






void Cgrafy::graf1() {
//
	Form1->Chart1->Left = 0;
	Form1->Chart1->Width = Form1->ClientWidth/5*1,5;
	Form1->Chart1->Height = Form1->ClientHeight/3*1,5;
	Form1->Series1->Clear();

	if (Form1->Memo1->Visible) {
		Form1->Chart1->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart1->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Chart1->Height;
	}

	Form1->Chart1->Title->Caption = "Èasové stavy zakázky";

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

	Form1->Series1->AddGantt(0, 20, 1, "z1:0-20");
	Form1->Series1->AddGantt(15, 80, 2, "z2:15-80");
	Form1->Series1->AddGantt(60, 100, 3, "z3:60-100");
	Form1->Series1->AddGantt(60, 100, 4, "z4:60-100");
	Form1->Series1->AddGantt(90, 100, 5, "z5:90-100");
	// Series1->AddGantt();
	// Series2->Add(15,2,"z3",clYellow);

}

//// ---------------------------------------------------------------------------
void Cgrafy::graf2() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

    	if (Form1->Memo1->Visible) {
		Form1->Chart2->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart2->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Chart1->Height;
	}


	Form1->Chart2->Left = Form1->Chart1->Width+5;
	Form1->Chart2->Width = Form1->ClientWidth/5*1,5;
	Form1->Chart2->Height = Form1->ClientHeight/3*1,5;

	Form1->Series3->Clear();
	Form1->Series4->Clear(); // souèet technolog.èasù - celý plán výroby

	Form1->Series3->Add(9, "nav", clRed);
	Form1->Series3->Add(16, "co2", clRed);
	Form1->Series3->Add(28, "lak", clRed);
	Form1->Series3->Add(19, "vyt", clRed);
	Form1->Series3->Add(20, "lak2", clRed);
	Form1->Series3->Add(15, "vyt2", clRed);

}

//// ---------------------------------------------------------------------------
void Cgrafy::graf3() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)

    	if (Form1->Memo1->Visible) {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart3->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Chart1->Height;
	}

	Form1->Chart3->Left = Form1->Chart1->Width + Form1->Chart2->Width + 30;
	Form1->Chart3->Width = 400;
	Form1->Chart3->Height = 400;

	Form1->Series5->Clear();
	Form1->Series6->Clear(); // kapacity objektù - nadefinované vs. potøebná

	Form1->Series5->Add(2, "nav", clYellow);
	Form1->Series6->Add(5, "nav", clRed);
	Form1->Series5->Add(2, "lak", clYellow);
	Form1->Series6->Add(3, "lak", clRed);
	Form1->Series5->Add(2, "lak2", clYellow);
	Form1->Series6->Add(2, "lak2", clRed);

}
//// ---------------------------------------------------------------------------
//
void Cgrafy::graf4() {

	// defaultní vykreslení grafu (checkbox reší událost onclick)
    	if (Form1->Memo1->Visible) {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart4->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Chart1->Height;
	}

	Form1->Chart4->Left = Form1->Chart1->Width + Form1->Chart2->Width + Form1->Chart3->Width + 30;
	Form1->Chart4->Width = 400;
	Form1->Chart4->Height = 400;

	Form1->Series7->Clear();
	Form1->Series8->Clear();
	// souèet technolog. èasù vs souèet prostojù dle zakázek

	Form1->Series7->Add(20, "Zak1", clBlue);
	Form1->Series8->Add(5, "prostoj", clRed);

	Form1->Series7->Add(74, "Zak2", clBlue);
	Form1->Series8->Add(30, "prostoj", clRed);

}
//// ---------------------------------------------------------------------------
//
void Cgrafy::graf5() { // WIP stats


    	if (Form1->Memo1->Visible) {
		Form1->Chart5->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Memo1->Height - Form1->Chart1->Height;
	}
	else {
		Form1->Chart5->Top = Form1->ClientHeight - Form1->RzStatusBar1->Height - Form1->Chart1->Height;
	}

	Form1->Chart5->Left = Form1->Chart1->Width + Form1->Chart2->Width + Form1->Chart3->Width +
		Form1->Chart4->Width + 30;
	Form1->Chart5->Width = 200;
	Form1->Chart5->Height = 400;

	Form1->Chart5->AxisVisible = false;

}
//// ---------------------------------------------------------------------------
//
//void Cgrafy::graf6() { // Buffery
//
//	// defaultní vykreslení grafu (checkbox reší událost onclick)
//	Form1->Chart5->Top = 500;
//	Form1->Chart5->Left = Chart1->Width + Chart2->Width + Chart3->Width +
//		Form1->Chart4->Width + 30;
//	Form1->Chart5->Width = 200;
//	Form1->Chart5->Height = 400;
//
//	Form1->Chart5->AxisVisible = false;
//
//}
// ---------------------------------------------------------------------------
