#include <iostream>
#include <string>

#include "LFSR.cpp"

#define BOOST_TEST_STATIC_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
//using namespace boost::unit_test;
BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}
//Checks that null strings work
//in this case, all return values should be 0
BOOST_AUTO_TEST_CASE(smallStringWorks) {
  LFSR l1("", 2);
  BOOST_REQUIRE(l1.getTap() == 0);
  BOOST_REQUIRE(l1.getLFSR() == 0);
  BOOST_REQUIRE(l1.generate(100) == 0);
}

//Checks that strings with a length larger than the amount of bits in
//an int works. The test should pass because I store my data using a vector
BOOST_AUTO_TEST_CASE(largeStringWorks) {
  std::string str = "0";
  for (int i = 0; i < (int) sizeof(int) * 4; ++i){
  	str += "1";
  }
  LFSR l1(str, 2);
  BOOST_REQUIRE(l1.step() == 1);
  for (int i = 0; i < (int) sizeof(int) * 4; ++i){
  	BOOST_REQUIRE(l1.step() == 0);
  }
}
