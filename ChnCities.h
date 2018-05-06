// ChnCities.h: interface for the CChnCities class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHNCITIES_H__FA4A8589_6618_4D28_AC65_E69DC1539E58__INCLUDED_)
#define AFX_CHNCITIES_H__FA4A8589_6618_4D28_AC65_E69DC1539E58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct city_Struct  //定义结构体
{
	int id;         //ID
	float lon;      //经度
	float lat;      //纬度
	CString name;   //城市名称
};

typedef struct city_Struct CITY; 

#include "afxtempl.h" //用于支持安全数组的头文件

class CChnCities  
{
public:
	void Draw(CDC *pDC);
	void addCity(CITY city);
	CArray <CITY,CITY>cities; //动态数组cities定义

	CRect wcRect;             //包含所有点集的外接矩形，记录原始图形范围


	CChnCities();
	virtual ~CChnCities();

};

#endif // !defined(AFX_CHNCITIES_H__FA4A8589_6618_4D28_AC65_E69DC1539E58__INCLUDED_)
