#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}

int GetOpenBrecketIndex(char* fname)
{
        for (int i = 0; i < length(); i++) {
            if (s[i] == '(')
                return i;
        }
        return -1;
}

int GetCloseBrecketIndex(char* fname)
{
    ifstream fin(fname);
    string s;
    while (getline(fin, s))
    {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')')
                return i;
        }
        return -1;
    }
}

bool IsBrecketPair(char* fname) 
{
    cout << fname << endl;

    int FirstBrecketIndex = GetOpenBrecketIndex(fname);
    int SecondBrecketIndex = GetCloseBrecketIndex(fname);
    cout << "qqq" << endl;
    cout << FirstBrecketIndex << endl;
    cout << SecondBrecketIndex << endl;
    return FirstBrecketIndex != -1 && SecondBrecketIndex != -1 && SecondBrecketIndex > FirstBrecketIndex;
}

bool ValidateInnerBreckets(char* fname) 
{
    int BracketCounter = 0;
    bool BracketFind = false;
    ifstream fin(fname);
    string s;
    while (getline(fin, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                BracketCounter--;

            if (s[i] == ')')
                BracketCounter++;

            if (BracketCounter == -2)
                BracketFind = true;

            if (BracketCounter == 0 && BracketFind)
                return false;
        }
    }
    return true;
}

char* RemoveBrackets(char* fname)
{
    ifstream fin(fname);
    string s;

    int FirstBrecketIndex = GetOpenBrecketIndex(fname);
    int SecondBrecketIndex = GetCloseBrecketIndex(fname);

    while (getline(fin, s)) {
        if (FirstBrecketIndex == -1 || SecondBrecketIndex == -1) {
            return fname;
        }
        if (SecondBrecketIndex <= FirstBrecketIndex)
            return fname;
    }

    int resultLeng = s.length() - (SecondBrecketIndex - FirstBrecketIndex + 1) + 1;
    char* result = new char[resultLeng];

    for (int i = 0, j = 0; i < s.length(); i++) {
        if (i >= FirstBrecketIndex && i <= SecondBrecketIndex)
            continue;
        result[j] = s[i];
        j++;
    }
    result[resultLeng - 1] = '\0';

    if (IsBrecketPair(result)) {
        cout << "adaw" << endl;
        return RemoveBrackets(result);
    }
    else {
        cout << "adaljksd" << endl;
        return result;
    }
}

int main()
{
	char fname[100];
	cout << "Enter file name 1: "; 
    cin >> fname;
	PrintTXT(fname);

    if (!ValidateInnerBreckets(fname)) {
        cout << "Error: found inner brackets " << endl;
        return -1;
    }

//    char gname[100];
//    cout << "Enter file name 2: ";
//    cin >> gname;
    char* result = RemoveBrackets(fname);
    cout << "Result: " << result << endl;

	PrintTXT(fname);

    delete[] result;
	return 0;
}







