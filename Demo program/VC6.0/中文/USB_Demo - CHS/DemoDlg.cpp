// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CReader mReader;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Control(pDX, IDC_EDIT2, m_mem);
	DDX_Control(pDX, IDC_TAB1, m_TabCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	/*
    CFont *f;     
	f = new   CFont;     
	f->CreateFont(16,   //   nHeight     
		0,   //   nWidth     
		0,   //   nEscapement     
		0,   //   nOrientation     
		0,   //   nWeight     
		TRUE,   //   bItalic     
		FALSE,   //   bUnderline     
		0,   //   cStrikeOut     
		ANSI_CHARSET,   //   nCharSet     
		OUT_DEFAULT_PRECIS,   //   nOutPrecision     
		CLIP_DEFAULT_PRECIS,   //   nClipPrecision     
		DEFAULT_QUALITY,   //   nQuality     
		DEFAULT_PITCH   |   FF_SWISS,   //   nPitchAndFamily     
		_T("Arial"));   //   lpszFac  
	*/

	//m_editControl.SetFont(f);     
	//m_editControl.SetWindowText("ÎÊ×¨¼Ò");     
	//GetDlgItem(IDC_STATIC)->SetFont(f);   

	m_pSystemSetting = new CSYSTEMSETTING;
	m_pSystemSetting->Create(CSYSTEMSETTING::IDD, &m_TabCtrl);

	m_p14443AMF = new C14443AMF;
	m_p14443AMF->Create(C14443AMF::IDD, &m_TabCtrl);

	m_pUltraLight = new CULTRALIGHT;
	m_pUltraLight->Create(CULTRALIGHT::IDD, &m_TabCtrl);

	m_p14443B = new C14443B;
	m_p14443B->Create(C14443B::IDD, &m_TabCtrl);
	
	m_p15693 = new C15693;
	m_p15693->Create(C15693::IDD, &m_TabCtrl);
	
	PSTR pszTabItems[] = {"System Setting",	"14443A_MF", "Ultralight", "14443B", "15693"};

	TCITEM item;
	
	for(int i = 0; i < 5; i++)
	{
		item.mask = TCIF_TEXT|TCIF_PARAM|TCIF_IMAGE;
		
		item.pszText = pszTabItems[i];
		
		m_TabCtrl.InsertItem(i, &item);
	}

	CRect r; 
	
	m_TabCtrl.GetClientRect (&r); 

	m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW); 		
	m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right -20, r.bottom - 40, SWP_HIDEWINDOW); 
	m_pUltraLight->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
	m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
	m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  

	m_pSystemSetting->pMem = &m_mem;
	m_pSystemSetting->pReader = &mReader;
	
    m_p14443AMF->pMem = &m_mem;
	m_p14443AMF->pReader = &mReader;

    m_pUltraLight->pMem = &m_mem;
    m_pUltraLight->pReader = &mReader;
	
	m_p14443B->pMem = &m_mem;
    m_p14443B->pReader = &mReader;

    m_p15693->pMem = &m_mem;
    m_p15693->pReader = &mReader;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemoDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CRect r; 
	
	m_TabCtrl.GetClientRect (&r); 
	
	switch(m_TabCtrl.GetCurSel()) 	
	{ 
		
	case 0: 
		
		m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW); 		
		m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right -20, r.bottom - 40, SWP_HIDEWINDOW); 
		m_pUltraLight->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
		m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
		m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
		
		break; 
		
	case 1: 
		
		m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW); 
		m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);  
		m_pUltraLight->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
		m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
		m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   

		break; 

    case 2: 
		
		m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom -40, SWP_HIDEWINDOW); 
		m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom -40, SWP_HIDEWINDOW);  
		m_pUltraLight->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom -40, SWP_SHOWWINDOW);  
		m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
		m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);  
		
		break; 
   
    case 3: 
		
		m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW); 
		m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
       	m_pUltraLight->SetWindowPos (NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW); 
		m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW); 
		m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW); 
		break; 

	case 4: 
		
		m_pSystemSetting->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW); 
		m_p14443AMF->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
		m_pUltraLight->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
		m_p14443B->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_HIDEWINDOW);   
		m_p15693->SetWindowPos(NULL, 10, 30, r.right - 20, r.bottom - 40, SWP_SHOWWINDOW);   
		break; 	
		
	} 
	
	*pResult = 0;
}

void CDemoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_mem.SetWindowText("");
}
