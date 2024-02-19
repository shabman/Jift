#pragma once

#include <iostream>

#define JIFT_LOG(x, ...) std::cout << "[JIFT COMPILER TEST]: " << x << __VA_ARGS__ << std::endl;