#ifndef INTERFACE_DEFINE_AND_REALIZE
#define INTERFACE_DEFINE_AND_REALIZE
#include <string>
using std::string;
//define interface
class Person
{
public:
	Person():m_StrName("###") //成员列表初始化参数
	{};
	virtual ~Person(){};
	virtual void Eat()=0;//人需要吃东西
	virtual void Sleep()=0;//人需要睡觉
	virtual void SetName(const string strName)=0;//人都有名字
	virtual string GetName()=0;//获取名字
	virtual void Work()=0;//人可能要有工作
private:
	string m_StrName;
};
//实现接口
//实现接口是通过派生类实现的，每个派生类依据自身特点，可以获取同一接口的不同实现
//也就是所谓的多态
class Student:public Person
{
public:
	Student():m_strName("***")
	{};
	~Student()
	{};
	void Eat();
	void Sleep();
	void SetName(const string strName);
	string GetName();
	void Work();
private:
	string m_strName;
};
#endif