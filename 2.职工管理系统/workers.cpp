#include"workers.h"

person::person(int id, string name, int did)
{
		this->id = id;
		this->name = name;
		this->did = did;
}
string person::saypost(){
	return string("Ա��");
}
void person::sayWork() {
	cout << "ְ����ţ�" << this->id << '\t' << "ְ��������" << this->name << '\t' << "��λ��" << this->saypost() <<'\t'<< "ְ����ɾ���ֲ�������" << endl;
}

manager::manager(int id, string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
string manager::saypost() {
	return string("����");
}
void manager::sayWork() {
	cout << "ְ����ţ�" << this->id << '\t' << "ְ��������" << this->name << '\t' << "��λ��" << this->saypost() << '\t' << "ְ������ϰ巢�ŵ����񣬲��ֲ���Ա��" << endl;
}

boss::boss(int id, string name, int did)
{
	this->id = id;
	this->name = name;
	this->did = did;
}
string boss::saypost() {
	return string("�ϰ�");;
}
void boss::sayWork() {
	cout << "ְ����ţ�" << this->id << '\t' << "ְ��������" << this->name << '\t' << "��λ��" << this->saypost() << '\t' << "ְ�𣺹���˾��������" << endl;
}