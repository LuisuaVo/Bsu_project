#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../boostl3/boostl3.cpp"


BOOST_AUTO_TEST_CASE(myTestCase)
{
	BOOST_TEST(1 == 1);
	BOOST_TEST(true);
}