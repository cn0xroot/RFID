#if !defined(AFX_15693_H__1786390B_4BA0_4E0D_ACB6_4551EE5FC239__INCLUDED_)
#define AFX_15693_H__1786390B_4BA0_4E0D_ACB6_4551EE5FC239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 15693.h : header file
//
#include "Read.h"

/////////////////////////////////////////////////////////////////////////////
// C15693 dialog

class C15693 : public CDialog
{
// Construction
public:
	C15693(CWnd* pParent = NULL);   // standard constructor

	CReader *pReader;
	//CRichEditCtrl *pMem;
	CEdit *pMem;

	int GetDataLength(CString str);
	int GetData(BYTE *pData, CString str, int maxlen);

// Dialog Data
	//{{AFX_DATA(C15693)
	enum { IDD = IDD_15693 };
	CString	m_read_flag;
	CString	m_read_start_area;
	CString	m_read_number;
	CString	m_write_flag;
	CString	m_write_start_area;
	CString	m_write_number;
	CString	m_data_for_write;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C15693)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C15693)
	afx_msg void OnInventory();
	afx_msg void OnISO15693_Read();
	afx_msg void OnISO15693_Write();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_15693_H__1786390B_4BA0_4E0D_ACB6_4551EE5FC239__INCLUDED_)
