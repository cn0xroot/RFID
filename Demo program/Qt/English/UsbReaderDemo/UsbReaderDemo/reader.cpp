#include "reader.h"
#include<QMessageBox>

Reader::Reader(QWidget *parent)
{
	DeviceAddress = 0;
	functionLib = new QLibrary("function.dll");
	if (!LoadDll())
	{
		QMessageBox::critical(parent,"Error","Failed to load function.dll");
	}
}
Reader::~Reader()
{
	CloseDll();
}

bool Reader::LoadDll()
{
	if ( !functionLib->load() )
	{
		qDebug()<<"Failed to load function.dll";
		return false;
	}
	
	qDebug()<<"Succeed to load function.dll";

	//14443A-MF
	MF_Read        = (MF_Read_Func)functionLib->resolve("MF_Read");
	MF_Write       = (MF_Write_Func)functionLib->resolve("MF_Write");
	MF_InitValue   = (MF_InitValue_Func)functionLib->resolve("MF_InitValue");
	MF_Dec         = (MF_Dec_Func)functionLib->resolve("MF_Dec");
	MF_Inc         = (MF_Inc_Func)functionLib->resolve("MF_Inc");
	MF_Halt        = (MF_Halt_Func)functionLib->resolve("MF_Halt");
	MF_Getsnr            = (MF_Getsnr_Func)functionLib->resolve("MF_Getsnr");

	//System Setting
	ControlLED           = (ControlLED_Func)functionLib->resolve("ControlLED");
    ControlBuzzer        = (ControlBuzzer_Func)functionLib->resolve("ControlBuzzer");
	GetVersionNum        = (GetVersionNum_Func)functionLib->resolve("GetVersionNum");
    SetSerNum            = (SetSerNum_Func)functionLib->resolve("SetSerNum");
	GetSerNum            = (GetSerNum_Func)functionLib->resolve("GetSerNum");

	//14443 B
	TypeB_Request        = (TypeB_Request_Func)functionLib->resolve("TypeB_Request");
    TYPEB_SFZSNR         = (TYPEB_SFZSNR_Func)functionLib->resolve("TYPEB_SFZSNR");
	TypeB_TransCOS		 = (TypeB_TransCOS_Func)functionLib->resolve("TypeB_TransCOS");

	//ISO15693
    ISO15693_Inventory		= (ISO15693_Inventory_Func)functionLib->resolve("ISO15693_Inventory");
    ISO15693_Read			= (ISO15693_Read_Func)functionLib->resolve("ISO15693_Read");
	ISO15693_Write			= (ISO15693_Write_Func)functionLib->resolve("ISO15693_Write");
	ISO15693_GetSysInfo		= (ISO15693_GetSysInfo_Func)functionLib->resolve("ISO15693_GetSysInfo");
	ISO15693_Lock			= (ISO15693_Lock_Func)functionLib->resolve("ISO15693_Lock");
	ISO15693_Select			= (ISO15693_Select_Func)functionLib->resolve("ISO15693_Select");
	ISO15693_WriteAFI		= (ISO15693_WriteAFI_Func)functionLib->resolve("ISO15693_WriteAFI");
	ISO15693_LockAFI		= (ISO15693_LockAFI_Func)functionLib->resolve("ISO15693_LockAFI");
	ISO15693_WriteDSFID		= (ISO15693_WriteDSFID_Func)functionLib->resolve("ISO15693_WriteDSFID");
	ISO15693_LockDSFID		= (ISO15693_LockDSFID_Func)functionLib->resolve("ISO15693_LockDSFID");
	ISO15693_GetMulSecurity = (ISO15693_GetMulSecurity_Func)functionLib->resolve("ISO15693_GetMulSecurity");

	//Ultralight
    UL_Request           = (UL_Request_Func)functionLib->resolve("UL_Request"); 
	UL_HLRead            = (UL_HLRead_Func)functionLib->resolve("UL_HLRead"); 
    UL_HLWrite           = (UL_HLWrite_Func)functionLib->resolve("UL_HLWrite"); 

    if(//14443A
		MF_Read		 == NULL	|| 
	    MF_Write	 == NULL	||
	    MF_InitValue == NULL	||
	    MF_Dec		 == NULL	||	
	    MF_Inc		 == NULL	||
	    MF_Getsnr	 == NULL	||
	    MF_Halt		 == NULL	||

		//System Setting
	    SetSerNum		== NULL	||
	    GetSerNum		== NULL	||
        ControlLED		== NULL	||
	    ControlBuzzer	== NULL	||
	    GetVersionNum	== NULL	||

		//14443B
	    TypeB_Request	== NULL	||
	    TYPEB_SFZSNR	== NULL	||
	    TypeB_TransCOS	== NULL ||

		//ISO15693
   	    ISO15693_Inventory	== NULL ||
	    ISO15693_Read		== NULL	||
	    ISO15693_Write		== NULL ||
	    ISO15693_GetSysInfo == NULL ||
		ISO15693_Lock		== NULL ||
		ISO15693_Select		== NULL ||
		ISO15693_WriteAFI	== NULL ||
		ISO15693_LockAFI	== NULL ||
		ISO15693_WriteDSFID	== NULL ||
		ISO15693_LockDSFID	== NULL ||

		//Ultralight
	    UL_Request == NULL  ||
	    UL_HLRead  == NULL  ||
	    UL_HLWrite == NULL)
	{
		qDebug()<<"Failed to resolve function";
		return false;
	}
  qDebug()<<"Succeed to resolve function";
  return true;
}

bool Reader::CloseDll()
{
	if(functionLib)
	{
		functionLib->unload();
		return true;
	}
	return false;
}