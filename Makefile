CATCH_URL = https://raw.githubusercontent.com/CatchOrg/Catch2/master/single_include/catch.hpp
CC = g++

.PHONY: all test

all: test

test:
	@curl $(CATCH_URL) -so test/catch.hpp
	$(CC) -std=c++1z -Wall -Wextra -Werror test/Spec.cpp -o Spec
	./Spec -s
