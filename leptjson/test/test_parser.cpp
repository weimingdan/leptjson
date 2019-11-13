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

TEST_CASE("test_add", "[add]")
{
	int a = 1 + 2;
	REQUIRE(a == 3);
}