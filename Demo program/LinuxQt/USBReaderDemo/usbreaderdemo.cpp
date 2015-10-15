#include "usbreaderdemo.h"
#include <QMessageBox>

USBReaderDemo::USBReaderDemo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
    ui.setupUi(this);
}

QString USBReaderDemo::formatStr(QString str)
{
	QRegExp regExp("[^a-fA-F0-9]");
	return str.replace(regExp,"");
}

void USBReaderDemo::showStatue(QPlainTextEdit *text, int Code)
{
	QString msg;
	switch (Code)
	{
	case 0x00:
		msg = "Command succeed.....";
		break;
	case 0x01:
		msg = "Command failed.....";
		break;
	case 0x02:
		msg = "Checksum error.....";
		break;
	case 0x03:
		msg = "Not selected COM port.....";
		break;
	case 0x04:
		msg = "Reply time out.....";
		break;
	case 0x05:
		msg = "Check sequence error.....";
		break;
	case 0x07:
		msg = "Check sum error.....";
		break;
	case 0x0A:
		msg = "The parameter value out of range.....";
		break;
	case 0x80:
		msg = "Command OK.....";
		break;
	case 0x81:
		msg = "Command FAILURE.....";
		break;
	case 0x82:
		msg = "Reader reply time out error.....";
		break;
	case 0x83:
		msg = "The card does not exist.....";
		break;
	case 0x84:
		msg = "The data is error.....";
		break;
	case 0x85:
		msg = "Reader received unknown command.....";
		break;
	case 0x87:
		msg = "Error.....";
		break;
	case 0x89:
		msg = "The parameter of the command or the format of the command error.....";
		break;
	case 0x8A:
		msg = "Some error appear in the card InitVal process.....";
		break;
	case 0x8B:
		msg = "Get the wrong snr during anticollison loop.....";
		break;
	case 0x8C:
		msg = "The authentication failure.....";
		break;
	case 0x8F:
		msg = "Reader received unknown command.....";
		break;
	case 0x90:
		msg = "The card do not support this command.....";
		break;
	case 0x91:
		msg = "The foarmat of the command error.....";
		break;
	case 0x92:
		msg = "Do not support option mode.....";
		break;
	case 0x93:
		msg = "The block do not exist.....";
		break;
	case 0x94:
		msg = "The object have been locked.....";
		break;
	case 0x95:
		msg = "The lock operation do not success.....";
		break;
	case 0x96:
		msg = "The operation do not success.....";
		break;
	}
	//msg += '\n';
	text->appendPlainText(msg);
}

void USBReaderDemo::convertStr(unsigned char *after, QString before, int length)
{
	for(int i=0;i<length;i++)
	{
		after[i] = before.mid(2*i,2).toInt(0,16);
	}
}

void USBReaderDemo::showData(QPlainTextEdit *text, unsigned char *data, int position, int length)
{
	QString msg = "";
	for(int i=0;i<length;i++)
	{
		msg += QString("%1").arg(int(data[position+i]), 2, 16, QChar('0')).toUpper() + ' ';
	}
	text->appendPlainText(msg);
}

void USBReaderDemo::showData(QPlainTextEdit *text,char *data, int position, int length)
{
	for(int i=0;i<length;i++)
	{
		if(data[position+i]<0)
			data[position+i] += 256;
	}
	showData(text, (unsigned char*)data, position, length);
}

//System Setting

void USBReaderDemo::on_setsernumButton_clicked()
{
	unsigned char buffer;
	unsigned char newValue[8] = {0};
	QString serNum = formatStr(ui.sernumEdit->text());
	convertStr(newValue,serNum,8);
    int result = API_SetSerNum(newValue,&buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_readsernumButton_clicked()
{
	try
	{
		unsigned char buffer[9] = {0};
        int result = API_GetSerNum(buffer);
        QPlainTextEdit *text = ui.dataEdit;
		showStatue(text, result);
		showData(text,buffer,1,8);
		text->appendPlainText(""); //new line
	}
	catch(...)
	{}
}

void USBReaderDemo::on_setledButton_clicked()
{
	int freq = ui.ledcycleEdit->text().toInt();
	int duration = ui.ledtimesEdit->text().toInt();
	unsigned char buffer;
    int result = API_ControlLED(freq, duration, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_setbuzzerButton_clicked()
{
	int freq = ui.bzrcycleEdit->text().toInt();
	int duration = ui.bzrtimesEdit->text().toInt();
	unsigned char buffer;
    int result = API_ControlBuzzer(freq, duration, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_getverButton_clicked()
{
    char VersionNum[256] = {0};	//version number
    int result = GetVersionNum(VersionNum);
    QPlainTextEdit *text = ui.dataEdit;
    showStatue(text, result);
    if (result == 0)
        showData(text,VersionNum, 1, 20);
    else
        showStatue(text, VersionNum[0]);
    text->appendPlainText(""); //new line

}

////14443A-MF
void USBReaderDemo::on_mfRead_clicked()
{
	unsigned char mode1 = ui.readKeyB->isChecked();
	unsigned char mode2 = ui.readAll->isChecked();
	unsigned char mode = (mode1<<1) | mode2;	//reading model
	unsigned char blk_add = ui.readStart->currentText().toInt(0,16);	//block address
	unsigned char num_blk = ui.readNum->currentText().toInt(0,16);	//block number
    unsigned char snr[6];	//key
	QString snrStr = formatStr(ui.readKey->currentText());	//format the string
	convertStr(snr, snrStr, 6);	//conert to unsigned char
	unsigned char *buffer = new unsigned char[16*num_blk];	//data read
	
    int result = API_PCDRead(mode,blk_add,num_blk,snr,buffer);

	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,4);
		text->appendPlainText("The card data:");
		showData(text,buffer,0,16*num_blk);
	}
	else
        showStatue(text, snr[0]);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_mfWrite_clicked()
{
	unsigned char mode1 = ui.writeKeyB->isChecked();
	unsigned char mode2 = ui.writeAll->isChecked();
	unsigned char mode = (mode1<<1) | mode2;	//writing model
	unsigned char blk_add = ui.writeStart->currentText().toInt(0,16);	//block address
	unsigned char num_blk = ui.writeNum->currentText().toInt(0,16);	//block number
    unsigned char snr[6];	//key
	QString snrStr = formatStr(ui.writeKey->currentText());	//format the string
	convertStr(snr, snrStr, 6);	//conert to unsigned char
	unsigned char *buffer = new unsigned char[16*num_blk];	//data write
	QString bufferStr = formatStr(ui.writeData->text());
	convertStr(buffer,bufferStr,16*num_blk);
	
    int result = API_PCDWrite(mode,blk_add,num_blk,snr,buffer);

	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,4);
	}
	else
        showStatue(text, snr[0]);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_mfInit_clicked()
{
	unsigned char mode1 = ui.initKeyB->isChecked();
	unsigned char mode2 = ui.initAll->isChecked();
	unsigned char mode = (mode1<<1) | mode2;	//reading model
	unsigned char SectNum = ui.initSector->text().toInt(0,16); //sector 
    unsigned char snr[6];	//key
	QString snrStr = formatStr(ui.initKey->text());	//format the string
	convertStr(snr, snrStr, 6);	//conert to unsigned char
	unsigned char value[4];	//initialize value
	QString valueStr = formatStr(ui.initValue->text());	//format the string
	convertStr(value, valueStr, 4);	//conert to unsigned char
	
    int result = API_PCDInitVal(mode, SectNum, snr, value);

	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,4);
	}
	else
		showStatue(text, snr[0]);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_mfDeval_clicked()
{
	unsigned char mode1 = ui.decKeyB->isChecked();
	unsigned char mode2 = ui.decAll->isChecked();
	unsigned char mode = (mode1<<1) | mode2;	//reading model
	unsigned char SectNum = ui.decSector->text().toInt(0,16); //sector 
    unsigned char snr[6];	//key
	QString snrStr = formatStr(ui.decKey->text());	//format the string
	convertStr(snr, snrStr, 6);	//conert to unsigned char
	unsigned char value[4];	//initialize value
	QString valueStr = formatStr(ui.decValue->text());	//format the string
	convertStr(value, valueStr, 4);	//conert to unsigned char
	
    int result = API_PCDDec(mode, SectNum, snr, value);

	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,4);
	}
	else
		showStatue(text, snr[0]);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_mfInval_clicked()
{
	unsigned char mode1 = ui.incKeyB->isChecked();
	unsigned char mode2 = ui.incAll->isChecked();
	unsigned char mode = (mode1<<1) | mode2;	//reading model
	unsigned char SectNum = ui.incSector->text().toInt(0,16); //sector 
    unsigned char snr[6];	//key
	QString snrStr = formatStr(ui.incKey->text());	//format the string
	convertStr(snr, snrStr, 6);	//conert to unsigned char
	unsigned char value[4];	//initialize value
	QString valueStr = formatStr(ui.incValue->text());	//format the string
	convertStr(value, valueStr, 4);	//conert to unsigned char
	
    int result = API_PCDInc(mode, SectNum, snr, value);

	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,4);
	}
	else
		showStatue(text, snr[0]);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_mfCardNum_clicked()
{

    unsigned char mode;
    if (ui.snrAll->isChecked())
        mode = 0x52;
    else
        mode = 0x26;
    unsigned char halt = ui.snrHalt->isChecked();
    unsigned char snr;
       unsigned char value[5];	//card number
    QString valueStr = formatStr(ui.incValue->text());	//format the string
    convertStr(value, valueStr, 4);	//conert to unsigned char
    int result = GET_SNR(mode, halt, &snr, value);
    QPlainTextEdit *text = ui.dataEdit;
    showStatue(text, result);
    if (result == 0)
    {
        if (snr==0x00)
            text->appendPlainText("Only one card.....");
        else
            text->appendPlainText("More than one card......");
        text->appendPlainText("The card number:");
        showData(text,value,0,4);
    }
    else
        showStatue(text, snr);
    text->appendPlainText(""); //new line
}

//Ultralight
void USBReaderDemo::on_utsnRead_clicked()
{
    unsigned char snr[7];
    unsigned char mode = ui.utsnAll->isChecked();
       int result = UL_Request(mode, snr);
    QPlainTextEdit *text = ui.dataEdit;
    showStatue(text, result);
    if (result == 0)
    {
        text->appendPlainText("The card number:");
        showData(text,snr,0,7);
    }
    else
        showStatue(text, snr[0]);
    text->appendPlainText(""); //new line
}

void USBReaderDemo::on_utHalt_clicked()
{
    int result = MF_Halt();
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text,result);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_utblockRead_clicked()
{
	unsigned char mode = ui.utreadAll->isChecked();
	unsigned char blk_add = ui.utreadBlock->currentItem()->text().toInt();
	unsigned char *snr = new unsigned char[7];
	unsigned char *buffer = new unsigned char[16];
    int result = UL_HLRead(mode,blk_add,snr,buffer);
	QPlainTextEdit *text = ui.dataEdit;
    showStatue(text, result);
	if (result == 0)
	{
		text->appendPlainText("The card number:");
		showData(text,snr,0,7);
		text->appendPlainText("The card data:");
		showData(text,buffer,0,16);
	}
	else
		showStatue(text,buffer[0]);
	text->appendPlainText(""); //new line
	delete[] snr;
	delete[] buffer;
}

void USBReaderDemo::on_utwriteWrite_clicked()
{
	unsigned char mode = ui.utwriteAll->isChecked();
	unsigned char blk_add = ui.utwriteBlock->currentItem()->text().toInt();
	unsigned char snr[7]={0};
	unsigned char buffer[4];
	QString bufferStr = formatStr(ui.utwriteData->text());
	convertStr(buffer, bufferStr, 4);
    int result = UL_HLWrite(mode,blk_add,snr,buffer);
	QPlainTextEdit *text = ui.dataEdit;
	if (result == 0)
	{
		showStatue(text, result);
		text->appendPlainText("The card number:");
		showData(text,snr,0,7);
	}
	else
		if (result == 10)
		{
			text->appendPlainText("False");
			showStatue(text, result);	
		}// something different
		else
			showStatue(text,snr[0]);
	text->appendPlainText(""); //new line
}

//14443B
void USBReaderDemo::on_BRequest_clicked()
{
	unsigned char *buffer = new unsigned char[256];
    int result = RequestType_B(buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if(result == 0)
	{
		text->appendPlainText("The datalength:");
		showData(text,buffer,0,1);
		text->appendPlainText("The data:");
		showData(text,buffer,1,buffer[0]);
	}
	else
		showStatue(text,buffer[0]);
	text->appendPlainText(""); //new line
	delete[] buffer;
}

void USBReaderDemo::on_BTransfer_clicked()
{
	int cmdSize = ui.Blength->text().toInt(0,16);
	unsigned char buffer[256];
	unsigned char *cmd = new unsigned char[cmdSize];
	QString cmdStr = formatStr(ui.BData->text());
	convertStr(cmd, cmdStr, cmdSize);
    int result = API_ISO14443TypeBTransCOSCmd(cmd, cmdSize,buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if(result == 0)
	{
		text->appendPlainText("The Data:");
		showData(text,buffer,0,8);
	}
	else
		showStatue(text, buffer[0]);
	text->appendPlainText(""); //new line
}

//15693
void USBReaderDemo::on_isoInventory_clicked()
{
	unsigned char Cardnumber;
    unsigned char pBuffer[256];
    unsigned char pData[] = "ddadsfsf";
    int result = API_ISO15693_Inventory(0x22,0,pData,&Cardnumber, pBuffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if(result==0)
	{
		text->appendPlainText("The card number:");
		text->appendPlainText(QString("%1").arg(Cardnumber,2,16,QChar('0')).toUpper());
		text->appendPlainText("The card data:");
		showData(text,pBuffer,0,10*Cardnumber);
		for (int i=0;i<Cardnumber;i++)
		{
			text->appendPlainText(QString("No.%1 card data:").arg(i+1));
			QString cardData;
			for (int j=0;j<8;j++)
			{
				cardData += QString("%1 ").arg(pBuffer[Cardnumber*10 - (i*10+j) - 1], 2, 16, QChar('0')).toUpper();
			}
			text->appendPlainText(cardData);
		}
	}
	else
		showStatue(text, Cardnumber);
	text->appendPlainText(""); //new line
}

void USBReaderDemo::on_isoRead_clicked()
{
	unsigned char flags = ui.isoreadFlag->text().toInt(0,16);
	unsigned char blk_add = ui.isoreadStart->text().toInt(0,16);
	unsigned char num_blk = ui.isoreadNum->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.isoreadUID->text());
	convertStr(uid,uidStr,8);
	unsigned char buffer[256];
	int n;
	if(flags == 0x42)
		n = 5;
	else
		n = 4;
    int result = API_ISO15693Read(flags,blk_add,num_blk,uid,buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text,result);
	if(result == 0)
	{
		text->appendPlainText("Flags:");
		showData(text,buffer,0,1);
		text->appendPlainText("The card data:");
		showData(text,buffer,1,n*num_blk);
	}
	else
		showStatue(text,buffer[0]);
	text->appendPlainText("");
}

void USBReaderDemo::on_isoWrite_clicked()
{
	unsigned char flags = ui.isowriteFlag->text().toInt(0,16);
	unsigned char blk_add = ui.isowriteStart->text().toInt(0,16);
	unsigned char num_blk = ui.isowriteNum->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.isoreadUID->text());
	convertStr(uid,uidStr,8);
	unsigned char data[256];
	int n;
	if(flags == 0x42)
		n = 5;
	else
		n = 4;
	QString dataStr = formatStr(ui.isowriteData->text());
	convertStr(data,dataStr,num_blk*n);
    int result = API_ISO15693Write(flags,blk_add,num_blk,uid,data);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text,result);
	if(result != 0)
		showStatue(text,data[0]);
	text->appendPlainText("");
}

//no data
void USBReaderDemo::on_isoGet_clicked()
{
	unsigned char flag = ui.isogetFlag->text().toInt(0,16);
	unsigned char uid[8];
	unsigned char Buffer[255]={0};
	QString uidStr = formatStr(ui.isogetUID->text());
	convertStr(uid,uidStr,8);
    int result = API_ISO15693_GetSysInfo(flag, uid, Buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	if ( result == 0 )
	{
		text->appendPlainText("Flags:");
		showData(text,Buffer,0,1);
		text->appendPlainText("INFO Flags:");
		showData(text,Buffer,1,1);
		text->appendPlainText("UID:");
		showData(text,Buffer,2,8);
		text->appendPlainText("DSFID:");
		showData(text,Buffer,10,1);
		text->appendPlainText("AFI");
		showData(text,Buffer,11,1);
		text->appendPlainText("Other fields:");
		showData(text,Buffer,12,5);
	}
	else 
		showStatue(text, Buffer[0]);
	text->appendPlainText("");
}

void USBReaderDemo::on_blockLock_clicked()
{
	unsigned char flags = ui.blklockFlag->text().toInt(0,16);
	unsigned char num_blk = ui.lockBlock->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.blklockUID->text());
	convertStr(uid,uidStr,8);
	unsigned char buffer;
    int result = API_ISO15693Lock(flags, num_blk, uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

void USBReaderDemo::on_cardSelect_clicked()
{
	unsigned char flags = ui.cardselFlag->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.cardselUID->text());
	convertStr(uid,uidStr,8);
	unsigned char buffer;
    int result = API_ISO15693Select(flags, uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

void USBReaderDemo::on_afiWrite_clicked()
{
	unsigned char flags = ui.afiwriteFlag->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.afiwriteUID->text());
	convertStr(uid,uidStr,8);
	unsigned char afi = ui.writeAFI->text().toInt(0,16);
	unsigned char buffer;
    int result = API_WriteAFI(flags, afi,uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

void USBReaderDemo::on_afiLock_clicked()
{
	unsigned char flags = ui.afilockFlag->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.afilockUID->text());
	convertStr(uid,uidStr,8);
	unsigned char buffer;
    int result = API_LockAFI(flags,uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

//Reader received unknown command
void USBReaderDemo::on_dsfidWrite_clicked()
{
	unsigned char flags = ui.dsfidwriteFlag->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.dsfidwriteUID->text());
	convertStr(uid,uidStr,8);
	unsigned char DSFID = ui.writeDSFID->text().toInt(0,16);
	unsigned char buffer;
    int result = API_WriteDSFID(flags, DSFID, uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

void USBReaderDemo::on_dsfidLock_clicked()
{
	unsigned char flags = ui.dsfidlockFlag->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.lockdsfidUID->text());
	convertStr(uid,uidStr,8);
	unsigned char buffer;
    int result = API_LockDSFID(flags,uid, &buffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text, result);
	showStatue(text, buffer);
	text->appendPlainText("");
}

//Check sequence error
void USBReaderDemo::on_blksecGet_clicked()
{
	unsigned char flags = ui.blksecFlag->text().toInt(0,16);
	unsigned char blkAddr = ui.blksecStart->text().toInt(0,16);
	unsigned char blkNum = ui.blksecNum->text().toInt(0,16);
	unsigned char uid[8];
	QString uidStr = formatStr(ui.blksecUID->text());
	convertStr(uid,uidStr,8);
	unsigned char *pBuffer = new unsigned char[blkNum+1];
    int result = API_ISO15693_GetMulSecurity(flags,blkAddr,blkNum,uid,pBuffer);
	QPlainTextEdit *text = ui.dataEdit;
	showStatue(text,result);
	if(result == 0)
	{
		text->appendPlainText("Flags:");
		showData(text,pBuffer,0,1);
		text->appendPlainText("The Block Security:");
		showData(text,pBuffer,1,blkNum);
	}
	else
		showStatue(text,pBuffer[0]);
	text->appendPlainText("");
}	

USBReaderDemo::~USBReaderDemo()
{

}
