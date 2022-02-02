cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

project (pubSub VERSION 1.0)

add_executable(pubSub 
            main.cpp
            Broker.cpp
            Subscriber.cpp
            Publisher.cpp)

target_include_directories(pubSub 
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
