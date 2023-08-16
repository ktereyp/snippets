#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "aes.h"
#include <openssl/aes.h>

struct TestCase {

};

BOOST_FIXTURE_TEST_CASE(FirstDayEver, TestCase) {
    std::string key = "12345678901234567890123456789012";
    std::string plaintext = "hello world!" ;
    std::string ciphertext;
    int r = aes_encrypt(key, key.substr(0, AES_BLOCK_SIZE), plaintext, ciphertext);
    BOOST_ASSERT(r == 0);
}