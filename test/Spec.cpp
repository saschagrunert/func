// Copyright 2018 Sascha Grunert

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/Func.h"

MAYBE(int, foo);

SCENARIO("Maybe Data Type", "[Maybe]") {
    GIVEN("A None Maybe value for integers") {
        Maybe(foo) sut = Nothing_foo();

        WHEN("checking the default value") {
            THEN("it should be nothing") {
                REQUIRE(isNothing(sut));
                REQUIRE_FALSE(isJust(sut));
            }
        }

        WHEN("retrieving the inner value") {
            int t = fromMaybe(1, sut);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }

    GIVEN("A Just Maybe value for integers") {
        Maybe(foo) sut = Just_foo(2);

        WHEN("checking the default value") {
            THEN("it should be nothing") {
                REQUIRE(isJust(sut));
                REQUIRE_FALSE(isNothing(sut));
            }
        }

        WHEN("retrieving the inner value") {
            int t = fromMaybe(0, sut);

            THEN("it should succeed") {
                REQUIRE(t == 2);
            }
        }
    }
}

EITHER(int, foo, char, bar);

SCENARIO("Either Data Type", "[Either]") {
    GIVEN("A Left Either type for integers and chars") {
        Either(foo, bar) sut = Left_foo_bar(0);

        WHEN("checking the default value") {
            THEN("it should be Left") {
                REQUIRE(isLeft(sut));
                REQUIRE_FALSE(isRight(sut));
            }
        }

        WHEN("retrieving the Left value") {
            int t = fromLeft(1, sut);

            THEN("it should succeed") {
                REQUIRE(t == 0);
            }
        }

        WHEN("retrieving the Right value") {
            int t = fromRight(1, sut);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }

    GIVEN("A Right Either type for integers and chars") {
        Either(foo, bar) sut = Right_foo_bar('c');

        WHEN("checking the default value") {
            THEN("it should be Right") {
                REQUIRE(isRight(sut));
                REQUIRE_FALSE(isLeft(sut));
            }
        }

        WHEN("retrieving the Right value") {
            char t = fromRight('a', sut);

            THEN("it should succeed") {
                REQUIRE(t == 'c');
            }
        }

        WHEN("retrieving the Left value") {
            int t = fromLeft(1, sut);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }
}
