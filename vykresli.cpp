//---------------------------------------------------------------------------
#pragma hdrstop
#include "vykresli.h"
#include "Unit1.h"
#include "stdlib.h"
//--------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//konstruktor
Cvykresli::Cvykresli()
{
	//parametry vykreslovaného obdelníku technologického objektu
	O_width=50;
	O_height=40;
	//měřítko PX na MIN, globální proměná pro využítí výpisu ve SB v Unit1
	PX2MIN=30.0;
}
//---------------------------------------------------------------------------
void Cvykresli::vykresli_vektory(TCanvas *canv)
{
		////OBJEKTY
		Cvektory::TObjekt *ukaz;

		//spojovací linie
		ukaz=v.OBJEKTY->dalsi;//přeskočí hlavičku
		while (ukaz!=NULL)
		{
			canv->Pen->Style=psSolid;
			canv->Pen->Width=m.round(2*Form1->Zoom);
			canv->Pen->Color=clGray;
			if(ukaz->n==1)//pro situaci z posledního prvku na první
			{
				//if(ukaz->n!=ukaz->predchozi->predchozi->n)//pokud jsou minimálně dva prky, ale šipka bude obousměrnná - možná žádoucí
				if(v.OBJEKTY->predchozi->n>=3)//až budou alespoň tři prvky,tj. poslední prvek bude mít index n větší než 3
				{
					canv->MoveTo(m.L2Px(ukaz->predchozi->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->predchozi->predchozi->Y)+O_height*Form1->Zoom/2);
					canv->LineTo(m.L2Px(ukaz->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->Y)+O_height*Form1->Zoom/2);
					sipka(canv,m.L2Px((ukaz->predchozi->predchozi->X+ukaz->X)/2)+O_width*Form1->Zoom/2,m.L2Py((ukaz->predchozi->predchozi->Y+ukaz->Y)/2)+O_height*Form1->Zoom/2,m.azimut(ukaz->predchozi->predchozi->X,ukaz->predchozi->predchozi->Y,ukaz->X,ukaz->Y));//zajistí vykreslení šipky - orientace spojovací linie
				}
			}
			else
			{
				canv->MoveTo(m.L2Px(ukaz->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(ukaz->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->Y)+O_height*Form1->Zoom/2);
				sipka(canv,m.L2Px((ukaz->predchozi->X+ukaz->X)/2)+O_width*Form1->Zoom/2,m.L2Py((ukaz->predchozi->Y+ukaz->Y)/2)+O_height*Form1->Zoom/2,m.azimut(ukaz->predchozi->X,ukaz->predchozi->Y,ukaz->X,ukaz->Y));//zajistí vykreslení šipky - orientace spojovací linie
			}
			ukaz=ukaz->dalsi;//posun na další prvek
		}

		//samotné objekty, kreslím až v samostatném následujícím cyklu, aby se nakreslilo do horní vrstvy
		ukaz=v.OBJEKTY->dalsi;//přeskočí hlavičku
		while (ukaz!=NULL)
		{
			vykresli_rectangle(canv,ukaz);
			ukaz=ukaz->dalsi;//posun na další prvek
		}
		//delete ukaz;ukaz=NULL;  nesmíš!!! smažu si DATA!
}
//---------------------------------------------------------------------------
//zajistí vykreslení šipky - orientace spojovací linie
void Cvykresli::sipka(TCanvas *canv, int X, int Y, float azimut, bool bez_vyplne, unsigned short int size,COLORREF color,COLORREF color_brush,TPenMode PenMode)
{
			canv->Pen->Mode=PenMode;
			canv->Pen->Width=1;
			canv->Pen->Style=psSolid;
			canv->Pen->Color=(TColor)color;
			canv->Brush->Color=(TColor)color_brush;
			size=m.round(size*2*Form1->Zoom);
			short sklon=230;

			//varianta střed v těžišti
			if(!bez_vyplne)//barevná výplň trojúhelníku
			{
				POINT body[3]={{X+m.rotace(1,sklon,azimut).x*size,Y+m.rotace(1,sklon,azimut).y*size},{X+m.rotace(1,0,azimut).x*size,Y+m.rotace(1,0,azimut).y*size},{X+m.rotace(1,360-sklon,azimut).x*size,Y+m.rotace(1,360-sklon,azimut).y*size}};
				canv->Polygon((TPoint*)body,2);
			}
			else//transparentní střed
			{
				canv->MoveTo(X+m.rotace(1,sklon,azimut).x*size,Y+m.rotace(1,sklon,azimut).y*size);
				canv->LineTo(X+m.rotace(1,0,azimut).x*size,Y+m.rotace(1,0,azimut).y*size);
				canv->LineTo(X+m.rotace(1,360-sklon,azimut).x*size,Y+m.rotace(1,360-sklon,azimut).y*size);
				canv->LineTo(X+m.rotace(1,sklon,azimut).x*size,Y+m.rotace(1,sklon,azimut).y*size);
			}


}
//---------------------------------------------------------------------------
void Cvykresli::vykresli_rectangle(TCanvas *canv,Cvektory::TObjekt *ukaz)
{
		//referenčni bod jsem nakonce stanovil pravý konec levé packy
		TPoint S=m.L2P(ukaz->X,ukaz->Y);//Převede logické souřadnice na fyzické (displej zařízení) , vraci fyzické souřadnice

		unsigned short W=O_width*Form1->Zoom;
		unsigned short H=O_height*Form1->Zoom;

		if(Form1->zobrazit_barvy_casovych_rezerv)
		{
			set_color(canv,ukaz->TTo);
			unsigned short O=m.round(4*Form1->Zoom);//Okraj nutno zaokrouhlit tady
			canv->Rectangle(S.x-O,S.y-O,S.x+W+O,S.y+H+O);
		}

		//odelník objektu
		canv->Pen->Style=psSolid;
		canv->Brush->Style=bsSolid;
		canv->Brush->Color=clWhite;
		canv->Pen->Color=clBlack;
		canv->Pen->Mode=pmCopy;
		canv->Font->Name="MS Sans Serif";
		canv->Font->Size=8;
		rotace_textu(canv,0);
		canv->Font->Color=clBlack;
		canv->Pen->Width=m.round(2*Form1->Zoom);
		canv->Rectangle(S.x,S.y,S.x+W,S.y+H);

		//packy
		/*unsigned short packy_W=5*Form1->Zoom;
		canv->Pen->Width=1*Form1->Zoom;
		canv->MoveTo(S.x-packy_W,S.y+H/2);canv->LineTo(S.x,S.y+H/2);
		canv->MoveTo(S.x+W,S.y+H/2);canv->LineTo(S.x+W+packy_W,S.y+H/2);*/

		//text - pro jednotlivé zoomu různé podoby výpisu
		if(Form1->Zoom>1)//nadpis
		{
		 canv->Font->Style = TFontStyles()<< fsBold;//zapnutí tučného písma
		 if(Form1->Zoom==1.5)	drawRectText(canv,TRect(S.x,S.y,S.x+W,S.y+H),ukaz->name.UpperCase());//zajistí vykreslení textu vycentrovaného vevnitř objektu/obdelníku
		 else canv->TextOutW(S.x+5,S.y+5,ukaz->name.UpperCase());
		 canv->Font->Style = TFontStyles();//vypnutí tučného písma
		}
		if(Form1->Zoom>1.5)//i datové položky
		{
		 UnicodeString T="";
		 switch(ukaz->rezim)
		 {
			case 0:T="STOP & GO";break;
			case 1:T="KONTINUÁLNÍ";break;
			case 2:T="POSTPROCESNÍ";break;
		 }
		 canv->TextOutW(S.x+5,S.y+18,T);
		 canv->TextOutW(S.x+5,S.y+31,"TT: "+UnicodeString(ukaz->TTo)+" min/v");
		 canv->TextOutW(S.x+5,S.y+44,"CT: "+UnicodeString(ukaz->CT)+" min/v");
		 canv->TextOutW(S.x+5,S.y+57,"Kap.: "+UnicodeString(ukaz->kapacita_objektu)+" v");
		}
		if(Form1->Zoom<=1)//pro největší oddálení zobrazí jenom zkratku objektu
		{
			if(Form1->Zoom==1)canv->Font->Style = TFontStyles()<< fsBold;else canv->Font->Style = TFontStyles();
			drawRectText(canv,TRect(S.x,S.y,S.x+W,S.y+H),ukaz->short_name.UpperCase());//zajistí vykreslení textu vycentrovaného vevnitř objektu/obdelníku
		}
}
//---------------------------------------------------------------------------
void Cvykresli::drawRectText(TCanvas *canv,TRect Rect,UnicodeString Text)
{
	canv->TextOutW(Rect.Left+Rect.Width()/2-canv->TextWidth(Text)/2,Rect.Top+Rect.Height()/2-canv->TextHeight(Text)/2,Text);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Cvykresli::vykresli_grid(TCanvas *canv, int size_grid)
{
		//if(Form1->Zoom==1.75 || Form1->Zoom==0.75)bacha u těchto hodnot špatné vykreslování asi zaokrouhlouvaním
		for(int x=m.round((m.round(-1*Form1->Posun.x)%size_grid)*Form1->Zoom);x<=Form1->Width;x+=m.round(size_grid*Form1->Zoom))
		for(int y=m.round((m.round(-1*Form1->Posun.y)%size_grid)*Form1->Zoom);y<=Form1->Height;y+=m.round(size_grid*Form1->Zoom))
		{
			canv->Pixels[x][y]=clGray;
		}
}
//---------------------------------------------------------------------------
void Cvykresli::vykresli_graf_rezervy(TCanvas *canv)
{
	 SetBkMode(canv->Handle,OPAQUE);
	 canv->Font->Size=12;
	 canv->Font->Name="Arial";
	 UnicodeString text_horizontal="časová osa procesů";
	 UnicodeString text_vertical="TAKT TIME [čas na vozík]";
	 unsigned int L=/*Form1->RzSizePanel_knihovna_objektu->Width+*/canv->TextHeight(text_vertical)+3;
	 unsigned int P=Form1->ClientWidth-1;
	 unsigned int D=Form1->ClientHeight-Form1->RzStatusBar1->Height-canv->TextHeight(text_horizontal)-1;
	 unsigned int H=Form1->RzToolbar1->Height;
	 unsigned int offset_horizont=0;//bylo 20 - nyní nepoužívám, pouze vizuální záležitost na ose X, pro graf, aby nebyl až ke kraji
	 unsigned int offset_vertical=100;
	 double akt_max_TTo=0;
	 bool graficka_legenda=false;
	 v.get_LT_a_max_min_TT();

	 ////objekty
		canv->Brush->Style=bsSolid;
		canv->Font->Color=clWhite;
		canv->Font->Style = TFontStyles() /*<< fsItalic << fsBold*/;
		canv->Font->Size=14;
		rotace_textu(canv,900);

		Cvektory::TObjekt *ukaz;
		unsigned int sirka_uzita=L;
		ukaz=v.OBJEKTY->dalsi;//přeskočí hlavičku
		if(ukaz==NULL){v.MAX_TT=0;v.MIN_TT=0;}//pokud neexistuje žádný objekt, ošetření, aby se nic nezobrazovalo v grafu
		while (ukaz!=NULL)//pokud existuje nějaký prvek
		{
			if(ukaz->TTo>0)//vykreslí, jenom pokud má objekt TTo>0
			{
				//sloupce
				set_color(canv,ukaz->TTo);
				canv->Pen->Style=psSolid;
				canv->Brush->Style=bsSolid;
				unsigned int sirka_sloupce=m.round((P-offset_horizont-L)*ukaz->CT/v.LT);
				unsigned int vyska_sloupce=m.round((D-H-offset_vertical)*ukaz->TTo/v.MAX_TT);//pokud bych chtěl rovnoměrně rozdělovat tak jako u sirka_sloupce:unsigned int vyska_sloupce=m.round((D-H-offset_vertical)*ukaz->time/LT);
				canv->Rectangle(sirka_uzita,D-vyska_sloupce,sirka_uzita+sirka_sloupce,D);
				//zajistí grafické oddělení sloupců bílá svislá čára
				canv->Pen->Color=clWhite;
				canv->Pen->Width=1;
				canv->Pen->Style=psSolid;
				canv->MoveTo(sirka_uzita,D-vyska_sloupce);
				canv->LineTo(sirka_uzita,D);

				////vykreslení doporučeného TTo či buffrování,je-li důvod,tzn. je-li výška slopuce pod TT
				akt_max_TTo=(ukaz->TTo > akt_max_TTo) ? ukaz->TTo : akt_max_TTo;//přiřadí aktuálně nejvyšší TT
				if(akt_max_TTo!=ukaz->TTo)graficka_legenda=true;
				//doporučení zvýšení TTo
				canv->Brush->Style=bsDiagCross;
				canv->Rectangle(sirka_uzita,D-vyska_sloupce,sirka_uzita+sirka_sloupce,D-m.round((D-H-offset_vertical)*akt_max_TTo/v.MAX_TT));
				//doporučení BUFFROVANÍ či STOP STANIC
				if(ukaz->dalsi!=NULL && akt_max_TTo<ukaz->dalsi->TTo)
				{
					canv->Brush->Style=bsCross;
					canv->Rectangle(sirka_uzita,D-m.round((D-H-offset_vertical)*akt_max_TTo/v.MAX_TT),sirka_uzita+sirka_sloupce,D-m.round((D-H-offset_vertical)*ukaz->dalsi->TTo/v.MAX_TT));
				}

				/*//popisek
				if(ukaz->rezim==0)//S&G
				{
						//
				}
				else//kontinual, dále postprocesní nemusím z principu řešit
				{
					 //
				}
				////----
				*/
				UnicodeString Popisek=ukaz->name.UpperCase();//standardně celý název jinak zkratka, pokud se nevejde do sloupce
				if(vyska_sloupce<canv->TextWidth(Popisek))Popisek=ukaz->short_name;
				if(D-vyska_sloupce/2+canv->TextWidth(Popisek)/2<D)//zajišťuje, aby byl popisek vždy nad osou
					canv->TextOutW((sirka_uzita+sirka_uzita+sirka_sloupce)/2-canv->TextHeight(Popisek)/2,D-vyska_sloupce/2+canv->TextWidth(Popisek)/2,Popisek);//popisek
				else
				canv->TextOutW((sirka_uzita+sirka_uzita+sirka_sloupce)/2-canv->TextHeight(Popisek)/2,D-1,Popisek);//popisek

				sirka_uzita+=sirka_sloupce;

			}
			ukaz=ukaz->dalsi;//posun na další prvek
		}
		//vypnutí tučného písma
		canv->Font->Style = TFontStyles();
		canv->Font->Size=12;
	 ////----------

	 ////legenda a osy
		canv->Pen->Style=psClear;
		canv->Font->Color=clGray;
		canv->Font->Size=9;
		canv->Pen->Color=clGray;
		canv->Brush->Color=clGray;
		rotace_textu(canv,0);
		//grafická legenda
		if(graficka_legenda)
		{
				canv->Brush->Style=bsDiagCross;
				UnicodeString P1="zvýšit TAKT TIME objektu";
				UnicodeString P2="zařadit BUFFER/STOP STANICI";
				unsigned short T_W=(canv->TextWidth(P1)>canv->TextWidth(P2)) ? canv->TextWidth(P1):canv->TextWidth(P2);//přiřadí aktuálně nejvyšší TT
				unsigned short T_H=canv->TextHeight(P1);
				canv->TextOutW(P-T_W-2,(H+10+H+20+10)/2-T_H/2,P1);
				canv->Rectangle(P-50-T_W-4,H+10,P-T_W-4,H+20+10);
				canv->Brush->Style=bsCross;
				canv->TextOutW(P-T_W-2,(H+20+20+H+20+20+20)/2-T_H/2,P2);
				canv->Rectangle(P-50-T_W-4,H+20+20,P-T_W-4,H+20+20+20);
		}

		//osy a nastavení
		canv->Pen->Width=1;
		canv->Pen->Style=psSolid;
		canv->Brush->Color=clWhite;
		//vodorovná osa
		canv->MoveTo(L,D);canv->LineTo(P,D);//linie
		canv->LineTo(P-10,D-10);canv->MoveTo(P,D);canv->LineTo(P-10,D+10);//šipka
		canv->TextOutW((L+P)/2-canv->TextWidth(text_horizontal)/2,D+1,text_horizontal);//popisek
		//svislá osa
		canv->MoveTo(L,D);canv->LineTo(L,H);//linie
		canv->LineTo(L-10,H+10);canv->MoveTo(L,H);canv->LineTo(L+10,H+10);//šipka
		rotace_textu(canv,900);canv->TextOutW(L-1-canv->TextHeight(text_vertical),(D+H)/2+canv->TextWidth(text_vertical)/2,text_vertical);//popisek
		//další popisky a osy
		canv->Pen->Style=psDot;
		rotace_textu(canv,0);
		UnicodeString T="";
		//min TTo
		if(v.MIN_TT!=Form1->PP.TT && v.MAX_TT!=v.MIN_TT )//zobrazí osu s popiskem pouze pokud nebude stejná jako TT a zároveň MAX_TT
		{
			canv->MoveTo(L,D-m.round((D-H-offset_vertical)*v.MIN_TT/v.MAX_TT));canv->LineTo(P,D-m.round((D-H-offset_vertical)*v.MIN_TT/v.MAX_TT));
			T="min. TAKT TIME objektů";
			canv->TextOutW(P-canv->TextWidth(T)-1,D-m.round(D-H-offset_vertical)*v.MIN_TT/v.MAX_TT-canv->TextHeight(T),T);
		}
		//max TTo
		if(v.MAX_TT!=Form1->PP.TT)//zobrazí osu s popiskem pouze pokud nebude stejná jako TT
		{
			canv->MoveTo(L,D-m.round(D-H-offset_vertical));canv->LineTo(P,D-m.round(D-H-offset_vertical));
			if(v.MAX_TT!=0)T="uskutečnitelný (max.) TAKT TIME objektů";else T="požadovaný TAKT TIME";
			canv->TextOutW(P-canv->TextWidth(T)-1,D-m.round(D-H-offset_vertical)-canv->TextHeight(T),T);
			T="požadovaný TAKT TIME";
		}
		else T="požadovaný (uskutečnitelný) TAKT TIME";
		//TT osa
		canv->Pen->Style=psDash;
		if(v.MAX_TT>0)
		{
			canv->MoveTo(L,D-m.round((D-H-offset_vertical)*Form1->PP.TT/v.MAX_TT));canv->LineTo(P,D-m.round((D-H-offset_vertical)*Form1->PP.TT/v.MAX_TT));
			canv->TextOutW(P-canv->TextWidth(T)-1,D-m.round(D-H-offset_vertical)*Form1->PP.TT/v.MAX_TT-canv->TextHeight(T),T);
    }
		//vypis hodnoty LT
		T="LEAD TIME: "+UnicodeString(v.LT)+" [min]";
		canv->TextOutW(P-canv->TextWidth(T)-11,D+1,T);
		//Legenda pravý horní roh
		unsigned short n=0;
		canv->TextOutW(L+10,H+canv->TextHeight(T)*++n,"požadovaný TAKT TIME: "+UnicodeString(Form1->PP.TT)+" [min/vozík]");
		canv->TextOutW(L+10,H+canv->TextHeight(T)*++n,"uskutečnitelný (max.) TAKT TIME: "+UnicodeString(v.MAX_TT)+" [min/vozík]");
		if(Form1->PP.TT>0)
		{
			//canv->TextOutW(L+10,H+canv->TextHeight(T)*++n,"Počet realizovaných produktů v čase:...[ks]");
			canv->TextOutW(L+10,H+canv->TextHeight(T)*++n,"WIP: "+UnicodeString((1/Form1->PP.TT)*v.LT)+" [vozíků]");
			if(v.LT>0)canv->TextOutW(L+10,H+canv->TextHeight(T)*++n,"PCE: "+UnicodeString(m.round2double(v.sum_WT()/v.LT*100,2))+" [%]");//zokrouhleno na dvě desetinná místa
    }
		canv->Brush->Style=bsSolid;
	 ///------
}
//---------------------------------------------------------------------------
//celkové vykreslení módu časové osy
void Cvykresli::vykresli_casove_osy(TCanvas *canv)
{
	v.vymazat_casovou_obsazenost_objektu(v.OBJEKTY);//vymaže předchozí časovou obsazenost objektů, jinak by se při každém dalším překreslení objekty posovali o obsazenost z předchozího vykreslení
	Cvektory::TVozik *vozik=v.VOZIKY->dalsi;//ukazatel na první objekt v seznamu VOZÍKŮ, přeskočí hlavičku
	while (vozik!=NULL)
	{
		short KrokY=20;//vizuální rozteč na ose Y mezi jednotlivými vozíky
		double X=0.0;//výchozí odsazení na ose X
		int Y=(vozik->n-1)*KrokY+Form1->RzToolbar1->Height+KrokY;//výchozí odsazení na ose Y

		Cvektory::TCesta *C=vozik->cesta->cesta->dalsi;//ukazatel na první segment/objekt CESTY, přeskočí hlavičku
		while (C!=NULL)
		{
			if(C->objekt->rezim==0 && X<C->objekt->obsazenost)X=C->objekt->obsazenost; //pro S&G řeší,aby se procesy v čase nepřekrývaly
			double X_predchozi=X;//uloží povodní X hodnotu
			//X+=C->objekt->CT*PX2MIN;//uloží hodnotu posunu o délku technologického času na ose X
			X+=C->CT*PX2MIN;//uloží hodnotu posunu o délku technologického času na ose X
			C->objekt->obsazenost=X;//nahraje koncovou X hodnotu do obsaženosti objektu pro další využítí
			vykresli_casovou_osu(canv,C->objekt->short_name,vozik->barva,m.round(X),m.round(X_predchozi),Y,KrokY);
			//posun na další prvek v seznamu
			C=C->dalsi;
		}
		vozik=vozik->dalsi;//posun na další prvek v seznamu
		WidthCanvasCasoveOsy=m.round(X);//uchová velikost nejdelší osy, pro použítí pro export canvasu do rastru
		HeightCanvasCasoveOsy=Y+Form1->RzToolbar1->Height+KrokY;//uchová výšku grafu
	}                       //okraj na výšku nutno ještě dodělat exaktně
	if(Form1->grid)vykresli_Xosy(canv);//vykreslí statické svislice na časové osy pokud je aktivovaná mřížka
}
//---------------------------------------------------------------------------
//vykreslí jednu dílčí časovou osu (obdelníček objektu) pro jeden vozík, vytaženo pouze kvůli přehlednosti
void Cvykresli::vykresli_casovou_osu(TCanvas *canv, AnsiString shortname, TColor color, int X1, int X2, int Y, short KrokY)
{
	////osa
	//set_pen(canv,color,2);//nastavení pera barvy osy
	canv->Pen->Style=psClear;
	canv->Brush->Style=bsSolid;
	canv->Brush->Color=color;
	canv->Rectangle(X1,Y-KrokY/2,X2,Y+KrokY/2);

	////popisek
	SetBkMode(canv->Handle,OPAQUE);//nastvení transparentního pozadí
	if(color!=clBlack)canv->Font->Color=clBlack;else canv->Font->Color=clWhite;//pokud je obdelníček černě, tak popisek bude bíle
	canv->Font->Size=6;
	canv->Font->Name="Arial";
	canv->Font->Style = TFontStyles();//<< fsBold;//normání font (vypnutí tučné, kurzívy, podtrženo atp.)
	canv->TextOutW(((X2+X1)/2)-canv->TextWidth(shortname)/2,Y-canv->TextHeight(shortname)/2,shortname);//vypíše vycentrovaný (polovina nových a starých souřadnic a posun referenčního písma o horizontálně=TextWidth/2 a verticálně=TextHeight/2) popisek shorname t-objektu
}
//---------------------------------------------------------------------------
//vykreslí pohyblivou svislici na časové osy dle umístění kurzoru myši
void Cvykresli::vykresli_svislici_na_casove_osy(TCanvas *canv,int X)
{
	if(X!=-200)//pokud je mimo obraz -200 jen nahodilá hodnota pro zneplatenění čí výchozí obraz
	{
		canv->Pen->Mode=pmNotXor;
		canv->Pen->Width=1;
		canv->Pen->Style=psDashDot;//nastevení čarkované čáry
		canv->Pen->Color=clGray;
		canv->Brush->Style=bsClear;
		canv->MoveTo(X,0);
		canv->LineTo(X,Form1->ClientWidth);
		canv->Brush->Style=bsSolid;//vracím raději do původního stavu
	}
}
//---------------------------------------------------------------------------
//vykreslí statické svislice na časové osy
void Cvykresli::vykresli_Xosy(TCanvas *canv)
{

		canv->Pen->Width=1;    //nastavení šířky pera
		canv->Pen->Style=psDot;
		canv->Pen->Color=TColor RGB(220,220,220);   //míchání světlě šedé
		canv->Font->Color=clGray;
		canv->Brush->Style=bsClear;
		canv->TextOutW(1,0+Form1->RzToolbar1->Height,"[min]"); //popisek osy x

		canv->Font->Pitch = TFontPitch::fpFixed;
		canv->Font->Pitch = System::Uitypes::TFontPitch::fpFixed;





		for(int i=PX2MIN;i<=WidthCanvasCasoveOsy;i+=PX2MIN)
		{

		if(i==WidthCanvasCasoveOsy)
		{
	   //	canv->Font->Style=TFontStyles()<< fsBold;
		}
		else
		{
		canv->Font->Style = TFontStyles();
		}

			canv->MoveTo(i,0);
			canv->LineTo(i,HeightCanvasCasoveOsy);
			canv->Brush->Style=bsSolid;
			canv->Brush->Color=clWhite;
			canv->TextOutW(i-canv->TextWidth(i/PX2MIN)/2,0+Form1->RzToolbar1->Height,i/PX2MIN);

		}




		Cvektory::TSeznam_cest *ukaz=v.CESTY->dalsi;
while (ukaz!=NULL)
{
  UnicodeString	T=ukaz->cesta->predchozi->objekt->obsazenost/PX2MIN;
	canv->Font->Style=TFontStyles()<< fsBold;

	ShowMessage(T);

	canv->TextOutW(ukaz->cesta->predchozi->objekt->obsazenost-canv->TextWidth(T)/2,0+Form1->RzToolbar1->Height,T);

	ukaz=ukaz->dalsi;
}

	}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Cvykresli::rotace_textu(TCanvas *canv, long rotace)//úhel rotace je desetinách stupně
{
		LOGFONT LogRec;
		GetObject(canv->Font->Handle,sizeof(LogRec),&LogRec);
		LogRec.lfEscapement=rotace;
		canv->Font->Handle=CreateFontIndirect(&LogRec);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//nastaví pero
void Cvykresli::set_pen(TCanvas *canv, TColor color, int width, int style)//popř.PS_ENDCAP_FLAT PS_ENDCAP_ROUND, PS_ENDCAP_SQUERE viz Matoušek III str. 179
{
		DeleteObject(canv->Pen->Handle);//zruší původní pero
		DWORD pStyle = PS_GEOMETRIC | PS_SOLID | style | PS_JOIN_BEVEL;
		DWORD pWidth = width;

		LOGBRUSH lBrush;
		lBrush.lbStyle = BS_SOLID;
		lBrush.lbColor = color;
		lBrush.lbHatch = 0;

		canv->Pen->Handle = ExtCreatePen(pStyle, pWidth, &lBrush, NULL, NULL);
}
//---------------------------------------------------------------------------
void  Cvykresli::set_color(TCanvas *canv, double time)
{
		double taktTime=Form1->PP.TT;//Form1->Edit_takt_time->Text.ToDouble();

		unsigned short i=0;
		if(time>0)
		{
			if(time>taktTime)i=1;
			if(time<taktTime)i=6;
			if(time==taktTime)i=5;
		}
	 /*	rgb(255,140,0) - DarkOrange
		rgb(255,215,0) - Gold (žlutá)
		rgb(218,112,214) - Orchid (fialová)
		LightSkyBlue	rgb(135,206,250)
		//rgb(135,206,235) - SkyBlue
		rgb(152,251,152) -PaleGreen

		*/
		canv->Pen->Style=psClear;
		canv->Pen->Width=1;
		canv->Brush->Style=bsSolid;
		if(m.cele_cislo(Form1->Zoom)==false && i>0)canv->Pen->Style=psSolid;
		switch(i)
		{
			case 1:canv->Pen->Color=clRed;canv->Brush->Color=clRed;break;
			case 2:canv->Pen->Color=(TColor)RGB(255,140,0);canv->Brush->Color=(TColor)RGB(255,140,0);break;
			case 3:canv->Pen->Color=(TColor)RGB(255,215,0);canv->Brush->Color=(TColor)RGB(255,215,0);break;
			case 4:canv->Pen->Color=(TColor)RGB(218,112,214);canv->Brush->Color=(TColor)RGB(218,112,214);break;
			case 5:canv->Pen->Color=(TColor)RGB(135,206,250);canv->Brush->Color=(TColor)RGB(135,206,250);break;
			case 6:canv->Pen->Color=(TColor)RGB(152,251,152);canv->Brush->Color=(TColor)RGB(152,251,152);break;
			//default:canv->Pen->Color=clWhite;canv->Brush->Color=clWhite;break;
			default:canv->Brush->Style=bsBDiagonal;canv->Pen->Color=clRed;canv->Brush->Color=clRed;break;
		}

}
//---------------------------------------------------------------------------
//nakreslí editační okno
void Cvykresli::editacni_okno(TCanvas *canv,unsigned int  X1, unsigned int  Y1, unsigned int  X2, unsigned int  Y2, unsigned short int size, COLORREF color)//implicitně černá a velikost 1
{
	canv->Pen->Width=size;
	canv->Pen->Style=psSolid;
	canv->Pen->Color=(TColor)color;
	canv->Pen->Mode=pmNotXor;
	canv->Brush->Style=bsClear;
	canv->Rectangle(X1,Y1,X2,Y2);//obdelník editačního okna
	canv->Pen->Mode=pmCopy;
	canv->Brush->Style=bsSolid;
}
//nakreslí editační okno, přetížená fce
void Cvykresli::editacni_okno(TCanvas *canv, TPoint LH, TPoint PD, unsigned short int size, COLORREF color)
{
	editacni_okno(canv, LH.x, LH.y, PD.x, PD.y, size, color);
}
//---------------------------------------------------------------------------
//označí nebo odznačí objekt  používá se pro posouvání
void Cvykresli::odznac_oznac_objekt(TCanvas *canv, Cvektory::TObjekt *p, int posunX, int posunY,COLORREF color)
{
		//ShowMessage(UnicodeString(p->X)+" "+UnicodeString(p->Y));
		//nastavení pera
		canv->Pen->Color=(TColor)color;
		canv->Pen->Width=1;
		canv->Pen->Style=psDot;//nastevení čarkované čáry
		canv->Pen->Mode=pmNotXor;
		canv->Brush->Style=bsClear;

		//provizorní spojovací linie + znovupřekreslení zůčastněných objekt§ pro lepší vzhled
		if(v.OBJEKTY->predchozi->n>=3)//pokud budou alespoň 3 prky
		{

			if(p->n==1)//pokud se jedná o první prvek
			{
				canv->MoveTo(m.L2Px(p->predchozi->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(p->predchozi->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(p->X)+O_width*Form1->Zoom/2+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom/2+posunY);
				canv->LineTo(m.L2Px(p->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(p->dalsi->Y)+O_height*Form1->Zoom/2);
				sipka(canv,(m.L2Px(p->predchozi->predchozi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->predchozi->predchozi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->predchozi->predchozi->X,p->predchozi->predchozi->Y,p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->predchozi->predchozi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->predchozi->predchozi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->predchozi->predchozi->X,p->predchozi->predchozi->Y,p->X,p->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,(m.L2Px(p->dalsi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->dalsi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom,p->dalsi->X,p->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->dalsi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->dalsi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->X,p->Y,p->dalsi->X,p->dalsi->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,v.OBJEKTY->predchozi);
				vykresli_rectangle(canv,p);
				vykresli_rectangle(canv,p->dalsi);
			}
			if(p->n==v.OBJEKTY->predchozi->n)//pokud se jedná o poslední prvek
			{
				canv->MoveTo(m.L2Px(p->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(p->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(p->X)+O_width*Form1->Zoom/2+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom/2+posunY);
				canv->LineTo(m.L2Px(v.OBJEKTY->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(v.OBJEKTY->dalsi->Y)+O_height*Form1->Zoom/2);
				sipka(canv,(m.L2Px(p->predchozi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->predchozi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->predchozi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->predchozi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X,p->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,(m.L2Px(v.OBJEKTY->dalsi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(v.OBJEKTY->dalsi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom,v.OBJEKTY->dalsi->X,v.OBJEKTY->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((v.OBJEKTY->dalsi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((v.OBJEKTY->dalsi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->X,p->Y,v.OBJEKTY->dalsi->X,v.OBJEKTY->dalsi->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p->predchozi);
				vykresli_rectangle(canv,p);
				vykresli_rectangle(canv,v.OBJEKTY->dalsi);
			}
			if(p->n!=1 && p->n!=v.OBJEKTY->predchozi->n)//pokud se nejedná o první ani poslední prvek
			{
				canv->MoveTo(m.L2Px(p->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(p->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(p->X)+O_width*Form1->Zoom/2+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom/2+posunY);
				canv->LineTo(m.L2Px(p->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(p->dalsi->Y)+O_height*Form1->Zoom/2);
				sipka(canv,(m.L2Px(p->dalsi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->dalsi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom,p->dalsi->X,p->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->dalsi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->dalsi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->X,p->Y,p->dalsi->X,p->dalsi->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,(m.L2Px(p->predchozi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->predchozi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->predchozi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->predchozi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X,p->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p->predchozi);
				vykresli_rectangle(canv,p);
				vykresli_rectangle(canv,p->dalsi);
			}
		}

		if(v.OBJEKTY->predchozi->n==2)//pokud budou pouze 2 prky
		{
			if(p->n==1)//pokud se jedná o první prvek
			{
				canv->MoveTo(m.L2Px(p->X)+O_width*Form1->Zoom/2+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom/2+posunY);
				canv->LineTo(m.L2Px(p->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(p->dalsi->Y)+O_height*Form1->Zoom/2);
				sipka(canv,(m.L2Px(p->dalsi->X)+m.L2Px(p->X)+posunX+O_width*Form1->Zoom)/2,(m.L2Py(p->dalsi->Y)+m.L2Py(p->Y)+posunY+O_height*Form1->Zoom)/2,m.azimut(p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom,p->dalsi->X,p->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->dalsi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->dalsi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->X,p->Y,p->dalsi->X,p->dalsi->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p);
				vykresli_rectangle(canv,p->dalsi);
			}
			else//pokud se jedná o druhý prvek
			{
				canv->MoveTo(m.L2Px(p->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(p->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(p->X)+O_width*Form1->Zoom/2+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom/2+posunY);
				sipka(canv,(m.L2Px(p->predchozi->X)+m.L2Px(p->X)+O_width*Form1->Zoom+posunX)/2,(m.L2Py(p->predchozi->Y)+m.L2Py(p->Y)+O_height*Form1->Zoom+posunY)/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X+posunX/Form1->Zoom,p->Y-posunY/Form1->Zoom),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				sipka(canv,m.L2Px((p->predchozi->X+p->X)/2)+O_width*Form1->Zoom/2,m.L2Py((p->predchozi->Y+p->Y)/2)+O_height*Form1->Zoom/2,m.azimut(p->predchozi->X,p->predchozi->Y,p->X,p->Y),false,3,clBlack);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p->predchozi);
				vykresli_rectangle(canv,p);
			}
		}

		//samotná imitace posovaného objektu
		editacni_okno(canv, m.L2Px(p->X)+posunX,m.L2Py(p->Y)+posunY,m.L2Px(p->X)+O_width*Form1->Zoom+posunX,m.L2Py(p->Y)+O_height*Form1->Zoom+posunY,1);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//používá se pro přidávání objektu do mezi poslední a první prvek
void Cvykresli::odznac_oznac_objekt_novy_posledni(TCanvas *canv,int X, int Y)
{
		if(v.OBJEKTY->predchozi->n>0)//pokud už existuje nějaký prvek
		{
			if(X!=-200 && Y!=-200)//spojovací linie  //pokud je mimo obraz -200 jen nahodilá hodnota
			{
				canv->Pen->Color=clBlack;
				canv->Pen->Width=1;
				canv->Pen->Style=psDot;//nastevení čarkované čáry
				canv->Pen->Mode=pmNotXor;

				canv->MoveTo(m.L2Px(v.OBJEKTY->predchozi->X)+O_width*Form1->Zoom/2,m.L2Py(v.OBJEKTY->predchozi->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(X+O_width*Form1->Zoom/2,Y+O_height*Form1->Zoom/2);
				if(v.OBJEKTY->predchozi->n>1)//pokud je více než jenom jeden prvek
				{
					canv->LineTo(m.L2Px(v.OBJEKTY->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(v.OBJEKTY->dalsi->Y)+O_height*Form1->Zoom/2);
					sipka(canv,(m.L2Px(v.OBJEKTY->dalsi->X)+X)/2+O_width*Form1->Zoom/2,(m.L2Py(v.OBJEKTY->dalsi->Y)+Y)/2+O_height*Form1->Zoom/2,m.azimut(m.P2Lx(X),m.P2Ly(Y),v.OBJEKTY->dalsi->X,v.OBJEKTY->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
					vykresli_rectangle(canv,v.OBJEKTY->dalsi);
				}
				sipka(canv,(m.L2Px(v.OBJEKTY->predchozi->X)+X)/2+O_width*Form1->Zoom/2,(m.L2Py(v.OBJEKTY->predchozi->Y)+Y)/2+O_height*Form1->Zoom/2,m.azimut(v.OBJEKTY->predchozi->X,v.OBJEKTY->predchozi->Y,m.P2Lx(X),m.P2Ly(Y)),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,v.OBJEKTY->predchozi);
			}
		}
		editacni_okno(canv,X,Y,X+O_width*Form1->Zoom,Y+O_height*Form1->Zoom,1);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//používá se pro přidvání objektu mimo poslední a první prvek
void Cvykresli::odznac_oznac_objekt_novy(TCanvas *canv, int X, int Y,Cvektory::TObjekt *p)
{
		if(p->n>0)//pokud už existuje nějaký prvek
		{
			if(X!=-200 && Y!=-200)//spojovací linie  //pokud je mimo obraz -200 jen nahodilá hodnota
			{
				canv->Pen->Color=clBlack;
				canv->Pen->Width=1;
				canv->Pen->Style=psDot;//nastevení čarkované čáry
				canv->Pen->Mode=pmNotXor;

				canv->MoveTo(m.L2Px(p->X)+O_width*Form1->Zoom/2,m.L2Py(p->Y)+O_height*Form1->Zoom/2);
				canv->LineTo(X+O_width*Form1->Zoom/2,Y+O_height*Form1->Zoom/2);
				canv->LineTo(m.L2Px(p->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(p->dalsi->Y)+O_height*Form1->Zoom/2);
				sipka(canv,(m.L2Px(p->dalsi->X)+X)/2+O_width*Form1->Zoom/2,(m.L2Py(p->dalsi->Y)+Y)/2+O_height*Form1->Zoom/2,m.azimut(m.P2Lx(X),m.P2Ly(Y),p->dalsi->X,p->dalsi->Y),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p->dalsi);
				sipka(canv,(m.L2Px(p->X)+X)/2+O_width*Form1->Zoom/2,(m.L2Py(p->Y)+Y)/2+O_height*Form1->Zoom/2,m.azimut(p->X,p->Y,m.P2Lx(X),m.P2Ly(Y)),true,3,clBlack,clWhite,pmNotXor);//zajistí vykreslení šipky - orientace spojovací linie
				vykresli_rectangle(canv,p);
			}
		}
		editacni_okno(canv,X,Y,X+O_width*Form1->Zoom,Y+O_height*Form1->Zoom,1);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
bool Cvykresli::lezi_v_pasmu(TCanvas *c,long X,long Y,Cvektory::TObjekt *p)
{
		bool ret=false;

		int W=m.round(O_width*Form1->Zoom);
		int H=m.round(O_height*Form1->Zoom);

		if((p->X<=p->dalsi->X && p->Y<p->dalsi->Y)||(p->X>p->dalsi->X && p->Y>=p->dalsi->Y))
		ret=lezi_v_pasmu(c,X,Y,m.L2Px(p->X),m.L2Py(p->Y),m.L2Px(p->X)+W,m.L2Py(p->Y)+H,m.L2Px(p->dalsi->X)+W,m.L2Py(p->dalsi->Y)+H,m.L2Px(p->dalsi->X),m.L2Py(p->dalsi->Y));

		if((p->X>p->dalsi->X && p->Y<p->dalsi->Y)||(p->X<=p->dalsi->X && p->Y>=p->dalsi->Y))
		ret=lezi_v_pasmu(c,X,Y,m.L2Px(p->X),m.L2Py(p->Y)+H,m.L2Px(p->X)+W,m.L2Py(p->Y),m.L2Px(p->dalsi->X)+W,m.L2Py(p->dalsi->Y),m.L2Px(p->dalsi->X),m.L2Py(p->dalsi->Y)+H);

		return ret;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
bool Cvykresli::lezi_v_pasmu_poslednim(TCanvas *c,long X,long Y)
{
		bool ret=false;
		if(v.OBJEKTY->predchozi!=NULL)
		{
			int W=m.round(O_width*Form1->Zoom);
			int H=m.round(O_height*Form1->Zoom);

			if((v.OBJEKTY->predchozi->X<=v.OBJEKTY->dalsi->X && v.OBJEKTY->predchozi->Y<v.OBJEKTY->dalsi->Y)||(v.OBJEKTY->predchozi->X>v.OBJEKTY->dalsi->X && v.OBJEKTY->predchozi->Y>=v.OBJEKTY->dalsi->Y))
			ret=lezi_v_pasmu(c,X,Y,m.L2Px(v.OBJEKTY->predchozi->X),m.L2Py(v.OBJEKTY->predchozi->Y),m.L2Px(v.OBJEKTY->predchozi->X)+W,m.L2Py(v.OBJEKTY->predchozi->Y)+H,m.L2Px(v.OBJEKTY->dalsi->X)+W,m.L2Py(v.OBJEKTY->dalsi->Y)+H,m.L2Px(v.OBJEKTY->dalsi->X),m.L2Py(v.OBJEKTY->dalsi->Y));

			if((v.OBJEKTY->predchozi->X>v.OBJEKTY->dalsi->X && v.OBJEKTY->predchozi->Y<v.OBJEKTY->dalsi->Y)||(v.OBJEKTY->predchozi->X<=v.OBJEKTY->dalsi->X && v.OBJEKTY->predchozi->Y>=v.OBJEKTY->dalsi->Y))
			ret=lezi_v_pasmu(c,X,Y,m.L2Px(v.OBJEKTY->predchozi->X),m.L2Py(v.OBJEKTY->predchozi->Y)+H,m.L2Px(v.OBJEKTY->predchozi->X)+W,m.L2Py(v.OBJEKTY->predchozi->Y),m.L2Px(v.OBJEKTY->dalsi->X)+W,m.L2Py(v.OBJEKTY->dalsi->Y),m.L2Px(v.OBJEKTY->dalsi->X),m.L2Py(v.OBJEKTY->dalsi->Y)+H);
		}
		return ret;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
bool Cvykresli::lezi_v_pasmu(TCanvas *c,long X,long Y,long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4)
{
		POINT *body=new POINT[4];
		body[0].x=x1;body[0].y=y1;
		body[1].x=x2;body[1].y=y2;
		body[2].x=x3;body[2].y=y3;
		body[3].x=x4;body[3].y=y4;

		HRGN hreg=CreatePolygonRgn(body,4,WINDING);//vytvoření regionu
		HRGN hregO=CreateRectRgn(x1,y1,x2,y2);
		HRGN hregO1=CreateRectRgn(x3,y3,x4,y4);
		CombineRgn(hreg,hreg,hregO,RGN_DIFF);//aby neoznačoval objekt, tento region odečtu
		DeleteObject(hregO);
		CombineRgn(hreg,hreg,hregO1,RGN_DIFF);//aby neoznačoval objekt, tento region odečtu
		DeleteObject(hregO1);
		//c->Brush->Color = RGB(96, 96, 96);
		//FrameRgn(c->Handle,hreg,c->Brush->Handle,5,5);
		bool ret=PtInRegion(hreg,X,Y);
		delete body;body=NULL;
		DeleteObject(hreg);
		return ret;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//zajišťuje vykreslení simulace
void Cvykresli::vykresli_simulaci(TCanvas *canv)
{
	//vykreslení linky
	vykresli_linku(canv);

	//vozíky
	Cvektory::TVozik *ukaz1;
	ukaz1=v.VOZIKY->dalsi;//přeskočí hlavičku
	while (ukaz1!=NULL)
	{
			umisti_vozik(canv,ukaz1);
			ukaz1=ukaz1->dalsi;//posun na další prvek
	}

	//vykreslení palce
	Cvektory::TPalec *ukaz;
	ukaz=v.PALCE->dalsi;//přeskočí hlavičku
	while (ukaz!=NULL)
	{
			umisti_palec(canv,ukaz);
			ukaz=ukaz->dalsi;//posun na další prvek
	}

	//vypis
	canv->Brush->Color=clWhite;
	double sec=cas*Form1->Timer_simulace->Interval/1000.0;
	short h=floor(sec/3600);sec=sec-h*3600;
	short m=floor(sec/60);sec=sec-m*60;
	AnsiString H=h; if (h<10)H="0"+H;//pouze přidání 0 prefix
	AnsiString M=m; if (m<10)M="0"+M;//pouze přidání 0 prefix
	canv->Pen->Color=clGrayText;
	canv->TextOutW(10,30,H+":"+M+":"+AnsiString(sec));

	//ukončení simulace
	//Form1->Timer_simulace->Enabled=false;
	//sound();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::vykresli_linku(TCanvas *canv)//zajišťuje vykreslení osy linky
{
		//nastavení šířky a barvy linie
		canv->Pen->Color=(TColor)RGB(255,0,0);
		canv->Pen->Width=1*Form1->Zoom;
		canv->Pen->Mode=pmCopy;

		//samotné vykreslení
		Cvektory::TObjekt *ukaz=v.OBJEKTY->dalsi;//ukazatel na první objekt v seznamu OBJEKTU, přeskočí hlavičku
		while (ukaz!=NULL)
		{
			//počátek úsečky
			canv->MoveTo(m.L2Px(ukaz->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->Y)+O_height*Form1->Zoom/2);

			//konec úsečky
			if(ukaz->dalsi!=NULL)
			canv->LineTo(m.L2Px(ukaz->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(ukaz->dalsi->Y)+O_height*Form1->Zoom/2);
			else//pro spojnici z posledního bodu do prvního
			canv->LineTo(m.L2Px(v.OBJEKTY->dalsi->X)+O_width*Form1->Zoom/2,m.L2Py(v.OBJEKTY->dalsi->Y)+O_height*Form1->Zoom/2);

			//posun na další prvek v seznamu
			ukaz=ukaz->dalsi;
		}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::umisti_vozik(TCanvas *canv,Cvektory::TVozik *ukaz)//zajišťuje umístění vozíku na lince
{
	STOPKA(ukaz);
	SG(ukaz);
	if(ukaz->predchozi!=NULL)
	if(KOLIZE(ukaz,ukaz->predchozi))Form1->Memo1->Lines->Add("KOLIZE!");


	Cvektory::TObjekt *u_seg=ukaz->segment;//pouze zkrácení zápisu

	if(ukaz->stav==1 && cas%10==0)ukaz->stav=2;//pokud vozík čeká na palec a palec přijde nastaví stav na zelenou
	if(ukaz->stav==2)ukaz->pozice+=1;//pokud je povolen pohyb daného vozíku
	double rest=0;

	if(u_seg!=NULL)
	{
		double X1=m.L2Px(u_seg->X)+O_width*Form1->Zoom/2;
		double Y1=m.L2Py(u_seg->Y)+O_height*Form1->Zoom/2;
		double X2=0;double Y2=0;

		if(u_seg->dalsi!=NULL)
		{
			X2=m.L2Px(u_seg->dalsi->X)+O_width*Form1->Zoom/2;
			Y2=m.L2Py(u_seg->dalsi->Y)+O_height*Form1->Zoom/2;
		}
		else//pro poslední linii
		{
			X2=m.L2Px(v.OBJEKTY->dalsi->X)+O_width*Form1->Zoom/2;
			Y2=m.L2Py(v.OBJEKTY->dalsi->Y)+O_height*Form1->Zoom/2;
		}

		double delka=m.delka(X1,Y1,X2,Y2);
		double krok=1.0;//metrů optimálně by měl odpovídat 1px, aby nebylo znatelné problikávání při animaci

		//smazání starého čtverec-vozíku
		if(ukaz->pozice>-1)vykresli_vozik(canv,ukaz,m.round((ukaz->pozice-1)*Form1->Zoom*(X2-X1)/(delka/krok)+X1),m.round((ukaz->pozice-1)*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1),false);

		//zajistit překreslení umazávaného gridu, toto přimo ještě nefunguje //vykresli_grid(canv);

		//nakreslí nový čtverec-vozík
		if(ukaz->pozice>-1)vykresli_vozik(canv,ukaz,m.round(ukaz->pozice*Form1->Zoom*(X2-X1)/(delka/krok)+X1),m.round(ukaz->pozice*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1),true);

		//posun na další prvek v seznamu
		if(krok*(ukaz->pozice+1)*Form1->Zoom>delka)
		{
			//výpis zbytkukrok*ukaz->pozice*Form1->Zoom
			//canv->TextOutW(50,50,AnsiString(krok*ukaz->pozice*Form1->Zoom)+";"+AnsiString(delka));
			if(ukaz->pozice>-1)vykresli_vozik(canv,ukaz,m.round(ukaz->pozice*Form1->Zoom*(X2-X1)/(delka/krok)+X1),m.round(ukaz->pozice*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1),false);//v případě přechodu na další linii smazání starého
			rest=delka-(krok*(ukaz->pozice+1)*Form1->Zoom);//rest z minulé úsečky
			ukaz->pozice=rest;ukaz->segment=u_seg->dalsi;
		}
	}
	else//pokračování do dalšího kola
	{
		//pokračování do dalšího kola
		ukaz->pozice=rest;//rest z minulého kola
		ukaz->segment=v.OBJEKTY->dalsi;
		umisti_vozik(canv,ukaz);//nutná rekurze zajišťující, aby se nepřišlo o jeden krok simulace
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::vykresli_vozik(TCanvas *canv,Cvektory::TVozik *ukaz,long X,long Y,bool NEW=true)//zajišťuje vykreslení vozíku při simulaci
{
	//záměrná záměna z důvodu špatně navrženého (o 90° orotovaného) výpočtu souřadnic vozíku
	double delka=ukaz->sirka;
	double sirka=ukaz->delka;

	//nastavení stylu vykreslování
	canv->Pen->Width=0;
	canv->Pen->Mode=pmCopy;
	if(NEW)
	{
		canv->Pen->Color=(TColor)RGB(0,0,0);
		canv->Brush->Style=bsSolid;
		canv->Brush->Color=ukaz->barva;
	}
	else
	{
		canv->Pen->Color=(TColor)RGB(255,255,255);
		canv->Brush->Style=bsSolid;
		canv->Brush->Color=clWhite;
	}

	//příprava souřadnic bodů polygonu dle rotace
	double size=sqrt(pow(Form1->Zoom/Form1->m2px*delka/2,2)+pow(Form1->Zoom/Form1->m2px*sirka/2,2));
	double A=0;
	if(ukaz->segment->dalsi!=NULL)//mimo poslední spojnice
		A=m.azimut(ukaz->segment->X,ukaz->segment->Y,ukaz->segment->dalsi->X,ukaz->segment->dalsi->Y);
	else// pro poslední spojnici
		A=m.azimut(ukaz->segment->X,ukaz->segment->Y,v.OBJEKTY->dalsi->X,v.OBJEKTY->dalsi->Y);
	A+=ukaz->rotace;//přídání rotace vozíku k azimut segmentu
	double U=m.uhel(X,Y,X-delka/2,Y-sirka/2);
	POINT body[4]=
	{
		{m.round(X+m.rotace(1,360-U,A).x*size),m.round(Y+m.rotace(1,360-U,A).y*size)},
		{m.round(X+m.rotace(1,180-(360-U),A).x*size),m.round(Y+m.rotace(1,180-(360-U),A).y*size)},
		{m.round(X+m.rotace(1,180-U,A).x*size),m.round(Y+m.rotace(1,180-U,A).y*size)},
		{m.round(X+m.rotace(1,U,A).x*size),m.round(Y+m.rotace(1,U,A).y*size)}
	};
	canv->Polygon((TPoint*)body,3);

	//prozatim, potom budu ukladat celé vnější souřadnice
	ukaz->X=m.P2Lx(X);ukaz->X=m.P2Ly(Y);

	//provizorní vykreslení středu (pomocí uhlopříček)
	canv->MoveTo(body[0].x,body[0].y);canv->LineTo(body[2].x,body[2].y);
	canv->MoveTo(body[1].x,body[1].y);canv->LineTo(body[3].x,body[3].y);
	if(ukaz->n==1)
	{
	canv->TextOutW(50,110,AnsiString(ukaz->pozice));
	canv->TextOutW(50,130,AnsiString(v.PALCE->dalsi->pozice));
	}

	//provizorní výpis čísel rohu polygonu
	/*canv->TextOutW(body[0].x,body[0].y,"0");
	canv->TextOutW(body[1].x,body[1].y,"1");
	canv->TextOutW(body[2].x,body[2].y,"2");
	canv->TextOutW(body[3].x,body[3].y,"3");*/
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//přidá nový palec do seznamu PALCE s umístěním přímo na linku dle stanovené rozteče
void Cvykresli::priprav_palce()
{
	double roztec=10.0;//metr;
	double i=0.0;//krok pozice palců;
	double delka=0.0;
	Cvektory::TObjekt *ukaz=v.OBJEKTY->dalsi;//ukazatel na první objekt v seznamu OBJEKTU, přeskočí hlavičku
	while (ukaz!=NULL)
	{
		if(ukaz->dalsi!=NULL)delka=m.delka(ukaz->X,ukaz->Y,ukaz->dalsi->X,ukaz->dalsi->Y);//mimo posledního segmentu
		else delka=m.delka(ukaz->X,ukaz->Y,v.OBJEKTY->dalsi->X,v.OBJEKTY->dalsi->Y);// pro poslední segment
		while(i<=delka)
		{
			v.vloz_palec();
			v.PALCE->predchozi->pozice=i/Form1->m2px;
			v.PALCE->predchozi->segment=ukaz;
			i+=roztec;
		}
		//ShowMessage(AnsiString(delka)+" | "+AnsiString(i));
		i-=delka;//rest zbytek chybějící do celé délky řetězu se přenese/zohlední do dalšího segmentu
		//ShowMessage(AnsiString(i));
		ukaz=ukaz->dalsi;//posun na další prvek v seznamu
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//zajišťuje aktuální umístění vozíku na lince vůči animaci
void Cvykresli::umisti_palec(TCanvas *canv,Cvektory::TPalec *ukaz)
{
	double rest=0.0;
  ukaz->pozice+=1.0;
	//přesunoto z konce:ukaz->pozice+=1; //pozice na dílčí úsečce
	Cvektory::TObjekt *u_seg=ukaz->segment;//pouze zkrácení zápisu
	if(u_seg!=NULL)
	{
		double X1=m.L2Px(u_seg->X)+O_width*Form1->Zoom/2;
		double Y1=m.L2Py(u_seg->Y)+O_height*Form1->Zoom/2;
		double X2=0;double Y2=0;

		if(u_seg->dalsi!=NULL)
		{
			X2=m.L2Px(u_seg->dalsi->X)+O_width*Form1->Zoom/2;
			Y2=m.L2Py(u_seg->dalsi->Y)+O_height*Form1->Zoom/2;
		}
		else//pro poslední linii
		{
			X2=m.L2Px(v.OBJEKTY->dalsi->X)+O_width*Form1->Zoom/2;
			Y2=m.L2Py(v.OBJEKTY->dalsi->Y)+O_height*Form1->Zoom/2;
		}

		double delka=m.delka(X1,Y1,X2,Y2);
		double krok=1.0;//metrů optimálně by měl odpovídat 1px, aby nebylo znatelné problikávání při animaci

		//smazání starého palec
		if(ukaz->pozice>-1)vykresli_palec(canv,(ukaz->pozice-1)*Form1->Zoom*(X2-X1)/(delka/krok)+X1,(ukaz->pozice-1)*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1,false);

		//nakreslí nový palec
		if(ukaz->pozice>-1)vykresli_palec(canv,ukaz->pozice*Form1->Zoom*(X2-X1)/(delka/krok)+X1,ukaz->pozice*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1,true);

		//posun na další prvek v seznamu (na další zub
		if(krok*(ukaz->pozice+1)*Form1->Zoom>delka)
		{
			if(ukaz->pozice>-1)
			vykresli_palec(canv,(ukaz->pozice)*Form1->Zoom*(X2-X1)/(delka/krok)+X1,(ukaz->pozice)*Form1->Zoom*(Y2-Y1)/(delka/krok)+Y1,false);//v případě přechodu na další linii smazání starého
			rest=delka-(krok*ukaz->pozice+1*Form1->Zoom);//rest z minulé úsečky
			ukaz->pozice=rest;ukaz->segment=u_seg->dalsi;
		}
	}
	else//pokračování do dalšího kola (na další segment
	{
		//pokračování do dalšího kola
		ukaz->segment=v.OBJEKTY->dalsi;
		ukaz->pozice=rest;//přiřadí restovou hodnotu z minulého kola
		umisti_palec(canv,ukaz);//nutná rekurze zajišťující, aby se nepřišlo o jeden krok simulace
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//zajišťuje samotné vykreslení vozíku (rotovaný obdelník)
void Cvykresli::vykresli_palec(TCanvas *canv,double X,double Y,bool NEW=true)
{
	double size=2*Form1->Zoom;
	if(NEW)
	{
		canv->Pen->Mode=pmCopy;
		canv->Pen->Style=psSolid;
		canv->Brush->Color=clBlue;
		canv->Pen->Width=1;
		canv->Ellipse(m.round(X-size),m.round(Y-size),m.round(X+size),m.round(Y+size));
	}
	else
	{
		canv->Pen->Mode=pmCopy;
		canv->Pen->Style=psSolid;
		canv->Pen->Color=clWhite;
		canv->Brush->Color=clWhite;
		canv->Pen->Width=1;
		canv->Ellipse(m.round(X-size),m.round(Y-size),m.round(X+size),m.round(Y+size));
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::STOPKA(Cvektory::TVozik *ukaz)//zajištuje základní funkcionalitu technologického objektu v režimu S&G při vykreslování simulaci
{
	if(ukaz->segment!=NULL)
	{
		if(ukaz->segment->id==11)//stopka -- zatimí provizorně na objekt s ID 11
		{
		 if(ukaz->pozice<=0)ukaz->stav=ukaz->segment->stav;
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::SG(Cvektory::TVozik *ukaz)//zajištuje základní funkcionalitu technologického objektu STOPKA při vykreslování simulaci
{
	Cvektory::TObjekt *u_seg=ukaz->segment;//pouze zkrácení zápisu
	if(u_seg!=NULL)
	{
		if(u_seg->rezim==0)//S&G
		{
			switch (u_seg->stav)
			{
				case 0:
				{
					if(ukaz->pozice<=0)//pouze pro nový příchozí prvek
					{
						ukaz->stav=0;
						ukaz->timer=u_seg->CT*60;
						u_seg->stav=1;//čekací mod
					}
					//Form1->Memo1->Lines->Add(ukaz->pozice);
					break;
				}
				case 1:
				{
					if(--ukaz->timer==0)
					{
						u_seg->stav=2;//vozík může opustit objekt
						ukaz->stav=1;//vozík bude čekat na palec
					}
				}
				break;
				case 2:
				u_seg->stav=0;//objekt pozdrží další vozík
				break;
			}
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
bool Cvykresli::KOLIZE(Cvektory::TVozik *V1,Cvektory::TVozik *V2)//vrací logickou hodnotu zda došlo či nedošlo ke kolizi s jiným vozíkem
{  //provizorní algoritmus není dotažený
	 if(m.delka(V1->X,V1->Y,V2->X,V2->Y) <= V1->delka+V2->delka)//zatím nedokonalá detekce konfliktu
	 	return true;
	 else
		return false;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------
//vykresluje měřítko
/*
void Cvykresli::vykresli_meritko(TCanvas * canv, unsigned short Level, unsigned short ID_podklad, TPoint WH)
{
 if(Level>3)//zde měřítko příliš vizuálně záleželo na pozici od rovníku (rovník malé, poly - velké a vzhledem k umístění na obrazovce to mátlo)
 {
  unsigned short int X=10;// na monitoru na ose X umístění
  if(ID_podklad<=8)X=135;//v případě googlovských map až za nápisem GOOGLE
  unsigned short int Y=WH.y-15;// na monitoru na ose Y umístění
  unsigned short int rozsah=1;//rozsah na ose X,počet políček na ose X
  unsigned int faktorX=1000;//velikost jednoho políčka v METRECH na ose X
  unsigned short int faktorY=8;//velikost měřítka v px na ose Y
  //TColor barva=(TColor)RGB(0,128,192);//nastavení barva měřítka
  //TColor barva=(TColor)RGB(0,0,0);//nastavení barva měřítka

  //nastavení rozsahu měřítka
  switch(Level)
  {     //x políček//políčko metrů
   case 1:rozsah=1;faktorX=1000000;break;
   case 2:rozsah=2;faktorX=1000000;break;
   case 3:rozsah=2;faktorX=1000000;break;
   case 4:rozsah=2;faktorX=500000;break;
   case 5:rozsah=2;faktorX=250000;break;
   case 6:rozsah=2;faktorX=100000;break;
   case 7:rozsah=2;faktorX=50000;break;
   case 8:rozsah=2;faktorX=25000;break;
   case 9:rozsah=2;faktorX=10000;break;
   case 10:rozsah=2;faktorX=5000;break;
   case 11:rozsah=2;faktorX=2000;break;
   case 12:rozsah=3;faktorX=1000;break;
   case 13:rozsah=4;faktorX=500;break;
   case 14:rozsah=4;faktorX=250;break;
   case 15:rozsah=5;faktorX=100;break;
   case 16:rozsah=4;faktorX=50;break;
   case 17:rozsah=4;faktorX=25;break;
   case 18:rozsah=5;faktorX=10;break;
   case 19:rozsah=4;faktorX=5;break;
   case 20:rozsah=5;faktorX=2;break;

  }

  //nastavení fontu
  canv->Font->Color=barva_meritko;
  canv->Font->Name="Tahoma";
  canv->Font->Size=8;
	//canv->Font->Style = TFontStyles() /*<< fsItalic *//*<< fsBold;
  canv->Brush->Style=bsClear;

  //samotné měřítko
  for(unsigned short int i=0;i<=rozsah;i++)//i je jedno políčko
  {
	//výplň
	if(i!=rozsah)//mimo poslední, je totiž o krok dál než pismo (indexace od nuly+konec dílku)
	{
	   if(i%2)canv->Brush->Color=barva_meritko;//výplň barevna
	   else canv->Brush->Color=clWhite;//výplň bílá
	   canv->FillRect(TRect(m.px_offset(X,Y,faktorX*i),Y,m.px_offset(X,Y,faktorX+faktorX*i),Y-faktorY));
	}
	//text
	int delit_jednotky=1000.0;//v případě použí kilometrů
	AnsiString jednotky="";
    if(faktorX<1000)
	{
      delit_jednotky=1;
	  if(i==rozsah)jednotky=" m";
    }
	else if(i==rozsah)jednotky=" km";//v případě přepnutí do metrů //pokud se jedná o poslední popisek přidá i km
	AnsiString text=faktorX*i/delit_jednotky;
	canv->Brush->Style=bsClear;
	canv->TextOutA(m.px_offset(X-canv->TextWidth(text)/2,Y,faktorX*i),Y,text+jednotky);
  }

  //oramávání
  canv->Pen->Width=1;
  //canv->Brush->Style=bsSolid;
	canv->Pen->Style=psSolid;
	canv->Pen->Mode=pmCopy;
  canv->Pen->Color=barva_meritko;
  canv->Rectangle(m.px_offset(X,Y,0),Y,m.px_offset(X,Y,rozsah*faktorX),Y-faktorY);
 }
}*/
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Cvykresli::sound()
{
	Beep(400,250);	// 440 hertz (A4) for half a second
	Beep(500,250);	// 494 hertz for half a second
	Beep(600,250);	// 523 hertz for half a second
	Beep(700,250);	// 587 hertz for half a second
	Beep(800,500);	// 659 hertz for half a second
}
//------------------------------------------------------------------------------------------------------------------------------------------------------


