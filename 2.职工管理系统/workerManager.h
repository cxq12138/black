#pragma once
#include<iostream>
using namespace std;
#include"workers.h"

class WorkerManager
{
public:
	WorkerManager();  //���캯���ж��ı�״̬����ʼ������
	//��ʾ�˵�
	void showMenu();
	//�˳��������
	void exitProgram();
	//����ְ������
	void add_per();
	//��ʾְ������
	void showPer();
	//�õ���ʼְ������
	int txtNotnull();
	//��ʼ��ְ������
	void resetArr();
	//��ʾְ����Ϣ����
	void showWorkers();
	//ɾ����ְְ������
	void delworker();
	//�޸�ְ����Ϣ
	void modifyWorker();
	//����ְ����Ϣ
	void selectWorker();
	//��ְ����������
	void sortArray();
	//��������ĵ�
	void clearWorker();

	~WorkerManager();

	int n;               //ְ������
	workers** perArray;  //ָ��ְ�������ָ��
	bool txtIsnull;
};