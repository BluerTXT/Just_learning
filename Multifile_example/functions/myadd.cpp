#include "../Multifile_example.h"

int add () {

	int a; int b;

	std::wcout << L"Введите два числа:\n";

	std::wcin >> a >> b;

	std::wcout << a + b << L" - сумма двух ваших чисел";

	return 0;
}