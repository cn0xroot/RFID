// ULTRALIGHT.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "ULTRALIGHT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CULTRALIGHT dialog


CULTRALIGHT::CULTRALIGHT(CWnd* pParent /*=NULL*/)
	: CDialog(CULTRALIGHT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CULTRALIGHT)
	m_write_data = _T("00 00 00 00");
	//}}AFX_DATA_INIT
}


void CULTRALIGHT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CULTRALIGHT)
	DDX_Control(pDX, IDC_ULTRALIGHTWRITE, m_ultralight_write);
	DDX_Control(pDX, IDC_ULTRALIGHTREAD, m_ultralight_read);
	DDX_Control(pDX, IDC_LIST2, m_write);
	DDX_Control(pDX, IDC_LIST1, m_read);
	DDX_Control(pDX, IDC_CARDSERIESNUMBER, m_card_series_number);
	DDX_Text(pDX, IDC_DATA_EDIT, m_write_data);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CULTRALIGHT, CDialog)
	//{{AFX_MSG_MAP(CULTRALIGHT)
	ON_BN_CLICKED(IDC_BUTTON2, OnHalt)
	ON_BN_CLICKED(IDC_BUTTON1, OnReadCardSeriesNumber)
	ON_BN_CLICKED(IDC_BUTTON3, OnUltraLightRead)
	ON_BN_CLICKED(IDC_BUTTON4, OnUltraLightWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CULTRALIGHT message handlers

BOOL CULTRALIGHT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString Item[16] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15"};
	for (int i = 0; i < 16; i++)
	{
		m_read.AddString(Item[i]);
		m_write.AddString(Item[i]);
	}
	
	m_read.SetCurSel(0);
    m_write.SetCurSel(0);

    m_card_series_number.AddString("Idle");
	m_card_series_number.AddString("All");
    m_card_series_number.SetCurSel(0);

    m_ultralight_read.AddString("Idle");
	m_ultralight_read.AddString("All");
    m_ultralight_read.SetCurSel(0);

	m_ultralight_write.AddString("Idle");
	m_ultralight_write.AddString("All");
    m_ultralight_write.SetCurSel(0);
 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CULTRALIGHT::OnHalt() 
{
	// TODO: Add your control notification handler code here

    int re = 0;
    re = pReader->MF_Halt();
	if(re == 0)
	{
        CString str;
		str.Format("success");
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
	}
}

void CULTRALIGHT::OnReadCardSeriesNumber() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

	int mode = 0x00;
    int re = 0;

	BYTE snr[100];
	memset(snr, 0, 100);

	if(m_card_series_number.GetCurSel() == 0)
	{
        mode = 0x00;	
	}
	else
	{
        mode = 0x01;
	}

	re = pReader->UL_Request(mode, snr);
	if(re == 0)
	{
        CString str;
        str.Format("success\r\n");

        CString str1;
		str1.Format(" the card snr is.. %02x %02x %02x %02x %02x %02x %02x\n", snr[0], snr[1], snr[2], snr[3],
			snr[4], snr[5], snr[6]);

		str = str + str1;
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
			str.Format("false\n");
            pMem->SetSel(-1, -1);              //自动滚屏
            pMem->ReplaceSel(str + "\r\n");    //自动换行
			
            CString str1;
			str1.Format("%d", re);
			
			CString reason;
			FalseReason(str1, reason);
            pMem->SetSel(-1, -1);                 //自动滚屏
            pMem->ReplaceSel(reason + "\r\n");    //自动换行
						
			char buf1[256];
			sprintf(buf1, "%02X", snr[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
            pMem->SetSel(-1, -1);                         //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");       //自动换行
		}
	}
}

void CULTRALIGHT::OnUltraLightRead() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

    int re = 0;

	int mode = 0;

	int Index = m_read.GetCurSel();

	CString Text;
    m_read.GetText(Index, Text);

    int blk_add = atoi(Text);
 
	BYTE snr[100];
	memset(snr, 0, 100);
	
	BYTE buffer[100];
    memset(buffer, 0, 100);

    if(m_ultralight_read.GetCurSel() == 0)
	{
        mode = 0x00;	
	}
	else
	{
        mode = 0x01;
	}

	re = pReader->UL_HLRead(mode, blk_add, snr, buffer);
	if(re == 0)
	{
        CString str;
		str.Format("success  the card snr is..  %02x %02x %02x %02x %02x %02x %02x\r\n", snr[0], snr[1], snr[2], snr[3],
			snr[4], snr[5], snr[6]);

		CString str1;
		str1.Format("\r\n the card data is.. %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10],
			buffer[11], buffer[12], buffer[13], buffer[14], buffer[15]);
		
		str = str + str1;

		pMem->SetSel(-1, -1);                    //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");      //自动换行
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error, no data receive... ");
			
			pMem->SetSel(-1, -1);                    //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");      //自动换行
		}
		
		if(re != NULL)
		{
            CString str;
			str.Format("false\r\n");
			
            CString str1;
			str1.Format("%d", re);
			
			CString reason;
			FalseReason(str1, reason);

			str = str + reason;

			//pMem->SetWindowText(temp + "\n" + str);
			//pMem->GetWindowText(temp);
            pMem->SetSel(-1, -1);              //自动滚屏
            pMem->ReplaceSel(str + "\r\n");    //自动换行
			
			
			char buf1[256];
			sprintf(buf1, "%02X", snr[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
			
			//pMem->SetWindowText(temp + "\n" + reason1 + "\n");
            pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");    //自动换行
		}
	}
}


int gethexvalue5(char p)
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

int CULTRALIGHT::GetData(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
//	if(len < maxlen)
//		return 1;

	for(i=0; i<4; i++)
	{
		int value = 0;
		value = gethexvalue5(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue5(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}

	return 0;
}


void CULTRALIGHT::OnUltraLightWrite() 
{
	// TODO: Add your control notification handler code here

	//CString temp;	
	//pMem->GetWindowText(temp);

	UpdateData(true);

    int re = 0;
	int mode = 0x00;

	int Index = m_write.GetCurSel();

	CString Text;
	m_write.GetText(Index, Text);

	int blk_add = atoi(Text);

	BYTE snr[100];
	memset(snr, 0, 100);

	BYTE key[100];
    memset(key, 0, 100);

	if(GetData(key, m_write_data, 47))
	{
	    pMem->SetSel(-1, -1);                          //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");     //自动换行
		return;
	}	

	if(m_ultralight_write.GetCurSel() == 0)
	{
        mode = 0x00;
	}
	else
	{
        mode = 0x01;
	}

	re = pReader->UL_HLWrite(mode, blk_add, snr, key);
	if(re == 0)
	{
        CString str;
		str.Format("success  the card snr is..  %02x %02x %02x %02x %02x %02x %02x\n", snr[0], snr[1], snr[2], snr[3],
			snr[4], snr[5], snr[6]);
		
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

            //pMem->SetWindowText(temp + "\n" + str);
			//pMem->GetWindowText(temp);
            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行

            CString str1;
			str1.Format("%d", re);
			
			CString reason;
			FalseReason(str1, reason);

			//pMem->SetWindowText(temp + "\n" + reason);
			//pMem->GetWindowText(temp);
            pMem->SetSel(-1, -1);                     //自动滚屏
            pMem->ReplaceSel(reason + "\r\n");        //自动换行
			
			char buf1[256];
			sprintf(buf1, "%02X", snr[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);

			//pMem->SetWindowText(temp + "\n" + reason1);
            pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");    //自动换行
		}
	}
}


