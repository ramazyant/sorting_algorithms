#ifndef generator_h
#define generator_h

#include <vector>
#include <list>
#include <algorithm>

const int INT_RANGE = 1000000;

void intVectGen (std::vector<int> & arr, int new_size) {
    arr.resize(new_size);
    for (int i = 0; i < new_size; ++i) {
        arr[i] = std::rand() % INT_RANGE;
    }
}

void binVectGen (std::vector<int> & arr, int new_size) {
    arr.resize(new_size);
    for (int i = 0; i < new_size; ++i) {
        arr[i] = std::rand() % 2;
    }
}

void decVectGen (std::vector<int> & arr, int new_size) {
    arr.resize(new_size);
    for (int i = 0; i < new_size; ++i) {
        arr[i] = std::rand() % 10;
    }
}

void intListGen (std::list<int> & lst, std::vector<int> & arr) {
    lst.clear();
    for (long i = 0; i < arr.size(); ++i) {
        lst.insert(lst.begin(), arr[i]);
    }
}

#include <random>
#include <string>

std::string random_string(std::string::size_type length) {
    static auto & chrs = "0123456789"
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //
    thread_local static std::mt19937 rg{ std::random_device{}() };
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::string s;
    s.reserve(length);
    while(--length) {
        s += chrs[pick(rg)];
    }
    return s;
}

void strVectGen (std::vector<std::string> & arr, int new_size) {
    arr.resize(new_size);
    for (int i = 0; i < new_size; ++i) {
        arr[i] = random_string(10);
    }
}

void strListGen (std::list<std::string> & lst, std::vector<std::string> & arr) {
    lst.clear();
    for (long i = 0; i < arr.size(); ++i) {
        lst.insert(lst.begin(), arr[i]);
    }
}


#endif /* generator_h */
