# A sample Makefile for building Tests

# GoogleTest path dir.
GTEST_DIR = ./googletest

# Where to find the code to test.
INCLUDES_DIR = ./include

# Where to find the tests code.
TESTS_DIR = ./test

# Test file names without .cpp extension.
TESTS = vec2_test vec3_test vec4_test mat4_test funcs_test

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g --coverage -fprofile-arcs -ftest-coverage -Wall -Wextra -pthread -std=c++11 -I$(INCLUDES_DIR)

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

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

vec4_test.o :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/vec4_test.cpp

mat4_test.o :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/mat4_test.cpp

funcs_test.o :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTS_DIR)/funcs_test.cpp

vec2_test : vec2_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

vec3_test : vec3_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

vec4_test : vec4_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

mat4_test : mat4_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

funcs_test : funcs_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

all : $(TESTS) clean

clean :
	rm -rf bin/
	mkdir bin/
	cp *.o bin/
	cp *.a bin/
	cp $(TESTS) bin/
	rm *.o *.a $(TESTS)

build_tests : $(TESTS)

prepare_coverage : build_tests
	rm -rf coverage_bin
	mkdir coverage_bin
	cp *.gcno coverage_bin/
	rm *.gcno
	lcov -c -i -d ./coverage_bin -o ./base.info

test : prepare_coverage clean
	./bin/vec2_test && \
	./bin/vec3_test && \
	./bin/vec4_test && \
	./bin/mat4_test && \
	./bin/funcs_test

collect_coverage : test
	cp *.gcda coverage_bin/
	rm *.gcda
	lcov -c -d ./coverage_bin -o ./test.info

combine_coverages : collect_coverage
	lcov -a ./base.info -a ./test.info -o ./total.info

filter_coverage : combine_coverages
	lcov -r ./total.info 'test/*' '/usr/include/*' 'include/gtest/*' 'src/*' '*/math/test/*' -o ./coverage.info

coverage : filter_coverage
	rm -rf base.info bin coverage_bin base.info test.info total.info
