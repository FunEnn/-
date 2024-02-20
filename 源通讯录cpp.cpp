#include<iostream>
#include<string>
using namespace std;
const int MAX = 100;
void showMenu() {
	cout << "*******************" << endl;
	cout << "***1、添加联系人***" << endl;
	cout << "***2、显示联系人***" << endl;
	cout << "***3、删除联系人***" << endl;
	cout << "***4、查找联系人***" << endl;
	cout << "***5、修改联系人***" << endl;
	cout << "***6、清空联系人***" << endl;
	cout << "***0、退出通讯录***" << endl;
	cout << "*******************" << endl;
}

//设计联系人结构体
typedef struct Person {
	string Name;
	int Age;
	string Phone;
}person;

//设计通讯录结构体
 struct Addressbooks{
	//通讯录中保存的联系人数组
	person personArrary[MAX];

	//通讯录中当前记录联系人个数
	int size;
};


 void cls()
 {
	 system("pause");
	 system("cls");
	 showMenu();
 }

//1.添加联系人
void addperson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满" << endl;
		return ;
	}
	else {
		//添加具体联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArrary[abs->size].Name = name;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArrary[abs->size].Age = age;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArrary[abs->size].Phone = phone;

		//更新通讯录人数
		abs->size++;
		cout << "添加成功" << endl;
		cls();
	}
}

//2.显示联系人
void showPerson(Addressbooks* abs) 
{
	//判断通讯录中人数是否为0
	//不为0，显示记录的联系人信息
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "联系人" << i + 1 <<" :" << endl;
			cout << "  姓名：" << abs->personArrary[i].Name << endl;
			cout << "  年龄：" << abs->personArrary[i].Age << endl;
			cout << "  电话：" << abs->personArrary[i].Phone << endl;
			cout << '\n';
		}
	}
	cls();
}

int Exist(Addressbooks*abs,string name)
{
	//检测联系人是否存在 存在返回联系人所在数组中的具体位置，不存在返回-1
	for (int i = 0; i < abs->size; i++)
	{
		//找到用户的名字了
		if (abs->personArrary[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}


//3.删除联系人
void exist(Addressbooks* abs)
{
	string name;
	cout << "输入你要删除人的名字" << endl;
	cin >> name;
	int ret = Exist(abs, name);
	if (ret != -1)
	{
		for (int j = ret; j < abs->size; j++) {
			//数据前移
			abs->personArrary[j] = abs->personArrary[j + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
	cout << "没找到对应的联系人" << endl;
	cls();
}


//4.查找联系人
void findperson(Addressbooks* abs)
{
	cout << "输入要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = Exist(abs, name);
	if (ret != -1)
	{
		//找到用户的名字了
			cout << "姓名：" << abs->personArrary[ret].Name << endl;
			cout << "年龄: " << abs->personArrary[ret].Age << endl;
			cout << "电话：" << abs->personArrary[ret].Phone << endl;
	}
	else 
	cout << "查无此人" << endl;
	cls();
}

//5.修改联系人
void modifyperson(Addressbooks* abs)
{
	cout << "输入你要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = Exist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入修改姓名：" << endl;
		cin >> name;
		abs->personArrary[ret].Name = name;

		int age;
		cout << "请输入修改年龄" << endl;
		cin >> age;
		abs->personArrary[ret].Age = age;

		string phone;
		cout << "请输入修改电话" << endl;
		cin >> phone;

		abs->personArrary[ret].Phone = phone;
		cout << "修改成功" << endl;
	}
	else cout << "查无此人" << endl;
	cls();
}

//6.清空通讯录
void claenperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已经清空" << endl;
	cls();
}

int main() {
	int select = 0;
	showMenu();
	Addressbooks abs;
	abs.size = 0;
	while (cin >> select) {
		switch (select)
		{
		case 1: addperson(&abs);
			break;
		case 2: showPerson(&abs);
			break;
		case 3: exist(&abs);
			break;
		case 4:findperson(&abs);
			break;
		case 5:modifyperson(&abs);
			break;
		case 6:claenperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		}
	}
	system("pause");
	return 0;

}