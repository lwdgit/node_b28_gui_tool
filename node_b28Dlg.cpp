// node_b28Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "node_b28.h"
#include "node_b28Dlg.h"
#include <atlconv.h>
#include <shlobj.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




CString ConvertGBKToUtf8(CString strGBK )
{
    int len=MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, NULL,0);
    WCHAR * wszUtf8 = new WCHAR[len+1];
    memset(wszUtf8, 0, len * 2 + 2);
    MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)strGBK, -1, wszUtf8, len);
 
    len = WideCharToMultiByte(CP_UTF8, 0, wszUtf8, -1, NULL, 0, NULL, NULL);
    char *szUtf8=new char[len + 1];
    memset(szUtf8, 0, len + 1);
    WideCharToMultiByte (CP_UTF8, 0, wszUtf8, -1, szUtf8, len, NULL,NULL);
 
    return (CString)szUtf8;
    //delete[] szUtf8;
    //delete[] wszUtf8;
}


inline BYTE toHex(const BYTE &x)
{
       return x > 9 ? x + 55: x + 48;
}
CString UrlEncode(CString sIn)
{

	   sIn = ConvertGBKToUtf8(sIn);
       CString sOut;
      
       const int nLen = sIn.GetLength() + 1;
 
       register LPBYTE pOutTmp = NULL;
       LPBYTE pOutBuf = NULL;
       register LPBYTE pInTmp = NULL;
       LPBYTE pInBuf =(LPBYTE)sIn.GetBuffer(nLen);
       BYTE b = 0;
      
       //alloc out buffer
       pOutBuf = (LPBYTE)sOut.GetBuffer(nLen*3 - 2);//new BYTE [nLen  * 3];
 
       if(pOutBuf)
       {
              pInTmp   = pInBuf;
              pOutTmp = pOutBuf;
             
              // do encoding
              while (*pInTmp)
              {
                     if(isalnum(*pInTmp))
                            *pOutTmp++ = *pInTmp;
                     else
                            if(isspace(*pInTmp))
                                   *pOutTmp++ = '+';
                            else
                            {
                                   *pOutTmp++ = '%';
                                   *pOutTmp++ = toHex(*pInTmp>>4);
                                   *pOutTmp++ = toHex(*pInTmp%16);
                            }
                     pInTmp++;
              }
              *pOutTmp = '\0';
              //sOut=pOutBuf;
              //delete [] pOutBuf;
              sOut.ReleaseBuffer();
       }
       sIn.ReleaseBuffer();
       return sOut;
}


CString ConvertUtf8ToGBK(CString& strUtf8 )
{
    int len=MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, NULL,0);
    WCHAR * wszGBK = new WCHAR[len+1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)strUtf8, -1, wszGBK, len);
 
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char *szGBK=new char[len + 1];
    memset(szGBK, 0, len + 1);
    WideCharToMultiByte (CP_ACP, 0, wszGBK, -1, szGBK, len, NULL,NULL);
 
    return (CString)szGBK;
    //delete[] szGBK;
    //delete[] wszGBK;
 
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
    CAboutDlg();
	
	// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA
	
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL
	
	// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNode_b28Dlg dialog

CNode_b28Dlg::CNode_b28Dlg(CWnd* pParent /*=NULL*/)
: CDialog(CNode_b28Dlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CNode_b28Dlg)
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNode_b28Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CNode_b28Dlg)
    DDX_Control(pDX, IDC_EDIT_OUTPUT, m_output);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNode_b28Dlg, CDialog)
//{{AFX_MSG_MAP(CNode_b28Dlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnViewSrc)
ON_BN_CLICKED(IDC_BUTTON2, OnSaveDest)
ON_BN_CLICKED(IDC_BUTTON_LANG, OnButtonLang)
ON_BN_CLICKED(IDC_RADIO1, OnRadioTranslate)
ON_BN_CLICKED(IDC_RADIO2, OnRadioTranslate)
ON_BN_CLICKED(IDC_RADIO3, OnRadioTranslate)
ON_BN_CLICKED(IDC_RADIO4, OnRadioTranslate)
ON_BN_CLICKED(IDC_BUTTON3, OnDoWork)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNode_b28Dlg message handlers

BOOL CNode_b28Dlg::OnInitDialog()
{
    CDialog::OnInitDialog();
	
    // Add "About..." menu item to system menu.
	
    // IDM_ABOUTBOX must be in the system command range.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);
	
    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        CString strAboutMenu;
        strAboutMenu.LoadString(IDS_ABOUTBOX);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }
	
    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);         // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon
    
    // TODO: Add extra initialization here
    ((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
    ((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(TRUE);
    setOutput("欢迎使用多国语自动提取翻译助手V1.4");

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNode_b28Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialog::OnSysCommand(nID, lParam);
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNode_b28Dlg::OnPaint() 
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting
		
        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
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
        CDialog::OnPaint();
    }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNode_b28Dlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

#define BIF_USENEWUI 0x0050
#define BIF_NEWDIALOGSTYLE 0x0040

static INT CALLBACK BrowseCallbackProc(HWND hwnd,  UINT uMsg, LPARAM lp,  LPARAM pData) 
{
	//回调函数,用于初始化目录
   switch(uMsg) 
   {
   case BFFM_INITIALIZED: 
       {
           // WParam is TRUE since you are passing a path.
           // It would be FALSE if you were passing a pidl.
           TCHAR szDir[MAX_PATH]={0};
           GetCurrentDirectory(sizeof(szDir)/sizeof(TCHAR), szDir);
           SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)szDir);
       }
       break;
   }
   return 0;
}


BOOL CNode_b28Dlg::GetFilePath(char *FilePath, int type, HWND hParentWnd)
{
	if (type == 0) {
		BROWSEINFO bInfo;
		LPITEMIDLIST pidl;
		ZeroMemory ((PVOID) &bInfo,sizeof (BROWSEINFO));
		
		bInfo.hwndOwner=hParentWnd;
		bInfo.pszDisplayName=FilePath;
		bInfo.lpszTitle="请选择文件夹或文件：";
		bInfo.ulFlags=BIF_USENEWUI //BIF_USENEWUI拥有新特性,有新建文件夹按钮,可以调整大小,一般加上
			|BIF_RETURNFSANCESTORS //Only return file system ancestors
			|BIF_RETURNONLYFSDIRS //Only return file system directories
			|BIF_BROWSEINCLUDEFILES;//只需要文件夹不需要文件时可以去掉BIF_BROWSEINCLUDEFILES ,
		bInfo.lpfn=BrowseCallbackProc;
		bInfo.lParam=0;
		
		if ((pidl = ::SHBrowseForFolder(&bInfo)) == NULL)    return false;
		if (::SHGetPathFromIDList(pidl,FilePath) == FALSE)   return false; 
		return true;
	} else {
		CString filename ;
		if (type == 1) {
			CFileDialog fileDlg (TRUE, "json", filename,OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, "JSON文件|*.json||");
			if(fileDlg.DoModal()==IDOK) {
				filename = fileDlg.GetPathName();  
				SetDlgItemText(IDC_EDIT_SRC, filename);
				return false;
			}
		} else {
			CFileDialog fileDlg (TRUE, "xlsx", filename,OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, "Office 2007文件|*.xlsx|");
			if(fileDlg.DoModal()==IDOK) {
				filename = fileDlg.GetPathName();    
				SetDlgItemText(IDC_EDIT_SRC, filename);
				return false;
			}
		}
	}
	return false;
	 //default return
}



CString SaveDirPath(CString strFolderPath) {
    BROWSEINFO broInfo = {0};
    TCHAR       szDisName[MAX_PATH] = {0};
	
    //broInfo.hwndOwner = this->m_hWnd;
    broInfo.pidlRoot  = NULL;
    broInfo.pszDisplayName = szDisName;
    broInfo.lpszTitle = _T("选择保存路径：");
    broInfo.ulFlags   = BIF_USENEWUI | BIF_DONTGOBELOWDOMAIN
        | BIF_BROWSEFORCOMPUTER | BIF_RETURNONLYFSDIRS | BIF_RETURNFSANCESTORS;
    broInfo.lpfn      = BrowseCallbackProc;
    broInfo.lParam    = NULL;
    broInfo.iImage    = IDR_MAINFRAME;
	
    LPITEMIDLIST pIDList = SHBrowseForFolder(&broInfo);
    if (pIDList != NULL)
    {
        memset(szDisName, 0, sizeof(szDisName));
        SHGetPathFromIDList(pIDList, szDisName);
        strFolderPath = szDisName;
    }
    return strFolderPath;
}

CString SaveFilePath(CString path) {
    CFileDialog fileDlg (FALSE, "xlsx", "lang.xlsx",OFN_HIDEREADONLY, "Office 2007|*.xlsx|");
    
    if(fileDlg.DoModal()==IDOK)
    {
        return fileDlg.GetPathName();    
    } else 
        return path;
}


void CNode_b28Dlg::OnViewSrc() 
{
    CString filePath;
    if (GetFilePath((LPSTR)(LPCSTR)filePath, ((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck() ? 1 : ((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck() ? 2 : 0)) {
        SetDlgItemText(IDC_EDIT_SRC, filePath);
    }
}

void CNode_b28Dlg::OnSaveDest() 
{
    CString path;
    GetDlgItemText(IDC_EDIT_DEST, path);
	
    if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() || ((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck()) path = SaveDirPath(path);
    else path = SaveFilePath(path);
    
    path.TrimLeft();
    SetDlgItemText(IDC_EDIT_DEST, path);
}

CNode_b28Dlg::changeZhState()
{
	if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()){
        ((CButton *)GetDlgItem(IDC_CHECK1))->EnableWindow(TRUE);
    } else {
        ((CButton *)GetDlgItem(IDC_CHECK1))->EnableWindow(FALSE);
    }

	if(((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck()) {
		((CEdit *)GetDlgItem(IDC_EDIT_LANG))->EnableWindow(TRUE);
		((CButton *)GetDlgItem(IDC_BUTTON_LANG))->EnableWindow(TRUE);
	} else {
		((CEdit *)GetDlgItem(IDC_EDIT_LANG))->EnableWindow(FALSE);
		SetDlgItemText(IDC_EDIT_LANG, "");
		((CButton *)GetDlgItem(IDC_BUTTON_LANG))->EnableWindow(FALSE);
	}
	SetDlgItemText(IDC_EDIT_SRC, "");
	SetDlgItemText(IDC_EDIT_DEST, "");
}


void CNode_b28Dlg::OnRadioTranslate() 
{
    // TODO: Add your control notification handler code here
    changeZhState();
}

void CNode_b28Dlg::OnButtonLang() 
{
    CString filename ;
    CFileDialog fileDlg (TRUE, "json", filename,OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, "JSON语言包|*.json|All Files (*.*)|*.*||");
    if( fileDlg.DoModal()==IDOK) {
        filename = fileDlg.GetPathName();    
        SetDlgItemText(IDC_EDIT_LANG, filename);
    }
}

CString GetModuleDir() 
{ 
	HMODULE module = GetModuleHandle(0); 
	char pFileName[MAX_PATH]; 
	GetModuleFileName(module, pFileName, MAX_PATH); 
	
	CString csFullPath(pFileName); 
	int nPos = csFullPath.ReverseFind( _T('\\') ); 
	if( nPos < 0 ) 
		return CString(""); 
	else 
		return csFullPath.Left(nPos); 
}

void CNode_b28Dlg::OnDoWork() 
{
    CString srcPath, destPath, langPath;
    BOOL onlyZH = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
    short workType = ((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() ? 1 : 0;
    GetDlgItemText(IDC_EDIT_SRC, srcPath);
    GetDlgItemText(IDC_EDIT_DEST, destPath);
    GetDlgItemText(IDC_EDIT_LANG, langPath);
    if (srcPath == "" || destPath == "" || (workType == 1 && langPath == "")) {
        MessageBox("请先将路径配置完整！");
        return;
    }
	
    CString args = "",args1="", output = "";

    if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck()) {

		args.Format("%s/bin/node \"%s/bin/node_b28.js\" -encode --src=%s --dest=%s", 
			GetModuleDir(), ConvertGBKToUtf8(GetModuleDir()), UrlEncode(srcPath), UrlEncode(destPath));
		args1.Format("%s/bin/node \"%s/bin/node_b28.js\" --src=%s --dest=%s",
			GetModuleDir(), GetModuleDir(), srcPath, destPath);

        if (onlyZH) {
            args += " -zh";
			args1 += " -zh";
        }

    } else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck()) {

        args.Format("%s/bin/node \"%s/bin/node_b28.js\" -encode --src=%s --dest=%s -t", 
			GetModuleDir(), ConvertGBKToUtf8(GetModuleDir()), UrlEncode(srcPath), UrlEncode(destPath));
		args1.Format("%s/bin/node \"%s/bin/node_b28.js\" --src=%s --dest=%s -t",
			GetModuleDir(), GetModuleDir(), srcPath, destPath);

    } else if (((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck()) {

		args.Format("%s/bin/node \"%s/bin/JSON2EXECL.js\" -encode -f %s -o %s", 
			GetModuleDir(), ConvertGBKToUtf8(GetModuleDir()), UrlEncode(srcPath), UrlEncode(destPath));
		args1.Format("%s/bin/node \"%s/bin/JSON2EXECL.js\" -f %s -o %s",
			GetModuleDir(), GetModuleDir(), srcPath, destPath);

	} else if (((CButton *)GetDlgItem(IDC_RADIO4))->GetCheck()) {

		args.Format("%s/bin/node \"%s/bin/EXCEL2JSON.js\" -encode -f %s -o %s", 
			GetModuleDir(), ConvertGBKToUtf8(GetModuleDir()), UrlEncode(srcPath), UrlEncode(destPath));
		args1.Format("%s/bin/node \"%s/bin/EXCEL2JSON.js\" -f %s -o %s",
			GetModuleDir(), GetModuleDir(), srcPath, destPath);

	}

    setOutput("Excute:" + args1);
	
    output = ConvertUtf8ToGBK(ExecuteCmd(args));
    if (output.Find("success!")<0) {
        output += "\r\n执行失败，请检查错误信息! ↑↑↑\r\n";
        setOutput(output);
        MessageBox("执行失败，请检查错误信息!");
    } else {
        output += "\r\n执行成功!\r\n";
        MessageBox("执行成功!");
        setOutput(output);
    }
}

TCHAR* StringToChar(CString& str)
{
    int len=str.GetLength();
    TCHAR* tr=str.GetBuffer(len);
    str.ReleaseBuffer();
    return tr; 
}


CString CNode_b28Dlg::ExecuteCmd(CString str)
{
	SECURITY_ATTRIBUTES sa;
	HANDLE hRead,hWrite;
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
	{
		MessageBox("Error on CreatePipe()!");
		return "";
	}
	STARTUPINFO si={sizeof(si)};
	PROCESS_INFORMATION pi;
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	TCHAR* cmdline=StringToChar(str);
	if (!CreateProcess(NULL,cmdline,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
	{
		MessageBox("Error on CreateProcess()!");
		return "";
	}
	CloseHandle(hWrite);
	
	char buffer[4096];
	memset(buffer,0,4096);
	CString output;
	DWORD byteRead;
	while(true)
	{
		if (ReadFile(hRead,buffer,4095,&byteRead,NULL) == NULL)
		{
			break;
		}
		output += buffer;
	}
	return output;
}

CString outPut = "";
void CNode_b28Dlg::setOutput(CString msg)
{
    outPut += msg + "\r\n";
    SetDlgItemText(IDC_EDIT_OUTPUT, outPut);
    int index=m_output.GetLineCount();//获得当前List控件一共多少行
    m_output.LineScroll(index,0);//将垂直滚动条滚动到最后一行
}



CString CNode_b28Dlg::getRunEnvironment()
{
	char pFileName[MAX_PATH]; 
    int nPos = GetCurrentDirectory( MAX_PATH, pFileName); 
	
    CString csFullPath(pFileName);  
    if( nPos < 0 ) 
        return CString(""); 
    else 
        return csFullPath; 
}



