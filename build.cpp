import bake.build;
import std;

// tomlplusplus — toml++ for bake.
//
// Module strategy: compile upstream's own C++20 module file when the
// pinned release ships one (src/modules/tomlplusplus.cppm — upstream
// keeps it on master, unreleased as of 3.4.0); otherwise fall back to
// the local wrapper in module/ (trimmed to the release's API). The
// switch is automatic per upstream release.

int main() {
    bake::Builder b;
    namespace fs = std::filesystem;
    const auto upstream = std::string(b.dep_src_dir("upstream"));

    const fs::path upstream_module =
        fs::path(upstream) / "src/modules/tomlplusplus.cppm";
    if (fs::is_regular_file(upstream_module)) {
        b.include_dirs(upstream + "/include");
        b.public_modules(upstream_module.generic_string());
    } else {
        b.include_dirs(upstream + "/include");
        b.public_modules("module/*.cppm");
    }
    b.public_headers(upstream + "/include");
    return b.build();
}
