#pragma once

class Board;

class Player
{
	enum
	{
		MOVE_TICK = 100
	};
public:
	void Init(Board* board);
	void Update(uint64 deltaTick);

	void SetPos(POS pos) { _pos = pos; }
	POS GetPos() { return _pos; }

	bool CanGo(POS pos);
private:

	POS _pos = {};
	int32 _dir = DIR_UP;
	Board* _board = nullptr;

	vector<POS> _path;
	uint32 _pathIndex = 0;
	uint64 _sumTick = 0;
};

