#include "neural_network.h"
#include "parse_csv.h"


int main()
{
	constexpr uint32_t train_num = 100;        //数据组数
	constexpr uint32_t output_nodes = 10;
	constexpr uint32_t row = 28;
	constexpr uint32_t col = 28;
	constexpr uint32_t input_nodes = row * col;
	constexpr uint32_t hidden_nodes = 100;
	constexpr double learning_rate = 0.3;

	auto int_array = parseCsvInt("mnist_train_100.csv");

	std::vector<int> target_nums;                  //获得目标矢量集
	for (const auto& int_line : int_array)
	{
		target_nums.push_back(int_line[0]);
	}
	std::vector<VectorXd> target_vectors;                     
	for (int i = 0; i < train_num; ++i)
	{
		VectorXd v(output_nodes);
		for (int j = 0; j < output_nodes; ++j)
		{
			v(j) = 0.01;
		}
		v(target_nums[i]) = 0.99;
		target_vectors.push_back(v);
	}

	std::vector<VectorXd> train_vectors;
	for (const auto& int_line : int_array)
	{
		int size = int_line.size();
		VectorXd v(size - 1);
		for (int i = 0; i < size-1; ++i)
		{
			v(i) = transformDoubleFrom255To1(static_cast<double>(int_line[i + 1]));
		}
		train_vectors.push_back(v);
	}


	auto net = std::make_unique<NeuralNetwork>(input_nodes, hidden_nodes, output_nodes, learning_rate);



	for (int i = 0; i < train_num; ++i)
	{
		net->train(train_vectors[i], target_vectors[i]);
	//	std::cout << "finish " << i << " train" << std::endl;
	}

	/*                                                        使用训练集的一部分进行测试
	for (int i = 0; i < 10; ++i)
	{
		std::cout <<"true num is "<< int_array[i][0] << std::endl;

		auto v = net->query(train_vectors[i]);
		int size = v.size();
		int res = 0;
		double max_n = v[0];
		for (int j = 1; j < size; ++j)
		{
			if (v[j] > max_n)
			{
				max_n = v[j];
				res = j;
			}
		}
		std::cout << "cal result is " << res << std::endl << std::endl;
	}
	*/

	return 0;
}