#pragma once
#include "Basic.h"
#include "Pokemon.h"
#include "Random.h"
#include "Map.h"
#include "Player.h"

class Battle
{
private:
	InitMap map;
    bool escaped = false;
    bool captured = false;

    // 상성
    float GetTypeEffectiveness(const string& attackType, const string& defenderType)
    
    {
        float effectiveness = 1.0f; // 기본 배율
        // 노말 타입 공격
        if (attackType == "normal") {
            if (defenderType == "rock") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "ghost") effectiveness = 0.0f;    // 효과가 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 불꽃 타입 공격
        else if (attackType == "fire") {
            if (defenderType == "fire") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "water") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "grass") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "ice") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "bug") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "rock") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "dragon") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 1.5f;    // 효과는 뛰어남
        }
        // 물 타입 공격
        else if (attackType == "water") {
            if (defenderType == "fire") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "water") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "grass") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "rock") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "dragon") effectiveness = 0.5f;   // 효과가 별로 없음
        }
        // 풀 타입 공격
        else if (attackType == "grass") {
            if (defenderType == "fire") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "water") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "grass") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "poison") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "flying") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "bug") effectiveness = 0.5f;      // 효과가 별로 없음
            if (defenderType == "rock") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "dragon") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 전기 타입 공격
        else if (attackType == "electric") {
            if (defenderType == "water") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "grass") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "electric") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 0.0f;   // 효과가 없음
            if (defenderType == "flying") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "dragon") effectiveness = 0.5f;   // 효과가 별로 없음
        }
        // 얼음 타입 공격
        else if (attackType == "ice") {
            if (defenderType == "fire") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "water") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "grass") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "ice") effectiveness = 0.5f;      // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "flying") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "dragon") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 격투 타입 공격
        else if (attackType == "fighting") {
            if (defenderType == "normal") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "ice") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "poison") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "flying") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "psychic") effectiveness = 0.5f;  // 효과가 별로 없음
            if (defenderType == "bug") effectiveness = 0.5f;      // 효과가 별로 없음
            if (defenderType == "rock") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "ghost") effectiveness = 0.0f;    // 효과가 없음
            if (defenderType == "dark") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 1.5f;    // 효과는 뛰어남
        }
        // 독 타입 공격
        else if (attackType == "poison") {
            if (defenderType == "grass") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "poison") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "rock") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "ghost") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 0.0f;    // 효과가 없음
        }
        // 땅 타입 공격
        else if (attackType == "ground") {
            if (defenderType == "fire") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "electric") effectiveness = 1.5f; // 효과는 뛰어남
            if (defenderType == "grass") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "poison") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "flying") effectiveness = 0.0f;   // 효과가 없음
            if (defenderType == "bug") effectiveness = 0.5f;      // 효과가 별로 없음
            if (defenderType == "rock") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 1.5f;    // 효과는 뛰어남
        }
        // 비행 타입 공격
        else if (attackType == "flying") {
            if (defenderType == "grass") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "electric") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "fighting") effectiveness = 1.5f; // 효과는 뛰어남
            if (defenderType == "bug") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "rock") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 에스퍼 타입 공격
        else if (attackType == "psychic") {
            if (defenderType == "fighting") effectiveness = 1.5f; // 효과는 뛰어남
            if (defenderType == "poison") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "psychic") effectiveness = 0.5f;  // 효과가 별로 없음
            if (defenderType == "dark") effectiveness = 0.0f;     // 효과가 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 벌레 타입 공격
        else if (attackType == "bug") {
            if (defenderType == "fire") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "grass") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "fighting") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "poison") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "flying") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "psychic") effectiveness = 1.5f;  // 효과는 뛰어남
            if (defenderType == "ghost") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "dark") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 바위 타입 공격
        else if (attackType == "rock") {
            if (defenderType == "fire") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "ice") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "fighting") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "ground") effectiveness = 0.5f;   // 효과가 별로 없음
            if (defenderType == "flying") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "bug") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 고스트 타입 공격
        else if (attackType == "ghost") {
            if (defenderType == "normal") effectiveness = 0.0f;   // 효과가 없음
            if (defenderType == "psychic") effectiveness = 1.5f;  // 효과는 뛰어남
            if (defenderType == "ghost") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "dark") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 드래곤 타입 공격
        else if (attackType == "dragon") {
            if (defenderType == "dragon") effectiveness = 1.5f;   // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 악 타입 공격
        else if (attackType == "dark") {
            if (defenderType == "fighting") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "psychic") effectiveness = 1.5f;  // 효과는 뛰어남
            if (defenderType == "ghost") effectiveness = 1.5f;    // 효과는 뛰어남
            if (defenderType == "dark") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }
        // 강철 타입 공격
        else if (attackType == "steel") {
            if (defenderType == "fire") effectiveness = 0.5f;     // 효과가 별로 없음
            if (defenderType == "water") effectiveness = 0.5f;    // 효과가 별로 없음
            if (defenderType == "electric") effectiveness = 0.5f; // 효과가 별로 없음
            if (defenderType == "ice") effectiveness = 1.5f;      // 효과는 뛰어남
            if (defenderType == "rock") effectiveness = 1.5f;     // 효과는 뛰어남
            if (defenderType == "steel") effectiveness = 0.5f;    // 효과가 별로 없음
        }

        return effectiveness;
    }

    // 데미지 계산 공식
    pair<int, float> CalculateDamage(Pokemon* attacker, Pokemon* defender, Skill& skill)
    {
        // 기본 데미지
        float baseDamage = skill.GetPower() * (attacker->Atk / (float)defender->Def);

        // 레벨 보정
        float levelModifier = (1.5f * attacker->Pokemon_Level / 5.0f + 2.0f) / 50.0f;

        // 타입 상성 (1.0은 보통, 2.0은 효과적, 0.5는 효과가 별로없음)
        float typeEffectiveness = GetTypeEffectiveness(skill.GetType(), defender->Type);

        // 무작위 변동 (85%~100%)
        float randomFactor = 0.85f + ran.Rand(0, 15) / 100.0f;

        // 최종 데미지 계산
        int damage = static_cast<int>(baseDamage * levelModifier * typeEffectiveness * randomFactor);

        // 최소 1 데미지 보장
        return make_pair(max(1, damage), typeEffectiveness);
    }

public:
    ~Battle()
    {
        if (wildPokemon != nullptr)
        {
            delete wildPokemon;
            wildPokemon = nullptr;
        }
    }

    Pokemon* wildPokemon;
    Random ran;
	void Battle_Start(Player& player)
	{
        map.ClearScreen();
		Pokemon* playerPokemon = player.GetPokemonAtIndex(0);
        captured = false;
        escaped = false;

        while (true)
        {
            if (captured || wildPokemon->CurrentHp <= 0 || playerPokemon->CurrentHp <= 0)
                break;

            system("cls");
            DisplayBattleScreen(playerPokemon);
            PlayerTurn(playerPokemon, player);

            if (captured)
            {
                break;
            }
            else if (wildPokemon->CurrentHp <= 0)
            {
                if (!escaped)
                {
                    cout << "야생 " << wildPokemon->Pokemon_Name << "이(가) 쓰러졌다!" << endl;
                    cout << "승리했다!" << endl;
                }
                break;
            }

            WildPokeTurn(playerPokemon);
            if (playerPokemon->CurrentHp <= 0) {
                cout << "패배했다..." << endl;
                break;
            }
        }
        if (wildPokemon != nullptr && !player.IsCaptured(wildPokemon))
        {
            delete wildPokemon;
            wildPokemon = nullptr;
        }

        if (playerPokemon->CurrentHp <= 0)
        {
            player.ReorderAfterBattle();
        }
        this_thread::sleep_for(chrono::milliseconds(3000));
        map.ClearScreen();
	}

	void DisplayBattleScreen(Pokemon* playerPokemon, bool clearScreen = false)
	{
        map.ClearScreen();
        system("cls");

        if (clearScreen)
            map.ClearScreen();
        else
            map.SetCursorPosition(0, 0);
		// 야생 
		wildPokemon->WildShowText();
		cout << "야생 " << wildPokemon->Pokemon_Name << " Lv." << wildPokemon->Pokemon_Level << endl;
		DisplayHealthBar(wildPokemon->CurrentHp, wildPokemon->MaxHp, wildPokemon);

		cout << "\n\n";

		// 플레이어
		playerPokemon->PlayerShowText();
		cout << playerPokemon->Pokemon_Name << " Lv." << playerPokemon->Pokemon_Level << endl;
		DisplayHealthBar(playerPokemon->CurrentHp, playerPokemon->MaxHp, playerPokemon);

		cout << "\n";
	}

	void DisplayHealthBar(int currentHP, int maxHP, Pokemon* pokemon1)
	{
        vector<pair<int, string>> Bar = { {20, "■"} };
        float ratio = static_cast<float>(currentHP) / maxHP;
        int displayHpbar = static_cast<int>(ratio * Bar[0].first);
        if (currentHP <= 0)
            currentHP = 0;
        cout << "HP: " << currentHP << "/" << maxHP << " ";

        if (ratio > 0.5) cout << "\033[1;32m";
        else if (ratio > 0.2) cout << "\033[1;33m";
        else cout << "\033[1;31m";

        cout << "[";
        for (int i = 0; i < Bar[0].first; i++)
        {
            if (i < displayHpbar)
                cout << Bar[0].second;
            else
                cout << "  ";
        }
        cout << "]";
        cout << "\033[0m" << endl;

	}

	void PlayerTurn(Pokemon* playerPokemon, Player& player)
	{
        bool turnEnded = false;

            while (!turnEnded)
            {
                map.ClearScreen();
                ClearBuffer();
                DisplayBattleScreen(playerPokemon);
                cout << "1. 싸운다 " << endl;
                cout << "2. 도망간다" << endl;
                cout << "3. 가방 " << endl;
                char choice = (char)_getch();

                if (choice == '1')
                {
                    turnEnded =  Fight(playerPokemon);
                }
                else if (choice == '2')
                {
                    Run(playerPokemon);
                    turnEnded = true;
                }
                else if (choice == '3')
                {
                    Bag(player);
                    if (captured)
                        turnEnded = true;
                    else
                        turnEnded = false;
                }
                else
                    DisplayBattleScreen(playerPokemon);
            }

		
	}

    void WildPokeTurn(Pokemon* playerPokemon)
    {
        int choice = ran.MaxRand(0, 3);
            if (choice == 0)
            {
                wild_fight_mechanism(playerPokemon, choice);
            }
            else if (choice == 1)
            {
                wild_fight_mechanism(playerPokemon, choice);
            }
            else if (choice == 2)
            {
                wild_fight_mechanism(playerPokemon, choice);
            }
            else if (choice == 3)
            {
                wild_fight_mechanism(playerPokemon, choice);
            }
        
    }

    void wild_fight_mechanism(Pokemon* playerPokemon, int choice)
    {
        while (true)
        {
            pair<int, float> result = CalculateDamage(wildPokemon, playerPokemon, wildPokemon->GetSkills()[choice]);
            int damage_real = result.first;
            float type_real = result.second;

            ClearBuffer();
            DisplayBattleScreen(playerPokemon);
            cout << "야생 " << wildPokemon->Pokemon_Name << "의 "
                << wildPokemon->GetSkills()[choice].GetName() << "!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            if (ran.Rand(1, 100) > wildPokemon->GetSkills()[choice].GetAccuracy())
            {
                cout << "하지만 빗나갔다!!" << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));
                ClearBuffer();
                break;
            }
            playerPokemon->CurrentHp = playerPokemon->CurrentHp - damage_real;
            DisplayBattleScreen(playerPokemon);

            if (type_real > 1.4f)
            {
                cout << "효과가 굉장했다!" << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
            }
            else if (type_real < 0.6f && type_real > 0.0f)
            {
                cout << "효과가 별로인 듯 하다.." << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
            }
            cout << playerPokemon->Pokemon_Name << "는(은) " << damage_real
                << "의 데미지를 입었다!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            break;
        }
    }
     
    bool Fight(Pokemon* playerPokemon)
    {
        while (true)  // 유효한 스킬을 선택할 때까지 반복
        {
            DisplayBattleScreen(playerPokemon);
            cout << "                                       " << playerPokemon->Pokemon_Name << endl;
            cout << "====================================================================================" << endl;
            playerPokemon->ShowSkills();
            cout << "5. 뒤로가기" << endl;
            cout << "====================================================================================" << endl;

            fflush(stdin);
            char choice = (char)_getch();
            int Nchoice = (choice - '0') - 1;

            if (Nchoice >= 0 && Nchoice <= 3)  // 스킬 선택 (0-3)
            {
                // PP 체크를 여기서 수행
                if (!playerPokemon->GetSkills()[Nchoice].Use())
                {
                    cout << "PP가 다 떨어졌습니다." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    ClearBuffer();
                    continue;  // 스킬 선택 화면으로 돌아감
                }

                // PP가 충분하면 공격 진행
                ClearBuffer();
                DisplayBattleScreen(playerPokemon);
                cout << "\n" << playerPokemon->Pokemon_Name << "의 "
                    << playerPokemon->GetSkills()[Nchoice].GetName() << "!" << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));

                if (ran.Rand(1, 100) > playerPokemon->GetSkills()[Nchoice].GetAccuracy())
                {
                    cout << "하지만 빗나갔다!!" << endl;
                    this_thread::sleep_for(chrono::milliseconds(3000));
                    ClearBuffer();
                    return true;
                }

                pair<int, float> result = CalculateDamage(playerPokemon, wildPokemon, playerPokemon->GetSkills()[Nchoice]);
                int damage_real = result.first;
                float type_real = result.second;

                wildPokemon->CurrentHp = wildPokemon->CurrentHp - damage_real;
                DisplayBattleScreen(playerPokemon);

                if (type_real > 1.4f)
                {
                    cout << "효과가 굉장했다!" << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                }
                else if (type_real == 0.0f)
                {
                    cout << "효과가 없는 것 같다..." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                }
                else if (type_real < 0.6f && type_real > 0.0f)
                {
                    cout << "효과가 별로인 듯 하다.." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                }

                cout << "야생 " << wildPokemon->Pokemon_Name << "에게 " << damage_real
                    << "의 데미지를 입혔다!" << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));
                ClearBuffer();
                return true;
            }
            else if (Nchoice == 4)
            {
                return false;  // 뒤로가기
            }
        }
    }
		
	void Run(Pokemon* playerPokemon)
	{
        int escapeChance = 50 + (playerPokemon->Pokemon_Level - wildPokemon->Pokemon_Level) * 5;
        escapeChance = max(20, min(90, escapeChance));

        if (ran.Rand(1, 100) <= escapeChance)
        {
            cout << endl << "성공적으로 도망쳤다!" << endl;
            escaped = true;
            wildPokemon->CurrentHp = 0;
        }
        else
        {
            cout << "도망칠 수 없었다!" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
	}
 
    void Bag(Player& player)
    {
        int itemIndex = player.SelectItem();
        if (itemIndex >= 0)
        {
            string itemName = player.GetInventoryItemName(itemIndex);
            if (itemName == "MonsterBall" || itemName == "MasterBall")
            {
                // 몬스터볼 사용 로직
                UsePokeBall(player, itemName);

                if (captured)
                    return;
            }
            else
            {
                // 기존 아이템 사용 로직
                player.UseItem(itemIndex);
            }
        }
    }

    void UsePokeBall(Player& player, const string& ballName)
    {
        map.ClearScreen();
        cout << "플레이어는 " << ballName << "을(를) 던졌다!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        bool isMasterBall = (ballName == "MasterBall");
        float catchRate = isMasterBall ? 255.0f : 45.0f; // 마스터볼은 항상 성공, 일반볼은 기본 45
        
        if (!isMasterBall)
        {
            float hpRatio = static_cast<float>(wildPokemon->CurrentHp) / wildPokemon->MaxHp;
            catchRate = catchRate * (1.0f - (0.7f * hpRatio)); 
        }

        float randomValue = ran.Rand(0, 255) / 255.0f;

        map.ShowPokeBallAnimation(ballName);

        if (isMasterBall || randomValue <= (catchRate / 255.0f))
        {
            // 포획 성공
            captured = true;
            cout << "찰칵!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            cout << "신난다!!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            cout << "야생의 " << wildPokemon->Pokemon_Name << "를 잡았다!" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));

            player.SetPokemon(wildPokemon->Pokemon_Name, wildPokemon->Pokemon_Level);
            player.UseItem(player.GetItemIndex(ballName));

            wildPokemon->CurrentHp = 0;
        }
        else
        {
            // 포획 실패
            cout << "하지만 야생 " << wildPokemon->Pokemon_Name << "(이)가 볼에서 나왔다!" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            player.UseItem(player.GetItemIndex(ballName));
        }
    }
};

