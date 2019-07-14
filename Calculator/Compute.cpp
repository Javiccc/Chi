#include"Calculator.h"
#include"Matrix.h"

void printRequest();	//输出需求选择
void matrixCompute();	//封装矩阵计算的函数


void Calculator::compute()
{//用来封装计算的函数
	printRequest();
	int choice;
	while (cin>>choice)
	{
		switch (choice)
		{
		case 1:
			matrixCompute();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
		printRequest();
	}

}

void printRequest()
{
	cout << "****************************************************" << endl;
	cout << "***** Please choose which computation you want *****" << endl;
	cout << "***** 1. MatrixCompute       2. HugeIntCompute *****" << endl;
	cout << "***** Please choose which computation you want *****" << endl;
	cout << "****************************************************" << endl;
}

void matrixCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. MatrixAdd            2. MatrixSubstract *****" << endl;
	cout << "***** 3. MatrixProductReal    4. MatrixProduct   *****" << endl;
	cout << "******************************************************" << endl;
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		Matrix B = Matrix(r, c);
		B.setMember();
		Matrix C = Matrix(r, c);
		C = A + B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 2:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		Matrix B = Matrix(r, c);
		B.setMember();
		Matrix C = Matrix(r, c);
		C = A - B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 3:
	{
		cout << "请输入矩阵行列数：" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		cout << "请输入所乘实数：" << endl;
		double real;
		cin >> real;
		Matrix C = Matrix(r, c);
		C = A * real;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	case 4:
	{
		cout << "请输入矩阵1的行列数：" << endl;
		int r1, c1;
		cin >> r1 >> c1;
		Matrix A = Matrix(r1, c1);
		A.setMember();
		cout << "请输入矩阵2的行列数：" << endl;
		int r2, c2;
		cin >> r2 >> c2;
		Matrix B = Matrix(r2, c2);
		B.setMember();
		Matrix C = Matrix();
		C = A * B;
		cout << "The Answer is: " << endl;
		C.print();
	}
	break;

	default:
		break;
	}
}