#include <chrono>
#include <string>
#include <cstdint>

uint64_t inline get_time() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

void inline time_function(void (*function)(), const std::string &name) {
    printf("Running function `%s`: ", name.c_str());
    auto ms = get_time();
    function();
    printf("took %lu ms to complete.\n", get_time() - ms);
}
