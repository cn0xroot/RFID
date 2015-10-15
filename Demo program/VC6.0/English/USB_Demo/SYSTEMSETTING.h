#if !defined(AFX_SYSTEMSETTING_H__370603E6_5A8E_47C9_8B39_1802690BB790__INCLUDED_)
#define AFX_SYSTEMSETTING_H__370603E6_5A8E_47C9_8B39_1802690BB790__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SYSTEMSETTING.h : header file
//

#include "Read.h"

/////////////////////////////////////////////////////////////////////////////
// CSYSTEMSETTING dialog

class CSYSTEMSETTING : public CDialog
{
// Construction
public:
	CSYSTEMSETTING(CWnd* pParent = NULL);   // standard constructor
 
	CReader *pReader;

	//CRichEditCtrl *pMem;
	CEdit *pMem;

	int GetData(BYTE *pData,CString str,int maxlen);
// Dialog Data
	//{{AFX_DATA(CSYSTEMSETTING)
	enum { IDD = IDD_SYSTEMSETTING };
	CString	m_ser;
	CString	m_buzzer_cycle;
	CString	m_buzzer_times;
	CString	m_led_cycle;
	CString	m_led_times;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSYSTEMSETTING)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSYSTEMSETTING)
	afx_msg void OnSetSerNum();
	afx_msg void OnReadSerNum();
	afx_msg void OnSetLED();
	afx_msg void OnSetBuzzer();
	afx_msg void OnGetVer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMSETTING_H__370603E6_5A8E_47C9_8B39_1802690BB790__INCLUDED_)
