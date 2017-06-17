#include "../Generator.h"
#include <sstream>

#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(GeneratorTests)

BOOST_AUTO_TEST_CASE(input_constructor_works)
{
    int argc = 4;
    const char *argv[] = { "name", "12345", "-L", "123" };
    Generator(std::make_unique<Input>(argc, argv));
    //BOOST_CHECK_EQUAL()
}
BOOST_AUTO_TEST_SUITE_END()
