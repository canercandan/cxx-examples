#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main(void)
{
    std::vector< std::string > vec(2);
    std::vector< std::string >::iterator it;

    vec[ 0 ] = "aaa";
    vec[ 1 ] = "bbb";

    it = std::find(vec.begin(), vec.end(), "aaa");
    std::cout << "idx aaa: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "bbb");
    std::cout << "idx bbb: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "ccc");
    std::cout << "idx ccc: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "ddd");
    std::cout << "idx ddd: " << it - vec.begin() << std::endl;

    return 0;
}
