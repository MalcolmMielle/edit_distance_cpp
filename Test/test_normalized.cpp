#include <iostream>
#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>


#include "NormalizedEditDistance.hpp"

BOOST_AUTO_TEST_CASE(trying)
{

	std::string str;
	str = "matching";
	std::string str2("matching");
	std::string out;
	double dist = AASS::editdistance::normalizedEditDistance(str2, str, out);
	BOOST_CHECK_EQUAL(dist, 0);
	dist = AASS::editdistance::normalizedEditDistance("", "", out);
	BOOST_CHECK_EQUAL(dist, 0);
	
	std::string str_n("a");
	std::string str_n2("b");
	dist = AASS::editdistance::normalizedEditDistance(str_n, str_n2, out);
	BOOST_CHECK_EQUAL(dist, 1);
	
	std::string str_n3("a");
	std::string str_n4("ab");
	dist = AASS::editdistance::normalizedEditDistance(str_n3, str_n4, out);
	std::cout << "Dist 0,5 : " << dist << std::endl; 
	BOOST_CHECK_EQUAL(dist, 0.5);
	
	std::string str_n5("a");
	std::string str_n6("abb");
	dist = AASS::editdistance::normalizedEditDistance(str_n5, str_n6, out);
 	double bob = ((double) 2/ (double) 3);
	BOOST_CHECK_EQUAL(dist, bob);
	
	std::string str_n7("ab");
	std::string str_n8("abb");
	dist = AASS::editdistance::normalizedEditDistance(str_n7, str_n8, out);
 	bob = ((double) 2/ (double) 6);
	BOOST_CHECK_EQUAL(dist, bob);
}
