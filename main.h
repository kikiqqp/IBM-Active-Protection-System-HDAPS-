//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class THDAPS : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TBevel *Bevel1;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TBevel *Bevel4;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TButton *Button1;
        TButton *Button2;
        TImage *Image1;
        TLabel *Label19;
        TPopupMenu *PopupMenu1;
        TButton *Button3;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall THDAPS(TComponent* Owner);
        typedef struct _ACCELREPORT
        {
          int            PresentState;         // Current internal state (stable: 0, unstable1: 1: unstable2: 2)
          unsigned short LatestRawAccelDataX;  // latest raw acceleration data of X axis     <-- works!
          unsigned short LatestRawAccelDataY;  // latest raw acceleration data of Y axis     <-- works!
          unsigned short LatestAccelDataX;     // latest acceleration data of X axis (average in 40ms)    <-- Works even better?
          unsigned short LatestAccelDataY;     // latest acceleration data of Y axis (average in 40ms)    <-- Works even better?
          char           Temperature;          // latest temperature
          unsigned short LatestZeroG_X;        // latest zero-G offset of X axis   <-- Seems to be the current notion of "center"
          unsigned short LatestZeroG_Y;        // latest zero-G offset of Y axis   <-- ""
        }ACCELREPORT, *PACCELREPORT;
        typedef int HDAPS_API;
        typedef     HDAPS_API(__stdcall *ReadHDAPS)(PACCELREPORT pAcceleration);
        ReadHDAPS   HDAPS;
        HINSTANCE   hDLL;
        ACCELREPORT HDAPSData;
        int OffsetX;
        int OffsetY;
        bool LoadOK;
};
//---------------------------------------------------------------------------
extern PACKAGE THDAPS *HDAPS;
//---------------------------------------------------------------------------
#endif
