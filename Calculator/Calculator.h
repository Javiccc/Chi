#pragma once
#include<iostream>
using namespace std;
//Using singleton
class Calculator
{
public:
	//Singleton
	static Calculator *getInstance();
	static void destroyInstance();
	void compute();	//to encapsulate compute manipulation

private:
	static Calculator* myInstance;

	Calculator();
	Calculator(const Calculator&);
	Calculator operator=(const Calculator &){ }	//to protect assignment
	~Calculator();
};

void printRequest();	//�������ѡ��
void matrixCompute();	//��װ�������ĺ���
void hugeIntCompute();	//��װ��������ĺ���
void complexCompute();	//��װ��������ĺ���	
void pictureDraw();		//��װͼ����Ƶĺ���
void polynomialCompute();		//��װ����ʽ����ĺ���
void simpleCompute();		//��װ������������ĺ���
void simpleFunction();		//��װ���Ⱥ�������ĺ���
void beautifulCompute();	//���þ������ӻ�����