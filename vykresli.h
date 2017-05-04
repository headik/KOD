//---------------------------------------------------------------------------
#ifndef vykresliH
#define vykresliH
#include <vcl.h>
#include "vektory.h"
#include "my.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Cvykresli
{
	private:
	bool lezi_v_pasmu(TCanvas *c,long X,long Y,long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4);
	void SG(Cvektory::TVozik *ukaz);//zajištuje základní funkcionalitu technologického objektu v reimu S&G pøi vykreslování simulaci
	void STOPKA(Cvektory::TVozik *ukaz);//zajištuje základní funkcionalitu technologického objektu STOPKA pøi vykreslování simulaci
	bool KOLIZE(Cvektory::TVozik *V1,Cvektory::TVozik *V2);//vrací logickou hodnotu zda došlo èi nedošlo ke kolizi s jinım vozíkem
	void vykresli_proces(TCanvas *canv, AnsiString shortname, TColor color,short typ, int X1, int X2,int Y, short KrokY);//vykreslí jeden dílèí èasovı proces (obdelníèek procesu objektu) pro jeden vozík, vytaeno pouze kvùli pøehlednosti
	void vytizenost_procesu(TCanvas *canv, Cvektory::TProces *P,double X,int Y);
	void vykresli_Xosy(TCanvas *canv);//vykreslí statické svislice na èasové osy

	public:
	Cvykresli();//konstruktor
	Cvektory v;
	Cmy m;

  //--promìnné k úèelu filtrace
	struct TTP
	{
		double K;//Krok po kolika minutach se bude zobrazovat
		double OD;//od které min se proces zaène vypisovat
		double DO;//do ktere se bue vypisovat
		double KZ;//kosntatní konec zakazky v min
		unsigned int Nod;//rozmezí Jakı se vypíše vozik,
		unsigned int Ndo;//rozmezí Jakı se vypíše vozik, pokud bude 0 vypisují se všechny
		bool A;
	};TTP TP;//nastavení modu technologické procesy

	void vykresli_vektory(TCanvas *canv);
	void vykresli_rectangle(TCanvas *canv, Cvektory::TObjekt *ukaz);
	void prislusnost_cesty(TCanvas *canv,TColor Color,int X,int Y,float A,short N);
	void vykresli_grid(TCanvas *canv, int size_grid=10);
	void vykresli_graf_rezervy(TCanvas *canv);//mód graf rezerv
	void vykresli_casove_osy(TCanvas *canv);//MARO metoda, celkové vykreslení módu èasové osy
	void vykresli_vytizenost_objektu(TCanvas *canv);

	double proces(TCanvas *canv, unsigned int n, double X_predchozi, double X, int Y, Cvektory::TCesta *C, Cvektory::TVozik *vozik);
	void vykresli_svislici_na_casove_osy(TCanvas *canv,int X,int Y);//vykreslí pohyblivou svislici yna èasové osy dle umístìní kurzoru myši
	void zobrazit_label_zamerovac(int X,int Y);//vypiše labal zamìøovaè
	void vykresli_technologicke_procesy(TCanvas *canv);//ROMA metoda, vykreslí graf technologickıch procesù vùèi jednotlivım t-objektùm v èase
	void vykresli_simulaci(TCanvas *canv);//zajišuje vykreslení simulace
	void vykresli_linku(TCanvas *canv);//zajišuje vykreslení osy linky
	void umisti_vozik(TCanvas *canv,Cvektory::TVozik *ukaz);//zajišuje umístìní vozíku na lince
	void vykresli_vozik(TCanvas *canv,Cvektory::TVozik *ukaz,long X,long Y,bool NEW);//zajišuje vykreslení vozíku pøi simulaci, pokud je NEW==1, tak se vykreslí novı, pøi 0 se smae starı
	void priprav_palce();//pøidá novı palec do seznamu PALCE s umístìním pøímo na linku dle stanovené rozteèe
	void umisti_palec(TCanvas *canv,Cvektory::TPalec *ukaz);//zajišuje aktuální umístìní vozíku na lince vùèi animaci
	void vykresli_palec(TCanvas *canv,double X,double Y,bool NEW);//zajišuje samotné vykreslení vozíku (rotovanı obdelník)
	void rotace_textu(TCanvas *canv, long rotace);//úhel rotace je desetinách stupnì
	void set_pen(TCanvas *canv, TColor color, int width, int style=PS_ENDCAP_SQUARE);//vrátí HANDLE na nastavení pera,//popø.PS_ENDCAP_FLAT PS_ENDCAP_ROUND, PS_ENDCAP_SQUARE viz Matoušek III str. 179 èi http://www.zive.cz/clanky/geometricka-pera/sc-3-a-103079
	void set_color(TCanvas *canv, double time);
	void drawRectText(TCanvas *canv,TRect Rect, UnicodeString Text);
	void editacni_okno(TCanvas *canv, unsigned int X1, unsigned int Y1,unsigned  int X2,unsigned  int Y2, unsigned short int size=1, COLORREF color=clBlack);//nakreslí editacni_okno
	void editacni_okno(TCanvas *canv, TPoint LH, TPoint PD, unsigned short int size=1, COLORREF color=clBlack);//nakreslí editacni_okno
	void sipka(TCanvas *canv,int X, int Y,float azimut,bool bez_vyplne=false, unsigned short int size=3,COLORREF color=clBlack,COLORREF color_brush=clGray,TPenMode=pmCopy);//zajistí vykreslení šipky - orientace spojovací linie
	void odznac_oznac_objekt(TCanvas *canv, Cvektory::TObjekt *p,int posunX=0, int posunY=0, COLORREF color=clBlack);
	void odznac_oznac_objekt_novy(TCanvas *canv, int X, int Y,Cvektory::TObjekt *p);
	void odznac_oznac_objekt_novy_posledni(TCanvas *canv, int X, int Y);
	bool lezi_v_pasmu(TCanvas *c,long X,long Y,Cvektory::TObjekt *p);
	bool lezi_v_pasmu_poslednim(TCanvas *c,long X,long Y);
	void sound();



	short O_width,O_height;//logické parametry, nezoomovat
	unsigned long cas;//ms
	double PX2MIN;//mìøítko PX na MIN
	short KrokY;//rozteè na èasovıch osách
	int WidthCanvasCasoveOsy,HeightCanvasCasoveOsy;
	TPointD PosunT; //vıchozí posunutí obrazu Posunu
	bool mod_vytizenost_objektu;
	short NOLIEX;//NO - 0, LINEAR - 1, EXPO - 2

	protected:



};
#endif
