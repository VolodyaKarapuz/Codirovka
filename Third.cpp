#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <mutex>
#include <thread>
#include <unistd.h> 



 
using namespace std;





void foo (FILE *in, FILE *out, int A)
{
	
    char *buf,str2;
	wchar_t tbuf[100];
	char str[50];
	ifstream f;
	ofstream f1;
	f1.open("out.txt", ios_base::app);	
	while (!feof(in))
	{
		buf = fgets (str,sizeof(str),in);
		MultiByteToWideChar(A,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(CP_UTF8,0,tbuf,-1,buf,100,NULL,NULL); //4110 CP_UTF8
		
		f1<<str2;
		cout << "POTOK1"<< endl;
	}
	f1.close();

	
}


void bar (FILE *in2, FILE *out2, int A)
{
	
    char *buf,str2;
	wchar_t tbuf[100];
	char str[50];
	ifstream f;
	ofstream f1;
	f1.open("out2.txt", ios_base::app);	
	while (!feof(in2))
	{
		buf = fgets (str,sizeof(str),in2);
		MultiByteToWideChar(A,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(CP_UTF8,0,tbuf,-1,buf,100,NULL,NULL); //4110 CP_UTF8
		
		f1<<str2;
		cout << "POTOK2"<< endl;
	}
	f1.close();
	
}

int main(int argc, char *argv[])
{
	string a;
	FILE *in, *out, *in2, *out2;
	int A;
	in = fopen (argv[1],"r+");
	in2 = fopen (argv[2],"r+");
	out = fopen (argv[3],"w");
	out2 = fopen (argv[4],"w");	
	fclose(out);
	A = atoi(argv[5]); //in.txt in2.txt out.txt out2.txt 1251
	
	thread t1 (foo, in, out, A);
	thread t2 (bar, in2, out,A);
	
	t1.join();
	t2.join();

	fclose(in);
	fclose(out);
	fclose(in2);
	fclose(out2);
	
}

