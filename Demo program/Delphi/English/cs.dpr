program cs;

uses
  Windows,
  Messages,
  Dialogs,
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  Unit2 in 'Unit2.pas' {Form2};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'RFID';


  CreateMutex(nil, true, 'Project1');
  if GetLastError = ERROR_ALREADY_EXISTS then
  begin
    showmessage('The program is already opened , please donot open again.. ');
    Exit;
  end;

  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
