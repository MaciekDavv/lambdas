cmake_minimum_required(VERSION 3.10)
project(schedule)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

add_executable(${PROJECT_NAME}-ut tests/tests.cpp)
target_link_libraries(${PROJECT_NAME}-ut PRIVATE Catch2::Catch2WithMain)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Werror -Wpedantic)

add_executable(${PROJECT_NAME}-ut-bonus tests/tests-bonus.cpp)
target_compile_options(${PROJECT_NAME}-ut-bonus PRIVATE -Wall -Wextra -Werror -Wpedantic)
target_link_libraries(${PROJECT_NAME}-ut-bonus PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME schedule-tests COMMAND ${PROJECT_NAME}-ut)
