#pragma once
#include <vector>

template<typename type, typename type1>
auto initialize_vector(type value, type1 count) {
    return std::vector<typeof(value)>(count, value);
}

template<typename type, typename type1, typename ...Args>
auto initialize_vector(type value, type1 count, Args... args) {
    return std::vector<typeof(initialize_vector(value, args...))>
            (count, initialize_vector(value, args...));
}
