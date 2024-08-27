#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

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
//#pragma region 다익스트라
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
//#pragma endregion
//#pragma region 트리노드
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
//#pragma endregion

//#pragma region 우선순위 큐
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
//#pragma endregion

int main()
{

}
