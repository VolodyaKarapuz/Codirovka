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



 
using namespace std;

void gets_utf8(FILE *in, FILE *out)
{
    char *buf;
	wchar_t tbuf[100];
	char str[50];
	string str2;
    while (!feof(in))
	{
		buf = fgets (str,sizeof(str),in);
		MultiByteToWideChar(1251,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(CP_UTF8,0,tbuf,-1,buf,100,NULL,NULL);
		buf = str2;
		fprintf(out,buf);
	}
}

int main(int argc, char *argv[])
{
	FILE *in, *out, *in2, *in3, *in4;
	char str[50], str2[50];
	char *n, *n1;
	int fl=0;
	in = fopen ("in.txt","r+");
	out = fopen ("out.txt","w");

	gets_utf8(in,out);
	fclose(in);
	fclose(out);
}

