//
// Created by huiyan on 10/14/22.
//

#include "common/functions.hpp"
#include <glog/logging.h>
namespace huiyan {
namespace common {

// note : theses inline function for a convenient method of statistic of runtime
// cost of all executors.
template<typename T>
inline void LOG_INFO_NOINPUT(const std::string &name) {
  LOG(INFO) << "No input for " << name << " at time(ms)" << TimeHelper<T>::current_time_ms << ", sleep a cycle.";
}
inline void LOG_INFO_SIZE(const std::string &name, const size_t &count) {
  LOG(INFO) << "The size of object " << name << " is " << count << " .";
}
inline void LOG_INFO_COST(const std::string &name, const size_t &count, const std::string &unit) {
  LOG(INFO) << "The process of object " << name << " cost " << count << " " << unit << " .";
}
} // namespace common
} // namespace huiyan
