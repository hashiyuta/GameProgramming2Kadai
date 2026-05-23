#include <stdio.h>

// 解答と入力値の比較
int compare(int& answerRef, int& numberRef)
{
    if (answerRef == numberRef)
    {
        return 0;
    }
    else if (answerRef > numberRef)
    {
        return 1;
    }
    else if (answerRef < numberRef)
    {
        return 2;
    }
}

// 結果表示
void disp(int& checkRef, bool& clear)
{
    switch (checkRef)
    {
    case 0:
        printf("ゲームクリア\n");
        clear = true;
        break;
    case 1:
        printf("小さい\n");
        break;
    case 2:
        printf("大きい\n");
        break;
    }
}