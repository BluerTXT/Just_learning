// Multifile_example.cpp: определяет точку входа для приложения.
//

#include "Multifile_example.h"

using namespace std;

int multiple (int a, int b) {
	return a * b;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	//Привет мир на трех разных языках :D
	/*
	wcout << L"Hello World!\n";
	wcout << L"こんにちは世界!" << endl;
	wcout << L"Привет Мир!";
	*/

	int number_one;int number_two;

	wcout << L"Привет! Введите два числа:\n";
	wcin >> number_one >> number_two;
	wcout << multiple(number_one, number_two) << L" - произведение двух ваших чисел\n";

	add();

	return 0;
}
