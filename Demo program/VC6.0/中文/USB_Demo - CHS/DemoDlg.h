// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__679A5E5E_3D30_48B5_A611_81174314C08C__INCLUDED_)
#define AFX_DEMODLG_H__679A5E5E_3D30_48B5_A611_81174314C08C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SYSTEMSETTING.h"
#include "14443AMF.h"
#include "ULTRALIGHT.h"
#include "14443B.h"
#include "15693.h"

#include "Read.h"

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DEMO_DIALOG };
	CEdit	m_mem;
	CTabCtrl	m_TabCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	CSYSTEMSETTING *m_pSystemSetting;
    C14443AMF *m_p14443AMF;    
	CULTRALIGHT *m_pUltraLight;
	C14443B *m_p14443B;
	C15693 *m_p15693;

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__679A5E5E_3D30_48B5_A611_81174314C08C__INCLUDED_)
