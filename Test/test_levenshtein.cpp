#include <iostream>
#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>


#include "Levenshtein.hpp"

BOOST_AUTO_TEST_CASE(trying)
{

	std::string str;
	str = "matching";
	std::string str2("graph");
	std::string out;
	int dist = AASS::editdistance::levenshteinDistance(str2, str, out);
	BOOST_CHECK_EQUAL(dist, 7);
	dist = AASS::editdistance::levenshteinDistance("", "", out);
	BOOST_CHECK_EQUAL(dist, 0);
	
	
}
