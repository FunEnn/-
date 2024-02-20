#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<algorithm>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>


//����ݽ�������
class SpeechManager
{
public:

	//���캯��
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();


	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼����
	void saveRecord();
	
	//��ȡ��¼
	void loadRecord();

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void claerRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;



	//��������¼������
	map<int, vector<string>>m_Record;

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;

	//��������
	~SpeechManager();
};