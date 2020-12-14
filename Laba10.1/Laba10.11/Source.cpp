#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

int GetThirdComma(char* fname)
{
	ifstream fin(fname);
	string s; 
	while (getline(fin, s)) 
	{ 	
			int SkipCommaCounter = 2;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == ',') {
					if (SkipCommaCounter != 0) {
						SkipCommaCounter--;
						continue;
					}
					return i;
				}
			}
	return -1;
	}
}

int main()
{
	char fname[100];
	cout << "Enter file name: "; cin >> fname;
	PrintTXT(fname);
	cout << "Third comma: " << GetThirdComma(fname) << endl;
	return 0;
}