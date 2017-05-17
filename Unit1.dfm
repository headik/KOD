object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ELTEP - TISPL - Timing Inspection of Single Purpose Lines'
  ClientHeight = 542
  ClientWidth = 946
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poDesigned
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  OnResize = FormResize
  OnShortCut = FormShortCut
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object wip: TLabel
    Left = 896
    Top = 50
    Width = 27
    Height = 19
    Caption = 'wip'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label_zamerovac: TLabel
    Left = 149
    Top = 75
    Width = 32
    Height = 28
    Margins.Left = 6
    Margins.Top = 6
    Margins.Right = 6
    Margins.Bottom = 6
    Caption = 'voz'#237'k:'#13'min:'
    Color = clWhite
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clGray
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object Label6: TLabel
    Left = 544
    Top = 208
    Width = 89
    Height = 13
    Caption = 'Label6'
  end
  object RzToolbar1: TRzToolbar
    Left = 0
    Top = 0
    Width = 946
    Height = 29
    Images = ImageList1
    BorderInner = fsNone
    BorderOuter = fsGroove
    BorderSides = [sdTop]
    BorderWidth = 0
    TabOrder = 0
    VisualStyle = vsGradient
    ToolbarControls = (
      RzToolButton1
      RzToolButton2
      RzToolButton3
      RzSpacer1
      RzToolButton4
      RzToolButton5
      RzSpacer2
      RzToolButton6
      RzToolButton7
      RzToolButton8
      RzToolButton9
      RzToolButton10
      RzToolButton11
      RzToolButton12
      LabelRoletka)
    object RzToolButton1: TRzToolButton
      Left = 4
      Top = 2
      Hint = 'Zalo'#382#237' nov'#253' soubor'
      ImageIndex = 0
      Images = ImageList1
      ParentShowHint = False
      ShowHint = True
      OnClick = NovySouborClick
    end
    object RzToolButton2: TRzToolButton
      Left = 29
      Top = 2
      Hint = 'Otev'#345'e existuj'#237'c'#237' soubor'
      ImageIndex = 1
      Images = ImageList1
      ParentShowHint = False
      ShowHint = True
      OnClick = OtevritClick
    end
    object RzToolButton3: TRzToolButton
      Left = 54
      Top = 2
      Hint = 'Ulo'#382#237' aktu'#225'ln'#237' soubor'
      ImageIndex = 2
      Images = ImageList1
      Enabled = False
      ParentShowHint = False
      ShowHint = True
      OnClick = UlozitClick
    end
    object RzSpacer1: TRzSpacer
      Left = 79
      Top = 2
    end
    object RzToolButton4: TRzToolButton
      Left = 87
      Top = 2
      Hint = 'Zp'#283't'
      ImageIndex = 3
      Enabled = False
      ParentShowHint = False
      ShowHint = True
    end
    object RzToolButton5: TRzToolButton
      Left = 112
      Top = 2
      Hint = 'Vp'#345'ed'
      ImageIndex = 4
      Enabled = False
    end
    object RzToolButton6: TRzToolButton
      Left = 145
      Top = 2
      Hint = 'Posouvat obraz'
      ImageIndex = 6
      ParentShowHint = False
      ShowHint = True
      OnClick = Posouvat2Click
    end
    object RzToolButton7: TRzToolButton
      Left = 170
      Top = 2
      Hint = 'Posunout obraz'
      ImageIndex = 5
      ParentShowHint = False
      ShowHint = True
      OnClick = Posunout3Click
    end
    object RzToolButton8: TRzToolButton
      Left = 195
      Top = 2
      Hint = 'P'#345'ibl'#237#382'it obraz'
      ImageIndex = 7
      ParentShowHint = False
      ShowHint = True
      OnClick = RzToolButton8Click
    end
    object RzToolButton9: TRzToolButton
      Left = 220
      Top = 2
      Hint = 'Odd'#225'lit obraz'
      ImageIndex = 8
      ParentShowHint = False
      ShowHint = True
      OnClick = RzToolButton9Click
    end
    object RzSpacer2: TRzSpacer
      Left = 137
      Top = 2
    end
    object RzToolButton10: TRzToolButton
      Left = 245
      Top = 2
      Hint = 'P'#345'ibl'#237#382'it obraz dle v'#253'b'#283'ru oknem'
      ImageIndex = 9
      ParentShowHint = False
      ShowHint = True
      OnClick = Vybratoknem2Click
    end
    object RzToolButton11: TRzToolButton
      Left = 270
      Top = 2
      Hint = 'Zobrazit v'#353'echny objekty'
      ImageIndex = 10
      ParentShowHint = False
      ShowHint = True
      OnClick = RzToolButton11Click
    end
    object RzToolButton12: TRzToolButton
      Left = 295
      Top = 2
      Hint = 'P'#345'edchoz'#237' pohled'
      ImageIndex = 11
      Enabled = False
      ParentShowHint = False
      ShowHint = True
      OnClick = Predchozipohled1Click
    end
    object LabelRoletka: TLabel
      Left = 320
      Top = 8
      Width = 61
      Height = 13
      Caption = 'LabelRoletka'
      Visible = False
    end
  end
  object RzStatusBar1: TRzStatusBar
    Left = 0
    Top = 523
    Width = 946
    Height = 19
    BorderInner = fsNone
    BorderOuter = fsNone
    BorderSides = [sdLeft, sdTop, sdRight, sdBottom]
    BorderWidth = 0
    TabOrder = 1
    VisualStyle = vsGradient
    object RzStatusPane1: TRzStatusPane
      Left = 0
      Top = 0
      Width = 125
      Height = 19
      Hint = 'Kliknut'#237'm lze p'#345'epnout m'#243'd zobrazen'#237
      Align = alLeft
      ParentShowHint = False
      ShowHint = True
      OnClick = RzStatusPane1Click
      Caption = ''
      DefaultWidth = 50
    end
    object RzStatusPane2: TRzStatusPane
      Left = 125
      Top = 0
      Width = 77
      Height = 19
      Hint = 'Aktu'#225'ln'#237' '#250'rove'#328' p'#345'ibl'#237#382'en'#237' obrazu'
      Align = alLeft
      ParentShowHint = False
      ShowHint = True
      Caption = ''
      ExplicitLeft = 100
    end
    object RzStatusPane3: TRzStatusPane
      Left = 202
      Top = 0
      Height = 19
      Hint = 'Aktu'#225'ln'#237' polohu kurzoru v sou'#345'adnic'#237'ch aplikace'
      Align = alLeft
      ParentShowHint = False
      ShowHint = True
      Caption = ''
    end
    object RzStatusPane4: TRzStatusPane
      Left = 378
      Top = 0
      Width = 568
      Height = 19
      Hint = 'Rychl'#225' n'#225'pov'#283'da aplikace'
      Align = alClient
      ParentShowHint = False
      ShowHint = True
      Caption = ''
      DefaultWidth = 200
      ExplicitLeft = 300
      ExplicitWidth = 155
    end
    object RzStatusPane5: TRzStatusPane
      Left = 302
      Top = 0
      Width = 76
      Height = 19
      Hint = 'Kliknut'#237'm zm'#283'n'#237'te re'#382'im p'#345'ichyt'#225'v'#225'n'#237' objektu ke m'#345#237#382'ce'
      Align = alLeft
      ParentShowHint = False
      ShowHint = True
      OnClick = RzStatusPane5Click
      Caption = ''
    end
  end
  object RzSizePanel_knihovna_objektu: TRzSizePanel
    Left = 0
    Top = 143
    Width = 145
    Height = 258
    Align = alNone
    AlignmentVertical = avTop
    LockBar = True
    Locked = True
    TabOrder = 2
    VisualStyle = vsGradient
    OnMouseEnter = RzSizePanel_knihovna_objektuMouseEnter
    object Label3: TLabel
      Left = 0
      Top = 0
      Width = 140
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Knihovna objekt'#367
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      ExplicitWidth = 99
    end
    object DrawGrid_knihovna: TDrawGrid
      Left = 0
      Top = 13
      Width = 140
      Height = 245
      ParentCustomHint = False
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      ColCount = 2
      Ctl3D = False
      DefaultColWidth = 70
      DefaultRowHeight = 50
      FixedColor = clWhite
      FixedCols = 0
      RowCount = 4
      FixedRows = 0
      GridLineWidth = 0
      Options = []
      ParentCtl3D = False
      ScrollBars = ssNone
      TabOrder = 0
      OnDrawCell = DrawGrid_knihovnaDrawCell
      OnKeyDown = DrawGrid_knihovnaKeyDown
      OnKeyUp = DrawGrid_knihovnaKeyUp
      OnMouseDown = DrawGrid_knihovnaMouseDown
      OnMouseLeave = DrawGrid_knihovnaMouseLeave
      OnMouseWheelDown = DrawGrid_knihovnaMouseWheelDown
      OnMouseWheelUp = DrawGrid_knihovnaMouseWheelUp
    end
  end
  object RzSizePanel_parametry_projekt: TRzSizePanel
    Left = 0
    Top = 33
    Width = 145
    Height = 104
    Align = alNone
    AlignmentVertical = avTop
    Locked = True
    TabOrder = 3
    VisualStyle = vsGradient
    object Label1: TLabel
      Left = 5
      Top = 20
      Width = 56
      Height = 13
      Margins.Left = 2
      Caption = 'TAKT TIME:'
      Transparent = True
    end
    object Label2: TLabel
      Left = 5
      Top = 48
      Width = 94
      Height = 13
      Caption = 'DEFINICE ZAK'#193'ZEK'
      Transparent = True
    end
    object Label4: TLabel
      Left = 0
      Top = 0
      Width = 140
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Parametry linky'
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      ExplicitWidth = 91
    end
    object Label5: TLabel
      Left = 102
      Top = 21
      Width = 16
      Height = 13
      Caption = 'min'
      Transparent = True
    end
    object Label8: TLabel
      Left = 5
      Top = 75
      Width = 42
      Height = 13
      Caption = 'POHONY'
      Transparent = True
    end
    object Edit_takt_time: TEdit
      Left = 64
      Top = 18
      Width = 35
      Height = 19
      Alignment = taCenter
      Ctl3D = False
      ParentCtl3D = False
      TabOrder = 1
      OnChange = Edit_takt_timeChange
      OnEnter = Edit_takt_timeEnter
    end
    object Button_kalkulatorTT: TButton
      Left = 120
      Top = 16
      Width = 20
      Height = 22
      Hint = 'Zobraz'#237' TAKT TIME kalkul'#225'tor'
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = Button_kalkulatorTTClick
    end
    object Button_dopravnik_parametry: TButton
      Left = 120
      Top = 72
      Width = 20
      Height = 22
      Hint = 'Nastaven'#237' parametr'#367' dopravn'#237'ku'
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = Button_dopravnik_parametryClick
    end
    object Button_vozik_parametry: TButton
      Left = 120
      Top = 44
      Width = 20
      Height = 22
      Hint = 'Nastaven'#237' parametr'#367' voz'#237'ku'
      Caption = '...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = Button_vozik_parametryClick
    end
  end
  object Button1: TButton
    Left = 146
    Top = 33
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 4
    Visible = False
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 0
    Top = 474
    Width = 946
    Height = 49
    Align = alBottom
    Lines.Strings = (
      '')
    TabOrder = 5
    Visible = False
  end
  object Button3: TButton
    Left = 160
    Top = 112
    Width = 85
    Height = 25
    Caption = 'Nav'#283'sit voz'#237'k (0)'
    TabOrder = 6
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 160
    Top = 143
    Width = 85
    Height = 25
    Caption = 'Pauza simulace'
    TabOrder = 7
    Visible = False
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 160
    Top = 205
    Width = 85
    Height = 25
    Caption = 'stopka'
    TabOrder = 8
    Visible = False
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 160
    Top = 236
    Width = 85
    Height = 25
    Caption = #269'ekat na palec'
    TabOrder = 9
    Visible = False
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 160
    Top = 174
    Width = 85
    Height = 25
    Caption = 'Krok simulace'
    TabOrder = 10
    Visible = False
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 160
    Top = 267
    Width = 85
    Height = 25
    Caption = 'D'#233'lka dopravn'#237'ku'
    TabOrder = 11
    Visible = False
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 160
    Top = 329
    Width = 129
    Height = 25
    Caption = 'vypsat spoj'#225'k VOZIKY'
    TabOrder = 12
    Visible = False
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 160
    Top = 298
    Width = 110
    Height = 25
    Caption = 'zkr'#225'tit linky dle palc'#367
    TabOrder = 13
    Visible = False
    OnClick = Button10Click
  end
  object Chart1: TChart
    Left = 497
    Top = 29
    Width = 76
    Height = 58
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    TabOrder = 14
    OnClick = Chart1Click
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      12
      15
      12)
    ColorPaletteIndex = 19
    object Series1: TGanttSeries
      Marks.Children = <
        item
          Shape.ShapeStyle = fosRectangle
          Shape.Style = smsValue
        end>
      Marks.ChildLayout = slLeftRight
      ValueFormat = '##0.## %'
      ClickableLine = False
      Pointer.HorizSize = 18
      Pointer.InflateMargins = True
      Pointer.Pen.Visible = False
      Pointer.Style = psRectangle
      Pointer.VertSize = 18
      XValues.DateTime = False
      XValues.Name = 'Start'
      XValues.Order = loNone
      YValues.Name = 'Y'
      YValues.Order = loNone
      Callout.Style = psRightTriangle
      Callout.Arrow.Visible = False
      StartValues.DateTime = False
      StartValues.Name = 'Start'
      StartValues.Order = loNone
      EndValues.Name = 'End'
      EndValues.Order = loNone
      NextTask.Name = 'NextTask'
      NextTask.Order = loNone
    end
  end
  object Chart2: TChart
    Left = 571
    Top = 29
    Width = 76
    Height = 58
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    TabOrder = 15
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      BarPen.Visible = False
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Arrow.Visible = False
      Marks.Callout.Arrow.Visible = False
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = 5
      Marks.Callout.Length = 0
      MultiBar = mbStacked
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series3: TBarSeries
      BarPen.Visible = False
      Marks.Children = <
        item
          Shape.ShapeStyle = fosRectangle
          Shape.Visible = False
          Shape.Style = smsValue
        end>
      Marks.Frame.Visible = False
      Marks.Shadow.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = 5
      Marks.Callout.Length = 0
      MultiBar = mbStacked
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
      Data = {0000000000}
    end
  end
  object Chart3: TChart
    Left = 642
    Top = 29
    Width = 76
    Height = 58
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    TabOrder = 16
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series5: TBarSeries
      BarPen.Visible = False
      Marks.Frame.Visible = False
      Marks.Transparency = 30
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Arrow.Visible = False
      Marks.Callout.Pen.Visible = False
      Marks.Callout.Arrow.Visible = False
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = 5
      Marks.Callout.Length = 0
      Marks.Symbol.Frame.Visible = False
      Marks.Symbol.Pen.Visible = False
      MultiBar = mbStacked
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series6: TBarSeries
      BarBrush.Gradient.EndColor = 3513587
      BarPen.Visible = False
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = 5
      Marks.Callout.Length = 0
      Gradient.EndColor = 3513587
      MultiBar = mbStacked
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Chart4: TChart
    Left = 716
    Top = 32
    Width = 73
    Height = 53
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    View3DOptions.Elevation = 315
    View3DOptions.Orthogonal = False
    View3DOptions.Perspective = 0
    View3DOptions.Rotation = 360
    TabOrder = 17
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series7: TPieSeries
      Marks.Font.Color = clWhite
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Arrow.Visible = False
      Marks.Callout.Arrow.Visible = False
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = -35
      Marks.Callout.Length = 0
      XValues.Order = loAscending
      YValues.Name = 'Pie'
      YValues.Order = loNone
      Frame.InnerBrush.BackColor = clRed
      Frame.InnerBrush.Gradient.EndColor = clGray
      Frame.InnerBrush.Gradient.MidColor = clWhite
      Frame.InnerBrush.Gradient.StartColor = 4210752
      Frame.InnerBrush.Gradient.Visible = True
      Frame.MiddleBrush.BackColor = clYellow
      Frame.MiddleBrush.Gradient.EndColor = 8553090
      Frame.MiddleBrush.Gradient.MidColor = clWhite
      Frame.MiddleBrush.Gradient.StartColor = clGray
      Frame.MiddleBrush.Gradient.Visible = True
      Frame.OuterBrush.BackColor = clGreen
      Frame.OuterBrush.Gradient.EndColor = 4210752
      Frame.OuterBrush.Gradient.MidColor = clWhite
      Frame.OuterBrush.Gradient.StartColor = clSilver
      Frame.OuterBrush.Gradient.Visible = True
      Frame.Width = 4
      OtherSlice.Legend.Visible = False
      PiePen.Visible = False
    end
  end
  object Button2: TButton
    Left = 852
    Top = 1
    Width = 75
    Height = 25
    Caption = 'EXPO'
    TabOrder = 18
    Visible = False
    OnClick = Button2Click
  end
  object ButtonPLAY: TButton
    Left = 795
    Top = 1
    Width = 43
    Height = 21
    Caption = 'PLAY'
    TabOrder = 19
    Visible = False
    OnClick = ButtonPLAYClick
  end
  object Chart6: TChart
    Left = 784
    Top = 29
    Width = 84
    Height = 58
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    TabOrder = 20
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      13
      15
      13)
    ColorPaletteIndex = 13
    object Series9: TBarSeries
      BarPen.Visible = False
      Marks.Frame.Visible = False
      Marks.Shadow.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Arrow.Visible = False
      Marks.Callout.Arrow.Visible = False
      Marks.Callout.ArrowHeadSize = 0
      Marks.Callout.Distance = 5
      Marks.Callout.Length = 0
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object CheckBoxVytizenost: TCheckBox
    Left = 262
    Top = 156
    Width = 152
    Height = 20
    Caption = 'zobrazit vyt'#237#382'enost objekt'#367
    Color = clBtnFace
    ParentColor = False
    TabOrder = 21
    Visible = False
    OnClick = CheckBoxVytizenostClick
  end
  object CheckBoxAnimovatSG: TCheckBox
    Left = 262
    Top = 177
    Width = 145
    Height = 20
    Caption = 'animovat i jednokapacitn'#237
    Checked = True
    Color = clBtnFace
    ParentColor = False
    State = cbChecked
    TabOrder = 22
    Visible = False
    OnClick = CheckBoxVytizenostClick
  end
  object CheckBoxPALCE: TCheckBox
    Left = 262
    Top = 114
    Width = 163
    Height = 20
    Caption = 'zohlednit rozte'#269' palc'#367' '#345'et'#283'zu'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 23
    Visible = False
    OnClick = CheckBoxPALCEClick
  end
  object CheckBoxVymena_barev: TCheckBox
    Left = 262
    Top = 135
    Width = 211
    Height = 20
    Caption = 'zohlednit '#269'i'#353't'#283'n'#237' pistole a v'#253'm'#283'nu barev'
    Color = clBtnFace
    Ctl3D = False
    ParentColor = False
    ParentCtl3D = False
    TabOrder = 24
    Visible = False
    OnClick = CheckBoxVymena_barevClick
  end
  object ComboBoxDOmin: TComboBox
    Left = 374
    Top = 87
    Width = 40
    Height = 21
    TabOrder = 25
    Text = 'Do'
    Visible = False
    OnChange = ComboBoxDOminChange
    Items.Strings = (
      ''
      '')
  end
  object ComboBoxODmin: TComboBox
    Left = 328
    Top = 87
    Width = 40
    Height = 21
    TabOrder = 26
    Text = 'Od'
    Visible = False
    OnChange = ComboBoxODminChange
    Items.Strings = (
      '')
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 32
    object Projekt1: TMenuItem
      Caption = '&Projekt'
      object NovySoubor: TMenuItem
        Caption = '&Nov'#253
        ShortCut = 16462
        OnClick = NovySouborClick
      end
      object Otevrit: TMenuItem
        Caption = '&Otev'#345#237't'
        ShortCut = 16463
        OnClick = OtevritClick
      end
      object Otevritsablonu: TMenuItem
        Caption = 'Otev'#345#237't '#353'ablonu...'
        ShortCut = 16468
        OnClick = OtevritsablonuClick
      end
      object Ulozit: TMenuItem
        Caption = '&Ulo'#382'it'
        Enabled = False
        ShortCut = 16467
        OnClick = UlozitClick
      end
      object Ulozitjako: TMenuItem
        Caption = 'U&lo'#382'it jako...'
        OnClick = UlozitjakoClick
      end
      object Export1: TMenuItem
        Caption = 'Export...'
        OnClick = Export1Click
      end
      object Report1: TMenuItem
        Caption = 'Report'
        object csv1: TMenuItem
          Caption = '*.csv, *xls'
          OnClick = csv1Click
        end
        object html1: TMenuItem
          Caption = '*.html'
          OnClick = html1Click
        end
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Obnovitzezlohy1: TMenuItem
        Caption = 'Obnovit ze z'#225'lohy...'
        OnClick = Obnovitzezlohy1Click
      end
      object Konec1: TMenuItem
        Caption = '&Konec'
        ShortCut = 32883
        OnClick = Konec1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Magna: TMenuItem
        Caption = '&1   Magna'
        OnClick = MagnaClick
      end
      object SPPP1: TMenuItem
        Caption = '&2   SPPP'
        OnClick = SPPP1Click
      end
      object Boskovice1: TMenuItem
        Caption = '&3   Boskovice'
        OnClick = Boskovice1Click
      end
      object eXtreme1: TMenuItem
        Caption = '&4   eXtreme'
        OnClick = eXtreme1Click
      end
    end
    object Md1: TMenuItem
      Caption = '&M'#243'd'
      object editacelinky1: TMenuItem
        Caption = 'editace linky'
        Checked = True
        RadioItem = True
        OnClick = editacelinky1Click
      end
      object testovnkapacity1: TMenuItem
        Caption = 'testov'#225'n'#237' kapacity'
        RadioItem = True
        OnClick = testovnkapacity1Click
      end
      object casoverezervy1: TMenuItem
        Caption = #269'asov'#233' rezervy'
        RadioItem = True
        OnClick = casoverezervy1Click
      end
      object casovosa1: TMenuItem
        Caption = #269'asov'#225' osa'
        RadioItem = True
        ShortCut = 120
        OnClick = casovosa1Click
      end
      object technologickprocesy1: TMenuItem
        Caption = 'technologick'#233' procesy'
        Enabled = False
        RadioItem = True
        ShortCut = 122
        OnClick = technologickprocesy1Click
      end
      object simulace1: TMenuItem
        Caption = 'simulace'
        Enabled = False
        RadioItem = True
        ShortCut = 123
        OnClick = simulace1Click
      end
    end
    object Pohled1: TMenuItem
      Caption = 'P&ohled'
      object Piblit1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8800888888888888800088888888888800088888888888800088888800008800
          08888800FFFF0000888880FFFFFFFF08888880FFF00FFF0888880FFFF00FFFF0
          88880FF000000FF088880FF000000FF088880FFFF00FFFF0888880FFF00FFF08
          888880FFFFFFFF0888888800FFFF008888888888000088888888}
        Caption = 'P'#345'ibl'#237#382'it'
        ShortCut = 118
        OnClick = Piblit1Click
      end
      object Oddlit1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8800888888888888800088888888888800088888888888800088888800008800
          08888800FFFF0000888880FFFFFFFF08888880FFFFFFFF0888880FFFFFFFFFF0
          88880FF000000FF088880FF000000FF088880FFFFFFFFFF0888880FFFFFFFF08
          888880FFFFFFFF0888888800FFFF008888888888000088888888}
        Caption = 'Odd'#225'lit'
        ShortCut = 119
        OnClick = Oddlit1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Posouvat1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888880000000
          088888880FFFFFFFF0888880FFFFFFFFF088880FFFFFFFFFFF08880FFFFFFFFF
          FF08880FF00FFFFFFFF0880F0880FFFFFFF0880F0880F0F0F0F088808880F0F0
          F0F000088880F0F0F0F00880880F0F0F0F080880880F0F0F0F08000880F0F0F0
          8088088888080808888808888888888888880008888888888888}
        Caption = 'Posouvat'
        ShortCut = 116
        OnClick = Posouvat1Click
      end
      object Posunout2: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          888888880000000088888880FFFFFFFF0888880FFFFFFFFF088880FFFFFFFFFF
          F08880FFFFFFFFFFF08880FF00FFFFFFFF0880F0880FFFFFFF0880F0880F0F0F
          0F088808880F0F0F0F088888880F0F0F0F08888880F0F0F0F088888880F0F0F0
          F08888880F0F0F08088888888080808888888888888888888888}
        Caption = 'Posunout'
        ShortCut = 117
        OnClick = Posunout2Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object Vybratoknem1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8800877777777777700087FFFFFFFFFF000887FFFF000FF0007887FF00FFF000
          0F7887F0FFFFFFF0FF7887F0FFF0FFF0FF78870FFFF0FFFF0F78870FF00000FF
          0F78870FFFF0FFFF0F7887F0FFF0FFF0FF7887F0FFFFFFF0FF7887FF00FFF00F
          FF7887FFFF000FFFFF7887777777777777788888888888888888}
        Caption = 'Vybrat oknem'
        ShortCut = 115
        OnClick = Vybratoknem1Click
      end
      object Ve1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8800877777777777700087FFFFFFFFFF000887FFFF000FF0007887FF00FFF000
          0F7887F0FFFFFFF0FF7887F0FFFFFFF0FF78870FFFFFFFFF0F78870FFFFFFFFF
          0F78870FFFFFFFFF0F7887F0FFFFFFF0FF7887F0FFFFFFF0FF7887FF00FFF00F
          FF7887FFFF000FFFFF7887777777777777788888888888888888}
        Caption = 'V'#353'e'
        ShortCut = 114
        OnClick = RzToolButton11Click
      end
      object Predchozipohled1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          8800888888888888800088888888888800088888888888800088888800008800
          08888800FFFF0000888880FFFFFFFF08888880FF00FFFF0888880FF000FFFFF0
          88880F00000000F088880F00000000F088880FF000FFFFF0888880FF00FFFF08
          888880FFFFFFFF0888888800FFFF008888888888000088888888}
        Caption = 'P'#345'edchoz'#237
        Enabled = False
        ShortCut = 24666
        OnClick = Predchozipohled1Click
      end
      object Obnovitobraz1: TMenuItem
        Bitmap.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888777778
          8888888877777777788888877777777777888877778888877778887778888888
          7778877788888888888887778888888888888777888888888888877788888777
          7777877788888877777788777888888777778877778888877777888777777777
          7777888877777777787788888877777888878888888888888888}
        Caption = 'Obnovit obraz'
        ShortCut = 16466
        OnClick = Obnovitobraz1Click
      end
    end
    object Knihovna1: TMenuItem
      Caption = '&Knihovna'
      Enabled = False
    end
    object Nastaven1: TMenuItem
      Caption = 'Na&staven'#237
      object Vzhled1: TMenuItem
        Caption = 'V&zhled'
        Visible = False
        object WinXP1: TMenuItem
          Caption = 'WinXP'
          OnClick = WinXP1Click
        end
        object Klasick1: TMenuItem
          Caption = 'Klasick'#233
          OnClick = Klasick1Click
        end
        object Gradientn1: TMenuItem
          Caption = 'Gradientn'#237
          OnClick = Gradientn1Click
        end
      end
      object Mrizka: TMenuItem
        AutoCheck = True
        Caption = 'M'#345#237#382'ka'
        Checked = True
        OnClick = MrizkaClick
      end
      object antialiasing1: TMenuItem
        AutoCheck = True
        Caption = 'Antialiasing'
        Checked = True
        OnClick = antialiasing1Click
      end
    end
    object Npovda1: TMenuItem
      Caption = '&N'#225'pov'#283'da'
      object Vypicestuktempu1: TMenuItem
        Caption = 'Vypi'#353' cestu k tempu'
        OnClick = Vypicestuktempu1Click
      end
    end
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 184
    Top = 32
    object Nastvitparametry1: TMenuItem
      Caption = 'Nastavit parametry'
      Visible = False
      OnClick = Nastvitparametry1Click
    end
    object Smazat1: TMenuItem
      Caption = 'Smazat objekt'
      Visible = False
      OnClick = Smazat1Click
    end
    object Zobrazitparametry1: TMenuItem
      Caption = 'Zobrazit parametry'
      Visible = False
      OnClick = Zobrazitparametry1Click
    end
    object Rychlexport1: TMenuItem
      Caption = 'Rychl'#253' export'
      Visible = False
      OnClick = Rychlexport1Click
    end
    object N5: TMenuItem
      Caption = '-'
    end
    object Posouvat2: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888880000000
        088888880FFFFFFFF0888880FFFFFFFFF088880FFFFFFFFFFF08880FFFFFFFFF
        FF08880FF00FFFFFFFF0880F0880FFFFFFF0880F0880F0F0F0F088808880F0F0
        F0F000088880F0F0F0F00880880F0F0F0F080880880F0F0F0F08000880F0F0F0
        8088088888080808888808888888888888880008888888888888}
      Caption = 'Posouvat'
      ShortCut = 116
      OnClick = Posouvat2Click
    end
    object Posunout3: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        888888880000000088888880FFFFFFFF0888880FFFFFFFFF088880FFFFFFFFFF
        F08880FFFFFFFFFFF08880FF00FFFFFFFF0880F0880FFFFFFF0880F0880F0F0F
        0F088808880F0F0F0F088888880F0F0F0F08888880F0F0F0F088888880F0F0F0
        F08888880F0F0F08088888888080808888888888888888888888}
      Caption = 'Posunout'
      ShortCut = 117
      OnClick = Posunout3Click
    end
    object Priblizit2: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8800888888888888800088888888888800088888888888800088888800008800
        08888800FFFF0000888880FFFFFFFF08888880FFF00FFF0888880FFFF00FFFF0
        88880FF000000FF088880FF000000FF088880FFFF00FFFF0888880FFF00FFF08
        888880FFFFFFFF0888888800FFFF008888888888000088888888}
      Caption = 'P'#345'ibl'#237#382'it'
      ShortCut = 118
      OnClick = Priblizit2Click
    end
    object Oddalit2: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8800888888888888800088888888888800088888888888800088888800008800
        08888800FFFF0000888880FFFFFFFF08888880FFFFFFFF0888880FFFFFFFFFF0
        88880FF000000FF088880FF000000FF088880FFFFFFFFFF0888880FFFFFFFF08
        888880FFFFFFFF0888888800FFFF008888888888000088888888}
      Caption = 'Odd'#225'lit'
      ShortCut = 119
      OnClick = Oddalit2Click
    end
    object Vybratoknem2: TMenuItem
      Bitmap.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        8800877777777777700087FFFFFFFFFF000887FFFF000FF0007887FF00FFF000
        0F7887F0FFFFFFF0FF7887F0FFF0FFF0FF78870FFFF0FFFF0F78870FF00000FF
        0F78870FFFF0FFFF0F7887F0FFF0FFF0FF7887F0FFFFFFF0FF7887FF00FFF00F
        FF7887FFFF000FFFFF7887777777777777788888888888888888}
      Caption = 'Vybrat oknem...'
      ShortCut = 115
      OnClick = Vybratoknem2Click
    end
  end
  object ImageList1: TImageList
    Left = 216
    Top = 32
    Bitmap = {
      494C010118004402440210001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000007000000001002000000000000070
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000080808000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      000000000000FFFFFF0080808000000000000000000080808000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      000000000000FFFFFF0080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000000000008080800000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF008080800000000000000000008080800000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF0080808000000000000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      000000000000000000000000000000000000000000008080800000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000FFFFFF008080800000000000000000008080800000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF00808080000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      000000000000000000000000000000000000000000008080800000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF008080800000000000000000008080800000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF00808080000000000000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00808080000000000000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00808080000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000000000000000000000000000FFFF
      FF0000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000000000000000000000000000FFFF
      FF0000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      0000FFFFFF0000000000FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      0000FFFFFF0000000000FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      0000FFFFFF0000000000FFFFFF000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF00000000000000000000000000FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF0000000000FFFFFF0000000000FFFFFF000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF0000000000FFFFFF0000000000FFFF
      FF0000000000FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF0000000000FFFFFF0000000000FFFFFF000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF0000000000FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000FFFFFF0000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFFFF000000
      0000008080000080800000808000008080000080800000808000008080000080
      8000008080000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF00000000000080800000808000008080000080800000808000008080000080
      8000008080000080800000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000808000008080000080800000808000008080000080
      8000008080000080800000808000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000008080000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000008080000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFFFF0000FF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000700000000100010000000000800300000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFFFFFFFFFFFC003C003C003C003
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D043C003D043C007DFD7C007DFD7C00FDFCFC00FDFCF
      C01FC01FC01FC01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC003C003C003C003
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D043C003D043C007DFD7C007DFD7C00FDFCFC00FDFCF
      C01FC01FC01FC01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC003C003C003C003
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D00BC003D00BC003DFFBC003DFFBC003D00BC003D00B
      C003DFFBC003DFFBC003D043C003D043C007DFD7C007DFD7C00FDFCFC00FDFCF
      C01FC01FC01FC01FFFFFFFFFFFFFFFFFFFFCFFFCFFFCFFFCFFF880008000FFF8
      FFF180018001FFF1FFE380018001FFE3F0C780018001F0C7C00F80018001C00F
      801F80018001801F801F80018001801F000F80018001000F000F80018001000F
      000F80018001000F000F80018001000F801F80018001801F801F80018001801F
      C03F80018001C03FF0FFFFFFFFFFF0FFFFFFFFFFF807FFFCFFFFF00FF003FFF8
      FFFFE007E003FFF1FFFFC007C001FFE3EFFF8003C001F0C7EF838003C000C00F
      DFC38001C600801FDFE38C01C600801FDFD38C01EE00000FEF3BDC011E00000F
      F0FFFC016C01000FFFFFF8036C01000FFFFFF803180B801FFFFFF0177D5F801F
      FFFFFABF7FFFC03FFFFFFFFF1FFFF0FFFFFFFFFFFFFFFFFFFFFFFFFFC001FFFF
      C007800F8031FFFFC00780078031FFFFC00780038031FFF7C00780018001C1F7
      C00780008001C3FBC00780008001C7FBC007800F8FF1CBFBC007800F8FF1DCF7
      C007800F8FF1FF0FC007C7F88FF1FFFFC00FFFFC8FF1FFFFC01FFFBA8FF5FFFF
      C03FFFC78001FFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object SaveDialog: TSaveDialog
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 248
    Top = 32
  end
  object OpenDialog1: TOpenDialog
    Left = 280
    Top = 32
  end
  object Timer_backup: TTimer
    Interval = 120000
    OnTimer = Timer_backupTimer
    Left = 344
    Top = 32
  end
  object SavePictureDialog1: TSavePictureDialog
    DefaultExt = '*.bmp'
    Filter = 
      'All (*.gif;*.png;*.jpg;*.jpeg;*.bmp;*.tif;*.tiff;*.ico;*.emf;*.w' +
      'mf)|*.gif;*.png;*.jpg;*.jpeg;*.bmp;*.tif;*.tiff;*.ico;*.emf;*.wm' +
      'f|GIF Image (*.gif)|*.gif|Portable Network Graphics (*.png)|*.pn' +
      'g|JPEG Image File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|' +
      'Bitmaps (*.bmp)|*.bmp|TIFF Images (*.tif)|*.tif|TIFF Images (*.t' +
      'iff)|*.tiff|Icons (*.ico)|*.ico|Enhanced Metafiles (*.emf)|*.emf' +
      '|Metafiles (*.wmf)|*.wmf'
    Left = 312
    Top = 32
  end
  object Timer_simulace: TTimer
    Enabled = False
    Interval = 17
    OnTimer = Timer_simulaceTimer
    Left = 376
    Top = 32
  end
  object Timer_neaktivity: TTimer
    Enabled = False
    OnTimer = Timer_neaktivityTimer
    Left = 408
    Top = 32
  end
  object Timer_animace: TTimer
    Enabled = False
    Interval = 40
    OnTimer = Timer_animaceTimer
    Left = 440
    Top = 32
  end
  object TeeGDIPlus1: TTeeGDIPlus
    Active = True
    AntiAliasText = gpfBest
    TeePanel = Chart1
    Left = 504
    Top = 96
  end
  object TeeGDIPlus2: TTeeGDIPlus
    Active = True
    AntiAliasText = gpfBest
    TeePanel = Chart2
    Left = 632
    Top = 96
  end
  object TeeGDIPlus3: TTeeGDIPlus
    Active = True
    AntiAliasText = gpfBest
    TeePanel = Chart3
    Left = 600
    Top = 96
  end
  object TeeGDIPlus4: TTeeGDIPlus
    Active = True
    AntiAliasText = gpfBest
    TeePanel = Chart4
    Left = 568
    Top = 96
  end
  object TeeGDIPlus5: TTeeGDIPlus
    Active = True
    AntiAliasText = gpfBest
    TeePanel = Chart6
    Left = 536
    Top = 96
  end
end
