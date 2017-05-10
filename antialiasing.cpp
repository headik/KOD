//---------------------------------------------------------------------------

#pragma hdrstop
#include "antialiasing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//vrátí bitmapu pøesampovanou pomocí algoritmu antialiasingu
Graphics::TBitmap *Cantialising::antialiasing(Graphics::TBitmap *bmp_grid,Graphics::TBitmap *bmp_in)
{
	//tutoriál
	//http://www.builder.cz/rubriky/delphi/aliasing-a-antialiasing-156152cz
	//http://www.builder.cz/rubriky/delphi/fastantialiasing-156158cz

	//zoom
	short Z=3;//*3 vyplývá z logiky algoritmu antialiasingu

	//vstupní bitmapy
	bmp_grid->PixelFormat=pf24bit;//nutné!!!
	bmp_in->PixelFormat=pf24bit;//nutné!!!

	//výstupní bitmapa
	Graphics::TBitmap *bmp_out=new Graphics::TBitmap;
	bmp_out->PixelFormat=pf24bit;//nutné!!!
	bmp_out->Width=bmp_in->Width/Z;bmp_out->Height=bmp_in->Height/Z;//tøetinová velikost výsledné bitmapy

	//if(grid){bmp_out->Transparent=true;bmp_out->TransparentColor=clWhite;bmp_out->TransparentMode = tmAuto;}//již se nevyužívá, ale nechávám pro pøípadné další použití

	for(int Y=0;Y<=bmp_out->Height-1;Y++)// pro všechny øadky
	{
		//naètení øádkù
		PRGBTriple RG = NULL;if(!bmp_grid->Empty) RG = (PRGBTriple)(bmp_grid->ScanLine[Y]);// vezmu ukazatel na sloupec y z bitmapy s GRIDem   //grid pokud existuje, je bmp_grid->Height>0
		PRGBTriple RD = (PRGBTriple)(bmp_out->ScanLine[Y]);// vezmu ukazatel na sloupec y z výsledné bitmapy
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
			//grid pokud existuje, je bmp_grid->Height>0
			if(!bmp_grid->Empty && RD[X].rgbtRed==255 && RD[X].rgbtGreen==255 && RD[X].rgbtBlue==255 && RG[X].rgbtRed==128 && RG[X].rgbtGreen==128 && RG[X].rgbtBlue==128)//pokud by se jednalo ve výsledné mapì o bílý pixel a zároveò je pøítomna teèka gridu, bacha grid musí mít šedou barvu
			{RD[X].rgbtRed=RG[X].rgbtRed;RD[X].rgbtGreen=RG[X].rgbtGreen;RD[X].rgbtBlue=RG[X].rgbtBlue;}
		}
	}
	return bmp_out;
}
