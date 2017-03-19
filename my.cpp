//---------------------------------------------------------------------------
#pragma hdrstop
#include "my.h"
#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
/////////////////////////////////////////////////////////////////////////////
//fce pro zaokrouhlení realného èísla na nejblížší celé èíslo
long Cmy::round(double number)
{
	if(number>0)
	return (long)(number+0.5);//pro kladné hodnoty
	else
	return (long)(number-0.5);//pro záporné hodnoty
}
/////////////////////////////////////////////////////////////////////////////
//zaokrouhlí na poèet desetinných míst dle precison
double Cmy::round2double(double number,unsigned short precision)
{
	return number=round(number*pow(10.0,precision))/pow(10.0,precision);
}
/////////////////////////////////////////////////////////////////////////////
//ovìøí, zda dané èíslo je celé èíslo
bool Cmy::cele_cislo(double number)
{
	 return number==floor(number);
}
/////////////////////////////////////////////////////////////////////////////
//modulo pro double hodnoty
double Cmy::mod_d(double number1,double number2)
{
	 //nedotažené: return number1-floor(number1/number2)*number2;
	 return fmod(number1,number2);//toto ale také nefunguje pro druhou reálnou hodnotu dobøe
}
/////////////////////////////////////////////////////////////////////////////
//Pøevede logické souøadnice na fyzické (displej zaøízení) , vraci fyzické souøadnice
TPoint Cmy::L2P(double logickaX, double logickaY)
{
	return TPoint(L2Px(logickaX),L2Py(logickaY));
}
TPoint Cmy::L2P(TPointD logicke)
{
	return L2P(logicke.x,logicke.y);
}
long Cmy::L2Px(double logicka)
{
	//return round(Form1->Posun.X+logicka*Form1->Zoom);
	return round(Form1->Zoom*(logicka/Form1->m2px-Form1->Posun.x));
}
long Cmy::L2Py(double logicka)
{
	//return round(Form1->Posun.Y+logicka*Form1->Zoom);
	return round(Form1->Zoom*(-1*logicka/Form1->m2px-Form1->Posun.y));
}
/////////////////////////////////////////////////////////////////////////////
//Pøevede  fyzické na logické souøadnice (displej zaøízení) , vraci logické souøadnice
TPointD Cmy::P2L(TPoint fyzicke)
{
		TPointD logicke;logicke.x=P2Lx(fyzicke.X);logicke.y=P2Ly(fyzicke.Y);
		return logicke;
}
TPointD Cmy::P2L(long fyzickaX,long fyzickaY)
{
		TPointD logicke;logicke.x=P2Lx(fyzickaX);logicke.y=P2Ly(fyzickaY);
		return logicke;
}
double Cmy::P2Lx(long fyzicka)
{
		return (fyzicka/Form1->Zoom+Form1->Posun.x)*Form1->m2px;
}
double Cmy::P2Ly(long fyzicka)
{
		return -1.0*(fyzicka/Form1->Zoom+Form1->Posun.y)*Form1->m2px;
}
/////////////////////////////////////////////////////////////////////////////
double Cmy::delka(double X1,double Y1,double X2,double Y2)
{
		return sqrt(pow(X2-X1,2)+ pow(Y2-Y1,2));
}
/////////////////////////////////////////////////////////////////////////////
double Cmy::azimut(double X1,double Y1,double X2,double Y2)
{
		try{
			float A=acos((Y2-Y1)/(delka(X1,Y1,X2,Y2)*1.0))*180/M_PI;
			if(X2<X1)A=360-A;
			return A;
		}
		catch(...)
		{return 0;}
}
double Cmy::uhel(double X1,double Y1,double X2,double Y2)
{
		try{
			return acos((Y2-Y1)/(delka(X1,Y1,X2,Y2)*1.0))*180/M_PI;
		}
		catch(...)
		{return 0;}
}
/////////////////////////////////////////////////////////////////////////////
//rotace
TPointD Cmy::rotace(double delka, double akt_uhel, double rotace)
{
		double Uhel=fmod(akt_uhel+rotace,360.0);// vèetnì ošetøení pøeteèení pøes 360 stupòù
		if(Uhel<0){Uhel+=360;}//pro záporné hodnoty

		short ZnamenkoX,ZnamenkoY;

		if (Uhel>=0 && Uhel< 90)
    {
			ZnamenkoX=1;ZnamenkoY=-1;
    }
		if (Uhel>=90 && Uhel<= 180)
		{
			Uhel=180-Uhel;
    	ZnamenkoX=1;ZnamenkoY=1;
    }
		if (Uhel>180 && Uhel<= 270)
    {
			Uhel=Uhel-180;
    	ZnamenkoX=-1;ZnamenkoY=1;
    }
		if (Uhel>270 && Uhel<= 360)
    {
			Uhel=360-Uhel;
    	ZnamenkoX=-1;ZnamenkoY=-1;
    }

    Uhel=Uhel*(M_PI/180);//pro prevod ze stupnu na radiany
		TPointD ret;
		ret.x=sin(Uhel)*delka*ZnamenkoX;//posun na Xove ose
		ret.y=cos(Uhel)*delka*ZnamenkoY;//posun na Yove ose

	return ret;
}
/////////////////////////////////////////////////////////////////////////////
long Cmy::LeziVblizkostiUsecky(double x, double y, double X1, double Y1, double X2, double Y2)
{
	double a=Y2-Y1;
	double b=X1-X2;
	double c=-a*X1-b*Y1;

  if(X2==X1)//pokud jsou v jedné "linii" tj. je abs. svislá
  {
	if((Y1<=y && y<=Y2 && Y1<Y2) || (Y2<=y && y<=Y1 && Y2<Y1))
		return round(fabs((a*x + b*y + c) / sqrt(fabs(a*a + b*b))));
    else
	  return 2147483647;//vrací nesmyslnì vysoké èíslo jako neúspìch (zøejmì leží na pøímce ale ne na úseèce)
  }
  else//pro ostatní situace
  {
	if(((X1<=x && x<=X2 && X1<X2) || (X2<=x && x<=X1 && X2<X1)) && ((Y1<=y && y<=Y2 && Y1<Y2) || (Y2<=y && y<=Y1 && Y2<Y1)))
		return round(fabs((a*x + b*y + c) / sqrt(fabs(a*a + b*b))));
	else
		return 2147483647;//vrací nesmyslnì vysoké èíslo jako neúspìch (zøejmì leží na pøímce ale ne na úseèce)
	}
}
/////////////////////////////////////////////////////////////////////////////
TPointDbool Cmy::zkratit_polygon_na_roztec(double d, double r,double xp, double yp, double x0, double y0, double x1, double y1)//d - delka linky,r - roztec palcuxp, yp - souradnice oznaceneho bodu x0, y0, x1, y1- souradnice sousedu k oznacenemu bodu
{
		TPointDbool RET;
		// zkratit linku o z, d je delka linky, r je roztec zubu
		double z=fmod(d,r);

		// kontrola vhodnosti vybraneho bodu
		double d0=sqrt(pow((x0-xp),2)+pow((y0-yp),2));
		double d1=sqrt(pow((x1-xp),2)+pow((y1-yp),2));
		double dt=sqrt(pow((x0-x1),2)+pow((y0-y1),2));
		double sq=d0+d1-dt-z;

		if (sq<0)
			RET.b=false; //pokud nebude splnena trojuhelnikova nerovnost, nemuze se dany bod pouzit
		else
		{
			double d0n=((d0+d1-z)*d0)/(d0+d1); // prepocitani ocekavanych delek
			double d1n=((d0+d1-z)*d1)/(d0+d1);

			double m=((pow(d0n,2)-pow(d1n,2))/2*dt)+(dt/2); // prusecik pocitan metodikou popsanou na wikibooks(prusecik dvou kruznic)
			ShowMessage(pow(d0n,2)); ShowMessage(pow(m,2));
			double v=sqrt(fabs(pow(d0n,2)-pow(m,2)));// dela se to trojuhelnikama  <--DOPLNÌNA ABSOLUTNÍ HODNOTA PRO REÁLNÁ ÈÍSLA

			double xs=x0+(m/dt)*(x1-x0); // vypocet pruseciku spojnice bodu s osou
			double ys=y0+(m/dt)*(y1-y0);

			double xn1=xs-(v/dt)*(y0-y1); // mozne souradnice novych bodu
			double yn1=ys+(v/dt)*(x0-x1);
			double xn2=xs+(v/dt)*(y0-y1);
			double yn2=ys-(v/dt)*(x0-x1);

			double dist1=sqrt(pow((xn1-xp),2)+pow((yn1-yp),2)); // nalezeni blizsiho bodu
			double dist2=sqrt(pow((xn2-xp),2)+pow((yn2-yp),2));

      double xn,yn;

			if (dist1<dist2)
			{
				xn=xn1;
				yn=yn1;
			}
			else
			{
				xn=xn2;
				yn=yn2;
      }

			RET.b=true; RET.x=xn; RET.y=yn;
		}

		return RET;
}
/////////////////////////////////////////////////////////////////////////////
double Cmy::cekani_na_palec(double cas, double roztec_palcu,double rychlost_dopravniku)//vrátí dobu èekání na palec v sec, zadání je u èas (výstupu vozíku z objektu) v sec, rozteèe je v mm resp. v m za z minu u rychlosti dopravniku
{
		rychlost_dopravniku*=100;//pøevod z mm na mm
		return 60/rychlost_dopravniku*fmod(rychlost_dopravniku/60*cas,roztec_palcu);
}
/////////////////////////////////////////////////////////////////////////////
