#ifndef CARLPP_VECTOR_H
#define CARLPP_VECTOR_H

#include <cstddef>
#include <memory>

namespace carstl {
template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
    vector() : m_begin{ nullptr }, m_last{ nullptr }, m_end( nullptr )
    {}

    vector(std::size_t n) : m_begin{ alloc.allocate(n) }, m_last { m_begin }, m_end( m_begin + n )
    {}

    vector(std::size_t n, const T& val) : vector(n)
    {
        for (auto it = m_begin; it != m_last; ++it)
        {
            **it = val;
        }
    }

    vector(std::size_t n, T&& val)
        : vector(n, std::move(val))
    {}

    vector(std::size_t n, const Allocator& alloc)
    : alloc{ alloc }
    , m_begin{ alloc.allocate(n) }
    , m_last { m_begin }
    , m_end( m_begin + n )
    {}

    // copy constructors and operators
    vector(const vector& v)
    : alloc{ v.alloc }, m_begin{ v.m_begin }, m_last{ v.m_last }, m_end( v.m_end )
    {
        free(m_begin);
        m_begin = alloc.allocate(v.size());
        std::copy(v.begin(), v.end(), m_begin);
    }

    vector& operator=(const vector& v)
    {
        if (this != &v)
        {

            std::copy(v.begin(), v.end(), m_begin);
        }

        return *this;
    }

    // move constructors and operators
    vector(vector&& v) noexcept
    : alloc{ v.alloc }, m_begin{ v.m_begin }, m_last{ v.m_last }, m_end( v.m_end )
    {
        v.alloc = nullptr;
        v.m_begin = nullptr;
        v.m_last = nullptr;
        v.m_end = nullptr;
    }

    vector& operator=(vector&& v) noexcept
    {
        if (this != &v)
        {
            m_begin = v.m_begin;
            m_last = v.m_last;
            m_end = v.m_end;
            alloc = v.alloc;
            v.alloc = nullptr;
            v.m_begin = nullptr;
            v.m_last = nullptr;
            v.m_end = nullptr;
        }

        return *this;
    }

    [[nodiscard]] std::size_t size() const
    {
        return m_last - m_begin;
    }

    [[nodiscard]] std::size_t capacity() const
    {
        return m_end - m_begin;
    }

private:
    Allocator alloc; // allocator object - not needed in normal stl impl, but easier for me for now
    T* m_begin;
    T* m_last;  // points to end of size
    T* m_end;   // points to capacity
};
}

#endif //CARLPP_VECTOR_H
