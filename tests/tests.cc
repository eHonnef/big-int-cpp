#define CATCH_CONFIG_MAIN
#include "../src/big-int.cc"
#include <catch.hpp>

TEST_CASE("BigNumber class", "BigNumber class") {
  BigNumber D{};
  BigNumber A = BigNumber("68");
  BigNumber B = BigNumber("53");

  REQUIRE(A.to_string() == "68");
  REQUIRE(B.to_string() == "53");
  REQUIRE(D.to_string() == "0");
}

TEST_CASE("Basic operations", "Basic operations") {
  BigInt A = BigInt("168", opBasic);
  BigInt B = BigInt("79", opBasic);
  BigInt C;

  // Sum
  C = A + B;
  REQUIRE(C.to_string() == "247");

  // Sub
  C = A - B;
  REQUIRE(C.to_string() == "89");
}