#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
    "one two one tho three\n"
    ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "0 0 1 0 0 "
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "She sells sea shells on the sea shore;\n"
            "The shells that she sells are sea shells I'm sure.\n"
            "So if she sells sea shells on the sea shore,\n"
            "I'm sure that the shells are sea shore shells.\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "0 0 0 0 0 0 1 0 0 1 0 0 1 0 2 2 0 0 0 0 1 2 3 3 1 1 4 0 1 0 1 2 4 1 5 0 0 "
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "aba aba; aba @?\""
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "0 0 1 0 "
    );
}
