#include <iostream>
using namespace std;

#include "HuffmanPress.h"

HTCompress::HTCompress()
{
	_charInfo.resize(256);
	for (size_t i = 0; i < 256; i++)
	{
		_charInfo[i].ch = i;
	}
}
void HTCompress::CompressFile(const string& filePath)
{
	FILE* fin = fopen(filePath.c_str(), "r");
	if (nullptr == fin)
	{
		cout << "带压缩文件路径出错！\n" << endl;
		return;
	}
	char readBuf[1024];
	while (true)
	{
		size_t rdsize = fread(readBuf, 1, 1024, fin);
		if (0 == rdsize)
		{
			break;
		}
		for (size_t i = 0; i < rdsize; ++i)
		{
			_charInfo[readBuf[i]].appearCount++;
		}
	}
	hafumanTree<CharInfo> ht;
	ht.CreathafumanTree(_charInfo);
	GeneteCode();

	fclose(fin);
}

void HTCompress::GeneteCode(hafumanTreeNode<CharInfo>* root)
{
	if (nullptr == root)
	{
		return;
	}
	GeneteCode(root->_left);
	GeneteCode(root->_right);
	if (nullptr == root->_left && nullptr == root->_right)
	{
		hafumanTreeNode<CharInfo>* cur = root;
		hafumanTreeNode<CharInfo>* parent = cur->_parent;

		string &strCode = _charInfo[cur->_weight.ch]._strCode;
		while (parent)
		{
			if (cur == parent->_left)
				strCode += '0';
			else
				strCode += '1';
			cur = parent;
			parent = cur->_parent;
		}
		reverse(strCode.begin(), strCode.end());
	}
}