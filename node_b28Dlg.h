// node_b28Dlg.h : header file
//

#if !defined(AFX_NODE_B28DLG_H__169F2837_7F47_48D6_965E_2D14E5CEA363__INCLUDED_)
#define AFX_NODE_B28DLG_H__169F2837_7F47_48D6_965E_2D14E5CEA363__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNode_b28Dlg dialog

class CNode_b28Dlg : public CDialog
{
// Construction
public:
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	BOOL GetFilePath(char *FilePath, int type, HWND hParentWnd=NULL);
	changeZhState();
	CString getRunEnvironment();
	void setOutput(CString msg);
	CNode_b28Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNode_b28Dlg)
	enum { IDD = IDD_NODE_B28_DIALOG };
	CEdit	m_output;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNode_b28Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	DWORD ThreadID;
	HANDLE hThread;
	// Generated message map functions
	//{{AFX_MSG(CNode_b28Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnViewSrc();
	afx_msg void OnSaveDest();
	afx_msg void OnRadioTranslate();
	afx_msg void OnButtonLang();
	afx_msg void OnDoWork();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NODE_B28DLG_H__169F2837_7F47_48D6_965E_2D14E5CEA363__INCLUDED_)
