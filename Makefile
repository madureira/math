# A sample Makefile for building Tests

# GoogleTest path dir.
GTEST_DIR = ./test/ext/googletest/googletest

# Where to find the code to test.
INCLUDES_DIR = ./include

# Where to find the tests code.
TESTS_DIR = ./test

# Test file names without .cpp extension.
TESTS = vec2_test vec3_test

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11 -I$(INCLUDES_DIR)

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS) clean

clean :
	rm -rf bin/
	mkdir bin/
	cp *.o bin/
	cp *.a bin/
	cp $(TESTS) bin/
	rm *.o *.a $(TESTS)

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


vec2_test.o :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/vec2_test.cpp

vec3_test.o :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/vec3_test.cpp

vec2_test : vec2_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

vec3_test : vec3_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@


test: vec2_test vec3_test clean
	./bin/vec2_test && \
	./bin/vec3_test
