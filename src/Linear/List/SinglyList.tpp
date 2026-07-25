
template<typename D>
LIST<D>::LIST(){ H=T=nullptr; elem=0; }

template<typename D>
LIST<D>::LIST(LIST<D>&& other) noexcept :H(other.H), T(other.T), elem(other.elem) {
    other.H = other.T = nullptr;
    other.elem = 0;
}

template<typename D>
LIST<D>::LIST(const LIST<D>& other):LIST<D>(){
    LISTnode<D>* iter = other.H;
    while(iter){
        insert(iter->K); iter = iter->P;
    }
}

template<typename D>
LIST<D>::~LIST(){
    clear(H);
    T = nullptr; elem = 0;
}

template<typename D>
LIST<D>& LIST<D>::operator=(LIST<D>&& other) noexcept{
    if(this != &other){
        clear(H);
        H = other.H; T = other.T;
        elem = other.elem;

        other.H = other.T = nullptr;
        other.elem = 0;
    }
    return *this;
}

template<typename D>
LIST<D>& LIST<D>::operator=(const LIST<D>& other){
    if(this != &other){
        clear(H);
        H=T=nullptr; elem=0;
        
        LISTnode<D>* iter=other.H;
        while(iter){
            insert(iter->K); iter=iter->P;
        }
    }
    return *this;
}

template<typename D>
bool LIST<D>::add(const LIST<D>& next){
    if(this == &next) return false;
    if(!next.H) return false;
    LISTnode<D>* tmp=next.H;
    while(tmp){
        insert(tmp->K); tmp=tmp->P;
    }
    return true;
}

template<typename D>
size_t LIST<D>::clear(LISTnode<D>*& p){
    LISTnode<D>* tmp; size_t count=0;
    while(p){ 
        tmp=p; p=p->P; 
        delete tmp; count++;
    }
    return count;
}

template<typename D>
size_t LIST<D>::clearupto(LISTnode<D>*& head, LISTnode<D>*& tail){
    if(!head) return 0;
    LISTnode<D>* p=head->P, *tmp; size_t count=0;
    while(p && p!=tail){ 
        tmp=p; p=p->P; 
        delete tmp; count++;
    }
    if(!p){ head->P=nullptr; return count; }
    if(tail && p==tail){
        tail=tail->P; 
        delete p; count++;
    }
    if(tail){ head->P=tail;  
    }else{ 
        tail=head; tail->P=head->P=nullptr; 
    }
    return count;
}

template<typename D>
D& LIST<D>::operator[](const std::ptrdiff_t index){
    if(!H || elem==0) throw std::runtime_error("List is empty");

    LISTnode<D>* ptr=pointer(index);  
    if(!ptr) throw std::out_of_range("Index out of bounds");
    return ptr->K;                    
}

template<typename D>
const D& LIST<D>::operator[](const std::ptrdiff_t index) const{
    if(!H || elem==0) throw std::runtime_error("List is empty");

    const LISTnode<D>* ptr = pointer(index);   
    if(!ptr) throw std::out_of_range("Index out of bounds");
    return ptr->K;                    
}

template<typename D>
size_t LIST<D>::update(D prev, D curr, bool in){
    LISTnode<D> *iter=H; size_t index=0;
    while(iter){
        if(iter->K==prev){
            iter->K=curr;
            return index;
        }
        iter=iter->P; index++;
    }
    if(in){ 
        insert(curr); return elem-1; 
    } return -1;
}

template<typename D>
D LIST<D>::modify(D curr, std::ptrdiff_t index){
    LISTnode<D>* point=pointer(index);
    if(point){
        D tmp=point->K; point->K=curr;
        return tmp;
    } 
    throw std::out_of_range("Index out of bounds");
}

template<typename D>
LISTnode<D>* LIST<D>::pointer(std::ptrdiff_t index) const{
    if(index<0) index=static_cast<std::ptrdiff_t>(elem)+index;
    if(index>=static_cast<std::ptrdiff_t>(elem) || index<0) return nullptr;
    LISTnode<D> *iter=H;
    for(std::ptrdiff_t i=0; i<index; i++) iter=iter->P;
    return iter;
}

template<typename D>
size_t LIST<D>::index(D value) const{
    LISTnode<D> *iter=H; size_t index=0;
    while(iter){
        if(iter->K==value) return index;
        iter=iter->P; index++;
    } return -1;
}

template<typename D>
const D& LIST<D>::value(std::ptrdiff_t index) const{
    if(index<0) index=static_cast<std::ptrdiff_t>(elem)+index;
    if(index>=static_cast<std::ptrdiff_t>(elem) || index<0) 
        throw std::out_of_range("Index out of bounds");
    LISTnode<D> *iter=H;
    for(std::ptrdiff_t i=0; i<index; i++) iter=iter->P;
    return iter->K;
}

template<typename D>
D LIST<D>::remove(std::ptrdiff_t index){
    if(!elem) throw std::runtime_error("List is empty"); 
    if(index<0) index=static_cast<std::ptrdiff_t>(elem)+index;
    if(index>=static_cast<std::ptrdiff_t>(elem) || index<0) 
        throw std::out_of_range("Index out of bounds");

    LISTnode<D> *iter=H; D K;
    if(index==0){ K=iter->K;
        H=H->P; delete iter; elem--; 
        if(!H) T=nullptr; return K; 
    }
    for(std::ptrdiff_t i=1; i<index; i++){ iter=iter->P; }
    LISTnode<D> *tmp=iter->P; 
    iter->P=tmp->P;
    if(T==tmp) T=iter;
    K=tmp->K; delete tmp; elem--; return K;
}

template<typename D>
size_t LIST<D>::drop(D val){
    if(H==nullptr) return -1; 
    LISTnode<D> *iter=H;
    if(H->K==val){ 
        H=H->P; delete iter; elem--; 
        if(!H) T=nullptr; return 0; 
    }
    size_t index=1;
    while(iter->P){
        if(iter->P->K==val){
            LISTnode<D> *tmp=iter->P; iter->P=tmp->P;
            if(tmp==T) T=iter;
            delete tmp; elem--; return index;
        }
        iter=iter->P; index++;
    }
    return -1; 
}

template<typename D>
bool LIST<D>::insert(D val, std::ptrdiff_t index){
    if(H==nullptr && index!=-1 && index!=0) return false;
    if(H==nullptr){
        H=T=new LISTnode<D>{val, nullptr}; elem++;
        return true;
    }
    if(index==-1 || index==static_cast<std::ptrdiff_t>(elem)){
        T->P=new LISTnode<D>{val, nullptr}; T=T->P; elem++;    
        return true;    
    }
    if(index<0) index=static_cast<std::ptrdiff_t>(elem)+index;
    if(index<0 || index>static_cast<std::ptrdiff_t>(elem)) return false;
    if(index==0){
        LISTnode<D> *tmp=new LISTnode<D>{val, H};
        H=tmp; elem++;
        return true;
    }
    LISTnode<D> *iter=H; std::ptrdiff_t i;
    for(i=1; i<index; i++) iter=iter->P;
    LISTnode<D> *tmp=new LISTnode<D>{val, iter->P};
    iter->P=tmp; elem++;
    return true;
}

template<typename D>
void LIST<D>::view(bool v) const{
    if(!H)
        if(v) std::cout<<"Head->NULL<-Tail";
        else std::cout<<"NULL";
    else{
        LISTnode<D> *iter=H;
        if(v) std::cout<<"Head->";
        bool f=false;
        while(iter){
            if(f) std::cout<<"->["<<iter->K<<"]";  else{ std::cout<<"["<<iter->K<<"]"; f=true; }
            iter=iter->P;
        }
        if(v) std::cout<<"<-Tail";
    }
}

template<typename D>
void LIST<D>::rotate(LISTnode<D>*& head, LISTnode<D>*& tail){
    if(!head || !head->P) return;
    LISTnode<D>* pA = nullptr, *pB = head, *pC = nullptr;
    while(pB){
        pC=pB->P;
        pB->P=pA;
        pA=pB; pB=pC;
    }
    tail=head; head=pA;
    return;
}

template<typename D>
void LIST<D>::reverse(){ rotate(H,T); }

template<typename D>
LISTiterator<D> LIST<D>::begin() noexcept{ return LISTiterator<D>(H); }

template<typename D>
LISTiterator<D> LIST<D>::end() noexcept{ return LISTiterator<D>(nullptr); }

template<typename D>
LISTiterator<D> LIST<D>::begin() const noexcept{ return LISTiterator<D>(H); }

template<typename D>
LISTiterator<D> LIST<D>::end() const noexcept{ return LISTiterator<D>(nullptr); }



//----------------------------------------------------------------------------------------- LISTiterator

template<typename D>
LISTiterator<D>::LISTiterator(LISTnode<D>* p) : ptr(p) {}

template<typename D>
D& LISTiterator<D>::operator*(){
    if(!ptr) throw std::runtime_error("Null LISTiterator");
    return ptr->K;
}

template<typename D>
const D& LISTiterator<D>::operator*() const{
    if(!ptr) throw std::runtime_error("Null LISTiterator");
    return ptr->K;
}

template<typename D>
LISTiterator<D>& LISTiterator<D>::operator++() noexcept{
    if(ptr) ptr = ptr->P;
    return *this;
}

template<typename D>
LISTiterator<D> LISTiterator<D>::operator++(int) noexcept{
    LISTiterator<D> temp = *this; 
    ++(*this);
    return temp;
}

template<typename D>
bool LISTiterator<D>::operator!=(const LISTiterator<D>& other) const noexcept{ return ptr != other.ptr; }

template<typename D>
bool LISTiterator<D>::operator==(const LISTiterator<D>& other) const noexcept{ return ptr == other.ptr; }

template<typename D>
D* LISTiterator<D>::operator->(){ 
    if(!ptr) throw std::runtime_error("Null LISTiterator");
    return &(ptr->K); 
}

template<typename D>
const D* LISTiterator<D>::operator->() const{ 
    if(!ptr) throw std::runtime_error("Null LISTiterator");
    return &(ptr->K); 
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const LIST<D>& l){  l.view(false); return out;  }
