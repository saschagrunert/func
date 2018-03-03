CATCH_URL = https://raw.githubusercontent.com/CatchOrg/Catch2/master/single_include/catch.hpp
CC = g++

.PHONY: all test

all: test

test:
	@if [ ! -f test/catch.hpp ]; then \
		curl $(CATCH_URL) -so test/catch.hpp ;\
	fi
	$(CC) -std=gnu++11 -Wall -Wextra -Werror test/Spec.cpp -o Spec
	./Spec -s
