
// gSW_ProjectDlg.h: 헤더 파일
//

#pragma once

#include "DlgImage.h"
// CgSWProjectDlg 대화 상자
class CgSWProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CgSWProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

private:
	CDlgImage* m_pDlgImage;

	int m_nWidth = 1060;
	int m_nHeight = 710;

	int m_nDlgWidth = 1020;
	int m_nDlgHeight = 480;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GSW_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	void InitImage();
	bool PointCheck();
	int comparePoint(bool check, int point, int incr, int EndPoint);
	int DistanceMaxValue(int start, int end, int divison);
	int DistanceMinValue(int startX, int startY, int endX, int endY, int nIncre);
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnAction();
};
