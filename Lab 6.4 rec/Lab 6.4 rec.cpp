#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void create(double* a, int n, const int i, const double HIGH, const double LOW);
void print(double* a, int n, const int i);
double Dobutok(double* a, int n, const int i, double& dobutok);
double find_min(double* a, int n, const int i, double& min);
double Suma(double* a, int n, const int i, double& suma, double& min);
void sort_parni(double* a, const int n, const int i);
void sort_neparni(double* a, const int n, const int i);

int main()
{
	srand(time(NULL));


	cout << "F: " << endl;
	int n;
	cout << "n = "; cin >> n;
	double* a = new double[n];
	const double HIGH = 53;
	const double LOW = -17;
	const int i = 0;
	cout << "a[] = { ";
	create(a, n, i, HIGH, LOW);
	print(a, n, i);
	cout << "}" << endl;
	double dobutok = 1;
	cout << "D = " << Dobutok(a, n, i, dobutok) << endl;
	double suma = 0;
	double min = a[0];
	cout << "FM = " << find_min(a, n, i, min) << endl;
	cout << "S = " << Suma(a, n, i, suma, min) << endl;
	cout << "G: " << endl;
	cout << "a[] = { ";
	sort_parni(a, n, i + 1);
	print(a, n, i);
	cout << "}" << endl;
	cout << "J: " << endl;
	sort_neparni(a, n, i);
	cout << "a[] = { ";
	print(a, n, i);
	cout << "}" << endl;
}
void create(double* a, int n, const int i, const double HIGH, const double LOW)
{
	a[i] = LOW + rand() * (HIGH - LOW) / RAND_MAX;
	if (i < n - 1)
		create(a, n, i + 1, HIGH, LOW);
}
void print(double* a, int n, const int i)
{
	cout << a[i] << " ";
	if (i < n - 1)
		print(a, n, i + 1);
}
double Dobutok(double* a, int n, const int i, double& dobutok)
{
	bool umova = false;
	if (a[i] > 0)
	{
		umova = true;
	}
	if (umova)
	{
		dobutok *= a[i];
	}
	if (i < n - 1)
		Dobutok(a, n, i + 1, dobutok);
	else
		return dobutok;
}
double find_min(double* a, int n, const int i, double& min)
{
	if (i < n)
	{
		if (a[i] < min)
			min = a[i];
		find_min(a, n, i + 1, min);
	}
	return min;
}
double Suma(double* a, int n, const int i, double& suma, double& min)
{
	double minimum_element = find_min(a, n, i, min);
	suma += a[i];
	if (a[i] == minimum_element)
		return suma;
	if (i < n - 1)
		Suma(a, n, i + 1, suma, min);

}
void sort_parni(double* a, const int n, const int i)
{
	for (int j = i + 2; j < n; j++)
		if (a[j] < a[i])
		{
			double temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	if (i < n - 1)
		sort_parni(a, n, i + 1);
}
void sort_neparni(double* a, const int n, const int i)
{
	for (int j = i + 1; j < n; j++)
		if (a[j] < a[i])
		{
			double temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	if (i < n - 1)
		sort_neparni(a, n, i + 1);
}