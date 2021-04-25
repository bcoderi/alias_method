#pragma once

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
#include <vector>
#include <queue>

class CDiscreteRandomVariable
{
public:
	CDiscreteRandomVariable(const std::vector<int>& vals, const std::vector<double>& probs)
		: m_out_values(vals)
		, m_int_dis(0, probs.size() - 1)
		, m_alias(GenerateAliasTable(probs))
	{
	}

	int Random();
private:
	std::vector<std::pair<double, int> > GenerateAliasTable(const std::vector<double>& probs);
private:
	std::vector<int> m_out_values;
	std::vector<std::pair<double, int>> m_alias;
	mutable std::random_device   m_rd;
	mutable std::mt19937         m_gen{ m_rd() };
	mutable std::uniform_real_distribution<double> m_float_dis{ 0.0, 1.0 };
	mutable std::uniform_int_distribution<int>  m_int_dis;
};