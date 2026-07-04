#pragma once

class Character {
protected:
	struct Parameter {
		const char* _name = {};
		int _hp = {};
		int _attack = {};
	};
	int maxAttack = 10;

public:
	Character();
	int SetAttack();
	void Died();
	void DispHp();

public:
	Parameter* paraPtr = nullptr;
	bool dead = false;
};

class Player : public Character {
public:
	Player();
};

class Goblin : public Character {
public:
	Goblin();
};

class Slime : public Character {
public:
	Slime();
};