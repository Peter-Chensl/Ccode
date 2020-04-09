#include <stdio.h>
#include <math.h>
#include <windows.h>
#pragma warning(disable:4996)

double FractionSum()
{
	double sum = 0.0;
	double num = 1;
	for (; num <= 100; num++)
	{
		double n = pow(1.0, (num - 1.0));
		sum += n * (1.0/num);
	}
	return sum;

}

int main()
{
	printf("½á¹ûÎª£º%lf", FractionSum());
	system("pause");
	return  0;
}

