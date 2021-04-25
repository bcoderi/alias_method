
#include <fstream>
#include <ctime>
#include "alias_method.h"

/*
	À„∑® µœ÷
*/
std::vector<std::pair<double, int>> CDiscreteRandomVariable::GenerateAliasTable(const std::vector<double>& probs)
{
	const int sz = probs.size();
	std::vector<std::pair<double, int>> alias(sz, { 0.0, std::numeric_limits<int>::max() });
	std::queue<int> small, large;

	for (int i = 0; i != sz; ++i)
	{
		alias[i].first = sz * probs[i];
		if (alias[i].first < 1.0)
		{
			small.push(i);
		}
		else
		{
			large.push(i);
		}
	}

	while (not(small.empty()) and not(large.empty()))
	{
		auto s = small.front(), l = large.front();
		small.pop(), large.pop();
		alias[s].second = l;
		alias[l].first -= (1.0 - alias[s].first);

		if (alias[l].first < 1.0)
		{
			small.push(l);
		}
		else
		{
			large.push(l);
		}
	}

	return alias;
}

int CDiscreteRandomVariable::Random()
{
	int idx = m_int_dis(m_gen);
	if (m_float_dis(m_gen) >= m_alias[idx].first and m_alias[idx].second != std::numeric_limits<int>::max())
	{
		return m_out_values[m_alias[idx].second];
	}
	else
	{
		return m_out_values[idx];
	}
}
