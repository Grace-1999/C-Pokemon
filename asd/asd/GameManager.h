#pragma once
#include "Basic.h"
#include "Map.h"
#include "Battle.h"
#include "Random.h"
#include "Player.h"

class Loop
{
public:
	Battle battle;
	InitMap map;
	Random ran;

	void Move(Player &player, char L)
	{
		
		pair<int, int> newPosition = player.Location;
		bool moved = false;
		bool justbattled = false;

		if (L == 'w')
			newPosition.first--;
		else if (L == 's')
			newPosition.first++;
		else if (L == 'a')
			newPosition.second--;
		else if (L == 'd')
			newPosition.second++;
		else if (L == '1')
		{
			player.GetPokemon();
			moved = false;
            map.ClearScreen();
			return;
		}
		else if (L == '2')
		{
			player.GetItem();
			moved = false;
            map.ClearScreen();
			return;
		}
		else if (L == '3')
		{
			cout << endl << "포켓몬을 종료합니다." << endl;
			exit(0);
		}

		// 맵 데이터 가져오기
		vector<vector<char>> currentMap = map.GetOriginalMap();

		// 새 위치가 맵 범위 내에 있는지 확인
		if (newPosition.first >= 0 && newPosition.first < currentMap.size() &&
			newPosition.second >= 0 && newPosition.second < currentMap[0].size())
		{
			// 새 위치의 타일 값 확인
			char tileValue = currentMap[newPosition.first][newPosition.second];

			// 벽('1')이 아니면 이동 가능
			if (tileValue != '1' && tileValue != 'W' && tileValue != 'R' && tileValue != 'P')
			{
				player.Location = newPosition;
				moved = true;
				justbattled = false;
			}


		}

		MeetPokemon(moved, justbattled, player);
	}


	void MeetPokemon(bool moved, bool justbattled, Player& player)
	{
		if (moved && !justbattled)
		{
			vector<vector<char>> TempMap = map.GetOriginalMap();
			char currentTile = TempMap[player.Location.first][player.Location.second];

			if (currentTile == '5') // 풀숲
			{
				if (ran.MaxRand(1, 100) <= 5) 
				{
					system("cls");
					map.When_Battle();
                    system("cls");
					SpawnGrasslandPokemon(player);
					battle.Battle_Start(player);
					ClearBuffer();
					system("cls");
					justbattled = true;
				}
			}
			else if (currentTile == 'B' || currentTile == 'G' || currentTile == 'I' || currentTile == 'U') // 다리
			{
				if (ran.MaxRand(1, 100) <= 5)
				{
					system("cls");
					map.When_Battle();
                    system("cls");
					SpawnWaterPokemon(player);
					battle.Battle_Start(player);
					ClearBuffer();
					system("cls");
					justbattled = true;
				}
			}
            else if (currentTile == 'M') // 산악
            {
                if (ran.MaxRand(1, 100) <= 5)
                {
                    system("cls");
                    system("cls");
                    map.When_Battle();
                    system("cls");
                    SpawnMountainPokemon(player);
                    battle.Battle_Start(player);
                    ClearBuffer();
                    system("cls");
                    justbattled = true;
                }
            }
		}
	}


    // 풀 지역에 나오는 포켓몬
    void SpawnGrasslandPokemon(Player& player)
    {
        // 망나뇽이 등장할 확률 체크 (5% 확률)
        if (ran.MaxRand(1, 100) <= 5)
        {
            system("cls");
            battle.wildPokemon = new Dragonite(ran.MaxRand(12, 18));
            battle.wildPokemon->WildShowText();
            cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            return;
        }

        // 일반 풀 포켓몬 등장 로직
        int pokemonChoice = ran.MaxRand(1, 5);

        switch (pokemonChoice)
        {
        case 1:
            battle.wildPokemon = new Pikachu(ran.MaxRand(5, 10));
            break;
        case 2:
            battle.wildPokemon = new Eevee(ran.MaxRand(4, 9));
            break;
        case 3:
            battle.wildPokemon = new Bulbasaur(ran.MaxRand(4, 8));
            break;
        case 4:
            battle.wildPokemon = new Butterfree(ran.MaxRand(6, 12));
            break;
        case 5:
            battle.wildPokemon = new Pidgeotto(ran.MaxRand(7, 14));
            break;
        }

        system("cls");
        battle.wildPokemon->WildShowText();
        cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        ClearBuffer();
    }

    // 물가에 나오는 포켓몬
    void SpawnWaterPokemon(Player& player)
    {
        // 망나뇽이 등장할 확률 체크 (5% 확률)
        if (ran.MaxRand(1, 100) <= 5)
        {
            system("cls");
            battle.wildPokemon = new Dragonite(ran.MaxRand(12, 18));
            battle.wildPokemon->WildShowText();
            cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            return;
        }

        // 일반 물가 포켓몬 등장 로직
        int pokemonChoice = ran.MaxRand(1, 3);

        switch (pokemonChoice)
        {
        case 1:
            battle.wildPokemon = new Squirtle(ran.MaxRand(6, 12));
            break;
        case 2:
            battle.wildPokemon = new Lapras(ran.MaxRand(8, 15));
            break;
        case 3:
            battle.wildPokemon = new Arbok(ran.MaxRand(10, 18));
            break;
        }

        system("cls");
        battle.wildPokemon->WildShowText();
        cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        ClearBuffer();
    }

    // 산에 나오는 포켓몬
    void SpawnMountainPokemon(Player& player)
    {
        // 뮤가 등장할 확률 체크 (1% 확률)
        if (ran.MaxRand(1, 100) <= 1)
        {
            system("cls");
            battle.wildPokemon = new Mew(ran.MaxRand(15, 20));
            battle.wildPokemon->WildShowText();
            cout << "===============이런! 전설의 포켓몬 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            return;
        }

        // 메타그로스가 등장할 확률 체크 (3% 확률)
        if (ran.MaxRand(1, 100) <= 3)
        {
            system("cls");
            battle.wildPokemon = new Metagross(ran.MaxRand(14, 19));
            battle.wildPokemon->WildShowText();
            cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            return;
        }

        // 팬텀이 등장할 확률 체크 (5% 확률)
        if (ran.MaxRand(1, 100) <= 5)
        {
            system("cls");
            battle.wildPokemon = new Gengar(ran.MaxRand(10, 16));
            battle.wildPokemon->WildShowText();
            cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            ClearBuffer();
            return;
        }

        // 일반 산 포켓몬 등장 로직
        int pokemonChoice = ran.MaxRand(1, 4);

        switch (pokemonChoice)
        {
        case 1:
            battle.wildPokemon = new Onix(ran.MaxRand(8, 16));
            break;
        case 2:
            battle.wildPokemon = new Dugtrio(ran.MaxRand(7, 14));
            break;
        case 3:
            battle.wildPokemon = new Charmander(ran.MaxRand(5, 10));
            break;
        case 4:
            battle.wildPokemon = new Lucario(ran.MaxRand(10, 18));
            break;
        }

        system("cls");
        battle.wildPokemon->WildShowText();
        cout << "===============앗! 야생의 " << battle.wildPokemon->Pokemon_Name << "(이)가 나타났다!===============" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "가랏! " << player.GetPokemonAtIndex(0)->Pokemon_Name << "!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        ClearBuffer();
    }
	
	void Update(Player& player)
	{
		map.SetConsoleSize(2000, 2000);
		player.SetItem("MonsterBall");
		player.SetPokemon("뮤", 20);
        player.SetPokemon("피카츄", 20);
		player.SetItem("MasterBall");
		system("cls");
		map.Init(player.Location);


		while (true)
		{

			char L = (char)_getch();
			Move(player, L);
            map.ClearScreen();

			map.Init(player.Location);
		}
	}
};

