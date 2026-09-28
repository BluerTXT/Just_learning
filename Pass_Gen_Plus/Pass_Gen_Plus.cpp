#include "Pass_Gen_Plus.h"

int rand_int(int from, int to) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(from, to);
	return dist(rng);
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	std::wstring input;
	bool working = true;

	std::wcout << L"Добро пожаловать в систему генерации пароля\nВведите вашу фамилию: ";
	std::getline(std::wcin, input);

	std::wcout << L"Какой длины вам нужен пароль? (Если той же длины введите 0)\n";
	int pass_size;
	std::wcin >> pass_size;

	if (pass_size == 0 or input.length() == pass_size) {
		std::reverse(input.begin(), input.end());
	}
	else if (pass_size < input.length()) {
		input.resize(pass_size);
		std::reverse(input.begin(), input.end());
	}
	else {
		int old_size = input.length();
		for (int i = old_size; i < pass_size; i++) {
			input += input[rand_int(0, old_size - 1)];
		}
		std::reverse(input.begin(), input.end());
	}

	std::system("cls");
	std::wcout << L"Ваш пароль: " << input << std::endl;
	std::wcout << L"\nНажмите любую кнопку чтобы закрыть окно...";
	int key = _getch();
	std::system("cls");

	return 0;
}
