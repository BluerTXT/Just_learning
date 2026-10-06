#include "../headers/TimeConverter.h"

void convert(int time, int* minutes, int* seconds) {
	*minutes = time / 60;*seconds = time % 60;
}