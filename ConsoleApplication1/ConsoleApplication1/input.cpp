#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ‰ğ“š‚Ìİ’è
int setAnswer()
{
    srand((unsigned int)time(NULL));
    int answer = rand() % 10 + 0;

    return answer;
}

// “ü—Í‚Ìæ“¾
int inputNumber()
{
    int number;

    scanf_s("%d", &number);

    return number;
}