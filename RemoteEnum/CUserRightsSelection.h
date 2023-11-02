#pragma once
#include "afxdialogex.h"


// CUserRightsSelection dialog

class CUserRightsSelection : public CDialogEx
{
	DECLARE_DYNAMIC(CUserRightsSelection)

public:
	CUserRightsSelection(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserRightsSelection();
//	CListBox m_listPermissions;
	CString GetSelectedPermission() const;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeListPermissions();
	CListBox m_userRightsList;
};
