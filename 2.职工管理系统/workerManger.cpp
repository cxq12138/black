#include"workerManager.h"
#include<fstream>

WorkerManager::WorkerManager(){
	//文件判断

	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		this->n = 0;
		this->perArray = NULL;
		this->txtIsnull = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->n = 0;
		this->perArray = NULL;
		this->txtIsnull = true;
		ifs.close();
		return;
	}
	//统计职工人数
	this->n = this->txtNotnull();
	//初始化职工数组
	this->perArray = new workers * [this->n];
	this->resetArr();
	this->txtIsnull = false;

}

void WorkerManager::showMenu()
{
	cout << "*********************************" << endl;
	cout << "***   欢迎使用职工管理系统  *****" << endl;
	cout << "*****   0、退出管理程序   *******" << endl;
	cout << "*****   1、增加职工信息   *******" << endl;
	cout << "*****   2、显示职工信息   *******" << endl;
	cout << "*****   3、删除离职职工   *******" << endl;
	cout << "*****   4、修改职工信息   *******" << endl;
	cout << "*****   5、查找职工信息   *******" << endl;
	cout << "*****   6、按照编号排序   *******" << endl;
	cout << "*****   7、清空所有文档   *******" << endl;
	cout << "*********************************" << endl;
}

void WorkerManager::add_per()
{
	cout << "请输入增加职工数量：" << endl;
	int j;
	cin >> j;
	if (j > 0)
	{
		int newN = this->n + j;
		workers** newPer = new workers * [newN];
		if (this->perArray != NULL)
		{
			for (int i = 0; i < this->n; i++)
			{
				newPer[i] = this->perArray[i];
			}
		}
		for (int i = 0; i < j; i++)
		{
			int id;
			string name;
			int did;
			cout << "请输入第 " << i + 1 << " 个新职工编号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			workers* worker = NULL;
			if (did == 1)
				worker = new person(id, name, did);
			if (did == 2)
				worker = new person(id, name, did);
			if (did == 3)
				worker = new person(id, name, did);
			newPer[this->n + i] = worker;
		}
		delete[] this->perArray;
		this->perArray = newPer;
		this->n = newN;
		ofstream ofs;
		ofs.open("test.txt", ios::out);
		for (int i = 0;i < this->n; i++)
		{
			ofs << this->perArray[i]->id << " " << this->perArray[i]->name << " " << this->perArray[i]->did << endl;
		}
		ofs.close();
		
		cout << "成功添加 " << j << " 名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	if (this->n != 0)
		this->txtIsnull = false;
	system("pause");
	system("cls");
}

int WorkerManager::txtNotnull()
{
	int id,did,num = 0;
	string name;
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::resetArr()
{
	int id, did, num = 0;
	string name;
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		workers* wk = NULL;
		if (did == 1)
			wk = new person(id, name, did);
		if (did == 2)
			wk = new manager(id, name, did);
		if (did == 3)
			wk = new boss(id, name, did);
		this->perArray[num] = wk;
		num++;
	}
	ifs.close();
}
void WorkerManager::showWorkers()
{
	if (this->txtIsnull)
	{
		cout << "职工数据为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		this->perArray[i]->sayWork();
	}
	system("pause");
	system("cls");
}

void WorkerManager::delworker()
{
	if (this->txtIsnull)
	{
		cout << "职工数据为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id,i;
	cout << "输入您要删除的职工编号：" << endl;
	cin >> id;
	for (i = 0; i < this->n; i++)
		if (this->perArray[i]->id == id)
			break;
	if (i == this->n)
	{
		cout << "无此员工编号！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (; i < n; i++)
		this->perArray[i] = this->perArray[i + 1];
	this->n -= 1;
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	for (i = 0; i < this->n; i++)
	{
		ofs << this->perArray[i]->id << " " << this->perArray[i]->name << " " << this->perArray[i]->did << endl;
	}
	ofs.close();
	cout << "删除成功" << endl;
	if (this->n == 0)
		this->txtIsnull = true;
	system("pause");
	system("cls");
}

void WorkerManager::modifyWorker()
{
	if (this->txtIsnull)
	{
		cout << "职工数据为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id,i;
	cout << "输入修改的职工编号：" << endl;
	cin >> id;
	for ( i = 0; i < this->n; i++)
	{
		if (this->perArray[i]->id == id)
		{
			cout << "已查到 " << this->perArray[i]->id << " 号职工，请输入新职工号" << endl;
			cin >> this->perArray[i]->id;
			cout << "请输入新姓名：" << endl;
			cin >> this->perArray[i]->name;
			cout << "请输入新岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> this->perArray[i]->did;
			ofstream ofs;
			ofs.open("test.txt", ios::out);
			for (i = 0; i < this->n; i++)
			{
				ofs << this->perArray[i]->id << " " << this->perArray[i]->name << " " << this->perArray[i]->did << endl;
			}
			ofs.close();
			system("pause");
			system("cls");
			return;
		}
	}
	if (i == this->n)
	{
		cout << "无此员工编号！" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager::selectWorker()
{
	if (this->txtIsnull)
	{
		cout << "职工数据为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id, opt, i;
	string name;
	cout << "请选择查找的方式：" << endl;
	cout << "1、按职工编号查找" << endl;
	cout << "2、按姓名查找" << endl;
	cin >> opt;
	if (opt == 1)
	{
		cout << "请输入查找的职工编号：" << endl;
		cin >> id;
		for(i = 0;i<this->n;i++)
			if (this->perArray[i]->id == id)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->perArray[i]->sayWork();
				system("pause");
				system("cls");
				return;
			}
		if (i == this->n)
		{
			cout << "无此员工编号！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	if (opt == 2)
	{
		cout << "请输入查找的姓名：" << endl;
		cin >> name;
		for (i = 0; i < this->n; i++)
			if (this->perArray[i]->name == name)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->perArray[i]->sayWork();
				system("pause");
				system("cls");
				return;
			}
		if (i == this->n)
		{
			cout << "无此员工姓名！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "输入有误！" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager::sortArray()
{
	if (this->txtIsnull)
	{
		cout << "职工数据为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	int max_id, j, opt;
	workers* wk = NULL;
	cout << "请选择排序类型：" << endl;
	cout << "1、按职工编号升序" << endl;
	cout << "2、按职工编号降序" << endl;
	cin >> opt;
	if (opt == 1)
	{
		for (int i = 0; i < (this->n) - 1; i++)
		{
			max_id = this->perArray[i]->id;
			for (int k = i; k < this->n; k++)
			{
				if (this->perArray[k]->id <= max_id)
				{
					max_id = this->perArray[k]->id;
					j = k;
				}
			}
			wk = this->perArray[j];
			this->perArray[j] = this->perArray[i];
			this->perArray[i] = wk;
		}
		cout << "排序成功！排序结果为：" << endl;
		this->showWorkers();
	}
	if (opt == 2)
	{
		for (int i = 0; i < (this->n) - 1; i++)
		{
			max_id = this->perArray[i]->id;
			for (int k = i; k < this->n; k++)
			{
				if (this->perArray[k]->id >= max_id)
				{
					max_id = this->perArray[k]->id;
					j = k;
				}
			}
			wk = this->perArray[j];
			this->perArray[j] = this->perArray[i];
			this->perArray[i] = wk;
		}
		this->showWorkers();
	}
}

void WorkerManager::clearWorker()
{
	int opt;
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	cin >> opt;
	if (opt == 2)
	{
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs;
	//打开模式 ios::trunc 如果存在删除文件并重新创建

	ofs.open("test.txt", ios::trunc);
	ofs.close();

	if (this->perArray != NULL)
	{
		for (int i = 0; i < this->n; i++)
		{

			//删除堆区的每个职工对象
			if (this->perArray[i] != NULL)
				delete this->perArray[i];
		}

		//删除堆区数组指针
		this->n = 0;
		delete[] this->perArray;
		this->perArray = NULL;
		this->txtIsnull = true;
		cout << "清空成功" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
	return;
}
WorkerManager::~WorkerManager(){}