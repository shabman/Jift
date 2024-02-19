#include "jift_util.hpp"
#include <boost/log/trivial.hpp>

int main(int argc, char* argv[]) {
    JIFT_LOG("Starting Compiler Tests with 0 failed tasks...", "")
    JIFT_LOG("Jift Compiler Testing", "")

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
}