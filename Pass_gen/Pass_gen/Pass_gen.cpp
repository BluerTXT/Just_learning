#include <iostream>
#include <Windows.h>
#include <string>
#include <io.h>
#include <fcntl.h>

std::wstring last_name = L"";

using namespace std;

wstring Gen_password() {
    wcout << L"Какая твоя фамилия?\n";
    wcin >> last_name;
    
    const int password_size = last_name.length();
    wstring result = L"";
    for (int i = 0; i < password_size; i++) {
        result = last_name[i] + result;
    }
    
    return result;
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);


    wcout << L"Ваш пороль: " << Gen_password();

    return 0;
}
