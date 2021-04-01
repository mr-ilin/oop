#include <iostream>
#include <string>
#include <algorithm>

template <typename T, size_t const Size>
class dummy_array_iterator
{
public:
    typedef dummy_array_iterator<T,Size> self_type;
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;

private:
    pointer ptr = nullptr;
    size_t index = 0;
    bool compatible(self_type const &other) const
    {
        return ptr == other.ptr;
    }

public:
    

    // common iterator
    explicit dummy_array_iterator(pointer ptr,
                                  size_t const index)
        : ptr(ptr), index(index) {}
    dummy_array_iterator() = default; //forward
    dummy_array_iterator(dummy_array_iterator const &o) = default;
    dummy_array_iterator &operator=(dummy_array_iterator const &o) = default;
    ~dummy_array_iterator() = default;

    self_type &operator++()
    {
        if (index >= Size)
             throw std::out_of_range("Iterator cannot be incremented past the end of range.");
          ++index;
          return *this;
    }

    self_type operator++(int)
    {
        self_type tmp = *this;
        ++*this;
        return tmp;
    }

    // input iterator
    bool operator==(self_type const &other) const
    {
        assert(compatible(other));
        return index == other.index;
    }

    bool operator!=(self_type const &other) const
    {
        return !(*this == other);
    }

    reference operator*() const
    {
        if (ptr == nullptr)
            throw std::bad_function_call();
        return *(ptr + index);
    }

    reference operator->() const
    {
        if (ptr == nullptr)
            throw std::bad_function_call();
        return *(ptr + index);
    }

    // bidirectional
    self_type &operator--()
    {
        if (index <= 0)
            throw std::out_of_range("Iterator cannot be decremented past the end of range.");
          --index;
          return *this;
    }

    self_type operator--(int)
    {
        self_type tmp = *this;
        --*this;
        return tmp;
    }
    // random access
    self_type operator+(difference_type offset) const
    {
        self_type tmp = *this;
        return tmp += offset;
    }
    self_type operator-(difference_type offset) const
    {
        self_type tmp = *this;
        return tmp -= offset;
    }
    difference_type operator-(self_type const &other) const
    {
        assert(compatible(other));
        return (index - other.index);
    }
    bool operator<(self_type const &other) const
    {
        assert(compatible(other));
        return index < other.index;
    }
    bool operator>(self_type const &other) const { return other < *this; }
    bool operator<=(self_type const &other) const { return !(other < *this); }
    bool operator>=(self_type const &other) const { return !(*this < other); }
    self_type &operator+=(difference_type const offset)
    {
        if (index + offset < 0 || index + offset > Size)
            throw std::out_of_range("Iterator cannot be incremented past the end of range.");
        index += offset;
        return *this;
    }
    self_type &operator-=(difference_type const offset) { return *this += -offset; }
    value_type &operator[](difference_type const offset) { return (*(*this + offset)); }
    value_type const &operator[](difference_type const offset) const { return (*(*this + offset)); }
};

auto main() -> int
{
    int array[10];

    auto begin = dummy_array_iterator<int,10>(array,0);
    auto end   = dummy_array_iterator<int,10>(array,10);

    for(auto &a: array) std::cin >> a;

    std::sort(begin,end);

    std::cout << "sorted ---------" << std::endl;
    for(auto a: array) std::cout << a << std::endl;

    return 1;
}