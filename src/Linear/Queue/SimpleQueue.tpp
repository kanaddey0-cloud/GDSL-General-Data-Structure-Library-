
template<typename D>
size_t FIFO<D>::Continuous::size(){ return S; }

template<typename D>
size_t FIFO<D>::Linked::size(){ return Q.size(); }

template<typename D>
bool FIFO<D>::Continuous::empty(){ return S==0; }

template<typename D>
bool FIFO<D>::Linked::empty(){ return Q.size()==0; }

template<typename D>
bool FIFO<D>::Continuous::enqueue(D val){
    if (S==C)
        throw std::runtime_error("Queue overflow");

    Q[r]=val; r=(r+1)%C; S++;
    return true;
}

template<typename D>
bool FIFO<D>::Linked::enqueue(D val){ return Q.insert(val); }

template<typename D>
D FIFO<D>::Continuous::dequeue(){
    if (empty())
        throw std::runtime_error("Queue is empty");

    D val=Q[f]; f=(f+1)%C; S--;
    return val;
}

template<typename D>
D FIFO<D>::Linked::dequeue(){
    if(empty()) 
        throw std::runtime_error("Queue is empty");

    return Q.remove(0);
}

template<typename D>
D FIFO<D>::Continuous::front(){
    if (empty())
        throw std::runtime_error("Queue is empty");

    return Q[f];
}

template<typename D>
D FIFO<D>::Linked::front(){
	if(empty())
        throw std::runtime_error("Queue is empty");
		
    return Q.value(0);
}

template<typename D>
D FIFO<D>::Continuous::rear(){
    if (empty())
        throw std::runtime_error("Queue is empty");

    return Q[(r+C-1)%C];
}

template<typename D>
D FIFO<D>::Linked::rear(){
	if(empty())
        throw std::runtime_error("Stack is empty");
		
    return Q.value(-1);
}

template<typename D>
void FIFO<D>::Continuous::clear(){ S=f=r=0; }

template<typename D>
void FIFO<D>::Linked::clear(){
    while(Q.size()) Q.remove(0);
}

template<typename D>
void FIFO<D>::Continuous::view(bool v) const {
    if(v) std::cout << "Front->";
    std::cout << "[";
    for (size_t i=0; i<S; i++){
        if(i) std::cout << ", "; std::cout << Q[(f+i)%C];
    }
    std::cout << "]";
    if(v) std::cout << "<-Rear";
}

template<typename D>
void FIFO<D>::Linked::view(bool v) const{
    if(v) std::cout << "Front->";
    bool f=false;
    std::cout << "[";
    for(auto x : Q){
        if(f) std::cout<<", "<<x;  else{ std::cout<<x; f=true; }
    }
    std::cout << "]";
    if(v) std::cout << "<-Rear";
}



//----------------------------------------- queue

template<typename D>
QUEUE<D>::QUEUE(size_t size)
{
    if(size){
        new (&Queue.array) typename FIFO<D>::Continuous(size);
        C = true;
    }else{
        new (&Queue.list) typename FIFO<D>::Linked();
        C = false;
    }
}

template<typename D>
QUEUE<D>::~QUEUE()
{
    if(C)
        Queue.array.~Continuous();
    else
        Queue.list.~Linked();
}

template<typename D>
QUEUE<D>::QUEUE(const QUEUE& other)
{
    C=other.C;
    if(C)
        new (&Queue.array) typename FIFO<D>::Continuous(other.Queue.array);
    else
        new (&Queue.list) typename FIFO<D>::Linked(other.Queue.list);
}

template<typename D>
QUEUE<D>& QUEUE<D>::operator=(const QUEUE& other)
{
    if(this == &other) return *this;

    if(C)
        Queue.array.~Continuous();
    else
        Queue.list.~Linked();

    C=other.C;
    if(C)
        new (&Queue.array) typename FIFO<D>::Continuous(other.Queue.array);
    else
        new (&Queue.list) typename FIFO<D>::Linked(other.Queue.list);

    return *this;
}

template<typename D>
QUEUE<D>::QUEUE(QUEUE&& other) noexcept
{
    C=other.C;
    if(C)
        new (&Queue.array) typename FIFO<D>::Continuous(std::move(other.Queue.array));
    else
        new (&Queue.list) typename FIFO<D>::Linked(std::move(other.Queue.list));
}

template<typename D>
QUEUE<D>& QUEUE<D>::operator=(QUEUE&& other) noexcept
{
    if(this == &other) return *this;

    if(C)
        Queue.array.~Continuous();
    else
        Queue.list.~Linked();

    C=other.C;
    if(C)
        new (&Queue.array) typename FIFO<D>::Continuous(std::move(other.Queue.array));
    else
        new (&Queue.list) typename FIFO<D>::Linked(std::move(other.Queue.list));

    return *this;
}

template<typename D>
size_t QUEUE<D>::size()
{
    return C? Queue.array.size()
            : Queue.list.size();
}

template<typename D>
bool QUEUE<D>::empty()
{
    return C? Queue.array.empty()
            : Queue.list.empty();
}

template<typename D>
bool QUEUE<D>::enqueue(D val)
{
    return C? Queue.array.enqueue(val)
            : Queue.list.enqueue(val);
}

template<typename D>
D QUEUE<D>::dequeue()
{
    return C? Queue.array.dequeue()
            : Queue.list.dequeue();
}

template<typename D>
D QUEUE<D>::front()
{
    return C? Queue.array.front()
            : Queue.list.front();
}

template<typename D>
D QUEUE<D>::rear()
{
    return C? Queue.array.rear()
            : Queue.list.rear();
}

template<typename D>
void QUEUE<D>::view(bool v) const
{
     C? Queue.array.view(v)
      : Queue.list.view(v);
}

template<typename D>
void QUEUE<D>::clear()
{
     C? Queue.array.clear()
      : Queue.list.clear();
}

template<typename D>
bool QUEUE<D>::resize(size_t size, bool force)
{
    if(!C) return false;
    if(size<Queue.array.S) return false;
    if(size<=Queue.array.C) return true;
    if(!force) return false;

    D *ARR=new D[size];
    for(size_t i=0; i<Queue.array.S; i++)
        ARR[i]=Queue.array.Q[(Queue.array.f+i)%Queue.array.C];

    delete[] Queue.array.Q;
    Queue.array.Q=ARR;  Queue.array.C=size; 
    Queue.array.f=0;    Queue.array.r=Queue.array.S;

    return true;
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const QUEUE<D>& Q){ Q.view(false); return out; }
