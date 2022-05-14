#include <iostream>
#include "DataBuffer.hpp"
#include "A.hpp"

using namespace std;

CDataBuffer::CDataBuffer(const std::string &name, A *data, unsigned int length) : m_dataName(name),
                                                                                  m_DataLength(length)
{

    std::cout << "ctor" << std::endl;
    if (data != nullptr)
    {
        m_pFoo = new A(*data);
    }
    else
    {
        m_pFoo = nullptr;
    }
}

CDataBuffer::CDataBuffer(const CDataBuffer &db) : m_dataName(db.m_dataName + "'"),
                                     m_DataLength(db.m_DataLength)
{
    std::cout << "cp ctor" << std::endl;
    if (db.m_pFoo != nullptr)
    {
        m_pFoo = new A(*db.m_pFoo);
    }
    else
    {
        m_pFoo = nullptr;
    }
}

CDataBuffer&
CDataBuffer::operator=(const CDataBuffer &db)
{
    std::cout << "cp =" << std::endl;
    if (this != &db)
    {
        // copy swap ?
        /*
                    CDataBuffer temp(db);
                    std::swap(m_pFoo, temp.m_pFoo);
                    m_DataLength = temp.m_DataLength;
        */
        if (db.m_pFoo != nullptr)
        {
            if (m_pFoo != nullptr)
            {
                (*m_pFoo) = *(db.m_pFoo);
            }
            else
            {
                m_pFoo = new A(*db.m_pFoo);
            }
        }
        else
        {
            delete m_pFoo;
            m_pFoo = nullptr;
        }
    }

    return *this;
}

CDataBuffer::~CDataBuffer()
{
    delete m_pFoo;
}

A* CDataBuffer::GetExtraData() { return m_pFoo; }


CDataBuffer::CDataBuffer(CDataBuffer&& db) noexcept  
: m_dataName(std::move(db.m_dataName))
{
	std::cout << "mv ctor" << std::endl;
	m_pFoo = db.m_pFoo;
	db.m_pFoo = nullptr;
}

CDataBuffer& CDataBuffer::operator= (CDataBuffer&& db) noexcept
{
	std::cout << "mv assignment" << std::endl;
	delete m_pFoo;
	this->m_pFoo = db.m_pFoo;
	db.m_pFoo = nullptr;
	return *this;
}


void CDataBuffer::Dump()
{
    cout << "--------" << endl;
    cout << m_dataName << endl;
    cout << m_DataLength << endl;
    m_pFoo->Dump();
    cout << "Obj size: " << sizeof(*this) << endl;
    cout << "========" << endl;
}
