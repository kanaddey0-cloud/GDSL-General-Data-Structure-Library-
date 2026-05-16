#ifndef SIMPLE_QUEUE_FIFO
#define SIMPLE_QUEUE_FIFO

#include <iostream>
#include "Linear/List/SinglyList.hpp"

template<typename D>
class QUEUE{
protected:
    LIST<D> Q;
public:
    long int size();
    bool empty();
    bool enqueue(D val);
    D dequeue();
	D front();
    D rear();
    void view(bool v=true) const;
	void clear();
};

#include "src/Linear/Queue/SimpleQueue.tpp"

#endif