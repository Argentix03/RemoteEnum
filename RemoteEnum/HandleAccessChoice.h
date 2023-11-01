#pragma once
#include "afxdialogex.h"


// HandleAccessChoice dialog

class HandleAccessChoice : public CDialogEx
{
	DECLARE_DYNAMIC(HandleAccessChoice)

public:
	HandleAccessChoice(CWnd* pParent = nullptr);   // standard constructor
	virtual ~HandleAccessChoice();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_POLICY_ALL_ACCESS;
	BOOL m_POLICY_VIEW_LOCAL_INFORMATION;
	BOOL m_POLICY_VIEW_AUDIT_INFORMATION;
	BOOL m_POLICY_GET_PRIVATE_INFORMATION;
	BOOL m_POLICY_TRUST_ADMIN;
	BOOL m_POLICY_CREATE_ACCOUNT;
	BOOL m_POLICY_CREATE_SECRET;
	BOOL m_POLICY_CREATE_PRIVILEGE;
	BOOL m_POLICY_SET_DEFAULT_QUOTA_LIMITS;
	BOOL m_POLICY_SET_AUDIT_REQUIREMENTS;
	BOOL m_POLICY_AUDIT_LOG_ADMIN;
	BOOL m_POLICY_SERVER_ADMIN;
	BOOL m_POLICY_LOOKUP_NAMES;
	BOOL m_POLICY_NOTIFICATION;
};
