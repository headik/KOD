object MyMessageBox: TMyMessageBox
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 86
  ClientWidth = 242
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    AlignWithMargins = True
    Left = 8
    Top = 10
    Width = 3
    Height = 13
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object Button_Yes: TButton
    Left = 35
    Top = 37
    Width = 70
    Height = 25
    Caption = 'Ano'
    ModalResult = 6
    TabOrder = 0
  end
  object CheckBox_pamatovat: TCheckBox
    Left = 3
    Top = 68
    Width = 238
    Height = 17
    Caption = 'Pamatovat si volbu po dobu spu'#353't'#283'n'#237' aplikace'
    TabOrder = 1
  end
  object Button_No: TButton
    Left = 139
    Top = 37
    Width = 70
    Height = 25
    Caption = 'Ne'
    ModalResult = 7
    TabOrder = 2
  end
  object Button_OK: TButton
    Left = 83
    Top = 37
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 3
    Visible = False
  end
end
