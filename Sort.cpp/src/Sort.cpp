#include "../headers/Sort.h"



int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	std::wcout << L"Выберете, как вы хотите проверить работу сортировки:\n1. Самостоятельный ввод\n2. Пусть сгенерирует программа\n 0 и все остальное. Выход";
	int inp = 0;
	std::wcin >> inp;

	if (inp == 1 or inp == 2){
		std::system("cls");
		std::wcout << L"Введите размер массива:\n";
		int oldinp = inp;
		std::wcin >> inp;
		const int size = inp;
		int* originalArr = new int[size];
		int* oldArr = new int[size];
		if (oldinp == 1) {
			std::system("cls");
			std::wcout << L"Введите целые числа, которые будут входить в массив заданный вами ранее (" << size << L" раз):\n";

			for (int i = 0; i < size; ++i) {
				std::wcin >> originalArr[i];
				oldArr[i] = originalArr[i];
			}
		}
		else if (oldinp == 2) {
			std::system("cls");
			for (int i = 0; i < size; ++i) {
				originalArr[i] = rand_int(0, 9999);
				oldArr[i] = originalArr[i];
			}
		}

		optimizedBubbleSort(originalArr, size);

		std::system("cls");
		std::wcout << L"Неотсортированный массив: ";
		printArray(oldArr, size);
		std::wcout << L"\nОтсортированный массив: ";
		printArray(originalArr, size);
		delete[] oldArr;
		delete[] originalArr;
	}
	else {
		std::system("cls");
		std::wcout << L"Пока!";
	}
}
