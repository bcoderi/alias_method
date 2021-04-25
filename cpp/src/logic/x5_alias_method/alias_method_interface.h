#pragma once

#include <vector>
#include <map>

class IAliasMethodInterface
{
public:
	/*
		����alias_table
		probs��Ȩ��
		alias_table ���ɽ�������������ⲿά��
	*/
	virtual void GenerateAliasTable(const std::vector<float>& probs, std::vector<std::pair<float, int> >& alias_table) = 0;
	
	/*
		��ȡ������
		alias_table ͨ��GenerateAliasTable������alias_table
		out_value ҵ�����ݣ���������ƷID�������������淨���� 
	*/
	virtual int Random(const std::vector<std::pair<float, int> >& alias_table, const std::vector<int>& out_value) = 0;

public:
	virtual ~IAliasMethodInterface(){}
};
