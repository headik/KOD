//---------------------------------------------------------------------------

#ifndef MyMessageBoxH
#define MyMessageBoxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMyMessageBox : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button_Yes;
	TCheckBox *CheckBox_pamatovat;
	TButton *Button_No;
	TButton *Button_OK;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	UnicodeString DD;
	bool dd_on;
	void dynamicka_velikost_formulare();
public:		// User declarations
	__fastcall TMyMessageBox(TComponent* Owner);
	int ShowMyMessageBox(long Left,long Top,UnicodeString Caption_text, UnicodeString Label1_text);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyMessageBox *MyMessageBox;
//---------------------------------------------------------------------------
#endif
