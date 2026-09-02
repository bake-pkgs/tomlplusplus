# tomlplusplus — toml++ for bake

[toml++](https://github.com/marzer/tomlplusplus) 3.4.0, packaged for
[bake](https://github.com/Ariaszzzhc/bake). Header-only, requires C++17.

## Use

```bash
bake add https://github.com/bake-pkgs/tomlplusplus --tag v3.4.0 tomlplusplus
```

```toml
[dependencies]
tomlplusplus = { url = "https://github.com/bake-pkgs/tomlplusplus", tag = "v3.4.0" }
```

```cpp
#include <toml++/toml.hpp>
```

Nothing is vendored here: the pinned upstream release archive is fetched
and its `include/` is exposed as the public header root. License: MIT
(upstream).
