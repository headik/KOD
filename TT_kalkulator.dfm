object Form_TT_kalkulator: TForm_TT_kalkulator
  Left = 0
  Top = 0
  Anchors = [akLeft, akTop, akRight, akBottom]
  BorderStyle = bsDialog
  Caption = 'Takt Time - kalkul'#225'tor'
  ClientHeight = 318
  ClientWidth = 276
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  ExplicitWidth = 320
  ExplicitHeight = 240
  PixelsPerInch = 96
  TextHeight = 13
  object OK: TButton
    Left = 101
    Top = 287
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 0
    OnClick = OKClick
  end
  object GroupBox1: TGroupBox
    Left = 5
    Top = 2
    Width = 266
    Height = 159
    Caption = 'Parametry'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label2: TLabel
      Left = 11
      Top = 24
      Width = 104
      Height = 13
      Caption = 'Po'#269'et hodin za sm'#283'nu'
    end
    object Label1: TLabel
      Left = 11
      Top = 51
      Width = 90
      Height = 13
      Caption = 'Po'#269'et sm'#283'n za den'
    end
    object Label3: TLabel
      Left = 11
      Top = 78
      Width = 44
      Height = 13
      Caption = 'Po'#269'et dn'#237
    end
    object Label4: TLabel
      Left = 11
      Top = 105
      Width = 146
      Height = 13
      Caption = 'Po'#382'adovan'#233' mno'#382'sv'#237' produkt'#367
    end
    object Label6: TLabel
      Left = 11
      Top = 132
      Width = 85
      Height = 13
      Caption = 'Produkt'#367' na voz'#237'k'
    end
    object Button_zamek_produkty: TSpeedButton
      Left = 172
      Top = 102
      Width = 21
      Height = 21
      Hint = 'Uzamkne hodnotu polo'#382'ky'
      AllowAllUp = True
      GroupIndex = 1
      Glyph.Data = {
        56020000424D560200000000000076000000280000003C0000000F0000000100
        040000000000E001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000FFFFFFF0FFFF
        0FFFFFFFFF0FFFF0FFFFFFFFF0FFFF0FFFFFF0FFFF0FFFFF0000FFFFFFF0FFFF
        0FFFFFFFFF0FFFF0FFFFFFFFF0FFFF0FFFFFF0FFFF0FFFFF0000FFFFFFFF0FF0
        FFFFFFFFFFF0FF0FFFFFFFFFFF0FF0FFFFFFF0FFFF0FFFFF0000FFFFFFFF0000
        FFFFFFFFFFF0000FFFFFFFFFFF0000FFFFFFFF0000FFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000}
      NumGlyphs = 4
      ParentShowHint = False
      ShowHint = True
      OnClick = Button_zamek_produktyClick
    end
    object Edit_hodin: TEdit
      Left = 196
      Top = 21
      Width = 60
      Height = 21
      TabOrder = 0
      Text = '8'
      OnChange = Zadani_Change
    end
    object Edit_smen: TEdit
      Left = 196
      Top = 48
      Width = 60
      Height = 21
      TabOrder = 1
      Text = '1'
      OnChange = Zadani_Change
    end
    object Edit_dni: TEdit
      Left = 196
      Top = 75
      Width = 60
      Height = 21
      TabOrder = 2
      Text = '21'
      OnChange = Zadani_Change
    end
    object Edit_produkty: TEdit
      Left = 196
      Top = 102
      Width = 60
      Height = 21
      TabOrder = 3
      Text = '0'
      OnChange = Zadani_Change
    end
    object Edit_produktu_na_vozik: TEdit
      Left = 196
      Top = 129
      Width = 60
      Height = 21
      NumbersOnly = True
      TabOrder = 4
      Text = '1'
      OnChange = Zadani_Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 5
    Top = 167
    Width = 266
    Height = 110
    TabOrder = 2
    object Label5: TLabel
      Left = 7
      Top = 11
      Width = 175
      Height = 13
      Caption = 'Po'#382'adovan'#253' v'#253'robn'#237' Takt Time'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 56
      Top = 33
      Width = 52
      Height = 13
      Caption = '[min/voz'#237'k]'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 166
      Top = 33
      Width = 65
      Height = 13
      Caption = '[min/produkt]'
    end
    object Label_nerelev: TLabel
      Left = 181
      Top = 21
      Width = 40
      Height = 13
      Caption = 'nerelev.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object Label11: TLabel
      Left = 166
      Top = 79
      Width = 71
      Height = 13
      Caption = '[produkt'#367'/min]'
    end
    object Label8: TLabel
      Left = 7
      Top = 57
      Width = 159
      Height = 13
      Caption = 'Po'#382'adovan'#225' m'#237'ra dokon'#269'en'#237
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 56
      Top = 79
      Width = 58
      Height = 13
      Caption = '[voz'#237'k'#367'/min]'
    end
    object Button_zamek_TT: TSpeedButton
      Left = 239
      Top = 52
      Width = 21
      Height = 21
      Hint = 'Uzamkne hodnotu polo'#382'ky'
      AllowAllUp = True
      GroupIndex = 1
      Glyph.Data = {
        56020000424D560200000000000076000000280000003C0000000F0000000100
        040000000000E001000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000F00000000FFF
        FFFF00000000FFFFFFF00000000FFFFFFFFF00000000FFFF0000FFFFFFF0FFFF
        0FFFFFFFFF0FFFF0FFFFFFFFF0FFFF0FFFFFF0FFFF0FFFFF0000FFFFFFF0FFFF
        0FFFFFFFFF0FFFF0FFFFFFFFF0FFFF0FFFFFF0FFFF0FFFFF0000FFFFFFFF0FF0
        FFFFFFFFFFF0FF0FFFFFFFFFFF0FF0FFFFFFF0FFFF0FFFFF0000FFFFFFFF0000
        FFFFFFFFFFF0000FFFFFFFFFFF0000FFFFFFFF0000FFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000}
      NumGlyphs = 4
      ParentShowHint = False
      ShowHint = True
      OnClick = Button_zamek_TTClick
    end
    object Edit_TT: TEdit
      Left = 7
      Top = 30
      Width = 48
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
      OnChange = Edit_TTChange
    end
    object Edit_TT_produktu: TEdit
      Left = 116
      Top = 30
      Width = 48
      Height = 21
      TabOrder = 1
      Text = '0'
      OnChange = Edit_TT_produktuChange
    end
    object Button_TT_sec: TButton
      Left = 239
      Top = 29
      Width = 21
      Height = 21
      Hint = 'Zobraz'#237' hodnoty v sekund'#225'ch'
      Caption = 'sec'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = Button_TT_secClick
    end
    object Button_TP_sec: TButton
      Left = 239
      Top = 76
      Width = 21
      Height = 21
      Hint = 'Zobraz'#237' hodnoty v sekund'#225'ch'
      Caption = 'sec'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = Button_TP_secClick
    end
    object Edit_TP_produktu: TEdit
      Left = 116
      Top = 76
      Width = 48
      Height = 21
      TabOrder = 4
      Text = '0'
      OnChange = Edit_TP_produktuChange
    end
    object Edit_TP: TEdit
      Left = 7
      Top = 76
      Width = 48
      Height = 21
      TabOrder = 5
      Text = '0'
      OnChange = Edit_TPChange
    end
  end
end
