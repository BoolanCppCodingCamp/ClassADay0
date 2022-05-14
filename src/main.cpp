#include <iostream>
#include "A.hpp"
#include "DataBuffer.hpp"

void f(CDataBuffer buf)
{
	buf.Dump();
}

CDataBuffer createBuffer(const std::string& name)
{
    A c{3,1,4,1};
    CDataBuffer bufferN{name, &c, sizeof(A)};
    return bufferN;
}

int main()
{
/*
    A a{2,7,1,8};
    A b{3,1,4,1};
    CDataBuffer bufferA{"bufferA", &a, sizeof(A)};
    CDataBuffer bufferB{std::move(bufferA)};
    f(std::move(bufferB));
*/
    //CDataBuffer n = createBuffer("bufferN");
    //n.Dump();
	
    A c{3,1,4,1};
    CDataBuffer bufferN{"N", &c, sizeof(A)};
    CDataBuffer n_1{bufferN};
    n_1.Dump();
}
