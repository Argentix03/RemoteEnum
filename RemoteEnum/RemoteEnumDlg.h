
// RemoteEnumDlg.h : header file
//

#pragma once
#include "ntsecapi.h"

// CRemoteEnumDlg dialog
class CRemoteEnumDlg : public CDialogEx
{
// Construction
public:
	CRemoteEnumDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REMOTEENUM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonGetHandle();
	afx_msg void OnEnChangeEdit1();
	CString m_ComputerName;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeOutput();
	CEdit m_txtOutput;
	void AppendTextToOutput(const CString& str);
	CString SidToString(PSID pSid);
	LSA_HANDLE m_policyHandle;
	afx_msg void OnBnClickedButtonUsersWithPerm();
	CComboBox m_cboRights;
	afx_msg void OnBnClickedButton3();
};
