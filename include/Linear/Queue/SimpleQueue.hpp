#ifndef SIMPLE_QUEUE_FIFO
#define SIMPLE_QUEUE_FIFO

#include <iostream>
#include <stdexcept>
#include <new>
#include <gdsl_list>
// #include "Linear/List/SinglyList.hpp"


template<typename D>
class QUEUE;

template<typename D>
union FIFO
{
    struct Continuous { friend class QUEUE<D>;
    protected:
        D *Q;
        size_t C, S, f, r;
    public:
        Continuous(size_t size=2)
            : C(size ? size : 2), S(0), f(0), r(0)
        { Q=new D[C]; }
        ~Continuous() { delete[] Q; }

        size_t size();
        bool empty();
        bool enqueue(D val);
        D dequeue();
        D front();
        D rear();
        void view(bool v) const;
        void clear();

        Continuous(const Continuous&);
        Continuous& operator=(const Continuous&);

        Continuous(Continuous&&) noexcept;
        Continuous& operator=(Continuous&&) noexcept;
    } 
    array;

    struct Linked { friend class QUEUE<D>;
    protected:
        ::LIST<D> Q;
    public:
        Linked()=default;

        size_t size();
        bool empty();
        bool enqueue(D val);
        D dequeue();
        D front();
        D rear();
        void view(bool v) const;
        void clear();

        Linked(const Linked&) = default;
        Linked& operator=(const Linked&) = default;

        Linked(Linked&&) noexcept = default;
        Linked& operator=(Linked&&) noexcept = default;
    } 
    list;

    FIFO() {}
    ~FIFO() {}

    FIFO(const FIFO&)=delete;
    FIFO& operator=(const FIFO&)=delete;

    FIFO(FIFO&&)=delete;
    FIFO& operator=(FIFO&&)=delete;
};


template<typename D>
class QUEUE{
protected:
    bool C;
    FIFO<D> Queue;
public:
    QUEUE(size_t size=0);
    ~QUEUE();

    bool resize(size_t size, bool force=false);
    size_t size();
    bool empty();
    bool enqueue(D val);
    D dequeue();
    D front();
    D rear();
    void view(bool v=false) const;
    void clear();

    QUEUE(const QUEUE&);
    QUEUE& operator=(const QUEUE&);

    QUEUE(QUEUE&&) noexcept;
    QUEUE& operator=(QUEUE&&) noexcept;
};


#include "GDSL/src/Linear/Queue/SimpleQueue.tpp"
// #include "src/Linear/Queue/SimpleQueue.tpp"

#endif