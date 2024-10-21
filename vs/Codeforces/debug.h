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

// Base case: Ends recursion of variadic templates
void debug_out() {
    std::cerr << std::endl;
}

// Handling individual values
template <typename T>
void debug_out(const T& value) {
    std::cerr << value << std::endl;
}

// Specialized for pairs
template <typename T1, typename T2>
void debug_out(const std::pair<T1, T2>& p) {
    std::cerr << "(" << p.first << ", " << p.second << ")";
}

// Handling vectors
template <typename T>
void debug_out(const std::vector<T>& vec) {
    std::cerr << "[ ";
    for (const auto& v : vec) {
        debug_out(v);  // Recursive call to support nested containers
        std::cerr << " ";
    }
    std::cerr << "]" << std::endl;
}

// Handling sets
template <typename T>
void debug_out(const std::set<T>& s) {
    std::cerr << "{ ";
    for (const auto& v : s) {
        debug_out(v);  // Recursive call for elements
        std::cerr << " ";
    }
    std::cerr << "}" << std::endl;
}

// Handling unordered sets
template <typename T>
void debug_out(const std::unordered_set<T>& us) {
    std::cerr << "{ ";
    for (const auto& v : us) {
        debug_out(v);  // Recursive call for elements
        std::cerr << " ";
    }
    std::cerr << "}" << std::endl;
}

// Handling maps
template <typename K, typename V>
void debug_out(const std::map<K, V>& m) {
    std::cerr << "{ ";
    for (const auto& kv : m) {
        std::cerr << "["; 
        debug_out(kv.first);
        std::cerr << ": ";
        debug_out(kv.second);
        std::cerr << "] ";
    }
    std::cerr << "}" << std::endl;
}

// Handling unordered maps
template <typename K, typename V>
void debug_out(const std::unordered_map<K, V>& m) {
    std::cerr << "{ ";
    for (const auto& kv : m) {
        std::cerr << "["; 
        debug_out(kv.first);
        std::cerr << ": ";
        debug_out(kv.second);
        std::cerr << "] ";
    }
    std::cerr << "}" << std::endl;
}

// Handling lists
template <typename T>
void debug_out(const std::list<T>& lst) {
    std::cerr << "( ";
    for (const auto& v : lst) {
        debug_out(v);  // Recursive call for elements
        std::cerr << " ";
    }
    std::cerr << ")" << std::endl;
}

// Handling multisets
template <typename T>
void debug_out(const std::multiset<T>& ms) {
    std::cerr << "{ ";
    for (const auto& v : ms) {
        debug_out(v);  // Recursive call for elements
        std::cerr << " ";
    }
    std::cerr << "}" << std::endl;
}

// Variadic template to print multiple arguments
template <typename... Args>
void debug_out(const Args&... args) {
    (debug_out(args), ...);
}

// Debug macro
#ifdef LOCAL
#define dbg(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
