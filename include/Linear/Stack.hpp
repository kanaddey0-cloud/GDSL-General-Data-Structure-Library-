#ifndef STACK_LIFO
#define STACK_LIFO

#include <iostream>
#include <stdexcept>
#include <new>
#include <gdsl_list>
#include <gdsl_array>
// #include "Linear/List/SinglyList.hpp"


template<typename D>
class STACK;

template<typename D>
union LIFO
{
    struct Continuous { friend class STACK<D>;
    protected:
        ::ARRAY<D> S;
    public:
        Continuous(size_t size=0) :S(size) {} 

        size_t size();
        bool empty();
        bool push(D val);
        D tos();
        D pop();
        void view(bool v) const;
        void clear();

        Continuous(const Continuous&) = default;
        Continuous& operator=(const Continuous&) = default;

        Continuous(Continuous&&) noexcept = default;
        Continuous& operator=(Continuous&&) noexcept = default;
    } 
	array;

    struct Linked { friend class STACK<D>;
    protected:
        ::LIST<D> S;
    public:
        Linked()=default;

        size_t size();
        bool empty();
        bool push(D val);
        D tos();
        D pop();
        void view(bool v) const;
        void clear();

        Linked(const Linked&) = default;
        Linked& operator=(const Linked&) = default;

        Linked(Linked&&) noexcept = default;
        Linked& operator=(Linked&&) noexcept = default;
    } 
	list;

    LIFO() {}
    ~LIFO() {}

    LIFO(const LIFO&)=delete;
    LIFO& operator=(const LIFO&)=delete;

    LIFO(LIFO&&)=delete;
    LIFO& operator=(LIFO&&)=delete;
};


template<typename D>
class STACK{
protected:
    bool C;
    LIFO<D> Stack;
public:
    STACK(size_t size=0);
    ~STACK();

    bool resize(size_t size, bool force=false);
    size_t size();
    bool empty();
    bool push(D val);
    void view(bool v=false) const;
    D tos();
    D pop();
    void clear();

    STACK(const STACK&);
    STACK& operator=(const STACK&);

    STACK(STACK&&) noexcept;
    STACK& operator=(STACK&&) noexcept;
};


#include "GDSL/src/Linear/Stack.tpp"
// #include "src/Linear/Stack.tpp"

#endif