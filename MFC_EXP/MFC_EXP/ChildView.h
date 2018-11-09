
// ChildView.h: CChildView 类的接口
//


#pragma once


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
//	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnExp1();
	afx_msg void OnExp2();
	afx_msg void OnExp3();
	afx_msg void OnExp4();
	afx_msg void OnExp5();
	afx_msg void OnExp6();
	afx_msg void OnExp7();

	// 实验类型
	int TypeEXP;
	bool boolLButtonDown;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	CPoint startPoint;
	CPoint endPoint;
	
	//顶点列表
	CArray<CPoint, CPoint> pointList;

	// DDA直线画法
	void DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	// 填充学号
	void PatternFill(CDC *pDC, int x, int y);
};

