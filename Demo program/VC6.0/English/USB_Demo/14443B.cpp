// 14443B.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "14443B.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



int gethexvalue8(char p)
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
int C14443B::GetData(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	if(len < maxlen)
		return 1;

	for(i=0; i<16; i++)
	{
		int value = 0;
		value = gethexvalue8(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue8(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}

	return 0;
}
/////////////////////////////////////////////////////////////////////////////
// C14443B dialog

C14443B::C14443B(CWnd* pParent /*=NULL*/)
	: CDialog(C14443B::IDD, pParent)
{
	//{{AFX_DATA_INIT(C14443B)
		// NOTE: the ClassWizard will add member initialization here
		m_data_length = _T("08");
		m_send_data = _T("00 00 05 00 84 00 00 08");
	//}}AFX_DATA_INIT
}


void C14443B::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C14443B)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Text(pDX, IDC_EDIT1, m_data_length);
	DDX_Text(pDX, IDC_EDIT2, m_send_data);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C14443B, CDialog)
	//{{AFX_MSG_MAP(C14443B)
	ON_BN_CLICKED(IDC_BUTTON3, OnSFZUID)
	ON_BN_CLICKED(IDC_BUTTON1, OnRequestTypeB)
	ON_BN_CLICKED(IDC_BUTTON2, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void C14443B::OnSend()
{
	// TODO: Add your control notification handler code here
	BYTE cmd[255];
	memset(cmd,0,255);

	BYTE buffer[1];
	memset(buffer,0,1);
	
	UpdateData(true);

	int cmdSize;
	CString cmdSizeStr;
	sscanf(m_data_length,"%x",&cmdSize);

	if(GetData(buffer, m_send_data, cmdSize))
	{
        pMem->SetSel(-1, -1);                         //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");    //自动换行
		return;
	}	

	 int re = pReader->TypeB_TransCOS (cmd,cmdSize,buffer);
	if(re == 0)
	{
		CString str;
		str.Format("Success :%02x %02x %02x %02x %02x %02x %02x %02x", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7]);
		
		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
        if(re == NULL)
		{
			//error, no data receive...
            CString str;
			str.Format("error, no data receive...\n");
 
			pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
		}
		
		if(re == 1)
		{
			CString str;
			str.Format("false\r\n");
			
			char buf1[256];
            sprintf(buf1, "%02X", buffer[0]);
			
			CString reason;
			FalseReason(buf1, reason);

			str = str + reason;
			
			pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
		}
		else
		{
            CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			
			pMem->SetSel(-1, -1);                                                //自动滚屏
            pMem->ReplaceSel("false, the reason is :" + reason + "\r\n\r\n");    //自动换行
		}
	}	
}
/////////////////////////////////////////////////////////////////////////////
// C14443B message handlers

void C14443B::OnSFZUID() 
{
	// TODO: Add your control notification handler code here
	
	int mode = 26;
    int halt = 0;

    BYTE snr[100];
	memset(snr, 0, 100);

	BYTE value[100];
    memset(value, 0, 100);

    int re;
	re = pReader->TYPEB_SFZSNR(mode, halt, snr, value);
	if(re == 0)
	{
        CString str;
		str.Format("success.. \r\n");
		
		CString str1;
		
		if(snr[0] == 0)
		{
			str1.Format("It is only one card...\r\n");
		}
		else
		{
			str1.Format("It is more than one card...\r\n");
		}
		
        CString str2;
		str2.Format("the receive card number is : %02x %02x %02x %02x %02x %02x %02x %02x\r\n", value[0], value[1], value[2], 
			 value[3], value[4], value[5], value[6], value[7]);
		
		str = str + str1 +str2;

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
		
		if(re == 1)
		{
			CString str1;
			str1.Format("false\r\n");
			
			char buf1[256];
			sprintf(buf1, "%02X", snr[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);

			str1 = str1 + reason1;

            pMem->SetSel(-1, -1);                   //自动滚屏
            pMem->ReplaceSel(str1 + "\r\n\r\n");    //自动换行
		}
		else
		{
            CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
			

            pMem->SetSel(-1, -1);                                                //自动滚屏
            pMem->ReplaceSel("false, the reason is :" + reason + "\r\n\r\n");    //自动换行
		}
	}
}

void C14443B::OnRequestTypeB() 
{
	// TODO: Add your control notification handler code here
	CString temp;
	pMem->GetWindowText(temp);
	
	BYTE buffer1[100];
	memset(buffer1, 0, 100);

	int re;
	re = pReader->TypeB_Request(buffer1);
	if(re == 0)
	{
		CString str;
		str.Format("success  %02x %02x %02x %02x %02x %02x %02x %02x\r\n", buffer1[0], buffer1[1], buffer1[2], buffer1[3], 
			buffer1[4], buffer1[5], buffer1[6], buffer1[7]);

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
			str.Format("false\n");

            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n");        //自动换行
			
            CString str1;
			str1.Format("%d", re);
			
			CString reason;
			FalseReason(str1, reason);
 
			pMem->SetSel(-1, -1);                     //自动滚屏
            pMem->ReplaceSel(reason + "\r\n");        //自动换行

			
			char buf1[256];
			sprintf(buf1, "%02X", buffer1[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);

            pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");    //自动换行
		}
	}
}
