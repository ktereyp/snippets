#define BOOST_TEST_MODULE json
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "json.h"

BOOST_AUTO_TEST_CASE(json_test)
{
    json();
    BOOST_TEST(true /* test assertion */ );
}