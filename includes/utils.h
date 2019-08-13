#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <map>
#include <vector>
#include <string>

#include <sstream>

using namespace std;

namespace qx {
	namespace util {

		//
		// STRING UTILS
		//

		// Splits line into a vector or ints
		vector<int> split_to_ints(string str, char delimiter);

		// Splits line into a vector or floats
		vector<float> split_to_floats(string str, char delimiter);

	}
}

#endif