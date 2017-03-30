//---------------------------------------------------------------------------
#ifndef vektoryH
#define vektoryH
#include <vcl.h>
#include "knihovna_objektu.h"
//#include "math.h"
#include "my.h"
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
			double doporucena_kapacita_objektu;
			double obsazenost;//čas obsazenosti
			UnicodeString techn_parametry;//obsah valuestringlistu, nelze ukládát pouze jednotlivá data, protože se seznam může u S&G měnit
			struct TObjekt *predchozi;
			struct TObjekt *dalsi;
		};
		TObjekt *OBJEKTY;

		struct TCesta//seznam technologických objektů na cestě - definice cesty
		{
			unsigned int n; //pořadí + ID objektu ve spoj.seznamu
			TObjekt *objekt;
			double CT; //cycle time
			struct TCesta *predchozi;
			struct TCesta *dalsi;
		};
		struct TSeznam_cest //seznam cest
		{
			unsigned int n; //pořadí cesty ve spoj.seznamu všech cest
			TCesta *cesta;
			TColor barva;
			struct TSeznam_cest *predchozi;
			struct TSeznam_cest *dalsi;
		}; TSeznam_cest *CESTY;

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
			double start;//výchozí pozice vozíku v grafu časové osy
			double pozice;//pozice na dopravniku či v grafu
			double X;
			double Y;
			double timer;
			struct TObjekt *segment;
			struct TSeznam_cest *cesta;
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
		void hlavicka_objekty();
		short vloz_objekt(unsigned int id, double X, double Y);//vloží prvek do seznamu
		short vloz_objekt(TObjekt *Objekt);//přetížená fce
		short vloz_objekt(unsigned int id, double X, double Y,TObjekt *p);//přetížená fce
		TObjekt *najdi_objekt(double X, double Y,double offsetX, double offsetY);//hledá bod v dané oblasti
		short smaz_objekt(TObjekt *Objekt);//smaže prvek ze seznamu
		void sniz_indexy(TObjekt *Objekt);
		void zvys_indexy(TObjekt *Objekt);
		void vymazat_casovou_obsazenost_objektu_a_pozice_voziku(TObjekt *Objekt,TVozik *Vozik);
		double delka_dopravniku(Cvektory::TObjekt *ukaz);
		void aktualizace_indexu_uzitych_dopravniku(short item_index);
		bool kontrola_existence_dopravniku(short item_index);
		long vymaz_seznam();
		void hlavicka_seznamu_cest();
		void hlavicka_jedne_cesty(TSeznam_cest *jaka);
		void vloz_segment_cesty(TSeznam_cest *C,TObjekt *Objekt,unsigned short R=0,double K=1,double CT=0);//do konkrétní cesty vloží segmenty cesty
		void vloz_cestu(TSeznam_cest *Cesta);//vloží hotovou cestu do spojového seznamu cesty
		TSeznam_cest *vrat_cestu(unsigned int ID_cesty);
		long vymaz_cesty();
		short int uloz_do_souboru(UnicodeString FileName);
		short int nacti_ze_souboru(UnicodeString FileName);
		short int ulozit_report(UnicodeString FileName);
		void hlavicka_voziky();
		void vloz_vozik();//přidá nový prázdný - nedefinovaný vozík do seznamu VOZIKY
		void vloz_vozik(TVozik *Vozik);
		void vloz_vozik(unsigned long n,UnicodeString id,double delka,double sirka,double vyska,double rotace,UnicodeString nazev_vyrobku,double max_vyrobku,double akt_vyrobku,double delka_vcetne_vyrobku,double sirka_vcetne_vyrobku,double vyska_vcetne_vyrobku,TColor barva,TSeznam_cest *cesta);
    long vymaz_seznam_voziku();
		void hlavicka_palce();
		void vloz_palec();//přidá nový vozík do seznamu PALCE
		long vymaz_seznam_palcu();
		//technické, statistické a ekonomické ukazatele
		void get_LT_a_max_min_TT();
		double sum_WT();
		double LT;
		double MAX_TT;
		double MIN_TT;
		TPointD vrat_zacatek_a_konec_zakazky(TSeznam_cest *jaka);//ukazatel na cestu resp, zakázku
		TPointD vrat_zacatek_a_konec_zakazky(unsigned int n_zakazky);//n resp. ID cestu resp, zakázku
		double vrat_LT_voziku(TVozik *jaky);//vrátí celkový čas, který strávil vozík ve výrobě včetně čekání
		double vrat_LT_voziku(unsigned int n_voziku);//vrátí celkový čas, který strávil vozík ve výrobě včetně čekání
		double vrat_sumPT_voziku(TVozik *jaky);//vrátí čistý čas, který strávil vozík ve výrobě bez čekání
		double vrat_sumPT_voziku(unsigned int n_voziku);//vrátí čistý čas, který strávil vozík ve výrobě bez čekání
		double vrat_AVGsumPT_zakazky(TSeznam_cest *jaka);//vrátí čistý čas, který strávily vozík ve výrobě bez čekání pro danou zakazku
		double vrat_WT_voziku(TVozik *jaky);//vrátí čas čeká vozíku během výroby
		double vrat_WT_voziku(unsigned int n_voziku);//vrátí čas čeká vozíku během výroby
		double vrat_AVGsumWT_zakazky(TSeznam_cest *jaka);//vrátí čistý čas, který vozíky čekaly pro danou zakazku
		double vrat_TT_voziku(TVozik *jaky);//vrátí takt, resp. rozdíl čásů mezi dokončením tohoto a předchozího vozíku
		double vrat_TT_voziku(unsigned int n_voziku);//vrátí takt, resp. rozdíl čásů mezi dokončením tohoto a předchozího vozíku
		double vrat_prumerne_TT_zakazky(TSeznam_cest *jaka);//vrátí hodnotu průměrného TT mezi vozíky v rámci dané zakázky/cesty
		double vrat_prumerne_TT_zakazky(unsigned int n_zakazky);//vrátí hodnotu průměrného TT mezi vozíky v rámci
		unsigned int vrat_pocet_voziku_zakazky(TSeznam_cest *jaka);
		unsigned int vrat_pocet_voziku_zakazky(unsigned int n_zakazky);
		unsigned int WIP();//vrátí max. počet vozíků na lince


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
