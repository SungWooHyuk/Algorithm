#pragma once

class Board;

class Player
{
public:
	void Init(Board* board);
	void Update(uint64 deltaTick);

	void SetPos(POS pos) { _pos = pos; }
	POS GetPos() { return _pos; }

private:

	POS _pos = {};
	int32 _die = DIR_UP;
	Board* _board = nullptr;
};

