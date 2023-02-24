
// MFCApplication3Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication3Dlg
class CMFCApplication3Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	float X1;
	float Y1;
	float X2;
	float Y2;
	float resultX;
	float resultY;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
};
