#ifndef DATA_BUFFER_HPP_
#define DATA_BUFFER_HPP_

#include <string>

class A;

class CDataBuffer
{
public:
    // Big Four
    CDataBuffer(const std::string& name, A* data, unsigned int length);
    CDataBuffer(const CDataBuffer& db);
    CDataBuffer& operator= (const CDataBuffer& db);
    CDataBuffer(CDataBuffer&& db) noexcept;
    CDataBuffer& operator= (CDataBuffer&& db) noexcept;
    virtual ~CDataBuffer();

    A* GetExtraData();
    void Dump ();
private:
    std::string m_dataName;
    unsigned int m_DataLength;
    unsigned int m_BufSize = 0;
    A* m_pFoo;
};


#endif 
