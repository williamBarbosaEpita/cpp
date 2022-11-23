#include <ostream>
#include <memory>

#include "vector.h"


Vector::Vector(const Vector& rhs) : n(rhs.n), data(new value[n])
{
    for (size_t i = 0; i < n; ++i)
        data[i] = rhs.data[i];
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this != &rhs)
    {
        n = rhs.n;
        data.reset(new value[n]);
        for (size_t i = 0; i < n; ++i)
                data[i] = rhs.data[i];
    }
    return *this;
}

Vector::Vector(size_t n) : n(n), data(new value[n])
{
    for (size_t i = 0; i < n; ++i)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> l) : n(l.size()), data(new value[n])
{
    size_t i = 0;
    for (auto& v : l)
        data[i++] = v;
}

size_t Vector::size() const
{
    return n;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    assert(n == rhs.n);
    for (size_t i = 0; i < n; ++i)
        data[i] += rhs.data[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    assert(n == rhs.n);
    for (size_t i = 0; i < n; ++i)
        data[i] -= rhs.data[i];
    return *this;
}

Vector& Vector::operator+=(value v)
{
    for (size_t i = 0; i < n; ++i)
        data[i] += v;
    return *this;
}

Vector& Vector::operator*=(value v)
{
    for (size_t i = 0; i < n; ++i)
        data[i] *= v;
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    Vector result(*this);
    result += rhs;
    return result;
}

Vector Vector::operator+(value v) const
{
    Vector result(*this);
    result += v;
    return result;
}

value Vector::operator*(const Vector& rhs) const
{
    assert(n == rhs.n);
    value result = 0;
    for (size_t i = 0; i < n; ++i)
        result += data[i] * rhs.data[i];
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
    assert(idx < n);
    return data[idx];
}

value Vector::operator[](size_t idx) const
{
    assert(idx < n);
    return data[idx];
}

Vector operator*(const value& s, const Vector& v)
{
    return v * s;
}

Vector operator+(const value& s, const Vector& v)
{
    return v + s;
}

std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    for (int i = 0; i < rhs.size(); i++)
        os << rhs[i] << (i == rhs.size() - 1 ? "" : ",");
    return os << "}";
}
