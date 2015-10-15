#include "stdafx.h"
#include "Read.h"

CReader::CReader()
{
	LoadDll();
	
}
CReader::~CReader()
{
	CloseDll();
}

int CReader::LoadDll()
{
	char buf[1024];
	GetCurrentDirectory(1024, buf);

	CString str;
	str.Format("%s", buf);
	m_hInstMaster = LoadLibrary(".\\function.dll");	
	if(!m_hInstMaster)
	{
		DWORD er = GetLastError();
		MessageBox(NULL, "调用读写器动态连接库(function.dll)失败!", "警  告", MB_OK | MB_ICONERROR);
		exit(0);
	}
	
	(FARPROC &)MF_Read        = GetProcAddress(m_hInstMaster, _T("MF_Read"));
	(FARPROC &)MF_Write       = GetProcAddress(m_hInstMaster, _T("MF_Write"));
	(FARPROC &)MF_InitValue   = GetProcAddress(m_hInstMaster, _T("MF_InitValue"));
	(FARPROC &)MF_Dec         = GetProcAddress(m_hInstMaster, _T("MF_Dec"));
	(FARPROC &)MF_Inc         = GetProcAddress(m_hInstMaster, _T("MF_Inc"));
	(FARPROC &)MF_Halt        = GetProcAddress(m_hInstMaster, _T("MF_Halt"));

	(FARPROC &)ControlLED           = GetProcAddress(m_hInstMaster, _T("ControlLED"));
    (FARPROC &)ControlBuzzer        = GetProcAddress(m_hInstMaster, _T("ControlBuzzer"));
	(FARPROC &)MF_Getsnr            = GetProcAddress(m_hInstMaster, _T("MF_Getsnr"));
	(FARPROC &)GetVersionNum        = GetProcAddress(m_hInstMaster, _T("GetVersionNum"));
    (FARPROC &)SetSerNum            = GetProcAddress(m_hInstMaster, _T("SetSerNum"));
	(FARPROC &)GetSerNum            = GetProcAddress(m_hInstMaster, _T("GetSerNum"));

	(FARPROC &)TypeB_Request        = GetProcAddress(m_hInstMaster, _T("TypeB_Request"));
    (FARPROC &)TYPEB_SFZSNR         = GetProcAddress(m_hInstMaster, _T("TYPEB_SFZSNR"));
	(FARPROC &)TypeB_TransCOS		= GetProcAddress(m_hInstMaster, _T("TypeB_TransCOS"));

    (FARPROC &)ISO15693_Inventory   = GetProcAddress(m_hInstMaster, _T("ISO15693_Inventory"));
    (FARPROC &)ISO15693_Read        = GetProcAddress(m_hInstMaster, _T("ISO15693_Read"));
	(FARPROC &)ISO15693_Write       = GetProcAddress(m_hInstMaster, _T("ISO15693_Write"));

    (FARPROC &)UL_Request           = GetProcAddress(m_hInstMaster, _T("UL_Request")); 
	(FARPROC &)UL_HLRead            = GetProcAddress(m_hInstMaster, _T("UL_HLRead")); 
    (FARPROC &)UL_HLWrite           = GetProcAddress(m_hInstMaster, _T("UL_HLWrite")); 


	if(MF_Read == NULL || 
	   MF_Write == NULL ||
	   MF_InitValue == NULL ||
	   MF_Dec == NULL ||
	   MF_Inc == NULL ||
	   MF_Getsnr == NULL ||
	   SetSerNum == NULL ||
	   GetSerNum == NULL ||
       ControlLED == NULL ||
	   ControlBuzzer == NULL ||
	   TypeB_Request == NULL ||
	   TYPEB_SFZSNR == NULL ||
	   GetVersionNum == NULL ||
	   TypeB_TransCOS == NULL ||
	   ISO15693_Inventory == NULL ||
	   ISO15693_Read == NULL ||
	   ISO15693_Write == NULL ||
	   UL_Request == NULL ||
	   MF_Halt == NULL ||
	   UL_HLRead == NULL ||
	   UL_HLWrite == NULL)
	{
		MessageBox(NULL, "调用读写器动态连接库的函数失败!", "警  告", MB_OK|MB_ICONERROR);
		exit(0);
		return 0;
	}
	
    return 1;
}

int CReader::CloseDll()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
{
	if(m_hInstMaster)
	{
		FreeLibrary(m_hInstMaster);

		MF_Read           = NULL;
		MF_Write          = NULL;
		MF_InitValue      = NULL;
		MF_Dec            = NULL;
		MF_Inc            = NULL;
		MF_Getsnr         = NULL;
		ControlBuzzer     = NULL;
		MF_Halt           = NULL;

		TypeB_Request     = NULL;
        TYPEB_SFZSNR      = NULL;
		TypeB_TransCOS	  = NULL;
		GetVersionNum     = NULL;
		UL_Request        = NULL;
		UL_HLRead         = NULL;
		UL_HLWrite        = NULL;

		return 1;
	}

	return 0;
}
