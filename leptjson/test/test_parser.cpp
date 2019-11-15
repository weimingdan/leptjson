#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("test1", "[func test]")
{
	REQUIRE(true);
}

TEST_CASE("test2", "[ttaa]")
{
	REQUIRE(true);
}


TEST_CASE("test_add", "[add]")
{
	int a = 1 + 2;
	REQUIRE(a == 3);
}

TEST_CASE("sub_test", "[sub]")
{
	int aa = 1;
	REQUIRE(aa == 1);
}