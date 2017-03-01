object Form_vozik_nastaveni: TForm_vozik_nastaveni
  Left = 0
  Top = 0
  AutoSize = True
  BorderStyle = bsDialog
  Caption = 'Voz'#237'k - parametry'
  ClientHeight = 313
  ClientWidth = 949
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button_OK: TButton
    Left = 371
    Top = 231
    Width = 95
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button_OKClick
  end
  object RzStringGrid1: TRzStringGrid
    Left = 0
    Top = 0
    Width = 949
    Height = 225
    ColCount = 14
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
    OnClick = RzStringGrid1Click
    OnDrawCell = RzStringGrid1DrawCell
    OnGetEditMask = RzStringGrid1GetEditMask
    OnMouseDown = RzStringGrid1MouseDown
    OnRowMoved = RzStringGrid1RowMoved
  end
  object Button1: TButton
    Left = 191
    Top = 231
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 272
    Top = 231
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 3
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 472
    Top = 231
    Width = 75
    Height = 25
    Caption = 'P'#345'idat voz'#237'k'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 480
    Top = 262
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 5
    Visible = False
  end
  object Memo1: TMemo
    Left = 664
    Top = 231
    Width = 97
    Height = 82
    Lines.Strings = (
      'Memo1')
    TabOrder = 6
    Visible = False
  end
  object Memo_spojak: TButton
    Left = 371
    Top = 262
    Width = 75
    Height = 25
    Caption = 'spojacek-color'
    TabOrder = 7
    Visible = False
    OnClick = Memo_spojakClick
  end
  object Memo2: TMemo
    Left = 0
    Top = 218
    Width = 185
    Height = 88
    Lines.Strings = (
      'Memo2')
    TabOrder = 8
    Visible = False
  end
  object Memo3: TMemo
    Left = 561
    Top = 231
    Width = 97
    Height = 74
    Lines.Strings = (
      'Memo3')
    TabOrder = 9
    Visible = False
  end
  object Button_DEL: TButton
    Left = 859
    Top = 0
    Width = 15
    Height = 15
    Hint = 'Sma'#382'e '#345#225'dek'
    Caption = 'X'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    Visible = False
    OnClick = Button_DELClick
  end
  object ColorDialog1: TColorDialog
    Left = 520
    Top = 48
  end
end
