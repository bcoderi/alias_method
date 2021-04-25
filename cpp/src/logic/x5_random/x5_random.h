#pragma once

#include <random>

class CX5Random
{
public:
	CX5Random(const std::vector<int>& values, const std::vector<int>& probs)
		: m_values(values)
		, m_probs(probs)
		, m_int_dis(0, std::numeric_limits<int>::max())
	{
		std::vector<int>::const_iterator itr = probs.begin();
		for (; itr != probs.end(); ++itr)
		{
			m_all_prob += *itr;
		}
	}
public:
	int Random();
private:
	mutable std::random_device   m_rd;
	mutable std::mt19937         m_gen{ m_rd() };
	mutable std::uniform_int_distribution<int>  m_int_dis;
	std::vector<int> m_values;
	const std::vector<int> m_probs;
	int m_all_prob;
};
