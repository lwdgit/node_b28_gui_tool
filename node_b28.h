// node_b28.h : main header file for the NODE_B28 application
//

#if !defined(AFX_NODE_B28_H__583F4A86_2035_491B_8A95_091791C62F64__INCLUDED_)
#define AFX_NODE_B28_H__583F4A86_2035_491B_8A95_091791C62F64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNode_b28App:
// See node_b28.cpp for the implementation of this class
//

class CNode_b28App : public CWinApp
{
public:
	CNode_b28App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNode_b28App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNode_b28App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NODE_B28_H__583F4A86_2035_491B_8A95_091791C62F64__INCLUDED_)
