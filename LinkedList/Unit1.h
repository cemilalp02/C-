//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CreateLinkedList;
	TButton *AddToHead;
	TButton *AddToEnd;
	TPanel *PaintBox1;
	TEdit *EditValue;
	void __fastcall CreateLinkedListClick(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall AddToHeadClick(TObject *Sender);
	void __fastcall AddToEndClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
