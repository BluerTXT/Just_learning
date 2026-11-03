// StructTypeMove.cpp: определяет точку входа для приложения.
//

#include "../headers/StructTypeMove.h"

struct student {
	std::wstring name;std::wstring surname;int age;int group;float aveGrade;
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	student s1{L"Артём", L"Юрченко", 19, 4511, 4.2};
	student s3{L"Вова", L"Вовкин", 4586879, 4511, 3.25};

	std::wcout << L"Студент: " << s1.surname << " " << s1.name << L"\nВозраст: " << s1.age << L" лет\nГруппа: " << s1.group << L"\nСредняя оценка: " << s1.aveGrade << L"\n\nВведите данные своего студента.\nВведите имя: ";
	student s2;
	std::wcin >> s2.name;
	std::system("cls");

	std::wcout << L"Введите фамилию студента: ";
	std::wcin >> s2.surname;
	std::system("cls");

	std::wcout << L"Введите сколько полных лет студенту: ";
	std::wcin >> s2.age;
	std::system("cls");

	std::wcout << L"Введите номер группы студента: ";
	std::wcin >> s2.group;
	std::system("cls");

	std::wcout << L"Введите средний балл студента (пример ввода: \"3.5\"): ";
	std::wcin >> s2.aveGrade;
	std::system("cls");

	std::wcout << L"Первый студент:\nИмя и фамилия студента: " << s1.surname << " " << s1.name << L"\nВозраст: " << s1.age << L" лет\nГруппа: " << s1.group << L"\nСредняя оценка: " << s1.aveGrade << L"\n\n";
	std::wcout << L"Второй студент:\nИмя и фамилия студента: " << s2.surname << " " << s2.name << L"\nВозраст: " << s2.age << L" лет\nГруппа: " << s2.group << L"\nСредняя оценка: " << s2.aveGrade << L"\n\n";
	std::wcout << L"Третий студент:\nИмя и фамилия студента: " << s3.surname << " " << s3.name << L"\nВозраст: " << s3.age << L" лет\nГруппа: " << s3.group << L"\nСредняя оценка: " << s3.aveGrade << L"\n\n";

	int SIZE = 3;
	student* group_sts = new student[SIZE];

	group_sts[0] = s1;group_sts[1] = s2;group_sts[2] = s3;

	int maxAveGradeStudentIndex;
	float maxAveGrade = 0;
	for (int i = 0;i < SIZE;i++) {
		if (maxAveGrade < group_sts[i].aveGrade) {
			maxAveGrade = group_sts[i].aveGrade;maxAveGradeStudentIndex = i;
		}
	}

	std::wcout << L"Студент лучший по успеваемости:\nИмя и фамилия студента: " << group_sts[maxAveGradeStudentIndex].surname << " " << group_sts[maxAveGradeStudentIndex].name << L"\nВозраст: " << group_sts[maxAveGradeStudentIndex].age << L" лет\nГруппа: " << group_sts[maxAveGradeStudentIndex].group << L"\nСредняя оценка: " << group_sts[maxAveGradeStudentIndex].aveGrade << L"\n";
	delete[] group_sts;

	return 0;
}
