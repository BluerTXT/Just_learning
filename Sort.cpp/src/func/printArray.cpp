#include "../../headers/Sort.h"

void printArray(int arr[], int size) {
	std::wcout << L"[";
	for (int i = 0; i < size; ++i) {
		if (i != (size - 1)) {
			std::wcout << arr[i] << L", ";
		}
		else {
			std::wcout << arr[i] << L"]";
		}
	}
}