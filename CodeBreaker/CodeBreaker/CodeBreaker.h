#pragma once

class Answer
{
public:
	int answerNum[4] = {};

public:
	void SetNumber(int i);
};

class Input
{
public:
	int inputNum[4] = {};

public:
	void GetNumber(int i);
};

class Check
{
public:
	struct CheckStruct
	{
		int hitCount = 0;
		int blowCount = 0;
		bool allHit = false;
	};

public:
	bool checkStart = false;
	CheckStruct* ptr = nullptr;

public:
	void CheckNum(int* answer, int* input, bool hit);
	void deletePtr();
};

class Disp
{
public:
	bool DispResult(Check::CheckStruct& result);
};