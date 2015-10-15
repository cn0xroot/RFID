// SYSTEMSETTING.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "SYSTEMSETTING.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CSYSTEMSETTING dialog

CSYSTEMSETTING::CSYSTEMSETTING(CWnd* pParent /*=NULL*/)
	: CDialog(CSYSTEMSETTING::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSYSTEMSETTING)
	m_ser = _T("AA BB AA BB AA BB AA BB");
	m_buzzer_cycle = _T("18");
	m_buzzer_times = _T("09");
	m_led_cycle = _T("18");
	m_led_times = _T("09");
	//}}AFX_DATA_INIT
}

void CSYSTEMSETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSYSTEMSETTING)
	DDX_Text(pDX, IDC_EDIT1, m_ser);
	DDX_Text(pDX, IDC_BUZZERCYCLE, m_buzzer_cycle);
	DDX_Text(pDX, IDC_BUZZERTIMERS, m_buzzer_times);
	DDX_Text(pDX, IDC_LEDCYCLE, m_led_cycle);
	DDX_Text(pDX, IDC_LEDTIMES, m_led_times);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSYSTEMSETTING, CDialog)
	//{{AFX_MSG_MAP(CSYSTEMSETTING)
	ON_BN_CLICKED(IDC_BUTTON1, OnSetSerNum)
	ON_BN_CLICKED(IDC_BUTTON2, OnReadSerNum)
	ON_BN_CLICKED(IDC_BUTTON3, OnSetLED)
	ON_BN_CLICKED(IDC_BUTTON4, OnSetBuzzer)
	ON_BN_CLICKED(IDC_BUTTON5, OnGetVer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSYSTEMSETTING message handlers
int gethexvalue1(char p)
{
	switch(p)
	{
	case '0': return 0; 
	case '1': return 1;
	case '2': return 2; 
	case '3': return 3;
	case '4': return 4; 
	case '5': return 5;
	case '6': return 6; 
	case '7': return 7;
	case '8': return 8; 
	case '9': return 9;
	case 'a': return 10;
	case 'A': return 10;
	case 'b': return 11;
	case 'B': return 11;
	case 'c': return 12;  
	case 'C': return 12;
	case 'd': return 13; 
	case 'D': return 13;
	case 'e': return 14;
	case 'E': return 14;
	case 'f': return 15;
	case 'F': return 15;
	};
	return -1;
}

//if(GetData(buf,m_data,47))
int CSYSTEMSETTING::GetData(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	if(len < maxlen)
		return 1;
	
	for(i=0; i<16; i++)
	{
		int value = 0;
		value = gethexvalue1(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue1(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}
	
	return 0;
}

void CSYSTEMSETTING::OnSetSerNum() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	
	BYTE Snr[128];
	memset(Snr, 0, 128);

	BYTE buffer[128];
	memset(buffer, 0, 128);

	if(GetData(Snr, m_ser, 23))
	{
		pMem->SetSel(-1, -1);                            //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");       //自动换行
		return;
	}
	
    int re = 0;
	
	re = pReader->SetSerNum(Snr, buffer);

	if(re == 0)
	{
        pMem->SetSel(-1, -1);                                     //自动滚屏
        pMem->ReplaceSel("\nSuccess: " + m_ser + "\r\n\r\n");    //自动换行

		return;
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");

			pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
		}
		
		if(re != NULL)
		{
            CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			

            pMem->SetSel(-1, -1);                                            //自动滚屏
            pMem->ReplaceSel("false, the reason is :" + reason + "\r\n");    //自动换行


			char buf1[256];
			sprintf(buf1, "%02X", buffer[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
            pMem->SetSel(-1, -1);                           //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");         //自动换行
		}
	}
}

void CSYSTEMSETTING::OnReadSerNum() 
{
	// TODO: Add your control notification handler code here

    BYTE buffer[100];
	memset(buffer, 0, 100);

	int re = 0;
	re = pReader->GetSerNum(buffer);

	if(re == 0)
	{
        CString str;
		str.Format("success  %02x %02x %02x %02x %02x %02x %02x %02x\n", buffer[1], buffer[2], buffer[3], 
			buffer[4], buffer[5], buffer[6], buffer[7], buffer[8]);

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");
			
            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行 
		}

		if(re != NULL)
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			

			pMem->SetSel(-1, -1);                                            //自动滚屏
            pMem->ReplaceSel("false, the reason is :" + reason + "\r\n");    //自动换行 

			
			char buf1[256];
			sprintf(buf1, "%02X", buffer[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
            pMem->SetSel(-1, -1);                         //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");       //自动换行 
		}
	}
}

void CSYSTEMSETTING::OnSetLED() 
{
	// TODO: Add your control notification handler code here
    UpdateData(true);
	
    int cycle = atoi(m_led_cycle);

    int times = atoi(m_led_times);

	BYTE buf[1024];
	memset(buf, 0, 1024);

	int re = 0;
	re = pReader->ControlLED(cycle, times, buf);
	if(re == 0)
	{
		CString str;
		str.Format("success\n");
      
		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");
			
			pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行	
		}
		
		if(re != NULL)
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			
			pMem->SetSel(-1, -1);                          //自动滚屏
            pMem->ReplaceSel("false " + reason + "\r\n");  //自动换行
			
			char buf1[256];
			sprintf(buf1, "%02X", buf[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
			pMem->SetSel(-1, -1);                         //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");       //自动换行
		}
	}
}

void CSYSTEMSETTING::OnSetBuzzer() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	int re = 0;

    int cycle = atoi(m_buzzer_cycle);
	int times = atoi(m_buzzer_times);
	
	BYTE buf[1024];
	memset(buf, 0, 1024);

	re = pReader->ControlBuzzer(cycle, times, buf);
    if(re == 0)
	{
		CString str;
		str.Format("success\n");
		
		pMem->SetSel(-1, -1);                     //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");       //自动换行
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");
			
            pMem->SetSel(-1, -1);                     //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");       //自动换行	
		}
		
		if(re != NULL)
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			
            pMem->SetSel(-1, -1);                               //自动滚屏
            pMem->ReplaceSel("false " + reason + "\r\n");       //自动换行

			
			char buf1[256];
			sprintf(buf1, "%02X", buf[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
            pMem->SetSel(-1, -1);                         //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");       //自动换行
		}
	}
}

void CSYSTEMSETTING::OnGetVer() 
{
	// TODO: Add your control notification handler code here
	char VersionNum[255];
	memset(VersionNum,0,255);
	int re = pReader->GetVersionNum(VersionNum);

	if(re == 0)
	{
		CString str;
		str.Format("success\n Version Num:\n %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x",VersionNum[1],VersionNum[2],VersionNum[3],VersionNum[4],VersionNum[5],VersionNum[6],VersionNum[7],VersionNum[8],VersionNum[9],VersionNum[10],VersionNum[11]);
		
		pMem->SetSel(-1, -1);                     //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");       //自动换行
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");
			
            pMem->SetSel(-1, -1);                     //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");       //自动换行	
		}
		
		if(re != NULL)
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			
            pMem->SetSel(-1, -1);                               //自动滚屏
            pMem->ReplaceSel("false " + reason + "\r\n");       //自动换行

			
			char buf1[256];
			sprintf(buf1, "%02X", VersionNum[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
            pMem->SetSel(-1, -1);                         //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");       //自动换行
		}
	}
}
