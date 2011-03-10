#include <vector>
#include <iostream>

class Atom
{
public:
    Atom(int fitness = 0) : _fitness(fitness) {}
    ~Atom() {}
    Atom(const Atom& o) { *this = o; }

    Atom& operator=(const Atom& o)
    {
        if (this != &o)
            {
                _fitness = o._fitness;
            }
        return *this;
    }

    const int& fitness() const { return _fitness; }
    void fitness(const int& value) { _fitness = value; }

private:
    int _fitness;
};

class Object : public Atom
{
public:
    static int cnt_ctor;
    static int cnt_dtor;
    static int cnt_cpy;

    Object(int fitness = 0) : Atom(fitness) { cnt_ctor++; }
    ~Object() { cnt_dtor++; }

    Object(const Object& o) : Atom(o) { *this = o; }

    Object& operator=(const Object& o)
    {
        if ( this != &o )
            {
                cnt_cpy++;
                fitness(o.fitness());
            }
        return *this;
    }
};

int Object::cnt_ctor = 0;
int Object::cnt_dtor = 0;
int Object::cnt_cpy = 0;

int main(void)
{
    {
        std::vector< Object > vec(100, Object(12));
        //vec.resize(100);

        for (size_t i = 0; i < vec.size(); ++i)
            {
                std::cout << vec[i].fitness() << ", ";
            }
        std::cout << std::endl;

        // Object o1(50);
        // std::cout << "fitness: " << o1.fitness() << std::endl;
    }

    std::cout << "vec ctor: " << Object::cnt_ctor << std::endl;
    std::cout << "vec dtor: " << Object::cnt_dtor << std::endl;
    std::cout << "vec cpy: " << Object::cnt_cpy << std::endl;

    return 0;
}
