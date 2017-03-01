object Form_parametry: TForm_parametry
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Parametry objektu'
  ClientHeight = 410
  ClientWidth = 276
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
  object Label_CT: TLabel
    Left = 2
    Top = 296
    Width = 140
    Height = 13
    Caption = 'CYCLE TIME [min/voz'#237'k] :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_rezim: TLabel
    Left = 2
    Top = 24
    Width = 38
    Height = 13
    Caption = 'Re'#382'im:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_technologicke_parametry: TLabel
    Left = 2
    Top = 148
    Width = 148
    Height = 13
    Caption = 'Technologick'#233' parametry:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_kapacita: TLabel
    Left = 2
    Top = 334
    Width = 152
    Height = 13
    Caption = 'Kapacita objektu [voz'#237'k'#367']: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_kapacita_hodnota: TLabel
    Left = 197
    Top = 334
    Width = 7
    Height = 13
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_CT_hodnota: TLabel
    Left = 197
    Top = 296
    Width = 7
    Height = 13
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_vypis: TLabel
    Left = 41
    Top = 355
    Width = 194
    Height = 13
    Caption = 'TT objektu nen'#237' toto'#382'n'#253' s TT linky!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label_TT: TLabel
    Left = 2
    Top = 315
    Width = 183
    Height = 13
    Caption = 'TAKT TIME objektu [min/voz'#237'k] :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_TT_hodnota: TLabel
    Left = 197
    Top = 315
    Width = 7
    Height = 13
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label_delka_prepravniku: TLabel
    Left = 2
    Top = 374
    Width = 124
    Height = 13
    Caption = 'D'#233'lka koleje [metry]: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label_delka_prepravniku_hodnota: TLabel
    Left = 197
    Top = 374
    Width = 7
    Height = 13
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label1: TLabel
    Left = 2
    Top = 5
    Width = 37
    Height = 13
    Caption = 'N'#225'zev:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 193
    Top = 5
    Width = 48
    Height = 13
    Caption = 'Zkratka:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button_OK: TButton
    Left = 90
    Top = 374
    Width = 95
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 2
  end
  object ValueListEditor: TValueListEditor
    Left = 3
    Top = 162
    Width = 271
    Height = 133
    BiDiMode = bdLeftToRight
    BorderStyle = bsNone
    DefaultColWidth = 192
    KeyOptions = [keyEdit, keyUnique]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking, goFixedColClick, goFixedRowClick, goFixedHotTrack]
    ParentBiDiMode = False
    ScrollBars = ssNone
    Strings.Strings = (
      'PT - '#269'ist'#253' technologick'#253' v'#253'robn'#237' '#269'as=0'
      'MT - '#269'as p'#345'esouv'#225'n'#237' produktu=0'
      'WT - doba '#269'ek'#225'n'#237' voz'#237'ku=0'
      'IT - doba kontroly voz'#237'ku=0'
      'QT - doba '#269'ek'#225'n'#237' ve front'#283'=0'
      '...=')
    TabOrder = 1
    TitleCaptions.Strings = (
      ' n'#225'zev'
      ' '#269'as [min/voz'#237'k]')
    OnClick = ValueListEditorClick
    OnStringsChange = ValueListEditorStringsChange
    ColWidths = (
      192
      77)
  end
  object ComboBox_druh_objektu: TComboBox
    Left = 2
    Top = 37
    Width = 272
    Height = 21
    Hint = 'Volba re'#382'imu objektu'
    Style = csDropDownList
    ItemIndex = 0
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'STOP & GO'
    OnChange = ComboBox_druh_objektuChange
    Items.Strings = (
      'STOP & GO'
      'KONTINU'#193'LN'#205' (line tracking)'
      'POSTPROCESN'#205)
  end
  object ComboBox_dopravnik: TComboBox
    Left = 2
    Top = 162
    Width = 272
    Height = 21
    Hint = 'Volba dopravn'#237'ku'
    Style = csDropDownList
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    Visible = False
    OnChange = ComboBox_dopravnikChange
  end
  object GroupBox_voziky: TGroupBox
    Left = 2
    Top = 64
    Width = 272
    Height = 79
    Caption = 'Voz'#237'ky'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    object GroupBox_orientace_voziku: TGroupBox
      Left = 5
      Top = 13
      Width = 262
      Height = 61
      Caption = 'orientace'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Image_vozik: TImage
        Left = 74
        Top = 8
        Width = 185
        Height = 50
        Hint = 'Kliknut'#237'm lze zm'#283'nit orientaci voz'#237'ku'
        ParentShowHint = False
        ShowHint = True
        Transparent = True
        OnClick = Image_vozikClick
      end
      object RadioButton_na_delku: TRadioButton
        Left = 14
        Top = 16
        Width = 65
        Height = 17
        Caption = 'na d'#233'lku'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton_na_delkuClick
      end
      object RadioButton_na_sirku: TRadioButton
        Left = 14
        Top = 35
        Width = 65
        Height = 17
        Caption = 'na '#353#237#345'ku'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton_na_sirkuClick
      end
    end
    object GroupBox_vzdalenost: TGroupBox
      Left = 195
      Top = 13
      Width = 72
      Height = 61
      Caption = 'vzd'#225'lenost'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Visible = False
      object Label3: TLabel
        Left = 38
        Top = 25
        Width = 30
        Height = 13
        Caption = '[metr]'
      end
      object Edit_vzdalenost_voziku: TEdit
        Left = 5
        Top = 22
        Width = 30
        Height = 21
        Alignment = taCenter
        TabOrder = 0
        Text = '1'
        OnChange = Edit_vzdalenost_vozikuChange
        OnKeyDown = Edit_vzdalenost_vozikuKeyDown
      end
    end
  end
  object Button_min_sec: TButton
    Left = 224
    Top = 392
    Width = 50
    Height = 16
    Hint = 'P'#345'epo'#269#237't'#225' hodnoty z minut na sekundy a obr'#225'cen'#283
    Caption = 'min<->sec'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    OnClick = Button_min_secClick
  end
  object Button_DEL: TButton
    Left = 258
    Top = 277
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
    TabOrder = 6
    Visible = False
    OnClick = Button_DELClick
  end
  object Edit_name: TEdit
    Left = 43
    Top = 1
    Width = 142
    Height = 21
    CharCase = ecUpperCase
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnChange = Edit_nameChange
  end
  object Edit_shortname: TEdit
    Left = 245
    Top = 1
    Width = 29
    Height = 21
    Alignment = taCenter
    AutoSize = False
    CharCase = ecUpperCase
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    MaxLength = 3
    ParentFont = False
    TabOrder = 8
  end
end
