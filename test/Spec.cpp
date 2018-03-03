// Copyright 2018 Sascha Grunert

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../include/Either.h"
#include "../include/Maybe.h"

SCENARIO("Maybe Data Type", "[Maybe]") {
    MAYBE_TYPE(int);

    GIVEN("A None Maybe value for integers") {
        Maybe(int) sut = Nothing(int);

        WHEN("checking the default value") {
            THEN("it should be nothing") {
                REQUIRE(isNothing(sut));
                REQUIRE_FALSE(isJust(sut));
            }
        }

        WHEN("retrieving the inner value") {
            int t = 1;
            fromJust(sut, t);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }

    GIVEN("A Just Maybe value for integers") {
        Maybe(int) sut = Just(int, 2);

        WHEN("checking the default value") {
            THEN("it should be nothing") {
                REQUIRE(isJust(sut));
                REQUIRE_FALSE(isNothing(sut));
            }
        }

        WHEN("retrieving the inner value") {
            int t = 0;
            fromJust(sut, t);

            THEN("it should succeed") {
                REQUIRE(t == 2);
            }
        }
    }
}

SCENARIO("Either Data Type", "[Either]") {
    EITHER_TYPE(int, char);

    GIVEN("A Left Either type for integers and chars") {
        Either(int, char) sut = Left(int, char, 0);

        WHEN("checking the default value") {
            THEN("it should be Left") {
                REQUIRE(isLeft(sut));
                REQUIRE_FALSE(isRight(sut));
            }
        }

        WHEN("retrieving the Left value") {
            int t = 1;
            fromLeft(sut, t);

            THEN("it should succeed") {
                REQUIRE(t == 0);
            }
        }

        WHEN("retrieving the Right value") {
            int t = 1;
            fromRight(sut, t);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }

    GIVEN("A Right Either type for integers and chars") {
        Either(int, char) sut = Right(int, char, 'c');

        WHEN("checking the default value") {
            THEN("it should be Right") {
                REQUIRE(isRight(sut));
                REQUIRE_FALSE(isLeft(sut));
            }
        }

        WHEN("retrieving the Right value") {
            char t = 'a';
            fromRight(sut, t);

            THEN("it should succeed") {
                REQUIRE(t == 'c');
            }
        }

        WHEN("retrieving the Left value") {
            int t = 1;
            fromLeft(sut, t);

            THEN("it should fail") {
                REQUIRE(t == 1);
            }
        }
    }
}
