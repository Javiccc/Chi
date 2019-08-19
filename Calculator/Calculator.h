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

void printRequest();	//输出需求选择
void matrixCompute();	//封装矩阵计算的函数
void hugeIntCompute();	//封装大数运算的函数
void complexCompute();	//封装复数运算的函数	
void pictureDraw();		//封装图像绘制的函数
void polynomialCompute();		//封装多项式计算的函数
void simpleCompute();		//封装基本函数运算的函数
void simpleFunction();		//封装初等函数运算的函数
void beautifulCompute();	//调用精美可视化界面