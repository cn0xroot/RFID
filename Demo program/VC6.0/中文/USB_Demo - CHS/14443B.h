#if !defined(AFX_14443B_H__2890F019_4BCC_4E12_AEE8_80F17C51766B__INCLUDED_)
#define AFX_14443B_H__2890F019_4BCC_4E12_AEE8_80F17C51766B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 14443B.h : header file
//
#include "Read.h"

/////////////////////////////////////////////////////////////////////////////
// C14443B dialog

class C14443B : public CDialog
{
// Construction
public:
	C14443B(CWnd* pParent = NULL);   // standard constructor
	int GetData(BYTE *pData, CString str, int maxlen);
	CReader *pReader;
	//CRichEditCtrl *pMem;
	CEdit *pMem;

// Dialog Data
	//{{AFX_DATA(C14443B)
	enum { IDD = IDD_14443B };
	CString	m_data_length;
	CString m_send_data;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C14443B)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C14443B)
	afx_msg void OnSFZUID();
	afx_msg void OnRequestTypeB();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_14443B_H__2890F019_4BCC_4E12_AEE8_80F17C51766B__INCLUDED_)
