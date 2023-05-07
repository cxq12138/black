#pragma once
#include<iostream>
using namespace std;
#include"workers.h"

class WorkerManager
{
public:
	WorkerManager();  //构造函数判断文本状态并初始化变量
	//显示菜单
	void showMenu();
	//退出管理程序
	void exitProgram();
	//增加职工函数
	void add_per();
	//显示职工函数
	void showPer();
	//得到初始职工数量
	int txtNotnull();
	//初始化职工数组
	void resetArr();
	//显示职工信息函数
	void showWorkers();
	//删除离职职工函数
	void delworker();
	//修改职工信息
	void modifyWorker();
	//查找职工信息
	void selectWorker();
	//对职工数组排序
	void sortArray();
	//清空所有文档
	void clearWorker();

	~WorkerManager();

	int n;               //职工数量
	workers** perArray;  //指向职工数组的指针
	bool txtIsnull;
};