#include <iostream>
#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>


#include "NormalizedEditDistance.hpp"

void print(std::deque<int> i){
	for(auto it = i.begin() ; it != i.end() ; ++it){
		std::cout << *it << " " ;
	}
}

bool compareInt(int i, int j)
{
	std::cout << "comapring " << i << " and " << j << " gives " << (bool)(i == j) << std::endl;
    return i == j;
}

BOOST_AUTO_TEST_CASE(trying)
{

	std::deque<int> str;
	std::deque<int> str2; str2.push_back(1);
	std::string out;
	std::function<bool(int, int)> compareFunction = compareInt;
	double dist = AASS::editdistance::normalizedEditDistance< int, int >(str2, str, compareFunction, out);
	BOOST_CHECK_EQUAL(dist, 1);
	
	str2.push_back(1);
	dist = AASS::editdistance::normalizedEditDistance< int, int >(str2, str, compareFunction, out);
	BOOST_CHECK_EQUAL(dist, 1);
	std::cout << "Todo : " << out << " dist " << dist << std::endl;
	
	str.push_back(1);
	dist = AASS::editdistance::normalizedEditDistance< int, int >(str2, str, compareFunction, out);
	BOOST_CHECK_EQUAL(dist, 0.5);
	std::cout << "Todo : " << out << " dist " << dist << std::endl;
	
	
	str.push_back(2);
	std::cout << "FINAL" << std::endl;
	dist = AASS::editdistance::levenshteinDistance< int, int >(str2, str, compareFunction, out);
	BOOST_CHECK_EQUAL(dist, 1);
	std::cout << "Todo : " << out << " dist " << dist << " for " << std::endl;
	print(str);
	std::cout << std::endl;
	print(str2);
// 	dist = AASS::editdistance::normalizedEditDistance("", "", out);
// 	BOOST_CHECK_EQUAL(dist, 0);
// 	
// 	std::string str_n("");
// 	std::string str_n2("b");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n, str_n2, out);
// 	BOOST_CHECK_EQUAL(dist, 1);
// 	
// 	std::string str_n3("a");
// 	std::string str_n4("ab");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n3, str_n4, out);
// 	std::cout << "Dist 0,5 : " << dist << std::endl; 
// 	BOOST_CHECK_EQUAL(dist, 0.5);
// 	
// 	std::string str_n5("a");
// 	std::string str_n6("abb");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n5, str_n6, out);
//  	double bob = ((double) 2/ (double) 3);
// 	BOOST_CHECK_EQUAL(dist, bob);
// 	
// 	std::string str_n7("ab");
// 	std::string str_n8("abb");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n7, str_n8, out);
//  	bob = ((double) 2/ (double) 6);
// 	BOOST_CHECK_EQUAL(dist, bob);
// 	
// 	std::string str_n9("je");
// 	std::string str_n10("jj");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n9, str_n10, out);
//  	bob = 1;
// 	BOOST_CHECK_EQUAL(dist, bob);
// 	
// 	std::string str_n11("je");
// 	std::string str_n12("ej");
// 	dist = AASS::editdistance::normalizedEditDistance(str_n11, str_n12, out);
//  	bob = 1;
// 	BOOST_CHECK_EQUAL(dist, bob);
// 	
// 	std::string str_n13("jjj");
// 	std::string str_n14("jjj");
// 	std::string uu;
// 	dist = AASS::editdistance::normalizedEditDistance(str_n13, str_n14, uu);
//  	bob = 0;
// 	BOOST_CHECK_EQUAL(uu, "nnn");
// 	BOOST_CHECK_EQUAL(dist, bob);
}

