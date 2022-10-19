#include <iostream> 
#include <list> 
#include <random> 
# include <string> 
using namespace std;


int random(int k)
{
	int rnd = rand() % k;
	return rnd;
}

void Print_Arr_int(int* arr, int len)
{
	cout <<"\n";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] <<", ";
	}
}

//вывод матрицы на экран 
void Pint_Matr_str(string*** A, int n, int m)
{

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << " {" << A[i][j][0] << "," << A[i][j][1] << "} ";
		}
		cout << "\n";
	}
}

bool proverka(string*** A, int* LS, int* LO, int n, int m)
{
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((LS[i] < LO[j] && stoi(A[i][j][0]) == 1) || (LS[i] > LO[j] && stoi(A[i][j][1]) == 1))
			{
				ok = false;
				cout << "\nМатрица не прошла проверку на Субъекте " << i << " и объекте " << j;
			}
		}
	}
	return ok;
}

string*** filling_MTR(string*** A, int* LS, int* LO, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (LS[i] >= LO[j])
				A[i][j][0] = to_string(1);
			else
				A[i][j][0] = to_string(0);
			if (LS[i] <= LO[j])
				A[i][j][1] = to_string(1);
			else
				A[i][j][1] = to_string(0);
		}
	}
	return A;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	n = 3;
	m = 5;
	//Создаём матрицу длступа 

	string*** A = new string * *[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new string * [m];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			A[i][j] = new string[2];
		}
	//LS[i] – значение уровня допуска субъекта si ; LO[1:m] так что LO[j] – значение уровня секретности объекта oj 
	int* LS = new int[n], * LO = new int[m];


	// массивы случайными числами от 1 до 10 
	for (int i = 0; i < n; i++)
	{
		LS[i] = random(9);
	}
	for (int i = 0; i < m; i++)
	{
		LO[i] = random(9);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int z = 0; z < 2; z++)
			{
				A[i][j][z] = to_string(random(2));
			}
	//Pint_Matr_str(A, n, m);
	//Print_Arr_int(LS, n);
	//Print_Arr_int(LO, m);
//	if (proverka(A, LS, LO, n, m))
		//cout << "\nДанная матрица прошла проверку. Ураааааааа!!!";
	//else
	//	cout << "\nДанная матрица не прошла проверку :(";

	cout << " ";
	


	////--------------------ДЗ------------------------------------------— 
	string*** A1 = new string * *[n]; 
	 A1 = filling_MTR(A, LS, LO, n, m); 
	 Pint_Matr_str(A1, n, m); 
	 if (proverka(A, LS, LO, n, m)) 
	 cout << "\nДанная матрица прошла проверку"; 
	else 
	 cout << "\nДанная матрица не прошла проверку"; 
}
