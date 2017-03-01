object Form_dopravnik: TForm_dopravnik
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Dopravn'#237'ky - parametry'
  ClientHeight = 214
  ClientWidth = 533
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ValueListEditor: TValueListEditor
    Left = 0
    Top = 0
    Width = 533
    Height = 57
    Align = alTop
    BiDiMode = bdLeftToRight
    BorderStyle = bsNone
    KeyOptions = [keyEdit, keyUnique]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking, goFixedColClick, goFixedRowClick, goFixedHotTrack]
    ParentBiDiMode = False
    ScrollBars = ssNone
    Strings.Strings = (
      'hlavn'#237' dopravn'#237'k=5'
      'vedlej'#353#237' dopravn'#237'k=3')
    TabOrder = 0
    TitleCaptions.Strings = (
      ' n'#225'zev'
      ' rychlost [m/min]')
    ExplicitWidth = 321
    ColWidths = (
      150
      381)
  end
  object Button_ADD: TButton
    Left = 42
    Top = 63
    Width = 75
    Height = 25
    Caption = 'P'#345'idat'
    TabOrder = 1
    OnClick = Button_ADDClick
  end
  object Button_DEL: TButton
    Left = 160
    Top = 63
    Width = 75
    Height = 25
    Caption = 'Smazat'
    TabOrder = 2
    OnClick = Button_DELClick
  end
  object Button_OK: TButton
    Left = 90
    Top = 107
    Width = 95
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 3
    OnClick = Button_OKClick
  end
end
