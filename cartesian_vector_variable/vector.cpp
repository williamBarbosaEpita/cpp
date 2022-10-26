#include <ostream>
#include <memory>

#include "vector.h"


Vector::Vector(const Vector& vector) : vec_size(vector.vec_size), data(new value[vec_size])
{
    for (size_t i = 0; i < vec_size; ++i)
        data[i] = vector.data[i];
}

Vector& Vector::operator=(const Vector& vector)
{
    if (this != &vector)
    {
        vec_size = vector.vec_size;
        data.reset(new value[vec_size]);
        for (size_t i = 0; i < vec_size; ++i)
                data[i] = vector.data[i];
    }
    return *this;
}

Vector::Vector(size_t vec_size) : vec_size(vec_size), data(new value[vec_size])
{
    int i = 0;
    while(i < vec_size)
    {data[i] = 0; i++;}
}

Vector::Vector(std::initializer_list<value> l) : vec_size(l.size()), data(new value[vec_size])
{
    size_t i = 0;
    for (auto& v : l)
        data[i++] = v;
}

size_t Vector::size() const
{
    return vec_size;
}

Vector& Vector::operator+=(const Vector& vector)
{
    assert(vec_size == vector.vec_size);
    for (size_t i = 0; i < vec_size; ++i)
        data[i] += vector.data[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& vector)
{
    assert(vec_size == vector.vec_size);
    for (size_t i = 0; i < vec_size; ++i)
        data[i] -= vector.data[i];
    return *this;
}

Vector& Vector::operator+=(value v)
{
    size_t i = 0;
    while(i < vec_size)
    {data[i] += v;i++;}
    return *this;
}

Vector& Vector::operator*=(value v)
{
    size_t i = 0;
    while(i < vec_size)
    {data[i] *= v;i++;}
    return *this;
}

Vector Vector::operator+(const Vector& vector) const
{
    Vector result(*this);
    result += vector;
    return result;
}

Vector Vector::operator+(value v) const
{
    Vector result(*this);
    result += v;
    return result;
}

value Vector::operator*(const Vector& vector) const
{
    assert(vec_size == vector.vec_size);
    value result = 0;
    for (size_t i = 0; i < vec_size; ++i)
        result += data[i] * vector.data[i];
    return result;
}

Vector Vector::operator*(value v) const
{
    Vector result(*this);
    result *= v;
    return result;
}

value& Vector::operator[](size_t idx)
{
    assert(idx < vec_size);
    return data[idx];
}

value Vector::operator[](size_t idx) const
{
    assert(idx < vec_size);
    return data[idx];
}

Vector operator*(const value& a, const Vector& b)
{
    return a * b;
}

Vector operator+(const value& a, const Vector& b)
{
    return a + b;
}

std::ostream& operator<<(std::ostream &os, const Vector& vector)
{
    os << "{";
    for (int i = 0; i < vector.size(); i++)
        os << vector[i] << (i == vector.size() - 1 ? "" : ",");
    return os << "}";
}
