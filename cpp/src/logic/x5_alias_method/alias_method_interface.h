#pragma once

#include <vector>
#include <map>

class IAliasMethodInterface
{
public:
	/*
		构建alias_table
		probs，权重
		alias_table 生成结果，生命周期外部维护
	*/
	virtual void GenerateAliasTable(const std::vector<float>& probs, std::vector<std::pair<float, int> >& alias_table) = 0;
	
	/*
		获取随机结果
		alias_table 通过GenerateAliasTable构建的alias_table
		out_value 业务数据，可以是物品ID，可以是其他玩法主键 
	*/
	virtual int Random(const std::vector<std::pair<float, int> >& alias_table, const std::vector<int>& out_value) = 0;

public:
	virtual ~IAliasMethodInterface(){}
};
