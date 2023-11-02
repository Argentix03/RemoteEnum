// CUserRightsSelection.cpp : implementation file
//

#include "pch.h"
#include "RemoteEnum.h"
#include "afxdialogex.h"
#include "CUserRightsSelection.h"


// CUserRightsSelection dialog

IMPLEMENT_DYNAMIC(CUserRightsSelection, CDialogEx)

CUserRightsSelection::CUserRightsSelection(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CUserRightsSelection::~CUserRightsSelection()
{
}

void CUserRightsSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PERMISSIONS, m_userRightsList);
}



BEGIN_MESSAGE_MAP(CUserRightsSelection, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_PERMISSIONS, &CUserRightsSelection::OnLbnSelchangeListPermissions)
END_MESSAGE_MAP()


// CUserRightsSelection message handlers


BOOL CUserRightsSelection::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_userRightsList.AddString(_T("SeTrustedCredManAccessPrivilege"));
	m_userRightsList.AddString(_T("SeNetworkLogonRight"));
	m_userRightsList.AddString(_T("SeTcbPrivilege"));
	m_userRightsList.AddString(_T("SeMachineAccountPrivilege"));
	m_userRightsList.AddString(_T("SeIncreaseQuotaPrivilege"));
	m_userRightsList.AddString(_T("SeInteractiveLogonRight"));
	m_userRightsList.AddString(_T("SeRemoteInteractiveLogonRight"));
	m_userRightsList.AddString(_T("SeBackupPrivilege"));
	m_userRightsList.AddString(_T("SeChangeNotifyPrivilege"));
	m_userRightsList.AddString(_T("SeSystemtimePrivilege"));
	m_userRightsList.AddString(_T("SeTimeZonePrivilege"));
	m_userRightsList.AddString(_T("SeCreatePagefilePrivilege"));
	m_userRightsList.AddString(_T("SeCreateTokenPrivilege"));
	m_userRightsList.AddString(_T("SeCreateGlobalPrivilege"));
	m_userRightsList.AddString(_T("SeCreatePermanentPrivilege"));
	m_userRightsList.AddString(_T("SeCreateSymbolicLinkPrivilege"));
	m_userRightsList.AddString(_T("SeDebugPrivilege"));
	m_userRightsList.AddString(_T("SeDenyNetworkLogonRight"));
	m_userRightsList.AddString(_T("SeDenyBatchLogonRight"));
	m_userRightsList.AddString(_T("SeDenyServiceLogonRight"));
	m_userRightsList.AddString(_T("SeDenyInteractiveLogonRight"));
	m_userRightsList.AddString(_T("SeDenyRemoteInteractiveLogonRight"));
	m_userRightsList.AddString(_T("SeEnableDelegationPrivilege"));
	m_userRightsList.AddString(_T("SeRemoteShutdownPrivilege"));
	m_userRightsList.AddString(_T("SeAuditPrivilege"));
	m_userRightsList.AddString(_T("SeImpersonatePrivilege"));
	m_userRightsList.AddString(_T("SeIncreaseWorkingSetPrivilege"));
	m_userRightsList.AddString(_T("SeIncreaseBasePriorityPrivilege"));
	m_userRightsList.AddString(_T("SeLoadDriverPrivilege"));
	m_userRightsList.AddString(_T("SeLockMemoryPrivilege"));
	m_userRightsList.AddString(_T("SeBatchLogonRight"));
	m_userRightsList.AddString(_T("SeServiceLogonRight"));
	m_userRightsList.AddString(_T("SeSecurityPrivilege"));
	m_userRightsList.AddString(_T("SeRelabelPrivilege"));
	m_userRightsList.AddString(_T("SeSystemEnvironmentPrivilege"));
	m_userRightsList.AddString(_T("SeDelegateSessionUserImpersonatePrivilege"));
	m_userRightsList.AddString(_T("SeManageVolumePrivilege"));
	m_userRightsList.AddString(_T("SeProfileSingleProcessPrivilege"));
	m_userRightsList.AddString(_T("SeSystemProfilePrivilege"));
	m_userRightsList.AddString(_T("SeUndockPrivilege"));
	m_userRightsList.AddString(_T("SeAssignPrimaryTokenPrivilege"));
	m_userRightsList.AddString(_T("SeRestorePrivilege"));
	m_userRightsList.AddString(_T("SeShutdownPrivilege"));
	m_userRightsList.AddString(_T("SeSyncAgentPrivilege"));
	m_userRightsList.AddString(_T("SeTakeOwnershipPrivilege"));


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

CString CUserRightsSelection::GetSelectedPermission() const
{
	TCHAR msgbuf[256];
	wsprintf(msgbuf, L"The m_userRightsList: %p\n", &m_userRightsList);
	OutputDebugString(msgbuf);
	int selIndex = m_userRightsList.GetCurSel();
	if (selIndex != LB_ERR)
	{
		CString selectedItem;
		m_userRightsList.GetText(selIndex, selectedItem);
		return selectedItem;
	}
	return _T("");
}

void CUserRightsSelection::OnLbnSelchangeListPermissions()
{
	// TODO: Add your control notification handler code here
}
