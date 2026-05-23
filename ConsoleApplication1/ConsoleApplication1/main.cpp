#include <stdio.h>
#include "input.h"
#include "judge.h"

int main()
{
    int answer, number, check;
    bool clear = false;

    answer = setAnswer();

    while (true)
    {
        number = inputNumber();
        check = compare(answer, number);
        judge(check, clear);
        if (clear)break;
    }

    return 0;
}
