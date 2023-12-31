// HandleAccessChoice.cpp : implementation file
//

#include "pch.h"
#include "RemoteEnum.h"
#include "afxdialogex.h"
#include "HandleAccessChoice.h"


// HandleAccessChoice dialog

IMPLEMENT_DYNAMIC(HandleAccessChoice, CDialogEx)

HandleAccessChoice::HandleAccessChoice(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_POLICY_ALL_ACCESS(FALSE)
	, m_POLICY_VIEW_LOCAL_INFORMATION(FALSE)
	, m_POLICY_VIEW_AUDIT_INFORMATION(FALSE)
	, m_POLICY_GET_PRIVATE_INFORMATION(FALSE)
	, m_POLICY_TRUST_ADMIN(FALSE)
	, m_POLICY_CREATE_ACCOUNT(FALSE)
	, m_POLICY_CREATE_SECRET(FALSE)
	, m_POLICY_CREATE_PRIVILEGE(FALSE)
	, m_POLICY_SET_DEFAULT_QUOTA_LIMITS(FALSE)
	, m_POLICY_SET_AUDIT_REQUIREMENTS(FALSE)
	, m_POLICY_AUDIT_LOG_ADMIN(FALSE)
	, m_POLICY_SERVER_ADMIN(FALSE)
	, m_POLICY_LOOKUP_NAMES(FALSE)
	, m_POLICY_NOTIFICATION(FALSE)
{

}

HandleAccessChoice::~HandleAccessChoice()
{
}

void HandleAccessChoice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_POLICY_ALL_ACCESS, m_POLICY_ALL_ACCESS);
	DDX_Check(pDX, IDC_POLICY_VIEW_LOCAL_INFORMATION, m_POLICY_VIEW_LOCAL_INFORMATION);
	DDX_Check(pDX, IDC_POLICY_VIEW_AUDIT_INFORMATION, m_POLICY_VIEW_AUDIT_INFORMATION);
	DDX_Check(pDX, IDC_POLICY_GET_PRIVATE_INFORMATION, m_POLICY_GET_PRIVATE_INFORMATION);
	DDX_Check(pDX, IDC_POLICY_TRUST_ADMIN, m_POLICY_TRUST_ADMIN);
	DDX_Check(pDX, IDC_POLICY_CREATE_ACCOUNT, m_POLICY_CREATE_ACCOUNT);
	DDX_Check(pDX, IDC_POLICY_CREATE_SECRET, m_POLICY_CREATE_SECRET);
	DDX_Check(pDX, IDC_POLICY_CREATE_PRIVILEGE, m_POLICY_CREATE_PRIVILEGE);
	DDX_Check(pDX, IDC_POLICY_SET_DEFAULT_QUOTA_LIMITS, m_POLICY_SET_DEFAULT_QUOTA_LIMITS);
	DDX_Check(pDX, IDC_POLICY_SET_AUDIT_REQUIREMENTS, m_POLICY_SET_AUDIT_REQUIREMENTS);
	DDX_Check(pDX, IDC_POLICY_AUDIT_LOG_ADMIN, m_POLICY_AUDIT_LOG_ADMIN);
	DDX_Check(pDX, IDC_POLICY_SERVER_ADMIN, m_POLICY_SERVER_ADMIN);
	DDX_Check(pDX, IDC_POLICY_LOOKUP_NAMES, m_POLICY_LOOKUP_NAMES);
	DDX_Check(pDX, IDC_POLICY_NOTIFICATION, m_POLICY_NOTIFICATION);
}


BEGIN_MESSAGE_MAP(HandleAccessChoice, CDialogEx)
END_MESSAGE_MAP()


// HandleAccessChoice message handlers
