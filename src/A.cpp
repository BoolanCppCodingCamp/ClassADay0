#include <iostream>
#include "A.hpp"

using namespace std;

#define PRINTFUN_ADDR std::cout << static_cast<const char *>(__PRETTY_FUNCTION__) << " at " << this << std::endl

A::A()
{

}

A::A(const A &other) : m_a(other.m_a),
                       m_b(other.m_b),
                       m_c(other.m_c),
                       m_d(other.m_d)
{

    PRINTFUN_ADDR;
}

A::A(int a, int b, int c, uint8_t d):
m_a(a),
m_b(b),
m_c(c),
m_d(d)
{
    PRINTFUN_ADDR;
}

void A::Dump()
{
     using namespace std;
     auto dumpItem = [this](auto name, auto& item){
        std::cout << name << "@" << (void*)&item << " value is " << static_cast<int>(item) << ", size is " << sizeof(item) << endl;
     };
     dumpItem("m_a", m_a);
     dumpItem("m_b", m_b);
     dumpItem("m_c", m_c);
     dumpItem("m_d", m_d);
}
//EOF