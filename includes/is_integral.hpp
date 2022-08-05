#ifndef IS_INTEGRAL_H
# define IS_INTEGRAL_H
namespace ft{
	template <class T, T v>
	struct integral_constant{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;

		operator value_type() const throw(){return value;}//throw() to replace noexcept
		value_type operator()() const throw(){return value;}//idem
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template<class T>
	struct is_integral:public integral_constant<bool, false>{};

	template<>//because the function is still a template
	struct is_integral<bool>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<wchar_t>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<signed char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<short int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<long long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned short int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned long long int>:public integral_constant<bool, true>{};
	//const ver
	template<>
	struct is_integral<const bool>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const wchar_t>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const signed char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const short int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const long long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned char>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned short int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned long int>:public integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned long long int>:public integral_constant<bool, true>{};
}
#endif