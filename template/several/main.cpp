template < typename T > class AllocateFunc {};
template < typename T, template < typename > class Allocate > class Container {};

int main()
{
    Container< int, AllocateFunc > container;
}
