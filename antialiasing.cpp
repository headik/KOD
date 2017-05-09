//---------------------------------------------------------------------------

#pragma hdrstop
#include "antialiasing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//vrátí bitmapu pøesampovanou pomocí algoritmu antialiasingu
Graphics::TBitmap *Cantialising::antialiasing(Graphics::TBitmap *bmp_in)
{
  //tutorial
	//http://www.builder.cz/rubriky/delphi/aliasing-a-antialiasing-156152cz
	//http://www.builder.cz/rubriky/delphi/fastantialiasing-156158cz

	//zoom
	short Z=3;//*3 vyplývá z logiky algoritmu antialiasingu

	//vstupní bitmapa
	bmp_in->PixelFormat=pf24bit;//nutné!!!

	//výstupní bitmapa
	Graphics::TBitmap *bmp_out=new Graphics::TBitmap;
	bmp_out->PixelFormat=pf24bit;//nutné!!!
	bmp_out->Width=bmp_in->Width/Z;bmp_out->Height=bmp_in->Height/Z;
	if(grid)
	{
		bmp_out->Transparent=true;
		bmp_out->TransparentColor=clWhite;
		bmp_out->TransparentMode = tmAuto;
	}

	for(int Y=0;Y<=bmp_out->Height-1;Y++)// pro všechny øadky
	{
		//naètení øádkù
		PRGBTriple RD = (PRGBTriple)(bmp_out->ScanLine[Y]);// Vezmu ukazatel na sloupec y z výsledné bitmapy
		int CY=Y*Z;
		PRGBTriple R1=(PRGBTriple)(bmp_in->ScanLine[CY]);//Vezmu body od aktuálního
		PRGBTriple R2=(PRGBTriple)(bmp_in->ScanLine[CY+1]);//následujícího
		PRGBTriple R3=(PRGBTriple)(bmp_in->ScanLine[CY+2]);// a ještì následujícího sloupce v pøesamplované bitmapì

		//práce se jednolivými pixely (jednoprvkovými sloupci) øádkù
		for(int X=0;X<=bmp_out->Width-1;X++)
		{
			int CX=X*Z;// zpracuju vzorky z 3 x 3 pixelu
				 // icializace vysledne barvy
			RD[X].rgbtRed=(R1[CX].rgbtRed+R2[CX].rgbtRed+R3[CX].rgbtRed+R1[CX+1].rgbtRed+R2[CX+1].rgbtRed+R3[CX+1].rgbtRed+R1[CX+2].rgbtRed+R2[CX+2].rgbtRed+R3[CX+2].rgbtRed)/9;
			RD[X].rgbtGreen=(R1[CX].rgbtGreen+R2[CX].rgbtGreen+R3[CX].rgbtGreen+R1[CX+1].rgbtGreen+R2[CX+1].rgbtGreen+R3[CX+1].rgbtGreen+R1[CX+2].rgbtGreen+R2[CX+2].rgbtGreen+R3[CX+2].rgbtGreen)/9;
			RD[X].rgbtBlue=(R1[CX].rgbtBlue+R2[CX].rgbtBlue+R3[CX].rgbtBlue+R1[CX+1].rgbtBlue+R2[CX+1].rgbtBlue+R3[CX+1].rgbtBlue+R1[CX+2].rgbtBlue+R2[CX+2].rgbtBlue+R3[CX+2].rgbtBlue)/9;
		}
	}

	return bmp_out;
}
