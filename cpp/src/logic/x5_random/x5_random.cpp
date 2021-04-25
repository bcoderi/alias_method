
#include "x5_random.h"

int CX5Random::Random()
{
	const size_t random_value = m_int_dis(m_gen);

	int idx = random_value % m_all_prob;
	int idx_lower = 0;
	int idx_upper = 0;
	for (size_t i = 0; i < m_probs.size(); i++)
	{
		idx_upper = idx_lower + m_probs[i];

		if (idx >= idx_lower && idx < idx_upper)
		{
			return m_values[i];
		}
		idx_lower = idx_upper;
	}
	return -1;
}
