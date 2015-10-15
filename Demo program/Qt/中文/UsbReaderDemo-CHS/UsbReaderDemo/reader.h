#ifndef	READER_H
#define READER_H

//#include "function.h"		
#include <QLibrary>
#include <QDebug>
#include "function.h"	

class Reader
{
public:


    Reader(QWidget *parent);
    ~Reader();

    bool LoadDll();
    bool CloseDll();

	//14443A-MF
    MF_Read_Func MF_Read;
    MF_Write_Func MF_Write;
    MF_InitValue_Func MF_InitValue;
    MF_Dec_Func MF_Dec;
    MF_Inc_Func MF_Inc;
    MF_Halt_Func MF_Halt;
    MF_Getsnr_Func MF_Getsnr;

	//System Setting
    ControlBuzzer_Func ControlBuzzer;
    ControlLED_Func ControlLED;
    GetVersionNum_Func GetVersionNum;
    SetSerNum_Func SetSerNum;
    GetSerNum_Func GetSerNum;

	//14443 B
    TypeB_Request_Func TypeB_Request;
    TYPEB_SFZSNR_Func TYPEB_SFZSNR;
	TypeB_TransCOS_Func TypeB_TransCOS;

	//Ultralight
    UL_Request_Func UL_Request;
    UL_HLRead_Func UL_HLRead;
    UL_HLWrite_Func UL_HLWrite;

	//ISO15693
    ISO15693_Inventory_Func ISO15693_Inventory;
    ISO15693_Read_Func ISO15693_Read;
    ISO15693_Write_Func ISO15693_Write;
	ISO15693_GetSysInfo_Func ISO15693_GetSysInfo;
	ISO15693_Lock_Func ISO15693_Lock;
	ISO15693_Select_Func ISO15693_Select;
	ISO15693_WriteAFI_Func ISO15693_WriteAFI;
	ISO15693_LockAFI_Func ISO15693_LockAFI;
	ISO15693_WriteDSFID_Func ISO15693_WriteDSFID;
	ISO15693_LockDSFID_Func ISO15693_LockDSFID;
	ISO15693_GetMulSecurity_Func ISO15693_GetMulSecurity;

private:
    QLibrary *functionLib;
    int DeviceAddress;
};

#endif
