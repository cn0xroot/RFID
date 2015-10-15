// 14443AMF.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "14443AMF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C14443AMF dialog


C14443AMF::C14443AMF(CWnd* pParent /*=NULL*/)
	: CDialog(C14443AMF::IDD, pParent)
{
	//{{AFX_DATA_INIT(C14443AMF)
	m_write_data = _T("FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF");
	m_decrement_sector = _T("04");
	m_decrement_key = _T("FF FF FF FF FF FF");
	m_increment_key = _T("FF FF FF FF FF FF");
	m_increment_sector = _T("04");
	m_decrement_value = _T("01 00 00 00");
	m_increment_value = _T("01 00 00 00");
	m_initval_key = _T("FF FF FF FF FF FF");
	m_initval_sector = _T("04");
	m_initval_value = _T("64 00 00 00");
	//}}AFX_DATA_INIT
}


void C14443AMF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C14443AMF)
	DDX_Control(pDX, IDC_READBLOCKNUMBER, m_read_block_number);
	DDX_Control(pDX, IDC_GETSNRHALT, m_get_snr_halt);
	DDX_Control(pDX, IDC_INITVALMODE, m_initval_mode);
	DDX_Control(pDX, IDC_INITVAL, m_initval);
	DDX_Control(pDX, IDC_INCREMENTMODE, m_increment_mode);
	DDX_Control(pDX, IDC_DECREMENT, m_decrement);
	DDX_Control(pDX, IDC_DECREMENTMODE, m_decrement_mode);
	DDX_Control(pDX, IDC_INCREMENT, m_increment);
	DDX_Control(pDX, IDC_GETSNR, m_get_snr);
	DDX_Control(pDX, IDC_WRITEMODE, m_write_mode);
	DDX_Control(pDX, IDC_READMODE, m_read_mode);
	DDX_Control(pDX, IDC_WRITEBLOCKKEY, m_write_block_key);
	DDX_Control(pDX, IDC_READBLOCKKEY, m_read_block_key);
	DDX_Control(pDX, IDC_WRITESTARTADDRESS, m_write_start_address);
	DDX_Control(pDX, IDC_WRITEBLOCKNUMBER, m_write_block_number);
	DDX_Control(pDX, IDC_WRITE, m_write);
	DDX_Control(pDX, IDC_READSTARTADDRESS, m_read_start_number);
	DDX_Control(pDX, IDC_READ, m_read);
	DDX_Text(pDX, IDC_WRITEDATA, m_write_data);
	DDX_Text(pDX, IDC_DECREMENTSECTOR, m_decrement_sector);
	DDX_Text(pDX, IDC_DECREMENTKEY, m_decrement_key);
	DDX_Text(pDX, IDC_INCREMENTKEY, m_increment_key);
	DDX_Text(pDX, IDC_INCREMENTSECTOR, m_increment_sector);
	DDX_Text(pDX, IDC_DECREMENTVALUE, m_decrement_value);
	DDX_Text(pDX, IDC_INCREMENTVALUE, m_increment_value);
	DDX_Text(pDX, IDC_INITVALKEY, m_initval_key);
	DDX_Text(pDX, IDC_INITVALSECTOR, m_initval_sector);
	DDX_Text(pDX, IDC_INITVALVALUE, m_initval_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C14443AMF, CDialog)
	//{{AFX_MSG_MAP(C14443AMF)
	ON_BN_CLICKED(IDC_READCARD, OnReadcard)
	ON_BN_CLICKED(IDC_WRITECARD, OnWritecard)
	ON_BN_CLICKED(IDC_INITIALIZATION, OnInitialization)
	ON_BN_CLICKED(IDC_BUTTON2, OnDeValue)
	ON_BN_CLICKED(IDC_BUTTON3, OnAddValue)
	ON_BN_CLICKED(IDC_BUTTON4, OnCardNumber)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C14443AMF message handlers

BOOL C14443AMF::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_read.AddString("Idle");
	m_read.AddString("All");
	m_read.SetCurSel(0);
	
    m_read_mode.AddString("Key A");
	m_read_mode.AddString("Key B");
	m_read_mode.SetCurSel(0);

    m_read_start_number.AddString("00");
    m_read_start_number.AddString("01");
	m_read_start_number.AddString("02");
	m_read_start_number.AddString("03");
	m_read_start_number.AddString("04");
	m_read_start_number.AddString("05");
	m_read_start_number.AddString("06");
	m_read_start_number.AddString("07");
	m_read_start_number.AddString("08");
	m_read_start_number.AddString("09");
	m_read_start_number.AddString("0A");
	m_read_start_number.AddString("0B");
	m_read_start_number.AddString("0E");
	m_read_start_number.AddString("0D");
	m_read_start_number.AddString("0E");
	m_read_start_number.AddString("0F");
    m_read_start_number.SetCurSel(0);

	m_read_block_number.AddString("01");
    m_read_block_number.AddString("02");
    m_read_block_number.AddString("03");
	m_read_block_number.AddString("04");
    m_read_block_number.SetCurSel(0);

	m_read_block_key.AddString("A0 A1 A2 A3 A4 A5");
    m_read_block_key.AddString("B0 B1 B2 B3 B4 B5");
    m_read_block_key.AddString("FF FF FF FF FF FF");
    m_read_block_key.SetCurSel(2);

    m_write.AddString("Idle");
	m_write.AddString("All");
	m_write.SetCurSel(0);
	
    m_write_mode.AddString("Key A");
	m_write_mode.AddString("Key B");
	m_write_mode.SetCurSel(0);

	m_write_start_address.AddString("00");
    m_write_start_address.AddString("01");
	m_write_start_address.AddString("02");
	m_write_start_address.AddString("03");
	m_write_start_address.AddString("04");
	m_write_start_address.AddString("05");
	m_write_start_address.AddString("06");
	m_write_start_address.AddString("07");
	m_write_start_address.AddString("08");
	m_write_start_address.AddString("09");
	m_write_start_address.AddString("0A");
	m_write_start_address.AddString("0B");
	m_write_start_address.AddString("0C");
	m_write_start_address.AddString("0D");
	m_write_start_address.AddString("0E");
	m_write_start_address.AddString("0F");
    m_write_start_address.SetCurSel(0);

	m_write_block_number.AddString("01");
    m_write_block_number.AddString("02");
	m_write_block_number.AddString("03");
	m_write_block_number.AddString("04");
    m_write_block_number.SetCurSel(0);

	m_write_block_key.AddString("A0 A1 A2 A3 A4 A5");
    m_write_block_key.AddString("B0 B1 B2 B3 B4 B5");
    m_write_block_key.AddString("FF FF FF FF FF FF");
    m_write_block_key.SetCurSel(2);

	m_initval.AddString("Idle");
	m_initval.AddString("All");
	m_initval.SetCurSel(0);

	m_initval_mode.AddString("Key A");
	m_initval_mode.AddString("Key B");
	m_initval_mode.SetCurSel(0);

	m_decrement.AddString("Idle");
	m_decrement.AddString("All");
	m_decrement.SetCurSel(0);

	m_decrement_mode.AddString("Key A");
	m_decrement_mode.AddString("Key B");
    m_decrement_mode.SetCurSel(0);

	m_increment.AddString("Idle");
	m_increment.AddString("All");
	m_increment.SetCurSel(0);

    m_increment_mode.AddString("Key A");
	m_increment_mode.AddString("Key B");
	m_increment_mode.SetCurSel(0);

    m_get_snr.AddString("Idle");
	m_get_snr.AddString("All");
	m_get_snr.SetCurSel(0);
    
	m_get_snr_halt.AddString("no halt");
	m_get_snr_halt.AddString("halt");
	m_get_snr_halt.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void C14443AMF::OnReadcard() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);
	
	int len = m_read_block_number.GetCurSel()+1;

	int type = m_read.GetCurSel()*2 + m_read_mode.GetCurSel();

	//BYTE mode;
	int mode = type;

    int read_blk_add = m_read_start_number.GetCurSel();

    int read_num_blk = m_read_block_number.GetCurSel() + 1;

	BYTE buf[1024];
	memset(buf, 0, 1024);
	
	BYTE pCode[6];
	memset(pCode, 0, 6);

	if(m_read_block_key.GetCurSel() == 0)
	{
		pCode[0] = 0xa0;
		pCode[1] = 0xa1;
		pCode[2] = 0xa2;
		pCode[3] = 0xa3;
		pCode[4] = 0xa4;
		pCode[5] = 0xa5;
	}
	else if(m_read_block_key.GetCurSel() == 1)
	{
		pCode[0] = 0xb0;
		pCode[1] = 0xb1;
		pCode[2] = 0xb2;
		pCode[3] = 0xb3;
		pCode[4] = 0xb4;
		pCode[5] = 0xb5;
	}
	else
		memset(pCode, 0xff, 6);
	
	int re = pReader->MF_Read(mode, read_blk_add, read_num_blk, pCode, buf);
	if(re == 0)
	{
		CString str;
		CString t;

		str.Format("Card Number: %02x %02x %02x %02x\r\nCard Data:", pCode[0], pCode[1], pCode[2], pCode[3]);
        
		for(int i=0; i<len; i++)
		{
			t.Format(" %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x ",
				buf[i*16+0], buf[i*16+1], buf[i*16+2], buf[i*16+3],
				buf[i*16+4], buf[i*16+5], buf[i*16+6], buf[i*16+7],
				buf[i*16+8], buf[i*16+9], buf[i*16+10], buf[i*16+11],
				buf[i*16+12], buf[i*16+13], buf[i*16+14], buf[i*16+15]);

			str += t;
			t = "";
		}
		

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
			CString str;
			str.Format("false\r\n");
			
			char buf1[256];
            sprintf(buf1, "%02X", buf[0]);
			
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

int gethexvalue(char p)
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
int C14443AMF::GetData(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	if(len < maxlen)
		return 1;

	for(i=0; i<16; i++)
	{
		int value = 0;
		value = gethexvalue(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}

	return 0;
}


int C14443AMF::GetData2(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	
	for(i=0; i<6; i++)
	{
		int value = 0;
		value = gethexvalue(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}
	
	return 0;
}

int C14443AMF::GetData3(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	
	for(i=0; i<4; i++)
	{
		int value = 0;
		value = gethexvalue(p[i*3])*16;
		if(value == -1)
			return 2;
		value += gethexvalue(p[i*3+1]);
		if(value == -1)
			return 2;
		pData[i] = value;
	}
	
	return 0;
}


void C14443AMF::OnWritecard() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

	int mode = m_write.GetCurSel()*2 + m_write_mode.GetCurSel();

	int write_blk_add = m_write_start_address.GetCurSel();

    int write_num_blk = m_write_block_number.GetCurSel() + 1;
	
	BYTE buf[1024];
	memset(buf, 0, 1024);
	
	BYTE pCode[56];
	if(m_write_block_key.GetCurSel() == 0)
	{
		pCode[0] = 0xa0;
		pCode[1] = 0xa1;
		pCode[2] = 0xa2;
		pCode[3] = 0xa3;
		pCode[4] = 0xa4;
		pCode[5] = 0xa5;
	}
	else if(m_write_block_key.GetCurSel() == 1)
	{
		pCode[0] = 0xb0;
		pCode[1] = 0xb1;
		pCode[2] = 0xb2;
		pCode[3] = 0xb3;
		pCode[4] = 0xb4;
		pCode[5] = 0xb5;
	}
	else
		memset(pCode, 0xff, 6);
	
	UpdateData(true);
	if(GetData(buf, m_write_data, 47))
	{
        pMem->SetSel(-1, -1);                         //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");    //自动换行

		return;
	}	
	
    int re = pReader->MF_Write(mode, write_blk_add, write_num_blk, pCode, buf);
	if(re == 0)
	{
		CString str;
		str.Format("Success :%02x %02x %02x %02x", pCode[0], pCode[1], pCode[2], pCode[3]);
		
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
            sprintf(buf1, "%02X", buf[0]);
			
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

void C14443AMF::OnInitialization() 
{
	// TODO: Add your control notification handler code here

    int mode = m_initval.GetCurSel()*2 + m_initval_mode.GetCurSel();

	int sectNum = atoi(m_initval_sector);

	BYTE key[1024];
	memset(key, 0, 1024);

	UpdateData(true);
	if(GetData2(key, m_initval_key, 47))
	{
        pMem->SetSel(-1, -1);                              //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");         //自动换行

		return;
	}	

    BYTE keywrite[1024];
	memset(keywrite, 0, 1024);

    UpdateData(true);
	if(GetData3(keywrite, m_initval_value, 47))
	{
        pMem->SetSel(-1, -1);                              //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");    //自动换行

		return;
	}	
	
	int re = 0;
	re = pReader->MF_InitValue(mode, sectNum, key, keywrite); 
    if(re == 0)
	{
		CString str;
		str.Format("success.. :%02x %02x %02x %02x\r\n", key[0], key[1], key[2], key[3]);

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
        if(re == NULL)
		{
			CString str;
			str.Format("error,no data receive...\n");
			
            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行 
		}

		if(re == 1)
		{
			CString str;
			str.Format("false\r\n");
			
			char buf1[256];
            sprintf(buf1, "%02X", key[0]);
			
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

void C14443AMF::OnDeValue() 
{
	// TODO: Add your control notification handler code here
    int mode = m_decrement.GetCurSel()*2 + m_decrement_mode.GetCurSel();

	int sectNum = atoi(m_decrement_sector);

	BYTE key[1024];
	memset(key, 0, 1024);

	UpdateData(true);
	if(GetData2(key, m_decrement_key, 47))
	{
        pMem->SetSel(-1, -1);                         //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");    //自动换行 
		return;
	}	
	
    BYTE keywrite[1024];
	memset(keywrite, 0, 1024);

    UpdateData(true);
	if(GetData3(keywrite, m_decrement_value, 47))
	{
        pMem->SetSel(-1, -1);                         //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");    //自动换行

		return;
	}	

    int re = 0;
	re = pReader->MF_Dec(mode, sectNum, key, keywrite);
    if(re == 0)
	{
		CString str;
		str.Format("success.. :%02x %02x %02x %02x\r\n", key[0], key[1], key[2], key[3]);

		CString str1;
        str1.Format("success.. :%02x %02x %02x %02x\r\n", keywrite[0], keywrite[1], keywrite[2], keywrite[3]);
		
        str = str + str1;

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行 
	}
	else
	{
		if(re == NULL)
		{
			CString str;
			str.Format("error,no data receive...\n");

            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行 
		}
		
		if(re == 1)
		{
			CString str;
			str.Format("false\r\n");
			
			char buf1[256];
            sprintf(buf1, "%02X", key[0]);
			
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

void C14443AMF::OnAddValue() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

	int mode = m_increment.GetCurSel()*2 + m_increment_mode.GetCurSel();
	int sectNum = atoi(m_increment_sector);
    
	BYTE key[1024];
	memset(key, 0, 1024);

	UpdateData(true);
	if(GetData2(key, m_increment_key, 47))
	{
		pMem->SetSel(-1, -1);                              //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");         //自动换行
		return;
	}	
	
    BYTE keywrite[1024];
	memset(keywrite, 0, 1024);

    UpdateData(true);
	if(GetData3(keywrite, m_increment_value, 47))
	{
		pMem->SetSel(-1, -1);                              //自动滚屏
        pMem->ReplaceSel("Data length invalid!\r\n\r\n");         //自动换行
		return;
	}	

	int re = 0;
	re = pReader->MF_Inc(mode, sectNum, key, keywrite);
	if(re == 0)
	{
		CString str;
		str.Format("success.. :%02x %02x %02x %02x\r\n", key[0], key[1], key[2], key[3]);

		CString str1;
        str.Format("success.. :%02x %02x %02x %02x\r\n", keywrite[0], keywrite[1], keywrite[2], keywrite[3]);
		
        str = str + str1;

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
        if(re == NULL)
		{
			CString str;
			str.Format("error,no data receive...\n");
			
            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
		}
		
		if(re == 1)
		{
			CString str;
			str.Format("false\r\n");
			
			char buf1[256];
            sprintf(buf1, "%02X", key[0]);
			
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

void C14443AMF::OnCardNumber() 
{
	// TODO: Add your control notification handler code here

    int mode;
	int halt;

	BYTE snr[100];
	BYTE value[100];
	UpdateData(true);

    if((m_get_snr.GetCurSel()) == 0)
    {
        mode = 0x26;
	}
    else
    {
		mode = 0x52;

	}
     
	if((m_get_snr_halt.GetCurSel()) == 0)
	{
        halt = 0x00;
	}
	else
	{
        halt = 0x01;
	}
    
	int re = 0;
	re = pReader->MF_Getsnr(mode, halt, snr, value);
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
		str2.Format("the receive card number is : %02x %02x %02x %02x\r\n", value[0], value[1], value[2], value[3]);

		str = str + str1 +str2;

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

			char buf[256];
            sprintf(buf, "%02X", snr[0]);

			CString reason;
			FalseReason(buf, reason);

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
