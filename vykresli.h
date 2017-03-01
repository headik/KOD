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
	// pouzivam ve vektorechvoid get_LT_a_max_min_TT();
	// pouzivam ve vektorechdouble sum_WT();

	public:
  Cvykresli();//konstruktor
	Cvektory v;
	Cmy m;

	void vykresli_vektory(TCanvas *canv);
	void vykresli_rectangle(TCanvas *canv, Cvektory::TObjekt *ukaz);
	void vykresli_grid(TCanvas *canv, int size_grid=10);
	void vykresli_graf_rezervy(TCanvas *canv);
	void vykresli_simulaci(TCanvas *canv);//zajišuje vykreslení simulace
	void vykresli_linku(TCanvas *canv);//zajišuje vykreslení osy linky
	void umisti_vozik(TCanvas *canv,Cvektory::TVozik *ukaz);//zajišuje umístìní vozíku na lince
	void vykresli_vozik(TCanvas *canv,Cvektory::TVozik *ukaz,long X,long Y,bool NEW);//zajišuje vykreslení vozíku pøi simulaci, pokud je NEW==1, tak se vykreslí novı, pøi 0 se smae starı
	void priprav_palce();//pøidá novı palec do seznamu PALCE s umístìním pøímo na linku dle stanovené rozteèe
	void umisti_palec(TCanvas *canv,Cvektory::TPalec *ukaz);//zajišuje aktuální umístìní vozíku na lince vùèi animaci
	void vykresli_palec(TCanvas *canv,double X,double Y,bool NEW);//zajišuje samotné vykreslení vozíku (rotovanı obdelník)
	void rotace_textu(TCanvas *canv, long rotace);//úhel rotace je desetinách stupnì
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

	protected:



};
#endif
