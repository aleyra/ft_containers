#include "../common.hpp"

template<class T>
class NoAllocator : public std::allocator<T> {
	public:
	typedef size_t size_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ptrdiff_t difference_type;

	size_type max_size() const {
		return 10;
	}
};

int main()
{
	curr::vector<int> int_vec1(30, 42);
	curr::vector<double> int_vec2(30, 42.0);
	curr::vector<char> int_vec3(29, 42);
	curr::vector<unsigned char> int_vec4(31, 42);
	curr::vector<long long> int_vec5(30, 41);

	std::cout << int_vec1.max_size() << std::endl;
	std::cout << int_vec2.max_size() << std::endl;
	std::cout << int_vec3.max_size() << std::endl;
	std::cout << int_vec4.max_size() << std::endl;

	try {
		curr::vector< int, NoAllocator<int> > int_vec_wrong(30, 42, NoAllocator<int>());
		std::cout << "No max_size() exception thrown" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception thrown, as expected" << std::endl;
	}

	try {
		curr::vector< int, NoAllocator<int> > int_vec_wrong1((NoAllocator<int>()));
		std::cout << "max_size(): " << int_vec_wrong1.max_size() << std::endl;
		for (int i = 0; i < 100; ++i) {
			int_vec_wrong1.push_back(i);
			std::cout << i << std::endl;
		}
		std::cout << "No max_size() exception thrown" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception thrown, as expected" << std::endl;
	}

	return 0;
}
