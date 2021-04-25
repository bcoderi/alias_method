#pragma once

#include <vector>
#include <map>
#include "alias_method_interface.h"

class CAliasMethodMgr : public IAliasMethodInterface
{
public:
	/*
		����alias_table
		probs��Ȩ��
		alias_table ���ɽ�������������ⲿά��
	*/
	virtual void GenerateAliasTable(const std::vector<float>& probs, std::vector<std::pair<float, int> >& alias_table);

	/*
		��ȡ������
		random_first_value ��һά�������
		random_second_value �ڶ�ά�������
		alias_table ͨ��GenerateAliasTable������alias_table
	*/
	virtual int Random(const std::vector<std::pair<float, int> >& alias_table, const std::vector<int>& out_value);
};
