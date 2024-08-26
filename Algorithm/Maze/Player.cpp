#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	POS pos = _pos;

	_path.clear();
	_path.push_back(pos);
	// 목적지 도착하기 전에는 계속 실행
	POS dest = board->GetExitPos();
	
	POS front[4] =
	{
		POS { -1, 0}, // UP
		POS { 0, -1}, // LEFT
		POS { 1, 0},  // DOWN
		POS { 0, 1},  // RIGHT
	};


	while (pos != dest)
	{
		// 1. 현재 바라보는 방향으로 기준으로 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		if (CanGo(pos+front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;
			// 앞으로 전진
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos+front[_dir]))
		{
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

	stack<POS> s;

	for (int i = 0; i < _path.size() - 1; ++i)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	// dest 도착
	if (_path.empty() == false)
		s.push(_path.back());

	vector<POS> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());

	_path = path;
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(POS pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}
