#include <stdio.h>
#include "input.h"
#include "judge.h"

int main()
{
    int answer, number, check;
    bool clear = false;

    // 乱数生成
    answer = setAnswer();

    while (true)
    {
        // 入力取得
        number = inputNumber();
        // 解答比較
        check = compare(answer, number);
        // 結果表示
        disp(check, clear);
        if (clear)break;
    }

    return 0;
}
