# math
A lightweight, dependency-free C/C++ mathematics library.

## How to use

Add the `math/include` directory to your include path.

```c
#include <math/vec2.h>

math::vec2 coordinates(10.0f, 15.0f);
coordinates.add(math::vec2(20.0f, 30.0f));

math::vec2 position(coordinates + math::vec2(1.0f, 2.0f));
```
