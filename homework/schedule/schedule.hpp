#pragma once
#include <chrono>
#include <functional>
#include <optional>
#include <string>
#include <thread>

template <typename Func, typename Time, typename... Args>
auto schedule(Func&& func, Time time, Args... args) {
    std::this_thread::sleep_for(time);
    std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
}

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
