// CGExeView.cpp : implementation of the CCGExeView class
//

#include "stdafx.h"
#include "CGExe.h"

#include "CGExeDoc.h"
#include "CGExeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGExeView

IMPLEMENT_DYNCREATE(CCGExeView, CView)

BEGIN_MESSAGE_MAP(CCGExeView, CView)
	//{{AFX_MSG_MAP(CCGExeView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGExeView construction/destruction

CCGExeView::CCGExeView()
{
	// TODO: add construction code here
	this->isPressed=FALSE;
	this->isCityLoaded=FALSE;
	map = NULL;

}

CCGExeView::~CCGExeView()
{
}

BOOL CCGExeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCGExeView drawing

void CCGExeView::OnDraw(CDC* pDC)
{
	CCGExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*ddaLine.setPoint(100,100,500,400);
	ddaLine.Draw(pDC);
	myLine.Draw(pDC);

	if(this->isCityLoaded)
		chnCity.Draw(pDC);

	bezier.clearAllPoints();
	bezier.addPoint_Ct(CPoint(100,100));
	bezier.addPoint_Ct(CPoint(300,250));
	bezier.addPoint_Ct(CPoint(200,400));
	bezier.addPoint_Ct(CPoint(400,500));
	bezier.Draw(pDC);*/

	convexHull.Draw(pDC);

/*	if(map!=NULL)
	{
		map->Draw(pDC);
		mapPrj->Draw(pDC);
	}*/


}

/////////////////////////////////////////////////////////////////////////////
// CCGExeView printing

BOOL CCGExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCGExeView diagnostics

#ifdef _DEBUG
void CCGExeView::AssertValid() const
{
	CView::AssertValid();
}

void CCGExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGExeDoc* CCGExeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGExeDoc)));
	return (CCGExeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGExeView message handlers

void CCGExeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	this->isPressed=TRUE;                     //设置鼠标被按下状态标志
	pt1=point;                                //起点、终点指向同一点point，即鼠标按下点
	pt2=point;*/
	
	CView::OnLButtonDown(nFlags, point);
}

void CCGExeView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*this->isPressed=FALSE;                    //设置鼠标按下为不响应状态
	//this->Invalidate();                     //每次清除屏幕上所有临时图形

	CClientDC dc(this);                       //获取当前绘制图形区域的绘制对象
	
	CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)); 
	CBrush *oldBrush=dc.SelectObject(brush);  //选择该空笔刷，并保留以前笔刷到oldBrush

	CPen pen(PS_DOT,1,RGB(255,0,0));          //红色虚线笔
	CPen *oldPen=dc.SelectObject(&pen);       //选择该红色虚线笔，并保存以前笔到oldPen

	pt2=point;                                //新点赋值
	dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);    //绘制新图形

	dc.SelectObject(oldBrush);                //恢复笔刷
	dc.SelectObject(oldPen);                  //恢复以前笔形*/
	
	
	/*pt2=point;
	OnPrepareDC(&dc);                         //调用OnPrepareDC，实现对dc做同样坐标映射
	dc.DPtoLP(&pt1);                          //将基于设备坐标的pt1，转换为窗口坐标
	dc.DPtoLP(&pt2);                          //将基于设备坐标的point，转换为窗口坐标
	int minx=min(pt1.x,pt2.x);
	int miny=min(pt1.y,pt2.y);
	int maxx=max(pt1.x,pt2.x);
	int maxy=max(pt1.y,pt2.y);                //获取新的矩形区域

	CRect rect(minx,miny,maxx,maxy);
	this->wcRect=rect;
	Invalidate();*/

	CView::OnLButtonUp(nFlags, point);
}

void CCGExeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!this->isPressed)                      //如果鼠标没有被按下，平移不做任何事情，直接返回
		return;

    CClientDC dc(this);                       //获取当前绘制图形区域的绘制对象
	dc.SetROP2(R2_NOT);                       //设置绘图模式为取背景色为相反色
	/*
	dc.MoveTo(pt1);                           //移动到第一点
	dc.LineTo(pt2);                           //擦除老的线条

	pt2=point;                                //终点更新为当前点point
	dc.MoveTo(pt1);                           //移动到第一点
	dc.LineTo(pt2);                           //绘制到第二点
	*/

	//多边形默认为填充，所以需要设置一个空笔刷，使得绘制只考虑边界
	CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *oldBrush=dc.SelectObject(brush);  //选择该空笔刷，并保留以前的笔刷到oldBrush

	CPen pen(PS_DASHDOT,1,RGB(255,0,0));      //红色虚线笔
	CPen *oldPen=dc.SelectObject(&pen);       //选择该红色虚线笔，并保存以前笔到oldPen

	dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);    //擦除老的图形
	pt2=point;                                //新点赋值
	dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);    //绘制新图形

	dc.SelectObject(oldBrush);                //恢复笔刷
	dc.SelectObject(oldPen);                  //恢复以前笔形

	CView::OnMouseMove(nFlags, point);
}

void CCGExeView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	//空间索引
	/*CFileDialog fDlg(true); //构造打开文件对话框
	if(fDlg.DoModal()==IDOK) //打开文件，并选择文件ok后
	{
		CString fileName=fDlg.GetPathName();  //获取文件名称
		FILE *fp=fopen(fileName,"r"); //创建文件指针，并打开对应文件
		if(fp==NULL) //如果文件打开失败，提示信息
		{
			MessageBox("文件打开失败!");
			return;
		}
		int id;
		float lon,lat;
		CString name;
		float minl,minb,maxl,maxb;  //数据范围
		int scale=1000000;   //定义一比例尺，使其保证原始数据精度，同时满足绘制int需要
		minl=minb=180*scale;  //经纬度最大值
		maxl=maxb=-180*scale;   //经纬度最小值

		if(map!=NULL) return;
		map=new CGeoMap();//创建新的地图对象
		CGeoLayer *layer=new CGeoLayer();//创建空图层
		CSpatialObject *object=NULL;//创建空要素

		while(!feof(fp)) //文件没有结束
		{
			CSpatialObject *object=new CSpatialObject();//创建空空间要素
			fscanf(fp,"%d%f%f%s",&id,&lon,&lat,name); //读取数据
			lon=lon*scale;
			lat=lat*scale;
			minl=minl>lon?lon:minl;    //获取最小外接矩形
			minb=minb>lat?lat:minb;
			maxl=maxl<lon?lon:maxl;
			maxb=maxb<lat?lat:maxb;
			
			object->Id=id;
			object->lon=lon;
			object->lat=lat;
			object->name=name;
			layer->addObject(object);
		}
		map->addLayer(layer);
		fclose(fp);    //文件关闭
		map->wcRect=CRect(minl,minb,maxl,maxb);//设置其坐标范围
	}	
	Invalidate();  //强制让屏幕重绘*/

	//地图填充
	/*CFileDialog fDlg(true); //构造打开文件对话框
	if(fDlg.DoModal() == IDOK) //打开文件，并选择文件ok后
	{
		CString fileName=fDlg.GetPathName();  //获取文件名称
		FILE *fp=fopen(fileName,"r"); //创建文件指针，并打开对应文件
		if(fp==NULL) //如果文件打开失败，提示信息
		{
			MessageBox("文件打开失败!");
			return;
		}
		
		int flag1,flag2;
		float lon,lat;
		int size;
		float minb,minl,maxb,maxl;  //数据范围
		float minx,miny,maxx,maxy;
		int scale=1000000;   //定义一比例尺，使其保证原始数据精度，同时满足绘制int需要
		char *str1,*str2,*str3;
		str1=(char *)malloc(100*sizeof(char));
		str2=(char *)malloc(10*sizeof(char));
		minl=minb=180*scale;  //经纬度最大值
		maxl=maxb=-180*scale;   //经纬度最小值
		
		if(map!=NULL) return;
		map=new CGeoMap();//创建新的地图对象		
		CGeoLayer *layer=new CGeoLayer();//创建空图层
		CGeoPolygon *poly=NULL;//创建空要素
		
		while(!feof(fp)) //文件没有结束
		{
			fscanf(fp,"%s",str1);
			str2="1";
			flag1=strcmp(str1,str2);
			if(flag1==0)
			{
				poly=new CGeoPolygon();
				fscanf(fp,"%d",&size);
				for(int i=0;i<size;i++)
				{
					CPoint myPoint;
					fscanf(fp,"%f%f",&lon,&lat); //读取数据
					lat=lat*scale;				
					lon=lon*scale;
					minb=minb>lat?lat:minb;    //获取最小外接矩形
					minl=minl>lon?lon:minl;
					maxb=maxb<lat?lat:maxb;
					maxl=maxl<lon?lon:maxl;
					myPoint.x=lon;
					myPoint.y=lat;
					poly->addPts(myPoint);   //将其加入到数组中
				}
				layer->addPolygon(poly);

				do                           //读取中心点  
				{
					fscanf(fp,"%s",str1);
					str3="Center";
					flag2=strcmp(str1,str3);
				}while(flag2!=0);
				CPoint ctPt;
				fscanf(fp,"%f%f",&lon,&lat);
				ctPt.x=lon*scale;
				ctPt.y=lat*scale;
				poly->addCtPts(ctPt);
				
			}
		}
		map->addLayer(layer);
		fclose(fp);    //文件关闭
		
		minl=minl/1000000.0;
		minb=minb/1000000.0;
		maxl=maxl/1000000.0;
		maxb=maxb/1000000.0;
		mapPrj->getXY(minl,minb,&minx,&miny);
		mapPrj->getXY(maxl,maxb,&maxx,&maxy);
		map->wcRect=CRect(minx,miny,maxx,maxy);  //设置其坐标范围
	}	
	Invalidate();  //强制让屏幕重绘*/
	

	//地图投影
    /*CFileDialog fDlg(true); //构造打开文件对话框
	if(fDlg.DoModal() == IDOK) //打开文件，并选择文件ok后
	{
		CString fileName=fDlg.GetPathName();  //获取文件名称
		FILE *fp=fopen(fileName,"r"); //创建文件指针，并打开对应文件
		if(fp==NULL) //如果文件打开失败，提示信息
		{
			MessageBox("文件打开失败!");
			return;
		}

		int flag;
		float lon,lat;
		int size;
		float minb,minl,maxb,maxl;  //数据范围
		float minx,miny,maxx,maxy;
		int scale=1000000;   //定义一比例尺，使其保证原始数据精度，同时满足绘制int需要
		char *str1,*str2;
		str1=(char *)malloc(100*sizeof(char));
		str2=(char *)malloc(10*sizeof(char));
		minl=minb=180*scale;  //经纬度最大值
		maxl=maxb=-180*scale;   //经纬度最小值

		if(map!=NULL) return;
		map=new CGeoMap();//创建新的地图对象		
		CGeoLayer *layer=new CGeoLayer();//创建空图层
		CGeoPolyline *poly=NULL;//创建空要素
		
		while(!feof(fp)) //文件没有结束
		{
			fscanf(fp,"%s",str1);
			str2="Pline";
			flag=strcmp(str1,str2);
			if(flag==0)
			{
				poly=new CGeoPolyline();
				fscanf(fp,"%d",&size);
				for(int i=0;i<size;i++)
				{
					CPoint myPoint;
					fscanf(fp,"%f%f",&lon,&lat); //读取数据
					lat=lat*scale;				
					lon=lon*scale;
					minb=minb>lat?lat:minb;    //获取最小外接矩形
					minl=minl>lon?lon:minl;
					maxb=maxb<lat?lat:maxb;
					maxl=maxl<lon?lon:maxl;
					myPoint.x=lon;
					myPoint.y=lat;
					poly->addMyPoint(myPoint);   //将其加入到数组中
				}
				layer->addPolyline(poly);
			}
		}
		map->addLayer(layer);
		fclose(fp);    //文件关闭

		minl=minl/1000000.0;
		minb=minb/1000000.0;
		maxl=maxl/1000000.0;
		maxb=maxb/1000000.0;
		mapPrj->getXY(minl,minb,&minx,&miny);
		mapPrj->getXY(maxl,maxb,&maxx,&maxy);
		map->wcRect=CRect(minx,miny,maxx,maxy);  //设置其坐标范围
	}	
	Invalidate();  //强制让屏幕重绘*/

    //凸壳生成
	CFileDialog fDlg(true);
	if(fDlg.DoModal()==IDOK)
	{
		CString fileName=fDlg.GetPathName();
		FILE *fp=fopen(fileName,"r");
		if(fp==NULL)
		{
			MessageBox("文件打开失败");
			return;
		}
		float x,y;
		float minx,miny,maxx,maxy;
		while(!feof(fp))
		{
			fscanf(fp,"%f %f",&x,&y);
			minx=minx>x?x:minx;          
			miny=miny>y?y:miny;
			maxx=maxx<x?x:maxx;
			maxy=maxy<y?y:maxy;
			convexHull.pts.Add(CPoint((int)x,(int)y));
		}
		convexHull.crWCRect=CRect(minx,miny,maxx,maxy);
		this->crWCRect=convexHull.crWCRect;
		this->convexHull.getConvexHull();
		fclose(fp);
	}
	Invalidate();

    //图形裁切
	/*CFileDialog fDlg(true);
	if(fDlg.DoModal()==IDOK)
	{
		CString fileName=fDlg.GetPathName();
		FILE *fp=fopen(fileName,"r");
		if(fp==NULL)
		{
			MessageBox("文件打开失败");
			return;
		}

		int l,t,r,b;
		if(map!=NULL) return;
		map=new CGeoMap();//创建新的地图对象
		fscanf(fp,"%d%d%d%d",&l,&t,&r,&b);
		map->wcRect=CRect(l,t,r,b);

		CGeoLayer *layer=new CGeoLayer();//创建空图层
		CGeoPolyline *poly=NULL;//创建空要素
		int size;
		int x,y;
		while(!feof(fp))
		{
			poly=new CGeoPolyline();
			fscanf(fp,"%d",&size);
			for(int i=0;i<size;i++)
			{
				fscanf(fp,"%d%d",&x,&y);
				poly->addPoint(CPoint(x,y));
			}
			layer->addPolyline(poly);
		}
		map->addLayer(layer);
		fclose(fp);
		map->clipRect=CRect(l/2,t/2,r/2,b/2);
		map->clipMap(map->clipRect);
	}
	Invalidate();*/

}

void CCGExeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class

    if(map!=NULL)
	{
		CSize size;                          //表示矩形的宽度和高度
		CPoint pt;
		CRect rectD;

		this->GetClientRect(&rectD);         //获得客户区矩形区域，当前窗口左上角x\y为0，右下角为当前窗口的宽度、高度
		size.cx=rectD.Width();
		size.cy=rectD.Height();
		pt=rectD.CenterPoint();              //返回中心点坐标

		pDC->SetMapMode(MM_ISOTROPIC);     //设置指定设备环境的映射模式
		pDC->SetViewportExt(size);           //设置窗口尺寸
		pDC->SetViewportOrg(pt);             //设置窗口中心点为坐标系原点

		size=this->map->wcRect.Size();            
		size.cx=(int)(size.cx*1.02);
		size.cy=-(int)(size.cy*1.02);
		pt=this->map->wcRect.CenterPoint();

		pDC->SetWindowExt(size);             //设置窗口长宽
		pDC->SetWindowOrg(pt);               //设置窗口原点
	}
	CView::OnPrepareDC(pDC, pInfo);
}
