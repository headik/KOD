//---------------------------------------------------------------------------
#ifndef myH
#define myH
#include <vcl.h>
#include "CTpointD.h"

//---------------------------------------------------------------------------
class Cmy
{
  private:

  public:
  long round(double number);//fce pro zaokrouhlení realného èísla na nejblížší celé èíslo
  double round2double(double number,unsigned short precision);//zaokrouhlí na poèet desetinných míst dle precison
  double round2double(double number,unsigned short from_min,double ifcontent);//zaokrouhlí pokud reálná èást obsahuje hodnotu, zohledòuje požadavek na minimální desetinné místo dle from
  double abs_d(double number);//fce vrátí absolutní hodnotu z double èísla, možno nahradit mocí fabs z maht
  double ToRad(double number);
  double ToDeg(double number);
  //TPoint* P2L(TPoint *Physical, float Zoom, long PosunutiX, long PosunutiY);//Pøevede Fyzické souøadnice na logicke, vraci logicke souøadnice
	//double P2Lx(long fyzicka, unsigned short int Zoom, double Posunuti, unsigned short int ClientWidth);//Pøevede fyzické souøadnice (displej zaøízení) na logicke, vraci logicke souøadnice
	TPointD P2L(TPoint fyzicke);
	TPointD P2L(long fyzickaX,long fyzickaY);
	double P2Lx(long fyzicka);
	//double P2Ly(long fyzicka, unsigned short int Zoom, double Posunuti, unsigned short int ClientHeight);//Pøevede fyzické souøadnice (displej zaøízení) na logicke, vraci logicke souøadnice
	double P2Ly(long fyzicka);
	//double P2LyTEST(long fyzicka);
	TPoint L2P(double logickaX, double logickaY);//Pøevede logické souøadnice na fyzické (displej zaøízení) , vraci fyzické souøadnice
	TPoint L2P(TPointD logicke);
	long L2Px(double logicka);
	long L2Py(double logicka);
	//long L2Px(double logicka, unsigned short int Zoom, double Posunuti, unsigned short int ClientWidth);//Pøevede logické souøadnice na fyzické (displej zaøízení) , vraci fyzické souøadnice
	//long L2Py(double logicka, unsigned short int Zoom, double Posunuti, unsigned short int ClientHeight);//Pøevede logické souøadnice na fyzické (displej zaøízení) , vraci fyzické souøadnice
	//long L2PyTEST(double logicka, unsigned short int Zoom, double Posunuti, unsigned short int ClientHeight);//Pøevede logické souøadnice na fyzické (displej zaøízení) , vraci fyzické souøadnice
	long m2px(unsigned int meter,unsigned int Scale=1);//pøevede vzdálenost v metrech na vzdálenost monitoru
  float px2m(unsigned int px,unsigned int Scale=1);//Pøevede logické jednotky (udajnì metry) na pixely monitoru
  long px_offset(unsigned int X,unsigned int Y,long Distance);//vráti souøadnice pixelù posunuté o Distance METRù
	bool cele_cislo(double number);
	double mod_d(double number1,double number2);//možno nahradit fci fmod z math.h  - to si už tak nejsem jistý viz paramatry této funkce - ukazatel?
	bool isFinite(double number1,double number2);
	double azimut(double X1,double Y1,double X2,double Y2);
	double uhel(double X1,double Y1,double X2,double Y2);
	double delka(double X1,double Y1,double X2,double Y2);
	TPointD rotace(double delka, double akt_uhel, double rotace);
	TPointDbool zkratit_polygon_na_roztec(double d, double r,double xp, double yp, double x0, double y0, double x1, double y1);//d - delka linky,r - roztec palcuxp, yp - souradnice oznaceneho bodu x0, y0, x1, y1- souradnice sousedu k oznacenemu bodu
	double cekani_na_palec(double cas, double roztec_palcu, double rychlost_dopravniku, bool zohlednit=true);//vrátí dobu èekání na palec v sec, zadání je u èas (výstupu vozíku z objektu) v min, rozteèe je v mm resp. v m za z minu u rychlosti dopravniku

	long LeziVblizkostiUsecky(double x, double y, double X1, double Y1, double X2, double Y2);


	protected:

};
#endif








