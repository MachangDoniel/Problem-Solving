#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>

// Base case: Ends recursion of variadic templates
void debug_out() {
    std::cerr << std::endl;
}

// Handling individual values
template <typename T>
void debug_out(const T& value) {
    std::cerr << value;
}

// Specialized for pairs
template <typename T1, typename T2>
void debug_out(const std::pair<T1, T2>& p) {
    std::cerr << "(";
    debug_out(p.first);
    std::cerr << ", ";
    debug_out(p.second);
    std::cerr << ")";
}

// Handling tuples
template <typename Tuple, std::size_t... Is>
void print_tuple(const Tuple& t, std::index_sequence<Is...>) {
    ((std::cerr << (Is == 0 ? "" : ", "), debug_out(std::get<Is>(t))), ...);
}

template <typename... Args>
void debug_out(const std::tuple<Args...>& t) {
    std::cerr << "(";
    print_tuple(t, std::index_sequence_for<Args...>{});
    std::cerr << ")";
}

// Handling vectors
template <typename T>
void debug_out(const std::vector<T>& vec) {
    std::cerr << "[ ";
    for (const auto& v : vec) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << "]";
}

// Handling deques
template <typename T>
void debug_out(const std::deque<T>& deq) {
    std::cerr << "[ ";
    for (const auto& v : deq) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << "]";
}

// Handling lists
template <typename T>
void debug_out(const std::list<T>& lst) {
    std::cerr << "( ";
    for (const auto& v : lst) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << ")";
}

// Handling sets
template <typename T>
void debug_out(const std::set<T>& s) {
    std::cerr << "{ ";
    for (const auto& v : s) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << "}";
}

// Handling unordered sets
template <typename T>
void debug_out(const std::unordered_set<T>& us) {
    std::cerr << "{ ";
    for (const auto& v : us) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << "}";
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
    std::cerr << "}";
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
    std::cerr << "}";
}

// Handling multisets
template <typename T>
void debug_out(const std::multiset<T>& ms) {
    std::cerr << "{ ";
    for (const auto& v : ms) {
        debug_out(v);
        std::cerr << " ";
    }
    std::cerr << "}";
}

// Handling stacks (requires a copy for iteration)
template <typename T>
void debug_out(std::stack<T> s) {
    std::cerr << "( ";
    while (!s.empty()) {
        debug_out(s.top());
        s.pop();
        if (!s.empty()) std::cerr << ", ";
    }
    std::cerr << " )";
}

// Handling queues (requires a copy for iteration)
template <typename T>
void debug_out(std::queue<T> q) {
    std::cerr << "< ";
    while (!q.empty()) {
        debug_out(q.front());
        q.pop();
        if (!q.empty()) std::cerr << ", ";
    }
    std::cerr << " >";
}

// Handling priority queues (requires a copy for iteration)
template <typename T>
void debug_out(std::priority_queue<T> pq) {
    std::cerr << "< ";
    while (!pq.empty()) {
        debug_out(pq.top());
        pq.pop();
        if (!pq.empty()) std::cerr << ", ";
    }
    std::cerr << " >";
}

// Variadic template to print multiple arguments
template <typename... Args>
void debug_out(const Args&... args) {
    (debug_out(args), ...);
}

// Debug macro
#ifdef LOCAL
#define dbg(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__), std::cerr << std::endl
#else
#define dbg(...)
#endif
