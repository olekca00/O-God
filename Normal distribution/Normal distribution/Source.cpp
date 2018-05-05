#include <iostream>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

int main(void)
{
	// This is the underlying integer random number generator
	boost::mt19937 igen;
	// The second template parameter is the actual floating point
	// distribution that the user wants
	boost::variate_generator<boost::mt19937, boost::normal_distribution<> >
		gen(igen,
			boost::normal_distribution<>(1, 0.1));

	const size_t n = 10;
	for (size_t i = 0; i<n; ++i)
	{
		std::cout << gen()
			<< std::endl;
	}

	system("pause");
}