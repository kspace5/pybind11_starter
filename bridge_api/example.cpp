#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <string>
#include <map>
#include "utils.h"
#include "utils_xyz.h"
#include <iostream>

// ----------------
// Regular C++ code
// ----------------

// multiply all entries by 2.0
// input:  std::vector ([...]) (read only)
// output: std::vector ([...]) (new copy)
std::vector<double> modify(const std::vector<double>& input)
{
  std::vector<double> output;
  std::vector<int> ivec = qx::util::split_to_ints("12|2343|23434", '|');

  std::string str = xyz::util::ping("Anna");
  
  printf("ivec size: %d", (int)ivec.size());
  std::cout << "\nPING " << str << std::endl;
  
  std::transform(
    input.begin(),
    input.end(),
    std::back_inserter(output),
    [](double x) -> double { return x*x; }
  );

  // N.B. this is equivalent to (but there are also other ways to do the same)
  //
  // std::vector<double> output(input.size());
  //
  
  // for ( size_t i = 0 ; i < input.size() ; ++i )
  //   output[i] = 2. * input[i];

  return output;
}

// Custom test
std::vector<int> makeSquaresRange(int num)
{
	std::vector<int> output;

	for (int i = 0; i < num; i++) {
		output.push_back(i*i);
	}
	return output;
}

// Custom test
std::string helloString(std::string str)
{
	return "Hello world " + str;
}

// Custom test
std::map<std::string, int> makeSquareMap(int num)
{
	std::map<std::string, int> output;

	for (int i = 0; i < num; i++) {
		output[std::to_string(i)] = i*i;
	}
	return output;
}

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(example,m)
{
  m.doc() = "pybind11 example plugin";

  m.def("modify", &modify, "Multiply all entries of a list by 2.0");
  m.def("makeSquaresRange", &makeSquaresRange, "Make a range of squares");
  m.def("helloString", &helloString, "String test");
  m.def("makeSquareMap", &makeSquareMap, "Map test");
}
