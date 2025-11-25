#include "stdafx.h"
#include "ConfigServerDlg.h"
#include "Helpers.h"

LRESULT CConfigServerDbg::OnInitDialog(UINT uMsg, WPARAM wParam,
	LPARAM lParam, BOOL& bHandled) {
	m_Check1.Attach(GetDlgItem(IDC_SZDYG));
	m_Check2.Attach(GetDlgItem(IDC_MICROSOFT));
	m_Edit.Attach(GetDlgItem(IDC_SERVER_URL));
	return TRUE;
}

LRESULT CConfigServerDbg::OnCloseCmd(WORD, WORD wID, HWND, BOOL&) {
	if (wID == IDOK) {
		if (m_Check1.GetCheck() == BST_CHECKED) {
			m_Server = "https://msdl.szdyg.cn/download/symbols";
		}
		if (m_Check2.GetCheck() == BST_CHECKED) {
			m_Server = "https://msdl.microsoft.com/download/symbols";
		}
		CString url;
		m_Edit.GetWindowText(url);
		if (!url.IsEmpty()) {
			std::wstring wurl(url);
			m_Server = Helpers::WstringToString(wurl);
		}

	}
	EndDialog(wID);
	return 0;
}

std::string CConfigServerDbg::GetServer() const {
	return m_Server;
}