
template<typename D>
long int QUEUE<D>::size(){
    return Q.size();
}

template<typename D>
bool QUEUE<D>::empty(){
    return Q.size()==0;
}

template<typename D>
bool QUEUE<D>::enqueue(D val){
    return Q.insert(val);
}

template<typename D>
D QUEUE<D>::dequeue(){
    if(empty()) 
		throw std::runtime_error("Queue is empty");

	return Q.remove(0);
}

template<typename D>
void QUEUE<D>::view(bool v) const{
    long int index = Q.size();
    if(!index) return;
    if(v) std::cout << "Front->";
    std::cout << "[";
    for(long int i=0; i<index; i++){
        std::cout << Q.value(i); if(i<(index-1)) std::cout<<", ";
    }
    std::cout << "]";
    if(v) std::cout << "<-Rear";
}

template<typename D>
void QUEUE<D>::clear(){
    while(!empty())  dequeue();
}

template<typename D>
D QUEUE<D>::front(){
	if(!Q.size())
		throw std::runtime_error("Queue is empty");
		
    return Q.value(0);
}

template<typename D>
D QUEUE<D>::rear(){
	if(!Q.size())
        throw std::runtime_error("Queue is empty");
		
    return Q.value(-1);
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const QUEUE<D>& Q){  Q.view(false); return out;  }
