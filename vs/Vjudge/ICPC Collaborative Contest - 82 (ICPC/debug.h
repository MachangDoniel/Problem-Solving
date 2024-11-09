#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <tuple>
#include <utility>

void debug_out() {
    std::cerr << std::endl;
}

template <typename T>
void debug_out(const T& value) {
    std::cerr << value << std::endl;
}

template <typename T>
void debug_out(const std::vector<T>& vec) {
    std::cerr << "[ ";
    for (const auto& v : vec) {
        std::cerr << v << " ";
    }
    std::cerr << "]" << std::endl;
}

template <typename T>
void debug_out(const std::set<T>& s) {
    std::cerr << "{ ";
    for (const auto& v : s) {
        std::cerr << v << " ";
    }
    std::cerr << "}" << std::endl;
}

template <typename T>
void debug_out(const std::unordered_set<T>& us) {
    std::cerr << "{ ";
    for (const auto& v : us) {
        std::cerr << v << " ";
    }
    std::cerr << "}" << std::endl;
}

template <typename K, typename V>
void debug_out(const std::map<K, V>& m) {
    std::cerr << "{ ";
    for (const auto& kv : m) {
        std::cerr << "[" << kv.first << ": " << kv.second << "] ";
    }
    std::cerr << "}" << std::endl;
}

template <typename K, typename V>
void debug_out(const std::unordered_map<K, V>& m) {
    std::cerr << "{ ";
    for (const auto& kv : m) {
        std::cerr << "[" << kv.first << ": " << kv.second << "] ";
    }
    std::cerr << "}" << std::endl;
}

template <typename T>
void debug_out(const std::list<T>& lst) {
    std::cerr << "( ";
    for (const auto& v : lst) {
        std::cerr << v << " ";
    }
    std::cerr << ")" << std::endl;
}

template <typename... Args>
void debug_out(const Args&... args) {
    (debug_out(args), ...);
}

#ifdef LOCAL
#define dbg(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


/*
// Debugging
// #define LOCAL
// #include "debug.h"
#define dbg(x)

*/