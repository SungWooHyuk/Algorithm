#include "pch.h"
#include <iostream>
#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"
Board board;
Player player;
int main()
{
	::srand(static_cast<unsigned>(time(nullptr)));
	uint64 lastTick = 0;
	board.Init(25, &player);
	player.Init(&board);
	while (true)
	{
#pragma region 프레임 관리
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion
		
		player.Update(deltaTick);
		board.Render();
		
	}
}
