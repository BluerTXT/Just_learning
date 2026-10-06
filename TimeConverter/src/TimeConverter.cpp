#include "./headers/TimeConverter.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	int input_time; int minutes; int seconds;

	std::wcout << L"Введите время в секундах:\n";
	if (!(std::wcin >> input_time)) {
        std::wcout << L"\nОшибка ввода! Пожалуйста, введите целое число.\n";
        return 1;
    }

	convert(input_time, &minutes, &seconds);

	std::wcout << L"\n" << input_time << L" секунд = " << minutes << L" минут и " << seconds << L" секунд\n";

	return 0;
}