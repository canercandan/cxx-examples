#include <map>

struct Cell {};

bool operator<( const Cell&, const Cell& ){ return true; }

int main()
{
    std::map< Cell&, int > m;

    Cell c1;

    m[c1] = 1;

    const Cell& cr = c1;

    m[cr] = 2;
}
