#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	//RightHand();
	//Bfs();
	AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		_board->GenerateMap_Prim();
		Init(_board);
		return;
	}

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

void Player::RightHand()
{
	POS pos = _pos;

	_path.clear();
	_path.push_back(pos);
	// 목적지 도착하기 전에는 계속 실행
	POS dest = _board->GetExitPos();

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

		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;
			// 앞으로 전진
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos + front[_dir]))
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

void Player::Bfs()
{
	POS pos = _pos;

	// 목적지 도착하기 전에는 계속 실행
	POS dest = _board->GetExitPos();

	POS front[4] =
	{
		POS { -1, 0},	// UP
		POS { 0, -1},	// LEFT
		POS { 1, 0},	// DOWN
		POS { 0, 1},	// RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	//vector<vector<Pos>> parent;
	// parent[A] = B; -> A는 B로 인해 발견함
	map<POS, POS> parent;

	queue<POS> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 방문!
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < 4; dir++)
		{
			POS nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인.
			if (CanGo(nextPos) == false)
				continue;
			// 이미 발견한 지역인지 확인.
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	_path.clear();

	// 거꾸로 거슬러 올라간다
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// 시작점은 자신이 곧 부모이다
		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}

struct PQNode
{
	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32 f; // f = g + h
	int32 g;
	POS pos;
};
void Player::AStar()
{
	// 점수 매기기
	// F = G+H
	// F = 최종점수 ( 작을 수록 좋고, 경로에 따라 달라짐 )
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을수록 좋고, 경로에 따라 달라짐)
	// H = 목적지에서 얼마나 가까운지 ( 작을 수록 좋음, 고정 )

	POS start = _pos;
	POS dest = _board->GetExitPos();

	enum
	{
		DIR_COUNT = 4
	};

	POS front[] =
	{
		POS { -1, 0},	// UP
		POS { 0, -1},	// LEFT
		POS { 1, 0},	// DOWN
		POS { 0, 1},	// RIGHT
		POS {-1, -1},	// UP_LEFT
		POS {1, -1},	// DOWN_LEFT
		POS {1, 1},		// DOWN_RIGHT
		POS {-1, 1},	// UP_RIGHT
	};

	int32 cost[] =
	{
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14
	};

	const int32 size = _board->GetSize();

	//ClosedList
	//close[y][x] -> (y,x)에 방문을 했는지 여부
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	//best[y][x] -> 지금까지 (y,x)에 대한 가장 좋은 비용 (작을 수록 좋음)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	//부모 추적 해야죠
	map<POS, POS> parent;

	// openList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 1. 예약(발견) 시스템 구현
	// - 여기서 이미 더 좋은 경로를 찾았다면 스킵
	// 2. 뒤늦게 더 좋은 경로가 발견될시에는 예외처리 필수적으로
	// - openlist에서 찾아서 제거하거나
	// - pq에서 pop한 다음에 무시한다거나

	// 초기값
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start }); // 초기값 넣기
		best[start.y][start.x] = g + h; // 당연한것
		parent[start] = start; // 초기값의 부모는 나
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾아준다.
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾을 예정이다.
		// 거기서 더 빠른 경로로 인해서 이미 방문 즉, 닫힌 경우엔 스킵
		// 선택
		if (closed[node.pos.y][node.pos.x])
			continue;
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest) // 도착
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			POS nextPos = node.pos + front[dir];

			if (CanGo(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			// 자 이제 계산
			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue; // 베스트가 더 적다. 즉 이 길이 아니다.

			// 오 여기가 제일 빠르네
			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode{ g + h, g, nextPos });
			parent[nextPos] = node.pos;
		}
	}

	// 거꾸로 올라가기
	POS pos = dest;

	_path.clear();
	_pathIndex = 0;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}
