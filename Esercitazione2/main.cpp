#include <iostream>
#include "complex_number.hpp"

int main(){
    using complex = complex_number<float>;
    complex a(2,3);
    complex b(4,5);
    complex c(3,1);
    complex d = c.conjugate();
    std::cout<<a<<std::endl;
    std::cout<<a*b<<std::endl;
    std::cout<<c*d<<std::endl; /*modulo di c^2*/
    /*Verifico la commutatività*/
    std::cout<<a+b<<std::endl;
    float e = 3;
    complex g(3);
    std::cout<< a+e <<std::endl;
    std::cout<< e+a <<std::endl;
    std::cout << e*a << std::endl;
    std::cout << a*e <<std::endl;
    return 0;



}

