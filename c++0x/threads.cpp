#include <thread>

void f(){while (1);}

struct F {
    void operator()(){while (1);}
};

int main()
{
    std::thread t1{f};	// f() executes in separate thread
    std::thread t2{F()};	// F()() executes in separate thread
}
