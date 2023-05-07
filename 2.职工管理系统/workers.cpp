#include"workers.h"

person::person(int id, string name, int did)
{
		this->id = id;
		this->name = name;
		this->did = did;
}
string person::saypost(){
	return string("员工");
}
void person::sayWork() {
	cout << "职工编号：" << this->id << '\t' << "职工姓名：" << this->name << '\t' << "岗位：" << this->saypost() <<'\t'<< "职责：完成经理分布的任务" << endl;
}

manager::manager(int id, string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
string manager::saypost() {
	return string("经理");
}
void manager::sayWork() {
	cout << "职工编号：" << this->id << '\t' << "职工姓名：" << this->name << '\t' << "岗位：" << this->saypost() << '\t' << "职责：完成老板发放的任务，并分布给员工" << endl;
}

boss::boss(int id, string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
string boss::saypost() {
	return string("老板");;
}
void boss::sayWork() {
	cout << "职工编号：" << this->id << '\t' << "职工姓名：" << this->name << '\t' << "岗位：" << this->saypost() << '\t' << "职责：管理公司所有事务" << endl;
}