#include <iostream>
#include <time.h>
#include <random>
#include "CodeBreaker.h"

int main()
{
	Answer answer;
	Input input;
	Check check;
	Disp disp;

	Check::CheckStruct* pass = nullptr;

	for (int i = 0; i < 4; i++)
	{
		// 乱数生成
		answer.SetNumber(i);
	}

	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			// 入力取得
			input.GetNumber(i);
		}

		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if(a == b) check.CheckNum(&answer.answerNum[a], &input.inputNum[b], true);
				else check.CheckNum(&answer.answerNum[a], &input.inputNum[b], false);

				if (a == 4 && b == 4)
				{
					pass = check.ptr;
				}
			}
		}

		bool clear = disp.DispResult(*pass);
		check.deletePtr();
		if (clear == true) break;
	}

	return 0;
}

// 乱数生成
void Answer::SetNumber(int i)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, 9);

	answerNum[i] = distrib(gen);
}

// 入力取得
void Input::GetNumber(int i)
{
	std::cin >> inputNum[i];
}

// ヒット,ブローの確認
void Check::CheckNum(int* answer, int* input, bool hit)
{
	if (checkStart == false)
	{
		CheckStruct* checkStruct = new CheckStruct;
		ptr = checkStruct;
		checkStart = true;
	}

	if (*answer == *input)
	{
		if (hit == true) ptr->hitCount++;
		else ptr->blowCount++;
	}

	if (ptr->hitCount == 4)
	{
		// クリア判定
		ptr->allHit = true;
	}
}

// メモリ開放
void Check::deletePtr()
{
	delete ptr;
	ptr = nullptr;
}

bool Disp::DispResult(Check::CheckStruct& result)
{
	if (result.allHit == true)
	{
		std::cout << "ゲームクリア" << std::endl;
		return true;
	}
	else
	{
		std::cout << "ヒット | " << result.hitCount << std::endl;
		std::cout << "ブロー | " << result.blowCount << std::endl;
		return false;
	}
}

