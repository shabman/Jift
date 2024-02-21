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

#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#define JIFT_LOG(x, ...) std::cout << "[JIFT COMPILER TEST]: " << x << __VA_ARGS__ << std::endl;
#define JIFT_ELOG() std::cout << "\n";

#define JIFT_SLEEP_MS(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms))