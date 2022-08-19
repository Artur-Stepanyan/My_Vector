#include <iostream>
#include "Vector.h"

//constructors
Vector::Vector()
:m_capacity { 0 }, m_size { 0 }, m_ptr { nullptr } {}

Vector::Vector(int size, int value)
{
    m_size = size;
    m_capacity = size * 2;
    m_ptr = new int [m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = value;
    }
}

Vector::Vector(const Vector& rhs)
{
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_ptr = new int [m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = rhs.m_ptr[i];
    }
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs) { return *this; }
    delete[] m_ptr;
    m_ptr = nullptr;

    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;

    m_ptr = new int [m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_ptr[i] = rhs.m_ptr[i];
    }
    return *this;
}

Vector::~Vector() 
{
    delete m_ptr; 
    m_ptr = nullptr;
}

//operators
int& Vector::operator[](int index)
{
    return m_ptr[index];
}

Vector Vector::operator+(const Vector& vec)
{
    if (m_size == vec.m_size)
    {
        Vector tmp(*this);
        for (int i = 0; i < m_size; ++i)
        {
            tmp.m_ptr[i] += vec.m_ptr[i];
        }
        return tmp;
    }
    else
    {
         std::cout << 
        "operator+ : Error! sizes are different\n"; 
    }
    return *this;
}

Vector& Vector::operator+=(const Vector& vec)
{
    if (m_size == vec.m_size)
    {
        for (int i = 0; i < m_size; ++i)
        {
            m_ptr[i] += vec.m_ptr[i];
        }
        return *this;
    }
    else
    {
         std::cout << 
        "operator+= : Error! sizes are different\n"; 
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& rhs)
{
    for (int i = 0; i < rhs.Size(); ++i)
    {
        os << rhs.m_ptr[i] << " ";
    }
    return os;
}

//member functions
int Vector::Size() const { return m_size; }

int Vector::Capacity() const { return m_capacity; }

void Vector::push_back(int value)
{
    if (m_ptr == nullptr)
    {
        ++m_capacity;
        m_ptr = new int [m_capacity];
        m_ptr[m_size] = value;
        ++m_size; 
    }
    else if (m_size < m_capacity && m_size != 1)
    {
        m_ptr[m_size] = value;
        ++m_size;
    }
    else
    {
        m_capacity *= 2;
        int* tmp_m_ptr = new int [m_capacity];
        for (int i = 0; i < m_size; ++i)
        {   
            tmp_m_ptr[i] = m_ptr[i];
        }
        tmp_m_ptr[m_size] = value;
        ++m_size;
        delete[] m_ptr;
        m_ptr = tmp_m_ptr;
        tmp_m_ptr = nullptr;
    }
}

void Vector::pop()
{
    if (m_size == 0)
    { 
        std::cout << "pop(): Vector is empty!\n";
        std::abort();
    }
    --m_size;
}

void Vector::insert(int pos, int value)
{
    if (pos < 0 || pos > m_size)
    {
        std::cout << "insert(): index is out of range\n";
        std::abort();
    }
    if (m_size != m_capacity)
    {
        for (int i = m_size; i >= pos; --i)
        {   
            m_ptr[i + 1] = m_ptr[i];
        }
        m_ptr[pos] = value;
        ++m_size;
    }
    else
    {
        m_capacity *= 2;
        int* tmp_m_ptr = new int [m_capacity];
        for (int i = 0; i < m_size; ++i)
        {   
            tmp_m_ptr[i] = m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr = tmp_m_ptr;
        insert(pos, value);
    }
}

int Vector::find_by_value(int value) const
{
    int index = 0;
    for (index; index < m_size; ++index)
    {
        if( m_ptr[index] == value){ return index; }  
    }
    std::cout << "find_by_value: no such element\n";
    return -1;
}

void Vector::remove_by_value(int value)
{
    int index = this->find_by_value(value);
    if (index != -1)
    {
        for (int i = index; i < m_size; ++i)
        {
            std::swap(m_ptr[i], m_ptr[i+1]);
        }
        this->pop();
    }
    else 
    {
        std::cout << "remove_by_value:"
        << " no such element\n";
    }
}

