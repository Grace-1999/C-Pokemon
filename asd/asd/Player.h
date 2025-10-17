#pragma once
#include "Basic.h"
#include "Pokemon.h"
#include "Map.h"

class Player
{
private:
	vector<string> Have_Pokemon;
	vector<Pokemon*> PokemonTeam;
	vector<pair<string, int>> Inventory;
	InitMap map;
	static const int MAX_POKEMON = 6;

public:
	pair<int, int> Location = { 10, 30 };

	bool SetPokemon(string name, int level)
	{
		if (Have_Pokemon.size() >= MAX_POKEMON)
		{
			cout << "포켓몬은 최대 6마리까지만 소유할 수 있습니다!" << endl;
			return false;
		}

		Pokemon* newPokemon = nullptr;

		if (name == "피카츄")
		{
			newPokemon = new Pikachu(level);
		}
		else if (name == "두트리오")
		{
			newPokemon = new Dugtrio(level);
		}
		else if (name == "이상해씨")
		{
			newPokemon = new Bulbasaur(level);
		}
		else if (name == "파이리")
		{
			newPokemon = new Charmander(level);
		}
		else if (name == "꼬부기")
		{
			newPokemon = new Squirtle(level);
		}
		else if (name == "이브이")
		{
			newPokemon = new Eevee(level);
		}
		else if (name == "라프라스")
		{
			newPokemon = new Lapras(level);
		}
		else if (name == "루카리오")
		{
			newPokemon = new Lucario(level);
		}
		else if (name == "아보크")
		{
			newPokemon = new Arbok(level);
		}
		else if (name == "피죤투")
		{
			newPokemon = new Pidgeotto(level);
		}
		else if (name == "뮤")
		{
			newPokemon = new Mew(level);
		}
		else if (name == "버터플")
		{
			newPokemon = new Butterfree(level);
		}
		else if (name == "롱스톤")
		{
			newPokemon = new Onix(level);
		}
		else if (name == "팬텀")
		{
			newPokemon = new Gengar(level);
		}
		else if (name == "망나뇽")
		{
			newPokemon = new Dragonite(level);
		}
		else if (name == "메타그로스")
		{
			newPokemon = new Metagross(level);
		}

		Have_Pokemon.push_back(name);
		PokemonTeam.push_back(newPokemon);
	}

	Pokemon* GetPokemonAtIndex(int index) {
			return PokemonTeam[index];

	}

	void GetPokemon()
	{
		while (true)
		{
			map.ClearScreen();
			cout << endl << "====== 내 포켓몬 ======" << endl;
			for (int i = 0; i < PokemonTeam.size(); i++) {
				cout << i + 1 << ". " << PokemonTeam[i]->Pokemon_Name
					<< " Lv." << PokemonTeam[i]->Pokemon_Level
					<< " HP: " << PokemonTeam[i]->CurrentHp << "/" << PokemonTeam[i]->MaxHp << endl;
			}
			cout << "=======================" << endl;
			cout << "1. 순서 변경" << endl;
			cout << "2. 뒤로 가기" << endl;
			cout << "=======================" << endl;

			char choice = _getch();

			if (choice == '1')
			{
				ChangePokemonOrder();
			}
			else if (choice == '2')
			{
				return;
			}
		}
	}

	void SetItem(string _item)
	{
		for (auto& item : Inventory)
		{
			if (item.first == _item)
			{
				item.second++;
				cout << _item << "을(를) 획득했습니다! (현재 개수: " << item.second << ")" << endl;
				return;
			}
		}

		Inventory.push_back({ _item, 1 });
		cout << _item << "을(를) 획득했습니다! (현재 개수: 1)" << endl;
	}

	void GetItem(bool inBattle = false)
	{
		int count = 0;
		cout << endl << "====== 내 아이템 ======" << endl;
		if (Inventory.empty())
		{
			cout << "아이템이 없습니다." << endl;
		}
		else
		{
			for (auto& item : Inventory)
			{
				count++;
				cout << count << ". "  << item.first << " x" << item.second << endl;
			}
		}

		if (inBattle)
		{
			cout << (Inventory.empty() ? 1 : Inventory.size() + 1) << ". 뒤로 가기" << endl;
		}
		cout << "=======================" << endl;
		if (!inBattle)
		{
			system("pause");
		}
	}

	void UseItem(int item_number)
	{
		string itemName = Inventory[item_number].first;
		Inventory[item_number].second--;

		if (Inventory[item_number].second <= 0)
		{
			Inventory.erase(Inventory.begin() + item_number);
		}
	}

	int SelectItem()
	{
		
			GetItem(true);

			while (true)
			{
				char input = _getch();
				int choice = input - '0';

				if (Inventory.empty())
				{
					if (choice == 1)
					{
						return -1;
					}
				}
				else if (choice > 0 && choice <= Inventory.size())
				{
					return choice - 1;
				}
				else if (choice == Inventory.size() + 1)
				{
					return -1;
				}
			}
		
	
	}

	bool UseSelectedItem()
	{
		int selected = SelectItem();
		if (selected >= 0)
		{
			UseItem(selected);
			return true;
		}
		return false;
	}

	string GetInventoryItemName(int index)
	{
		if (index >= 0 && index < Inventory.size())
		{
			return Inventory[index].first;
		}
		return "";
	}

	int GetItemIndex(const string& itemName)
	{
		for (int i = 0; i < Inventory.size(); i++)
		{
			if (Inventory[i].first == itemName)
			{
				return i;
			}
		}
		return -1;
	}

	bool IsCaptured(Pokemon* pokemon)
	{
		// wildPokemon이 플레이어의 팀에 포함되었는지 확인하는 로직
		for (const auto& name : Have_Pokemon)
		{
			if (name == pokemon->Pokemon_Name)
			{
				return true;
			}
		}
		return false;
	}

	void SwapPokemonOrder(int index1, int index2)
	{
		if (index1 >= 0 && index1 < PokemonTeam.size() &&
			index2 >= 0 && index2 < PokemonTeam.size() &&
			index1 != index2)
		{
			// 포켓몬 객체 교환
			Pokemon* tempPokemon = PokemonTeam[index1];
			PokemonTeam[index1] = PokemonTeam[index2];
			PokemonTeam[index2] = tempPokemon;

			// 포켓몬 이름 목록도 교환
			string tempName = Have_Pokemon[index1];
			Have_Pokemon[index1] = Have_Pokemon[index2];
			Have_Pokemon[index2] = tempName;

			cout << PokemonTeam[index1]->Pokemon_Name << "와(과) "
				<< PokemonTeam[index2]->Pokemon_Name << "의 순서를 바꿨습니다." << endl;
		}
	}

	void ChangePokemonOrder()
	{
		while (true)
		{
			map.ClearScreen();
			cout << endl << "====== 포켓몬 순서 변경 ======" << endl;
			cout << "순서를 변경할 포켓몬을 선택하세요." << endl;

			for (int i = 0; i < PokemonTeam.size(); i++)
			{
				cout << i + 1 << ". " << PokemonTeam[i]->Pokemon_Name
					<< " Lv." << PokemonTeam[i]->Pokemon_Level
					<< " HP: " << PokemonTeam[i]->CurrentHp << "/" << PokemonTeam[i]->MaxHp << endl;
			}

			cout << PokemonTeam.size() + 1 << ". 뒤로 가기" << endl;
			cout << "==============================" << endl;

			char choice1 = _getch();
			int index1 = choice1 - '0' - 1;

			if (index1 == PokemonTeam.size())
			{
				return; // 뒤로 가기
			}

			if (index1 >= 0 && index1 < PokemonTeam.size())
			{
				map.ClearScreen();
				cout << endl << "====== 포켓몬 순서 변경 ======" << endl;
				cout << PokemonTeam[index1]->Pokemon_Name << "와(과) 교체할 포켓몬을 선택하세요." << endl;

				for (int i = 0; i < PokemonTeam.size(); i++)
				{
					if (i != index1) // 이미 선택한 포켓몬은 표시하지 않음
					{
						cout << i + 1 << ". " << PokemonTeam[i]->Pokemon_Name
							<< " Lv." << PokemonTeam[i]->Pokemon_Level
							<< " HP: " << PokemonTeam[i]->CurrentHp << "/" << PokemonTeam[i]->MaxHp << endl;
					}
					else
					{
						cout << i + 1 << ". [선택됨] " << PokemonTeam[i]->Pokemon_Name << endl;
					}
				}

				cout << PokemonTeam.size() + 1 << ". 취소" << endl;
				cout << "==============================" << endl;

				char choice2 = _getch();
				int index2 = choice2 - '0' - 1;

				if (index2 >= 0 && index2 < PokemonTeam.size() && index1 != index2)
				{
					SwapPokemonOrder(index1, index2);
					system("pause");
				}
				else if (index2 == PokemonTeam.size())
				{
					continue; // 취소하고 다시 첫 선택으로
				}
			}
		}
	}

	void ReorderAfterBattle()
	{
		// 체력이 0인 포켓몬을 찾아서 뒤로 보냄
		for (int i = 0; i < PokemonTeam.size(); i++)
		{
			if (PokemonTeam[i]->CurrentHp <= 0)
			{
				// 해당 포켓몬을 맨 뒤로 보냄
				Pokemon* faintedPokemon = PokemonTeam[i];
				string faintedName = Have_Pokemon[i];

				// i 위치의 포켓몬을 제거하고 나머지를 앞으로 당김
				PokemonTeam.erase(PokemonTeam.begin() + i);
				Have_Pokemon.erase(Have_Pokemon.begin() + i);

				// 맨 뒤에 추가
				PokemonTeam.push_back(faintedPokemon);
				Have_Pokemon.push_back(faintedName);

				cout << faintedName << "은(는) 기절했습니다. 포켓몬 순서가 재조정되었습니다." << endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				break; // 한 번에 하나의 포켓몬만 처리 (전투 후에는 보통 한 포켓몬만 체력이 0이 됨)
			}
		}
	}

};