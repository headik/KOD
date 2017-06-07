//---------------------------------------------------------------------------
#ifndef MyStringH
#define MyStringH
#include <vcl.h>
//#include "my.h"
//---------------------------------------------------------------------------
//struktury
//struktury
class TMyString
{
private:

public:

  AnsiString EP(AnsiString Text,AnsiString StartElement, AnsiString StopElement, unsigned short int startoffset=0, unsigned short int stopoffset=0);//parsování textu mezi zadanými texty, popø. možno využít offsetu  - ELEMENT PARSER
  UnicodeString TMyString::EP(UnicodeString Text,UnicodeString StartElement, UnicodeString StopElement, unsigned short int startoffset, unsigned short int stopoffset);
  AnsiString EP2(AnsiString Text,AnsiString StartElement, AnsiString StopElement, unsigned short int startoffset=0, unsigned short int stopoffset=0);//parsování textu mezi zadanými texty, popø. možno využít offsetu  - ELEMENT PARSER
	AnsiString replace(AnsiString Text,AnsiString Insert,AnsiString Delete);//nahradí daný text
	UnicodeString replace(UnicodeString Text,UnicodeString Insert,UnicodeString Delete);//nahradí daný text
  unsigned int count(AnsiString Text,AnsiString Find);//vráti poèet výskytù daného øetìzce
  unsigned int count(UnicodeString Text,UnicodeString Find);//vráti poèet výskytù daného øetìzce
  AnsiString l2h(AnsiString l);//zmìní první písmeno na velké
  AnsiString delete_repeat(AnsiString Text, AnsiString Text_delete,unsigned int Repeat, unsigned short int Offset=0);//smaže vše po zadaný text X-krát
  UnicodeString delete_repeat_UTF(UnicodeString Text, UnicodeString Text_delete,unsigned int Repeat, unsigned short int Offset=0);
  AnsiString delete_repeat(AnsiString Text, AnsiString Text_delete);
  UnicodeString delete_repeat(UnicodeString Text, UnicodeString Text_delete);
	AnsiString delete_repeat_all(AnsiString Text, AnsiString Text_delete);
	UnicodeString DeleteSpace(UnicodeString text);
  AnsiString TrimRightFrom(AnsiString Text,AnsiString Trim);//ožízne øetezec po znak, to co pøedchází znaku, vrátí
  UnicodeString TrimRightFrom_UTF(UnicodeString Text,UnicodeString Trim);//ožízne øetezec po znak, to co pøedchází znaku, vrátí
  UnicodeString TrimLeftFrom_UTF(UnicodeString  Text, UnicodeString Trim);//ožízne øetezec po znaku, to co následuje znaku, vrátí
  AnsiString Win2UTF(AnsiString Text);//pøevede text v kódování WINDOWS-1250 na UTF-8
  AnsiString UTF2Win(AnsiString Text);//pøevede text v kódování UTF-8 na WINDOWS-1250
  double MyToDouble (UnicodeString Text);//pøevede UnicodeString na Double, v pøípadì èárky pøevede na teèku
  AnsiString c2t(AnsiString Vstup);
  AnsiString t2c(AnsiString Vstup);
  long a2i(AnsiString Vstup);
  long u2i(UnicodeString Vstup);
  long long a2ll(AnsiString Vstup);
  UnicodeString get_local_decimal();//vrátí oddìlovaè desetinného místa na daném systému
  UnicodeString get_local_double(double number);//vrátí reálné èíslo s oddìlovaè desetinného místa na daném systému

	//TPointD HexGes2Dec(UnicodeString Loc);//pøevede èíslo z hexagesimálního tvaru na dekadický
protected:

};
//---------------------------------------------------------------------------
#endif
