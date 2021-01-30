#pragma once

#include<iostream>
using namespace std;

enum Color{RED, BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _data(data)
	, _color(color)
	{}

	RBTreeNode<T>* _left; // ��������
	RBTreeNode<T>* _right; // �����Һ���
	RBTreeNode<T>* _parent; // ����˫��
	T _data; // ����ֵ��
	Color _color; // ������ɫ
};


template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_phead = new Node();
		_phead->_left = _phead;
		_phead->_right = _phead;
		_phead->_parent = nullptr;//�������û���κν��
	}
	~RBTree()
	{
		Destory(GetRoot());
		delete _phead;
		_phead = nullptr;
	}
	bool Insert(const T& data)
	{
		//1.���ն�����������ԭ������½ڵ�
		Node*& pRoot = GetRoot();
		
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_parent = _phead;
			_phead->_left = pRoot;
			_phead->_right = pRoot;
			return true;
		}
		//Ѱ�Ҳ���λ��
		Node* cur = pRoot;
		Node* parent = nullptr;
		cur->_parent = _phead;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else if (data>cur->_data)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(data);
		if (data < cur->_data)
		{
			parent->_left = cur;
		}
		else
			parent->_right = cur;
		cur->_parent = parent;
		//����Ƿ�Υ������
		while (parent != _phead && RED == parent->_color)
		{
			Node* grandParent = parent->_parent;
			if (parent == grandParent->_left)
			{
				Node* uncle = grandParent->_right;
				//���һ����������ڲ���Ϊ��ɫ
				if (uncle && RED == uncle->_color)
				{
					//���Ľ�����ɫ
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandParent->_color = RED;
					//���游��㵱��cur,�������½����ɫ
					cur = grandParent;
					parent = cur->_parent;
				}
				else
				{
					//����������������㲻���ڻ���Ϊ��ɫ
					if (cur == parent->_right)
					{
						RoateLeft(parent);
						std::swap(parent,cur);
					}
					
					grandParent->_color = RED;
					parent->_color = BLACK;
					RoateRight(grandParent);
				}
			}
			else
			{
				Node* uncl = grandParent->_left;
				if (uncl && RED == uncl->_color)
				{
					parent->_color = BLACK;
					uncl->_color = BLACK;
					grandParent->_color = RED;

					cur = grandParent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RoateRight(parent);
						std::swap(parent, cur);
					}
					parent->_color = BLACK;
					grandParent->_color = RED;
					RoateLeft(grandParent);
				}
			}
		}
		pRoot->_color = BLACK;
		_phead->_left = leftMost();
		_phead->_right = rightMost();
		return true;
	}
void Inorder()
{
	Inorder(GetRoot());
}
private:
	Node*& GetRoot()
	{
		return _phead->_parent;
	}
	Node* leftMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
		{
			return _phead;
		}
		Node* cur = root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node* rightMost()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return _phead;
		Node* cur = root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}
	void RoateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subR;
		subR->_parent = pparent;

		if (pparent == _phead)
		{
			_phead->_parent = subR;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}

	}
	void RoateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* pparent = parent->_parent;
		parent->_parent = subL;
		subL->_parent = pparent;

		if (pparent == _phead)
		{
			_phead->_parent = subL;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
			{
				pparent->_right = subL;
			}

		}
	}
	void Inorder(Node* root)
	{
		if (root)
		{
			Inorder(root->_left);
			cout << root->_data << " ";
			Inorder(root->_right);
		} 
		//cout << endl;

	}
	void Destory(Node* & root)
	{
		if (root)
		{

			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;
		}
	}
private:
	Node* _phead;

};

void TestRBTree()
{
	int array[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	t.Inorder();
}