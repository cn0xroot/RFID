#if !defined(AFX_ULTRALIGHT_H__D8284316_890F_4F1C_ADB2_1815F7DC301E__INCLUDED_)
#define AFX_ULTRALIGHT_H__D8284316_890F_4F1C_ADB2_1815F7DC301E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ULTRALIGHT.h : header file
//

#include "Read.h"
/////////////////////////////////////////////////////////////////////////////
// CULTRALIGHT dialog

class CULTRALIGHT : public CDialog
{
// Construction
public:
	CULTRALIGHT(CWnd* pParent = NULL);   // standard constructor

	CReader *pReader;
	//CRichEditCtrl *pMem;
	CEdit *pMem;

	int GetData(BYTE *pData, CString str, int maxlen);

// Dialog Data
	//{{AFX_DATA(CULTRALIGHT)
	enum { IDD = IDD_ULTRALIGHT };
	CComboBox	m_ultralight_write;
	CComboBox	m_ultralight_read;
	CListBox	m_write;
	CListBox	m_read;
	CComboBox	m_card_series_number;
	CString	m_write_data;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CULTRALIGHT)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CULTRALIGHT)
	afx_msg void OnHalt();
	afx_msg void OnReadCardSeriesNumber();
	afx_msg void OnUltraLightRead();
	afx_msg void OnUltraLightWrite();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ULTRALIGHT_H__D8284316_890F_4F1C_ADB2_1815F7DC301E__INCLUDED_)
