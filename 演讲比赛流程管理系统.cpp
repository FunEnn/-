#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include<ctime>

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//�������������
	SpeechManager sm;

	//����12��ѡ�ִ���
	//for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ� " << it->first << "������ " << it->second.m_name << "������ " << it->second.m_score[0] << endl;
	//}

	int choice = 0; //�����洢�û�����

	while (true)
	{
		sm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴����������
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.claerRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}