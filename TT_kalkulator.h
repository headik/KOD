//---------------------------------------------------------------------------

#ifndef TT_kalkulatorH
#define TT_kalkulatorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm_TT_kalkulator : public TForm
{
__published:	// IDE-managed Components
	TButton *OK;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TEdit *Edit_hodin;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *Edit_smen;
	TEdit *Edit_dni;
	TEdit *Edit_produkty;
	TLabel *Label4;
	TLabel *Label6;
	TEdit *Edit_produktu_na_vozik;
	TGroupBox *GroupBox2;
	TLabel *Label5;
	TEdit *Edit_TT;
	TLabel *Label7;
	TEdit *Edit_TT_produktu;
	TLabel *Label9;
	TLabel *Label_nerelev;
	TButton *Button_TT_sec;
	TButton *Button_TP_sec;
	TLabel *Label11;
	TEdit *Edit_TP_produktu;
	TLabel *Label8;
	TLabel *Label10;
	TEdit *Edit_TP;
	TSpeedButton *Button_zamek_TT;
	TSpeedButton *Button_zamek_produkty;
	void __fastcall OKClick(TObject *Sender);
	void __fastcall Zadani_Change(TObject *Sender);
	void __fastcall Edit_TTChange(TObject *Sender);
	void __fastcall Button_TT_secClick(TObject *Sender);
	void __fastcall Button_TP_secClick(TObject *Sender);
	void __fastcall Edit_TPChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit_TT_produktuChange(TObject *Sender);
	void __fastcall Edit_TP_produktuChange(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall Button_zamek_TTClick(TObject *Sender);
	void __fastcall Button_zamek_produktyClick(TObject *Sender);

private:	// User declarations
	void getTT();
	void getProductCount();
	void getDays();
	bool OK_status;
public:		// User declarations
	__fastcall TForm_TT_kalkulator(TComponent* Owner);
	double TT;
	void editTT();
	void kontrola_zadani();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_TT_kalkulator *Form_TT_kalkulator;
//---------------------------------------------------------------------------
#endif
