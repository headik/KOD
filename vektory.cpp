//---------------------------------------------------------------------------
#pragma hdrstop
#include "vektory.h"
#include "unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
//konstruktor
Cvektory::Cvektory()
{
	hlavicka_prvky();//vytvoří novou hlavičku pro body
	hlavicka_voziky();
	hlavicka_palce();
}
//---------------------------------------------------------------------------
//vytvoří novou hlavičku pro body
void Cvektory::hlavicka_prvky()
{
	TObjekt *novy_uzel=new TObjekt;
	novy_uzel->n=0;
	novy_uzel->X=0;
	novy_uzel->Y=0;
	novy_uzel->TTo=0;
	novy_uzel->CT=0;//cycle time
	novy_uzel->stav=0;//0- stop, 2- vozik může jet
	novy_uzel->orientace_voziku=0;//0-na délku, 1- na šířku
	novy_uzel->vzdalenost=0;//mezera mezi vozíky
	novy_uzel->typ_dopravniku=0;
	novy_uzel->delka_dopravniku=0;
	novy_uzel->kapacita_objektu=0;
	novy_uzel->techn_parametry="";

	novy_uzel->predchozi=novy_uzel;//ukazuje sam na sebe
	novy_uzel->dalsi=NULL;
	OBJEKTY=novy_uzel;
	seznam_dopravniku=L"hlavní dopravník=5\nvedlejší dopravník=3\n";

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//uloží bod a jeho parametry do seznamu
short Cvektory::vloz_objekt(unsigned int id, double X, double Y)
{
	TObjekt *novy=new TObjekt;

	novy->n=OBJEKTY->predchozi->n+1;//navýším počítadlo prvku o jedničku
	novy->id=id;
	novy->short_name=knihovna_objektu[id].short_name;
	novy->name=knihovna_objektu[id].name;
	novy->rezim=0;if(id==4 || id==5 || id==6)novy->rezim=2;//rezim objektu 0-S&G,1-Kontin.(line tracking),2-Postprocesní
	novy->X=X;//přiřadím X osu,pozice objektu
	novy->Y=Y;//přiřadím Y osu,pozice objektu
	novy->TTo=0;//takt time objektu
	novy->CT=0;//cycle time
	novy->stav=0;//0- stop, 2- vozik může jet
	novy->orientace_voziku=0;//0-na délku, 1- na šířku
	novy->vzdalenost=0;//mezera mezi vozíky
	novy->typ_dopravniku=0;
	novy->delka_dopravniku=0;
	novy->kapacita_objektu=0;
	novy->techn_parametry="";

	OBJEKTY->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=OBJEKTY->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;
	OBJEKTY->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí

	return 0;
};
//---------------------------------------------------------------------------
//uloží bod a jeho parametry do seznamu                                   //p předchozí
short Cvektory::vloz_objekt(unsigned int id, double X, double Y,TObjekt *p)
{
	TObjekt *novy=new TObjekt;

	novy->id=id;
	novy->short_name=knihovna_objektu[id].short_name;
	novy->name=knihovna_objektu[id].name;
	novy->X=X;//přiřadím X osu
	novy->Y=Y;//přiřadím Y osu
	novy->TTo=0;
	novy->CT=0;//cycle time
	novy->stav=0;//0- stop, 2- vozik může jet
	novy->orientace_voziku=0;//0-na délku, 1- na šířku
	novy->vzdalenost=0;//mezera mezi vozíky
	novy->typ_dopravniku=0;
	novy->delka_dopravniku=0;
	novy->kapacita_objektu=0;
	novy->techn_parametry="";

	novy->predchozi=p;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=p->dalsi;
	p->dalsi->predchozi=novy;
	p->dalsi=novy;
	novy->n=p->n;//přiřadím počítadlo prvku ze současného prvku, v dalším kroku se totiž navýší

	//indexy zvýšit separátně
	return 0;
};
//---------------------------------------------------------------------------
//uloží bod a jeho parametry do seznamu - přetížená fce
short Cvektory::vloz_objekt(TObjekt *Objekt)
{
	TObjekt *novy=new TObjekt;

	novy=Objekt;//novy bude ukazovat tam kam prvek data
	novy->n=OBJEKTY->predchozi->n+1;//navýším počítadlo prvku o jedničku
	OBJEKTY->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=OBJEKTY->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;//poslední prvek se na zadny dalsí prvek neodkazuje (neexistuje
	OBJEKTY->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí

	return 0;
};
//---------------------------------------------------------------------------
//hledá bod v dané oblasti                                       //pracuje v logic souradnicich tzn. již nepouživat *Zoom  použít pouze m2px
Cvektory::TObjekt *Cvektory::najdi_bod(double X, double Y,double offsetX, double offsetY)
{
	Cvektory::TObjekt *ret=NULL;
	Cvektory::TObjekt *p=OBJEKTY->dalsi;//přeskočí hlavičku
	while (p!=NULL)
	{
		if(p->X<=X && X<=p->X+offsetX*Form1->m2px &&  p->Y>=Y && Y>=p->Y-offsetY*Form1->m2px)ret=p;//nalezeno !
		p=p->dalsi;//posun na další prvek
	}
	return ret;
}
//---------------------------------------------------------------------------
//smaze bod ze seznamu
short int Cvektory::smaz_bod(TObjekt *Objekt)
{
	//vyřazení prvku ze seznamu a napojení prvku dalšího na prvek předchozí prku mazaného
	if(Objekt->dalsi!=NULL)//ošetření proti poslednímu prvku
	{
		Objekt->predchozi->dalsi=Objekt->dalsi;
		Objekt->dalsi->predchozi=Objekt->predchozi;
  }
  else//poslední prvek
  {
		if(Objekt->n==1)//pokud je mazaný prvek hned za hlavičkou
    {
			OBJEKTY->predchozi=Objekt->predchozi; //popř hlavička bude ukazovat sama na sebe
			OBJEKTY->dalsi=NULL;
    }
    else
    {
			Objekt->predchozi->dalsi=NULL;
			OBJEKTY->predchozi=Objekt->predchozi;//zapis do hlavičky poslední prvek seznamu
    }
  }

  Objekt=NULL;delete Objekt;//smaže mazaný prvek

  return 0;

};
void Cvektory::sniz_indexy(TObjekt *Objekt)
{
	while (Objekt!=NULL)
	{
		Objekt=Objekt->dalsi;//posun na další prvek
		if(Objekt!=NULL)Objekt->n--;//sníží indexy nasledujicích bodů,protože optimalizace seznamu nefungovalo, navíc ušetřím strojový čas
	}
}
//---------------------------------------------------------------------------
void Cvektory::zvys_indexy(TObjekt *Objekt)//zvýší indexy NÁSLEDUJICÍCH bodů
{
	while (Objekt!=NULL)
	{
		Objekt=Objekt->dalsi;//posun na další prvek
		if(Objekt!=NULL)Objekt->n++;//sníží indexy nasledujicích bodů,protože optimalizace seznamu nefungovalo, navíc ušetřím strojový čas
	}
}
//---------------------------------------------------------------------------
double Cvektory::delka_dopravniku(Cvektory::TObjekt *ukaz)
{
		Cvektory::TObjekt *ukaz_prvni=ukaz;
		double delka=0;
		ukaz=ukaz->dalsi;//ukazatel na první objekt v seznamu OBJEKTU, přeskočí hlavičku
		while (ukaz!=NULL)
		{
			if(ukaz->dalsi!=NULL)//mimo poslední linie
				delka+=Form1->m.delka(ukaz->X,ukaz->Y,ukaz->dalsi->X,ukaz->dalsi->Y);
			else//pro poslední linii
				delka+=Form1->m.delka(ukaz->X,ukaz->Y,ukaz_prvni->X,ukaz_prvni->Y);
			//posun na další prvek v seznamu
			ukaz=ukaz->dalsi;
		}
		return delka;
}
//---------------------------------------------------------------------------
void Cvektory::aktualizace_indexu_uzitych_dopravniku(short item_index)
{
	Cvektory::TObjekt *ukaz;
	ukaz=OBJEKTY->dalsi;//přeskočí hlavičku

	while (ukaz!=NULL)
	{
			if(ukaz->typ_dopravniku>item_index)
			{
					ukaz->typ_dopravniku--;
			}
			ukaz=ukaz->dalsi;//posun na další prvek
	}
}
//---------------------------------------------------------------------------
bool Cvektory::kontrola_existence_dopravniku(short item_index)
{
	bool RET=false;
	Cvektory::TObjekt *ukaz;
	ukaz=OBJEKTY->dalsi;//přeskočí hlavičku

	while (ukaz!=NULL)
	{
			if(ukaz->typ_dopravniku==item_index)
			{
					RET=true;break;
			}
			ukaz=ukaz->dalsi;//posun na další prvek
	}
	return RET;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//smaze body z pameti
long Cvektory::vymaz_seznam()
{
	long pocet_smazanych_objektu=0;
	while (OBJEKTY!=NULL)
	{
		pocet_smazanych_objektu++;
		OBJEKTY->predchozi=NULL;
		delete OBJEKTY->predchozi;
    OBJEKTY=OBJEKTY->dalsi;
  };

	return pocet_smazanych_objektu;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//PRÁCE ZE SOUBORY
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Uloží vektorová data do souboru
short int Cvektory::uloz_do_souboru(UnicodeString FileName)
{
     TFileStream *FileStream=new TFileStream(FileName,fmOpenWrite|fmCreate);
		 //optimalizace_seznamu();

		 //zapiše hlavičku do souboru
		 File_hlavicka.pocet_objektu=OBJEKTY->predchozi->n;
		 File_hlavicka.pocet_voziku=VOZIKY->predchozi->n;
		 File_hlavicka.delka_textu_prepravniky=seznam_dopravniku.Length()+1;
		 FileStream->Write(&File_hlavicka,sizeof(TFile_hlavicka));

		 //uloží seznam dopravníků
		 wchar_t *DOP=new wchar_t[seznam_dopravniku.Length()+1];
		 DOP=seznam_dopravniku.c_str();
		 FileStream->Write(DOP,(seznam_dopravniku.Length()+1)*sizeof(wchar_t));//zapiše druhý řetězec za prvek bod
		 DOP=NULL; delete[] DOP;

		 //uložení seznamu technologických objektů
		 TObjekt *ukaz=OBJEKTY->dalsi;
		 while (ukaz!=NULL)
		 {
			 ////překopírování dat do pomocného objektu uložitelného do bináru
			 C_uzel *c_ukaz=new C_uzel;

			 if(ukaz->n>0 && File_hlavicka.pocet_objektu>=ukaz->n)//mimo hlavičky či shitu
			 {
					//samotná data
					c_ukaz->n=ukaz->n;
					c_ukaz->id=ukaz->id;
					c_ukaz->X=ukaz->X;
					c_ukaz->Y=ukaz->Y;
					c_ukaz->rezim=ukaz->rezim;
					c_ukaz->TTo=ukaz->TTo;
					c_ukaz->CT=ukaz->CT;
					c_ukaz->orientace_voziku=ukaz->orientace_voziku;
					c_ukaz->vzdalenost=ukaz->vzdalenost;
					c_ukaz->typ_dopravniku=ukaz->typ_dopravniku;
					c_ukaz->delka_dopravniku=ukaz->delka_dopravniku;
					c_ukaz->kapacita_objektu=ukaz->kapacita_objektu;
					c_ukaz->text_length=ukaz->name.Length()+1;
					c_ukaz->paremetry_text_length=ukaz->techn_parametry.Length()+1;
					FileStream->Write(c_ukaz,sizeof(C_uzel));//zapiše jeden prvek do souboru
					//text - short name
					wchar_t *short_name=new wchar_t[4];//max 3 znaky
					short_name=ukaz->short_name.c_str();
					FileStream->Write(short_name,4*sizeof(wchar_t));//zapiše jeden řetězec za prvek bod
					short_name=NULL; delete[] short_name;
					//text - name
					wchar_t *name=new wchar_t [c_ukaz->text_length];
					name=ukaz->name.c_str();
					FileStream->Write(name,c_ukaz->text_length*sizeof(wchar_t));//zapiše druhý řetězec za prvek bod
					name=NULL; delete[] name;
					//text - parametry
					wchar_t *parametry=new wchar_t [c_ukaz->paremetry_text_length];
					parametry=ukaz->techn_parametry.c_str();
					FileStream->Write(parametry,c_ukaz->paremetry_text_length*sizeof(wchar_t));//zapiše třetí řetězec za prvek bod
					parametry=NULL; delete[] parametry;
			 }
			 c_ukaz=NULL;delete c_ukaz;
			 ukaz=ukaz->dalsi;//posunutí na další pozici v seznamu
		 };
		 ukaz=NULL;delete ukaz;

		 //uložení vozíků
		 TVozik *ukaz1=VOZIKY->dalsi;

		 while (ukaz1!=NULL)
		 {
			 ////překopírování dat do pomocného objektu uložitelného do bináru
			 C_vozik *c_ukaz1=new C_vozik;

			 //samotná data
			 c_ukaz1->n=ukaz1->n;
			 c_ukaz1->id_length=ukaz1->id.Length()+1;
			 c_ukaz1->delka=ukaz1->delka;
			 c_ukaz1->sirka=ukaz1->sirka;
			 c_ukaz1->vyska=ukaz1->vyska;
			 c_ukaz1->rotace=ukaz1->rotace;
			 c_ukaz1->max_vyrobku=ukaz1->max_vyrobku;
			 c_ukaz1->akt_vyrobku=ukaz1->akt_vyrobku;
			 c_ukaz1->delka_vcetne_vyrobku=ukaz1->delka_vcetne_vyrobku;
			 c_ukaz1->sirka_vcetne_vyrobku=ukaz1->sirka_vcetne_vyrobku;
			 c_ukaz1->vyska_vcetne_vyrobku=ukaz1->vyska_vcetne_vyrobku;
			 c_ukaz1->stav=ukaz1->stav;
			 c_ukaz1->barva=ukaz1->barva;
			 c_ukaz1->text_length=ukaz1->nazev_vyrobku.Length()+1;
			 FileStream->Write(c_ukaz1,sizeof(C_vozik));//zapiše jeden prvek do souboru
			 //text - ID
			 wchar_t *id=new wchar_t [c_ukaz1->id_length];
			 id=ukaz1->id.c_str();
			 FileStream->Write(id,c_ukaz1->id_length*sizeof(wchar_t));//zapiše druhý řetězec za prvek bod
			 id=NULL; delete[] id;
			 //text - name
			 wchar_t *name=new wchar_t [c_ukaz1->text_length];
			 name=ukaz1->nazev_vyrobku.c_str();
			 FileStream->Write(name,c_ukaz1->text_length*sizeof(wchar_t));//zapiše druhý řetězec za prvek bod
			 name=NULL; delete[] name;

			 c_ukaz1=NULL;delete c_ukaz1;
			 ukaz1=ukaz1->dalsi;//posunutí na další pozici v seznamu
		 };
		 ukaz1=NULL;delete ukaz1;

		 delete FileStream;
		 return 1;
}
//---------------------------------------------------------------------------
//načte vektorová data ze souboru
short int Cvektory::nacti_ze_souboru(UnicodeString FileName)
{
	if(!FileExists(FileName))return 0;
	else
	{
			try
			{
			TFileStream *FileStream=new TFileStream(FileName,fmOpenRead);

			//zapiše hlavičku do souboru
			FileStream->Read(&File_hlavicka,sizeof(TFile_hlavicka));//načte hlavičku ze souboru

			//vytvoří nové hlavičky pro spojové seznamy
			hlavicka_prvky();
			hlavicka_voziky();

			//načte seznam dopravníků
			wchar_t *DOP=new wchar_t[File_hlavicka.delka_textu_prepravniky];
			FileStream->Read(DOP,File_hlavicka.delka_textu_prepravniky*sizeof(wchar_t));//načte jeden nazev fontu za prvekem bod a popisek bodu
			seznam_dopravniku=DOP;
			DOP=NULL; delete[] DOP;

			//bohužel nutno takto rozepisovat, problem s AnsiStringem, ukazoval jen na misto do paměti neukladali se data, proto konverze z jedne struktury na druhou a z toho pramenící dlouhý zápis
			//technologické objekty
			for(unsigned int i=1;i<=File_hlavicka.pocet_objektu;i++)//možno řešit sice while, po strukturách, ale toto je připravené pro případ, kdy budu načítat i objekty jiného typu než objekt
			{
				TObjekt *ukaz=new TObjekt;
				C_uzel *c_ukaz=new C_uzel;
				FileStream->Read(c_ukaz,sizeof(C_uzel));//načte jeden prvek ze souboru

				if(c_ukaz->n!=0 && File_hlavicka.pocet_objektu>=c_ukaz->n)//pokud nenačte hlavičku či nějaký shit
				{
						//ShowMessage(c_ukaz->n);
						//samotná data
						ukaz->n=c_ukaz->n;
						ukaz->id=c_ukaz->id;
						ukaz->X=c_ukaz->X;
						ukaz->Y=c_ukaz->Y;
						ukaz->rezim=c_ukaz->rezim;
						ukaz->TTo=c_ukaz->TTo;
						ukaz->CT=c_ukaz->CT;
						ukaz->orientace_voziku=c_ukaz->orientace_voziku;
						ukaz->vzdalenost=c_ukaz->vzdalenost;
						ukaz->typ_dopravniku=c_ukaz->typ_dopravniku;
						ukaz->delka_dopravniku=c_ukaz->delka_dopravniku;
						ukaz->kapacita_objektu=c_ukaz->kapacita_objektu;

						//zkratku
						wchar_t *short_name=new wchar_t [4];
						FileStream->Read(short_name,4*sizeof(wchar_t));//načte popisek umístěný za strukturou bod
						ukaz->short_name=short_name;
						short_name=NULL; delete[] short_name;
						//popisek
						wchar_t *name=new wchar_t[c_ukaz->text_length];
						FileStream->Read(name,c_ukaz->text_length*sizeof(wchar_t));//načte jeden nazev fontu za prvekem bod a popisek bodu
						ukaz->name=name;
						name=NULL; delete[] name;

						//data pro Valuelisteditor, paremetry
						wchar_t *parametry=new wchar_t[c_ukaz->paremetry_text_length];
						FileStream->Read(parametry,c_ukaz->paremetry_text_length*sizeof(wchar_t));//načte jeden nazev fontu za prvekem bod a popisek bodu
						ukaz->techn_parametry=parametry;
						parametry=NULL; delete[] parametry;

						//vloží prvek do spojového seznamu
						vloz_objekt(ukaz);
				}
				ukaz=NULL; delete ukaz;
				c_ukaz=NULL; delete c_ukaz;
			};


			for(unsigned int i=1;i<=File_hlavicka.pocet_voziku;i++)//možno řešit sice while, po strukturách, ale toto je připravené pro případ, kdy budu načítat i objekty jiného typu než objekt
			{
				TVozik *ukaz1=new TVozik;
				C_vozik *c_ukaz1=new C_vozik;
				FileStream->Read(c_ukaz1,sizeof(C_vozik));//načte jeden prvek ze souboru
				if(c_ukaz1->n!=0 && File_hlavicka.pocet_voziku>=c_ukaz1->n)//pokud nenačte hlavičku či nějaký shit
				{
						//samotná data
					ukaz1->n=c_ukaz1->n;
					ukaz1->delka=c_ukaz1->delka;
					ukaz1->sirka=c_ukaz1->sirka;
					ukaz1->vyska=c_ukaz1->vyska;
					ukaz1->rotace=c_ukaz1->rotace;
					ukaz1->max_vyrobku=c_ukaz1->max_vyrobku;
					ukaz1->akt_vyrobku=c_ukaz1->akt_vyrobku;
					ukaz1->delka_vcetne_vyrobku=c_ukaz1->delka_vcetne_vyrobku;
					ukaz1->sirka_vcetne_vyrobku=c_ukaz1->sirka_vcetne_vyrobku;
					ukaz1->vyska_vcetne_vyrobku=c_ukaz1->vyska_vcetne_vyrobku;
					ukaz1->stav=c_ukaz1->stav;
					ukaz1->barva=c_ukaz1->barva;


					//id
					wchar_t *id=new wchar_t[c_ukaz1->id_length];
					FileStream->Read(id,c_ukaz1->id_length*sizeof(wchar_t));//načte jeden nazev fontu za prvekem bod a popisek bodu
					ukaz1->id=id;
					id=NULL; delete[] id;

					//popisek
					wchar_t *name=new wchar_t[c_ukaz1->text_length];
					FileStream->Read(name,c_ukaz1->text_length*sizeof(wchar_t));//načte jeden nazev fontu za prvekem bod a popisek bodu
					ukaz1->nazev_vyrobku=name;
					name=NULL; delete[] name;

					//vloží finální prvek do spojového seznamu
					vloz_vozik(ukaz1);
				}
				ukaz1=NULL; delete ukaz1;
				c_ukaz1=NULL; delete c_ukaz1;
			};

			delete FileStream;
			return 1;
			}
			catch(...){return 2;}//jiná chyba, např. špatný formát souboru
	}
}
//---------------------------------------------------------------------------
short int Cvektory::ulozit_report(UnicodeString FileName)
{
		get_LT_a_max_min_TT();//zajistí hodnoty

		AnsiString data="";//celková textová data k exportu

		//zjištění exportovaného formátu
		unsigned short export_format=1;
		if(FileName.SubString(FileName.Length()-2,3).LowerCase() =="xls")export_format=2;
		if(FileName.SubString(FileName.Length()-3,4).LowerCase() =="html")export_format=3;

		//formátování textu do jednotlivých formátů
		UnicodeString S=";";//SEPARATOR pro CSV
		switch(export_format)//1-csv, 2 - xls,3 - html
		{
			case 1:data=get_csv_xls(";");break;//CSV
			case 2:data=get_csv_xls("\t");break;//XLS
			case 3:data=get_html();break;//html
		}

		//poznámka, provizorní záležitost - potom smazat
		if(export_format==3)data+="<font color=\"Red\">";
		data+="\n*pozn.:další paramatry objektů budou doplněny, jedná se provizorní podobu výstupu ...";

		///////////////////////////zapis data do souboru
		TMemoryStream* MemoryStream=new TMemoryStream();
		MemoryStream->Clear();
		MemoryStream->Write(data.c_str(),data.Length());//Win kodování
		MemoryStream->SaveToFile(FileName);
		delete MemoryStream;
		return 1;
}
//---------------------------------------------------------------------------
AnsiString Cvektory::get_csv_xls(AnsiString S)//S=separator
{
	AnsiString data="";

	//tabulka parametry linky
	data+="Předpokládáný celkový výrobní čas [hodin]:"+S+UnicodeString(Form1->PP.hodin*Form1->PP.smen*Form1->PP.dni)+"\n";
	data+="TAKT TIME linky [min/vozík]"+S+UnicodeString(Form1->PP.TT)+"\n";
	data+="Propustnost linky [vozíků/min]"+S+UnicodeString(1/Form1->PP.TT)+"\n";
	data+="LEAD TIME linky [vozíků/min]"+S+UnicodeString(LT)+"\n";
	data+="WIP [vozíků]"+S+UnicodeString((1/Form1->PP.TT)*LT)+"\n";
	data+="PCE [%]"+S+UnicodeString(sum_WT()/LT*100)+"\n";//zokrouhleno na dvě desetinná místa
	data+="Produktů na vozík [ks]:"+S+UnicodeString(Form1->PP.produktu_vozik)+"\n";
	data+="Délka vozíku [m]:"+S+UnicodeString(Form1->PP.delka_voziku)+"\n";
	data+="Šířka vozíku [m]:"+S+UnicodeString(Form1->PP.sirka_voziku)+"\n";
	data+="\n";//mezera,odřádkování

	//hlavička dat objektů
	data+="id"+S+"typ"+S+"zkratka"+S+"název"+S+"souřadnice X"+S+"souřadnice Y"+S+"režim"+S+"takt time objektu"+S+"cykle time objektu\n";

	Cvektory::TObjekt *ukaz;
	ukaz=OBJEKTY->dalsi;//přeskočí hlavičku
	while (ukaz!=NULL)
	{
		data+=UnicodeString(ukaz->n)+S+UnicodeString(ukaz->id)+S+UnicodeString(ukaz->short_name)+S+UnicodeString(ukaz->name)+S+UnicodeString(ukaz->X)+S+UnicodeString(ukaz->Y)+S;
		switch(ukaz->rezim)
		{
			case 0:data+="STOP & GO"+S;break;
			case 1:data+="KONTINUÁLNÍ"+S;break;
			case 2:data+="POSTPROCESNÍ"+S;break;
		}
		data+=UnicodeString(ukaz->TTo)+S+UnicodeString(ukaz->CT)+S+UnicodeString(ukaz->kapacita_objektu);
		data+="\n";//odřádkování
		ukaz=ukaz->dalsi;//posun na další prvek
	}
	return data;
}
//---------------------------------------------------------------------------
AnsiString Cvektory::get_html()
{
		AnsiString data="";
		data="<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"content-type\" content=\"text/html; charset=windows-1250\"><meta name=\"tispl\" content=\"TISPL - Eltep s.r.o\"><title>REPORT z programu TISPL - Eltep</title></head><body>";//hlavička
		data+="<style>th{color:white;font-family:Arial;background-color:gray;}td{text-align:center;color:gray;font-family:Arial;}table {border-collapse:collapse;border-color:gray;}</style>";
    //tabulka parametry linky
		data+="<table border=\"1\">";//tělo začátek tabulky parametry projektu
		data+="<tr><th align=\"right\">Předpokládáný celkový výrobní čas [hodin]</th><td>"+UnicodeString(Form1->PP.hodin*Form1->PP.smen*Form1->PP.dni)+"</td></tr>";
		data+="<tr><th align=\"right\">TAKT TIME linky [min/vozík]</th><td>"+UnicodeString(Form1->PP.TT)+"</td></tr>";
		data+="<tr><th align=\"right\">Propustnost linky [vozíků/min]</th><td>"+UnicodeString(1/Form1->PP.TT)+"</td></tr>";
		data+="<tr><th align=\"right\">LEAD TIME linky [vozíků/min]</th><td>"+UnicodeString(LT)+"</td></tr>";
		data+="<tr><th align=\"right\">WIP [vozíků]</th><td>"+UnicodeString((1/Form1->PP.TT)*LT)+"</td></tr>";
		data+="<tr><th align=\"right\">PCE [%]</th><td>"+UnicodeString(sum_WT()/LT*100)+"</td></tr>";//zokrouhleno na dvě desetinná místa
		data+="<tr><th align=\"right\">Produktů na vozík [ks]</th><td>"+UnicodeString(Form1->PP.produktu_vozik)+"</td></tr>";
		data+="<tr><th align=\"right\">Délka vozíku [m]</th><td>"+UnicodeString(Form1->PP.delka_voziku)+"</td></tr>";
		data+="<tr><th align=\"right\">Šířka vozíku [m]</th><td>"+UnicodeString(Form1->PP.sirka_voziku)+"</td></tr>";
		data+="</table>";//tělo konec tabulky parametry projektu
		data+="<hr>";
		//tělo začátek tabulky data
		data+="<table border=\"1\" width=\"100%\">";
		data+="<tr><th>id</th><th>typ</th><th>zkratka</th><th>název</th><th>souřadnice X</th><th>souřadnice Y</th><th>režim</th><th>takt time objektu</th><th>cykle time objektu</th><th>kapacita objektu</th></tr>";//tělo hlavička tabulky
		//samotná data
	 	Cvektory::TObjekt *ukaz;
	 	ukaz=OBJEKTY->dalsi;//přeskočí hlavičku
	 	while (ukaz!=NULL)
	 	{
			data+="<tr><td>"+UnicodeString(ukaz->n)+"</td><td>"+UnicodeString(ukaz->id)+"</td><td>"+UnicodeString(ukaz->short_name)+"</td><td>"+UnicodeString(ukaz->name)+"</td><td>"+UnicodeString(ukaz->X)+"</td><td>"+UnicodeString(ukaz->Y)+"</td><td>";
	 		switch(ukaz->rezim)
	 		{
	 			case 0:data+="STOP & GO";break;
	 			case 1:data+="KONTINUÁLNÍ";break;
				case 2:data+="POSTPROCESNÍ";break;
			}
			data+="</td><td>"+UnicodeString(ukaz->TTo)+"</td><td>"+UnicodeString(ukaz->CT)+"</td><td>"+UnicodeString(ukaz->kapacita_objektu)+"</td></tr>";//tělo hlavička tabulky
			ukaz=ukaz->dalsi;//posun na další prvek
	 	}
		data+="</table>";//tělo konec tabulky
		data+="</body></html>";//patička
		return data;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Cvektory::get_LT_a_max_min_TT()
{
		LT=0.0;
		MAX_TT=-100.0;
		MIN_TT=+1000.0;
		Cvektory::TObjekt *ukaz;
		ukaz=OBJEKTY->dalsi;//přeskočí hlavičku
		while (ukaz!=NULL)
		{
			LT+=ukaz->CT;
			if(MAX_TT<ukaz->TTo)MAX_TT=ukaz->TTo;
			if(MIN_TT>ukaz->TTo)MIN_TT=ukaz->TTo;
			ukaz=ukaz->dalsi;//posun na další prvek
		}
}
//---------------------------------------------------------------------------
double Cvektory::sum_WT()
{
	 double SUM=0;
	 Cvektory::TObjekt *ukaz;
	 ukaz=OBJEKTY->dalsi;//přeskočí hlavičku
	 while (ukaz!=NULL)
	 {
			switch(ukaz->rezim)
			{
					case 0:SUM+=ukaz->CT-Form1->ms.MyToDouble(Form1->ms.EP(Form1->ms.EP(ukaz->techn_parametry,"PT","\n")+"|","=",+"|"));break;//S&G
					case 1:SUM+=0;break;//Kontinual - je efektivní bez prostojů prostě kontinuální
					case 2:SUM+=ukaz->CT;break;//PP - je jeden velký prostoj
      }
			ukaz=ukaz->dalsi;//posun na další prvek
	 }
	 return SUM;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Cvektory::hlavicka_voziky()
{
	TVozik *novy_uzel=new TVozik;
	novy_uzel->n=0;
	novy_uzel->id=0;
	novy_uzel->delka=0;
	novy_uzel->sirka=0;
	novy_uzel->vyska=0;
	novy_uzel->rotace=0;
	novy_uzel->nazev_vyrobku="hlavicka";
	novy_uzel->max_vyrobku=0;
	novy_uzel->akt_vyrobku=0;
	novy_uzel->delka_vcetne_vyrobku=0;
	novy_uzel->sirka_vcetne_vyrobku=0;
	novy_uzel->vyska_vcetne_vyrobku=0;
	novy_uzel->stav=-1;
	novy_uzel->pozice=0;
	novy_uzel->segment=NULL;
	novy_uzel->X=0;novy_uzel->Y=0;

	novy_uzel->predchozi=novy_uzel;//ukazuje sam na sebe
	novy_uzel->dalsi=NULL;
	VOZIKY=novy_uzel;
}
//---------------------------------------------------------------------------
void Cvektory::vloz_vozik()//přidá nový vozík do seznamu VOZIKY
{
	TVozik *novy=new TVozik;

	novy->n=VOZIKY->predchozi->n+1;//navýším počítadlo prvku o jedničku
	novy->segment=NULL;novy->pozice=-1;novy->stav=-1;
	novy->X=0;novy->Y=0;

	VOZIKY->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=VOZIKY->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;
	VOZIKY->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí
}
//---------------------------------------------------------------------------
//uloží ukazatel na vozík do spojového seznamu voziku přetížená fce
void Cvektory::vloz_vozik(TVozik *Vozik)
{
	TVozik *novy=new TVozik;
	novy=Vozik;//novy bude ukazovat tam kam prvek data

	//pozor v případě načítání existujícího stavu ze souboru změnitm toto je výchozí pozice na lince
	novy->segment=NULL;novy->pozice=-1;novy->stav=-1;
	novy->X=0;novy->Y=0;

	novy->n=VOZIKY->predchozi->n+1;//navýším počítadlo prvku o jedničku
	VOZIKY->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=VOZIKY->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;//poslední prvek se na zadny dalsí prvek neodkazuje (neexistuje
	VOZIKY->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí
};
//---------------------------------------------------------------------------
void Cvektory::vloz_vozik(unsigned long n,UnicodeString id,double delka,double sirka,double vyska,double rotace,UnicodeString nazev_vyrobku,double max_vyrobku,double akt_vyrobku,double delka_vcetne_vyrobku,double sirka_vcetne_vyrobku,double vyska_vcetne_vyrobku,TColor barva)
{
 	TVozik *novy=new TVozik;

	novy->n=n;//navýším počítadlo prvku o jedničku
	novy->id=id;
	novy->delka=delka;
	novy->sirka=sirka;
	novy->vyska=vyska;
	novy->rotace=rotace;
	novy->nazev_vyrobku=nazev_vyrobku;
	novy->max_vyrobku=max_vyrobku;
	novy->akt_vyrobku=akt_vyrobku;
	novy->delka_vcetne_vyrobku=delka_vcetne_vyrobku;
	novy->sirka_vcetne_vyrobku=sirka_vcetne_vyrobku;
	novy->vyska_vcetne_vyrobku=vyska_vcetne_vyrobku;
	novy->barva=barva;
	novy->segment=NULL;novy->pozice=-1;novy->stav=-1;
	novy->X=0;novy->Y=0;

	VOZIKY->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=VOZIKY->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;
	VOZIKY->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí

}
//---------------------------------------------------------------------------
long Cvektory::vymaz_seznam_voziku()
{
	long pocet_smazanych_objektu=0;
	while (VOZIKY!=NULL)
	{
		pocet_smazanych_objektu++;
		VOZIKY->predchozi=NULL;
		delete VOZIKY->predchozi;
		VOZIKY=VOZIKY->dalsi;
	};

	return pocet_smazanych_objektu;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Cvektory::hlavicka_palce()
{
	TPalec *novy_uzel=new TPalec;
	novy_uzel->n=0;
	novy_uzel->pozice=0;
	novy_uzel->segment=NULL;

	novy_uzel->predchozi=novy_uzel;//ukazuje sam na sebe
	novy_uzel->dalsi=NULL;
	PALCE=novy_uzel;
}
//---------------------------------------------------------------------------
void Cvektory::vloz_palec()//přidá nový vozík do seznamu PALCE
{
	TPalec *novy=new TPalec;

	novy->n=PALCE->predchozi->n+1;//navýším počítadlo prvku o jedničku

	PALCE->predchozi->dalsi=novy;//poslednímu prvku přiřadím ukazatel na nový prvek
	novy->predchozi=PALCE->predchozi;//novy prvek se odkazuje na prvek predchozí (v hlavicce body byl ulozen na pozici predchozi, poslední prvek)
	novy->dalsi=NULL;
	PALCE->predchozi=novy;//nový poslední prvek zápis do hlavičky,body->predchozi zápis do hlavičky odkaz na poslední prvek seznamu "predchozi" v tomto případě zavádějicí
}
//---------------------------------------------------------------------------
long Cvektory::vymaz_seznam_palcu()
{
	long pocet_smazanych_objektu=0;
	while (PALCE!=NULL)
	{
		pocet_smazanych_objektu++;
		PALCE->predchozi=NULL;
		delete PALCE->predchozi;
		PALCE=PALCE->dalsi;
	};

	return pocet_smazanych_objektu;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

