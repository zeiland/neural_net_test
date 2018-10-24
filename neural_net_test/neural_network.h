#pragma once

#include <Eigen/Dense>

#include "common.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class NeuralNetwork
{
public:
	NeuralNetwork(uint32_t inputnodes, uint32_t hiddennodes, uint32_t outputnodes,double learningrate);
	void train(const VectorXd& inputs, const VectorXd& targets);
	VectorXd query(const VectorXd& inputs) const;
	
	void show()
	{
		std::cout << wih << std::endl;
		std::cout << who;
	}
private:
	uint32_t inodes_;
	uint32_t hnodes_;
	uint32_t onodes_;
	double learningrate_;

	MatrixXd wih;
	MatrixXd who;
};