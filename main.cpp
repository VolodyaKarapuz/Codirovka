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

void gets_utf8(FILE *in, FILE *out,int A)
{
    char *buf;
	wchar_t tbuf[100];
	char str[50];
	string str2;
    while (!feof(in))
	{
		buf = fgets (str,sizeof(str),in);
		MultiByteToWideChar(1251,0,buf,-1,tbuf,100);
		str2 = WideCharToMultiByte(4110,0,tbuf,-1,buf,100,NULL,NULL); //4110 CP_UTF8
		fprintf(out,"%s",str2);
	}
}

int main(int argc, char *argv[])
{
	FILE *in, *out;

	in = fopen (argv[2],"r+");
	out = fopen (argv[1],"w");

	gets_utf8(in,out,atoi(argv[3]));
	fclose(in);
	fclose(out);
}
