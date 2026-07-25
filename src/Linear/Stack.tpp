
template<typename D>
size_t LIFO<D>::Continuous::size(){ return S.size(); }

template<typename D>
size_t LIFO<D>::Linked::size(){ return S.size(); }

template<typename D>
bool LIFO<D>::Continuous::empty(){ return S.size()==0; }

template<typename D>
bool LIFO<D>::Linked::empty(){ return S.size()==0; }

template<typename D>
bool LIFO<D>::Continuous::push(D val){ return S.insert(val); }

template<typename D>
bool LIFO<D>::Linked::push(D val){ return S.insert(val,0); }

template<typename D>
D LIFO<D>::Continuous::pop(){
    if(empty()) 
        throw std::runtime_error("Stack is empty");

    return S.remove();
}

template<typename D>
D LIFO<D>::Linked::pop(){
    if(empty()) 
        throw std::runtime_error("Stack is empty");

    return S.remove(0);
}

template<typename D>
void LIFO<D>::Continuous::view(bool v) const{
    if(v) std::cout << "SP->"; S.view();
}

template<typename D>
void LIFO<D>::Linked::view(bool v) const{
    if(v) std::cout << "SP->";
    bool f=false;
    std::cout << "[";
    for(auto x : S){
        if(f) std::cout<<", "<<x;  else{ std::cout<<x; f=true; }
    }
    std::cout << "]";
}

template<typename D>
void LIFO<D>::Continuous::clear(){
    while(!empty()) S.remove();
}

template<typename D>
void LIFO<D>::Linked::clear(){
    while(!empty()) S.remove(0);
}

template<typename D>
D LIFO<D>::Continuous::tos(){
	if(empty())
        throw std::runtime_error("Stack is empty");
		
    return S[-1];
}

template<typename D>
D LIFO<D>::Linked::tos(){
	if(empty())
        throw std::runtime_error("Stack is empty");
		
    return S.value(0);
}



//----------------------------------------- stack

template<typename D>
STACK<D>::STACK(size_t size)
{
    if(size){
        new (&Stack.array) typename LIFO<D>::Continuous(size);
        C=true;
    }else{
        new (&Stack.list) typename LIFO<D>::Linked();
        C=false;
    }
}

template<typename D>
STACK<D>::~STACK()
{
    if(C)
        Stack.array.~Continuous();
    else
        Stack.list.~Linked();
}

template<typename D>
STACK<D>::STACK(const STACK& other) 
{
    C=other.C;
    if(C)
        new (&Stack.array) typename LIFO<D>::Continuous(other.Stack.array);
    else
        new (&Stack.list) typename LIFO<D>::Linked(other.Stack.list);
}

template<typename D>
STACK<D>& STACK<D>::operator=(const STACK& other) 
{
    if(this == &other) return *this;

    if(C)
        Stack.array.~Continuous();
    else
        Stack.list.~Linked();

    C=other.C;
    if(C)
        new (&Stack.array) typename LIFO<D>::Continuous(other.Stack.array);
    else
        new (&Stack.list) typename LIFO<D>::Linked(other.Stack.list);

    return *this;
}

template<typename D>
STACK<D>::STACK(STACK&& other) noexcept
{
    C=other.C;
    if(C)
        new (&Stack.array) typename LIFO<D>::Continuous(std::move(other.Stack.array));
    else
        new (&Stack.list) typename LIFO<D>::Linked(std::move(other.Stack.list));
}

template<typename D>
STACK<D>& STACK<D>::operator=(STACK&& other) noexcept
{
    if(this == &other) return *this;

    if(C)
        Stack.array.~Continuous();
    else
        Stack.list.~Linked();

    C=other.C;
    if(C)
        new (&Stack.array) typename LIFO<D>::Continuous(std::move(other.Stack.array));
    else
        new (&Stack.list) typename LIFO<D>::Linked(std::move(other.Stack.list));

    return *this;
}

template<typename D>
size_t STACK<D>::size()
{
    return C? Stack.array.size()
            : Stack.list.size();
}

template<typename D>
bool STACK<D>::empty()
{
    return C? Stack.array.empty()
            : Stack.list.empty();
}

template<typename D>
bool STACK<D>::push(D val)
{
    return C? Stack.array.push(val)
            : Stack.list.push(val);
}

template<typename D>
void STACK<D>::view(bool v) const
{
    C? Stack.array.view(v)
     : Stack.list.view(v);
}

template<typename D>
D STACK<D>::tos()
{
    return C? Stack.array.tos()
            : Stack.list.tos();
}

template<typename D>
D STACK<D>::pop()
{
    return C? Stack.array.pop()
            : Stack.list.pop();
}

template<typename D>
void STACK<D>::clear()
{
    C? Stack.array.clear()
     : Stack.list.clear();
}

template<typename D>
bool STACK<D>::resize(size_t size, bool force)
{
    if(!C) return false;

    if(Stack.array.S.capacity() < size && force){
        Stack.array.S.capacity(size);
        return true;
    }
    else if(Stack.array.S.capacity() < size) return false;
    return true;
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const STACK<D>& S){ S.view(false); return out; }
