// 15693.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "15693.h"
//#include "mi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C15693 dialog


C15693::C15693(CWnd* pParent /*=NULL*/)
	: CDialog(C15693::IDD, pParent)
{
	//{{AFX_DATA_INIT(C15693)
	m_read_flag = _T("02");
	m_read_start_area = _T("01");
	m_read_number = _T("05");
	m_write_flag = _T("42");
	m_write_start_area = _T("05");
	m_write_number = _T("01");
	m_data_for_write = _T("11 11 11 11");
	//}}AFX_DATA_INIT
}


void C15693::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C15693)
	DDX_Text(pDX, IDC_EDIT1, m_read_flag);
	DDX_Text(pDX, IDC_EDIT2, m_read_start_area);
	DDX_Text(pDX, IDC_EDIT3, m_read_number);
	DDX_Text(pDX, IDC_EDIT4, m_write_flag);
	DDX_Text(pDX, IDC_EDIT5, m_write_start_area);
	DDX_Text(pDX, IDC_EDIT6, m_write_number);
	DDX_Text(pDX, IDC_EDIT7, m_data_for_write);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C15693, CDialog)
	//{{AFX_MSG_MAP(C15693)
	ON_BN_CLICKED(IDC_BUTTON1, OnInventory)
	ON_BN_CLICKED(IDC_BUTTON2, OnISO15693_Read)
	ON_BN_CLICKED(IDC_BUTTON3, OnISO15693_Write)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C15693 message handlers

void ReverseData(char *ChangeString, CString &ReverseString)
{
    CString dataString = "";

	int length = strlen(ChangeString);

    for(int i = 0; i < length/2; i++)
	{
		char newString[20];
		memset(newString, 0, 20);
		
		char buffer[100];
		memset(buffer, 0, 100);
		
		sprintf(buffer, "%s", ChangeString);   
		
		strncpy(newString, buffer + strlen(ChangeString) - (2*i + 2), 2);   

        CString str;
        str.Format(_T("%s"), newString); 

		dataString = dataString + str + " ";
	}

    ReverseString = dataString;
}

void C15693::OnInventory() 
{
	// TODO: Add your control notification handler code here

	int re;

	BYTE cardnumber[100];
	BYTE pBuffer[100];
	
	re = pReader->ISO15693_Inventory(cardnumber, pBuffer);
	if(re == 0)
	{
		char buf1[256];
		memset(buf1, 0, 256);
        sprintf(buf1, "%02X", cardnumber[0]);

		int card = atoi(buf1);

		CString cardnum;

		for(int i = 0; i < 10*card; i++)
		{
			char buf2[256];
			memset(buf2, 0, 256);
            sprintf(buf2, "%02X", pBuffer[i]);

            cardnum = cardnum + buf2;
		}

		CString str;
		str.Format("卡号： %02x ", card);

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n");        //自动换行

 
		CString str5;
		str5.Format("接收到的数据： ");        

		CString cardsnr = cardnum;
         
		pMem->SetSel(-1, -1);                             //自动滚屏
        pMem->ReplaceSel(str5 + cardsnr + "\r\n\r\n");    //自动换行
   
		for(i = 1; i <= card; i++)
		{

            char GetCardNum[20];

			memset(GetCardNum, 0, 20);

			char buffer[100];
			memset(buffer, 0, 100);
            
			sprintf(buffer, "%s", cardnum);   
		

            strncpy(GetCardNum, buffer + 4 + (i - 1)*20, 16);

            ReverseData(GetCardNum, cardsnr);

			CString str6;
			str6.Format("第%d卡卡号为: ", i);

			pMem->SetSel(-1, -1);                             //自动滚屏
            pMem->ReplaceSel(str6 + cardsnr + "\r\n\r\n");    //自动换行
		} 	
	}
	else
	{
        if(re == NULL)
		{
			CString str;
			str.Format("错误！没有收到数据..... ");
			
            
			pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");        //自动换行
		}
		
		if(re == 1)
		{
			CString str;
			str.Format("错误！\r\n");
			
			char buf1[256];
			sprintf(buf1, "%02X", cardnumber[0]);
			
			CString reason;
			FalseReason(buf1, reason);

			str = str + reason;
			
            pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");        //自动换行
		}
		else
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);
            
			pMem->SetSel(-1, -1);                                                //自动滚屏
            pMem->ReplaceSel("错误！原因 :" + reason + "\r\n\r\n");    //自动换行
		}
	}
}


void C15693::OnISO15693_Read() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);

	int re; 
	int flags; 
	
	LPTSTR str1 = m_read_flag.GetBuffer(0);   
	
	sscanf(str1, "%4X", &flags); 

	int blk_add = atoi(m_read_start_area);
	int num_blk = atoi(m_read_number);

	BYTE uid[100];
	BYTE buffer[100];

    CString cardnum = "";

	re = pReader->ISO15693_Read(flags, blk_add, num_blk, uid, buffer);
	if(re == 0)
	{
        CString str;
		str.Format("操作成功！ ");

		for(int i = 1; i < num_blk*4 + 1; i++)
		{
			char buf2[256];
			memset(buf2, 0, 256);
            sprintf(buf2, "%02X", buffer[i]);
           
	        cardnum = cardnum + buf2;
		}
  
		CString str1;
		str1.Format("the card datas is : ");

        pMem->SetSel(-1, -1);                                       //自动滚屏
        pMem->ReplaceSel(str + str1 + cardnum + "\r\n\r\n");        //自动换行
	}
	else
	{
        if(re == NULL)
		{
			CString str;
			str.Format("错误！没有收到数据..... ");
            
			 pMem->SetSel(-1, -1);                      //自动滚屏
             pMem->ReplaceSel(str + "\r\n\r\n");        //自动换行
		}
		
		if(re != NULL)
		{
            CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);

			pMem->SetSel(-1, -1);                                                //自动滚屏
            pMem->ReplaceSel("错误！原因:" + reason + "\r\n");        //自动换行

			char buf1[256];
			sprintf(buf1, "%02X", buffer[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);

            pMem->SetSel(-1, -1);                          //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");        //自动换行
		}
	}
}

int gethexlength(char p)
{  
    int length = 0;

	switch(p)
	{
	case '0': 
           length++; 
           break;
 
	case '1':
           length++; 
           break;

	case '2':
           length++; 
           break;

	case '3':
          length++; 
           break;

	case '4':
           length++; 
           break;
	case '5':
          length++; 
           break;

	case '6': 
          length++; 
           break;

	case '7':
         length++; 
           break;

	case '8': 
          length++; 
           break;

	case '9':
           length++; 
           break;

	case 'a': 
          length++; 
           break;

	case 'A': 
          length++; 
           break;

	case 'b': 
           length++; 
           break;

	case 'B': 
          length++; 
           break;


	case 'c': 
           length++; 
           break;

	case 'C':
         length++; 
           break;

	case 'd': 
         length++; 
           break;


	case 'D': 
         length++; 
           break;


	case 'e':
         length++; 
           break;

	case 'E':
         length++; 
           break;

	case 'f': 
          length++; 
           break;

	case 'F':
        length++; 
           break;

	};

	return length;
}

//GetDataLength(CString str)
int C15693::GetDataLength(CString str)
{
	int i = 0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);

    int Getlen = 0; 
        
	for(i = 0; i < len; i++)
	{
	    int length = 0; 	
	    length = gethexlength(p[i]);
            
            if(length != 0)
            {
                Getlen++;
            }
		
	}

	return Getlen;
}

int gethexvalue7(char p)
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

int C15693::GetData(BYTE *pData, CString str, int maxlen)
{
	int i=0;
	int len = str.GetLength();
	char *p = str.GetBuffer(0);
	
	int Index = 0;
	
	for(i=0; i<len ; i++)
	{
		int value = 0;
		value = gethexvalue7(p[i*3])*16;
		if(value == -1)
			return 2;

		value += gethexvalue7(p[i*3+1]);
		if(value == -1)
			return 2;

		pData[i] = value;
	}
	
	return 0;
}

void C15693::OnISO15693_Write() 
{
	// TODO: Add your control notification handler code here
    CString temp;	
	pMem->GetWindowText(temp);

    UpdateData(true);

	int re;

    int flags; 

	LPTSTR str1 = m_write_flag.GetBuffer(0);   

	sscanf(str1, "%4X", &flags); 

	int blk_add = atoi(m_write_start_area);
	int num_blk = atoi(m_write_number);

	BYTE uid[100];
	BYTE data[100];

	memset(data, 0, 100);

	//modify
	UpdateData(true);

	int length =  GetDataLength(m_data_for_write);    

	if(length != 8*num_blk)
	{
		AfxMessageBox("数据长度错误.. ");
		return;
	}

	GetData(data, m_data_for_write, 47);
   
    re = pReader->ISO15693_Write(flags, blk_add, num_blk, uid, data);
	if(re == 0)
	{
		CString str;
		str.Format("操作成功！\n");

		pMem->SetSel(-1, -1);                  //自动滚屏
        pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
	}
	else
	{
        if(re == NULL)
		{
			CString str;
			str.Format("错误！没有收到数据..... ");

            pMem->SetSel(-1, -1);                  //自动滚屏
            pMem->ReplaceSel(str + "\r\n\r\n");    //自动换行
		}
		
		if(re != NULL)
		{
			CString str;
			str.Format("%d", re);
			
			CString reason;
			FalseReason(str, reason);

            pMem->SetSel(-1, -1);              //自动滚屏
            pMem->ReplaceSel(str + "\r\n");    //自动换行 
			
			
			char buf1[256];
			sprintf(buf1, "%02X", data[0]);
			
			CString reason1;
			FalseReason(buf1, reason1);
         
			pMem->SetSel(-1, -1);                      //自动滚屏
            pMem->ReplaceSel(reason1 + "\r\n\r\n");    //自动换行 
		}
	}
}
