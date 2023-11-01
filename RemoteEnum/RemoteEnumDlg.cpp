
// RemoteEnumDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "RemoteEnum.h"
#include "RemoteEnumDlg.h"
#include "CRightsDialog.h"
#include "afxdialogex.h"
#include "ntstatus.h"
#include <sddl.h>
#include <sstream>

#include "C:\\Projects\\EnumLib\\EnumLib\\EnumLib\\EnumLib.h"
#pragma comment(lib, "C:\\Projects\\EnumLib\\EnumLib\\x64\\Debug\\EnumLib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGetHandle();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GET_HANDLE, &CAboutDlg::OnBnClickedButtonGetHandle)
END_MESSAGE_MAP()


// CRemoteEnumDlg dialog



CRemoteEnumDlg::CRemoteEnumDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REMOTEENUM_DIALOG, pParent)
	, m_ComputerName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemoteEnumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_REMOTE_COMPUTER, m_ComputerName);
	DDX_Control(pDX, IDC_OUTPUT, m_txtOutput);
}

BEGIN_MESSAGE_MAP(CRemoteEnumDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GET_HANDLE, &CRemoteEnumDlg::OnBnClickedButtonGetHandle)
	ON_EN_CHANGE(IDC_OUTPUT, &CRemoteEnumDlg::OnEnChangeOutput)
END_MESSAGE_MAP()


// CRemoteEnumDlg message handlers

BOOL CRemoteEnumDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemoteEnumDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRemoteEnumDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRemoteEnumDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRemoteEnumDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


void CRemoteEnumDlg::OnBnClickedButtonGetHandle()
{
	CRightsDialog dlgGetAccessRights;
	if (dlgGetAccessRights.DoModal() == IDOK)
	{
		// Example: Accessing a result method from dlg
		ACCESS_MASK mask = dlgGetAccessRights.CalculateAccessMask();

		// Use mask or other results as needed
		LSA_HANDLE policyHandle = nullptr;
		LPCWSTR computerName = m_ComputerName.GetBuffer();
		NTSTATUS status = GetLSAPolicyHandle(computerName, &policyHandle, mask);

		if (status != STATUS_SUCCESS)
		{
			DWORD errorCode = LsaNtStatusToWinError(status);
			AppendTextToOutput(_T("Win32 Error Code: ") + CString(std::to_wstring(errorCode).c_str()) + _T("\n"));
		}
		else
		{
			AppendTextToOutput(_T("LSA policy handle obtained successfully."));

			std::vector<SID*> sids = EnumerateUserSIDs(policyHandle, L"SeInteractiveLogonRight");
			std::vector<std::wstring> names = TranslateSidsToNames(policyHandle, sids);
			std::vector<PSID> remoteUserSids = LookupUserNamesToSids(policyHandle, names);

			// Print names and SIDs
			AppendTextToOutput(_T("\r\nAccount Name\t\tSID\r\n"));
			AppendTextToOutput(CString('-', 60) + _T("\r\n"));  // Draws a line separator

			for (size_t i = 0; i < remoteUserSids.size() && i < names.size(); ++i)
			{
				CString wname(names[i].c_str());
				CString wSidString = SidToString(remoteUserSids[i]);
				CString line = wname + _T("\t\t") + wSidString + _T("\r\n");

				AppendTextToOutput(line);
			}


		}


		m_ComputerName.ReleaseBuffer();

		// Actions after closing the dialog
	}

	// TODO: Add your control notification handler code here
}

CString CRemoteEnumDlg::SidToString(PSID pSid)
{
	if (!IsValidSid(pSid))
	{
		return _T("Invalid SID");
	}

	LPWSTR stringSid = nullptr;
	if (!ConvertSidToStringSid(pSid, &stringSid))
	{
		// Optionally, retrieve the error message for more details
		DWORD error = GetLastError();
		// Handle error or log it as needed
		return _T("Conversion Failed, Error: ") + CString(std::to_wstring(error).c_str());
	}

	CString result(stringSid);
	LocalFree(stringSid);
	return result;
}


void CAboutDlg::OnBnClickedButtonGetHandle()
{
	// TODO: Add your control notification handler code here
}


void CRemoteEnumDlg::OnEnChangeOutput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CRemoteEnumDlg::AppendTextToOutput(const CString& str)
{
	int nLength = m_txtOutput.GetWindowTextLength();
	m_txtOutput.SetSel(nLength, nLength); 
	m_txtOutput.ReplaceSel(str);
}

