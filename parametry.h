//---------------------------------------------------------------------------

#ifndef parametryH
#define parametryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_parametry : public TForm
{
__published:	// IDE-managed Components
	TButton *Button_OK;
	TValueListEditor *ValueListEditor;
	TLabel *Label_CT;
	TComboBox *ComboBox_druh_objektu;
	TLabel *Label_rezim;
	TLabel *Label_technologicke_parametry;
	TLabel *Label_kapacita;
	TLabel *Label_kapacita_hodnota;
	TLabel *Label_CT_hodnota;
	TComboBox *ComboBox_dopravnik;
	TLabel *Label_vypis;
	TLabel *Label_TT;
	TLabel *Label_TT_hodnota;
	TGroupBox *GroupBox_voziky;
	TGroupBox *GroupBox_orientace_voziku;
	TImage *Image_vozik;
	TRadioButton *RadioButton_na_delku;
	TRadioButton *RadioButton_na_sirku;
	TGroupBox *GroupBox_vzdalenost;
	TEdit *Edit_vzdalenost_voziku;
	TLabel *Label3;
	TButton *Button_min_sec;
	TLabel *Label_delka_prepravniku;
	TLabel *Label_delka_prepravniku_hodnota;
	TButton *Button_DEL;
	TEdit *Edit_name;
	TEdit *Edit_shortname;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Edit_CTKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ValueListEditorStringsChange(TObject *Sender);
	void __fastcall ComboBox_druh_objektuChange(TObject *Sender);
	void __fastcall ComboBox_dopravnikChange(TObject *Sender);
	void __fastcall RadioButton_na_delkuClick(TObject *Sender);
	void __fastcall RadioButton_na_sirkuClick(TObject *Sender);
	void __fastcall Image_vozikClick(TObject *Sender);
	void __fastcall ValueListEditorClick(TObject *Sender);
	void __fastcall Edit_vzdalenost_vozikuChange(TObject *Sender);
	void __fastcall Button_min_secClick(TObject *Sender);
	void __fastcall Button_DELClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit_nameChange(TObject *Sender);
	void __fastcall Edit_vzdalenost_vozikuKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);



private:	// User declarations
	enum Tminsec{MIN=0,SEC};Tminsec minsec;
	double get_sum();

	void get_capacity(unsigned int input);

	UnicodeString SG,K,P;
	unsigned short novy_parametr_n;
	short offset;

public:		// User declarations
	__fastcall TForm_parametry(TComponent* Owner);
	void vykresli_vozik(bool na_delku=true);
	void setForm4Rezim(unsigned short rezim,bool default_text=true);
	short dopravnik_typ;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_parametry *Form_parametry;
//---------------------------------------------------------------------------
#endif
