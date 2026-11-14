#define BOOST_TEST_MODULE laba3_tests
#include <boost/test/included/unit_test.hpp>
#include "../boostl3/boostl3.cpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename F>
string capture_cout(F f)
{
    ostringstream oss;
    streambuf* old = cout.rdbuf(oss.rdbuf());
    f();
    cout.rdbuf(old);
    return oss.str();
}


BOOST_AUTO_TEST_CASE(minEl_t) 
{
    int a1[] = { 1, 23, 45, 7, -12, 100 };
    BOOST_TEST(minEl(a1, 6) == 23);

    int a2[] = { 1, 2, 100, 0, -5 };
    BOOST_TEST(minEl(a2, 5) == 0);

    int a3[] = { 99, 10, -99, 1000 };
    BOOST_TEST(minEl(a3, 4) == -99);

    int a4[] = { -9, 9, 0 };
    BOOST_TEST(minEl(a4, 3) == 0);

    int a5[] = { 50, 10, 99 };
    BOOST_TEST(minEl(a5, 3) == 10);
}


BOOST_AUTO_TEST_CASE(sum_do_nul_t) 
{

    int a1[] = { 1, 2, 3, 0, 4, 5 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a1, 6); }) == "Summa do null: 6\n");
     
    int a2[] = { 1, 2, 3, 0, 4, 0, 5 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a2, 7); }) == "Summa do null: 10\n");

    int a3[] = { 1, 2, 3 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a3, 3); }) == "Summ doesn't exist\n");

    int a4[] = { 5, 6, 0 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a4, 3); }) == "Summa do null: 11\n");

    int a5[] = { 0, 1, 2 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a5, 3); }) == "Summ doesn't exist\n");

    int a6[] = { 0, 0, 0 };
    BOOST_TEST(capture_cout([&] { sum_do_nul(a6, 3); }) == "Summa do null: 0\n");

}


BOOST_AUTO_TEST_CASE(krat_t)
{
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    krat(a1, 9);
    int e1[] = { 1, 4, 7, 2, 3, 5, 6, 8, 9 };
    for (int i = 0; i < 9; ++i) 
    {
        BOOST_TEST_CONTEXT("i = " << i)
        {
            BOOST_TEST(a1[i] == e1[i]);
        }
    }
    int a2[] = { 1, 2, 3, 4 };
    krat(a2, 4);
    int e2[] = { 1, 4, 2, 3 };
    for (int i = 0; i < 4; ++i)
    {
        BOOST_TEST(a2[i] == e2[i]);
    }
    int a3[] = { 10, 20, 30 };
    krat(a3, 3);
    BOOST_TEST(a3[0] == 10);
    BOOST_TEST(a3[1] == 20);
    BOOST_TEST(a3[2] == 30);

    int a4[] = { 7, 8 };
    krat(a4, 2);
    BOOST_TEST(a4[0] == 7);
    BOOST_TEST(a4[1] == 8);

    int a5[] = { 42 };
    krat(a5, 1);
    BOOST_TEST(a5[0] == 42);

    int a6[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    krat(a6, 10);
    int e6[] = { 1, 4, 7, 10, 2, 3, 5, 6, 8, 9 };
    for (int i = 0; i < 10; ++i) 
    {
        BOOST_TEST_CONTEXT("i = " << i) 
        {
            BOOST_TEST(a6[i] == e6[i]);
        }
    }
}


BOOST_AUTO_TEST_CASE(get_mass_t)
{
    int a[] = { 1, 2, 3 };
    BOOST_TEST(capture_cout([&] { get_mass(a, 3); }) == "1 2 3 ");
}
