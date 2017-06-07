//---------------------------------------------------------------------------
#pragma hdrstop

#include "MyString.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//parsování textu mezi zadanými texty, popř. možno využít offsetu  - ELEMENT PARSER
AnsiString TMyString::EP(AnsiString Text,AnsiString StartElement, AnsiString StopElement, unsigned short int startoffset, unsigned short int stopoffset)
{
  if(Text.Pos(StartElement)==0 || Text.Pos(StopElement)==0)
    return AnsiString("");
  else
  {
    Text=Text.Delete(1,Text.Pos(StartElement)+StartElement.Length()+startoffset-1);//smaže vše předchozí, kvůli duplicitám
    return Text.SubString(1,Text.Pos(StopElement)-stopoffset-1);
  }
}
UnicodeString TMyString::EP(UnicodeString Text,UnicodeString StartElement, UnicodeString StopElement, unsigned short int startoffset, unsigned short int stopoffset)
{
  if(Text.Pos(StartElement)==0 || Text.Pos(StopElement)==0)
    return UnicodeString("");
  else
  {
    Text=Text.Delete(1,Text.Pos(StartElement)+StartElement.Length()+startoffset-1);//smaže vše předchozí, kvůli duplicitám
    return Text.SubString(1,Text.Pos(StopElement)-stopoffset-1);
  }
}
//---------------------------------------------------------------------------
//parsování textu včetně ohraničujicích zadaných textů, popř. možno využít offsetu  - ELEMENT PARSER
AnsiString TMyString::EP2(AnsiString Text,AnsiString StartElement, AnsiString StopElement, unsigned short int startoffset, unsigned short int stopoffset)
{
  if(Text.Pos(StartElement)==0 || Text.Pos(StopElement)==0)
    return AnsiString("");
  else
  {
    Text=Text.Delete(1,Text.Pos(StartElement)+startoffset-1);//smaže vše předchozí, kvůli duplicitám
    return Text.SubString(1,Text.Pos(StopElement)+StopElement.Length()-1-stopoffset);
  }
}
//---------------------------------------------------------------------------
//změní první písmeno na velké
AnsiString TMyString::l2h(AnsiString l)
{
 return l.SubString(1,1).UpperCase()+l.SubString(2,l.Length()-1);
}
//---------------------------------------------------------------------------
//nahradí daný text
AnsiString TMyString::replace(AnsiString Text,AnsiString Insert,AnsiString Delete)
{
	if(Insert.Pos(Delete)==0)//pokud neobsahuje nahrazovaný text puvodní text napr. v případě pokud:  "*" za "*:", else vitev ochrana poed zacyklením, if vitev strojovi méni nároenijší
	{
		while(Text.Pos(Delete)!=0) //nefunguje v poípad pokud:  "*" za "*:" se zacyklí
		{
			Text.Insert(Insert,Text.Pos(Delete));
			Text.Delete(Text.Pos(Delete),Delete.Length());
		}
		return Text;
	}
	else
	{
		unsigned long Pocet=count(Text,Delete);//zjistí počet výskytů
		int *Pole=new int[Pocet];//ukládání indexů umístění
		unsigned long Pos;//aktuální pozice
		for(unsigned long i=1;i<=Pocet;i++)
		{
			Pos=Text.Pos(Delete);//najde znak který je na řadě
			Pole[i-1]=Pos;//uloží jeho pozici do pole
			Text.Delete(Pos,Delete.Length());//smaže nalezený znak
		}
		for(unsigned long i=1;i<=Pocet;i++)
		{
			Text.Insert(Insert,Pole[i-1]+(i-1)*Insert.Length());//+pousouvá o pozici o kterou nově zabírá nový řetězec
		}
		delete[] Pole;
		return Text;
	}
}
//---------------------------------------------------------------------------
//nahradí daný text
UnicodeString TMyString::replace(UnicodeString Text,UnicodeString Insert,UnicodeString Delete)
{
	if(Insert.Pos(Delete)==0)//pokud neobsahuje nahrazovaný text puvodní text napr. v případě pokud:  "*" za "*:", else vitev ochrana poed zacyklením, if vitev strojovi méni nároenijší
	{
		while(Text.Pos(Delete)!=0) //nefunguje v poípad pokud:  "*" za "*:" se zacyklí
		{
			Text.Insert(Insert,Text.Pos(Delete));
			Text.Delete(Text.Pos(Delete),Delete.Length());
		}
		return Text;
	}
	else
	{
		unsigned long Pocet=count(Text,Delete);//zjistí počet výskytů
		int *Pole=new int[Pocet];//ukládání indexů umístění
		unsigned long Pos;//aktuální pozice
		for(unsigned long i=1;i<=Pocet;i++)
		{
			Pos=Text.Pos(Delete);//najde znak který je na řadě
			Pole[i-1]=Pos;//uloží jeho pozici do pole
			Text.Delete(Pos,Delete.Length());//smaže nalezený znak
		}
		for(unsigned long i=1;i<=Pocet;i++)
		{
			Text.Insert(Insert,Pole[i-1]+(i-1)*Insert.Length());//+pousouvá o pozici o kterou nově zabírá nový řetězec
		}
		delete[] Pole;
		return Text;
	}
}
//---------------------------------------------------------------------------
//vráti počet výskytů daného řetězce
unsigned int TMyString::count(AnsiString Text,AnsiString Find)
{
  unsigned int count=0;
  while(Text.Pos(Find)!=0)
  {
    count++;
    Text.Delete(Text.Pos(Find),Find.Length());
  }
  return count;
}
unsigned int TMyString::count(UnicodeString Text,UnicodeString Find)
{
  unsigned int count=0;
  while(Text.Pos(Find)!=0)
  {
    count++;
    Text.Delete(Text.Pos(Find),Find.Length());
  }
  return count;
}
//---------------------------------------------------------------------------
//smaže vše od počátku textu až po zadaný text X-krát dle zadání
AnsiString TMyString::delete_repeat(AnsiString Text, AnsiString Text_delete,unsigned int Repeat, unsigned short int Offset)
{
  for(unsigned int i=1;i<=Repeat;i++)
  {
    unsigned short int offset=0;
    if(i==Repeat)offset=Offset;
    Text.Delete(1,Text.Pos(Text_delete)+Text_delete.Length()-1-offset);
  }
  return Text;
}
UnicodeString TMyString::delete_repeat_UTF(UnicodeString Text, UnicodeString Text_delete,unsigned int Repeat, unsigned short int Offset)
{
  for(unsigned int i=1;i<=Repeat;i++)
  {
    unsigned short int offset=0;
    if(i==Repeat)offset=Offset;
    Text.Delete(1,Text.Pos(Text_delete)+Text_delete.Length()-1-offset);
  }
  return Text;
}
//---------------------------------------------------------------------------
//smaže všechen výskyt textu k vymazání (předcházející a ostatní text zanecha)
AnsiString TMyString::delete_repeat(AnsiString Text, AnsiString Text_delete)
{
  while(Text.Pos(Text_delete)!=0)
  {
	Text.Delete(Text.Pos(Text_delete),Text_delete.Length());
  }
  return Text;
}
//smaže všechen výskyt textu k vymazání (předcházející a ostatní text zanecha)
UnicodeString TMyString::delete_repeat(UnicodeString Text, UnicodeString Text_delete)
{
  while(Text.Pos(Text_delete)!=0)
  {
	Text.Delete(Text.Pos(Text_delete),Text_delete.Length());
  }
  return Text;
}
//---------------------------------------------------------------------------
//ožízne řetezec po znak, to co předchází znaku, vrátí
AnsiString TMyString::TrimRightFrom(AnsiString Text, AnsiString Trim)
{
  unsigned int Pos=Text.Pos(Trim);
  if(Pos!=0)
  {
    return Text.SubString(1,Pos-1);
  }
  else
  return Text;
}
UnicodeString  TMyString::TrimRightFrom_UTF(UnicodeString  Text, UnicodeString Trim)
{
  unsigned int Pos=Text.Pos(Trim);
  if(Pos!=0)
  {
    return Text.SubString(1,Pos-1);
  }
  else
  return Text;
}
//---------------------------------------------------------------------------
//ožízne řetezec od znaku, to co následuje znaku, vrátí
UnicodeString  TMyString::TrimLeftFrom_UTF(UnicodeString  Text, UnicodeString Trim)
{
  unsigned int Pos=Text.Pos(Trim);
  if(Pos!=0)
  {
	return Text.SubString(Pos+1,Text.Length());
  }
  else
  return Text;
}
//---------------------------------------------------------------------------
//smaže vše od počátku textu až po všechny vyskyty znaku, včetně ostatního textu co předchází
AnsiString TMyString::delete_repeat_all(AnsiString Text, AnsiString Text_delete)
{
  while(Text.Pos(Text_delete)!=0)
  {
    Text.Delete(1,Text.Pos(Text_delete)+Text_delete.Length()-1);
  }
  return Text;
}
//---------------------------------------------------------------------------
UnicodeString TMyString::DeleteSpace(UnicodeString text)//vymaže mezeru
{
       while(text.Pos(" ")>0)
       {
				text=text.Delete(text.Pos(" "),1);
       }
       return text;
}
//---------------------------------------------------------------------------
//převede text v kódování WINDOWS-1250 na UTF-8
AnsiString TMyString::Win2UTF(AnsiString Text)
{
  /*WideString WData=Text;
  char *CHData=new char[Text.Length()+4];
  WideCharToMultiByte(CP_UTF8,0,WData,Text.Length()+4,CHData,Text.Length()+4,NULL, NULL );
  AnsiString t=CHData;
  return t;
  */
  return AnsiToUtf8(Text);
}
//---------------------------------------------------------------------------
//převede text v kódování UTF-8 na WINDOWS-1250
AnsiString TMyString::UTF2Win(AnsiString Text)
{
  WCHAR *WData=new WCHAR[Text.Length()];
  MultiByteToWideChar(CP_UTF8,0,Text.c_str(),Text.Length(),WData,Text.Length());
  AnsiString DATA=WData;
  delete WData;
  return DATA;
}
//---------------------------------------------------------------------------
//převede text do double datového typu, řeší nastavení desetinná tečka vs. čárka
double TMyString::MyToDouble(UnicodeString Text)
{
  double number=0.0;
  if(Text!="")//pokud přijde prázdný řetězec přehodí na nulu
  {
    try{number=Text.ToDouble();}//testování výjimky
	catch(...)//zachycení výjimky
	{
		try{number=replace(Text,",",".").ToDouble();}
		catch(...){;}//vráti nulu pokud se ani po změně oddělovače byl řetězec neplatný
	}
  }
  return number;
}
//---------------------------------------------------------------------------
//prevod z carky na tecku v desetiném miste
AnsiString TMyString::c2t(AnsiString Vstup)
{
  int Pozice=Vstup.Pos(",");
  if(Pozice>0)
  {
    Vstup.Delete(Pozice,1);
    Vstup.Insert(".",Pozice);
    if(Vstup.Pos(",")>0)Vstup=c2t(Vstup);//rekurze
  }
  return Vstup;
}
//---------------------------------------------------------------------------
//prevod z tecky na carku v desetiném miste
AnsiString TMyString::t2c(AnsiString Vstup)
{
  int Pozice=Vstup.Pos(".");
  if(Pozice>0)
  {
    Vstup.Delete(Pozice,1);
    Vstup.Insert(",",Pozice);
    if(Vstup.Pos(",")>0)Vstup=t2c(Vstup);//rekurze
  }
  return Vstup;
}
//---------------------------------------------------------------------------
//převod AnsiStringu na integer, řeší, když příjde prázdný řetězec, nebo když se nejedná o číslo
long TMyString::a2i(AnsiString Vstup)
{
  try
  {
	if(Vstup=="")return 0;
	else return Vstup.ToInt();
  }
  catch(...)
  {
	return 0;
  }
}
//převod Unicode na integer, řeší, když příjde prázdný řetězec, nebo když se nejedná o číslo
long TMyString::u2i(UnicodeString Vstup)
{
  try
  {
	if(Vstup=="")return 0;
	else return Vstup.ToInt();
  }
  catch(...)
  {
	return 0;
  }
}
//není přesně do long longu ale alespoň větší než longu, viz lenost
long long TMyString::a2ll(AnsiString Vstup)
{
  try
  {
	if(Vstup=="")return 0;
	else return (long long) Vstup.ToDouble();
  }
  catch(...)
  {
	return 0;
  }
}
//---------------------------------------------------------------------------
//vrátí oddělovač desetinného místa na daném systému
UnicodeString TMyString::get_local_decimal()
{
 char text[5];
 //GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_SDECIMAL,text,sizeof(text));
 return UnicodeString(text);
}
//---------------------------------------------------------------------------
//vrátí reálné číslo s oddělovač desetinného místa na daném systému
//určeno pro výstupy ze systému
UnicodeString TMyString::get_local_double(double number)
{
	UnicodeString oddelovac=get_local_decimal();
	if(UnicodeString(number).Pos(oddelovac)>0)//oddělovač byl nastaven správne
		return UnicodeString(number);
	else
	{
	   if(UnicodeString(number).Pos(".")>0)
		return replace(UnicodeString(number),oddelovac,".");
	   else
	   	return replace(UnicodeString(number),oddelovac,",");
	}
}
//---------------------------------------------------------------------------
//převede číslo z hexagesimálního tvaru na dekadický
/*
LAT,LONG
49.8703442,16.3115764 níže uvedené převádí do tohoto a navíc dodrží na výstupu pořadí lat,long  pokud je zadané
49.8703442 16.3115764
49.8703442, 16.3115764
49.8703442º N, 16.3115764º Ø//zadává kart.finn.no
49.8703442°N,16.3115764°E
49.8703442°N 16.3115764°E
49.8703442°N, 16.3115764°E
49°52.22065'N,16°18.69458'E
49°52.22065'N 16°18.69458'E
49°52.22065'N, 16°18.69458'E
49°52'13.239"N,16°18'41.675"E
49°52'13.239"N 16°18'41.675"E
49°52'13.239"N, 16°18'41.675"E
*//*
TPointD TMyString::HexGes2Dec(UnicodeString Loc)
{
	Loc=Utf8ToAnsi(Loc);//v případě kart.finn.no
	if(count(Loc," ")>1)Loc=delete_repeat(Loc," ");//pokud je více mezer, tak vše odstraní
	Loc=replace(Loc,"E","O");Loc=replace(Loc,"°","o");//kvůli kart.finn.no
	//sjednocení formátu na variantu s oddělovačem čárkou a bez mezery
	if(Loc.Pos(" ") && Loc.Pos(","))Loc=Loc.Delete(Loc.Pos(" "),1);//pokud obsahuje jak mezeru, tak čárku, tak nechá jenom čárku
	if(Loc.Pos(" ") && !Loc.Pos(","))Loc=replace(Loc,","," ");//pokud je obsažena pouze mezera, tak ji nahradí čárkou

	if(!Loc.Pos("°")) //pokud se jedná o decimální tvar
	{
		 TPointD LongLat;
		 LongLat.y=MyToDouble(Loc.SubString(1,Loc.Pos(",")-1));
		 LongLat.x=MyToDouble(Loc.SubString(Loc.Pos(",")+1,Loc.Length()-Loc.Pos(",")));
		 return LongLat;
  }
	else//pokud se jedná o HEX tvar
	{
			TPointD LongLat_pom;
			bool sirka_prvni;
			double znamenko1=1.0;
			double znamenko2=1.0;

			//pokud je šířka první údaj
			if(Loc.Pos("N,") || Loc.Pos("S,"))sirka_prvni=true;else sirka_prvni=false;//pokud je délka první údaj

			//určení znaménka
			UnicodeString s1=TrimRightFrom_UTF(Loc,",");if(s1.SubString(s1.Length(),1)=="S" || s1.SubString(s1.Length(),1)=="W")znamenko1-1.0;else znamenko1=1.0;
			UnicodeString s2=TrimLeftFrom_UTF(Loc,",");if(s2.SubString(s2.Length(),1)=="S" || s2.SubString(s2.Length(),1)=="W")znamenko2-1.0;else znamenko2=1.0;

			s1=s1.Delete(s1.Length(),1); s2=s2.Delete(s2.Length(),1);//odebere poslední indikátor N,S,E,W

			if(s1.Pos("°") &&  s1.Pos("\'") &&  s1.Pos("\""))//49°52'13.239"N,16°18'41.675"E
			{
				LongLat_pom.y=MyToDouble(TrimRightFrom_UTF(s1,"°"))+(MyToDouble(EP(s1,"°","\'"))/60.0)+(MyToDouble(EP(s1,"\'","\""))/3600.0);
				LongLat_pom.x=MyToDouble(TrimRightFrom_UTF(s2,"°"))+(MyToDouble(EP(s2,"°","\'"))/60.0)+(MyToDouble(EP(s2,"\'","\""))/3600.0);
			}
			else
			{
				if(s1.Pos("\'") && !s1.Pos("\""))//49°52.22065'N,16°18.69458'E
				{
					s1=s1.Delete(s1.Length(),1); s2=s2.Delete(s2.Length(),1);//znovu odebere poslední indikátor minuty
					LongLat_pom.y=MyToDouble(TrimRightFrom_UTF(s1,"°"))+(MyToDouble(TrimLeftFrom_UTF(s1,"°"))/60.0);
					LongLat_pom.x=MyToDouble(TrimRightFrom_UTF(s2,"°"))+(MyToDouble(TrimLeftFrom_UTF(s2,"°"))/60.0);
				}
				else
				if(s1.Pos("°") &&  !s1.Pos("\'") && !s1.Pos("\""))//49.8703442°N,16.3115764°E
				{
					LongLat_pom.y=MyToDouble(s1.Delete(s1.Length(),1));//odebere indikátor stupnu a prevede na cislo
					LongLat_pom.x=MyToDouble(s2.Delete(s2.Length(),1));//odebere indikátor stupnu a prevede na cislo
				}
				}

			//určerní pořadí a znaménka na výstupu
			TPointD LongLat;
			if(sirka_prvni)
			{
				LongLat.y=LongLat_pom.y*znamenko1;LongLat.x=LongLat_pom.x*znamenko2;
			}
			else
			{
				LongLat.y=LongLat_pom.x*znamenko2;LongLat.x=LongLat_pom.y*znamenko1;
			}
			return LongLat;
	}
}  */
//---------------------------------------------------------------------------


