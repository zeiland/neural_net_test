#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
#include <random>
#include <ctime>
#include <Eigen/Dense>
#include <memory>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::uint32_t;



double getRandom(double left, double right);
double sigmoid(double x);
VectorXd sigmoid(const VectorXd& xs);
double transformDoubleFrom255To1(double x);  //将0到255转化为0.01到0.99
