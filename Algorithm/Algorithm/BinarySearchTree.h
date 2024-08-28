#pragma once

//				[]
//	[�� ������]		[�� ū��]

//				[10]
//			[5]			[20]
//					[9]		[30] 9�� �߸��Ȱ���.

enum class Color
{
	Red = 0,
	Black =1,
};
struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int key = {};
	Color color = Color::Black;
};

// Red-Black Tree
// 1) ��� ���� Red or Black
// 2) Root�� Black
// 3) Leaf(NIL)�� Black
// 4) Red ����� �ڽ��� Black (�����ؼ� Red-Red X)
// 5) �� ���κ��� ~ �������� ���� ��ε��� ��� ���� ���� Black
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Print();
	void Print(Node* node, int x, int y);


	void Print_Inorder() { Print_Inorder(_root); }
	void Print_Inorder(Node* node);

	Node* Search(Node* node, int key);
	Node* Search2(Node* node, int key);

	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node); // �� �������� ū �� ����

	void Insert(int key);
	void InsertFixup(Node* node);

	void Delete(int key);
	void Delete(Node* node);
	void DeleteFixup(Node* node);

	void Replace(Node* u, Node* v);

	void LeftRotate(Node* node);
	void RightRotate(Node* node);
private:
	Node* _root = nullptr;
	Node* _nil = nullptr;
};

