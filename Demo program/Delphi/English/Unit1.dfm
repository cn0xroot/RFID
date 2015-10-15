object Form1: TForm1
  Left = 187
  Top = 97
  Width = 968
  Height = 649
  Caption = 'USB_READER_Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 521
    Height = 537
    ActivePage = TabSheet2
    Align = alCustom
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'System Setting'
      object GroupBox2: TGroupBox
        Left = 16
        Top = 16
        Width = 449
        Height = 241
        Caption = 'System commands'
        TabOrder = 0
        object Label36: TLabel
          Left = 8
          Top = 21
          Width = 57
          Height = 13
          Caption = 'SetSerNum:'
        end
        object Label38: TLabel
          Left = 10
          Top = 64
          Width = 67
          Height = 13
          Caption = 'ReadSerNum:'
        end
        object Label6: TLabel
          Left = 33
          Top = 111
          Width = 21
          Height = 13
          Caption = 'Led:'
        end
        object Label19: TLabel
          Left = 152
          Top = 111
          Width = 32
          Height = 13
          Caption = 'Cycle  '
        end
        object Label21: TLabel
          Left = 256
          Top = 111
          Width = 28
          Height = 13
          Caption = 'Times'
        end
        object Label22: TLabel
          Left = 256
          Top = 149
          Width = 31
          Height = 13
          Caption = 'Times '
        end
        object Label20: TLabel
          Left = 152
          Top = 151
          Width = 35
          Height = 13
          Caption = 'Cycle   '
        end
        object Label18: TLabel
          Left = 22
          Top = 153
          Width = 35
          Height = 13
          Caption = 'Buzzer:'
        end
        object Label1: TLabel
          Left = 10
          Top = 208
          Width = 86
          Height = 13
          Caption = 'GetVersionNum:   '
        end
        object Edit2: TEdit
          Left = 116
          Top = 20
          Width = 143
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 0
          Text = 'AA BB AA BB AA BB AA BB'
        end
        object ReadserNum: TButton
          Left = 360
          Top = 61
          Width = 75
          Height = 25
          Caption = 'Read serNum'
          TabOrder = 1
          OnClick = ReadserNumClick
        end
        object SetserNumumber: TButton
          Left = 360
          Top = 18
          Width = 75
          Height = 25
          Caption = 'Set serNum'
          TabOrder = 2
          OnClick = SetserNumumberClick
        end
        object ledfrq: TEdit
          Left = 109
          Top = 108
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 3
          Text = '18'
        end
        object leddur: TEdit
          Left = 212
          Top = 107
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 4
          Text = '09'
        end
        object Button2: TButton
          Left = 360
          Top = 104
          Width = 75
          Height = 25
          Caption = 'Set LED'
          TabOrder = 5
          OnClick = Button2Click
        end
        object Button1: TButton
          Left = 360
          Top = 143
          Width = 75
          Height = 25
          Caption = 'Set Buzzer'
          TabOrder = 6
          OnClick = Button1Click
        end
        object buzzerdur: TEdit
          Left = 212
          Top = 147
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 7
          Text = '09'
        end
        object buzzerfrq: TEdit
          Left = 108
          Top = 147
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 8
          Text = '18'
        end
        object Button8: TButton
          Left = 360
          Top = 208
          Width = 75
          Height = 25
          Caption = 'GetVersion'
          TabOrder = 9
          OnClick = Button8Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = '14443A-MF'
      ImageIndex = 1
      object GroupBox8: TGroupBox
        Left = 14
        Top = 16
        Width = 491
        Height = 489
        Caption = 'Type A'
        TabOrder = 0
        object Label7: TLabel
          Left = 3
          Top = 21
          Width = 29
          Height = 13
          Caption = 'Read:'
        end
        object Label10: TLabel
          Left = 252
          Top = 20
          Width = 55
          Height = 13
          Caption = 'Read mode'
        end
        object Label11: TLabel
          Left = 164
          Top = 80
          Width = 119
          Height = 13
          Caption = 'The Six Bytes Block Key '
        end
        object Label12: TLabel
          Left = 76
          Top = 52
          Width = 177
          Height = 13
          Caption = 'The Start Adress of Blocks to be read'
        end
        object Label9: TLabel
          Left = 310
          Top = 51
          Width = 133
          Height = 13
          Caption = 'number of Blocks to be read'
        end
        object Label13: TLabel
          Left = 251
          Top = 118
          Width = 54
          Height = 13
          Caption = 'Write mode'
        end
        object Label16: TLabel
          Left = 164
          Top = 183
          Width = 119
          Height = 13
          Caption = 'The Six Bytes Block Key '
        end
        object Label15: TLabel
          Left = 81
          Top = 154
          Width = 177
          Height = 13
          Caption = 'The Start Adress of Blocks to be read'
        end
        object Label14: TLabel
          Left = 307
          Top = 156
          Width = 133
          Height = 13
          Caption = 'number of Blocks to be read'
        end
        object Label8: TLabel
          Left = 4
          Top = 119
          Width = 28
          Height = 13
          Caption = 'Write:'
        end
        object Label17: TLabel
          Left = 363
          Top = 235
          Width = 125
          Height = 13
          Caption = 'The Data for Write to Card'
        end
        object Label74: TLabel
          Left = 6
          Top = 314
          Width = 57
          Height = 13
          Caption = 'Decrementl:'
        end
        object Label78: TLabel
          Left = 5
          Top = 387
          Width = 50
          Height = 13
          Caption = 'Increment:'
        end
        object Label81: TLabel
          Left = 1
          Top = 467
          Width = 54
          Height = 13
          Caption = 'GET_SNR:'
        end
        object Label70: TLabel
          Left = 12
          Top = 247
          Width = 47
          Height = 13
          Caption = 'InitVal:     '
        end
        object Label30: TLabel
          Left = 176
          Top = 280
          Width = 27
          Height = 13
          Caption = 'KEY  '
        end
        object Label31: TLabel
          Left = 176
          Top = 352
          Width = 27
          Height = 13
          Caption = 'KEY  '
        end
        object Label33: TLabel
          Left = 176
          Top = 424
          Width = 27
          Height = 13
          Caption = 'KEY  '
        end
        object Label37: TLabel
          Left = 304
          Top = 248
          Width = 40
          Height = 13
          Caption = 'Sector   '
        end
        object Label39: TLabel
          Left = 296
          Top = 320
          Width = 40
          Height = 13
          Caption = 'Sector   '
        end
        object Label40: TLabel
          Left = 296
          Top = 392
          Width = 40
          Height = 13
          Caption = 'Sector   '
        end
        object Label41: TLabel
          Left = 336
          Top = 280
          Width = 33
          Height = 13
          Caption = 'Value  '
        end
        object Label42: TLabel
          Left = 336
          Top = 352
          Width = 33
          Height = 13
          Caption = 'Value  '
        end
        object Label43: TLabel
          Left = 336
          Top = 424
          Width = 33
          Height = 13
          Caption = 'Value  '
        end
        object GroupBox4: TGroupBox
          Left = 38
          Top = 10
          Width = 100
          Height = 33
          TabOrder = 0
          object reqa: TRadioButton
            Left = 51
            Top = 10
            Width = 35
            Height = 17
            Caption = 'All'
            TabOrder = 0
          end
          object reqi: TRadioButton
            Left = 4
            Top = 10
            Width = 39
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
        end
        object GroupBox5: TGroupBox
          Left = 136
          Top = 10
          Width = 105
          Height = 33
          TabOrder = 1
          object keyb: TRadioButton
            Left = 54
            Top = 10
            Width = 48
            Height = 17
            Caption = 'Key B'
            TabOrder = 0
          end
          object keya: TRadioButton
            Left = 4
            Top = 10
            Width = 50
            Height = 17
            Caption = 'Key A'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
        end
        object Button3: TButton
          Left = 406
          Top = 10
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 2
          OnClick = Button3Click
        end
        object ComboBox4: TComboBox
          Left = 38
          Top = 76
          Width = 119
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 3
          Text = 'FF FF FF FF FF FF'
          Items.Strings = (
            'A0 A1 A2 A3 A4 A5'
            'B0 B1 B2 B3 B4 B5'
            'FF FF FF FF FF FF')
        end
        object ComboBox6: TComboBox
          Left = 267
          Top = 47
          Width = 40
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 4
          Text = '01'
          Items.Strings = (
            '01'
            '02'
            '03'
            '04')
        end
        object ComboBox5: TComboBox
          Left = 39
          Top = 49
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 5
          Text = '10'
          Items.Strings = (
            '00'
            '01'
            '02'
            '03'
            '04'
            '05'
            '06'
            '07'
            '08'
            '09'
            '10'
            '11'
            '12'
            '13'
            '14'
            '15')
        end
        object Panel1: TPanel
          Left = 38
          Top = 103
          Width = 463
          Height = 3
          TabOrder = 6
        end
        object GroupBox6: TGroupBox
          Left = 37
          Top = 108
          Width = 100
          Height = 33
          TabOrder = 7
          object reqaa: TRadioButton
            Left = 51
            Top = 10
            Width = 35
            Height = 17
            Caption = 'All'
            TabOrder = 0
          end
          object reqii: TRadioButton
            Left = 4
            Top = 10
            Width = 39
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
        end
        object GroupBox7: TGroupBox
          Left = 135
          Top = 108
          Width = 105
          Height = 33
          TabOrder = 8
          object keybb: TRadioButton
            Left = 54
            Top = 10
            Width = 48
            Height = 17
            Caption = 'Key B'
            TabOrder = 0
          end
          object keyaa: TRadioButton
            Left = 4
            Top = 10
            Width = 50
            Height = 17
            Caption = 'Key A'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
        end
        object Button4: TButton
          Left = 406
          Top = 111
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 9
          OnClick = Button4Click
        end
        object ComboBox9: TComboBox
          Left = 38
          Top = 179
          Width = 119
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 10
          Text = 'FF FF FF FF FF FF'
          Items.Strings = (
            'A0 A1 A2 A3 A4 A5'
            'B0 B1 B2 B3 B4 B5'
            'FF FF FF FF FF FF')
        end
        object ComboBox8: TComboBox
          Left = 262
          Top = 153
          Width = 42
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 11
          Text = '05'
          Items.Strings = (
            '01'
            '02'
            '03'
            '04')
        end
        object ComboBox7: TComboBox
          Left = 38
          Top = 151
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          ItemHeight = 13
          TabOrder = 12
          Text = '80'
          Items.Strings = (
            '00'
            '01'
            '02'
            '03'
            '04'
            '05'
            '06'
            '07'
            '08'
            '09'
            '10'
            '11'
            '12'
            '13'
            '14'
            '15')
        end
        object Edit3: TEdit
          Left = 38
          Top = 206
          Width = 443
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
          TabOrder = 13
          Text = 
            'FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF  FF FF FF FF FF ' +
            'FF FF FF FF FF FF FF FF FF FF FF   FF FF FF FF FF FF FF FF FF FF' +
            ' FF FF FF FF FF FF   FF FF FF FF FF FF FF FF FF FF FF FF FF FF F' +
            'F FF   FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF'
        end
        object Panel65: TPanel
          Left = 66
          Top = 307
          Width = 86
          Height = 31
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 14
          object reql3: TRadioButton
            Left = 2
            Top = 8
            Width = 43
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object reqa3: TRadioButton
            Left = 50
            Top = 7
            Width = 34
            Height = 17
            Caption = 'All'
            TabOrder = 1
          end
        end
        object Panel66: TPanel
          Left = 158
          Top = 307
          Width = 106
          Height = 31
          TabOrder = 15
          object keya3: TRadioButton
            Left = 1
            Top = 8
            Width = 52
            Height = 17
            Caption = 'key A'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object keyb3: TRadioButton
            Left = 57
            Top = 7
            Width = 48
            Height = 17
            Caption = 'key B'
            TabOrder = 1
          end
        end
        object Edit62: TEdit
          Left = 267
          Top = 315
          Width = 25
          Height = 21
          TabOrder = 16
          Text = '04'
        end
        object Edit63: TEdit
          Left = 69
          Top = 347
          Width = 96
          Height = 21
          TabOrder = 17
          Text = 'FF FF FF FF FF FF'
        end
        object Edit64: TEdit
          Left = 264
          Top = 346
          Width = 65
          Height = 21
          TabOrder = 18
          Text = '01 00 00 00'
        end
        object Button27: TButton
          Left = 406
          Top = 310
          Width = 75
          Height = 25
          Caption = 'Devalue'
          TabOrder = 19
          OnClick = Button27Click
        end
        object Button28: TButton
          Left = 406
          Top = 416
          Width = 75
          Height = 25
          Caption = 'Addvalue'
          TabOrder = 20
          OnClick = Button28Click
        end
        object Edit68: TEdit
          Left = 263
          Top = 419
          Width = 65
          Height = 21
          TabOrder = 21
          Text = '01 00 00 00'
        end
        object Edit67: TEdit
          Left = 68
          Top = 420
          Width = 96
          Height = 21
          TabOrder = 22
          Text = 'FF FF FF FF FF FF'
        end
        object Edit66: TEdit
          Left = 266
          Top = 388
          Width = 25
          Height = 21
          TabOrder = 23
          Text = '04'
        end
        object Panel69: TPanel
          Left = 157
          Top = 380
          Width = 106
          Height = 31
          TabOrder = 24
          object keya4: TRadioButton
            Left = 1
            Top = 8
            Width = 52
            Height = 17
            Caption = 'key A'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object keyb4: TRadioButton
            Left = 57
            Top = 7
            Width = 48
            Height = 17
            Caption = 'key B'
            TabOrder = 1
          end
        end
        object Panel68: TPanel
          Left = 65
          Top = 380
          Width = 84
          Height = 31
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 25
          object reql4: TRadioButton
            Left = 2
            Top = 8
            Width = 43
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object reqa4: TRadioButton
            Left = 50
            Top = 7
            Width = 32
            Height = 17
            Caption = 'All'
            TabOrder = 1
          end
        end
        object Panel71: TPanel
          Left = 65
          Top = 453
          Width = 84
          Height = 31
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 26
          object reql5: TRadioButton
            Left = 2
            Top = 8
            Width = 43
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object reqa5: TRadioButton
            Left = 50
            Top = 7
            Width = 33
            Height = 17
            Caption = 'All'
            TabOrder = 1
          end
        end
        object Panel72: TPanel
          Left = 157
          Top = 453
          Width = 106
          Height = 31
          TabOrder = 27
          object nohalt: TRadioButton
            Left = 1
            Top = 8
            Width = 52
            Height = 17
            Caption = 'no halt'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object yeshalt: TRadioButton
            Left = 57
            Top = 7
            Width = 45
            Height = 17
            Caption = 'halt'
            TabOrder = 1
          end
        end
        object Button29: TButton
          Left = 406
          Top = 460
          Width = 75
          Height = 25
          Caption = 'card number'
          TabOrder = 28
          OnClick = Button29Click
        end
        object Panel2: TPanel
          Left = 38
          Top = 231
          Width = 465
          Height = 3
          TabOrder = 29
        end
        object Panel3: TPanel
          Left = 30
          Top = 301
          Width = 473
          Height = 3
          TabOrder = 30
        end
        object Panel4: TPanel
          Left = 34
          Top = 373
          Width = 473
          Height = 3
          TabOrder = 31
        end
        object Panel5: TPanel
          Left = 10
          Top = 445
          Width = 473
          Height = 3
          TabOrder = 32
        end
        object Panel63: TPanel
          Left = 67
          Top = 237
          Width = 86
          Height = 31
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 33
          object reql2: TRadioButton
            Left = 2
            Top = 8
            Width = 43
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object reqa2: TRadioButton
            Left = 50
            Top = 7
            Width = 35
            Height = 17
            Caption = 'All'
            TabOrder = 1
          end
        end
        object Panel64: TPanel
          Left = 159
          Top = 237
          Width = 106
          Height = 31
          TabOrder = 34
          object keya2: TRadioButton
            Left = 1
            Top = 8
            Width = 52
            Height = 17
            Caption = 'key A'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object keyb2: TRadioButton
            Left = 57
            Top = 7
            Width = 47
            Height = 17
            Caption = 'key B'
            TabOrder = 1
          end
        end
        object Edit57: TEdit
          Left = 268
          Top = 245
          Width = 25
          Height = 21
          TabOrder = 35
          Text = '04'
        end
        object Edit58: TEdit
          Left = 70
          Top = 277
          Width = 96
          Height = 21
          TabOrder = 36
          Text = 'FF FF FF FF FF FF'
        end
        object Edit59: TEdit
          Left = 265
          Top = 276
          Width = 65
          Height = 21
          TabOrder = 37
          Text = '64 00 00 00'
        end
        object Button26: TButton
          Left = 406
          Top = 251
          Width = 75
          Height = 25
          Caption = 'initialization'
          TabOrder = 38
          OnClick = Button26Click
        end
        object CheckBox1: TCheckBox
          Left = 408
          Top = 72
          Width = 65
          Height = 17
          Caption = 'AUTO'
          TabOrder = 39
          OnClick = CheckBox1Click
        end
        object CheckBox2: TCheckBox
          Left = 408
          Top = 176
          Width = 66
          Height = 17
          Caption = 'AUTO'
          TabOrder = 40
          OnClick = CheckBox2Click
        end
        object CheckBox3: TCheckBox
          Left = 328
          Top = 462
          Width = 65
          Height = 17
          Caption = 'AUTO'
          TabOrder = 41
          OnClick = CheckBox3Click
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Ultralight'
      ImageIndex = 4
      object GroupBox9: TGroupBox
        Left = 8
        Top = 16
        Width = 457
        Height = 105
        TabOrder = 0
        object Label105: TLabel
          Left = 8
          Top = 24
          Width = 131
          Height = 13
          Caption = 'Read  Card series number:  '
        end
        object Label34: TLabel
          Left = 28
          Top = 57
          Width = 22
          Height = 13
          Caption = 'Halt:'
        end
        object Button55: TButton
          Left = 366
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 0
          OnClick = Button55Click
        end
        object Button17: TButton
          Left = 366
          Top = 56
          Width = 75
          Height = 25
          Caption = 'Halt'
          TabOrder = 1
          OnClick = Button17Click
        end
        object Panel9: TPanel
          Left = -90
          Top = 87
          Width = 555
          Height = 3
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 2
        end
        object Panel16: TPanel
          Left = -90
          Top = 47
          Width = 555
          Height = 3
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 3
        end
        object GroupBox23: TGroupBox
          Left = 142
          Top = 10
          Width = 100
          Height = 33
          TabOrder = 4
          object Ula: TRadioButton
            Left = 51
            Top = 10
            Width = 35
            Height = 17
            Caption = 'All'
            TabOrder = 0
          end
          object Uli: TRadioButton
            Left = 4
            Top = 10
            Width = 39
            Height = 17
            Caption = 'Idle'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
        end
      end
      object GroupBox18: TGroupBox
        Left = 8
        Top = 134
        Width = 457
        Height = 374
        Caption = 'Ultralight '#21345#35835#20889
        TabOrder = 1
        object GroupBox19: TGroupBox
          Left = 16
          Top = 17
          Width = 201
          Height = 344
          Align = alCustom
          Caption = ' '#35835#21345' '
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 0
          object Label106: TLabel
            Left = 8
            Top = 15
            Width = 36
            Height = 13
            Caption = #25159#21306#65306
          end
          object Button18: TButton
            Left = 116
            Top = 307
            Width = 75
            Height = 25
            Caption = #35835#21345
            TabOrder = 0
            OnClick = Button18Click
          end
          object GroupBox24: TGroupBox
            Left = 13
            Top = 298
            Width = 100
            Height = 33
            TabOrder = 1
            object Ulaa: TRadioButton
              Left = 51
              Top = 10
              Width = 35
              Height = 17
              Caption = 'All'
              TabOrder = 0
            end
            object Ulii: TRadioButton
              Left = 4
              Top = 10
              Width = 39
              Height = 17
              Caption = 'Idle'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
          end
          object ListBox1: TListBox
            Left = 12
            Top = 31
            Width = 101
            Height = 258
            Cursor = crHandPoint
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clInfoText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 16
            Items.Strings = (
              '00'
              '01'
              '02'
              '03'
              '04'
              '05'
              '06'
              '07'
              '08'
              '09'
              '10'
              '11'
              '12'
              '13'
              '14'
              '15')
            ParentFont = False
            TabOrder = 2
          end
        end
        object GroupBox20: TGroupBox
          Left = 256
          Top = 17
          Width = 193
          Height = 344
          Align = alCustom
          Caption = ' '#20889#21345' '
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 1
          object Label104: TLabel
            Left = 8
            Top = 18
            Width = 36
            Height = 13
            Caption = #25159#21306#65306
          end
          object Button54: TButton
            Left = 112
            Top = 309
            Width = 75
            Height = 25
            Caption = 'Write'
            TabOrder = 0
            OnClick = Button54Click
          end
          object Edit56: TEdit
            Left = 112
            Top = 272
            Width = 74
            Height = 19
            TabOrder = 1
            Text = '00 00 00 00'
          end
          object GroupBox25: TGroupBox
            Left = 8
            Top = 298
            Width = 100
            Height = 33
            TabOrder = 2
            object Ulaaa: TRadioButton
              Left = 51
              Top = 10
              Width = 35
              Height = 17
              Caption = 'All'
              TabOrder = 0
            end
            object Uliii: TRadioButton
              Left = 4
              Top = 10
              Width = 39
              Height = 17
              Caption = 'Idle'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
          end
          object ListBox2: TListBox
            Left = 10
            Top = 35
            Width = 97
            Height = 258
            Cursor = crHandPoint
            Color = clSkyBlue
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clInfoText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ItemHeight = 16
            Items.Strings = (
              '00'
              '01'
              '02'
              '03'
              '04'
              '05'
              '06'
              '07'
              '08'
              '09'
              '10'
              '11'
              '12'
              '13'
              '14'
              '15')
            ParentFont = False
            TabOrder = 3
          end
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = '14443 B'
      ImageIndex = 3
      object GroupBox11: TGroupBox
        Left = 8
        Top = 16
        Width = 497
        Height = 241
        Caption = '14443B Commands'
        TabOrder = 0
        object Label88: TLabel
          Left = 144
          Top = 120
          Width = 135
          Height = 13
          Caption = 'the datalength for sending'#65306
        end
        object Label87: TLabel
          Left = 24
          Top = 192
          Width = 33
          Height = 13
          Caption = 'data'#65306
        end
        object Label28: TLabel
          Left = 24
          Top = 24
          Width = 103
          Height = 13
          Caption = 'Request_Typeb'#65306'     '
        end
        object Edit78: TEdit
          Left = 17
          Top = 112
          Width = 121
          Height = 21
          Hint = 'datalength'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Text = '08'
        end
        object Edit77: TEdit
          Left = 16
          Top = 166
          Width = 465
          Height = 21
          Hint = 'data'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          Text = '00 00 05 00 84 00 00 08'
        end
        object Button36: TButton
          Left = 378
          Top = 201
          Width = 87
          Height = 25
          Caption = 'Typeb_Transfer'
          TabOrder = 2
        end
        object Panel10: TPanel
          Left = 10
          Top = 87
          Width = 504
          Height = 3
          TabOrder = 3
        end
        object Button31: TButton
          Left = 378
          Top = 21
          Width = 87
          Height = 25
          Caption = 'Request'
          TabOrder = 4
          OnClick = Button31Click
        end
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 264
        Width = 497
        Height = 233
        Caption = 'China  identity card UID'
        TabOrder = 1
        object Button7: TButton
          Left = 384
          Top = 24
          Width = 75
          Height = 25
          Caption = 'SFZ UID'
          TabOrder = 0
          OnClick = Button7Click
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = '15693'
      ImageIndex = 2
      object GroupBox10: TGroupBox
        Left = 8
        Top = 8
        Width = 505
        Height = 433
        Caption = '15693 commands'
        TabOrder = 0
        object Label23: TLabel
          Left = 16
          Top = 40
          Width = 62
          Height = 13
          Caption = '  Inventory :  '
        end
        object Label26: TLabel
          Left = 13
          Top = 93
          Width = 38
          Height = 13
          Caption = 'Read'#65306
        end
        object Label24: TLabel
          Left = 123
          Top = 91
          Width = 17
          Height = 13
          Caption = 'flag'
        end
        object Label25: TLabel
          Left = 198
          Top = 90
          Width = 46
          Height = 13
          Caption = 'Start area'
        end
        object Label29: TLabel
          Left = 297
          Top = 90
          Width = 35
          Height = 13
          Caption = 'number'
        end
        object Label27: TLabel
          Left = 303
          Top = 213
          Width = 83
          Height = 13
          Caption = 'The data for write'
        end
        object Label72: TLabel
          Left = 297
          Top = 174
          Width = 35
          Height = 13
          Caption = 'number'
        end
        object Label48: TLabel
          Left = 198
          Top = 170
          Width = 46
          Height = 13
          Caption = 'Start area'
        end
        object Label35: TLabel
          Left = 123
          Top = 171
          Width = 17
          Height = 13
          Caption = 'flag'
        end
        object Label32: TLabel
          Left = 14
          Top = 167
          Width = 37
          Height = 13
          Caption = 'Write'#65306
        end
        object Label44: TLabel
          Left = 16
          Top = 256
          Width = 121
          Height = 13
          Caption = 'Get System Information :  '
        end
        object Label45: TLabel
          Left = 123
          Top = 297
          Width = 17
          Height = 13
          Caption = 'flag'
        end
        object Label46: TLabel
          Left = 312
          Top = 302
          Width = 28
          Height = 13
          Caption = 'UID   '
        end
        object Panel8: TPanel
          Left = 30
          Top = 247
          Width = 463
          Height = 3
          TabOrder = 0
        end
        object Panel7: TPanel
          Left = 30
          Top = 143
          Width = 463
          Height = 3
          TabOrder = 1
        end
        object Panel6: TPanel
          Left = 30
          Top = 71
          Width = 463
          Height = 3
          TabOrder = 2
        end
        object Button6: TButton
          Left = 392
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Inventory'
          TabOrder = 3
          OnClick = Button6Click
        end
        object flagr: TEdit
          Left = 83
          Top = 87
          Width = 33
          Height = 21
          TabOrder = 4
          Text = '02'
        end
        object startr: TEdit
          Left = 158
          Top = 87
          Width = 34
          Height = 21
          TabOrder = 5
          Text = '01'
        end
        object numberr: TEdit
          Left = 256
          Top = 87
          Width = 33
          Height = 21
          TabOrder = 6
          Text = '05'
        end
        object Button38: TButton
          Left = 389
          Top = 85
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 7
          OnClick = Button38Click
        end
        object Button39: TButton
          Left = 389
          Top = 161
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 8
          OnClick = Button39Click
        end
        object dataw: TEdit
          Left = 80
          Top = 211
          Width = 217
          Height = 21
          TabOrder = 9
          Text = '11 11 11 11'
        end
        object numberw: TEdit
          Left = 256
          Top = 167
          Width = 33
          Height = 21
          TabOrder = 10
          Text = '01'
        end
        object startw: TEdit
          Left = 158
          Top = 167
          Width = 34
          Height = 21
          TabOrder = 11
          Text = '05'
        end
        object flagw: TEdit
          Left = 83
          Top = 167
          Width = 33
          Height = 21
          TabOrder = 12
          Text = '42'
        end
        object Button5: TButton
          Left = 392
          Top = 256
          Width = 75
          Height = 25
          Caption = 'Get'
          Enabled = False
          TabOrder = 13
        end
        object Panel11: TPanel
          Left = 30
          Top = 327
          Width = 463
          Height = 3
          TabOrder = 14
        end
        object Edit4: TEdit
          Left = 83
          Top = 293
          Width = 33
          Height = 21
          TabOrder = 15
          Text = '42'
        end
        object Edit5: TEdit
          Left = 160
          Top = 294
          Width = 137
          Height = 21
          TabOrder = 16
        end
      end
    end
  end
  object GroupBox3: TGroupBox
    Left = 544
    Top = 16
    Width = 391
    Height = 521
    Caption = 'Data'
    TabOrder = 1
    object showm: TRichEdit
      Left = 8
      Top = 16
      Width = 377
      Height = 497
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = #40657#20307
      Font.Style = [fsBold]
      HideSelection = False
      ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
      ParentFont = False
      PopupMenu = PopupMenu1
      ScrollBars = ssBoth
      TabOrder = 0
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 567
    Width = 960
    Height = 28
    Panels = <>
  end
  object PopupMenu1: TPopupMenu
    Left = 584
    object Clear1: TMenuItem
      Caption = 'Clear'
      OnClick = Clear1Click
    end
    object Save1: TMenuItem
      Caption = 'Save'
      OnClick = Save1Click
    end
    object SelectAll1: TMenuItem
      Caption = 'Select All'
      OnClick = SelectAll1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Copy1: TMenuItem
      Caption = 'Copy'
      OnClick = Copy1Click
    end
    object Paste1: TMenuItem
      Caption = 'Paste'
      OnClick = Paste1Click
    end
    object Cut1: TMenuItem
      Caption = 'Cut'
      OnClick = Cut1Click
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 616
  end
  object Timer1: TTimer
    Enabled = False
    Left = 656
  end
  object MainMenu1: TMainMenu
    Left = 787
    Top = 104
    object MenuItem1: TMenuItem
      Caption = 'System'
      object N4: TMenuItem
        Caption = 'Exit'
        OnClick = N4Click
      end
    end
    object N3: TMenuItem
      Caption = 'Style'
      object N11: TMenuItem
        Caption = 'Style 1'
      end
      object N12: TMenuItem
        Caption = 'Style 2'
      end
      object N13: TMenuItem
        Caption = 'Style 3'
      end
      object N14: TMenuItem
        Caption = 'Style 4'
      end
      object N51: TMenuItem
        Caption = 'Style 5'
      end
      object N61: TMenuItem
        Caption = 'Style 6'
      end
    end
    object N2: TMenuItem
      Caption = 'About'
      object N5: TMenuItem
        Caption = 'About DEMO'
        OnClick = N5Click
      end
      object COM1: TMenuItem
        Caption = 'COM Setting'
      end
      object N10: TMenuItem
        Caption = 'System Setting'
      end
      object S50S701: TMenuItem
        Caption = 'S50/S70'
      end
      object Ultralight1: TMenuItem
        Caption = 'Ultralight'
      end
      object ISO14443B1: TMenuItem
        Caption = 'ISO14443B'
      end
      object ISO156931: TMenuItem
        Caption = 'ISO15693'
      end
    end
  end
end
