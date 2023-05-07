#pragma once
#include<iostream>
using namespace std;

class workers
{
public:
	virtual string saypost() = 0; //说岗位

	virtual void sayWork() = 0; //说工作

	int id;
	string name;
	int did;
};
class person :public workers
{
public:
	person(int id, string name, int did);
	string saypost();
	void sayWork();
};
class manager :public workers
{
public:
	manager(int id, string name, int did);
	string saypost();
	void sayWork();
};
class boss :public workers
{
public:
	boss(int id, string name, int did);
	string saypost();
	void sayWork();
};