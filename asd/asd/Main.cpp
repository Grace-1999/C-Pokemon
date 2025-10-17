#include "Basic.h"
#include "Map.h"
#include "Player.h"
#include "Pokemon.h"
#include "GameManager.h"

int main()
{
	Player Trainer;
	Loop GameLoop;

	//start.Notice();
	GameLoop.Update(Trainer);


	return 0;
}