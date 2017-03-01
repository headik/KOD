unsigned short pocet_objektu_knihovny=12;
struct Tknihovna_objektu{unsigned int id; UnicodeString short_name; UnicodeString name;};
Tknihovna_objektu knihovna_objektu[12]=
{
	 {1 , "NAV", "navìšování"},
	 {2 , "CO2", "CO2"},
	 {3 , "ION", "ionizace"} ,
	 {4 , "LAK", "lakování"},
	 {5 , "VY", "vytìkání"},
	 {6 , "SUŠ", "sušení"},
	 {7 , "CHL", "chlazení"},
	 {8 , "BUF", "buffer"},
	 {9 , "VİT", "vıtah"},
	 {10, "PRE", "pøejezd"},
	 {11, "VYH", "vıhybka"},
	 {12, "...", "nedefinovanı"},
};