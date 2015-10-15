unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, StdCtrls, XPMenu, ExtCtrls, Menus, jpeg, WinSkinData;

type
  TForm1 = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    GroupBox3: TGroupBox;
    StatusBar1: TStatusBar;
    showm: TRichEdit;
    PopupMenu1: TPopupMenu;
    Clear1: TMenuItem;
    Save1: TMenuItem;
    SelectAll1: TMenuItem;
    N1: TMenuItem;
    Copy1: TMenuItem;
    Paste1: TMenuItem;
    Cut1: TMenuItem;
    SaveDialog1: TSaveDialog;
    GroupBox8: TGroupBox;
    Label7: TLabel;
    GroupBox4: TGroupBox;
    reqa: TRadioButton;
    reqi: TRadioButton;
    GroupBox5: TGroupBox;
    keyb: TRadioButton;
    keya: TRadioButton;
    Label10: TLabel;
    Button3: TButton;
    ComboBox4: TComboBox;
    Label11: TLabel;
    Label12: TLabel;
    ComboBox6: TComboBox;
    Label9: TLabel;
    ComboBox5: TComboBox;
    Panel1: TPanel;
    GroupBox6: TGroupBox;
    reqaa: TRadioButton;
    reqii: TRadioButton;
    GroupBox7: TGroupBox;
    keybb: TRadioButton;
    keyaa: TRadioButton;
    Label13: TLabel;
    Button4: TButton;
    Label16: TLabel;
    ComboBox9: TComboBox;
    Label15: TLabel;
    ComboBox8: TComboBox;
    Label14: TLabel;
    ComboBox7: TComboBox;
    Label8: TLabel;
    Edit3: TEdit;
    Label17: TLabel;
    Timer1: TTimer;
    TabSheet3: TTabSheet;
    TabSheet4: TTabSheet;
    GroupBox2: TGroupBox;
    Label36: TLabel;
    Label38: TLabel;
    Label6: TLabel;
    Label19: TLabel;
    Label21: TLabel;
    Label22: TLabel;
    Label20: TLabel;
    Label18: TLabel;
    Edit2: TEdit;
    ReadserNum: TButton;
    SetserNumumber: TButton;
    ledfrq: TEdit;
    leddur: TEdit;
    Button2: TButton;
    Button1: TButton;
    buzzerdur: TEdit;
    buzzerfrq: TEdit;
    TabSheet5: TTabSheet;
    GroupBox9: TGroupBox;
    Label105: TLabel;
    Label34: TLabel;
    Button55: TButton;
    Button17: TButton;
    Panel9: TPanel;
    Panel16: TPanel;
    GroupBox23: TGroupBox;
    Ula: TRadioButton;
    Uli: TRadioButton;
    GroupBox18: TGroupBox;
    GroupBox19: TGroupBox;
    Label106: TLabel;
    Button18: TButton;
    GroupBox24: TGroupBox;
    Ulaa: TRadioButton;
    Ulii: TRadioButton;
    ListBox1: TListBox;
    GroupBox20: TGroupBox;
    Label104: TLabel;
    Button54: TButton;
    Edit56: TEdit;
    GroupBox25: TGroupBox;
    Ulaaa: TRadioButton;
    Uliii: TRadioButton;
    ListBox2: TListBox;
    Label74: TLabel;
    Panel65: TPanel;
    reql3: TRadioButton;
    reqa3: TRadioButton;
    Panel66: TPanel;
    keya3: TRadioButton;
    keyb3: TRadioButton;
    Edit62: TEdit;
    Edit63: TEdit;
    Edit64: TEdit;
    Button27: TButton;
    Button28: TButton;
    Edit68: TEdit;
    Edit67: TEdit;
    Edit66: TEdit;
    Panel69: TPanel;
    keya4: TRadioButton;
    keyb4: TRadioButton;
    Panel68: TPanel;
    reql4: TRadioButton;
    reqa4: TRadioButton;
    Label78: TLabel;
    Label81: TLabel;
    Panel71: TPanel;
    reql5: TRadioButton;
    reqa5: TRadioButton;
    Panel72: TPanel;
    nohalt: TRadioButton;
    yeshalt: TRadioButton;
    Button29: TButton;
    Panel2: TPanel;
    Panel3: TPanel;
    Panel4: TPanel;
    Panel5: TPanel;
    Label70: TLabel;
    Panel63: TPanel;
    reql2: TRadioButton;
    reqa2: TRadioButton;
    Panel64: TPanel;
    keya2: TRadioButton;
    keyb2: TRadioButton;
    Edit57: TEdit;
    Edit58: TEdit;
    Edit59: TEdit;
    Button26: TButton;
    GroupBox10: TGroupBox;
    Panel8: TPanel;
    Panel7: TPanel;
    Panel6: TPanel;
    Button6: TButton;
    Label23: TLabel;
    Label26: TLabel;
    flagr: TEdit;
    Label24: TLabel;
    startr: TEdit;
    Label25: TLabel;
    numberr: TEdit;
    Label29: TLabel;
    Button38: TButton;
    Button39: TButton;
    Label27: TLabel;
    dataw: TEdit;
    Label72: TLabel;
    numberw: TEdit;
    Label48: TLabel;
    startw: TEdit;
    Label35: TLabel;
    flagw: TEdit;
    Label32: TLabel;
    GroupBox11: TGroupBox;
    Label88: TLabel;
    Edit78: TEdit;
    Edit77: TEdit;
    Button36: TButton;
    Label87: TLabel;
    Panel10: TPanel;
    Button31: TButton;
    Label28: TLabel;
    Label30: TLabel;
    Label31: TLabel;
    Label33: TLabel;
    Label37: TLabel;
    Label39: TLabel;
    Label40: TLabel;
    Label41: TLabel;
    Label42: TLabel;
    Label43: TLabel;
    Label44: TLabel;
    Button5: TButton;
    Panel11: TPanel;
    Edit4: TEdit;
    Label45: TLabel;
    Edit5: TEdit;
    Label46: TLabel;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    CheckBox3: TCheckBox;
    GroupBox1: TGroupBox;
    Button7: TButton;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    N4: TMenuItem;
    N3: TMenuItem;
    N11: TMenuItem;
    N12: TMenuItem;
    N13: TMenuItem;
    N14: TMenuItem;
    N51: TMenuItem;
    N61: TMenuItem;
    N2: TMenuItem;
    N5: TMenuItem;
    COM1: TMenuItem;
    N10: TMenuItem;
    S50S701: TMenuItem;
    Ultralight1: TMenuItem;
    ISO14443B1: TMenuItem;
    ISO156931: TMenuItem;
    Label1: TLabel;
    Button8: TButton;
    procedure checkdata(s:string);
    procedure falsereason(s:string);
    procedure FormCreate(Sender: TObject);
    procedure SetserNumumberClick(Sender: TObject);
    procedure ReadserNumClick(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Clear1Click(Sender: TObject);
    procedure Save1Click(Sender: TObject);
    procedure SelectAll1Click(Sender: TObject);
    procedure Copy1Click(Sender: TObject);
    procedure Paste1Click(Sender: TObject);
    procedure Cut1Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Delay(MSecs: Longint);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button55Click(Sender: TObject);
    procedure Button17Click(Sender: TObject);
    procedure Button18Click(Sender: TObject);
    procedure Button54Click(Sender: TObject);
    procedure Button29Click(Sender: TObject);
    procedure Button26Click(Sender: TObject);
    procedure Button27Click(Sender: TObject);
    procedure Button28Click(Sender: TObject);
    procedure Button38Click(Sender: TObject);
    function  cdate(changedate: String)  :  string  ;
    procedure Button39Click(Sender: TObject);
    procedure CheckBox1Click(Sender: TObject);
    procedure CheckBox2Click(Sender: TObject);
    procedure CheckBox3Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure N4Click(Sender: TObject);
    procedure N5Click(Sender: TObject);
    procedure Button31Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

function GetVersionNum(buffer: pchar):integer;stdcall;
external 'function.dll';

function SetSerNum(newvalue:pchar; buffer: pchar):integer;stdcall;
external 'function.dll';

function GetSerNum(buffer: pchar):integer;stdcall;
external 'function.dll';

function MF_Read(mode:byte; add_blk,num_blk:integer; snr,buffer:pchar):integer;stdcall;
external 'function.dll';

function MF_Write(mode:byte; add_blk,num_blk:integer; snr,buffer:pchar):integer;stdcall;
external 'function.dll';

function MF_Getsnr(halt,mode:byte;  snr,value:pchar):integer;stdcall;
external 'function.dll';

function MF_Dec(mode:byte; SectNum:integer; snr,value:pchar):integer;stdcall;
external 'function.dll';

function MF_Inc(mode:byte; SectNum:integer; snr,value:pchar):integer;stdcall;
external 'function.dll';

function MF_InitValue(mode:byte; SectNum:integer; snr,value:pchar):integer;stdcall;
external 'function.dll';




function ControlLED(freq,duration:integer; buffer:pchar):integer;stdcall;
external 'function.dll';

function ControlBuzzer(freq,duration:integer; buffer:pchar):integer;stdcall;
external 'function.dll';

function ISO15693_Inventory(cardnumber:pchar; pBuffer:pchar):integer;stdcall;
external 'function.dll';

function ISO15693_Read(flags:byte; blk_add,num_blk:integer; uid,buffer:pchar):integer;stdcall;
external 'function.dll';

function ISO15693_Write(flags:byte; blk_add,num_blk:integer; uid,buffer:pchar):integer;stdcall;
external 'function.dll';


//14443 TYPE B  部分命令
function TYPEB_SFZSNR(halt,mode:byte;  snr,value:pchar):integer;stdcall;
external 'function.dll';

function TypeB_Request(buffer:pchar):integer;stdcall;
external 'function.dll';

function TypeB_TransCOS(cmd:pchar;cmdSize:integer; buffer:pchar):integer;stdcall;
external 'function.dll';



{6.2
  int   API_ISO15693Read	(
HANDLE        commHandle,
int              DeviceAddress,
unsigned char     flags,
unsigned char     blk_add,
unsigned char     num_blk,
unsigned char     *uid,
unsigned char     *buffer);
}



//Ultralight
function UL_Request(mode:byte;  snr:pchar):integer;stdcall;
external 'function.dll';

function MF_Halt():integer;stdcall;
external 'function.dll';

function UL_HLRead( mode:byte; blk_add:integer; snr,buffer:pchar):integer;stdcall;
external 'function.dll';

function UL_HLWrite( mode:byte; blk_add:integer; snr,buffer:pchar):integer;stdcall;
external 'function.dll';






var
  Form1: TForm1;
  comhandle : Thandle ;
  s100,reason:string;
implementation

uses Unit2;

{$R *.dfm}


procedure TForm1.Delay(MSecs: Longint);
//延时函数，MSecs单位为毫秒(千分之1秒)
var
  FirstTickCount, Now: Longint;
begin
  FirstTickCount := GetTickCount();
  repeat
    Application.ProcessMessages;
    Now := GetTickCount();
  until (Now - FirstTickCount >= MSecs) or (Now < FirstTickCount);
end;


procedure TForm1.checkdata(s:string);   //过虑数据中的空格和其它不合法字符
var                                     //所有过虑好的字符都放在S100里面
 temp:string;
 i:integer;
begin
for i:=1 to length(s) do
    begin
    if ((copy(s,i,1)>='0') and (copy(s,i,1)<='9'))or((copy(s,i,1)>='a') and (copy(s,i,1)<='f'))
        or((copy(s,i,1)>='A') and (copy(s,i,1)<='F')) then
      begin
        temp:=temp+copy(s,i,1);
      end;
    end;

    s100:='';

     for i:=0 to length(temp) div 2 - 1 do
      begin
       s100:=s100+copy(temp,(2*i+1),2);
      end;
end;

procedure TForm1.falsereason(s:string);
begin
     if s='' then begin reason:=''; exit; end;
     if s='00' then begin reason:=''; exit ; end;
     if s='1'  then begin reason:='Command false.....';   exit; end;
     if s='2'  then begin reason:='checksum error.....';  exit; end;
     if s='3'  then begin reason:='Not selected COM port.....';  exit; end;
     if s='4'  then begin reason:='time out reply.....';       exit; end;
     if s='5'  then begin reason:='check sequence error.....';    exit; end;
     if s='7'  then begin reason:='check sum error.....';   exit; end;
     if s='10' then begin reason:='the parameter value out of range.....';  exit; end;
     if s='80' then begin reason:='Command OK.....';    exit; end;
     if s='81' then begin reason:='Command FAILURE....';   exit; end;
     if s='82' then begin reason:='Reader reply time out error....';  exit; end;
     if s='83' then begin reason:='The card is not exist....';     exit; end;
     if s='84' then begin reason:='the data is error....';   exit; end;
     if s='85' then begin reason:='Reader received unknown command....';      exit; end;
     if s='87' then begin reason:='error....';    exit; end;
     if s='89' then begin reason:='The parameter of the command or the Format of the command Erro...';   exit; end;
     if s='8A' then begin reason:='Some Erro appear in the card InitVal process...';      exit; end;
     if s='8B' then begin reason:='Get The Wrong Snr during anticollison loop....';       exit; end;
     if s='8C' then begin reason:='The authentication failure....';    exit; end;
     if s='8F' then begin reason:='Reader received unknown command....';   exit; end;
     if s='90' then begin reason:='The Card do not support this command....';   exit; end;
     if s='91' then begin reason:='The Foarmat Of  The Command Erro....';        exit; end;
     if s='92' then begin reason:='Do not support Option mode....';     exit; end;
     if s='93' then begin reason:='The Block Do Not Exist....';   exit; end;
     if s='94' then begin reason:='The Object have been locked....';   exit; end;
     if s='95' then begin reason:='The lock Operation Do Not Success....';  exit; end;
     if s='96' then begin reason:='The Operation Do Not Success....';   exit; end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  PageControl1.TabWidth := (PageControl1.Width div 6) - 1;
  pagecontrol1.ActivePageIndex:=00;
  listbox1.ItemIndex:=00;
  listbox2.ItemIndex:=04;
end;

procedure TForm1.SetserNumumberClick(Sender: TObject);
var
 buffer :array [0..255] of char;
 receive,i :integer;
 Sernum:string;
 key : pchar;
begin

    s100:=edit2.Text;
    checkdata(s100);   //过虑数据中的多余的字符
    setlength(Sernum,8);      //转化数据

    for i:=1 to 8 do
    begin
      Sernum[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;

    key:=StrPCopy(buffer,Sernum);

     for i:=1 to 8 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= Sernum[i];
    end;



 receive:=SetSerNum(key,@buffer[1]);
 if (receive=0) then
  begin
   showm.Lines.Add('success');
   falsereason(inttohex(ord(buffer[1]),2));
   showm.Lines.Add(reason+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
  end;
end;


procedure TForm1.ReadserNumClick(Sender: TObject);
var
 receivedata :string;
 receive,i:integer;
  buffer:array [1..6] of integer;
  buffer1:array [0..63] of char;
begin

  receive:= GetSerNum(buffer1);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=1 to 8 do
    begin
     receivedata:=receivedata+ inttohex(ord(buffer1[i]),2)+' ';
    end;
     showm.Lines.Add(receivedata+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

procedure TForm1.Button3Click(Sender: TObject);
var
 mode:byte;
 add_blk,num_blk:byte;
 buffer,bufferr:array [0..255] of char;
 receive,i :integer;
 keydata,cardnum,carddata,showmemo:string;
 key : pchar;
begin
  if reqi.Checked and keya.Checked then mode:=$00;
  if reqi.Checked and keyb.Checked then mode:=$02;
  if reqa.Checked and keya.Checked then mode:=$01;
  if reqa.Checked and keyb.Checked then mode:=$03;
  add_blk:=strtoint('$'+ComboBox5.Text);
  num_blk:=strtoint('$'+ComboBox6.Text);


   s100:=ComboBox4.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(keydata,6);      //转化数据
    for i:=1 to 6 do
    begin
      keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;
    key:=StrPCopy(buffer,keydata);    //得到指针

    for i:=1 to 6 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;

    receive:=MF_Read(mode,add_blk,num_blk,key,bufferr);
//读出来的东西放在 buffer（ 4个字节的卡号）和 bufferr 里面 （ 读取到的数据(具体数量为： num_blk*16)）

    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..'+FormatDateTime('hh:mm:ss AM/PM', Now()));
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
       end;
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum);
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to strtoint('$'+inttohex(num_blk,2))*16-1 do
       begin
        carddata:=carddata+ inttohex(ord(bufferr[i]),2)+' ';
       end;
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the card data is ：'+carddata+#13#10);
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false'+FormatDateTime('hh:mm:ss AM/PM', Now()));
       showmemo:=inttohex(ord(bufferr[0]),2);
       falsereason(inttohex(ord(bufferr[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);
      end;
     end;
end;

procedure TForm1.Clear1Click(Sender: TObject);
begin
  showm.Clear;
end;

procedure TForm1.Save1Click(Sender: TObject);
begin
  savedialog1.Title:='Save as！' ;
  SaveDialog1.filter:='text(.txt)|*.txt';
  if(savedialog1.Execute()) then
  showm.Lines.SaveToFile(SaveDialog1.filename);
end;

procedure TForm1.SelectAll1Click(Sender: TObject);
begin
  showm.SelectAll;
end;

procedure TForm1.Copy1Click(Sender: TObject);
begin
  showm.CopyToClipboard;
end;

procedure TForm1.Paste1Click(Sender: TObject);
begin
  Showm.PasteFromClipboard;
end;

procedure TForm1.Cut1Click(Sender: TObject);
begin
  showm.CutToClipboard;
end;

procedure TForm1.Button4Click(Sender: TObject);
var
 mode:byte;
 add_blk,num_blk:byte;
 buffer,bufferr:array [0..255] of char;
 receive,i :integer;
 test,keydata,writedata,cardnum:string;
 key,keywrite : pchar;
begin
  if reqii.Checked and keyaa.Checked then mode:=$00;
  if reqii.Checked and keybb.Checked then mode:=$02;
  if reqaa.Checked and keyaa.Checked then mode:=$01;
  if reqaa.Checked and keybb.Checked then mode:=$03;
  add_blk:=strtoint('$'+ComboBox7.Text);
  num_blk:=strtoint('$'+ComboBox8.Text);
    //开始处理密钥匙
   s100:=ComboBox9.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(keydata,6);      //转化数据
    for i:=1 to 6 do
    begin
      keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;
    key:=StrPCopy(buffer,keydata);    //得到指针


    for i:=1 to 6 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;



      //结束处理密钥

      //开始处理待写数据
   S100:='';
   test:='';
   s100:=Edit3.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(writedata,num_blk*16);      //转化数据
   if length(s100)<>num_blk*32 then
    begin
     showmessage('input error,the data length is not accord,please checkout again.. ');
     exit;
    end;

    for i:=1 to 16*num_blk do
    begin

      writedata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;


    keywrite:=StrPCopy(bufferr,writedata);    //得到指针
      //结束处理待写数据


    for i:=1 to 16*num_blk do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      bufferr[i-1]:= writedata[i];
    end;


    receive:=MF_Write(mode,add_blk,num_blk,key,keywrite);
//读出来的东西放在 buffer（ 4个字节的卡号）里面

    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..');
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
       end;
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum+#13#10);
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false');
       falsereason(inttohex(ord(bufferr[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+#13#10);
      end;
     end;
  end;
procedure TForm1.Button2Click(Sender: TObject);
var
 buffer :array [0..255] of char;
 receive,i :integer;
 Sernum:string;
 key : pchar;
begin

 receive:=ControlLED(strtoint(ledfrq.Text),strtoint(leddur.Text),@buffer[1]);
 if (receive=0) then
  begin
   showm.Lines.Add('success'+#13#10);
//   falsereason(inttohex(ord(buffer[1]),2));
//   showm.Lines.Add(reason+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
  end;
end;


procedure TForm1.Button1Click(Sender: TObject);
var
 receivedata :string;
 receive,i:integer;
  buffer:array [1..6] of integer;
  buffer1:array [0..63] of char;
begin

 receive:=ControlBuzzer(strtoint(buzzerfrq.Text),strtoint(buzzerdur.Text),@buffer[1]);
  if (receive=0) then
  begin
   showm.Lines.Add('success'+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

procedure TForm1.Button6Click(Sender: TObject);
var
  card,receivedata,cardsnr :string;
  receive,i:integer;
  cardnumber:array [0..5] of char;
  cardnum:string;
  pBuffer:array [0..255] of char;
begin
  card:='';
  receive:=ISO15693_Inventory(cardnumber,pBuffer);
//  showm.Lines.Add(inttostr(receive));

  if (receive=0) then
   begin

      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..');
      showm.SelAttributes.Color := clWindowText;

      card:=inttohex(ord(cardnumber[0]),2);

      for i:=0 to 10*(strtoint(card))-1  do
       begin
        cardnum:=cardnum+ inttohex(ord(pBuffer[i]),2);
       end;



      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the card number is : '+ card);
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card datas is :'+cardnum);
      showm.SelAttributes.Color := clWindowText;

      cardsnr:=cardnum;

        try
          for i:=1 to strtoint(card) do
           begin
            showm.SelAttributes.Color := clMenuHighlight;
            cardsnr:=cdate(copy(cardnum,5+(i-1)*20,16));
            showm.Lines.Add('The '+inttostr(i)+'th card snr is  ：'+ cardsnr);
           end;
          except
            showm.Lines.Add('The card snr is not allow...');
         end;

      showm.Lines.Add('');

   end

   else

   begin
      if (receive=null) then begin  showm.Lines.Add('error,no data receive...');  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false'+FormatDateTime('hh:mm:ss AM/PM', Now()));
       falsereason(inttohex(ord(cardnumber[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);
      end;
   end

end;

function TForm1.cdate(changedate: String)  :  string  ;     //倒置数据
var
  i: integer;
  sdata: string;
begin
  sdata:='';
  for i:=1 to length(changedate) div 2  do
   begin
    sdata:=sdata + copy(changedate,length(changedate) - (2*i-1), 2 )+ ' ';
   end;
  Result:=sdata;
end;

procedure TForm1.Button55Click(Sender: TObject);
var
mode:byte;
 receivedata :string;
 receive,i:integer;
  snr:array [0..63] of char;
begin
  if Uli.Checked
   then    mode:=$00
   else    mode:=$01;

  receive:= UL_Request(mode,snr);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=0 to 6 do
    begin
     receivedata:=receivedata+ inttohex(ord(snr[i]),2)+' ';
    end;
     showm.Lines.Add('the card snr is.. '+receivedata+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(snr[0]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

procedure TForm1.Button17Click(Sender: TObject);
var
mode:byte;
 receivedata :string;
 receive,i:integer;
  buffer:array [1..6] of integer;
  snr:array [0..63] of char;
begin
  receive:= MF_Halt();
  if (receive=0) then
  begin
   showm.Lines.Add('success'+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(snr[0]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

procedure TForm1.Button18Click(Sender: TObject);
var
  mode:byte;
   receivedata :string;

   blk_add:byte;
   snr,buffer:array [0..255] of char;
   receive,i :integer;

begin
   blk_add:=strtoint(ListBox1.Items.Strings[ListBox1.ItemIndex]);
   if Ulii.Checked  then mode:=$00;
   if Ulaa.Checked  then mode:=$01;

   receive:=UL_HLRead(mode,blk_add,snr,buffer);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=0 to 6 do
    begin
     receivedata:=receivedata+ inttohex(ord(snr[i]),2)+' ';
    end;
     showm.Lines.Add('the card snr is.. '+receivedata);

     receivedata:='';
   for i:=0 to 15 do
    begin
     receivedata:=receivedata+ inttohex(ord(buffer[i]),2)+' ';
    end;
     showm.Lines.Add('the card data is.. '+receivedata+#13#10);

  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[0]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;


procedure TForm1.Button54Click(Sender: TObject);
var
  mode:byte;
   receivedata :string;
   blk_add:byte;
   snr,buffer:array [0..255] of char;
   receive,i :integer;
   keydata,cardnum,carddata,showmemo:string;
   key : pchar;
begin
   blk_add:=strtoint(ListBox1.Items.Strings[ListBox2.ItemIndex]);
   if Uliii.Checked  then mode:=$00;
   if Ulaaa.Checked  then mode:=$01;

   s100:=Edit56.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(keydata,6);      //转化数据
    for i:=1 to 4 do
    begin
      keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;
    key:=StrPCopy(buffer,keydata);    //得到指针

    for i:=1 to 4 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;


   receive:=UL_HLWrite(mode,blk_add,snr,key);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=0 to 6 do
    begin
     receivedata:=receivedata+ inttohex(ord(snr[i]),2)+' ';
    end;
     showm.Lines.Add('the card snr is.. '+receivedata+#13#10);


  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(snr[0]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

procedure TForm1.Button29Click(Sender: TObject);
var
 mode,halt:byte;
 snr,value:array [0..255] of char;
 receive,i :integer;
 cardnum,carddata,showmemo:string;
 key : pchar;
begin
  if reql5.Checked  then  mode:=$26
                    else  mode:=$52;

  if nohalt.Checked then  halt:=$00
                    else  halt:=01;

    receive:= MF_Getsnr(mode,halt,snr,value);

    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..'+FormatDateTime('hh:mm:ss AM/PM', Now()));
      showm.SelAttributes.Color := clWindowText;

      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(value[i]),2)+' ';
       end;
      carddata:=inttohex(ord(snr[0]),2);


      showm.SelAttributes.Color := clMenuHighlight;
      if carddata='00' then  showm.Lines.Add('It is only one card...')
                       else  showm.Lines.Add('It is more than one card...');
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum);
      showm.Lines.Add('');
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false'+FormatDateTime('hh:mm:ss AM/PM', Now()));
       showmemo:=inttohex(ord(snr[0]),2);
       falsereason(inttohex(ord(snr[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);
      end;
     end;
end;




procedure TForm1.Button26Click(Sender: TObject);
var
 mode:byte;
 add_blk,num_blk:byte;
 buffer,bufferr:array [0..255] of char;
 SectNum,receive,i :integer;
 keydata,writedata,cardnum:string;
 key,keywrite : pchar;
begin
  if reql2.Checked and keya2.Checked then mode:=$00;
  if reql2.Checked and keyb2.Checked then mode:=$02;
  if reqa2.Checked and keya2.Checked then mode:=$01;
  if reqa2.Checked and keyb2.Checked then mode:=$03;
  sectNum:=strtoint('$'+Edit57.Text);         //要初始化的扇区号00-0F

    //开始处理密钥匙
  s100:=Edit58.Text;
  checkdata(s100);  //过虑数据中的多余的字符
  setlength(keydata,6);      //转化数据
  for i:=1 to 6 do
  begin
    keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
  end;
  key:=StrPCopy(buffer,keydata);    //得到指针
      //结束处理密钥

   for i:=1 to 6 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;

      //开始处理扇区数据
   S100:='';
   s100:=Edit59.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(writedata,4);      //转化数据
    for i:=1 to 4 do
    begin
      writedata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;
    keywrite:=StrPCopy(bufferr,writedata);    //得到指针
      //结束处理待写数据


    for i:=1 to 4 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      bufferr[i-1]:= writedata[i];
    end;


    receive:=MF_InitValue(mode,sectNum,key,keywrite);
//读出来的东西放在 buffer（ 4个字节的卡号）里面


    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..');
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
       end;
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum+#13#10);
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false');
       falsereason(inttohex(ord(buffer[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+#13#10);
      end;
     end;
  end;

procedure TForm1.Button27Click(Sender: TObject);
var
 mode:byte;
 add_blk,num_blk:byte;
 buffer,bufferr:array [0..25] of char;
 SectNum,receive,i :integer;
 keydata,writedata,cardnum,carddata:string;
 key,keywrite : pchar;
begin
  if reql3.Checked and keya3.Checked then mode:=$00;
  if reql3.Checked and keyb3.Checked then mode:=$02;
  if reqa3.Checked and keya3.Checked then mode:=$01;
  if reqa3.Checked and keyb3.Checked then mode:=$03;
  sectNum:=strtoint('$'+Edit62.Text);         //要初始化的扇区号00-0F

    //开始处理密钥匙
  s100:=Edit63.Text+Edit64.Text;
  checkdata(s100);  //过虑数据中的多余的字符
  setlength(keydata,10);      //转化数据
  for i:=1 to 10 do
  begin
    keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
  end;
  key:=StrPCopy(buffer,keydata);    //得到指针
      //结束处理密钥
    for i:=1 to 10 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;

            //开始处理扇区数据
   S100:='';
   s100:=Edit64.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(writedata,4);      //转化数据
    for i:=1 to 4 do
    begin
      writedata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;
    keywrite:=StrPCopy(bufferr,writedata);    //得到指针
      //结束处理待写数据

     for i:=1 to 4 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      bufferr[i-1]:= writedata[i];
    end;


    receive:=MF_Dec(mode,sectNum,key,keywrite); //API_PCDDec
//读出来的东西放在 buffer（ 4个字节的卡号）里面

    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..');
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
       end;

       for i:=0 to 3  do
       begin
        carddata:=carddata+ inttohex(ord(bufferr[i]),2)+' ';
       end;

      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum);
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the value is :'+carddata+#13#10);
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false');
       falsereason(inttohex(ord(buffer[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+#13#10);
      end;
     end;
  end;

procedure TForm1.Button28Click(Sender: TObject);
var
 mode:byte;
 add_blk,num_blk:byte;
 buffer,buffertest:array [0..255] of char;
 SectNum,receive,i :integer;
 test,keydata,writedata,cardnum,carddata:string;
 key,keywrite : pchar;
begin
  if reql4.Checked and keya4.Checked then mode:=$00;
  if reql4.Checked and keyb4.Checked then mode:=$02;
  if reqa4.Checked and keya4.Checked then mode:=$01;
  if reqa4.Checked and keyb4.Checked then mode:=$03;
  sectNum:=strtoint('$'+Edit66.Text);         //要初始化的扇区号00-0F

    //开始处理密钥匙
  s100:=Edit67.Text;
  checkdata(s100);  //过虑数据中的多余的字符
  setlength(keydata,6);      //转化数据
  for i:=1 to 6 do
  begin
    keydata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
  end;
  key:=StrPCopy(buffer,keydata);    //得到指针
      //结束处理密钥

  for i:=1 to 6 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffer[i-1]:= keydata[i];
    end;


      //开始处理扇区数据
   S100:='';
   s100:=Edit68.Text;
   checkdata(s100);  //过虑数据中的多余的字符
   setlength(writedata,4);      //转化数据
   test:='';
    for i:=1 to 4 do
    begin
      writedata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
      test := test+Copy(s100,2*i-1,2);
    end;
    keywrite:=StrPCopy(buffertest,writedata);    //得到指针
      //结束处理待写数据

    for i:=1 to 4 do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      buffertest[i-1]:= writedata[i];
    end;


    receive:=MF_Inc(mode,sectNum,key,keywrite);
//读出来的东西放在 buffer（ 4个字节的卡号）里面


    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..');
      showm.SelAttributes.Color := clWindowText;
      for i:=0 to 3  do
       begin
        cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
       end;

       for i:=0 to 3  do
       begin
        carddata:=carddata+ inttohex(ord(buffertest[i]),2)+' ';
       end;

      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum);
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the value is :'+carddata+#13#10);
      showm.SelAttributes.Color := clWindowText;

      end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false');
       falsereason(inttohex(ord(buffer[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+#13#10);
      end;
     end;
  end;


{6.2
  int   API_ISO15693Read	(
HANDLE        commHandle,
int              DeviceAddress,
unsigned char     flags,
unsigned char     blk_add,
unsigned char     num_blk,
unsigned char     *uid,
unsigned char     *buffer);
}
procedure TForm1.Button38Click(Sender: TObject);
var
 uid,buffer :array [0..255] of char;
 receive,i :integer;
 Sernum,cardnum:string;
 key : pchar;
begin
  cardnum:='';
  receive:=ISO15693_Read(strtoint('$'+flagr.Text),strtoint(startr.Text),strtoint(numberr.Text),@uid,@buffer[1]);
  //function ISO15693_Read(flags:byte; blk_add,num_blk:integer; uid,buffer:pchar):integer;stdcall;

 if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=2 to (strtoint(numberr.Text)*4+1)  do
    begin
      cardnum:=cardnum+ inttohex(ord(buffer[i]),2)+' ';
    end;
    showm.Lines.Add('the card datas is : '+cardnum+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
  end;
end;

procedure TForm1.Button39Click(Sender: TObject);
var
 uid,buffer,bufferr :array [0..255] of char;
 receive,i,num_blk :integer;
 Sernum,cardnum,writedata:string;
 key,keywrite : pchar;
begin
  cardnum:='';
  s100:=dataw.Text;
  checkdata(s100);  //过虑数据中的多余的字符
  writedata:=s100;
  num_blk:=strtoint(numberw.Text);

   setlength(writedata,num_blk*4);      //转化数据
   if length(s100)<>num_blk*8 then
    begin
     showmessage('input error,the data length is not accord,please checkout again.. ');
     exit;
    end;
    for i:=1 to 4*num_blk do
    begin
      writedata[i]:=Chr(StrToInt('$'+Copy(s100,2*i-1,2)));
    end;

    keywrite:=StrPCopy(bufferr,writedata);    //得到指针
      //结束处理待写数据

    for i:=1 to 4*num_blk do    //这一步需要加，因为StrPCopy见到0就返回，可能产生见到0就不能继续的现象
    begin
      bufferr[i-1]:= writedata[i];
    end;




  receive:=ISO15693_Write(strtoint('$'+flagw.Text),strtoint(startw.Text),strtoint(numberw.Text),@uid,keywrite);

 if (receive=0) then
  begin
   showm.Lines.Add('success'+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(bufferr[0]),2));     
     showm.Lines.Add(reason+#13#10);
    end;
  end;
end;

procedure TForm1.CheckBox1Click(Sender: TObject);
begin
   if checkbox1.checked then
  repeat
    button3.click();
    delay(10);
  until
     checkbox1.checked=false;
end;

procedure TForm1.CheckBox2Click(Sender: TObject);
begin
   if checkbox2.checked then
  repeat
    button4.click();
    delay(10);
  until
     checkbox2.checked=false;
end;

procedure TForm1.CheckBox3Click(Sender: TObject);
begin
   if checkbox3.checked then
  repeat
    button29.click();
    delay(10);
  until
     checkbox3.checked=false;
end;

procedure TForm1.Button7Click(Sender: TObject);
var
 mode,halt:byte;
 snr,value:array [0..255] of char;
 receive,i :integer;
 cardnum,carddata,showmemo:string;
 key : pchar;
begin
    mode:=$26;
    halt:=$00;

    receive:=TYPEB_SFZSNR(mode,halt,snr,value);

    if receive=0 then
     begin
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('success..'+FormatDateTime('hh:mm:ss AM/PM', Now()));
      showm.SelAttributes.Color := clWindowText;

      for i:=0 to 7  do
       begin
        cardnum:=cardnum+ inttohex(ord(value[i]),2)+' ';
       end;

      carddata:=inttohex(ord(snr[0]),2);


      showm.SelAttributes.Color := clMenuHighlight;
      if carddata='00' then  showm.Lines.Add('It is only one card...')
                       else  showm.Lines.Add('It is more than one card...');
      showm.SelAttributes.Color := clMenuHighlight;
      showm.Lines.Add('the receive card number is :'+cardnum);
      showm.Lines.Add('');
      showm.SelAttributes.Color := clWindowText;
     end

    else

     begin
     if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);  exit; end;
     if (receive=1) then
      begin
       showm.Lines.Add('false'+FormatDateTime('hh:mm:ss AM/PM', Now()));
       showmemo:=inttohex(ord(snr[0]),2);
       falsereason(inttohex(ord(snr[0]),2));
       showm.Lines.Add(reason+#13#10);
      end
     else
      begin
       falsereason(inttostr(receive));
       showm.Lines.Add('false,the reason is :'+reason+FormatDateTime('hh:mm:ss AM/PM', Now())+#13#10);
      end;
     end;
end;
procedure TForm1.N4Click(Sender: TObject);
begin
  application.Terminate;
end;

procedure TForm1.N5Click(Sender: TObject);
begin
  if Form2=nil then
   begin
    Form2:=TForm2.create(Application);
    Form2.ShowModal();
   end
  else
    Form2.Showmodal();
    Form2.Free;
    Form2:=nil;
end;

procedure TForm1.Button31Click(Sender: TObject);
var
 receivedata :string;
 receive,i:integer;
  buffer:array [1..6] of integer;
  buffer1:array [0..63] of char;
begin

  receive:= TypeB_Request(buffer1);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=1 to 8 do
    begin
     receivedata:=receivedata+ inttohex(ord(buffer1[i]),2)+' ';
    end;
     showm.Lines.Add(receivedata+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer1[0]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
  end;

procedure TForm1.Button8Click(Sender: TObject);
var
 receivedata :string;
 receive,i:integer;
  buffer:array [1..6] of integer;
  buffer1:array [0..63] of char;
begin

  receive:= GetVersionNum(buffer1);
  if (receive=0) then
  begin
   showm.Lines.Add('success');
   for i:=1 to 11 do
    begin
     receivedata:=receivedata+ inttohex(ord(buffer1[i]),2)+' ';
    end;
     showm.Lines.Add(receivedata+#13#10);
  end
 else
  begin
   if (receive=null) then begin  showm.Lines.Add('error,no data receive...'+#13#10);  exit; end;
   if (receive<>null) then
    begin
     showm.Lines.Add('false');
     falsereason(inttostr(receive));
     showm.Lines.Add(reason);
     reason:='';
     falsereason(inttohex(ord(buffer[1]),2));
     showm.Lines.Add(reason+#13#10);
    end;
   end;
end;

end.



