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

#include "jift_util.hpp"

#include "lexer/package/jift_test_package.h"
#include "lexer/comments/jift_test_comments.h"

int main(int argc, char* argv[]) {
    
    JiftLogger::log(ALERT, "[Jift Compiler Tests]: Starting Tests...", true);

    JiftLogger::log(ALERT, "[Jift Compiler Tests]: Checking Packages...\n", true);
    __jift_test_package();

    JIFT_ELOG();
    JiftLogger::log(ALERT, "[Jift Compiler Tests]: Checking comments...\n", true);
    __jift_test_comments();
}