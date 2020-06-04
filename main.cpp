//---------------------------------------------------------------------------
// Hao.Y Wei (ÃQ»¨«Û) <kikiqqp@gmail.com>
#include <vcl.h>
#include <math.h>
#pragma hdrstop
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THDAPS *HDAPS;
//---------------------------------------------------------------------------
__fastcall THDAPS::THDAPS(TComponent* Owner)
        : TForm(Owner)
{
  try
  {
    /*Get DLL*/
    hDLL = LoadLibrary("Sensor.dll");
    if(hDLL != NULL)
    {
      HDAPS = (ReadHDAPS)GetProcAddress(hDLL, "ShockproofGetAccelerometerData");
    }
  }
  catch(...)
  {}
  /*Get first data*/
  if(HDAPS(&HDAPSData))
  {
    LoadOK  = true;
    OffsetX = 0;
    OffsetY = 0;
    OffsetX = -(HDAPSData.LatestZeroG_X + 1);
    OffsetY = -(HDAPSData.LatestZeroG_Y + 1);

  }
  DoubleBuffered = true;
  Label1->Caption = Label2->Caption;
}
//---------------------------------------------------------------------------
void __fastcall THDAPS::FormClose(TObject *Sender, TCloseAction &Action)
{
/*Free DLL*/
  if(LoadOK)
    FreeLibrary(hDLL);
}
//---------------------------------------------------------------------------

void __fastcall THDAPS::Timer1Timer(TObject *Sender)
{
  if(LoadOK)
  {
  /*Start*/
    HDAPS(&HDAPSData);

  /*0 - 4: running, 8-9: stopped, 13: auto-ignore
    http://www-03.ibm.com/developerworks/blogs/page/johnston?entry=python_and_thinkpad  */
    AnsiString HDStatus;
    if(HDAPSData.PresentState >= 0 &&HDAPSData.PresentState <= 4)
    {
      Label4->Color = clLime;
      Label4->Caption = "Running";
    }
    else if(HDAPSData.PresentState == 8 || HDAPSData.PresentState == 9)
    {
      Label4->Color = clRed;
      Label4->Caption = "Stopped";
    }
    else if(HDAPSData.PresentState == 13)
    {
      Label4->Color = clYellow;
      Label4->Caption = "Auto-ignore";
    }
    Label5->Caption  = "Present State :" + AnsiString(HDAPSData.PresentState);

    Label7->Caption  = "Latest Raw Accel Data X :" + AnsiString(HDAPSData.LatestRawAccelDataX);
    Label8->Caption  = "Latest Raw Accel Data Y :" + AnsiString(HDAPSData.LatestRawAccelDataY);
    Label9->Caption  = "Latest Accel Data X :" + AnsiString(HDAPSData.LatestAccelDataX);
    Label10->Caption = "Latest Accel Data Y :" + AnsiString(HDAPSData.LatestAccelDataY);

    if((int)HDAPSData.Temperature <= 39)
      Label12->Color = clLime;
    else if((int)HDAPSData.Temperature >= 40 && (int)HDAPSData.Temperature <=69)
      Label12->Color = clYellow;
    else
      Label12->Color = clRed;
    Label12->Caption = IntToStr(HDAPSData.Temperature)+"'C ("+FloatToStr((float)HDAPSData.Temperature*(9.0/5.0)+32.0)+"'F)";

    Label14->Caption = "Latest ZeroG X :"+AnsiString(HDAPSData.LatestZeroG_X);
    Label15->Caption = "Latest ZeroG Y :"+AnsiString(HDAPSData.LatestZeroG_Y);

    Label17->Caption = "X :"+IntToStr((-(HDAPSData.LatestRawAccelDataX + OffsetX)) / 2)+"'";
    Label18->Caption = "Y :"+IntToStr((-(HDAPSData.LatestRawAccelDataY + OffsetY)) / 2)+"'";

    double StandAngleX,StandAngleY;
    StandAngleX = -((HDAPSData.LatestRawAccelDataX + OffsetX) / 2 + 90) * M_PI/180.0;

    Image1->Picture = NULL;
    Image1->Canvas->Pen->Width = 2;
    Image1->Canvas->Pen->Color = clBlue;
    Image1->Canvas->MoveTo(120 + (int)(60 * sin(StandAngleX)),
                            50 - (int)(60 * cos(StandAngleX)));
    Image1->Canvas->LineTo(120 - (int)(60 * sin(StandAngleX)),
                            50 + (int)(60 * cos(StandAngleX)));

    StandAngleY = -((HDAPSData.LatestRawAccelDataY + OffsetY) / 2 + 90) * M_PI/180.0;
    Image1->Canvas->Pen->Color = clFuchsia;
    Image1->Canvas->MoveTo(120 + (int)(60 * sin(StandAngleY)),
                           120 - (int)(60 * cos(StandAngleY)));
    Image1->Canvas->LineTo(120 - (int)(60 * sin(StandAngleY)),
                           120 + (int)(60 * cos(StandAngleY)));
  }
}
//---------------------------------------------------------------------------
void __fastcall THDAPS::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall THDAPS::Button2Click(TObject *Sender)
{
  if(LoadOK)
  {
    HDAPS(&HDAPSData);
    OffsetX = -(HDAPSData.LatestZeroG_X + 1);
    OffsetY = -(HDAPSData.LatestZeroG_Y + 1);
  }
}
//---------------------------------------------------------------------------
void __fastcall THDAPS::Button3Click(TObject *Sender)
{
  Application->MessageBox("HDAPS (Use IBM Active Protection System DLL)\n\n"
      "Chung Hua University Photomechanics Lab\nkikiqqp@gmail.com\n\n"
      "2008/05/04", "About", MB_OK + MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

