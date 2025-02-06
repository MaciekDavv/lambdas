#pragma once

#include <chrono>
#include <thread>
#include <functional>
#include <optional>
#include <string>

auto schedule(std::function<void()> func,
              std::chrono::seconds time) {
    std::this_thread::sleep_for(time);
    func();
}

auto schedule(std::function<void(int)> func,
              std::chrono::seconds time,
              int notUse) {
    std::this_thread::sleep_for(time);
    func(notUse);
}

auto schedule(std::function<void(std::string, double)> func,
                                 std::chrono::seconds time,
                                 std::string notUseString,
                                 double notUseDouble) {
    std::this_thread::sleep_for(time);
    func(notUseString, notUseDouble);
}