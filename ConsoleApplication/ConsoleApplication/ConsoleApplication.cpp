#include <iostream>
#include <random>
#include "Character.h"

int main()
{
    std::unique_ptr<Player> player = std::make_unique<Player>();
    std::unique_ptr<Goblin> goblin = std::make_unique<Goblin>();
    std::unique_ptr<Slime> slime = std::make_unique<Slime>();

    int attackP, attackG, attackS;

    while (true)
    {
        // 生存確認
        if (player->dead) {
            std::cout << "敗けてしまった..." << std::endl;
            break;
        }

        // 全員のHPを表示
        player->DispHp();
        goblin->DispHp();
        slime->DispHp();

        // 攻撃対象の選択
        attackP = player->SetAttack();
        int target = 0;

        // ゴブリンとスライムの生存、死亡で分岐
        if (goblin->dead == false && slime->dead == false) {
            std::cout << std::endl;
            std::cout << "ターゲットを選択してください" << std::endl;
            std::cout << "ゴブリンに攻撃 " << 0 << std::endl;
            std::cout << "スライムに攻撃 " << 1 << std::endl << std::endl;
            std::cin >> target;
        }
        else if(goblin->dead == true && slime->dead == false) {
            std::cout << "スライムに攻撃 " << 1 << std::endl << std::endl;
            while (true) {
                std::cin >> target;
                if (target == 1) break;
            }
        }
        else if(slime->dead == true && goblin->dead == false){
            std::cout << "ゴブリンに攻撃" << 0 << std::endl << std::endl;
            while (true) {
                std::cin >> target;
                if (target == 0) break;
            }
        }
        else {
            std::cout << std::endl;
            std::cout << "勝利!" << std::endl;
            break;
        }

        switch (target) {
        case 0:
            goblin->paraPtr->_hp -= attackP;
            goblin->Died();
            break;
        case 1:
            slime->paraPtr->_hp -= attackP;
            break;
        default:
            std::cout << 0 << " か " << 1 << "を入力してください" << std::endl;
            continue;
        }

        std::cout << std::endl << "プレイヤーの攻撃" << std::endl;
        std::cout << attackP << "ダメージ" << std::endl << std::endl;

        goblin->DispHp();
        slime->DispHp();

        attackG = goblin->SetAttack();
        std::cout << std::endl <<  "ゴブリンの攻撃" << std::endl;
        std::cout << attackG << "ダメージ" << std::endl << std::endl;
        player->paraPtr->_hp -= attackG;

        player->DispHp();

        attackS = slime->SetAttack();
        std::cout << std::endl << "スライムの攻撃" << std::endl;
        std::cout << attackS << "ダメージ" << std::endl << std::endl;
        player->paraPtr->_hp -= attackS;

        player->Died();
        goblin->Died();
        slime->Died();
    }

    return 0;
}