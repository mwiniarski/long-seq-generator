#include "../Input.h"
#include <sstream>

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(InputTests)

BOOST_AUTO_TEST_CASE(input_constructor_works)
{
    int argc = 4;
    const char *argv[] = { "name", "12345", "-L", "123" };
    Input i(argc, argv);
    BOOST_CHECK_EQUAL(i.getReadsLength(), 123);
}

BOOST_AUTO_TEST_CASE(input_throws_exception_when_wrong_arguments)
{
    int argc = 4;
    const char *argv[] = { "name", "12345", "-L", "abc" };
    BOOST_CHECK_THROW(Input i(argc, argv), std::logic_error);
}

BOOST_AUTO_TEST_CASE(input_throws_exception_when_even_arguments)
{
    int argc = 3;
    const char *argv[] = { "name", "12345", "-L"};
    BOOST_CHECK_THROW(Input i(argc, argv), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(input_throws_exception_when_parameter_doesnt_exist)
{
    int argc = 4;
    const char *argv[] = { "name", "12345", "-F", "123"};
    BOOST_CHECK_THROW(Input i(argc, argv), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
