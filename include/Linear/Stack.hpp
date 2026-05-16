#ifndef STACK_LIFO
#define STACK_LIFO

#include <iostream>
#include "Linear/List/SinglyList.hpp"

template<typename D>
class STACK{
protected:
    LIST<D> S;
public:
    long int size();
    bool empty();
    bool push(D val);
	D tos();
	D pop();
    void view(bool v=true) const;
	void clear();
};

#include "src/Linear/Stack.tpp"

#endif