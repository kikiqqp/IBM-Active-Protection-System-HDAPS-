object HDAPS: THDAPS
  Left = 223
  Top = 125
  BorderStyle = bsToolWindow
  Caption = 'HDAPS'
  ClientHeight = 303
  ClientWidth = 403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 2
    Top = 2
    Width = 326
    Height = 29
    AutoSize = False
    Caption = 'IBM Active Protection System'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 1
    Top = 1
    Width = 326
    Height = 29
    AutoSize = False
    Caption = 'IBM Active Protection System'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsItalic]
    ParentFont = False
    Transparent = True
  end
  object Label3: TLabel
    Left = 2
    Top = 34
    Width = 37
    Height = 13
    AutoSize = False
    Caption = 'Status'
  end
  object Label4: TLabel
    Left = 2
    Top = 52
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 2
    Top = 70
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Bevel1: TBevel
    Left = 2
    Top = 178
    Width = 150
    Height = 2
  end
  object Label6: TLabel
    Left = 2
    Top = 90
    Width = 75
    Height = 13
    AutoSize = False
    Caption = 'AccelData'
  end
  object Label7: TLabel
    Left = 2
    Top = 108
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label8: TLabel
    Left = 2
    Top = 126
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label9: TLabel
    Left = 2
    Top = 144
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label10: TLabel
    Left = 2
    Top = 162
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label11: TLabel
    Left = 2
    Top = 182
    Width = 75
    Height = 13
    AutoSize = False
    Caption = 'Temperature'
  end
  object Label12: TLabel
    Left = 2
    Top = 200
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label13: TLabel
    Left = 2
    Top = 220
    Width = 75
    Height = 13
    AutoSize = False
    Caption = 'Latest Zero G'
  end
  object Label14: TLabel
    Left = 2
    Top = 238
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label15: TLabel
    Left = 2
    Top = 256
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Bevel2: TBevel
    Left = 2
    Top = 86
    Width = 150
    Height = 2
  end
  object Bevel3: TBevel
    Left = 2
    Top = 216
    Width = 400
    Height = 2
  end
  object Bevel4: TBevel
    Left = 2
    Top = 272
    Width = 400
    Height = 2
  end
  object Label16: TLabel
    Left = 166
    Top = 220
    Width = 75
    Height = 13
    AutoSize = False
    Caption = 'Angle'
  end
  object Label17: TLabel
    Left = 166
    Top = 238
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Label18: TLabel
    Left = 166
    Top = 256
    Width = 150
    Height = 13
    AutoSize = False
    Caption = 'Label4'
  end
  object Image1: TImage
    Left = 156
    Top = 40
    Width = 243
    Height = 173
    Transparent = True
  end
  object Label19: TLabel
    Left = 4
    Top = 282
    Width = 223
    Height = 13
    AutoSize = False
    Caption = 'Chung Hua University Photomechanics Lab'
    Enabled = False
  end
  object Button1: TButton
    Left = 326
    Top = 276
    Width = 75
    Height = 25
    Caption = '&Close'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 246
    Top = 276
    Width = 75
    Height = 25
    Caption = '&Reset'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 324
    Top = 244
    Width = 75
    Height = 25
    Caption = '&About'
    TabOrder = 2
    Visible = False
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 370
    Top = 4
  end
  object PopupMenu1: TPopupMenu
    OnPopup = Button3Click
    Left = 338
    Top = 4
  end
end
