#include <iostream>
#include <random>
#include "Character.h"

// コンストラクタで名前とHPの初期化
Character::Character() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(50, 100);

	Parameter* parameter = new Parameter;
	parameter->_hp = dist(mt);
	paraPtr = parameter;
}

Player::Player() {
	paraPtr->_name = "プレイヤー";
	maxAttack = 20;
}

Goblin::Goblin() {
	paraPtr->_name = "ゴブリン";
}

Slime::Slime() {
	paraPtr->_name = "スライム";
}



// 攻撃処理
int Character::SetAttack() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, maxAttack);
	paraPtr->_attack = dist(mt);
	return paraPtr->_attack;
}



// 死亡処理
void Character::Died() {
	if (dead == true) return;
	if (paraPtr->_hp <= 0) dead = true;
}



// HP表示
void Character::DispHp()
{
	if (paraPtr->_hp <= 0) paraPtr->_hp = 0;
	std::cout << paraPtr->_name << "のHP | " << paraPtr->_hp << std::endl;
}