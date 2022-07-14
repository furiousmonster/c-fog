#include "InterfaceDefineAndRealize.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
 
//接口的外部实现
void Student::Sleep()
{
	cout<<"student sleep."<<endl;
}
void Student::Eat()
{
	cout<<"student eat."<<endl;
}
void Student::SetName(const string strName)
{
	m_strName=strName;
}
void Student::Work()
{
	cout<<"student work."<<endl;
}
string Student::GetName()
{
	return m_strName;
}
//需要导出的函数，即用户在外部可以调用的接口
_declspec(dllexport)bool GetPersonObject(void** _RtObject)
{
	Person* pMan=NULL;
	pMan=new Student();
	*_RtObject=(void*)pMan;
	return true;
}