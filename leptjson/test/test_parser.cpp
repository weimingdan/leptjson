#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("test1", "[func test]")
{
	REQUIRE(true);
}

TEST_CASE("test2", "[ttaa]")
{
	REQUIRE(false);
}