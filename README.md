# math
A lightweight, dependency-free and header only C++ mathematics library.

[![circleci](https://img.shields.io/circleci/project/github/madureira/math/master.svg?style=popout)](https://circleci.com/gh/madureira/math/tree/master)
[![codecov](https://img.shields.io/codecov/c/github/madureira/math.svg?style=popout)](https://codecov.io/gh/madureira/math)
[![language](https://img.shields.io/badge/language-c++-blue.svg)](https://isocpp.org)

## How to use

You need just to add the `include` directory to your project's include path.

```c
#include <math/vec2.h>
#include <math/vec3.h>
#include <math/vec4.h>
#include <math/mat4.h>

math::vec2 coordinates(10.0f, 15.0f);
coordinates.add(math::vec2(20.0f, 30.0f));

math::vec4 position(coordinates + math::vec2(1.0f, 2.0f));
```

## Test

### Installing Google Test library

```sh
git submodule init
git submodule update
```

### Running all tests

```sh
make test
```
