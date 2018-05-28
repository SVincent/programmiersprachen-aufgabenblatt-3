#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

TEST_CASE (" filter alle vielfache von drei ", "[ erase ]") {
// ihre Loesung :
// ...
REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]) {
return Catch :: Session (). run(argc , argv );
}
