﻿#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "BinarySearchTree.h"
#include <thread>
using namespace std;

//template<typename T>
//class Vector
//{
//public:
//
//    Vector()
//    {
//
//    }
//
//    ~Vector()
//    {
//        if (_data)
//            delete[] _data;
//
//    }
//
//    void push_back(const T& value)
//    {
//        if (_size == _capacity)
//        {
//            int newCapacity = static_cast<int>(_capacity * 1.5);
//            if (newCapacity == _capacity)
//                newCapacity++;
//
//            reserve(newCapacity);
//        }
//
//        _data[_size] = value;
//
//        _size++;
//    }
//
//    void reserve(int capacity)
//    {
//        if (_capacity >= capacity)
//            return;
//
//        _capacity = capacity;
//
//        T* newData = new T[_capacity];
//
//        for (int i = 0; i < _size; ++i)
//            newData[i] = _data[i];
//
//        if (_data)
//            delete[] _data;
//
//        _data = newData;
//    }
//
//    T& operator[](const int pos) { return _data[pos]; };
//
//    int size() { return _size; };
//    int capacity() { return _capacity; };
//
//    void clear()
//    {
//        if (_data)
//        {
//            delete[] _data;
//            _data = new T[_capacity];
//        }
//
//        _size = 0;
//    }
//private:
//    T* _data = nullptr; 
//    int _size = 0;
//    int _capacity = 0;
//};
//
//template<typename T>
//class Node
//{
//public:
//    Node() :_prev(nullptr), _next(nullptr), _data(T)
//    {
//
//    }
//
//    Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
//    {
//
//    }
//    ~Node() {};
//
//public:
//    Node* _prev;
//    Node* _next;
//    T _data;
//};
//
//template<typename T>
//class Iterator
//{
//public:
//    Iterator() : _node(nullptr)
//    {
//
//    }
//
//    Iterator(Node<T>* node) : _node(node)
//    {
//
//    }
//
//
//    Iterator& operator++()
//    {
//        _node = _node->_next;
//        return *this;
//    }
//
//    Iterator operator++(int)
//    {
//        Iterator<T> temp = *this;
//        _node = _node->_next;
//        return temp;
//    }
//
//    Iterator& operator--()
//    {
//        _node = _node->_prev;
//        return *this;
//    }
//
//    Iterator operator--(int)
//    {
//        Iterator<T> temp = *this;
//        _node = _node->_prev;
//        return temp;
//    }
//
//    T& operator*()
//    {
//        return _node->_data;
//    }
//
//    bool operator==(const Iterator& other)
//    {
//        return _node == other._node;
//    }
//
//    bool operator!=(const Iterator& other)
//    {
//        return _node != other._node;
//    }
//
//public:
//    Node<T>* _node;
//};
//
//template<typename T>
//class List
//{
//public:
//    List() : _size(0)
//    {
//        _head = new Node<T>();
//        _tail = new Node<T>();
//        _head->_next = _tail;
//        _tail->_prev = _head;
//    }
//
//    ~List()
//    {
//        while (_size > 0)
//            pop_back();
//
//        delete _head;
//        delete _tail;
//
//    }
//
//    void push_back(const T& value)
//    {
//        AddNode(_tail, value);
//    }
//
//    void pop_back()
//    {
//        RemoveNode(_tail->_prev);
//    }
//private:
//
//    // [head] <->[1] <-> [2] <-> [before] <-> [tail]
//    Node<T>* AddNode(Node<T>* before, const T& value)
//    {
//        Node<T>* newNode = new Node<T>(value);
//        Node<T>* prevNode = before->_prev;
//
//        prevNode->_next = newNode;
//        newNode->_prev = prevNode;
//        newNode->_next = before;
//        before->_prev = newNode;
//        _size++;
//
//        return newNode;
//    }
//
//    Node<T> RemoveNode(Node<T>* node)
//    {
//        Node<T>* prevNode = node->_prev;
//        Node<T>* nextNode = node->_next;
//
//        prevNode->_next = nextNode;
//        nextNode->_prev = prevNode;
//
//        delete node;
//
//        _size--;
//
//        return nextNode;
//    }
//
//    int Size() { return size; };
//public:
//    using iterator = Iterator<T>;
//
//    iterator begin() { return iterator(_head->_next); }
//    iterator end() { return iterator(_tail); }
//
//    iterator insert(iterator it, const T& value)
//    {
//        Node<T>* node = AddNode(it._node, value);
//        return iterator(node);
//    }
//
//    iterator erase(iterator it)
//    {
//        Node<T>* node = RemoveNode(it._node);
//        return iterator(node);
//    }
//
//private:
//    Node<T>*    _head;
//    Node<T>*    _tale;
//    int         _size;
//};
//
//template<typename T>
//class Stack
//{
//public:
//    
//    void push(const T& value)
//    {
//        _container.push_back(value);
//    }
//
//    void pop()
//    {
//        _container.pop_back);
//    }
//
//    T& top()
//    {
//        return _container.back();
//    }
//
//    bool empty() { return _container.empty(); }
//    int size() { return _container.size(); }
//public:
//    vector<T> _container;
//};
//
//template<typename T>
//class ListQueue
//{
//public:
//    void push(const T& value)
//    {
//        _container.push_back(value);
//    }
//
//    void pop()
//    {
//        _container.pop_front();
//    }
//
//    T& front()
//    {
//        return _container.front();
//    }
//
//    bool empty() { return _container.empty(); }
//    int size() { return _container.size(); }
//public:
//    list<T> _container;
//};
//
//template<typename T>
//class ArrayQueue
//{
//public:
//    ArrayQueue()
//    {
//        _container.resize(100);
//    }
//    void push(const T& value)
//    {
//        // TODO : 다 찼는지 체크
//
//        if (_size == _container.size())
//        {
//            int newSize = max(1, _size * 2);
//            vector<T> newdata;
//            newdata.resize(newSize);
//
//            for (int i = 0; i < _size; ++i)
//            {
//                int index = (_front + i) % _container.size();
//                newData[i] = _container[index];
//            }
//
//            _container.swap(newData);
//            _front = 0;
//            _back = _size;
//        }
//
//        _container[_back] = value;
//        _back = (_back + 1) % _container.size();
//        _size++;
//
//    }
//
//    void pop()
//    {
//        _front = (_front + 1) % _container.size();
//        _size--;
//    }
//
//    T& front()
//    {
//        return _container[_front];
//    }
//
//    bool empty() { return _size == 0; }
//    int size() { return _size; }
//public:
//    vector<T> _container;
//
//    int _front = 0;
//    int _back = 0;
//    int _size = 0;
//};
//
#pragma region 다익스트라
//struct Vertex
//{
//    // int data;
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent; // 인접 행렬
//
//void CreateGraph()
//{
//    vertices.resize(6);
//    adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//    adjacent[0][1] = 15;
//    adjacent[0][3] = 35;
//    adjacent[1][0] = 15;
//    adjacent[1][2] = 5;
//    adjacent[1][3] = 10;
//    adjacent[3][4] = 5;
//    adjacent[5][4] = 5;
//}
//
//void Dijikstra(int here)
//{
//    struct VertexCost
//    {
//        int vertex;
//        int cost;
//    };
//
//    list<VertexCost> discovered; // 발견 목록
//    vector<int> best(6, INT32_MAX); // 각 정점별로 지금까지 발견한 최소 거리
//    vector<int> parent(6, -1);
//
//    discovered.push_back(VertexCost{ here, 0 });
//    best[here] = 0;
//    parent[here] = here;
//
//    while (discovered.empty() == false)
//    {
//        // 제일 좋은 후보를 찾는다
//        list<VertexCost>::iterator bestIt;
//        int bestCost = INT32_MAX;
//
//        for (auto it = discovered.begin(); it != discovered.end(); it++)
//        {
//            if (it->cost < bestCost)
//            {
//                bestCost = it->cost;
//                bestIt = it;
//            }
//        }
//
//        int cost = bestIt->cost;
//        here = bestIt->vertex;
//        discovered.erase(bestIt);
//
//        // 방문? 더 짧은 경로를 뒤늦게 찾았다면 스킵.
//        if (best[here] < cost)
//            continue;
//
//        // 방문!
//
//        for (int there = 0; there < 6; there++)
//        {
//            // 연결되지 않았으면 스킵.
//            if (adjacent[here][there] == -1)
//                continue;
//
//            // 더 좋은 경로를 과거에 찾았으면 스킵.
//            int nextCost = best[here] + adjacent[here][there];
//            if (nextCost >= best[there])
//                continue;
//
//            discovered.push_back(VertexCost{ there, nextCost });
//            best[there] = nextCost;
//            parent[there] = here;
//        }
//    }
//
//    int a = 3;
//}
#pragma endregion
#pragma region 트리노드
//struct Node
//{
//    Node() {}
//    Node(const string& data) : data(data) {}
//
//    string data;
//    vector<Node*> children;
//};
//
//Node* createTree()
//{
//    Node* root = new Node("R1 개발실");
//    {
//        Node* node = new Node("디자인 팀");
//        root->children.push_back(node);
//        {
//            Node* leaf = new Node("전투");
//            node->children.push_back(leaf);
//        }
//        {
//            Node* leaf = new Node("경제");
//            node->children.push_back(leaf);
//        }
//        {
//            Node* leaf = new Node("스토리");
//            node->children.push_back(leaf);
//        }
//    }
//    {
//        Node* node = new Node("프로그래밍 팀");
//        root->children.push_back(node);
//        {
//            Node* leaf = new Node("서버");
//            node->children.push_back(leaf);
//        }
//        {
//            Node* leaf = new Node("클라");
//            node->children.push_back(leaf);
//        }
//        {
//            Node* leaf = new Node("엔진");
//            node->children.push_back(leaf);
//        }
//    }
//    {
//        Node* node = new Node("아트 팀");
//        root->children.push_back(node);
//        {
//            Node* leaf = new Node("배경");
//            node->children.push_back(leaf);
//        }
//        {
//            Node* leaf = new Node("캐릭터");
//            node->children.push_back(leaf);
//            {
//                Node* leaf2 = new Node("전사");
//                leaf->children.push_back(leaf2);
//            }
//        }
//    }
//
//    return root;
//}
//
//void PrintTree(Node* root, int depth)
//{
//    for (int i = 0; i < depth; ++i)
//        cout << "-";
//
//    cout << root->data << endl;
//
//    for (auto child : root->children)
//        PrintTree(child, depth + 1);
//}
//
//int GetHeight(Node* root)
//{
//    int height = 1;
//
//    for (auto children : root->children)
//        height = max(height, GetHeight(children) + 1);
//
//    return height;
//}
#pragma endregion
#pragma region 우선순위 큐
//
//template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
//class PriorityQueue
//{
//public:
//	void push(const T& data)
//	{
//		// 구조 맞추기
//		_heap.push_back(data);
//
//		//도장깨기 시작
//		int now = static_cast<int>(_heap.size()) - 1;
//
//		while (now > 0)
//		{
//			// 부모 노드와 비교해서 더 작으면 패배
//			int next = (now - 1) / 2;
//			if (_predicate(_heap[now], _heap[next]))
//				break;
//
//			// 이기면 데이터 교체
//			::swap(_heap[now], _heap[next]);
//			now = next;
//		}
//
//	}
//
//	void pop()
//	{
//		_heap[0] = _heap.back();
//		_heap.pop_back();
//
//		int now = 0;
//
//		while (true)
//		{
//			int left = 2 * now + 1;
//			int right = 2 * now + 2;
//
//			// 리프에 도달
//			if (left >= (int)_heap.size())
//				break;
//
//			int next = now;
//			//왼쪽 비교
//			if (_predicate(_heap[next], _heap[left]))
//				next = left;
//			//오른쪽 비교
//			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
//				next = right;
//
//			// 왼쪽, 오른쪽 둘 다 현재 값보다 작을 시
//			if (next == now)
//				break;
//
//			::swap(_heap[now], _heap[next]);
//			now = next;
//		}
//	}
//
//	T& top()
//	{
//		return _heap[0];
//	}
//
//	bool empty()
//	{
//		return _heap.empty();
//	}
//
//private:
//	Container _heap = {};
//	Predicate _predicate = {};
//};
//
#pragma endregion
#pragma region 이진탐색
//
//// 면접때 많이 물어보고, STL에서 map을 사용하면 사용된다.
//// 이진 탐색 (binary search)
//// 상황) 배열에 데이터가 정렬되어 있다. 무조건 정렬!!
//
//// Q) 82라는 숫자가 배열에 있습니까?
//// [1][8][15][23][32][44][56][63][81][91]
//// A) O(N)과 O(logN)과는 다르죠. 업다운 게임
//vector<int> numbers;
//
//// O(logN)이다.
//// 정렬된 배열을 이용해서 이진 탐색 가능한것.
//// 잠깐. 배열은 그런데 중간 삽입/삭제가 느리다,, -> 트리로 가서 노드기반까지 써야함.
//// 만들어지고 데이터가 바뀔 일이 없으면 그냥 이진 탐색만 써도 우월
//// 정렬된 연결리스트로는 불가 ( 임의 접근 X )
//void BinarySearch(int N)
//{
//	int left = 0;
//	int right = (int)numbers.size() - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (N < numbers[mid])
//		{
//			right = mid - 1;
//		}
//		else if (N > numbers[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			cout << "찾음." << endl;
//			break;
//		}
//	}
//}
//
#pragma endregion
#pragma region 버블 정렬
//
//void BubbleSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	for (int i = 0; i < n - 1; ++i)
//	{
//		for (int j = 0; j < (n - 1 + i); ++j)
//		{
//			if (v[j] > v[j + 1])
//				swap(v[j], v[j + 1]);
//		}
//	}
//}
//
#pragma endregion
#pragma region 선택 정렬
//void SelectionSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int bestIdx = i;
//
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (v[j] < v[bestIdx])
//				bestIdx = j;
//		}
//
//		swap(v[i], v[bestIdx]);
//	}
//}
#pragma endregion
#pragma region 삽입정렬
//void InsertionSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	for (int i = 1; i < n; ++i)
//	{
//		int insertData = v[i];
//
//		int j;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (v[j] > insertData)
//				v[j + 1] = v[j];
//			else
//				break;
//		}
//
//		v[j + 1] = insertData;
//	}
//}
#pragma endregion
#pragma region 힙 정렬
//void HeapSort(vector<int>& v)
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//	for (int num : v)
//		pq.push(num);
//	v.clear();
//	while (pq.empty() == false)
//	{
//		v.push_back(pq.top());
//		pq.pop();
//	}
//}
#pragma endregion

#pragma region 병합 정렬

// 병합 정렬
// 분할 정복
// - 분할 - Divide - 문제를 더 단순하게 분할
// - 정복 - Conquer - 분할된 문제를 해결
// - 결합 - combine - 결과를 취합하여 마무리

// [3][K][7][2][3][4][8][9]         8개 * 1
// [3][K][7][2] [J][4][8][9]		4개 * 2
// [3][K] [7][2] [J][4] [8][9]		2개 * 4
// [3] [K] [7] [2] [J] [4] [8] [9]	1개 * 8
// [3][K] [2][7]  [4][J]  [8][9]	2개 * 4

vector<int> Merge(vector<int> a, vector<int> b)
{
	vector<int> temp;
	return temp;
}

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// [2][3][7][K][4][8][9][J]
	//          [1]             [r]
	int leftIdx = left;
	int rightIdx = mid + 1;

	// [2]
	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); ++i)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}
#pragma endregion 

#pragma region 퀵 정렬

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	// O(N)
	while (low <= high)
	{
		while (low <= right && pivot >= v[low])
			low++;

		while (high >= left && pivot <= v[high])
			high--;

		if (low < high)
			swap(v[low], v[high]);
	}

	swap(v[left], v[high]);
	return high;
}

void QuickSort(vector<int>& v, int left, int right)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
}

#pragma endregion

#pragma region 해시 테이블

// 해시 테이블

// map vs hash_map(unordered_map)

// map - Red-black Tree
// 추가 탐색 삭제 - O(logN)

// hash_map
// 추가 탐색 삭제 - O(1)

// 살은 내주고 뼈를 취한다. 메모리를 내주고 속도를 취한다.

void TestTable()
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	users[777] = User{ 777, "Rookiss" };

	string name = users[777].username;
	cout << name << endl;

	// 테이블
	// 키를 알면 데이터를 단번에 찾을 수 있다.
	// 만약 3억 이렇게 넘어가면 문제
}

// 보안
// id : rr + pw : 1234
// id : rr + pw : hash(1234) -> 12awerawero3j24

// DB [rr][12awerawero3j24]

void TestHash()
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash <- 고유번호

	// 123456789번 유저 정보 세팅
	users[key] = User{ userId, "Rookiss" };

	//123456789번 유저 이름
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}

	// 충돌 문제
	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나선다
	// 선형 조사법 (linear probing)
	// hash(key)+1 -> hash(key)+2
	// 이차 조사법 (quadratic probing)
	// hash(key)+1^2 -> hash(key)+2^2
	// -etc

	// 체이닝
}

//O(1)
void TestHashTableChaining()
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash <- 고유번호

	// 123456789번 유저 번호 세팅
	users[key].push_back(User{ userId, "Rookiss" });
	users[789].push_back(User{ 789, "Faker" });

	// 123456789번 유저 이름은?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}
#pragma endregion

#pragma region 그래프/트리 응용 MST전에 Union-Find
//
//class DisJoinSet
//{
//public:
//    DisJoinSet(int n) : _parent(n), _rank(n, 1)
//    {
//        for (int i = 0; i < n; ++i)
//            _parent[i] = i;
//    }
//
//    // 조직 폭력배 구조?
//    // [1]		[3]
//    // [2]	 [4][5][0]
//    // 		    
//
//    // 니 대장이 누구니?
//    int Find(int u)
//    {
//        if (u == _parent[u])
//            return u;
//
//        // _parent[u] = Find(_parent[u]);
//        // return _parent[u];
//
//        return _parent[u] = Find(_parent[u]);
//    }
//
//    // u와 v를 합친다
//    void Merge(int u, int v)
//    {
//        u = Find(u);
//        v = Find(v);
//
//        if (u == v)
//            return;
//        if (_rank[u] > _rank[v])
//            swap(u, v);
//
//        // rank[u] <= rank[v] 보장
//        _parent[u] = v;
//
//        if (_rank[u] == _rank[v])
//            _rank[v]++;
//    }
//
//private:
//    vector<int> _parent;
//    vector<int> _rank;
//};
//
//#pragma endregion
//
//#pragma region 크루스칼 사용 예시
//
//struct Vertex
//{
//    // int data;
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent; // 인접 행렬
//
//void CreateGraph()
//{
//    vertices.resize(6);
//    adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//    adjacent[0][1] = adjacent[1][0] = 15;
//    adjacent[0][3] = adjacent[3][0] = 35;
//    adjacent[1][2] = adjacent[2][1] = 5;
//    adjacent[1][3] = adjacent[3][1] = 10;
//    adjacent[3][4] = adjacent[4][3] = 5;
//    adjacent[3][5] = adjacent[5][3] = 10;
//    adjacent[5][4] = adjacent[4][5] = 5;
//}
//
//struct CostEdge
//{
//    int cost;
//    int u;
//    int v;
//
//    bool operator<(CostEdge& other)
//    {
//        return cost < other.cost;
//    }
//};
//
//int Kruskal(vector<CostEdge>& selected)
//{
//    int ret = 0;
//
//    selected.clear();
//
//    vector<CostEdge> edges;
//
//    for (int u = 0; u < adjacent.size(); ++u)
//    {
//        for (int v = 0; v < adjacent[u].size(); ++v)
//        {
//            if (u > v) // 양쪽일때 하나만 넣을때 좋음.
//                continue;
//
//            int cost = adjacent[u][v];
//            if (cost == -1)
//                continue;
//
//            edges.push_back(CostEdge{ cost, u, v });
//        }
//    }
//
//    std::sort(edges.begin(), edges.end());
//
//    DisJoinSet sets(vertices.size());
//
//    for (CostEdge& edge : edges)
//    {
//        // 같은 그룹은 스킵 - 사이클 발생 예방
//        if (sets.Find(edge.u) == sets.Find(edge.v))
//            continue;
//
//        // 두 그룹 합치기
//        sets.Merge(edge.u, edge.v);
//        selected.push_back(edge);
//        ret += edge.cost;
//
//    }
//
//    return ret;
//}
#pragma endregion

#pragma region DP-LIS

// LIS (Longest Increasing Sequence)

// Seq : 1 9 2 5 7
// 부분 수열 : 일부(0개 이상) 숫자를 지우고 남은 수열
// ex) 1 2 5
// ex) 1 9 5 7
// 순 증가 부분 수열
// ex) 1 2 5

// LIS : 제일 긴 [순 증가 부분 수열]의 길이
// 1 2 5 7 = 길이 4

//int cache[100];
//vector<int> seq;
//
//int LIS(int pos)
//{
//    // 기저사항
//
//    // 캐시 확인
//    int& ret = cache[pos];
//    if (ret != -1)
//        return ret;
//
//    // 구하기
//
//    // 최소 seq[pos]는 있으니 1부터 시작
//    ret = 1; // 길이임
//
//    // 구하기
//    for (int next = pos + 1; next < seq.size(); ++next)
//        if (seq[pos] < seq[next])
//            ret = max(ret, 1 + LIS(next));
//
//    return ret;
//}
#pragma endregion

#pragma region TRIANGLE_PATH DP

// TRIANGLE_PATH
// - (0,0)부터 시작해서 아래 or 아래우측으로 이동 가능
// - 만나는 숫자를 모두 더함
// - 더한 숫자가 최대가 되는 경로? 합?

// 6
// 1 2
// 3 7 4
// 9 4 1 7
// 2 7 5 9 4

//int N;
//vector<vector<int>> board;
//vector<vector<int>> cache;
//vector<vector<int>> nextX;
//
//int path(int y, int x)
//{
//    // 기저 사항
//    if (y == N)
//        return 0;
//
//    // 캐시 확인
//    int& ret = cache[y][x];
//    if (ret != -1)
//        return ret;
//
//    // 경로 기록
//    {
//        int nextBottom = path(y + 1, x);
//        int nextBottomRight = path(y + 1, x + 1);
//        if (nextBottom > nextBottomRight)
//            nextX[y][x] = x;
//        else
//            nextX[y][x] = x + 1;
//    }
//
//    return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
//}

#pragma endregion

#pragma region TIC_TAE_TOE DP

// [o][x][.]
// [.][o][x]
// [.][.][o]

// 0 ~ 3 ^ 9 = 19683

//int HashKey(const vector<vector<char>>& board)
//{
//	int ret = 0;
//
//	for (int y = 0; y < 3; ++y)
//	{
//		for (int x = 0; x < 3; ++x)
//		{
//			ret = ret * 3;
//
//			if (board[y][x] == 'o')
//				ret += 1;
//			else if (board[y][x] == 'x')
//				ret += 2;
//		}
//	}
//
//	return ret;
//}
//
//vector<vector<char>> board;
//int cache[19683];
//
//bool IsFinished(const vector<vector<char>>& board, char turn)
//{
//	// 좌우
//	for (int i = 0; i < 3; i++)
//		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
//			return true;
//
//	// 상하
//	for (int i = 0; i < 3; i++)
//		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
//			return true;
//
//	// 대각선
//	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
//		return true;
//
//	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
//		return true;
//
//	return false;
//}
//
//enum
//{
//	DEFAULT = 2,
//	WIN = 1,
//	DRAW = 0,
//	LOSE = -1
//};
//
//int CanWin(vector<vector<char>>& board, char turn)
//{
//	// 기저사례
//	if (IsFinished(board, 'o' + 'x' - turn))
//		return LOSE;
//
//	// 캐시 확인
//	int key = HashKey(board);
//	int& ret = cache[key];
//	if (ret != DEFAULT)
//		return ret;
//
//	// 풀기
//
//	// [.][x][.]
//	// [.][o][.]
//	// [.][.][.]
//	int minValue = DEFAULT;
//
//	for (int y = 0; y < 3; ++y)
//	{
//		for (int x = 0; x < 3; ++x)
//		{
//			if (board[y][x] != '.')
//				continue;
//
//			// 착수
//			board[y][x] = turn;
//
//			//확인
//			minValue = min(minValue, CanWin(board, 'o' + 'x' - turn)); // 상대방이 패배했을때가 제일 좋은케이스
//			
//			//취소
//			board[y][x] = '.';
//		}
//	}
//
//	if (minValue == DRAW || minValue == DEFAULT)
//		return ret = DRAW;
//
//	return ret = -minValue; // 상대가 이기면 내가 지고 상대가 지면 내가 이김
//}

#pragma endregion

#pragma region enchant DP

// 집행검 +N강까지 도달하는경우의수
// +1,+2,+3강이 가능하며 터지는건 경우의수에 없음

//int N;
//int cache[100];
//
//int Enchant(int num)
//{
//
//	//기저
//	if (num > N)
//		return 0; // 초과는 안셈
//	else if (num == N)
//		return 1; // 추가
//
//	//캐쉬
//	int& ret = cache[num];
//	if (ret != -1)
//		return ret;
//
//	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
//}

#pragma endregion

#pragma region KART_RIDER DP

// 오늘의 주제 : 동적 계획법 / (DP)
// KART-RIDER

// - 카트는 게임이 시작하면 달리기 시작하며, 주어진 시간(T)동안 달린다.
// - 카트는 처음에는 기본 속도 (초속 1)로 달린다.
// - 게임이 시작하고 특정 시간(a)가 되면 바닥에 신발 아이템이 생성된다.
// - 카트는 신발을 신거나 지나칠 수 있다. 지나간 신발은 영영 다시 주을 수 없다.
// - 신발를 착용하려면 (b)의 시간이 필요하다. 즉 (b)초 동안 제자리에서 멈추고 나서야 움직일 수 있다.
// - 신발을 착용하면 일정시간(c) 동안 신발 속도(d)로 달릴 수 있다.
// - 신발은 하나만 착용할 수 있고, 가장 최근에 착용한 신발의 속도만 적용된다. 
// - 신발을 벗거나 다른 신발로 바꿔 장착할 때 추가시간이 들지 않는다. (새로운 신발을 신는 시간만 소요 된다)
// - 신발 효과가 끝나면 다시 기본 속도 (초속 1)로 달린다.

// Q) 생성되는 모든 신발 정보가 주어졌을 때, (T)초 동안 갈 수 있는 최대 거리를 구하라.

struct Shoe
{
	Shoe(int a, int b, int c, int d)
	{
		time = a;
		start = a + b;
		end = a + b + c;
		speed = d;
	}

	int time; // a   - 신발스폰시간
	int start; //a+b - 신발 효과 시작 시간
	int end; //a+b+c - 신발 효과 끝나는 시간
	int speed; // d  - 신발속도
};

int T;
vector<Shoe> shoes;
vector<int> cache;

// input.txt
// 20
// 4
// 3 4 10 3
// 4 1 4 2
// 10 2 5 5
// 15 1 3 7

// now번 신발을 신고 갈 수 있는 최대 거리를 반환.

int Solve(int now)
{
	// 기저
	if (now >= shoes.size()) // 이럴수는 없지만 예방
		return 0;

	// 캐쉬
	int& ret = cache[now];
	if (ret != -1)
		return ret;

	// 풀이
	Shoe& shoe = shoes[now];

	// 신발 신고 이동한 거리 + 걸어서 이동한 거리
	int dist = (shoe.end - shoe.start) * shoe.speed + (T - shoe.end) * 1;
	ret = max(ret, dist);

	for (int next = now + 1; next < shoes.size(); ++next)
	{
		Shoe& nextShoe = shoes[next];
		if (nextShoe.time < shoe.start) // 지나친거
			continue;

		// 다음 신발까지 이동 거리
		int moveDist = 0;

		// 현재 신발 효과가 끝나기 전에 다음 신발이 스폰
		if (nextShoe.time <= shoe.end)
		{
			moveDist = (nextShoe.time - shoe.start) * shoe.speed; // 신발신고 이동
		}
		else
		{
			moveDist = (shoe.end - shoe.start) * shoe.speed;// 신발신고이동
			moveDist += (nextShoe.time - shoe.end) * 1; //나머지 부분 걸어서이동
		}

		ret = max(ret, moveDist + Solve(next));
	}

	return ret;
}

#pragma endregion
int main()
{
	{ // TRIANGLE_PATH
	/*	board = vector<vector<int>>
		{
			{6},
			{1, 2},
			{3, 7, 4},
			{9, 4, 1, 7},
			{2, 7, 5, 9, 4}
		};

		N = board.size();
		cache = vector<vector<int>>(N, vector<int>(N, -1));
		nextX = vector<vector<int>>(N, vector<int>(N));

		int ret = path(0, 0);
		cout << ret << endl;

		int y = 0;
		int x = 0;

		while (y < N)
		{
			cout << board[y][x] << " -> ";
			x = nextX[y][x];
			y++;
		}*/
	}
	T = 20;

	shoes.push_back(Shoe(0, 0, T, 1));
	shoes.push_back(Shoe(3, 4, 10, 3));
	shoes.push_back(Shoe(4, 1, 4, 2));
	shoes.push_back(Shoe(10, 2, 5, 5));
	shoes.push_back(Shoe(15, 1, 3, 7));
	sort(shoes.begin(), shoes.end(), [=](Shoe& left, Shoe& right) {
		return left.time < right.time;
	});

	cache = vector<int>(shoes.size(), -1);

	int ret = Solve(0);
	cout << ret << endl;
}
