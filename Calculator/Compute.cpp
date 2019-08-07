#include"Calculator.h"
#include"Matrix.h"
#include"HugeInt.h"
#include<string>
#include"Complex.h"


void printRequest();	//�������ѡ��
void matrixCompute();	//��װ�������ĺ���
void hugeIntCompute();	//��װ��������ĺ���
void complexCompute();	//��װ��������ĺ���	
void pictureDraw();		//��װͼ����Ƶĺ���

void Calculator::compute()
{//������װ����ĺ���
	printRequest();
	int choice;
	while (cin>>choice)
	{
		switch (choice)
		{
		case 1:
			matrixCompute();
			break;

		case 2:
			hugeIntCompute();
			break;

		case 3:
			complexCompute();
			break;

		case 4:
			pictureDraw();
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
	cout << "***** 3. ComplexCompute      4. PictureDraw    *****" << endl;
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
		cout << "�����������������" << endl;
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
		cout << "�����������������" << endl;
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
		cout << "�����������������" << endl;
		int r, c;
		cin >> r >> c;
		Matrix A = Matrix(r, c);
		A.setMember();
		cout << "����������ʵ����" << endl;
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
		cout << "���������1����������" << endl;
		int r1, c1;
		cin >> r1 >> c1;
		Matrix A = Matrix(r1, c1);
		A.setMember();
		cout << "���������2����������" << endl;
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

void hugeIntCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. HugeNumberAdd    2. HugeNumberSubstract *****" << endl;
	//cout << "*****           3. HugeNumberProduct             *****" << endl;
	cout << "******************************************************" << endl;
	//detect what to do
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:		//1. HugeNumberAdd
	{
		string val1, val2;
		cout << "������һ�����ݣ� ";
		cin >> val1;
		cout << "��������һ�����ݣ� ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 + num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 2:		//2. HugeNumberSubstract
	{
		string val1, val2;
		cout << "������һ�����ݣ� ";
		cin >> val1;
		cout << "��������һ�����ݣ�Ҫʹ���ȵ�һ������С�� ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 - num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 3:		// 3. HugeNumberProduct 
	{
		string val1, val2;
		cout << "������һ�����ݣ� ";
		cin >> val1;
		cout << "��������һ�����ݣ� ";
		cin >> val2;

		HugeInt num1 = HugeInt(val1);
		HugeInt num2 = HugeInt(val2);

		HugeInt result = HugeInt();
		result = num1 * num2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	default:
		break;
	}
}

void complexCompute()
{
	cout << "******************************************************" << endl;
	cout << "****** Please choose which computation you want ******" << endl;
	cout << "***** 1. ComplexAdd          2. ComplexSubstract *****" << endl;
	cout << "***** 3. ComplexProduct      4. ComplexDivide    *****" << endl;
	cout << "*****               5. ComplexModel              *****" << endl;
	cout << "******************************************************" << endl;
	//detect what to do
	int manipulate;
	cin >> manipulate;
	switch (manipulate)
	{
	case 1:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "�������һ��������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "������ڶ���������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 + op2;
		
		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 2:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "�������һ��������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "������ڶ���������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 - op2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 3:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "�������һ��������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "������ڶ���������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 * op2;

		cout << "The answer is: ";
		cout << result << endl;

	}
	break;

	case 4:
	{
		Complex op1;
		Complex op2;
		double a, b;
		cout << "�������һ��������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op1 = Complex(a, b);

		cout << "������ڶ���������ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op2 = Complex(a, b);

		Complex result;
		result = op1 / op2;

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	case 5:
	{
		Complex op1;
		double a, b;
		cout << "�����븴����ʵ�����鲿���м��ÿո������ ";
		cin >> a >> b;
		op1 = Complex(a, b);


		double result;
		result = op1.model();

		cout << "The answer is: ";
		cout << result << endl;
	}
	break;

	default:
		break;
	}

}

void pictureDraw()
{
	cout << "******************************************************" << endl;
	cout << "**** Please choose which picture you want to draw ****" << endl;
	cout << "***** 1.ָ������:y=a^x��a>0��a!=1��              *****" << endl;
	cout << "***** 2.�ݺ���:y=x^(m/n*(-1)^k),(y=x^a)          *****" << endl;
	cout << "***** 3.��������:y=loga (x)                      *****" << endl;
	cout << "***** 4.���Ǻ���                                 *****" << endl;
	cout << "***** 5.�����Ǻ���                               *****" << endl;
	cout << "***** 6.��������:y=c                             *****" << endl;
	cout << "******************************************************" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{

	}
	break;

	case 2:
	{

	}
	break;

	case 3:
	{

	}
	break;

	case 4:
	{

	}
	break;

	case 5:
	{

	}
	break;

	case 6:
	{

	}
	break;

	default:
		break;
	}
}