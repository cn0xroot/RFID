VERSION 5.00
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form RFID_DEMO 
   Caption         =   "RFID DEMO"
   ClientHeight    =   10890
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   15315
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   Picture         =   "SSTab.frx":0000
   ScaleHeight     =   10890
   ScaleWidth      =   15315
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame Frame12 
      Caption         =   "RFID"
      Height          =   10815
      Left            =   120
      TabIndex        =   4
      Top             =   0
      Width           =   9255
      Begin TabDlg.SSTab SSTab1 
         Height          =   10335
         Left            =   120
         TabIndex        =   0
         Top             =   480
         Width           =   9015
         _ExtentX        =   15901
         _ExtentY        =   18230
         _Version        =   393216
         Style           =   1
         Tabs            =   6
         TabsPerRow      =   9
         TabHeight       =   520
         TabCaption(0)   =   "&System Seting"
         TabPicture(0)   =   "SSTab.frx":0342
         Tab(0).ControlEnabled=   -1  'True
         Tab(0).Control(0)=   "from1"
         Tab(0).Control(0).Enabled=   0   'False
         Tab(0).Control(1)=   "Frame23"
         Tab(0).Control(1).Enabled=   0   'False
         Tab(0).ControlCount=   2
         TabCaption(1)   =   "Debug"
         TabPicture(1)   =   "SSTab.frx":035E
         Tab(1).ControlEnabled=   0   'False
         Tab(1).ControlCount=   0
         TabCaption(2)   =   "&ISO14443A"
         TabPicture(2)   =   "SSTab.frx":037A
         Tab(2).ControlEnabled=   0   'False
         Tab(2).Control(0)=   "Frame36"
         Tab(2).Control(1)=   "Frame29"
         Tab(2).Control(2)=   "Frame28"
         Tab(2).Control(3)=   "Frame27"
         Tab(2).Control(4)=   "Frame2"
         Tab(2).Control(5)=   "Frame1"
         Tab(2).ControlCount=   6
         TabCaption(3)   =   "&ISO14443B"
         TabPicture(3)   =   "SSTab.frx":0396
         Tab(3).ControlEnabled=   0   'False
         Tab(3).Control(0)=   "Frame14"
         Tab(3).ControlCount=   1
         TabCaption(4)   =   "&ISO15693"
         TabPicture(4)   =   "SSTab.frx":03B2
         Tab(4).ControlEnabled=   0   'False
         Tab(4).Control(0)=   "Frame44"
         Tab(4).Control(1)=   "Frame7"
         Tab(4).ControlCount=   2
         TabCaption(5)   =   "&Ultralight"
         TabPicture(5)   =   "SSTab.frx":03CE
         Tab(5).ControlEnabled=   0   'False
         Tab(5).Control(0)=   "Frame20"
         Tab(5).Control(1)=   "Frame19"
         Tab(5).Control(2)=   "Frame18"
         Tab(5).ControlCount=   3
         Begin VB.Frame Frame44 
            Caption         =   "Block Security"
            Height          =   1455
            Left            =   -74520
            TabIndex        =   201
            Top             =   8760
            Width           =   8055
            Begin VB.TextBox txtBlockUID 
               Height          =   375
               Left            =   120
               TabIndex        =   209
               Top             =   840
               Width           =   4695
            End
            Begin VB.TextBox txtBlockNum 
               Height          =   375
               Left            =   4200
               TabIndex        =   207
               Top             =   360
               Width           =   1095
            End
            Begin VB.CommandButton cmdGetBlock 
               Caption         =   "Get"
               Enabled         =   0   'False
               Height          =   375
               Left            =   6240
               TabIndex        =   204
               Top             =   360
               Width           =   1215
            End
            Begin VB.TextBox txtBlockStart 
               Height          =   375
               Left            =   1440
               TabIndex        =   203
               Top             =   360
               Width           =   735
            End
            Begin VB.TextBox txtBlockFlag 
               Height          =   375
               Left            =   120
               TabIndex        =   202
               Text            =   "42"
               Top             =   360
               Width           =   615
            End
            Begin VB.Label Label58 
               Caption         =   "UID"
               Height          =   375
               Left            =   5040
               TabIndex        =   210
               Top             =   840
               Width           =   1455
            End
            Begin VB.Label Label57 
               Caption         =   "Number"
               Height          =   375
               Left            =   5400
               TabIndex        =   208
               Top             =   360
               Width           =   855
            End
            Begin VB.Label Label56 
               Caption         =   "Start Area"
               Height          =   375
               Left            =   2640
               TabIndex        =   206
               Top             =   360
               Width           =   1455
            End
            Begin VB.Label Label55 
               Caption         =   "Flag"
               Height          =   375
               Left            =   840
               TabIndex        =   205
               Top             =   360
               Width           =   735
            End
         End
         Begin VB.Frame Frame36 
            Caption         =   "GET_SNR"
            Height          =   855
            Left            =   -74880
            TabIndex        =   161
            Top             =   8520
            Width           =   8775
            Begin VB.CommandButton cmdcard 
               Caption         =   "card number"
               Height          =   495
               Left            =   6960
               TabIndex        =   168
               Top             =   240
               Width           =   1575
            End
            Begin VB.Frame Frame38 
               Height          =   615
               Left            =   1320
               TabIndex        =   165
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton opcardAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   167
                  Top             =   240
                  Width           =   615
               End
               Begin VB.OptionButton Option17 
                  Caption         =   "Idle"
                  Height          =   240
                  Left            =   120
                  TabIndex        =   166
                  Top             =   240
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Frame Frame37 
               Height          =   735
               Left            =   3240
               TabIndex        =   162
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opcardKeyA 
                  Caption         =   "no half"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   164
                  Top             =   360
                  UseMaskColor    =   -1  'True
                  Value           =   -1  'True
                  Width           =   1095
               End
               Begin VB.OptionButton opcardKeyB 
                  Caption         =   "half"
                  Height          =   375
                  Left            =   1320
                  TabIndex        =   163
                  Top             =   240
                  Width           =   975
               End
            End
         End
         Begin VB.Frame Frame29 
            Caption         =   "Increment"
            Height          =   1335
            Left            =   -74880
            TabIndex        =   118
            Top             =   7080
            Width           =   8775
            Begin VB.CommandButton cmdAddvalue 
               Caption         =   "Addvalue"
               Height          =   495
               Left            =   7320
               TabIndex        =   160
               Top             =   720
               Width           =   1215
            End
            Begin VB.TextBox txtAddvalueSector 
               Height          =   375
               Left            =   5760
               TabIndex        =   156
               Text            =   "01"
               Top             =   360
               Width           =   615
            End
            Begin VB.TextBox txAddvaluekey 
               Height          =   375
               Left            =   480
               TabIndex        =   155
               Text            =   "FF FF FF FF FF FF"
               Top             =   840
               Width           =   2055
            End
            Begin VB.TextBox txtAddvalueValue 
               Height          =   375
               Left            =   4560
               TabIndex        =   154
               Text            =   "01 00 00 00"
               Top             =   840
               Width           =   1575
            End
            Begin VB.Frame Frame35 
               Height          =   615
               Left            =   1320
               TabIndex        =   134
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton Option14 
                  Caption         =   "Idle"
                  Height          =   240
                  Left            =   120
                  TabIndex        =   136
                  Top             =   240
                  UseMaskColor    =   -1  'True
                  Width           =   855
               End
               Begin VB.OptionButton opincrementAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   135
                  Top             =   240
                  Width           =   615
               End
            End
            Begin VB.Frame Frame34 
               Height          =   735
               Left            =   3240
               TabIndex        =   131
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opaddvalueKeyB 
                  Caption         =   "KeyB"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   133
                  Top             =   240
                  Width           =   975
               End
               Begin VB.OptionButton opaddvalueKeyA 
                  Caption         =   "KeyA"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   132
                  Top             =   360
                  UseMaskColor    =   -1  'True
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Label Label48 
               Caption         =   "Sector"
               Height          =   375
               Left            =   6480
               TabIndex        =   159
               Top             =   360
               Width           =   735
            End
            Begin VB.Label Label47 
               Caption         =   "KEY"
               Height          =   375
               Left            =   2760
               TabIndex        =   158
               Top             =   840
               Width           =   1095
            End
            Begin VB.Label Label46 
               Caption         =   "Value"
               Height          =   375
               Left            =   6240
               TabIndex        =   157
               Top             =   840
               Width           =   735
            End
         End
         Begin VB.Frame Frame28 
            Caption         =   "Decrementl"
            Height          =   1335
            Left            =   -74880
            TabIndex        =   117
            Top             =   5760
            Width           =   8775
            Begin VB.CommandButton cmdDevalue 
               Caption         =   "Devalue"
               Height          =   495
               Left            =   7320
               TabIndex        =   153
               Top             =   720
               Width           =   1215
            End
            Begin VB.TextBox txtDevalueSector 
               Height          =   375
               Left            =   5760
               TabIndex        =   149
               Text            =   "01"
               Top             =   360
               Width           =   615
            End
            Begin VB.TextBox txtDevaluekey 
               Height          =   375
               Left            =   480
               TabIndex        =   148
               Text            =   "FF FF FF FF FF FF"
               Top             =   840
               Width           =   2055
            End
            Begin VB.TextBox txtDevalueValue 
               Height          =   375
               Left            =   4560
               TabIndex        =   147
               Text            =   "01 00 00 00"
               Top             =   840
               Width           =   1575
            End
            Begin VB.Frame Frame33 
               Height          =   615
               Left            =   1320
               TabIndex        =   128
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton Option10 
                  Caption         =   "Idle"
                  Height          =   240
                  Left            =   120
                  TabIndex        =   130
                  Top             =   240
                  UseMaskColor    =   -1  'True
                  Width           =   855
               End
               Begin VB.OptionButton opdevalueAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   129
                  Top             =   240
                  Width           =   615
               End
            End
            Begin VB.Frame Frame32 
               Height          =   735
               Left            =   3240
               TabIndex        =   125
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opdevalueKeyB 
                  Caption         =   "KeyB"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   127
                  Top             =   240
                  Width           =   975
               End
               Begin VB.OptionButton opdevalueKeyA 
                  Caption         =   "KeyA"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   126
                  Top             =   360
                  UseMaskColor    =   -1  'True
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Label Label45 
               Caption         =   "Sector"
               Height          =   375
               Left            =   6480
               TabIndex        =   152
               Top             =   360
               Width           =   735
            End
            Begin VB.Label Label44 
               Caption         =   "KEY"
               Height          =   375
               Left            =   2760
               TabIndex        =   151
               Top             =   840
               Width           =   1095
            End
            Begin VB.Label Label43 
               Caption         =   "Value"
               Height          =   375
               Left            =   6240
               TabIndex        =   150
               Top             =   840
               Width           =   735
            End
         End
         Begin VB.Frame Frame27 
            Caption         =   "initVal"
            Height          =   1335
            Left            =   -74880
            TabIndex        =   116
            Top             =   4440
            Width           =   8775
            Begin VB.CommandButton cmdinitialization 
               Caption         =   "initialization"
               Height          =   495
               Left            =   7320
               TabIndex        =   143
               Top             =   720
               Width           =   1215
            End
            Begin VB.TextBox txtInitValSector 
               Height          =   375
               Left            =   5760
               TabIndex        =   139
               Text            =   "01"
               Top             =   360
               Width           =   615
            End
            Begin VB.TextBox txtinitValkey 
               Height          =   375
               Left            =   600
               TabIndex        =   138
               Text            =   "FF FF FF FF FF FF"
               Top             =   840
               Width           =   1935
            End
            Begin VB.TextBox txtInitValValue 
               Height          =   375
               Left            =   4560
               TabIndex        =   137
               Text            =   "64 00 00 00"
               Top             =   840
               Width           =   1575
            End
            Begin VB.Frame Frame31 
               Height          =   615
               Left            =   1320
               TabIndex        =   122
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton opiniValAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   124
                  Top             =   240
                  Width           =   615
               End
               Begin VB.OptionButton Option5 
                  Caption         =   "Idle"
                  Height          =   240
                  Left            =   120
                  TabIndex        =   123
                  Top             =   240
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Frame Frame30 
               Height          =   735
               Left            =   3240
               TabIndex        =   119
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opiniValKeyA 
                  Caption         =   "KeyA"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   121
                  Top             =   360
                  UseMaskColor    =   -1  'True
                  Value           =   -1  'True
                  Width           =   855
               End
               Begin VB.OptionButton opinitValKeyB 
                  Caption         =   "KeyB"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   120
                  Top             =   240
                  Width           =   975
               End
            End
            Begin VB.Label Label39 
               Caption         =   "Sector"
               Height          =   375
               Left            =   6480
               TabIndex        =   142
               Top             =   360
               Width           =   735
            End
            Begin VB.Label Label38 
               Caption         =   "KEY"
               Height          =   375
               Left            =   2760
               TabIndex        =   141
               Top             =   840
               Width           =   1095
            End
            Begin VB.Label Label37 
               Caption         =   "Value"
               Height          =   375
               Left            =   6240
               TabIndex        =   140
               Top             =   840
               Width           =   735
            End
         End
         Begin VB.Frame Frame7 
            Caption         =   "ISO15693 COMMANDS"
            Height          =   9735
            Left            =   -74880
            TabIndex        =   67
            Top             =   480
            Width           =   8655
            Begin VB.Frame Frame45 
               Caption         =   "Get System Information"
               Height          =   855
               Left            =   360
               TabIndex        =   211
               Top             =   7560
               Width           =   8055
               Begin VB.TextBox txtSysFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   214
                  Text            =   "42"
                  Top             =   360
                  Width           =   615
               End
               Begin VB.TextBox txtSysUID 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   213
                  Top             =   360
                  Width           =   735
               End
               Begin VB.CommandButton cmdGetSys 
                  Caption         =   "Get"
                  Enabled         =   0   'False
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   212
                  Top             =   360
                  Width           =   1215
               End
               Begin VB.Label Label60 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   216
                  Top             =   360
                  Width           =   735
               End
               Begin VB.Label Label59 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   215
                  Top             =   360
                  Width           =   2055
               End
            End
            Begin VB.Frame Frame43 
               Caption         =   "Lock AFI"
               Height          =   855
               Left            =   360
               TabIndex        =   195
               Top             =   6720
               Width           =   8055
               Begin VB.CommandButton LockDSFID 
                  Caption         =   "LockDSFID"
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   198
                  Top             =   360
                  Width           =   1215
               End
               Begin VB.TextBox txtLockDSFIDUID 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   197
                  Top             =   360
                  Width           =   735
               End
               Begin VB.TextBox txtLockDSFIDFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   196
                  Text            =   "42"
                  Top             =   360
                  Width           =   615
               End
               Begin VB.Label Label54 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   200
                  Top             =   360
                  Width           =   2055
               End
               Begin VB.Label Label53 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   199
                  Top             =   360
                  Width           =   735
               End
            End
            Begin VB.Frame Frame42 
               Caption         =   "Write DSFID"
               Height          =   735
               Left            =   360
               TabIndex        =   189
               Top             =   6000
               Width           =   8055
               Begin VB.TextBox txtWriteDSFIDDSFID 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   221
                  Text            =   "08"
                  Top             =   240
                  Width           =   735
               End
               Begin VB.CommandButton cmdWriteDSFID 
                  Caption         =   "WriteDSFID"
                  Enabled         =   0   'False
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   192
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.TextBox txtWriteDSFIDUID 
                  Height          =   375
                  Left            =   3960
                  TabIndex        =   191
                  Top             =   240
                  Width           =   1695
               End
               Begin VB.TextBox txtWriteDSFIDFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   190
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.Label Label63 
                  Caption         =   "DSFID"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   222
                  Top             =   240
                  Width           =   975
               End
               Begin VB.Label Label52 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   5640
                  TabIndex        =   194
                  Top             =   240
                  Width           =   495
               End
               Begin VB.Label Label51 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   193
                  Top             =   240
                  Width           =   735
               End
            End
            Begin VB.Frame Frame41 
               Caption         =   "Lock AFI"
               Height          =   735
               Left            =   360
               TabIndex        =   183
               Top             =   5280
               Width           =   8055
               Begin VB.TextBox txtLockAFIFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   186
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.TextBox txtLockAFIUID 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   185
                  Top             =   240
                  Width           =   735
               End
               Begin VB.CommandButton LockAFI 
                  Caption         =   "Lock"
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   184
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.Label Label50 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   188
                  Top             =   240
                  Width           =   735
               End
               Begin VB.Label Label20 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   187
                  Top             =   240
                  Width           =   2055
               End
            End
            Begin VB.Frame Frame40 
               Caption         =   "Write AFI"
               Height          =   735
               Left            =   360
               TabIndex        =   177
               Top             =   4560
               Width           =   8055
               Begin VB.TextBox txtWriteAFIAFI 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   219
                  Text            =   "02"
                  Top             =   240
                  Width           =   735
               End
               Begin VB.TextBox txtWriteAFIFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   180
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.TextBox txtWriteAFIUID 
                  Height          =   375
                  Left            =   3960
                  TabIndex        =   179
                  Top             =   240
                  Width           =   1695
               End
               Begin VB.CommandButton Write 
                  Caption         =   "Write"
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   178
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.Label Label62 
                  Caption         =   "AFI"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   220
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.Label Label49 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   182
                  Top             =   240
                  Width           =   735
               End
               Begin VB.Label txtWriteUID 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   5640
                  TabIndex        =   181
                  Top             =   240
                  Width           =   495
               End
            End
            Begin VB.Frame Frame39 
               Caption         =   "Select"
               Height          =   735
               Left            =   360
               TabIndex        =   171
               Top             =   3840
               Width           =   8055
               Begin VB.CommandButton cmdSelect 
                  Caption         =   "Select"
                  Height          =   375
                  Left            =   6240
                  TabIndex        =   174
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.TextBox txtSelectUID 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   173
                  Top             =   240
                  Width           =   735
               End
               Begin VB.TextBox txtSelectFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   172
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.Label Label7 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   2640
                  TabIndex        =   176
                  Top             =   240
                  Width           =   2055
               End
               Begin VB.Label Label3 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   175
                  Top             =   240
                  Width           =   735
               End
            End
            Begin VB.Frame Frame10 
               Caption         =   "Write"
               Height          =   1215
               Left            =   360
               TabIndex        =   84
               Top             =   1800
               Width           =   8055
               Begin VB.TextBox txtData 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   89
                  Text            =   "11 11 11 11"
                  Top             =   720
                  Width           =   3975
               End
               Begin VB.CommandButton cmd15693Write 
                  Caption         =   "Write"
                  Height          =   495
                  Left            =   6360
                  TabIndex        =   88
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.TextBox txtWriteNumber 
                  Height          =   375
                  Left            =   3360
                  TabIndex        =   87
                  Text            =   "01"
                  Top             =   240
                  Width           =   735
               End
               Begin VB.TextBox txtWriteArea 
                  Height          =   375
                  Left            =   1560
                  TabIndex        =   86
                  Text            =   "05"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.TextBox txtWriteFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   85
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.Label Label17 
                  Caption         =   "The data for write"
                  Height          =   375
                  Left            =   4440
                  TabIndex        =   93
                  Top             =   720
                  Width           =   2175
               End
               Begin VB.Label Label16 
                  Caption         =   "Number"
                  Height          =   375
                  Left            =   4320
                  TabIndex        =   92
                  Top             =   240
                  Width           =   735
               End
               Begin VB.Label Label15 
                  Caption         =   "Start area"
                  Height          =   375
                  Left            =   2400
                  TabIndex        =   91
                  Top             =   240
                  Width           =   1095
               End
               Begin VB.Label Label14 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   90
                  Top             =   240
                  Width           =   735
               End
            End
            Begin VB.Frame Frame9 
               Caption         =   "Read"
               Height          =   735
               Left            =   360
               TabIndex        =   76
               Top             =   1080
               Width           =   8055
               Begin VB.CommandButton cmd15693Read 
                  Caption         =   "Read"
                  Height          =   375
                  Left            =   6360
                  TabIndex        =   80
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.TextBox txtNumber 
                  Height          =   375
                  Left            =   3360
                  TabIndex        =   79
                  Text            =   "05"
                  Top             =   240
                  Width           =   735
               End
               Begin VB.TextBox txtArea 
                  Height          =   375
                  Left            =   1560
                  TabIndex        =   78
                  Text            =   "01"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.TextBox txtFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   77
                  Text            =   "02"
                  Top             =   240
                  Width           =   615
               End
               Begin VB.Label Label13 
                  Caption         =   "Number"
                  Height          =   375
                  Left            =   4320
                  TabIndex        =   83
                  Top             =   240
                  Width           =   735
               End
               Begin VB.Label Label12 
                  Caption         =   "Start area"
                  Height          =   375
                  Left            =   2400
                  TabIndex        =   82
                  Top             =   240
                  Width           =   1095
               End
               Begin VB.Label Label11 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   81
                  Top             =   240
                  Width           =   735
               End
            End
            Begin VB.Frame Frame8 
               Caption         =   "Inventory"
               Height          =   735
               Left            =   360
               TabIndex        =   74
               Top             =   360
               Width           =   8055
               Begin VB.CommandButton cmd15693Inventory 
                  Caption         =   "Inventory"
                  Height          =   375
                  Left            =   6360
                  TabIndex        =   75
                  Top             =   240
                  Width           =   1215
               End
            End
            Begin VB.Frame Frame13 
               Caption         =   "lock_Block"
               Height          =   855
               Left            =   360
               TabIndex        =   68
               Top             =   3000
               Width           =   8055
               Begin VB.TextBox txtLockBlock 
                  Height          =   375
                  Left            =   1440
                  TabIndex        =   217
                  Text            =   "01"
                  Top             =   360
                  Width           =   735
               End
               Begin VB.TextBox txtLockFlag 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   71
                  Text            =   "02"
                  Top             =   360
                  Width           =   615
               End
               Begin VB.TextBox txtLockUID 
                  Height          =   375
                  Left            =   3960
                  TabIndex        =   70
                  Top             =   360
                  Width           =   1575
               End
               Begin VB.CommandButton cmdLock 
                  Caption         =   "Lock_Block"
                  Height          =   495
                  Left            =   6240
                  TabIndex        =   69
                  Top             =   240
                  Width           =   1215
               End
               Begin VB.Label Label61 
                  Caption         =   "Block to Lock"
                  Height          =   375
                  Left            =   2400
                  TabIndex        =   218
                  Top             =   360
                  Width           =   1455
               End
               Begin VB.Label Label18 
                  Caption         =   "Flag"
                  Height          =   375
                  Left            =   840
                  TabIndex        =   73
                  Top             =   360
                  Width           =   735
               End
               Begin VB.Label Label19 
                  Caption         =   "UID"
                  Height          =   375
                  Left            =   5640
                  TabIndex        =   72
                  Top             =   360
                  Width           =   495
               End
            End
         End
         Begin VB.Frame Frame2 
            Caption         =   "Write"
            Height          =   2415
            Left            =   -74880
            TabIndex        =   51
            Top             =   2040
            Width           =   8775
            Begin VB.Frame Frame6 
               Height          =   735
               Left            =   2760
               TabIndex        =   60
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opWriteKeyB 
                  Caption         =   "KeyB"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   62
                  Top             =   240
                  Width           =   975
               End
               Begin VB.OptionButton opWriteKeyA 
                  Caption         =   "KeyA"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   61
                  Top             =   360
                  UseMaskColor    =   -1  'True
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Frame Frame5 
               Height          =   615
               Left            =   720
               TabIndex        =   57
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton Option2 
                  Caption         =   "Idle"
                  Height          =   240
                  Left            =   120
                  TabIndex        =   59
                  Top             =   240
                  Width           =   855
               End
               Begin VB.OptionButton opWriteAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   58
                  Top             =   240
                  Width           =   615
               End
            End
            Begin VB.TextBox txtWriteData 
               Height          =   375
               Left            =   360
               TabIndex        =   56
               Text            =   "AB AB AB AB AB AB AB AB AB AB AB AB AB AB AB AB AB"
               Top             =   1680
               Width           =   5775
            End
            Begin VB.CommandButton cmdWrite 
               Caption         =   "Write"
               Height          =   375
               Left            =   5880
               TabIndex        =   55
               Top             =   1080
               Width           =   1335
            End
            Begin VB.ComboBox cboWriteKey 
               Height          =   360
               Left            =   360
               TabIndex        =   54
               Text            =   "Combo1"
               Top             =   1200
               Width           =   2055
            End
            Begin VB.ComboBox cboStartWriteNumber 
               Height          =   360
               Left            =   4800
               TabIndex        =   53
               Text            =   "Combo1"
               Top             =   720
               Width           =   975
            End
            Begin VB.ComboBox cboStartWriteAdress 
               Height          =   360
               Left            =   360
               TabIndex        =   52
               Text            =   "Combo1"
               Top             =   720
               Width           =   975
            End
            Begin VB.Label Label10 
               Caption         =   "The Data for Write to Card"
               Height          =   255
               Left            =   6240
               TabIndex        =   66
               Top             =   1680
               Width           =   2535
            End
            Begin VB.Label Label9 
               Caption         =   "The Six Bytes Block Key "
               Height          =   375
               Left            =   2520
               TabIndex        =   65
               Top             =   1200
               Width           =   2535
            End
            Begin VB.Label Label8 
               Caption         =   "number of Blocks to be read"
               Height          =   375
               Left            =   5880
               TabIndex        =   64
               Top             =   720
               Width           =   3375
            End
            Begin VB.Label Label6 
               Caption         =   "The Start Adress of Blocks to be read"
               Height          =   375
               Left            =   1440
               TabIndex        =   63
               Top             =   840
               Width           =   3375
            End
         End
         Begin VB.Frame Frame1 
            Caption         =   "Read"
            Height          =   1695
            Left            =   -74880
            TabIndex        =   37
            Top             =   360
            Width           =   8775
            Begin VB.Frame Frame4 
               Height          =   735
               Left            =   2760
               TabIndex        =   45
               Top             =   0
               Width           =   2175
               Begin VB.OptionButton opReadKeyB 
                  Caption         =   "KeyB"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   47
                  Top             =   240
                  Width           =   975
               End
               Begin VB.OptionButton opReadKeyA 
                  Caption         =   "KeyA"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   46
                  Top             =   240
                  Value           =   -1  'True
                  Width           =   855
               End
            End
            Begin VB.Frame Frame3 
               Height          =   615
               Left            =   720
               TabIndex        =   42
               Top             =   0
               Width           =   1815
               Begin VB.OptionButton Option1 
                  Caption         =   "Idle"
                  Height          =   255
                  Left            =   120
                  TabIndex        =   44
                  Top             =   240
                  Value           =   -1  'True
                  Width           =   735
               End
               Begin VB.OptionButton opReadAll 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   960
                  TabIndex        =   43
                  Top             =   240
                  Width           =   615
               End
            End
            Begin VB.CommandButton cmdRead 
               Caption         =   "Read"
               Height          =   375
               Left            =   5760
               TabIndex        =   41
               Top             =   1200
               Width           =   1335
            End
            Begin VB.ComboBox cboReadKey 
               Height          =   360
               Left            =   240
               TabIndex        =   40
               Text            =   "Combo1"
               Top             =   1200
               Width           =   2055
            End
            Begin VB.ComboBox cboStartReadNumber 
               Height          =   360
               Left            =   4560
               TabIndex        =   39
               Text            =   "Combo1"
               Top             =   840
               Width           =   975
            End
            Begin VB.ComboBox cboStartReadAdress 
               Height          =   360
               Left            =   240
               TabIndex        =   38
               Text            =   "Combo1"
               Top             =   720
               Width           =   975
            End
            Begin VB.Label Label5 
               Caption         =   "The Six Bytes Block Key "
               Height          =   375
               Left            =   2520
               TabIndex        =   50
               Top             =   1200
               Width           =   2535
            End
            Begin VB.Label Label4 
               Caption         =   "number of Blocks to be read"
               Height          =   375
               Left            =   5520
               TabIndex        =   49
               Top             =   840
               Width           =   3375
            End
            Begin VB.Label Label2 
               Caption         =   "The Start Adress of Blocks to be read"
               Height          =   375
               Left            =   1200
               TabIndex        =   48
               Top             =   840
               Width           =   3375
            End
         End
         Begin VB.Frame Frame14 
            Caption         =   "ISO 14443 TypeB Commands"
            Height          =   4935
            Left            =   -74880
            TabIndex        =   26
            Top             =   600
            Width           =   8535
            Begin VB.Frame Frame16 
               Caption         =   "China identity card UID"
               Height          =   1695
               Left            =   240
               TabIndex        =   169
               Top             =   3000
               Width           =   8055
               Begin VB.CommandButton cmdSFZUID 
                  Caption         =   "SFZ UID"
                  Height          =   495
                  Left            =   6000
                  TabIndex        =   170
                  Top             =   720
                  Width           =   1815
               End
            End
            Begin VB.Frame Frame15 
               Caption         =   "Commands"
               Height          =   1095
               Left            =   240
               TabIndex        =   33
               Top             =   360
               Width           =   8055
               Begin VB.CommandButton cmd14443BRequest 
                  Caption         =   "Request_Typeb"
                  Height          =   495
                  Left            =   6000
                  TabIndex        =   34
                  Top             =   360
                  Width           =   1815
               End
            End
            Begin VB.Frame Frame17 
               Height          =   1335
               Left            =   240
               TabIndex        =   27
               Top             =   1560
               Width           =   8055
               Begin VB.CommandButton cmd14443BTypeb 
                  Caption         =   "Typeb_Transfer"
                  Height          =   495
                  Left            =   6000
                  TabIndex        =   30
                  Top             =   360
                  Width           =   1815
               End
               Begin VB.TextBox Text2 
                  Height          =   375
                  Left            =   2880
                  TabIndex        =   29
                  Text            =   "08"
                  Top             =   360
                  Width           =   2415
               End
               Begin VB.TextBox txt14443BData 
                  Height          =   375
                  Left            =   1680
                  TabIndex        =   28
                  Text            =   "00 00 05 00 84 00 00 08"
                  Top             =   840
                  Width           =   3615
               End
               Begin VB.Label Label21 
                  Caption         =   "the datalength for sending:"
                  Height          =   375
                  Left            =   120
                  TabIndex        =   32
                  Top             =   480
                  Width           =   2535
               End
               Begin VB.Label Label22 
                  Caption         =   "data:"
                  Height          =   375
                  Left            =   1080
                  TabIndex        =   31
                  Top             =   840
                  Width           =   495
               End
            End
         End
         Begin VB.Frame Frame18 
            Caption         =   "auto"
            Height          =   975
            Left            =   -74640
            TabIndex        =   23
            Top             =   360
            Width           =   8295
            Begin VB.Frame Frame24 
               Height          =   615
               Left            =   3360
               TabIndex        =   105
               Top             =   240
               Width           =   2295
               Begin VB.OptionButton opUltralightall 
                  Caption         =   "All"
                  Height          =   255
                  Left            =   1200
                  TabIndex        =   107
                  Top             =   240
                  Width           =   615
               End
               Begin VB.OptionButton opUltralightDle 
                  Caption         =   "Idle"
                  Height          =   255
                  Left            =   240
                  TabIndex        =   106
                  Top             =   240
                  Value           =   -1  'True
                  Width           =   735
               End
            End
            Begin VB.CommandButton cmdUltraligthRead 
               Caption         =   "Read"
               Height          =   495
               Left            =   6720
               TabIndex        =   24
               Top             =   360
               Width           =   1455
            End
            Begin VB.Label Label24 
               Caption         =   "Read Card series number:"
               Height          =   255
               Left            =   480
               TabIndex        =   25
               Top             =   480
               Width           =   2535
            End
         End
         Begin VB.Frame Frame19 
            Caption         =   "Halt"
            Height          =   975
            Left            =   -74640
            TabIndex        =   21
            Top             =   1440
            Width           =   8295
            Begin VB.CommandButton cmdHalt 
               Caption         =   "Halt"
               Height          =   495
               Left            =   6720
               TabIndex        =   108
               Top             =   360
               Width           =   1335
            End
            Begin VB.Label Label25 
               Caption         =   "Halt"
               Height          =   375
               Left            =   480
               TabIndex        =   22
               Top             =   360
               Width           =   975
            End
         End
         Begin VB.Frame Frame20 
            Caption         =   "Ultralight 卡读写"
            Height          =   6135
            Left            =   -74640
            TabIndex        =   15
            Top             =   2520
            Width           =   8295
            Begin VB.Frame Frame21 
               Caption         =   "读卡"
               Height          =   5655
               Left            =   360
               TabIndex        =   17
               Top             =   360
               Width           =   3735
               Begin VB.Frame Frame25 
                  Height          =   615
                  Left            =   120
                  TabIndex        =   109
                  Top             =   4920
                  Width           =   1935
                  Begin VB.OptionButton opUltralightDle1 
                     Caption         =   "Idle"
                     Height          =   255
                     Left            =   240
                     TabIndex        =   111
                     Top             =   240
                     Value           =   -1  'True
                     Width           =   735
                  End
                  Begin VB.OptionButton opUltralightall1 
                     Caption         =   "All"
                     Height          =   255
                     Left            =   1200
                     TabIndex        =   110
                     Top             =   240
                     Width           =   615
                  End
               End
               Begin VB.ListBox List1 
                  Appearance      =   0  'Flat
                  Height          =   4350
                  Left            =   960
                  TabIndex        =   19
                  Top             =   480
                  Width           =   2175
               End
               Begin VB.CommandButton cmdUltraligthRead1 
                  Caption         =   "Read"
                  Height          =   495
                  Left            =   2280
                  TabIndex        =   18
                  Top             =   5040
                  Width           =   1215
               End
               Begin VB.Label Label23 
                  Caption         =   "扇区"
                  Height          =   495
                  Left            =   240
                  TabIndex        =   20
                  Top             =   480
                  Width           =   495
               End
            End
            Begin VB.Frame Frame22 
               Caption         =   "写卡"
               Height          =   5655
               Left            =   4320
               TabIndex        =   16
               Top             =   360
               Width           =   3615
               Begin VB.TextBox txtUltralight 
                  Height          =   375
                  Left            =   120
                  TabIndex        =   115
                  Text            =   "00 00 00 00"
                  Top             =   4560
                  Width           =   1695
               End
               Begin VB.Frame Frame26 
                  Height          =   615
                  Left            =   240
                  TabIndex        =   112
                  Top             =   4920
                  Width           =   1935
                  Begin VB.OptionButton opUltralightall2 
                     Caption         =   "All"
                     Height          =   255
                     Left            =   1200
                     TabIndex        =   114
                     Top             =   240
                     Width           =   615
                  End
                  Begin VB.OptionButton opUltralightDle2 
                     Caption         =   "Idle"
                     Height          =   255
                     Left            =   240
                     TabIndex        =   113
                     Top             =   240
                     Value           =   -1  'True
                     Width           =   735
                  End
               End
               Begin VB.CommandButton cmdUltraligthWrite 
                  Caption         =   "Write"
                  Height          =   495
                  Left            =   2280
                  TabIndex        =   103
                  Top             =   5040
                  Width           =   1215
               End
               Begin VB.ListBox List2 
                  Appearance      =   0  'Flat
                  Height          =   4110
                  Left            =   960
                  TabIndex        =   102
                  Top             =   360
                  Width           =   2175
               End
               Begin VB.Label Label32 
                  Caption         =   "扇区"
                  Height          =   495
                  Left            =   240
                  TabIndex        =   104
                  Top             =   360
                  Width           =   495
               End
            End
         End
         Begin VB.Frame Frame23 
            Caption         =   "System Commands"
            Height          =   3375
            Left            =   240
            TabIndex        =   5
            Top             =   600
            Width           =   7935
            Begin VB.CommandButton GetVersion 
               Caption         =   "GetVersion"
               Height          =   375
               Left            =   5400
               TabIndex        =   224
               Top             =   2280
               Width           =   1575
            End
            Begin VB.CommandButton cmdSetBuzzer 
               Caption         =   "Set  Buzzer"
               Height          =   375
               Left            =   5400
               TabIndex        =   101
               Top             =   1800
               Width           =   1575
            End
            Begin VB.CommandButton cmdSetLED 
               Caption         =   "Set LED"
               Height          =   375
               Left            =   5400
               TabIndex        =   100
               Top             =   1320
               Width           =   1575
            End
            Begin VB.TextBox txtTimes2 
               Height          =   360
               Left            =   3480
               TabIndex        =   97
               Text            =   "09"
               Top             =   1800
               Width           =   735
            End
            Begin VB.TextBox txtTimes1 
               Height          =   360
               Left            =   3480
               TabIndex        =   96
               Text            =   "09"
               Top             =   1320
               Width           =   735
            End
            Begin VB.TextBox txtSetSerNum 
               Height          =   375
               Left            =   2040
               TabIndex        =   10
               Text            =   "AB AB AB AB AB AB AB AB"
               Top             =   360
               Width           =   3015
            End
            Begin VB.CommandButton cmdSetserNum 
               Caption         =   "Setser Num"
               Height          =   375
               Left            =   5400
               TabIndex        =   9
               Top             =   360
               Width           =   1575
            End
            Begin VB.CommandButton cmdReadserNum 
               Caption         =   "Read serNum"
               Height          =   375
               Left            =   5400
               TabIndex        =   8
               Top             =   840
               Width           =   1575
            End
            Begin VB.TextBox txtCycle1 
               Height          =   360
               Left            =   1800
               TabIndex        =   7
               Text            =   "18"
               Top             =   1320
               Width           =   735
            End
            Begin VB.TextBox txtCycle2 
               Height          =   360
               Left            =   1800
               TabIndex        =   6
               Text            =   "18"
               Top             =   1800
               Width           =   735
            End
            Begin VB.Label Label1 
               Caption         =   "Get Version Number:"
               Height          =   375
               Left            =   240
               TabIndex        =   223
               Top             =   2280
               Width           =   2175
            End
            Begin VB.Label Label36 
               Caption         =   "Times"
               Height          =   255
               Left            =   4320
               TabIndex        =   99
               Top             =   1800
               Width           =   735
            End
            Begin VB.Label Label35 
               Caption         =   "Times"
               Height          =   255
               Left            =   4320
               TabIndex        =   98
               Top             =   1320
               Width           =   735
            End
            Begin VB.Label Label34 
               Caption         =   "Cycle"
               Height          =   255
               Left            =   2640
               TabIndex        =   95
               Top             =   1800
               Width           =   735
            End
            Begin VB.Label Label33 
               Caption         =   "Cycle"
               Height          =   255
               Left            =   2640
               TabIndex        =   94
               Top             =   1320
               Width           =   735
            End
            Begin VB.Label Label28 
               Caption         =   "SetSerNum:"
               Height          =   255
               Left            =   120
               TabIndex        =   14
               Top             =   360
               Width           =   1215
            End
            Begin VB.Label Label29 
               Caption         =   "ReadSerNum:"
               Height          =   255
               Left            =   120
               TabIndex        =   13
               Top             =   840
               Width           =   1455
            End
            Begin VB.Label Label30 
               Caption         =   "Buzzer:"
               Height          =   255
               Left            =   240
               TabIndex        =   12
               Top             =   1800
               Width           =   1215
            End
            Begin VB.Label Label31 
               Caption         =   "Led:"
               Height          =   255
               Left            =   480
               TabIndex        =   11
               Top             =   1320
               Width           =   975
            End
         End
         Begin VB.Frame from1 
            Caption         =   "Communication Setting"
            Height          =   975
            Left            =   240
            TabIndex        =   35
            Top             =   4080
            Visible         =   0   'False
            Width           =   4815
            Begin VB.ComboBox cboAddress 
               Height          =   360
               Left            =   2400
               TabIndex        =   36
               Text            =   "cboAddress"
               Top             =   360
               Width           =   1455
            End
         End
      End
   End
   Begin VB.Frame Frame11 
      Caption         =   "ListEvent"
      Height          =   10815
      Left            =   9480
      TabIndex        =   1
      Top             =   0
      Width           =   5775
      Begin VB.ListBox lstEvents 
         Height          =   8940
         Left            =   120
         TabIndex        =   3
         Top             =   240
         Width           =   5535
      End
      Begin VB.CommandButton cmdClear 
         Caption         =   "Clear"
         Height          =   375
         Left            =   3360
         TabIndex        =   2
         Top             =   9240
         Width           =   2055
      End
   End
   Begin VB.Label Label42 
      Caption         =   "Sector"
      Height          =   375
      Left            =   5160
      TabIndex        =   146
      Top             =   0
      Width           =   735
   End
   Begin VB.Label Label41 
      Caption         =   "KEY"
      Height          =   375
      Left            =   1440
      TabIndex        =   145
      Top             =   480
      Width           =   1095
   End
   Begin VB.Label Label40 
      Caption         =   "Value"
      Height          =   375
      Left            =   4920
      TabIndex        =   144
      Top             =   480
      Width           =   735
   End
End
Attribute VB_Name = "RFID_DEMO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim hComm As Long



Private Sub cmd14443BRequest_Click()
Dim ret As Integer
    Dim blk_Addr, devAddr As Integer
    Dim mode, Num_blk As Byte
    
    Dim asnr(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    Dim buffer(256) As Byte
    Dim strRet As String
    
    ret = TypeB_Request(buffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("The data length is.." + strByHex(buffer, 1))
       lstEvents.AddItem ("the receive card number is :" + strByHex(buffer, buffer(0)))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aRecvBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmd14443BTypeb_Click()
Dim ret As Integer
    Dim cmdSize As Integer
    Dim cmd(256) As Byte
    Dim aBuffer(256) As Byte
    cmdSize = Val(Text2.Text)
    ret = hexToBin(txt14443BData.Text, cmd)
    ret = TypeB_TransCOS(cmd(0), cmdSize, aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem (strByHex(aBuffer, 8))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmd15693Inventory_Click()
   Dim ret As Integer
    Dim devAddr As Integer
    Dim cardNum, i As Integer
     Dim strRet As String
    
    
    Dim asnr(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    ret = ISO15693_Inventory(asnr(0), aRecvBuffer(0))
    If ret = 0 Then
       
       '获取卡的数量
       cardNum = CInt(strByHex(asnr, 1))
      
       
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 1))
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHex(aRecvBuffer, cardNum * 10))
       
        For i = 0 To cardNum - 1
       lstEvents.AddItem ("The th card snr is  ：" + strByHexe(aRecvBuffer, 8, (i + 1) * 10 - 1))
       Next

       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aRecvBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmd15693Read_Click()
Dim ret As Integer
    Dim blk_Addr, devAddr, Num_blk As Integer
    Dim flag As Byte
    
    'Dim aKeyA(20) As Byte
    Dim gui(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    
    Dim strRet As String
      

    '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
     '读取开始地址
    blk_Addr = Val(txtArea.Text)
    'flag
    flag = txtFlag.Text
  
    '读取块数
    Num_blk = Val(txtNumber.Text)
    
    ret = ISO15693_Read(flag, blk_Addr, Num_blk, gui(0), aRecvBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHexb(aRecvBuffer, Num_blk * 4, 1))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aRecvBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmd15693Write_Click()
    Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Integer
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim gui(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtWriteFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
     '写取开始地址
    blk_Addr = Val(txtWriteArea.Text)
 
  
    '写块数
    Num_blk = Val(txtWriteNumber.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtData.Text, aBuffer)
    
    ret = ISO15693_Write(flag, blk_Addr, Num_blk, gui(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdAddvalue_Click()
    Dim ret As Integer
    Dim dataLen As Integer
    Dim mode, devAddr, Num_blk As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
      'ret = asciiToBin(txtWriteData.Text, aBuffer)
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    
    '写取模式
  If Option14.value = True And opaddvalueKeyA.value = True Then mode = &O0
  If Option14.value = True And opaddvalueKeyB.value = True Then mode = &O2
  If opincrementAll.value = True And opaddvalueKeyA.value = True Then mode = &O1
  If opincrementAll.value = True And opaddvalueKeyB.value = True Then mode = &O3
  
    '写块数
    Num_blk = Val(txtAddvalueSector.Text)
    '一个指针，传递的是六个字节的密钥
    ret = hexToBin(txAddvaluekey.Text, asnr)
    '传入数据到缓冲区
    ret = hexToBin(txtAddvalueValue.Text, aBuffer)
    
    ret = MF_Inc(mode, Num_blk, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 4))
        lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHex(aBuffer, 4))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdcard_Click()
    Dim ret As Integer
    Dim dataLen As Integer
    Dim mode, devAddr, half As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
      'ret = asciiToBin(txtWriteData.Text, aBuffer)
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    
    '写取模式
  If Option17.value = True Then
  mode = 38
  Else
  mode = 82
  End If
  If opcardKeyA.value = True Then
  half = &O0
  Else
  half = &O1
  End If
  
  
    ret = MF_Getsnr(mode, half, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(aBuffer, 4))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdClear_Click()
lstEvents.Clear
End Sub


Private Sub cmdDevalue_Click()
    Dim ret As Integer
    Dim dataLen As Integer
    Dim mode, devAddr, Num_blk As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
      'ret = asciiToBin(txtWriteData.Text, aBuffer)
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    
    '写取模式
  If Option10.value = True And opdevalueKeyA.value = True Then mode = &O0
  If Option10.value = True And opdevalueKeyB.value = True Then mode = &O2
  If opdevalueAll.value = True And opdevalueKeyA.value = True Then mode = &O1
  If opdevalueAll.value = True And opdevalueKeyB.value = True Then mode = &O3
  
    '写块数
    Num_blk = Val(txtDevalueSector.Text)
    '一个指针，传递的是六个字节的密钥
    ret = hexToBin(txtDevaluekey.Text, asnr)
    '传入数据到缓冲区
    ret = hexToBin(txtDevalueValue.Text, aBuffer)
    
    ret = MF_Dec(mode, Num_blk, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 4))
        lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHex(aBuffer, 4))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdHalt_Click()
Dim ret As Integer
Dim devAddr As Integer
Dim aBuffer(2048) As Byte

 '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
   
    ret = MF_Halt()
    If ret = 0 Then
       lstEvents.AddItem (CStr(Now) + "  success..")
       Else
             lstEvents.AddItem (CStr(Now) + "  false..")
       End If
End Sub

Private Sub cmdinitialization_Click()
    Dim ret As Integer
    Dim dataLen As Integer
    Dim mode, devAddr, Num_blk As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
      'ret = asciiToBin(txtWriteData.Text, aBuffer)
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    
    '写取模式
  If Option5.value = True And opiniValKeyA.value = True Then mode = &O0
  If Option5.value = True And opinitValKeyB.value = True Then mode = &O2
  If opiniValAll.value = True And opiniValKeyA.value = True Then mode = &O1
  If opiniValAll.value = True And opinitValKeyB.value = True Then mode = &O3
  
    '写块数
    Num_blk = Val(txtInitValSector.Text)
    '一个指针，传递的是六个字节的密钥
    ret = hexToBin(txtinitValkey.Text, asnr)
    '传入数据到缓冲区
    ret = hexToBin(txtInitValValue.Text, aBuffer)
    
    ret = MF_InitValue(mode, Num_blk, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 4))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub



Private Sub cmdLock_Click()
 Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Byte
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim uid(256) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtLockFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
 
  
    '写块数
    Num_blk = Val(txtLockBlock.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtLockUID.Text, uid)
    
    ret = ISO15693_Lock(flag, Num_blk, uid(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdRead_Click()
    Dim ret As Integer
    Dim devAddr As Integer
    Dim mode, Num_blk As Byte
    Dim blk_Addr(4) As Byte
    'Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
    '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
     '读取开始地址
    ret = hexToBin(cboStartReadAdress.Text, blk_Addr)
    '读取模式
  If Option1.value = True And opReadKeyA.value = True Then mode = &O0
  If Option1.value = True And opReadKeyB.value = True Then mode = &O2
  If opReadAll.value = True And opReadKeyA.value = True Then mode = &O1
  If opReadAll.value = True And opReadKeyB.value = True Then mode = &O3
  
    '读取块数
    Num_blk = Val(cboStartReadNumber.Text)
    '一个指针，传递的是六个字节的密钥
    ret = hexToBin(cboReadKey.Text, asnr)
    
    ret = MF_Read(mode, blk_Addr(0), Num_blk, asnr(0), aRecvBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 4))
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHex(aRecvBuffer, Num_blk * 16))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             strRet = strByHex(aRecvBuffer, 1)
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(strByHex(aRecvBuffer, 1)))
             strRet = falsereason(strByHex(aRecvBuffer, 1))
             End If
       End If
    
End Sub

Private Sub cmdReadserNum_Click()
Dim ret, devAddr As Integer
Dim aBuffer(2048) As Byte

 '厂家预设地址
    devAddr = myVal(cboAddress.Text)
    
    ret = GetSerNum(aBuffer(0))
    
     If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHexb(aBuffer, 8, 1))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdSelect_Click()
 Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Byte
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim uid(256) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtSelectFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
 
  
    '写块数
    'Num_blk = Val(txtLockBlock.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtSelectUID.Text, uid)
    
    ret = ISO15693_Select(flag, uid(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

'设置通讯地址
Private Sub cmdSetAddress_Click()
Dim ret As Integer
Dim newAddr As Byte
Dim aBuffer(2048), devAddr As Byte

 '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
'设置通讯地址
    
    ret = API_SetDeviceAddress(hComm, devAddr, newAddr, aBuffer(0))
    If ret = 0 Then
       lstEvents.AddItem (CStr(Now) + "  success..")
       Else
             lstEvents.AddItem (CStr(Now) + "  false..")
       End If
    
End Sub

Private Sub cmdSetBuzzer_Click()
Dim ret As Integer
Dim newBoud, freq, duration As Byte
Dim aBuffer(2048), devAddr As Byte

 '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
'周期数
freq = txtCycle2.Text
'次数
duration = txtTimes2.Text


    
    ret = ControlBuzzer(freq, duration, aBuffer(0))
    If ret = 0 Then
       lstEvents.AddItem (CStr(Now) + "  success..")
       Else
             lstEvents.AddItem (CStr(Now) + "  false..")
       End If
End Sub

Private Sub cmdSetLED_Click()
Dim ret As Integer
Dim newBoud, freq, duration As Byte
Dim aBuffer(2048), devAddr As Byte

 '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
'周期数
freq = txtCycle1.Text
'次数
duration = txtTimes1.Text
   
    ret = ControlLED(freq, duration, aBuffer(0))
    If ret = 0 Then
       lstEvents.AddItem (CStr(Now) + "  success..")
       Else
             lstEvents.AddItem (CStr(Now) + "  false..")
       End If
End Sub

'读取由厂家预设的1个字节的读卡器地址和8个字节序列号
Private Sub cmdSetserNum_Click()
Dim ret, devAddr As Integer
Dim asnr(20) As Byte
Dim aBuffer(2048) As Byte

 '厂家预设地址
    devAddr = myVal(cboAddress.Text)
    
     '传入数据到缓冲区
    ret = hexToBin(txtSetSerNum.Text, asnr)
     'ret = hexToBin(txtSetSerNum.Text, aBuffer)
    
    ret = SetSerNum(asnr(0), aBuffer(0))
    If ret = 0 Then
       lstEvents.AddItem (CStr(Now) + "  success..")
       Else
             lstEvents.AddItem (CStr(Now) + "  false..")
       End If
End Sub

Private Sub cmdSFZUID_Click()
Dim ret As Integer
    Dim mode, halt As Byte
Dim value(8) As Byte
Dim snr(1) As Byte
mode = 38
halt = 0
ret = TYPEB_SFZSNR(mode, halt, snr(0), value(0))

    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       If snr(0) = 0 Then
            lstEvents.AddItem ("Only one card.....")
       Else
            lstEvents.AddItem ("More than one card.....")
       End If
       lstEvents.AddItem (strByHex(value, 8))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(snr, 1))))
             End If
       End If
End Sub

Private Sub cmdUltraligthRead_Click()
 Dim ret As Integer
    Dim blk_Addr, devAddr As Integer
    Dim mode, Num_blk As Byte
    
    Dim asnr(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
    '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
    '读取模式
  If opUltralightDle.value = True Then mode = &O0
  If opUltralightall.value = True Then mode = &O1
  
    
    ret = UL_Request(mode, asnr(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 7))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aRecvBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdUltraligthRead1_Click()
 Dim ret As Integer
    Dim blk_Addr, devAddr As Integer
    Dim mode, Num_blk As Byte
    
    'Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aRecvBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
    '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
     '读取开始地址
    blk_Addr = List1.Text
    
    '读取模式
  If opUltralightDle1.value = True Then mode = &O0
  If opUltralightall1.value = True Then mode = &O1
      
    ret = UL_HLRead(mode, blk_Addr, asnr(0), aRecvBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 7))
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHex(aRecvBuffer, 16))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
            ' End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aRecvBuffer, 1))))
             End If
       End If
End Sub

Private Sub cmdUltraligthWrite_Click()
Dim ret As Integer
    Dim blk_Addr, dataLen As Integer
    Dim mode, devAddr, Num_blk As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
  
    '写取模式
  If opUltralightDle2.value = True Then mode = &O0
  If opUltralightall2.value = True Then mode = &O1
  
  '读取开始地址
    blk_Addr = List2.Text
  
  
    '传入数据到缓冲区
    ret = hexToBin(txtUltralight.Text, aBuffer)
    
    ret = UL_HLWrite(mode, blk_Addr, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 7))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
            ' End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
    
End Sub

Private Sub cmdWrite_Click()
    Dim ret As Integer
    Dim dataLen As Integer
    Dim mode, devAddr, Num_blk As Byte
    Dim blk_Addr(4) As Byte
   ' Dim aKeyA(20) As Byte
    Dim asnr(20) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    mode = &O0
      'ret = asciiToBin(txtWriteData.Text, aBuffer)
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
     '写取开始地址
    ret = hexToBin(cboStartWriteAdress.Text, blk_Addr)
    '写取模式
  If Option2.value = True And opWriteKeyA.value = True Then mode = &O0
  If Option2.value = True And opWriteKeyB.value = True Then mode = &O2
  If opWriteAll.value = True And opWriteKeyA.value = True Then mode = &O1
  If opWriteAll.value = True And opWriteKeyB.value = True Then mode = &O3
  
    '写块数
    Num_blk = Val(cboStartWriteNumber.Text)
    '一个指针，传递的是六个字节的密钥
    ret = hexToBin(cboWriteKey.Text, asnr)
    '传入数据到缓冲区
    ret = hexToBin(txtWriteData.Text, aBuffer)
    
    ret = MF_Write(mode, blk_Addr(0), Num_blk, asnr(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem ("the receive card number is :" + strByHex(asnr, 4))
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(strByHex(aBuffer, 1)))
             End If
       End If
    
    
    'Text8.Text = Trim$(CStr(ret))
    'If Option3.Value = True Then
      'Text7.Text = strByHex(asnr, 4)
    'Else
      'Text7.Text = strByAscii(asnr, 4)
    'End If
'lstEvents.AddItem ("Write")
End Sub


Function falsereason(ByVal s As String)
 Dim reason As String
     If s = "" Then
        reason = ""
End If
     If s = "00" Then
         reason = ""
End If
     If s = "1" Then
reason = "Command false....."
End If
     If s = "2" Then
reason = "checksum error....."
End If
     If s = "3" Then
reason = "Not selected COM port....."
End If
     If s = "4" Then
reason = "time out reply.....';   "
End If
     If s = "5" Then
reason = "check sequence error....."
End If
     If s = "7" Then
reason = "check sum error....."
End If
     If s = "10" Then
reason = "the parameter value out of range....."
End If
     If s = "80" Then
reason = "Command OK....."
End If
     If s = "81" Then
reason = "Command FAILURE...."
End If
     If s = "82" Then
reason = "Reader reply time out error...."
End If
     If s = "83" Then
reason = "The card is not exist...."
End If
     If s = "84" Then
reason = "the data is error...."
End If
     If s = "85" Then
reason = "Reader received unknown command...."
End If
     If s = "87" Then
reason = "error...."
End If
     If s = "89" Then
reason = "The parameter of the command or the Format of the command Erro..."
End If
     If s = "8A" Then
reason = "Some Erro appear in the card InitVal process..."
End If
     If s = "8B" Then
reason = "Get The Wrong Snr during anticollison loop...."
End If
     If s = "8C" Then
reason = "The authentication failure...."
End If
     If s = "8F" Then
reason = "Reader received unknown command...."
End If
     If s = "90" Then
reason = "The Card do not support this command...."
End If
     If s = "91" Then
reason = "The Foarmat Of  The Command Erro...."
End If
     If s = "92" Then
reason = "Do not support Option mode...."
End If
     If s = "93" Then
 reason = "The Block Do Not Exist...."
End If
     If s = "94" Then
reason = "The Object have been locked...."
End If
     If s = "95" Then
reason = "The lock Operation Do Not Success...."
End If
     If s = "96" Then
reason = "The Operation Do Not Success...."
End If

falsereason = reason
End Function


Private Sub Form_Load()
         Dim i As Integer
         SSTab1.TabIndex = 0
'初始化地址，加入8个地址，默认00
    cboAddress.AddItem "00"
    cboAddress.AddItem "01"
    cboAddress.AddItem "02"
    cboAddress.AddItem "03"
    cboAddress.AddItem "04"
    cboAddress.AddItem "05"
    cboAddress.AddItem "06"
    cboAddress.AddItem "07"
    cboAddress.AddItem "08"
    cboAddress.Text = "00"
'读开始快的地址，加入16个，默认10
       For i = 0 To 63
          cboStartReadAdress.AddItem Hex(i)
        Next
        cboStartReadAdress.Text = "10"
'读开始块数，加入4个，默认01
     cboStartReadNumber.AddItem "01"
     cboStartReadNumber.AddItem "02"
     cboStartReadNumber.AddItem "03"
     cboStartReadNumber.AddItem "04"
     cboStartReadNumber.Text = "01"
 '读的密码，加入3个，默认fffff
     cboReadKey.AddItem "A0 A1 A2 A3 A4 A5"
     cboReadKey.AddItem "B0 B1 B2 B3 B4 B5"
     cboReadKey.AddItem "FF FF FF FF FF FF"
     cboReadKey.Text = "FF FF FF FF FF FF"
     
 '写开始快的地址，加入16个，默认10
       For i = 0 To 63
          cboStartWriteAdress.AddItem Hex(i)
        Next
        cboStartWriteAdress.Text = "10"
'写开始块数，加入4个，默认01
     cboStartWriteNumber.AddItem "01"
     cboStartWriteNumber.AddItem "02"
     cboStartWriteNumber.AddItem "03"
     cboStartWriteNumber.AddItem "04"
     cboStartWriteNumber.Text = "01"
 '写的密码，加入3个，默认fffff
     cboWriteKey.AddItem "A0 A1 A2 A3 A4 A5"
     cboWriteKey.AddItem "B0 B1 B2 B3 B4 B5"
     cboWriteKey.AddItem "FF FF FF FF FF FF"
     cboWriteKey.Text = "FF FF FF FF FF FF"
'初始化ListBox
     List1.AddItem ("00")
     List1.AddItem ("01")
     List1.AddItem ("02")
     List1.AddItem ("03")
     List1.AddItem ("04")
     List1.AddItem ("05")
     List1.AddItem ("06")
     List1.AddItem ("07")
     List1.AddItem ("08")
     List1.AddItem ("09")
     List1.AddItem ("10")
     List1.AddItem ("11")
     List1.AddItem ("12")
     List1.AddItem ("13")
     List1.AddItem ("14")
     List1.AddItem ("15")
     List1.ListIndex = 0
     
     
     List2.AddItem ("00")
     List2.AddItem ("01")
     List2.AddItem ("02")
     List2.AddItem ("03")
     List2.AddItem ("04")
     List2.AddItem ("05")
     List2.AddItem ("06")
     List2.AddItem ("07")
     List2.AddItem ("08")
     List2.AddItem ("09")
     List2.AddItem ("10")
     List2.AddItem ("11")
     List2.AddItem ("12")
     List2.AddItem ("13")
     List2.AddItem ("14")
     List2.AddItem ("15")
     List2.ListIndex = 0
     
     
End Sub











Private Sub GetVersion_Click()
Dim ret, devAddr As Integer
Dim aBuffer(2048) As Byte

 '厂家预设地址
    devAddr = myVal(cboAddress.Text)
    
    ret = GetVersionNum(aBuffer(0))
    
     If ret = 0 Then
       lstEvents.AddItem ("success..")
       lstEvents.AddItem (CStr(Now) + " receive data:")
       lstEvents.AddItem (strByHexb(aBuffer, 11, 1))
       Else
             If ret = Null Then
             lstEvents.AddItem (CStr(Now) + "  error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem (CStr(Now) + "  false..")
             Else
             lstEvents.AddItem (CStr(Now) + "  false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub LockAFI_Click()
 Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Byte
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim uid(256) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtLockAFIFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
 
  
    '写块数
    'Num_blk = Val(txtLockBlock.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtLockAFIUID.Text, uid)
    
    ret = ISO15693_LockAFI(flag, uid(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub LockDSFID_Click()
 Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Byte
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim uid(256) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtLockDSFIDFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
 
  
    '写块数
    'Num_blk = Val(txtLockBlock.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtLockDSFIDUID.Text, uid)
    
    ret = ISO15693_LockDSFID(flag, uid(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub

Private Sub SSTab1_Click(PreviousTab As Integer)
 
    'Select Case PreviousTab
        'Case 0
            'If txtRequired = "" Then
                'txtRequired.SetFocus
                'msg = "Enter a value in this field"
                'Cancel = True
            'End If
        'Case 1
           ' If Not IsNumeric(txtNumeric) Then
                'txtNumeric.SetFocus
                'msg = "Enter a number in this field"
               ' Cancel = True
            'End If
        'Case 2
            ' No validation for this tab.
    'End Select
End Sub


Function myVal(ByVal str As String)
    Dim retVal As Integer
    
    retVal = 0
    If Len(str) = 1 Then
        If str >= "0" And str <= "9" Then
            retVal = Val(str)
        ElseIf str >= "a" And str <= "z" Then
            retVal = Asc(str) - Asc("a") + 10
        ElseIf str >= "A" And str <= "Z" Then
            retVal = Asc(str) - Asc("A") + 10
        End If
    End If
        
    myVal = retVal

End Function


Function asciiToBin(ByVal str As String, ByRef buffer() As Byte)
    Dim i As Integer
    
    For i = 1 To Len(str)
        buffer(i - 1) = Asc(Mid(str, i, 1))
    Next

    asciiToBin = i - 1

End Function

Function hexToBin(ByVal str As String, ByRef buffer() As Byte)
    Dim strRemain As String
    Dim firstChar As Boolean
    Dim i, count, inputLen, remainLen As Integer
    
    i = 0
    count = 0
    firstChar = True
    strRemain = str
    
    While Len(strRemain) > 0
        If Mid(strRemain, 1, 1) = " " Then
            firstChar = True
            strRemain = Mid(strRemain, 2)
        ElseIf firstChar = True Then
            If Len(strRemain) = 1 Then
                buffer(count) = myVal(strRemain)
            ElseIf Len(strRemain) >= 2 Then
                buffer(count) = myVal(Mid(strRemain, 1, 1)) * 16 + myVal(Mid(strRemain, 2, 1))
                
                strRemain = Mid(strRemain, 3)
            End If
            
            count = count + 1
            firstChar = False
        Else
            strRemain = Mid(strRemain, 2)
        End If
    Wend
    
    hexToBin = count
End Function

Function strByAscii(ByRef buffer() As Byte, ByVal bufferSize As Integer)
        Dim i As Integer
        Dim strRet, strSingle As String
        
        strRet = ""
        For i = 0 To bufferSize - 1
            strSingle = Chr$(buffer(i)) & "(" & Trim$(CStr(buffer(i))) & ")"
            strRet = strRet + strSingle
        Next
        
        strByAscii = strRet
End Function

'从数组中取多少为
Function strByHex(ByRef buffer() As Byte, ByVal bufferSize As Integer)
        Dim i As Integer
        Dim strRet, strSingle As String
        
        strRet = ""
        For i = 0 To bufferSize - 1
            strSingle = Hex$(buffer(i))
            If Len(strSingle) = 1 Then
              strSingle = "0" & strSingle
            End If
            
            If bufferSize = 1 Then
            strRet = strSingle
            Else
            strRet = strRet + strSingle + " "
            End If
            
        Next
        
        strByHex = strRet
End Function

'开始的序号，和长度
Function strByHexb(ByRef buffer() As Byte, ByVal bufferSize As Integer, ByVal beginbuffer As Integer)
        Dim i As Integer
        Dim strRet, strSingle As String
        
        strRet = ""
        For i = beginbuffer To beginbuffer + bufferSize - 1
            strSingle = Hex$(buffer(i))
            If Len(strSingle) = 1 Then
              strSingle = "0" & strSingle
            End If
            strRet = strRet + strSingle + " "
        Next
        
        strByHexb = strRet
End Function

'结束的序号和长度
Function strByHexe(ByRef buffer() As Byte, ByVal bufferSize As Integer, ByVal endbuffer As Integer)
        Dim i As Integer
        Dim strRet, strSingle As String
        
        strRet = ""
        For i = 0 To bufferSize - 1
            strSingle = Hex$(buffer(endbuffer - i))
            If Len(strSingle) = 1 Then
              strSingle = "0" & strSingle
            End If
            strRet = strRet + strSingle + " "
        Next
        
        strByHexe = strRet
End Function


Private Sub Form_Unload(Cancel As Integer)
    If hComm <> 0 Then
        CloseComm (hComm)
    End If
End Sub




Private Sub Write_Click()
Dim ret As Integer
    Dim blk_Addr, flag, Num_blk As Byte
    Dim devAddr As Byte
    
   ' Dim aKeyA(20) As Byte
    Dim uid(256) As Byte
    Dim aBuffer(2048) As Byte
    
    Dim strRet As String
      

    flag = txtWriteAFIFlag.Text
    
     '设备地址，如果只有一个
    devAddr = myVal(cboAddress.Text)
 
  
    '写块数
    Num_blk = Val(txtWriteAFIAFI.Text)
    '传入数据到缓冲区
    ret = hexToBin(txtWriteAFIUID.Text, uid)
    
    ret = ISO15693_WriteAFI(flag, Num_blk, uid(0), aBuffer(0))
    
    If ret = 0 Then
       lstEvents.AddItem ("success..")
       Else
             If ret = Null Then
             lstEvents.AddItem ("error,no data receive :")
             'End If
             'If ret = 1 Then
             'lstEvents.AddItem ("false..")
             Else
             lstEvents.AddItem ("false,the reason is.." + falsereason(CStr(strByHex(aBuffer, 1))))
             End If
       End If
End Sub
