#include "common.h"

double getRandom(double left, double right)
{
	static std::default_random_engine e(std::time(0));
	std::uniform_real_distribution<double> u(left, right);
	return u(e);
}

double sigmoid(double x)
{
	return (1 / (1 + exp(-x)));
}

VectorXd sigmoid(const VectorXd& xs)
{
	int size = xs.size();
	VectorXd ret(size);
	for (int i = 0; i < size; ++i)
	{
		ret(i) = sigmoid(xs(i));
	}
	return ret;
}

double transformDoubleFrom255To1(double x)  //将0到255转化为0.01到0.99
{
	return (x / 255.0*0.99) + 0.01;
}