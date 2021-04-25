
#include <queue>
#include "alias_method_mgr.h"

void CAliasMethodMgr::GenerateAliasTable(const std::vector<float>& probs, std::vector<std::pair<float, int> >& alias_table)
{
	int sz = probs.size();
	std::vector<std::pair<float, int>> alias(sz, { 0.f, std::numeric_limits<int>::max() });
	std::queue<int> small;
	std::queue<int> large;

	std::vector<float>::const_iterator itr_prob_first = probs.begin();
	for (int i = 0; itr_prob_first != probs.end(); ++itr_prob_first, ++i)
	{
		alias[i].first = sz * (*itr_prob_first);
		if (alias[i].first < 1.0)
		{
			small.push(i);
		}
		else
		{
			large.push(i);
		}
	}

	std::vector<float>::const_iterator itr_prob_second = probs.begin();
	for (int i = 0; itr_prob_second != probs.end(); ++itr_prob_second, ++i)
	{
		alias[i].first = sz * (*itr_prob_second);
		if (alias[i].first < 1.f)
		{
			small.push(i);
		}
		else
		{
			large.push(i);
		}
	}

	while (!small.empty() && !large.empty())
	{
		int s = small.front();
		int l = large.front();
		small.pop();
		large.pop();
		alias[s].second = l;
		alias[l].first -= (1.f - alias[s].first);

		if (alias[l].first < 1.f)
		{
			small.push(l);
		}
		else
		{
			large.push(l);
		}
	}

	alias_table = alias;
}

int CAliasMethodMgr::Random(const std::vector<std::pair<float, int> >& alias_table, const std::vector<int>& out_value)
{
	int idx = 1;	//	todo��һ�������
	if (1000.f/*todo �ڶ��������*/ >= alias_table[idx].first && alias_table[idx].second != std::numeric_limits<int>::max())
	{
		return out_value[alias_table[idx].second];
	}
	else
	{
		return out_value[idx];
	}

	return -1;
}
