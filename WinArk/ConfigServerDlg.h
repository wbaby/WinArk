#pragma once
#include "resource.h"


class CConfigServerDbg
	: public CDialogImpl<CConfigServerDbg> {
public:
	enum { IDD = IDD_CONFIG_SERVER };

	BEGIN_MSG_MAP(CConfigServerDbg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
		COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
	END_MSG_MAP()


	LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	std::string GetServer() const;
private:
	CButton m_Check1, m_Check2, m_Check3;
	CEdit m_Edit;
	std::string m_Server;
};
