#include "../Input.h"
#include <sstream>

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(InputTests)

BOOST_AUTO_TEST_CASE(input_constructor_works)
{
    int argc = 3;
    const char *argv[3] = { "name", "-L", "123" };
    Input i(argc, argv);
    BOOST_CHECK_EQUAL(i.getReadsLength(), 123);
}

BOOST_AUTO_TEST_CASE(input_throws_exception_when_wrong_arguments)
{
    int argc = 3;
    const char *argv[3] = { "name", "-L", "abc" };
    BOOST_CHECK_THROW(Input i(argc, argv), std::logic_error);
}

BOOST_AUTO_TEST_CASE(input_throws_exception_when_odd_arguments)
{
    int argc = 2;
    const char *argv[3] = { "name", "-L"};
    BOOST_CHECK_THROW(Input i(argc, argv), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
