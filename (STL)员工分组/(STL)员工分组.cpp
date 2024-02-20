#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<map>
using namespace std;


#define cehua 0
#define meishu 1
#define yanfa 2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
//1.
void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999
		//放入容器
		v.push_back(worker);
	}
}

//2.
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (auto& it : v)
	{
		int deptId = rand() % 3;
		m.insert(make_pair(deptId, it));
	}
}
//3.分组显示

void print(multimap<int, Worker>& m,int x)
{

	multimap<int, Worker>::iterator pos = m.find(x);
	int count = m.count(x); //统计人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << "工资: " << pos->second.m_Salary << endl;
	}
	cout << "一共" << count << "人" << endl;
	cout << "___________________________" << endl;
}

void show(multimap<int, Worker>& m)
{
	cout << "策划： " << endl;
	print(m, cehua);
	cout << "美术： " << endl;
	print(m, meishu);
	cout << "研发： " << endl;
	print(m, yanfa);
}

int main()
{
	srand((unsigned int)time(NULL));
	//1.创建
	vector<Worker>vWorker;
	creatWorker(vWorker);
	//2.分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);
	//测试
	show(mWorker);
	system("pause");
	return 0;
}