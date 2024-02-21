/* 
 * This file is part of the JiftUI distribution (https://github.com/shabman/Jift.git)
 * Copyright (c) 2024 Mustafa Malik.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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