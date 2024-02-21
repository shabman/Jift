#ifndef __JIFT_ASSERT_H__
#define __JIFT_ASSERT_H__

#include <string>
#include "log/jift_log.hpp"

void jift_assert(bool expected, const std::string& data, const std::string& msg) {
    if (expected) {
        JiftLogger::log(VERBOSE, data, false);
        JiftLogger::log(TEST_OK, msg, true);
    } else {
        JiftLogger::log(VERBOSE, data, false);
        JiftLogger::log(FATAL, "TEST FAILED", true);
    }
}

#endif /* __JIFT_ASSERT_H__ */