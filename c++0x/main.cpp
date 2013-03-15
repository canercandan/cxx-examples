// http://www2.research.att.com/~bs/C++0xFAQ.html#think

#include <iostream>
#include <vector>
#include <initializer_list>
#include <tuple>
#include <parallel/parallel.h>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>

// export LD_LIBRARY_PATH=:/home/caner/Downloads/gcc-4.6.0/install/lib64
// ~/Downloads/gcc-4.6.0/install/bin/g++ -std=c++0x main.cpp && a.out

enum class Color : char;

void f(const std::initializer_list<int>& args)
{
    //for (auto p=args.begin(); p!=args.end(); ++p) std::cout << *p << "\n";
    for (auto& x : args) std::cout << x << "\n";
}

int f2() { return 12; }

// std::string operator""s (const char* p, size_t n)	// std::string literal
// {
//     return std::string(p,n);	// requires free store allocation
// }

enum class Color : char { red, blue };

enum Flags : char { good=0, fail=1, bad=2, eof=4 };

// class X {
//     int a;
// public:
//     X(int x) { if (0<x) a=x; }
//     X() :X{42} { }
// };

// class A
// {
// public:
//     A() {}
//     A(int a_val) : a(a_val) {}
//     //A(D d) : b(g(d)) {}
//     int a = 7;
//     int b = 5;
// private:
//     //HashingFunction hash_algorithm{"MD5"};  // Cryptographic hash to be applied to all A instances
//     std::string s{"Constructor run"};       // String indicating state in object lifecycle
// };

typedef int X;

void f(std::vector<X>& v)
{
    struct Less {
	bool operator()(const X& a, const X& b) { return a<b; }
    };
    std::sort(v.begin(), v.end(), Less());	// C++98: error: Less is local
    // C++11: ok
}

int main(void)
{
    // X xaa1;

    std::vector< int > vec = {0, 1, 2, 3};

    std::vector<std::vector<int>> vec2;

    for (auto it = vec.begin(); it != vec.end(); ++it)
	{

	}

    for ( auto& x : vec ) { std::cout << x << std::endl; };

    for (const auto x : { 1,2,3,5,8,13,21,34 }) std::cout << x << '\n';

    Color c = Color::red;

    constexpr int x1 = bad|eof;
    constexpr int x2 = bad;

    auto a1 = 12;

    decltype(a1) a2 = 45;

    std::vector< double > v1 = {7};

    f({1,2,3});

    std::tuple< int, double, char, int, double, char, int, double, char, int, double, char, int, double, char, int, double, char, int, double, char, int, double, char, int, double, char, int, double, char > tuple;

    auto tutu = std::make_tuple("hello", 12, 34335);

    auto toto = {33, 3333, 22};

    //std::cout << tutu << std::endl;

    int a = 24;
    int&& b = f2();

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    //std::string s = R"[\w\\\w]";

    auto varx = 11ULL;

    std::map<std::string,int> m {
	{"Dijkstra",1972}, {"Scott",1976}, {"Wilkes",1967}, {"Hamming",1968}
    };
    m["Ritchie"] = 1983;
    for(auto x : m) std::cout << '{' << x.first << ',' << x.second << '}';
    std::cout << std::endl;

    std::unordered_map<std::string,int> um {
	{"Dijkstra",1972}, {"Scott",1976}, {"Wilkes",1967}, {"Hamming",1968}
    };
    um["Ritchie"] = 1983;
    for(auto x : um) std::cout << '{' << x.first << ',' << x.second << '}';
    std::cout << std::endl;

    return 0;
}

// template<ForwardIterator Iter, class V>
// requires std::Assignable<Iter::value_type,V>
// void fill(Iter first, Iter last, const V& v)
// {
//     while (first!=last) {
// 	*first = v;
// 	first=first+1;	// error: + not defined for Forward_iterator
// 	// (use ++first)
//     }
// }

