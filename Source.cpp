#include<iostream>

using namespace std;

unsigned long long int Factorial(int m);
double Power(double foundation, int exponent);
void Fibonacci(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d, int i);
void Fibonacci(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d);

#define FACTORIAL
#define POWER
#define FIBONACCI
#define delimetr "\n----------------------------------------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef FACTORIAL
	int number;
	cout << "Факториал" << endl;
	cout << "Введите число: "; cin >> number;
	cout << "Факториал: " << Factorial(number) << endl;

#endif // FACTORIAL

	cout << delimetr << endl;

#ifdef POWER
	double foundation;
	int exponent;
	cout << "Возведение числа в степень" << endl;
	cout << "Введите число и степень: "; cin >> foundation >> exponent;
	cout << "Результат возведения в степень равен: " << Power(foundation, exponent) << endl;

#endif // POWER

	cout << delimetr << endl;

#ifdef FIBONACCI
	int d;
	int i=0;
	unsigned long long int a = 0;
	unsigned long long int b = 1;
	unsigned long long int c = a + b;
	cout << "Ряд чисел Фибоначчи до введенного числа" << endl;
	cout << "Введите число: "; cin >> d;
	Fibonacci(a, b, c, d);

	cout << delimetr << endl;

	cout << "Указанное кол-во чисел из ряда Фибоначчи" << endl;
	cout << "Введите кол-во чисел: "; cin >> d;
	Fibonacci(a, b, c, d, i);

#endif // FIBONACCI

}

unsigned long long int Factorial(int m)
{
	if (m == 0 || m==1)return 1;
	return m * Factorial(m - 1);
}

double Power(double foundation, int exponent)
{
	if (exponent == 0) return 1;
	if (exponent > 0) return foundation * Power(foundation, exponent - 1);
	if (exponent < 0) return 1 / foundation * Power(foundation, exponent +1);
	//return exponent > 0 ? foundation * Power(foundation, exponent - 1) : exponent < 0 ? 1 / foundation * Power(foundation, exponent + 1) : 1;
}

void Fibonacci(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d, int i)
{
	if (i < d)      // Не смог придумать ничего лучше, чем взять и разложить цикл for. Я так и не понял как можно решить
	{               // эту задачу без использования цикла
		i++;
		cout << a << "\t";
		c = a + b;
		a = b;
		b = c;
		Fibonacci(a, b, c, d, i);
	}
}

void Fibonacci(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d)
{
	if (a >= d) return;
	cout << a << "\t";
	c = a + b;
	a = b;
	b = c;
	Fibonacci(a, b, c, d);
}

// Предмет: Основы программирования на языке С++
// Преподаватель: Ковтун Олег
// Выполнил: Батодалаев Даши
