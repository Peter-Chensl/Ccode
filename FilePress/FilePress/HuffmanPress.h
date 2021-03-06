#pragma once

#include <string>
#include <vector>
#include "hufumanTree.h"
using namespace std;
typedef  unsigned long long  ulg;
struct CharInfo
{
	CharInfo(ulg appcount)
	:appearCount(appcount)
	{

	}
	char ch;
	ulg appearCount;
	string _strCode;
	bool operator>(const CharInfo& c)
	{
		return appearCount > c.appearCount;
	}
	CharInfo operator+(const CharInfo& c)const
	{
		return CharInfo(appearCount + c.appearCount);
	}
};



class HTCompress
{
public:
	HTCompress();
	void CompressFile(const string& filePath);
	void UNCompressFile(const string& filePath);
private:
	void GeneteCode(hafumanTreeNode<CharInfo>* root);
private:
	//�������ļ��ж������ֽڷ�ʽ�����
	vector<CharInfo> _charInfo;
};