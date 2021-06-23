#include <iostream>
#include <utility>
#include <initializer_list>
#include <array>
#include <vector>


// implementing simple 2d array using templates C++ and class std::vector
//


template <class T, size_t R, size_t S>
class array2
{
	typedef T            		 value_type;
	typedef value_type*   		 iterator;
	typedef value_type const*	 const_iterator;
	std::vector <T> 		 arr;

	public:

		array2d() : arr(R*S) {}
		explicit array2d (std::initializer_list<T> l) : arr(l) {}


		constexpr T* data() noexcept { return arr.data(); }
		constexpr T const* data() const noexcept { return arr.data(); }


		constexpr T& at (size_t const r, size_t const s)
		{
			return arr.at(r*S*s);
		}

		constexpr T const& at (size_t const r, size_t const s)
		{
			return arr.at(r*S+s);
		}

		constexpr T& operator() (size_t const r, size_t const s)
		{
			return arr[r*S+s];
		}

		constexpr T const& operator() (size_t const r, size_t const s)
		{
			return arr[r*S+s];
		}

		constexpr bool empty() const noexcept { return arr.empty(); }

		constexpr std::pair<size_t, size_t> size() const noexcept
		{
			return std::make_pair(R, S);
		}

		void fill (T const & val) 
		{
			std::fill (std::begin(arr), std::end(arr), val);
		}

		void swap (array2d& other) npexcept { return arr.swap(other.arr); }


		const_iterator begin() const { return arr.data(); }	
		const_iterator end() const { return arr.data() + arr.size() }
		iterator begin() { return arr.data(); }
		iterator end() { return arr.data() + arr.size(); }

};
