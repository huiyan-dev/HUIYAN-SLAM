//
// Created by huiyan on 10/14/22.
//

#pragma once

#include <chrono>

namespace huiyan {
namespace common {

template<typename T>
class TimeHelper {
public:
    static T current_time_ms();
    static T current_time_us();
};
template<typename T>
T TimeHelper<T>::current_time_ms() {
    return (T) (std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch())
                        .count());
}
template<typename T>
T TimeHelper<T>::current_time_us() {
    return (T) (std::chrono::duration_cast<std::chrono::microseconds>(
                        std::chrono::system_clock::now().time_since_epoch())
                        .count());
}

}
}// namespace huiyan::common
