
#include <vector>
#include <map>
#include <ctime>
#include <fstream>
#include "alias_method/alias_method.h"
#include "x5_random/x5_random.h"

void TestAliasMethod(const std::vector<int>& values, const std::vector<double>& probs);
void TestX5Random(const std::vector<int>& values, const std::vector<int>& probs);

int main()
{
	//	样本及概率设定
	std::vector<int> values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<double> probs{ 0.05, 0.05, 0.1, 0.2, 0.3, 0.02, 0.07, 0.19, 0.02 };
	std::vector<int> probs_x5{ 5000, 5000, 10000, 20000, 30000, 2000, 7000, 19000, 2000 };

	//	时间对比样本及概率设定
	std::vector<int> time_values;
	std::vector<double> time_probs;
	std::vector<int> time_probs_x5;
	for (int i = 1; i < 501; ++i)
	{
		time_values.push_back(i);
		if (i % 2)
		{
			time_probs.push_back(0.001);
			time_probs_x5.push_back(100);
		}
		else
		{
			time_probs.push_back(0.003);
			time_probs_x5.push_back(300);
		}
	}

	//	test alias
	//TestAliasMethod(values, probs);

	//	test x5
	//TestX5Random(values, probs_x5);


	//	test alias
	TestAliasMethod(time_values, time_probs);

	//	test x5
	TestX5Random(time_values, time_probs_x5);

	system("pause");

	return 0;
}

void TestAliasMethod(const std::vector<int>& values, const std::vector<double>& probs)
{
	//	alias table 构建
	CDiscreteRandomVariable drv(values, probs);
	
	//	数据输出
	int proc_num = 100;
	for (int i = 0; i < proc_num; ++i)
	{
		int do_num = 400000;	//	单次运行采样次数
		std::clock_t begin_time = std::clock();
		std::map<int, int> counter;
		for (int j = 0; j != do_num; ++j)
		{
			int x = drv.Random();
			++counter[x];
		}
		double use_time = std::clock() - begin_time;
		std::ofstream time_file("../bin/alias_method_time.txt", std::ios::app);
		time_file << i + 1 << "," << use_time << std::endl;

		std::ofstream do_file("../bin/alias_method_do.txt", std::ios::app);
		for (auto pair : counter)
		{
			if (do_file)
			{
				do_file << pair.first << "," << pair.second << std::endl;
			}
		}
		do_file.close();
	}
}

void TestX5Random(const std::vector<int>& values, const std::vector<int>& probs)
{
	//	alias table 构建
	CX5Random x5_random(values, probs);

	//	数据输出
	int proc_num = 100;
	for (int i = 0; i < proc_num; ++i)
	{
		int do_num = 400000;	//	单次运行采样次数
		std::clock_t begin_time = std::clock();
		std::map<int, int> counter;
		for (int j = 0; j != do_num; ++j)
		{
			int x = x5_random.Random();
			++counter[x];
		}
		double use_time = std::clock() - begin_time;
		std::ofstream time_file("../bin/x5_time.txt", std::ios::app);
		time_file << i + 1 << "," << use_time << std::endl;

		std::ofstream do_file("../bin/x5_do.txt", std::ios::app);
		for (auto pair : counter)
		{
			if (do_file)
			{
				do_file << pair.first << "," << pair.second << std::endl;
			}
		}
		do_file.close();
	}
}