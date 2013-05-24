

#include <iostream>
#include <cstdio>
using namespace std;

//数值的整数次方，求base的exponent次方。
//考虑要点：
//    1. 冥为负数时，转换为冥为正数
//    2. 基底为0，冥为负数时的情况（注意：double类型与0比较）
//    3. 用二分法提高计算速度
//
//

bool g_invalidInput = false;
double Power(double base, int exponent);
bool equal(double base1,double base2);
double PowerWithPostiveExponent(double base, unsigned exponent);

int main(int argc, char *argv[])
{	
	double base;
	int exponent;
	while( cin>>base>>exponent )
		printf("%f \n",Power(base,exponent));
	//    cout<<Power(base,exponent);
	return 0;
}


double Power(double base, int exponent)
{
	//处理基底为0同时冥为负数的情况，属于错误输入
	if( equal(base,0) && exponent<0 )
	{
		g_invalidInput = true;
		return 0.0;
	}

	//将负冥指数转换成正冥指数，计算正冥指数的power函数
	unsigned int absExponent = (exponent>0? exponent:-exponent);
	double result = PowerWithPostiveExponent(base,absExponent);

	//负冥指数的结果最后须转换回来
	if(exponent<0)
	{
		result = 1.0/result;
	}
	return result;
}

//判断两double类型数据是否相同
bool equal(double base1, double base2)
{
	if( (base1 - base2 > -0.0000001) &&
				(base1 - base2 < 0.0000001) )
		return true;
	else 
		return false;		
}

//数的正冥次方二分递归求解
double PowerWithPostiveExponent(double base, unsigned exponent)
{
	if( exponent == 0)
		return 1;
	if( exponent == 1)
		return base;
	double result = PowerWithPostiveExponent(base,exponent>>1);
	result *= result;
	if( exponent & 0x1 == 1)
		result *= base;
	return result;
}
