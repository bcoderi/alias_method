#pragma once

#include <vector>
#include <map>
#include "alias_method_interface.h"

class CAliasMethodMgr : public IAliasMethodInterface
{
public:
	/*
		构建alias_table
		probs，权重
		alias_table 生成结果，生命周期外部维护
	*/
	virtual void GenerateAliasTable(const std::vector<float>& probs, std::vector<std::pair<float, int> >& alias_table);

	/*
		获取随机结果
		random_first_value 第一维度随机数
		random_second_value 第二维度随机数
		alias_table 通过GenerateAliasTable构建的alias_table
	*/
	virtual int Random(const std::vector<std::pair<float, int> >& alias_table, const std::vector<int>& out_value);
};
