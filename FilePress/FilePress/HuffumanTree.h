#pragma once

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
struct huffmanTreeeNode
{
	huffmanTreeeNode(const T& weight = T())
	:_left(nullptr)
	, _right(nullptr)
	, _weight(weight)
	{}
	huffmanTreeeNode<T>* _left;
	huffmanTreeeNode<T>* _right;
	T _weight;
};

template<class T>
class huffmanTree
{
	
	typedef huffmanTreeeNode<T> Node;
	struct compare
	{
		bool operator()(const Node* left, const Node* right)
		{
			return left->_weight > right->_weight;
		}
	};
public:
	huffmanTree()
		:_root(nullptr)
	{}
	~huffmanTree()
	{
		destroy(_root);
	}

	Node* CreatehuffmanTree(const vector<T>& weight)
	{
		priority_queue<Node*,vector<Node*>,compare> q;
		for (auto e : weight)
		{
			q.push(new Node(e));
		}
		while (q.size() > 1)
		{
			Node* left = q.top();
			q.pop();

			Node* right = q.top();
			q.pop();

			Node* parent = new Node(left->_weight + right->_weight);
			parent->_right = right;
			parent->_left = left;

			q.push(parent);
		}
		_root = q.top();
		return _root;
	}
private:
	void destroy(Node *&root)
	{
		if (root)
		{
			destroy(root->_left);
			destroy(root->_right);
			delete root;
			root = nullptr;
		}
	}
private:
	Node* _root;
};

void testHuffmanTree()
{
	vector<int> v = { 1, 5, 3, 9 };
	huffmanTree<int> ht;
	ht.CreatehuffmanTree(v);
}