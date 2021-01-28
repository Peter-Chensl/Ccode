#pragma once


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x = T())
	:left(nullptr)
	, right(nullptr)
	, data(x)
	, _bf(0)
	{}
	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;

	T data;
	int _bf; 
};
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}
	~AVLTree()
	{
		Destroy(_root);
	}
	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}
		cur = new Node(data);
		if (data < parent->data)
		{
			parent->left = cur;
		}
		else
			parent->right = cur;

		while (parent)
		{
			if (cur == parent->left)
				parent->_bf--;
			else
				parent->_bf++;
			if (0 == parent->_bf)
				break;
			else if (-1 == parent->_bf || 1 == parent->_bf)
			{
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				if (2 == parent->_bf)
				{
					if (1 == cur->_bf)
					{
						RoateLeft(parent);
					}
					else
					{
						RotateRL(parent);
					}
				}
				else
				{
					if (-1 == cur->_bf)
					{
						RoateRight(parent);
					}
					else
					{
						RotateLR(parent);
					}
				}
				break;
			}
		}
		return true;
	}
	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}
private:
	void InOrder(Node* root)
	{
		if (root)
		{
			InOrder(root->left);
			cout << root->data << " ";
			InOrder(root->right);
		}
	}
	//二叉树的后续遍历规则
	void Destroy(Node*& root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}
	void RoateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;//bimianzuodanzhi
		subL->right = parent;

		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		//parent may be root
		if (nullptr == pparent)
		{
			_root = subL;
		}
		else
		{
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}
		parent->_bf = subL->_bf = 0;
	}
	void RoateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;
		subR->left = parent;

		Node* pparent = parent->parent;
		parent->parent = subR;
		subR->parent = pparent;

		if (nullptr == pparent)
		{
			_root = subR;
		}
		else
		{
			if (pparent->left = parent)
			{
				pparent->left = subR;
			}
			else
				pparent->right = subR;

		}
		subR->_bf = parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		RoateLeft(parent->left);
		RoateRight(parent);
	}
	void RotateRL(Node* parent)
	{
		RoateRight(parent->right);
		RoateLeft(parent);
	}
private:
	AVLTreeNode<T>* _root;
};

void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int> t;
	for (auto e : array)
	{
		t.Insert(e);
	}
	t.InOrder();
}