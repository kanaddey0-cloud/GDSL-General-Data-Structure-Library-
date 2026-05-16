
template<typename D>
long int STACK<D>::size(){ return S.size(); }

template<typename D>
bool STACK<D>::empty(){ return S.size()==0; }

template<typename D>
bool STACK<D>::push(D val){ return S.insert(val); }

template<typename D>
D STACK<D>::pop(){
    if(empty()) 
		throw std::runtime_error("Stack is empty");
	
	return S.remove(-1);
}

template<typename D>
void STACK<D>::view(bool v) const{
    long int index = S.size();
    if(!index) return;
    if(v) std::cout << "SP->";
    std::cout << "[";
    for(long int i=index-1; i>=0; i--){
        std::cout << S.value(i); if(i > 0) std::cout<<", ";
    }
    std::cout << "]";
}

template<typename D>
void STACK<D>::clear(){
    while(!empty())  pop();
}

template<typename D>
D STACK<D>::tos(){
	if(!S.size())
        throw std::runtime_error("Stack is empty");
		
    return S.value(-1);
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const STACK<D>& S){  S.view(false); return out;  }
