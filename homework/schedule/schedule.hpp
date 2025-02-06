#pragma once

#include <chrono>
#include <thread>
#include <functional>

auto schedule(std::function<void()> func,  std::chrono::seconds time) {
    std::this_thread::sleep_for(time);
    func();
}