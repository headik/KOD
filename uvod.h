//---------------------------------------------------------------------------

#ifndef uvodH
#define uvodH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm_uvod : public TForm
{
__published:	// IDE-managed Components
  TTimer *Timer1;
  TLabel *Label2;
  TLabel *Label3;
	TImage *Image1;
	TImage *Image2;
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_uvod(TComponent* Owner);
protected:
void __fastcall CreateParams(TCreateParams &Params);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_uvod *Form_uvod;
//---------------------------------------------------------------------------
#endif
