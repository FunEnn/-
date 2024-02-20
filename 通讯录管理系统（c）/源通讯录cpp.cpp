#include<iostream>
#include<string>
using namespace std;
const int MAX = 100;
void showMenu() {
	cout << "*******************" << endl;
	cout << "***1�������ϵ��***" << endl;
	cout << "***2����ʾ��ϵ��***" << endl;
	cout << "***3��ɾ����ϵ��***" << endl;
	cout << "***4��������ϵ��***" << endl;
	cout << "***5���޸���ϵ��***" << endl;
	cout << "***6�������ϵ��***" << endl;
	cout << "***0���˳�ͨѶ¼***" << endl;
	cout << "*******************" << endl;
}

//�����ϵ�˽ṹ��
typedef struct Person {
	string Name;
	int Age;
	string Phone;
}person;

//���ͨѶ¼�ṹ��
 struct Addressbooks{
	//ͨѶ¼�б������ϵ������
	person personArrary[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int size;
};


 void cls()
 {
	 system("pause");
	 system("cls");
	 showMenu();
 }

//1.�����ϵ��
void addperson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return ;
	}
	else {
		//��Ӿ�����ϵ��
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArrary[abs->size].Name = name;

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArrary[abs->size].Age = age;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArrary[abs->size].Phone = phone;

		//����ͨѶ¼����
		abs->size++;
		cout << "��ӳɹ�" << endl;
		cls();
	}
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs) 
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	//��Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "��ϵ��" << i + 1 <<" :" << endl;
			cout << "  ������" << abs->personArrary[i].Name << endl;
			cout << "  ���䣺" << abs->personArrary[i].Age << endl;
			cout << "  �绰��" << abs->personArrary[i].Phone << endl;
			cout << '\n';
		}
	}
	cls();
}

int Exist(Addressbooks*abs,string name)
{
	//�����ϵ���Ƿ���� ���ڷ�����ϵ�����������еľ���λ�ã������ڷ���-1
	for (int i = 0; i < abs->size; i++)
	{
		//�ҵ��û���������
		if (abs->personArrary[i].Name == name)
		{
			return i;
		}
	}
	return -1;
}


//3.ɾ����ϵ��
void exist(Addressbooks* abs)
{
	string name;
	cout << "������Ҫɾ���˵�����" << endl;
	cin >> name;
	int ret = Exist(abs, name);
	if (ret != -1)
	{
		for (int j = ret; j < abs->size; j++) {
			//����ǰ��
			abs->personArrary[j] = abs->personArrary[j + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	cout << "û�ҵ���Ӧ����ϵ��" << endl;
	cls();
}


//4.������ϵ��
void findperson(Addressbooks* abs)
{
	cout << "����Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = Exist(abs, name);
	if (ret != -1)
	{
		//�ҵ��û���������
			cout << "������" << abs->personArrary[ret].Name << endl;
			cout << "����: " << abs->personArrary[ret].Age << endl;
			cout << "�绰��" << abs->personArrary[ret].Phone << endl;
	}
	else 
	cout << "���޴���" << endl;
	cls();
}

//5.�޸���ϵ��
void modifyperson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = Exist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "�������޸�������" << endl;
		cin >> name;
		abs->personArrary[ret].Name = name;

		int age;
		cout << "�������޸�����" << endl;
		cin >> age;
		abs->personArrary[ret].Age = age;

		string phone;
		cout << "�������޸ĵ绰" << endl;
		cin >> phone;

		abs->personArrary[ret].Phone = phone;
		cout << "�޸ĳɹ�" << endl;
	}
	else cout << "���޴���" << endl;
	cls();
}

//6.���ͨѶ¼
void claenperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�Ѿ����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		}
	}
	system("pause");
	return 0;

}