#include "../headers/StringExample.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	std::wstring name;
	std::wcout << L"Введите ваше ФИО: ";std::getline(std::wcin, name);
	
	std::wcout << L"В вашем ФИО: " << name.length() << L" символов\n"; //С учетом пробелов так как пробелы тоже символы
	std::wcout << L"Вашы инициалы: ";
	bool isSurnameWritten = false;
	for (wchar_t x : name) {
		if (!isSurnameWritten) {
			if (x != L' ') {
				std::wcout << x;
			}
			else {
				std::wcout << L" ";
				isSurnameWritten = true;
			}
		}
		else {
			if (std::iswupper(x)) {
				std::wcout << x;
			}
			else if ( x == L' ') {
				std::wcout << L".";
			}
		}
	}

	wchar_t inpChar;
	std::wcout << L".\nВведите искомый символ в вашем ФИО: ";std::wcin.get(inpChar);

	int count = 0;
	if (name.find(inpChar) != std::wstring::npos) {
		for (wchar_t x : name) {
			if (x == inpChar) {
				count++;
			}
		}
	}
	std::wcout << L"Найдено " << count << L" таких символов в вашем ФИО.";
}