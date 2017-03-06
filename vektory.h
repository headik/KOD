//---------------------------------------------------------------------------
#ifndef vektoryH
#define vektoryH
#include <vcl.h>
#include "knihovna_objektu.h"
//#include "math.h"
//#include "my.h"
//#define TITULEK "Omap editor"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

class Cvektory
{
  private:

  public:

		struct TObjekt
		{
			unsigned int n; //pořadí objektu ve spoj.seznamu
			unsigned int id;   //id typu objektu
			UnicodeString short_name;  //krátký název
			UnicodeString name;  //celý název objektu
			double X, Y;
			unsigned short rezim;//rezim objektu 0-S&G,1-Kontin.(line tracking),2-Postprocesní,3-stopka
			double TTo; //takt time objektu
			double CT; //cycle time
			short stav;//0 - stop 2 - vozík může jet
			unsigned short orientace_voziku; //0-na délku, 1- na šířku
			double vzdalenost; //mezera mezi vozíky
			short typ_dopravniku;
			double delka_dopravniku;
			double kapacita_objektu;
			UnicodeString techn_parametry;//obsah valuestringlistu, nelze ukládát pouze jednotlivá data, protože se seznam může u S&G měnit
			struct TObjekt *predchozi;
			struct TObjekt *dalsi;
		};
		TObjekt *OBJEKTY;

		struct TVozik
		{
			unsigned int n; //pořadí objektu ve spoj.seznamu
			UnicodeString id;   //id typu objektu
			double delka;
			double sirka;
			double vyska;
			double rotace;
			UnicodeString nazev_vyrobku;
			double max_vyrobku;
			double akt_vyrobku;
			double delka_vcetne_vyrobku;
			double sirka_vcetne_vyrobku;
			double vyska_vcetne_vyrobku;
			short stav;//-1 - není na lince, 0 - stop, 1 - čeká, 2 - jede
			TColor barva;
			double pozice;
			double X;
			double Y;
			struct TObjekt *segment;
			double timer;
			struct TVozik *predchozi;
			struct TVozik *dalsi;
		};
		TVozik *VOZIKY;

		struct TPalec
		{
			unsigned long n; //pořadí objektu ve spoj.seznamu
			double pozice;
			struct TObjekt *segment;
			struct TPalec *predchozi;
			struct TPalec *dalsi;
		};
		TPalec *PALCE;

		struct TFile_hlavicka
		{
					unsigned short int Verze;
          unsigned short int Mod;
					double Zoom;
					long PosunutiX;//proměnné uchovávajicí velikost posunu obrazu (pro scrollování atp.), je to ve fyzických souřadnicích zařízení
          long PosunutiY;//proměnné uchovávajicí velikost posunu obrazu (pro scrollování atp.), je to ve fyzických souřadnicích zařízení
					unsigned int pocet_objektu;
					unsigned int pocet_voziku;
					//parametry projektu:
					double TT;
					double hodin;
					double smen;
					double dni;
					unsigned int produktu_vozik;
					double delka_voziku;
					double sirka_voziku;
					unsigned int delka_textu_prepravniky;
		};
		TFile_hlavicka File_hlavicka;

		UnicodeString seznam_dopravniku;

		Cvektory();//konstruktor
		void hlavicka_prvky();
		short vloz_objekt(unsigned int id, double X, double Y);//vloží prvek do seznamu
		short vloz_objekt(TObjekt *Objekt);//přetížená fce
		short vloz_objekt(unsigned int id, double X, double Y,TObjekt *p);//přetížená fce
		TObjekt *najdi_bod(double X, double Y,double offsetX, double offsetY);//hledá bod v dané oblasti
		short smaz_bod(TObjekt *Objekt);//smaže prvek ze seznamu
		void sniz_indexy(TObjekt *Objekt);
		void zvys_indexy(TObjekt *Objekt);
		double delka_dopravniku(Cvektory::TObjekt *ukaz);
		void aktualizace_indexu_uzitych_dopravniku(short item_index);
		bool kontrola_existence_dopravniku(short item_index);
		long vymaz_seznam();
		short int uloz_do_souboru(UnicodeString FileName);
		short int nacti_ze_souboru(UnicodeString FileName);
		short int ulozit_report(UnicodeString FileName);
		void hlavicka_voziky();
		void vloz_vozik();//přidá nový prázdný - nedefinovaný vozík do seznamu VOZIKY
    void vloz_vozik(TVozik *Vozik);
		void vloz_vozik(unsigned long n,UnicodeString id,double delka,double sirka,double vyska,double rotace,UnicodeString nazev_vyrobku,double max_vyrobku,double akt_vyrobku,double delka_vcetne_vyrobku,double sirka_vcetne_vyrobku,double vyska_vcetne_vyrobku,TColor barva=clRed);
    long vymaz_seznam_voziku();
		void hlavicka_palce();
		void vloz_palec();//přidá nový vozík do seznamu PALCE
		long vymaz_seznam_palcu();
		//ekonomické ukazatele
		void get_LT_a_max_min_TT();
		double sum_WT();
		double LT;
		double MAX_TT;
		double MIN_TT;

		/* z jiného projektu možno smazat
						short int vymaz_seznam(TBod *jaky);
		TBod *kopiruj_seznam(TBod *jaky);//vrací kam
		TBod *kopiruj(TBod *Prvek_kopirovany,float offset=0.0);//zkopíruje prvek do seznamu

		void smaz_bod_polygonu(TPolygon *jaky, TBod_LP *p);//smaže dílčí bod polygonu
		void optimalizace_seznamu(TBod *Prvek);//přepíše indexy vzestupně
				void optimalizace_seznamu(TPolygon *Prvek);//přepíše indexy vzestupně
        short int uloz_do_souboru(AnsiString FileName);
        short int nacti_ze_souboru(AnsiString FileName);
		short int import_ze_souboru(AnsiString FileName);
		TBod *vrat_bod(long long ID); //hledá prvek ve spojovém seznamu podle jeho ID, vrací ukazatel na něj
		void zmen_dcmntpt(long long ID,double X, double Y); //hledá prvek ve spojovém seznamu podle jeho ID, vrací ukazatel na něj
		TBod *vrat_bod(long long ID, unsigned  short layers[]); //hledá prvek ve spojovém seznamu podle jeho ID (zároveň kontroluje, zda je daná vrstva aktivni), vrací ukazatel na něj
		TBod *najdi_bod(double X, double Y, unsigned short offset_px);//hledá bod v dané oblasti
		TBod *najdi_bod(double X, double Y, unsigned short offset_px, unsigned  short layers[]);//hledá bod v dané oblasti a v dané vrstvě
		TBod *najdi_bod_od_bodu(TBod *ukaz,double X, double Y, unsigned short offset_px);//hledá bod v dané oblasti od zadané bodu (mimo něj)
		TBod_LP *najdi_bod_LP(double X, double Y, TPolygon *na_jakem);//hledá prvek na lini na aktuálních souřadnicích, vrací ukazatel na něj
        bool LeziNaPrimce(int x,int y,int a,int b,int c,int offset=3);//ověření zda bod leží na přímce
        double LeziVblizkostiPrimky(int x, int y, int a, int b, int c);//Počíta ABSOLUTNí vzdálenosti od přímky
        double LeziVblizkostiPrimky(float x, float y, float X1, float Y1, float X2, float Y2);//přetížená fce
        long LeziVblizkostiUsecky(long x, long y, long X1, long Y1, long X2, long Y2);//Počíta ABSOLUTNí vzdálenosti od usecky
		*/

	private:
		struct C_uzel//pro konverzi do bináru
		{
				unsigned int n;
				unsigned int id;
				//UnicodeString short_name;
				//UnicodeString name;
				unsigned int text_length;
				double X, Y;
				unsigned short rezim;//rezim objektu 0-S&G,1-Kontin.(line tracking),2-Postprocesní
				double TTo;//takttime objektu
				double CT;//cycle time
				unsigned short orientace_voziku;//0-na délku, 1- na šířku
				double vzdalenost;//mezera mezi vozíky
				short typ_dopravniku;
				double delka_dopravniku;
				double kapacita_objektu;
				unsigned long paremetry_text_length;
				//struct TObjekt *predchozi;
				//struct TObjekt *dalsi;
		};
		struct C_vozik//pro konverzi do bináru
		{
			unsigned int n; //pořadí objektu ve spoj.seznamu
			unsigned int id_length;   //délka řetězce id
			double delka;
			double sirka;
			double vyska;
			double rotace;
			unsigned int text_length;
			double max_vyrobku;
			double akt_vyrobku;
			double delka_vcetne_vyrobku;
			double sirka_vcetne_vyrobku;
			double vyska_vcetne_vyrobku;
			short stav;//-1 - není na lince, 0 - stop, 1 - čeká, 2 - jede
			TColor barva;
		};

		AnsiString get_csv_xls(AnsiString S);
		AnsiString get_html();

	protected:

};
//---------------------------------------------------------------------------
#endif
