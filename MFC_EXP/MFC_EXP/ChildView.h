
// ChildView.h: CChildView 类的接口
//


#pragma once

#include "math.h"

#include "Point3D.h"

#include "CDialogEXP3_1.h"
#include "CDialogEXP3_2.h"

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
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnExp1();
	afx_msg void OnExp2();
	afx_msg void OnExp3();
	afx_msg void OnExp31();
	afx_msg void OnExp32();
	afx_msg void OnExp4();
	afx_msg void OnExp5();
	afx_msg void OnExp51();
	afx_msg void OnExp52();
	afx_msg void OnExp53();
	afx_msg void OnExp54();
	afx_msg void OnExp6();
	afx_msg void OnExp7();

	// 实验类型
	int TypeEXP;
	// 按键是否按下
	bool boolLButtonDown;
	bool boolRButtonDown;

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);	
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	void ClearScreen();

	CPoint startPoint;
	CPoint endPoint;
	
	// 顶点列表
	CArray<CPoint, CPoint> pointList;

	// DDA直线画法
	void DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	// 填充学号
	void PatternFill(CDC *pDC, int x, int y);

	// EXP3
private:
	// 立方体相关点参数
	Point3D LBB3D;
	CPoint	LBB2D;
	Point3D LBT3D;
	CPoint	LBT2D;
	Point3D LFB3D;
	CPoint	LFB2D;
	Point3D LFT3D;
	CPoint	LFT2D;
	Point3D RBB3D;
	CPoint	RBB2D;
	Point3D RBT3D;
	CPoint	RBT2D;
	Point3D RFB3D;
	CPoint	RFB2D;
	Point3D RFT3D;
	CPoint	RFT2D;
	double mPM[4][4];
	// 是否为透视投影
	bool perspectiveProjection;
public:
	// 偏移量
	int shifting;
	// 变化程度
	double mStep;	//平移
	double pStep;	//比例
	double rStep;	//旋转
	// 透视点
	double perspectiveX;
	double perspectiveY;
	double perspectiveZ;
	// XYZ轴
	int axes;
	// 画矩形
	void DrawRect(CDC* pDC, CPoint P1, CPoint P3);
	void DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4);
	// 画立方体
	void DrawCubic();
	// 坐标变换
	void From3DTo2D();
	// 比例变换
	void ProportionChange(double scale);
	// 旋转变换
	void RotateChange(double angle);

	// EXP4
	CPoint startCutPoint;
	CPoint endCutPoint;
	CArray<CPoint, CPoint> pointCutList;
	void CutTop();
	void CutLeft();
	void CutBottom();
	void CutRight();

	// EXP5
	int typeEXP5;							//哪种类型画线
	int N;									//次数
	int K;									//阶数
	int nPoints;							//划分点
	CArray<CPoint, CPoint> pointPrintList;	//画点数组
	void HermiteToPoints();					//计算hermite曲线上各点坐标值
	CPoint Hermite(CPoint V[], double u);	//计算hermite曲线在参数为U的坐标值
	void BezierToPoints();					
	CPoint Bezier(double u);				//几何作图法
	void BSplineToPoints();					
	CPoint BSpline(double knot[], int num, double u);
	double Base(int i, int k, double knot[], int num, double u);//计算B样条基函数
	Point3D *ControlPoint;					//曲面角点的信息矩阵
	// 计算Bezier曲面上各点的坐标值
	void BezierToPoints2D(int n, int npoints, Point3D P[], Point3D points[]);
	//矩阵乘积运算
	template <typename T1, typename T2, typename T3> void
		Product(T1 a[], T2 b[], T3 c[], int ah, int s, int bw);
	//矩阵转置运算
	template <typename T> void Transpose(T a[], int n);
	// 世界坐标->观察坐标->屏幕坐标
	CPoint WorldToView(Point3D pt, Point3D VLoca, double Vz);
	// X轴上观察坐标->屏幕坐标
	long dtxs(double x);
	// Y轴上观察坐标->屏幕坐标
	long dtys(double y);
};

