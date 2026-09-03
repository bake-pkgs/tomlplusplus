import bake.build;
import std;

int main() {
    bake::Builder b;
    const auto upstream = std::string(b.dep_src_dir("upstream"));
    b.include_dirs(upstream + "/include");
    b.public_headers(upstream + "/include");
    b.public_modules("module/*.cppm");
    return b.build();
}
