
// ChildView.cpp: CChildView 类的实现
//

#include "stdafx.h"
#include "MFC_EXP.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	TypeEXP = 1;
	boolLButtonDown = false;
	boolRButtonDown = false;
	xStep = 1.5;
	yStep = 1.5;
	rStep = 0.05;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
//	ON_WM_PAINT()
	ON_COMMAND(ID_EXP1, &CChildView::OnExp1)
	ON_COMMAND(ID_EXP2, &CChildView::OnExp2)
	ON_COMMAND(ID_EXP3, &CChildView::OnExp3)
	ON_COMMAND(ID_EXP4, &CChildView::OnExp4)
	ON_COMMAND(ID_EXP5, &CChildView::OnExp5)
	ON_COMMAND(ID_EXP6, &CChildView::OnExp6)
	ON_COMMAND(ID_EXP7, &CChildView::OnExp7)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOUSEWHEEL()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_WM_SIZE()
ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDBLCLK()
ON_COMMAND(ID_EXP3_1, &CChildView::OnExp31)
ON_COMMAND(ID_EXP3_2, &CChildView::OnExp32)
ON_WM_RBUTTONDOWN()
ON_WM_RBUTTONUP()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}


void CChildView::OnExp1()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 1;
	ClearScreen();
}


void CChildView::OnExp2()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 2;
	ClearScreen();
}


void CChildView::OnExp3()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 3;

	ClearScreen();

	int c = 400;

	LBB3D = Point3D(c-100,c-100, c-100);
	LBT3D = Point3D(c-100, c -100, c +100);
	LFB3D = Point3D(c-100, c+100,c -100);
	LFT3D = Point3D(c-100, c+100,  c+100);
	RBB3D = Point3D(c+100, c-100, c-100);
	RBT3D = Point3D(c+100, c-100,c + 100);
	RFB3D = Point3D(c+100, c +100, c-100);
	RFT3D = Point3D(c+100, c +100,c  +100);
}

void CChildView::OnExp31()
{
	// TODO: 在此添加命令处理程序代码
	OnExp3();
	double L = 1;
	double Alpha = 45;
	Alpha *= 3.1415926 / 180;
	double c = cos(Alpha);
	double s = sin(Alpha);

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = L * c;
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = L * s;
	mPM[1][3] = 0;	
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;	
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 0;
	mPM[3][3] = 1;
	From3DTo2D();
	DrawCubic();
}


void CChildView::OnExp32()
{
	// TODO: 在此添加命令处理程序代码
	OnExp3();
	double x = 2;
	double y = 1;
	double d = 1;

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = x /d;
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = y/d;
	mPM[1][3] = 0;
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 1/d;
	mPM[3][3] = 0;
	From3DTo2D();
	DrawCubic();
}

void CChildView::OnExp4()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 4;
	ClearScreen();
}


void CChildView::OnExp5()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 5;
	ClearScreen();
}


void CChildView::OnExp6()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 6;
	ClearScreen();
}


void CChildView::OnExp7()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 7;
	ClearScreen();
}

void CChildView::ClearScreen()
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 3:
	{
		ClearScreen();
		if (nChar == VK_LEFT) {
			LBB3D.x -= xStep;
			LBT3D.x -= xStep;
			LFB3D.x -= xStep;
			LFT3D.x -= xStep;
			RBB3D.x -= xStep;
			RBT3D.x -= xStep;
			RFB3D.x -= xStep;
			RFT3D.x -= xStep;
		}
		if (nChar == VK_RIGHT) {
			LBB3D.x += xStep;
			LBT3D.x += xStep;
			LFB3D.x += xStep;
			LFT3D.x += xStep;
			RBB3D.x += xStep;
			RBT3D.x += xStep;
			RFB3D.x += xStep;
			RFT3D.x += xStep;
		}
		if (nChar == VK_UP) {
			LBB3D.y -= yStep;
			LBT3D.y -= yStep;
			LFB3D.y -= yStep;
			LFT3D.y -= yStep;
			RBB3D.y -= yStep;
			RBT3D.y -= yStep;
			RFB3D.y -= yStep;
			RFT3D.y -= yStep;
		}
		if (nChar == VK_DOWN) {
			LBB3D.y += yStep;
			LBT3D.y += yStep;
			LFB3D.y += yStep;
			LFT3D.y += yStep;
			RBB3D.y += yStep;
			RBT3D.y += yStep;
			RFB3D.y += yStep;
			RFT3D.y += yStep;
		} 
		From3DTo2D();
		DrawCubic();
	}
	break;

	default:
		break;
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->SetCapture();	//捕捉鼠标

	switch (TypeEXP)
	{
	case 1:
	{
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
	}
		break;
	case 2:
	{
		startPoint = point;
		endPoint = point;
		pointList.Add(point);
		boolLButtonDown = true;
	}
		break;
	default:
		break;
	}
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 1:
	{
		ReleaseCapture();	//释放鼠标
		boolLButtonDown = false;
		CDC* pDC = this->GetDC();
		pDC->Ellipse(startPoint.x, startPoint.y, point.x, point.y);
	}
	break;

	default:
		break;
	}

	CWnd::OnLButtonUp(nFlags, point);
}

void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 2:	//左键双击闭合多边形
	{
		if (boolLButtonDown)
		{
			ReleaseCapture();	//释放鼠标
			boolLButtonDown = false;
			CDC* pDC = this->GetDC();
			CPoint p1 = pointList.GetAt(0);
			CPoint p2;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p2 = pointList.GetAt(i);
				DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
				p1 = p2;
			}
			p2 = pointList.GetAt(0);
			DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
		}
	}
	break;

	default:
		break;
	}

	CWnd::OnLButtonDblClk(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 3:
	{
		startPoint = point;
		endPoint = point;
		boolRButtonDown = true;
	}
	break;

	default:
		break;
	}
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 3:
	{
		ReleaseCapture();	//释放鼠标
		boolRButtonDown = false;
	}
	break;

	default:
		break;
	}
	CWnd::OnRButtonUp(nFlags, point);
}

void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 2:	//右键双击填充多边形
	{
		if (!boolLButtonDown && pointList.GetSize() > 0)
		{
			CDC* pDC = this->GetDC();
			CPoint p1, p2, p3;
			//取矩阵最小扫描界
			int maxX, minX, maxY, minY;
			p1 = pointList.GetAt(0);
			maxX = p1.x;
			minX = p1.x;
			maxY = p1.y;
			minY = p1.y;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i);
				if (p1.x > maxX) maxX = p1.x;
				if (p1.x < minX) minX = p1.x;
				if (p1.y > maxY) maxY = p1.y;
				if (p1.y < minY) minY = p1.y;
			}
			//改变极值点
			p1 = pointList.GetAt(pointList.GetSize() - 1);
			p2 = pointList.GetAt(0);
			p3 = pointList.GetAt(1);
			if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
			{
				pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
			}
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i - 1);
				p2 = pointList.GetAt(i);
				if (i != pointList.GetSize() - 1)
				{
					p3 = pointList.GetAt(i + 1);
				}
				else
				{
					p3 = pointList.GetAt(0);
				}
				if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
				{
					pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
				}
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY - 1; y < maxY + 1; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX - 1; x < maxX + 1; x++)
				{
					bder = (pDC->GetPixel(x, y) == RGB(0, 0, 0));
					if (bder && flag)
					{
						inside = !inside;
						flag = false;
					}
					else if (!bder && !flag)
					{
						flag = true;
					}
					if (inside && !bder) PatternFill(pDC, x, y);
				}
			}
			pointList.RemoveAll();
		}
	}
	break;

	default:
		break;
	}
	CWnd::OnRButtonDblClk(nFlags, point);
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (boolLButtonDown)
	{
		switch (TypeEXP)
		{
		case 1:
		{
			CDC* pDC = this->GetDC();	//构造设备环境对象
			pDC->SetROP2(R2_NOT);		//设置绘图模式为R2_NOT
			pDC->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			pDC->Ellipse(startPoint.x, startPoint.y, point.x, point.y);
			endPoint = point;
		}
			break;
		case 2:
		{
			CDC* pDC = this->GetDC();	//构造设备环境对象
			pDC->SetROP2(R2_NOT);		//设置绘图模式为R2_NOT
			DDALine(pDC, startPoint.x, startPoint.y, endPoint.x, endPoint.y, RGB(0, 0, 0));
			DDALine(pDC, startPoint.x, startPoint.y, point.x, point.y, RGB(0, 0, 0));
			endPoint = point;
		}
			break;
		default:
			break;
		}
	}

	CWnd::OnMouseMove(nFlags, point);
}


// DDA直线画法
void CChildView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	// TODO: 在此处添加实现代码.
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e;
	dy /= e;
	x = x1;
	y = y1;
	pDC->MoveTo(x1, y1);
	for (int i = 1; i <= e; i++)
	{
		pDC->SetPixel((int)(x + 0.5), (int)(y + 0.5), color);
		x += dx;
		y += dy;
	}
}


// 填充学号
void CChildView::PatternFill(CDC *pDC, int x, int y)
{
	// TODO: 在此处添加实现代码.
	int rec[10][32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int a = x % 64;
	int b = y % 20;
	if (rec[b/2][a/2] == 1) pDC->SetPixel(x, y, RGB(255, 0, 0));
}


// 画矩形
void CChildView::DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4)
{
	// TODO: 在此处添加实现代码.
	CDC* pDC = this->GetDC();
	pDC->MoveTo(P1);
	pDC->LineTo(P2);
	pDC->LineTo(P3);
	pDC->LineTo(P4);
	pDC->LineTo(P1);
}


// 画立方体
void CChildView::DrawCubic()
{
	// TODO: 在此处添加实现代码.
	DrawRect(LBB2D, LBT2D, LFT2D, LFB2D);
	DrawRect(RBB2D, RBT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LBT2D, RBT2D, RBB2D);
	DrawRect(LFB2D, LFT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LFB2D, RFB2D, RBB2D);
	DrawRect(LBT2D, LFT2D, RFT2D, RBT2D);
}


// 坐标变换
void CChildView::From3DTo2D()
{
	// TODO: 在此处添加实现代码.
	LBB2D.x = long(LBB3D.x * mPM[0][0] + LBB3D.y * mPM[0][1] + LBB3D.z * mPM[0][2] + mPM[0][4]);
	LBB2D.y = long(LBB3D.x * mPM[1][0] + LBB3D.y * mPM[1][1] + LBB3D.z * mPM[1][2] + mPM[1][4]);
	LBT2D.x = long(LBT3D.x * mPM[0][0] + LBT3D.y * mPM[0][1] + LBT3D.z * mPM[0][2] + mPM[0][4]);
	LBT2D.y = long(LBT3D.x * mPM[1][0] + LBT3D.y * mPM[1][1] + LBT3D.z * mPM[1][2] + mPM[1][4]);
	LFB2D.x = long(LFB3D.x * mPM[0][0] + LFB3D.y * mPM[0][1] + LFB3D.z * mPM[0][2] + mPM[0][4]);
	LFB2D.y = long(LFB3D.x * mPM[1][0] + LFB3D.y * mPM[1][1] + LFB3D.z * mPM[1][2] + mPM[1][4]);
	LFT2D.x = long(LFT3D.x * mPM[0][0] + LFT3D.y * mPM[0][1] + LFT3D.z * mPM[0][2] + mPM[0][4]);
	LFT2D.y = long(LFT3D.x * mPM[1][0] + LFT3D.y * mPM[1][1] + LFT3D.z * mPM[1][2] + mPM[1][4]);
	RBB2D.x = long(RBB3D.x * mPM[0][0] + RBB3D.y * mPM[0][1] + RBB3D.z * mPM[0][2] + mPM[0][4]);
	RBB2D.y = long(RBB3D.x * mPM[1][0] + RBB3D.y * mPM[1][1] + RBB3D.z * mPM[1][2] + mPM[1][4]);
	RBT2D.x = long(RBT3D.x * mPM[0][0] + RBT3D.y * mPM[0][1] + RBT3D.z * mPM[0][2] + mPM[0][4]);
	RBT2D.y = long(RBT3D.x * mPM[1][0] + RBT3D.y * mPM[1][1] + RBT3D.z * mPM[1][2] + mPM[1][4]);
	RFB2D.x = long(RFB3D.x * mPM[0][0] + RFB3D.y * mPM[0][1] + RFB3D.z * mPM[0][2] + mPM[0][4]);
	RFB2D.y = long(RFB3D.x * mPM[1][0] + RFB3D.y * mPM[1][1] + RFB3D.z * mPM[1][2] + mPM[1][4]);
	RFT2D.x = long(RFT3D.x * mPM[0][0] + RFT3D.y * mPM[0][1] + RFT3D.z * mPM[0][2] + mPM[0][4]);
	RFT2D.y = long(RFT3D.x * mPM[1][0] + RFT3D.y * mPM[1][1] + RFT3D.z * mPM[1][2] + mPM[1][4]);
}