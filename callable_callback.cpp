#include <functional>
#include <iostream>


class Test
{
public:
      void blah() { std::cout << "BLAH!" << std::endl; }
};

class Bim
{
public:
      void operator()(){ std::cout << "BIM!" << std::endl; }
};

void boum() { std::cout << "BOUM!" << std::endl; }


int main()
{
    // store the member function of an object:
    Test test;  
    std::function< void() > callback = std::bind( &Test::blah, test );
    callback();

    // store a callable object (by copy)
    callback = Bim{};
    callback();

    // store the address of a static function
    callback = &boum;
    callback();

    // store a copy of a lambda (that is a callable object)
    callback = [&]{ test.blah(); }; // often clearer -and not more expensive- than std::bind()
    callback();
} 
