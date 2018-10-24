#include "neural_network.h"

#include <ctime>



NeuralNetwork::NeuralNetwork(uint32_t inputnodes, uint32_t hiddennodes, uint32_t outputnodes, double learningrate) :
	inodes_(inputnodes),
	hnodes_(hiddennodes),
	onodes_(outputnodes),
	learningrate_(learningrate),
	wih(hiddennodes, inputnodes),
	who(outputnodes, hiddennodes)
{
	for (int i = 0; i < hiddennodes; ++i)
	{
		for (int j = 0; j < inputnodes; ++j)
		{
			wih(i, j) = getRandom(-0.5, 0.5);
		}
	}
	for (int i = 0; i < outputnodes; ++i)
	{
		for (int j = 0; j < hiddennodes; ++j)
		{
			who(i, j) = getRandom(-0.5, 0.5);
		}
	}
};

void NeuralNetwork::train(const VectorXd& inputs, const VectorXd& targets)
{
	VectorXd hidden_inputs = wih * inputs;
	VectorXd hidden_outputs = sigmoid(hidden_inputs);

	VectorXd final_inputs = who * hidden_outputs;
	VectorXd final_outputs = sigmoid(final_inputs);

	VectorXd output_errors = targets - final_outputs;
	VectorXd hidden_errors = who.transpose() * output_errors;




	who += (learningrate_ * (output_errors.array()*final_outputs.array()*(VectorXd::Constant(final_outputs.size(),1.0) - final_outputs).array())).matrix()*hidden_inputs.transpose();
	wih += (learningrate_ * (hidden_errors.array()*hidden_outputs.array()*(VectorXd::Constant(hidden_outputs.size(), 1.0) - hidden_outputs).array())).matrix()*inputs.transpose();
}

VectorXd NeuralNetwork::query(const VectorXd& inputs) const
{
	VectorXd hidden_inputs = wih * inputs;
	VectorXd hidden_outputs = sigmoid(hidden_inputs);

	VectorXd final_inputs = who * hidden_outputs;
	VectorXd final_outputs = sigmoid(final_inputs);

	return final_outputs;
}


