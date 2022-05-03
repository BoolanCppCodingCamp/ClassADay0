#include <iostream>
#include "A.hpp"
#include "DataBuffer.hpp"

int main()
{
	A a{2,7,1,8};
    A b{3,1,4,1};
    CDataBuffer bufferA{"bufferA", &a, sizeof(A)};
    bufferA.Dump();

    CDataBuffer bufferB{"bufferB", &b, sizeof(A)};
    bufferB.Dump();

    CDataBuffer bufferC(bufferA);
    bufferC.Dump();

    CDataBuffer bufferD(bufferC);
    bufferD.Dump();

    bufferA = bufferB;
    bufferA.Dump();

    bufferB = bufferB;
    bufferB.Dump();
}