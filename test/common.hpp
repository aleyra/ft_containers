#pragma once

#ifdef USE_STD
	#include <vector>
	#include <map>
	namespace curr = std;
#else
	#include "vector.hpp"
	#include "map.hpp"
	namespace curr = ft;
#endif

#include <iostream>
#include <string>

class ComplexType {
	public:
		ComplexType() {
			std::cout << "Type has been constructed" << std::endl;
		}
		ComplexType& operator=(const ComplexType& other) {
			for (int i = 0; i < 16; ++i) {
				this->storage[i] = other.storage[i];
			}
			return *this;
		}

		int storage[16];
};
