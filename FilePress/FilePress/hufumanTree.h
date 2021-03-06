#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class W>
struct hafumanTreeNode
{
	hafumanTreeNode(const W& weight = W())
	:_left(nullptr)
	,_right(nullptr)
	, _parent(nullptr)
	,_weight(weight)
	{

	}
	hafumanTreeNode<W> *_left;
	hafumanTreeNode<W> *_right;
	hafumanTreeNode<W> *_parent;
	W _weight;
};

template <class W>
class hafumanTree
{
	typedef hafumanTreeNode<W> node;

	struct Compare
	{
		bool operator()(const node* left, const node* right)
		{
			return left->_weight > right->_weight;
		}
	};
public:
	hafumanTree()
		:_root(nullptr)
	{

	}
	~hafumanTree()
	{
		destroy(_root);
	}
	node* CreathafumanTree(const vector<W>& weight)
	{
		priority_queue<node*,vector<node*>,Compare> q;
		for (auto e : weight)
		{
			q.push(new node(e));
		}
		while (q.size() > 1)
		{
			node* left = q.top();
			q.pop();

			node *right = q.top();
			q.pop();

			node* parent = new node(left->_weight + right->_weight);
			parent->_left = left;
			parent->_right = right;

			left->_parent = parent;
			right->_parent = parent;
			q.push(parent);
		}
		_root = q.top();
		return _root;
	}
	node* getRoot()
	{
		return _root;
	}
private:
	void destroy(node *& root)
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
	node* _root;
};

/*void TestHafumanTree()
{
	vector<int> v = { 3, 9, 1, 5 };
	hafumanTree<int> ht;
	ht.CreathafumanTree(v);
}*/