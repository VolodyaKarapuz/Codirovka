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





void foo (mutex& mtx, FILE *in, FILE *out)
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
		MultiByteToWideChar(1251,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(CP_UTF8,0,tbuf,-1,buf,100,NULL,NULL); //4110 CP_UTF8
		
		f1<<str2;
		cout << "POTOK1"<< endl;
	}
	f1.close();

	
}


void bar (mutex& mtx, FILE *in2, FILE *out2)
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
		MultiByteToWideChar(1251,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(CP_UTF8,0,tbuf,-1,buf,100,NULL,NULL); //4110 CP_UTF8
		
		f1<<str2;
		cout << "POTOK2"<< endl;
	}
	f1.close();
	
}

int main(int argc, char *argv[])
{
	FILE *in, *out, *in2, *out2;
	mutex mtx;
	in = fopen ("in.txt","r+");
	in2 = fopen ("in2.txt","r+");
	out = fopen ("out.txt","w");
	out2 = fopen ("out.txt","w");	
	fclose(out);
	
	
	thread t1 (foo, ref(mtx), ref(in), ref(out));
	thread t2 (bar, ref(mtx), ref(in2), ref(out));
	
	t1.join();
	t2.join();

	fclose(in);
	fclose(out);
	fclose(in2);
	fclose(out2);
	
}

