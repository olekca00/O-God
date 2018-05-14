/*
#include <iostream>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include<boost/math/distributions/normal.hpp>
using namespace boost::math;

int main(void)
{
	double mean_life = 80.;
	double life_standard_deviation = 10.;
	normal bulbs(mean_life, life_standard_deviation);
	double expected_life = 100.;

	std::cout << "Fraction of bulbs that will last at best [<=] " // P(X <= 60)
		<< expected_life << " is " << cdf(bulbs, expected_life) << std::endl;
	std::cout << "Fraction of bulbs that will last at least [>] " // P(X > 60)
		<< expected_life << " is " << cdf(complement(bulbs, expected_life)) << std::endl;

	double min_life = 70;
	double max_life = 100;
	std::cout << "Fraction of bulbs that will last between "
		<< min_life << " and " << max_life << " is "
		<< cdf(bulbs, max_life) // P(X <= 100)
		- cdf(bulbs, min_life) << std::endl; // P(X <= 70)

	system("pause");
}
*/


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
			boost::normal_distribution<>(0,1));

	const size_t n = 10;
	for (size_t i = 0; i<n; ++i)
	{
		std::cout << gen()
			<< std::endl;
	}

	system("pause");
}