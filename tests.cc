#include "lib_playlist.h"

#define BOOST_TEST_MODULE tests

#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <memory>

struct cout_redirect {
    explicit cout_redirect(std::streambuf *new_buffer) : old(std::cout.rdbuf(new_buffer)) {}

    ~cout_redirect() {
        std::cout.rdbuf(old);
    }

private:
    std::streambuf *old;
};

BOOST_AUTO_TEST_SUITE(lib_playlist)


BOOST_AUTO_TEST_SUITE_END()
