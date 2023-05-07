#include"workerManager.h"
#include<fstream>

WorkerManager::WorkerManager(){
	//�ļ��ж�

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
	//ͳ��ְ������
	this->n = this->txtNotnull();
	//��ʼ��ְ������
	this->perArray = new workers * [this->n];
	this->resetArr();
	this->txtIsnull = false;

}

void WorkerManager::showMenu()
{
	cout << "*********************************" << endl;
	cout << "***   ��ӭʹ��ְ������ϵͳ  *****" << endl;
	cout << "*****   0���˳��������   *******" << endl;
	cout << "*****   1������ְ����Ϣ   *******" << endl;
	cout << "*****   2����ʾְ����Ϣ   *******" << endl;
	cout << "*****   3��ɾ����ְְ��   *******" << endl;
	cout << "*****   4���޸�ְ����Ϣ   *******" << endl;
	cout << "*****   5������ְ����Ϣ   *******" << endl;
	cout << "*****   6�����ձ������   *******" << endl;
	cout << "*****   7����������ĵ�   *******" << endl;
	cout << "*********************************" << endl;
}

void WorkerManager::add_per()
{
	cout << "����������ְ��������" << endl;
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
			cout << "������� " << i + 1 << " ����ְ�����" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
		
		cout << "�ɹ���� " << j << " ����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
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
		cout << "ְ������Ϊ�գ�" << endl;
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
		cout << "ְ������Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id,i;
	cout << "������Ҫɾ����ְ����ţ�" << endl;
	cin >> id;
	for (i = 0; i < this->n; i++)
		if (this->perArray[i]->id == id)
			break;
	if (i == this->n)
	{
		cout << "�޴�Ա����ţ�" << endl;
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
	cout << "ɾ���ɹ�" << endl;
	if (this->n == 0)
		this->txtIsnull = true;
	system("pause");
	system("cls");
}

void WorkerManager::modifyWorker()
{
	if (this->txtIsnull)
	{
		cout << "ְ������Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id,i;
	cout << "�����޸ĵ�ְ����ţ�" << endl;
	cin >> id;
	for ( i = 0; i < this->n; i++)
	{
		if (this->perArray[i]->id == id)
		{
			cout << "�Ѳ鵽 " << this->perArray[i]->id << " ��ְ������������ְ����" << endl;
			cin >> this->perArray[i]->id;
			cout << "��������������" << endl;
			cin >> this->perArray[i]->name;
			cout << "�������¸�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
		cout << "�޴�Ա����ţ�" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager::selectWorker()
{
	if (this->txtIsnull)
	{
		cout << "ְ������Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id, opt, i;
	string name;
	cout << "��ѡ����ҵķ�ʽ��" << endl;
	cout << "1����ְ����Ų���" << endl;
	cout << "2������������" << endl;
	cin >> opt;
	if (opt == 1)
	{
		cout << "��������ҵ�ְ����ţ�" << endl;
		cin >> id;
		for(i = 0;i<this->n;i++)
			if (this->perArray[i]->id == id)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->perArray[i]->sayWork();
				system("pause");
				system("cls");
				return;
			}
		if (i == this->n)
		{
			cout << "�޴�Ա����ţ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	if (opt == 2)
	{
		cout << "��������ҵ�������" << endl;
		cin >> name;
		for (i = 0; i < this->n; i++)
			if (this->perArray[i]->name == name)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->perArray[i]->sayWork();
				system("pause");
				system("cls");
				return;
			}
		if (i == this->n)
		{
			cout << "�޴�Ա��������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}
}

void WorkerManager::sortArray()
{
	if (this->txtIsnull)
	{
		cout << "ְ������Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	int max_id, j, opt;
	workers* wk = NULL;
	cout << "��ѡ���������ͣ�" << endl;
	cout << "1����ְ���������" << endl;
	cout << "2����ְ����Ž���" << endl;
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
		cout << "����ɹ���������Ϊ��" << endl;
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
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	cin >> opt;
	if (opt == 2)
	{
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs;
	//��ģʽ ios::trunc �������ɾ���ļ������´���

	ofs.open("test.txt", ios::trunc);
	ofs.close();

	if (this->perArray != NULL)
	{
		for (int i = 0; i < this->n; i++)
		{

			//ɾ��������ÿ��ְ������
			if (this->perArray[i] != NULL)
				delete this->perArray[i];
		}

		//ɾ����������ָ��
		this->n = 0;
		delete[] this->perArray;
		this->perArray = NULL;
		this->txtIsnull = true;
		cout << "��ճɹ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
	return;
}
WorkerManager::~WorkerManager(){}