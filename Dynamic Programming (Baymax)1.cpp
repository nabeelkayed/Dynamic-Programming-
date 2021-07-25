// Dynamic Programming (Baymax)1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>  
#include <cmath>
#include <cstring>
#include <time.h>
#include <string>
using namespace std;
int* a;
int* b;
int* c;
string convertToString(char* a, int size) {
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
double f(int i, int j) {
	cout << "(i=";
	cout << i;
	cout << ",";
	cout << "j=";
	cout << j;
	//cout << ",l=";


	double l;
	//l = sqrt(pow(a[i * 2] - b[j * 2], 2) + pow(a[(i * 2) + 1] - b[(j * 2) + 1], 2));
	//cout << l;
	cout << ")";
	cout << "(a[i]=";
	cout << a[i];
	cout << ",b[j+1]=";
	cout << b[j + 1];
	cout << ",a[i+1]=";
	cout << a[i + 1];
	cout << ",b[j + 2]=";
	cout << b[j + 2];
	cout << ")";


	int** t = new int* [j+1];
	for (int i = 0; i < j+1; i++)
		t[i] = new int[i];

	cout << "\n";
	cout << "----------------------------------------------";
	for (int j1 = 0; j1 < j + 1; j1++)
	{
		for (int i1 = 0; i1 < i + 1; i1++)
		{
			l = sqrt(pow(a[i1 * 2] - b[j1 * 2], 2) + pow(a[(i1 * 2) + 1] - b[(j1 * 2) + 1], 2));
			if (i1 == 0 && j1 == 0) {
				t[j1][i1] = l;	
			}
			else if (i1 == 0)
			{
				t[j1][i1] = max(t[j1 - 1][i1], int(ceil(l)));
				
			}
			else if (j1 == 0)
			{
				t[j1][i1] = max(t[j1][i1 - 1], int(ceil(l)));
			
			}
			else
			{
				t[j1][i1] = max(min(min(t[j1 - 1][i1 - 1], t[j1][i1 - 1]), t[j1][i1 - 1]), int(ceil(l)));
				
			}
			cout << t[j1][i1]<<" ";
		}
		cout << " \n";
	}

	return int(t[j][i]);
}

int read(string line, int* a1, int kk) {
	int ll = 0;
	for (int k = 0; k < line.length(); k++) {
		if (line[k] == ',')
			ll++;;
	}
	a1 = new int[ll + 1];
	char* char_array = new char[line.length()];
	for (int k = 0; k < line.length(); k++) {
		char_array[k] = line[k];
	}
	char* p;

	p = strtok_s(NULL, ",", &char_array);
	int i = 0;
	while (p != NULL)
	{
		int p_size = sizeof(p) / sizeof(char);
		string s_a = convertToString(p, p_size);
		a1[i] = stoi(s_a);
		p = strtok_s(NULL, ",", &char_array);
		i++;
	}
	if (kk == 0)
		a = a1;
	else if (kk == 1)
		b = a1;
	else
		c = a1;
	return i;
}

int main()
{
	string my_Points;
	getline(cin, my_Points);
	int i = read(my_Points, a, 0);

	string baymax_Points;
	getline(cin, baymax_Points);
	int i1 = read(baymax_Points, b, 1);

	string strn2;
	getline(cin, strn2);
	int i3 = read(strn2, c, 2);

	double x5 = 0;
	x5 = f((i / 2) - 1, (i1 / 2) - 1);

	cout << int(ceil(x5));

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
