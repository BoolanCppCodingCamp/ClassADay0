#ifndef A_HPP_
#define A_HPP_

class A{
    int m_a = 1;
    int m_b = 2;
    int m_c = 3;
    uint8_t m_d = 42;
public:
    A(int a, int b, int c, uint8_t d);
    A(const A& other);
    A();
    void Dump();
};

#endif //A_HPP_
