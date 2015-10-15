#if !defined(AFX_14443AMF_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)
#define AFX_14443AMF_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 14443AMF.h : header file
//
#include "Read.h"
/////////////////////////////////////////////////////////////////////////////
// C14443AMF dialog

class C14443AMF : public CDialog
{
// Construction
public:
	C14443AMF(CWnd* pParent = NULL);   // standard constructor

	CReader *pReader;
	//CRichEditCtrl *pMem;
	CEdit *pMem;

    int GetData(BYTE *pData,CString str,int maxlen);

    int GetData2(BYTE *pData,CString str,int maxlen);

    int GetData3(BYTE *pData,CString str,int maxlen);

// Dialog Data
	//{{AFX_DATA(C14443AMF)
	enum { IDD = IDD_14443A_MF };
	CComboBox	m_read_block_number;
	CComboBox	m_get_snr_halt;
	CComboBox	m_initval_mode;
	CComboBox	m_initval;
	CComboBox	m_increment_mode;
	CComboBox	m_decrement;
	CComboBox	m_decrement_mode;
	CComboBox	m_increment;
	CComboBox	m_get_snr;
	CComboBox	m_write_mode;
	CComboBox	m_read_mode;
	CComboBox	m_write_block_key;
	CComboBox	m_read_block_key;
	CComboBox	m_write_start_address;
	CComboBox	m_write_block_number;
	CComboBox	m_write;
	CComboBox	m_read_start_number;
	CComboBox	m_read;
	CString	m_write_data;
	CString	m_decrement_sector;
	CString	m_decrement_key;
	CString	m_increment_key;
	CString	m_increment_sector;
	CString	m_decrement_value;
	CString	m_increment_value;
	CString	m_initval_key;
	CString	m_initval_sector;
	CString	m_initval_value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C14443AMF)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C14443AMF)
	virtual BOOL OnInitDialog();
	afx_msg void OnReadcard();
	afx_msg void OnWritecard();
	afx_msg void OnInitialization();
	afx_msg void OnDeValue();
	afx_msg void OnAddValue();
	afx_msg void OnCardNumber();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_14443AMF_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)

