//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "RzPanel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "RzSplit.hpp"
#include "RzStatus.hpp"
#include <Vcl.Grids.hpp>
#include "my.h"
#include "vykresli.h"
#include "grafy.h"
#include "RzButton.hpp"
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include "RzBorder.hpp"
#include <Vcl.Dialogs.hpp>
#include "MyString.h"
#include <Vcl.ExtDlgs.hpp>
#include "RzBHints.hpp"
#include "RzGrids.hpp"
#include <VCLTee.GanttCh.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//#include "vektory.h" //už vkládám přes vykresli.h
//#include "knihovna_objektu.h" //už vkládám přes vykresli.h resp. vektory.h

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TPopupMenu *PopupMenu1;
	TRzToolbar *RzToolbar1;
	TRzStatusBar *RzStatusBar1;
	TMenuItem *Projekt1;
	TMenuItem *Pohled1;
	TMenuItem *Knihovna1;
	TMenuItem *Npovda1;
	TMenuItem *NovySoubor;
	TMenuItem *Otevrit;
	TMenuItem *Ulozit;
	TMenuItem *Ulozitjako;
	TMenuItem *N1;
	TMenuItem *Konec1;
	TRzSizePanel *RzSizePanel_knihovna_objektu;
	TMenuItem *Nastaven1;
	TMenuItem *Vzhled1;
	TMenuItem *Klasick1;
	TMenuItem *WinXP1;
	TMenuItem *Gradientn1;
	TRzStatusPane *RzStatusPane1;
	TRzStatusPane *RzStatusPane2;
	TMenuItem *Nastvitparametry1;
	TMenuItem *Smazat1;
	TRzSizePanel *RzSizePanel_parametry_projekt;
	TRzStatusPane *RzStatusPane3;
	TRzStatusPane *RzStatusPane4;
	TDrawGrid *DrawGrid_knihovna;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit_takt_time;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *Md1;
	TMenuItem *editacelinky1;
	TMenuItem *testovnkapacity1;
	TMenuItem *casoverezervy1;
	TLabel *Label5;
	TMenuItem *Mrizka;
	TButton *Button1;
	TMenuItem *Piblit1;
	TMenuItem *Oddlit1;
	TMenuItem *N4;
	TMenuItem *Predchozipohled1;
	TMenuItem *N5;
	TMenuItem *Priblizit2;
	TMenuItem *Oddalit2;
	TMenuItem *Posunout2;
	TMenuItem *Posouvat1;
	TMenuItem *N6;
	TMenuItem *Vybratoknem1;
	TMenuItem *Posouvat2;
	TMenuItem *Posunout3;
	TMenuItem *Vybratoknem2;
	TImageList *ImageList1;
	TRzToolButton *RzToolButton1;
	TRzToolButton *RzToolButton2;
	TRzToolButton *RzToolButton3;
	TRzSpacer *RzSpacer1;
	TRzToolButton *RzToolButton4;
	TRzToolButton *RzToolButton5;
	TRzToolButton *RzToolButton6;
	TRzToolButton *RzToolButton7;
	TRzToolButton *RzToolButton8;
	TRzToolButton *RzToolButton9;
	TRzSpacer *RzSpacer2;
	TRzToolButton *RzToolButton10;
	TRzToolButton *RzToolButton11;
	TRzToolButton *RzToolButton12;
	TMemo *Memo1;
	TMenuItem *Ve1;
	TRzStatusPane *RzStatusPane5;
	TSaveDialog *SaveDialog;
	TOpenDialog *OpenDialog1;
	TTimer *Timer_backup;
	TMenuItem *Obnovitzezlohy1;
	TMenuItem *Otevritsablonu;
	TMenuItem *Export1;
	TSavePictureDialog *SavePictureDialog1;
	TButton *Button_kalkulatorTT;
	TLabel *Label8;
	TButton *Button_dopravnik_parametry;
	TButton *Button_vozik_parametry;
	TMenuItem *Obnovitobraz1;
	TMenuItem *Report1;
	TMenuItem *csv1;
	TMenuItem *html1;
	TMenuItem *simulace1;
	TTimer *Timer_simulace;
	TMenuItem *Vypicestuktempu1;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TMenuItem *casovosa1;
	TChart *Chart1;
	TChart *Chart2;
	TChart *Chart3;
	TChart *Chart4;
	TCheckBox *CheckBoxPALCE;
	TLabel *Label6;
	TChart *Chart5;
	TGanttSeries *Series2;
	TGanttSeries *Series1;
	TLabel *Label7;
	TBarSeries *Series3;
	TBarSeries *Series4;
	TBarSeries *Series7;
	TBarSeries *Series8;
	TBarSeries *Series5;
	TBarSeries *Series6;
	TPanel *Panel1;
	TMenuItem *technologickprocesy1;
	TMenuItem *Rychlexport1;
	TMenuItem *Zobrazitparametry1;
	TButton *Button11;
	TMenuItem *N2;
	TMenuItem *Magna;
	TMenuItem *SPPP1;
	TMenuItem *Boskovice1;
	TMenuItem *eXtreme1;
	TButton *Button2;
	TTimer *Timer_neaktivity;
	TButton *Button12;
	TTimer *Timer_animace;
	void __fastcall Konec1Click(TObject *Sender);
	void __fastcall Klasick1Click(TObject *Sender);
	void __fastcall WinXP1Click(TObject *Sender);
	void __fastcall Gradientn1Click(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall DrawGrid_knihovnaDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall testovnkapacity1Click(TObject *Sender);
	void __fastcall casoverezervy1Click(TObject *Sender);
	void __fastcall editacelinky1Click(TObject *Sender);
	void __fastcall DrawGrid_knihovnaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall MrizkaClick(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DrawGrid_knihovnaMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall DrawGrid_knihovnaMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
	void __fastcall DrawGrid_knihovnaMouseLeave(TObject *Sender);
	void __fastcall DrawGrid_knihovnaKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DrawGrid_knihovnaKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall RzSizePanel_knihovna_objektuMouseEnter(TObject *Sender);
	void __fastcall Piblit1Click(TObject *Sender);
	void __fastcall Oddlit1Click(TObject *Sender);
	void __fastcall Predchozipohled1Click(TObject *Sender);
	void __fastcall Priblizit2Click(TObject *Sender);
	void __fastcall Oddalit2Click(TObject *Sender);
	void __fastcall Posouvat1Click(TObject *Sender);
	void __fastcall Posunout2Click(TObject *Sender);
	void __fastcall Vybratoknem1Click(TObject *Sender);
	void __fastcall Vybratoknem2Click(TObject *Sender);
	void __fastcall Posouvat2Click(TObject *Sender);
	void __fastcall Posunout3Click(TObject *Sender);
	void __fastcall RzToolButton8Click(TObject *Sender);
	void __fastcall RzToolButton9Click(TObject *Sender);
	void __fastcall RzToolButton11Click(TObject *Sender);
	void __fastcall Smazat1Click(TObject *Sender);
	void __fastcall Nastvitparametry1Click(TObject *Sender);
	void __fastcall RzStatusPane5Click(TObject *Sender);
	void __fastcall Edit_takt_timeChange(TObject *Sender);
	void __fastcall Edit_pocet_vozikuChange(TObject *Sender);
	void __fastcall UlozitClick(TObject *Sender);
	void __fastcall UlozitjakoClick(TObject *Sender);
	void __fastcall OtevritClick(TObject *Sender);
	void __fastcall NovySouborClick(TObject *Sender);
	void __fastcall Timer_backupTimer(TObject *Sender);
	void __fastcall Obnovitzezlohy1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall OtevritsablonuClick(TObject *Sender);
	void __fastcall Export1Click(TObject *Sender);
	void __fastcall Button_kalkulatorTTClick(TObject *Sender);
	void __fastcall Button_dopravnik_parametryClick(TObject *Sender);
	void __fastcall Button_vozik_parametryClick(TObject *Sender);
	void __fastcall Edit_takt_timeEnter(TObject *Sender);
	void __fastcall Obnovitobraz1Click(TObject *Sender);
	void __fastcall csv1Click(TObject *Sender);
	void __fastcall html1Click(TObject *Sender);
	void __fastcall simulace1Click(TObject *Sender);
	void __fastcall RzStatusPane1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer_simulaceTimer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Vypicestuktempu1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall casovosa1Click(TObject *Sender);
	void __fastcall FormShortCut(TWMKey &Msg, bool &Handled);
	void __fastcall CheckBoxPALCEClick(TObject *Sender);
	void __fastcall Chart1Click(TObject *Sender);
	void __fastcall technologickprocesy1Click(TObject *Sender);
	void __fastcall PopupMenu1Popup(TObject *Sender);
	void __fastcall Zobrazitparametry1Click(TObject *Sender);
	void __fastcall MagnaClick(TObject *Sender);
	void __fastcall Rychlexport1Click(TObject *Sender);
	void __fastcall SPPP1Click(TObject *Sender);
	void __fastcall Boskovice1Click(TObject *Sender);
	void __fastcall eXtreme1Click(TObject *Sender);
	void __fastcall casovevytizenostiobjektu1Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer_neaktivityTimer(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Timer_animaceTimer(TObject *Sender);


private:	// User declarations
	////struktury, výčty
	enum Tedice{DEVELOPER,BUSINESS,CLIENT,VIEWER};Tedice EDICE;
	enum Tmod{NO=0,EDITACE,TESTOVANI,REZERVY,CASOVAOSA,TECHNOPROCESY,SIMULACE};Tmod MOD;
	enum Takce{NIC=0,PAN,PAN_MOVE,ZOOM_W,ZOOM_W_MENU,ADD,MOVE};Takce Akce;
	enum TKurzory {standard=0,posun_v,posun_b,posun_p,posun_l,posun_t,kalibrovat,pan,pan_move,window,add_o};
	struct Tnastaveni{bool autosave;unsigned short int minut;bool posledni_file;};Tnastaveni nastaveni;

	////instance
	Graphics::TBitmap *Pan_bmp;
	Cvektory::TObjekt *pom;
	Cvektory::TProces *proces_pom;

	////metody
	void edice();
	void setVisualStyle(TRzVisualStyle VisualStyle=vsClassic);
	short int MB(UnicodeString text, unsigned short int typ=0,UnicodeString titulek="TISPL - Eltep");//vola rychle messabox
	void REFRESH();
	void ESC();
	void UP();void DOWN();void RIGHT();void LEFT();void Uloz_predchozi_pohled();//realizují posuny obrazu
	void ZOOM_IN();//přiblížení
	void ZOOM_OUT();//oddálení
	void ZOOM();//samotný ZOOM
	void ZOOM_WINDOW();//přiblížení oknem
	void zneplatnit_minulesouradnice();
	void kurzor(TKurzory typ_kurzor);
	void pan_map(TCanvas * canv, int X, int Y);
	void pan_move_map();
	void add_objekt(int X, int Y);
	Cvektory::TObjekt *add_objekt_za();
	void move_objekt(int X, int Y);
	void zobraz_tip(UnicodeString text);
	void akutalizace_stavu_prichytavani_vSB();
	void vytvor_hlavicku_souboru();
	void Ulozit_soubor();//samotné uložení
	void OtevritSoubor();//realizuje otevření opendialogu s následným voláním realizace samotného otevření souboru
	unsigned short int OtevritSoubor(UnicodeString soubor);//realizuje samotné otevření souboru
	void ulozit_posledni_otevreny();//uloží do ini nazev posledního pracovního souboru
	void vse_odstranit();
	UnicodeString get_computer_name();
	UnicodeString get_user_name();
	UnicodeString get_temp_dir();
	void nacist_nastaveni();
	void ulozit_nastaveni();
	void zavrit_uvod();//zavře úvodní dialog
	int vrat_max_vysku_grafu();
	void nastaveni_grafickeho_vystupu(Graphics::TBitmap * Bitmap);

	////proměnné
	int size_grid;

	int vybrany_objekt;

	TPoint akt_souradnice_kurzoru_PX;//uchová aktuální pozici kurzoru
	TPointD akt_souradnice_kurzoru;//uchová aktuální pozici kurzoru v logických jednotkách, resp. souřadnicích
	TPoint vychozi_souradnice_kurzoru;//uchová výchozí pozici kurzoru
	TPoint predchozi_souradnice_kurzoru;//uchová původní pozici kurzoru při stisku tlačítka myši
	TPoint minule_souradnice_kurzoru;//uchová původní souřadnice při posunu

	bool pan_non_locked;
	bool stisknute_leve_tlacitko_mysi;//uchovává stav levého tlačítka myši
	unsigned short int funkcni_klavesa;//uchovává stav poslední stisknuté funkční klávesy
	unsigned short int vyska_menu;

	double Zoom_predchozi;
	TPointD Posun_predchozi;
	short prichytavat_k_mrizce;
	bool uchop_zobrazen;
	bool vycentrovat;
	bool posun_objektu;
	bool probehl_zoom;
	bool add_posledni;
	bool upozornovat_na_zmenu_TT_parametru;

	bool duvod_k_ulozeni;
	bool stisknuto_storno;
	short pocitadlo_doby_neaktivity;

	UnicodeString FileName;


public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
  struct T_parametry_projektu{double TT;double hodin;double smen;double dni;unsigned int produktu_vozik;double delka_voziku;double sirka_voziku;};T_parametry_projektu PP;
	double m2px;//uchovává hodnotu prostorového rozlišení programu, nativní rozlišení 0,1 m na 1 pixel při zoomu 1x
	TMyString ms;
	Cmy m;
	Cvykresli d;
	Cgrafy g;
	double Zoom; //proměnná uchovávajicí velikost Zoomu
	TPointD Posun;//proměnné uchovávajicí velikost posunu obrazu (pro scrollování atp.), je to ve fyzických souřadnicích zařízení
  bool grid;
	bool zobrazit_barvy_casovych_rezerv;
	void DuvodUlozit(bool stav);
	void SB(UnicodeString Text, unsigned short Pane=4);//domnívám se, že zde má být hodnota 5
	void S(UnicodeString Text="");//Usnadňuje přístup k ShowMessage
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern AnsiString Parametry; //příjímá parametry programu, důležité pro otevírání programu konrkétním souborem
//---------------------------------------------------------------------------
#endif
