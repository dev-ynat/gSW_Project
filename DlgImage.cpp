// DlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "gSW_Project.h"
#include "afxdialogex.h"
#include "DlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{

}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CDlgImage::InitImage(int x, int y) 
{
	m_nWidth = x;
	m_nHeight = y;
	int nBpp = 8;
	m_image.Create(m_nWidth, -m_nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, m_nWidth * m_nHeight);
}

void CDlgImage::InitPoint(int sx, int sy, int ex, int ey)
{
	m_nStartX = sx;
	m_nStartY = sy;
	m_nEndX = ex;
	m_nEndY = ey;
	if (!m_bAction) {
		processCircle();
	}
}

void CDlgImage::processCircle()
{
	int nTempPoint = 1;
	m_nRadius = rand() % 100 + 10;
	drawCircle(m_nStartX, m_nStartY);
}

void CDlgImage::drawCircle(int x, int y)
{
	int nCenterX = x - m_nRadius;
	int nCenterY = y - m_nRadius;

	int nPitch = m_image.GetPitch();

	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, m_nWidth * m_nHeight);
	for (int i = nCenterX; i < x + m_nRadius * 2; i++) {
		for (int j = nCenterY; j < y + m_nRadius * 2; j++) {
			if (initCirlcle(i, j, x, y, m_nRadius)) {
				if(vaildImgPos(i, j))
					fm[j * nPitch + i] = m_nGray;
			}
		}
	}
	UpdateDisplay();
}

BOOL CDlgImage::vaildImgPos(int x, int y)
{
	CRect rect(0, 0, m_nWidth, m_nHeight);
	return rect.PtInRect(CPoint(x, y));
}

bool CDlgImage::initCirlcle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;
	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}
	return bRet;
}

//void CDlgImage::moveElli(int x, int y)
//{
//	int nPitch = m_image.GetPitch();
//	unsigned char* fm = (unsigned char*)m_image.GetBits();
//	drawCircle(fm, x, y);
//}

int CDlgImage::Point(bool check, int point, int StPoint)
{
	if (check) {
		int nTemp = StPoint + point;
		std::cout << "Plus = " << nTemp << std::endl;
		return nTemp;
		//return StPoint + point;
	}
	else {
		int nTemp = StPoint - point;
		std::cout << "Minus = " << nTemp << std::endl;
		return nTemp;
		//return StPoint - point;
	}
}

void CDlgImage::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}


// CDlgImage 메시지 처리기


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
}
