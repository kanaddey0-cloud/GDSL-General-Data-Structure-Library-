
template<typename D>
AVLTREE<D>::AVLTREE(const AVLTREE<D>& other) :AVLTREE<D>(){
    M=other.M;
    if(!other.ROOT) return; 
    QUEUE<AVLnode<D>*> Q(other.elem); 
    AVLnode<D>* tmp;
    Q.enqueue(other.ROOT);
    while(!Q.empty()){
        tmp=Q.dequeue();
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        insert(tmp->K);
    }
}

template<typename D>
AVLTREE<D>::AVLTREE(AVLTREE<D>&& other) noexcept :ROOT(other.ROOT), elem(other.elem), M(other.M){
    other.ROOT=nullptr;
    other.elem=0;
}

template<typename D>
AVLTREE<D>& AVLTREE<D>::operator=(const AVLTREE<D>& other){
    if(this == &other) return *this;

    freelink(ROOT); if(ROOT){ delete ROOT; ROOT=nullptr; } 
    elem=0; 
    if(!other.ROOT) return *this;
    
    QUEUE<AVLnode<D>*> Q(other.elem); 
    AVLnode<D>* tmp;
    Q.enqueue(other.ROOT);
    while(!Q.empty()){
        tmp=Q.dequeue();
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        insert(tmp->K);
    }
    return *this;
}

template<typename D>
AVLTREE<D>& AVLTREE<D>::operator=(AVLTREE<D>&& other) noexcept{
    if(this == &other) return *this;

    freelink(ROOT); if(ROOT){ delete ROOT; ROOT=nullptr; } 
    elem=0; 
    if(!other.ROOT) return *this;

    ROOT=other.ROOT; elem=other.elem;
    other.ROOT=nullptr; other.elem=0;
    return *this;
}

template<typename D>
AVLTREE<D>::~AVLTREE(){ 
    if(ROOT){ freelink(ROOT); delete ROOT; ROOT=nullptr; } 
}

template<typename D>
size_t AVLTREE<D>::addlink(AVLnode<D>*& root, const AVLnode<D>*& other){
    if(!root || !other) return 0;
    QUEUE<const AVLnode<D>*> Q; 
    AVLnode<D>* ptr, *tmp, *key; D item; size_t count=0;
    Q.enqueue(other);
    while(!Q.empty()){
        key=Q.dequeue();
            if(key->LINK[L]) Q.enqueue(key->LINK[L]);
            if(key->LINK[R]) Q.enqueue(key->LINK[R]); 
        ptr=root; item=key->K;
        while(ptr){
            tmp=ptr;
            if(item<ptr->K) ptr=ptr->LINK[L];
            else if(item>ptr->K) ptr=ptr->LINK[R];
            else{ tmp=nullptr; break; }
        }
        if(!tmp) continue;
        if(item<tmp->K) tmp->LINK[L]=create(item); 
        else tmp->LINK[R]=create(item); 
        elem++; count++;
    }
    return count;
}

template<typename D>
bool AVLTREE<D>::add(const AVLTREE<D>& root){
    if(this == &root) return false;
    if(!root.ROOT) return false;
    QUEUE<AVLnode<D>*> Q(root.elem); 
    AVLnode<D>* tmp;
    Q.enqueue(root.ROOT);
    while(!Q.empty()){
        tmp=Q.dequeue();
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        insert(tmp->K);
    }
    return true;
}

template<typename D>
void AVLTREE<D>::print_Key_L_C_R(const AVLnode<D>* tmp) const{
    std::cout<<"H->"<<tmp->H<<"\t";
    if(tmp->LINK[L]) std::cout<<tmp->LINK[L]->K<<"<-";
    else std::cout<<"NULL<-"; 
    std::cout<<"["<<tmp->K<<"]";
    if(tmp->LINK[R]) std::cout<<"->"<<tmp->LINK[R]->K;
    else std::cout<<"->NULL"; 
}

template<typename D>
void AVLTREE<D>::viewPRE() const{
    if(!ROOT){ 
        std::cout<<"NULL"; return;
    }
    AVLnode<D> *curr=ROOT;
    STACK<AVLnode<D>*> S(elem);
    do{
        while(curr){ print_Key_L_C_R(curr); std::cout<<"\n";

            if(curr->LINK[R]) S.push(curr->LINK[R]);
            curr=curr->LINK[L];
        }
        if(!S.empty()) curr=S.pop();
    } while(curr);
}

template<typename D>
void AVLTREE<D>::viewIN() const{
    if(!ROOT){ 
        std::cout<<"NULL"; return;
    }
    AVLnode<D>* curr = ROOT;
    STACK<AVLnode<D>*> S(elem);
    while(curr || !S.empty()){
        while(curr){
            S.push(curr); curr=curr->LINK[L];
        }
        curr=S.pop();
        print_Key_L_C_R(curr); std::cout << "\n";
        curr=curr->LINK[R];
    }
}

template<typename D>
void AVLTREE<D>::viewR_IN() const{
    if(!ROOT){ 
        std::cout<<"NULL"; return;
    }
    AVLnode<D>* curr = ROOT;
    STACK<AVLnode<D>*> S(elem);
    while(curr || !S.empty()){
        while(curr){
            S.push(curr); curr=curr->LINK[R];
        }
        curr=S.pop();
        print_Key_L_C_R(curr); std::cout << "\n";
        curr=curr->LINK[L];
    }
}

template<typename D>
void AVLTREE<D>::viewPOST() const{
    if(!ROOT){ 
        std::cout<<"NULL"; return; 
    }
    STACK<AVLnode<D>*> S(elem);
    AVLnode<D>* curr=ROOT,*last=nullptr;
    do{
        while(curr){
            S.push(curr); curr=curr->LINK[L];
        }
        curr=S.tos();
        if(curr->LINK[R] && last!=curr->LINK[R])
            curr=curr->LINK[R];
        else{
            print_Key_L_C_R(last=S.pop()); std::cout<<"\n";
            curr=nullptr;
        }
    } while(!S.empty());
}

template<typename D>
void AVLTREE<D>::viewBFS(bool order) const{
    if(!ROOT){ 
        std::cout<<"NULL"; return; 
    }
    QUEUE<AVLnode<D>*> Q(elem); 
    AVLnode<D>* tmp;
    Q.enqueue(ROOT);
    while(!Q.empty()){
        tmp=Q.dequeue();
        if(order){
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        }else{
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
        }
        print_Key_L_C_R(tmp); std::cout<<"\n";
    }
}

template<typename D>
void AVLTREE<D>::viewDFS(bool order) const{
    if(!ROOT){ 
        std::cout<<"NULL"; return; 
    }
    STACK<AVLnode<D>*> S(elem); 
    AVLnode<D>* tmp;
    S.push(ROOT);
    while(!S.empty()){
        tmp=S.pop();
        if(order){
            if(tmp->LINK[R]) S.push(tmp->LINK[R]);
            if(tmp->LINK[L]) S.push(tmp->LINK[L]);
        }else{
            if(tmp->LINK[L]) S.push(tmp->LINK[L]);
            if(tmp->LINK[R]) S.push(tmp->LINK[R]);
        }
        print_Key_L_C_R(tmp); std::cout<<"\n";
    }
}

template<typename D>
void AVLTREE<D>::view(MODE mode) const{
    if(!ROOT){ std::cout << "NULL"; return; }
    if(mode == MODE::DEF) mode=M;
    switch(mode){
        case MODE::DFS: viewDFS(); break;
        case MODE::BFS: viewBFS(); break;

        case MODE::IN:   viewIN();   break;
        case MODE::R_IN: viewR_IN(); break;
        case MODE::PRE:  viewPRE();  break;
        case MODE::POST: viewPOST(); break;

        case MODE::DFS_RL: viewDFS(false); break;
        case MODE::BFS_RL: viewBFS(false); break;

        default:
            throw std::runtime_error("Invalid traversal mode");
    }
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerIN(AVLnode<D>* root,const size_t index,size_t& count) const{
    STACK<AVLnode<D>*> S(elem); AVLnode<D>* curr=root;
    while(curr || !S.empty()){
        while(curr){ 
            S.push(curr); curr=curr->LINK[L]; 
        }
        curr=S.pop(); if(count==index) return curr; count++;
        curr=curr->LINK[R];
    }
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerR_IN(AVLnode<D>* root,const size_t index,size_t& count) const{
    STACK<AVLnode<D>*> S(elem); AVLnode<D>* curr=root;
    while(curr || !S.empty()){
        while(curr){ 
            S.push(curr); curr=curr->LINK[R]; 
        }
        curr=S.pop(); if(count==index) return curr; count++;
        curr=curr->LINK[L];
    }
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerPRE(AVLnode<D>* root,const size_t index,size_t& count) const{
    if(!root) return nullptr;
    AVLnode<D>* curr=root; STACK<AVLnode<D>*> S(elem);
    do{
        while(curr){ if(count==index) return curr; count++;
            
            if(curr->LINK[R]) S.push(curr->LINK[R]);
            curr=curr->LINK[L];
        }
        if(!S.empty()) curr=S.pop();
    }while(curr);
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerPOST(AVLnode<D>* root,const size_t index,size_t& count) const{
    if(!root) return nullptr;
    STACK<AVLnode<D>*> S(elem);
    AVLnode<D>* curr=root,*last=nullptr;
    do{
        while(curr){
            S.push(curr); curr=curr->LINK[L]; 
        }
        curr=S.tos();

        if(curr->LINK[R] && last!=curr->LINK[R]) 
            curr=curr->LINK[R];
        else{
            if(count==index) return curr;
            count++; last=S.pop(); curr=nullptr;
        }
    } while(!S.empty()); return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerBFS(const size_t index, bool order) const{
    if(!ROOT) return nullptr;
    size_t count=0;
    QUEUE<AVLnode<D>*> Q(elem); Q.enqueue(ROOT);
    AVLnode<D>* tmp;
    while(!Q.empty()){
        tmp=Q.dequeue();
        if(index == count) return tmp;   count++;
        if(order){
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        }else{
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
        }
    }
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointerDFS(const size_t index, bool order) const{
    if(!ROOT) return nullptr; 
    size_t count=0;
    STACK<AVLnode<D>*> S(elem); S.push(ROOT);
    AVLnode<D>* tmp;
    while(!S.empty()){
        tmp=S.pop();
        if(index == count) return tmp;   count++;
        if(order){
            if(tmp->LINK[R]) S.push(tmp->LINK[R]);
            if(tmp->LINK[L]) S.push(tmp->LINK[L]);
        }else{
            if(tmp->LINK[L]) S.push(tmp->LINK[L]);
            if(tmp->LINK[R]) S.push(tmp->LINK[R]);
        }
    }
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::pointer(std::ptrdiff_t index, MODE mode) const{
    if(index < 0) index = static_cast<std::ptrdiff_t>(elem) + index;
    if(index<0 || static_cast<size_t>(index)>=elem) return nullptr;

    size_t count = 0;  if(mode == MODE::DEF) mode=M;
    switch(mode){
        case MODE::DFS: return pointerDFS(static_cast<size_t>(index));
        case MODE::BFS: return pointerBFS(static_cast<size_t>(index));

        case MODE::IN:   return pointerIN(ROOT, static_cast<size_t>(index), count);
        case MODE::R_IN: return pointerR_IN(ROOT, static_cast<size_t>(index), count);
        case MODE::PRE:  return pointerPRE(ROOT, static_cast<size_t>(index), count);
        case MODE::POST: return pointerPOST(ROOT, static_cast<size_t>(index), count);

        case MODE::DFS_RL: return pointerDFS(static_cast<size_t>(index), false);
        case MODE::BFS_RL: return pointerBFS(static_cast<size_t>(index), false);

        default:
            throw std::runtime_error("Invalid traversal mode");
    }
}

template<typename D>  
const D& AVLTREE<D>::operator[](const std::ptrdiff_t index) const{
    if(!ROOT) throw std::runtime_error("Tree is empty"); 

    const AVLnode<D>* ptr=pointer(index);
    if(!ptr) throw std::out_of_range("Index out of bounds"); 
    return ptr->K;
}

template<typename D>
bool AVLTREE<D>::freelink(AVLnode<D>*& root){
    if(!root) return false;
    QUEUE<AVLnode<D>*> Q; 
    AVLnode<D>* tmp;
        if(root->LINK[L]) Q.enqueue(root->LINK[L]);
        if(root->LINK[R]) Q.enqueue(root->LINK[R]);
    while(!Q.empty()){
        tmp=Q.dequeue();
            if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
            if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        delete tmp;
    }
    root->LINK[L]=nullptr; root->LINK[R]=nullptr; 
    return true;
}

template<typename D>
bool AVLTREE<D>::search(D item){
    AVLnode<D>* ptr=ROOT;
    while(ptr){ 
        if(item<ptr->K) ptr=ptr->LINK[L];
        else if(item>ptr->K) ptr=ptr->LINK[R];
        else return true;
    } 
    return false;
}

template<typename D>
AVLiterator<D> AVLTREE<D>::begin() noexcept{
    AVLiterator<D> it(M,elem,ROOT);  return ++it;
}

template<typename D>
AVLiterator<D> AVLTREE<D>::end() noexcept{ return AVLiterator<D>(M,0,nullptr); }

template<typename D>
AVLiterator<D> AVLTREE<D>::begin() const noexcept{
        AVLiterator<D> it(M,elem,ROOT);  return ++it;
}

template<typename D>
AVLiterator<D> AVLTREE<D>::end() const noexcept{ return AVLiterator<D>(M,0,nullptr); }

template<typename D>
char AVLTREE<D>::subH(AVLnode<D>* sub) const noexcept{ if(!sub) return 0;   return 1+ sub->H; }

template<typename D>
char AVLTREE<D>::balanceH(char leftH, char rightH) const noexcept{
    char balance = leftH-rightH;
    if(balance<2 && balance>-2) return (leftH > rightH ? leftH : rightH);
    return -1;
}

template<typename D>
AVLnode<D>* AVLTREE<D>::balance(AVLnode<D>* AVL){ 
        
    if(subH(AVL->LINK[L]) > subH(AVL->LINK[R])){ 
        AVLnode<D>* left=AVL->LINK[L];
        AVLnode<D>* leftright=left->LINK[R];

        if(subH(left->LINK[L]) < subH(leftright)){ 
            left->LINK[R]=leftright->LINK[L];  AVL->LINK[L]= leftright->LINK[R];
            leftright->LINK[L]=left;       leftright->LINK[R]=AVL;
            
            left->H=balanceH(subH(left->LINK[L]),subH(leftright));  
            AVL->H=balanceH(subH(AVL->LINK[L]),subH(AVL->LINK[R]));
            AVL=leftright; 
        } else { 
            AVL->LINK[L]=leftright;  left->LINK[R]=AVL;
            
            left->LINK[L]->H=balanceH(subH(left->LINK[L]->LINK[L]), subH(left->LINK[L]->LINK[R]));  
            AVL->H=balanceH(subH(AVL->LINK[L]), subH(AVL->LINK[R]));
            AVL=left; 
        }
    }
    else { 
        AVLnode<D>* right=AVL->LINK[R];
        AVLnode<D>* rightleft=right->LINK[L];

        if(subH(rightleft) < subH(right->LINK[R])){ 
            AVL->LINK[R]=rightleft;
            right->LINK[L]=AVL;

            AVL->H=balanceH(subH(AVL->LINK[L]), subH(AVL->LINK[R]));  
            right->LINK[R]->H=balanceH(subH(right->LINK[R]->LINK[L]), subH(right->LINK[R]->LINK[R]));
            AVL=right; 
        } else { 
            AVL->LINK[R]=rightleft->LINK[L];  right->LINK[L]=rightleft->LINK[R];
            rightleft->LINK[L]=AVL;           rightleft->LINK[R]=right;

            AVL->H=balanceH(subH(AVL->LINK[L]), subH(AVL->LINK[R]));  
            right->H=balanceH(subH(rightleft), subH(right->LINK[R]));
            AVL=rightleft; 
        } 
    }

    if(AVL->LINK[L]->H == -1) AVL->LINK[L] = balance(AVL->LINK[L]);
    if(AVL->LINK[R]->H == -1) AVL->LINK[R] = balance(AVL->LINK[R]);

    AVL->H=balanceH(subH(AVL->LINK[L]), subH(AVL->LINK[R]));
    
    return AVL;
}

template<typename D> 
D AVLTREE<D>::deleting(AVLnode<D>* point, bool f1, bool f2){  D tmp; bool f=false;
    if(f1){
        if(f2){
            if(point->LINK[R]){
                tmp=deleting(point->LINK[R],true,true);
                if(f0){
                    delete point->LINK[R]; point->LINK[R]=nullptr; f0=false; elem--;
                }else{
                    if(AVL) point->LINK[R]=AVL; AVL=nullptr; 
                }
            }else return deleting(point,false);
        }else{
            if(point->LINK[L]){
                tmp=deleting(point->LINK[L],true);
                if(f0){
                    delete point->LINK[L]; point->LINK[L]=nullptr; f0=false; elem--;
                }else{
                    if(AVL) point->LINK[L]=AVL; AVL=nullptr;
                }
            }else return deleting(point,false);
        }
        point->H=balanceH(subH(point->LINK[L]), subH(point->LINK[R]));
        if(-1 == point->H) AVL=balance(point); 
        return tmp;

    }else{
        if(!point->LINK[L] && !point->LINK[R]){ f0=true; return point->K; }
        else if(point->LINK[L] && !point->LINK[R]){
            tmp=point->K; f=true;
            point->K=point->LINK[L]->K;
            delete point->LINK[L]; point->LINK[L]=nullptr; elem--;
        }
        else if(!point->LINK[L] && point->LINK[R]){
            tmp=point->K; f=true;
            point->K=point->LINK[R]->K;
            delete point->LINK[R]; point->LINK[R]=nullptr; elem--;
        }
        else{
            if(subH(point->LINK[L]) >= subH(point->LINK[R])){
                if(point->LINK[L]->LINK[R]){
                    point->K=deleting(point->LINK[L]->LINK[R],true,true);
                    if(f0){  
                        delete point->LINK[L]->LINK[R]; point->LINK[L]->LINK[R]=nullptr; f0=false; elem--;
                    }
                    point->LINK[L]->H=balanceH(subH(point->LINK[L]->LINK[L]), subH(point->LINK[L]->LINK[R]));
                    if(-1 == point->LINK[L]->H) 
                        point->LINK[L]=balance(point->LINK[L]);
                }else{
                    point->K=deleting(point->LINK[L],false);
                    if(f0){  
                        delete point->LINK[L]; point->LINK[L]=nullptr; f0=false; elem--;
                    }
                }
            }else{
                if(point->LINK[R]->LINK[L]){
                    point->K=deleting(point->LINK[R]->LINK[L],true);
                    if(f0){  
                        delete point->LINK[R]->LINK[L]; point->LINK[R]->LINK[L]=nullptr; f0=false;  elem--;
                    }
                    point->LINK[R]->H=balanceH(subH(point->LINK[R]->LINK[L]), subH(point->LINK[R]->LINK[R]));
                    if(-1 == point->LINK[R]->H) 
                        point->LINK[R]=balance(point->LINK[R]);
                }else{
                    point->K=deleting(point->LINK[R],false);
                    if(f0){  
                        delete point->LINK[R]; point->LINK[R]=nullptr; f0=false; elem--;
                    }
                }
            }
        }
        point->H=balanceH(subH(point->LINK[L]), subH(point->LINK[R]));
        if(-1 == point->H) AVL=balance(point);
        return f? tmp : point->K;
    }
}

template<typename D>
bool AVLTREE<D>::remove_(D item, AVLnode<D>* root){
    if(root->K > item){  
        if(root->LINK[L]){
            if(remove_(item,root->LINK[L])){ delete root->LINK[L]; root->LINK[L]=nullptr; elem--; }
            else if(AVL){
                root->LINK[L]=AVL; AVL=nullptr;
            }
        }else return false;

    }else if(root->K < item){ 
        if(root->LINK[R]){
            if(remove_(item,root->LINK[R])){ delete root->LINK[R]; root->LINK[R]=nullptr; elem--; }
            else if(AVL){
                root->LINK[R]=AVL; AVL=nullptr;
            }
        }else return false;

    }else{  
        deleting(root,false); 
        if(f0) return true;   f0=true;  
    }
    
    if(f0){
        root->H=balanceH(subH(root->LINK[L]), subH(root->LINK[R])); 
        if(-1 == root->H)
            AVL=balance(root); 
    }return false;  
}

template<typename D>
bool AVLTREE<D>::remove(D item){
    if(!ROOT) return false;
    if(ROOT->K == item){
        deleting(ROOT,false);
        if(f0){ delete ROOT; ROOT=nullptr; f0=false; elem--; }
        else if(AVL){ ROOT=AVL; AVL=nullptr; }
    }else{
        remove_(item,ROOT); f0=false;
        if(AVL){ ROOT=AVL; AVL=nullptr; }
    }   
    return false; 
}

template<typename D>
bool AVLTREE<D>::remove_index(std::ptrdiff_t index, MODE mode){
    if(!ROOT) return false;
    AVLnode<D>* tmp=pointer(index,mode);
    if(!tmp) throw std::out_of_range("Index out of bounds"); 
     
    return remove(tmp->K);
}

template<typename D>
void AVLTREE<D>::clear(){ freelink(ROOT); delete ROOT; ROOT=nullptr; }

template<typename D>
AVLnode<D>* AVLTREE<D>::create(D item){  elem++;
    AVLnode<D>* ptr=new AVLnode<D>;

    ptr->H=0; ptr->K=item;
    ptr->LINK[L]=nullptr; ptr->LINK[R]=nullptr; 

    return ptr;
}

template<typename D>
bool AVLTREE<D>::insert_(D item, AVLnode<D>* root){
    if(root->K > item){
        if(!root->LINK[L]){
            root->LINK[L]=create(item); 
            root->H=balanceH(subH(root->LINK[L]), subH(root->LINK[R])); 
            return true;
        }else{
            if(insert_(item,root->LINK[L])) root->H=balanceH(subH(root->LINK[L]), subH(root->LINK[R]));
            else if(AVL){
                if(root->K > AVL->K) root->LINK[L]=AVL;
                else root->LINK[R]=AVL;
                AVL=nullptr; return false;
            }else return false;
        }
    }else if(root->K < item){
        if(!root->LINK[R]){
            root->LINK[R]=create(item);
            root->H=balanceH(subH(root->LINK[L]), subH(root->LINK[R]));  
            return true;
        }else{
            if(insert_(item,root->LINK[R])) root->H=balanceH(subH(root->LINK[L]), subH(root->LINK[R]));
            else if(AVL){
                if(root->K > AVL->K) root->LINK[L]=AVL;
                else root->LINK[R]=AVL;
                AVL=nullptr; return false;
            }else return false;
        }
    }else return false;

    if(-1 != root->H) return true; 
    AVL=balance(root);  return false;
}

template<typename D>
void AVLTREE<D>::insert(D item){ 
    if(!ROOT){ ROOT=create(item); }
    else{
        insert_(item,ROOT);
        if(AVL){
            ROOT=AVL; AVL=nullptr;
        }
    } 
}



//----------------------------------------------------------------------------------------- iterator

template<typename D>
AVLiterator<D>::AVLiterator(MODE mode, size_t capacity, AVLnode<D>* p) 
                            : ptr(nullptr), last(nullptr), ROOT(p), M(mode), S(capacity), Q(capacity) {
    if(!ROOT) return;

    switch(M){
        case MODE::BFS:
        case MODE::BFS_RL:
            Q.enqueue(ROOT); break;

        case MODE::DFS:
        case MODE::DFS_RL:

        case MODE::PRE:
            S.push(ROOT); break;

        case MODE::IN:
        case MODE::POST:
        {
            AVLnode<D>* temp = ROOT;
            while(temp){
                S.push(temp);
                temp = temp->LINK[L];
            } break;
        }
		
        case MODE::R_IN:
        {
            AVLnode<D>* temp = ROOT;
            while(temp){
                S.push(temp);
                temp = temp->LINK[R];
            } break;
        }

        default: break;
    }
}
    
template <typename D>
AVLnode<D>* AVLiterator<D>::incrementBFS(){
    if(Q.empty()) return nullptr;
    AVLnode<D>* tmp = Q.dequeue();

    if(M == MODE::BFS){
        if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
        if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
    }else{
        if(tmp->LINK[R]) Q.enqueue(tmp->LINK[R]);
        if(tmp->LINK[L]) Q.enqueue(tmp->LINK[L]);
    }
    return tmp;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::incrementDFS(){
    if(S.empty()) return nullptr;
    AVLnode<D>* tmp = S.pop();

    if(M == MODE::DFS){
        if(tmp->LINK[R]) S.push(tmp->LINK[R]);
        if(tmp->LINK[L]) S.push(tmp->LINK[L]);
    }else{
        if(tmp->LINK[L]) S.push(tmp->LINK[L]);
        if(tmp->LINK[R]) S.push(tmp->LINK[R]);
    }
    return tmp;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::incrementIN(){
    if(S.empty()) return nullptr;
    AVLnode<D>* node = S.pop();

    AVLnode<D>* tmp = node->LINK[R];
    while(tmp){
        S.push(tmp);
        tmp = tmp->LINK[L];
    }
    return node;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::incrementR_IN(){
    if(S.empty()) return nullptr;
    AVLnode<D>* node = S.pop();

    AVLnode<D>* tmp = node->LINK[L];
    while(tmp){
        S.push(tmp);
        tmp = tmp->LINK[R];
    }
    return node;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::incrementPRE(){
    if(S.empty()) return nullptr;
    AVLnode<D>* node = S.pop();

    if(node->LINK[R]) S.push(node->LINK[R]);
    if(node->LINK[L]) S.push(node->LINK[L]);
    return node;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::incrementPOST(){
    while(!S.empty()){
        AVLnode<D>* peek = S.tos();
        AVLnode<D>* right = peek->LINK[R];

        if(right && last != right){
            AVLnode<D>* tmp = right;
            while(tmp){
                S.push(tmp);
                tmp = tmp->LINK[L];
            }
        }else{
            S.pop();
            last = peek;
            return peek;
        }
    }
    return nullptr;
}

template<typename D>
AVLnode<D>* AVLiterator<D>::increment(){
    switch(M){
        case MODE::BFS: 
        case MODE::BFS_RL: 
            return incrementBFS();

        case MODE::DFS: 
        case MODE::DFS_RL: 
            return incrementDFS();

        case MODE::IN:   return incrementIN();
        case MODE::R_IN: return incrementR_IN();
        case MODE::PRE:  return incrementPRE();
        case MODE::POST: return incrementPOST();

        default: return nullptr;
    }
}

template<typename D>
D& AVLiterator<D>::operator*(){
    if(!ptr) throw std::runtime_error("Null iterator");
    return ptr->K;
}

template<typename D>
const D& AVLiterator<D>::operator*() const{
    if(!ptr) throw std::runtime_error("Null iterator");
    return ptr->K;
}

template<typename D>
AVLiterator<D>& AVLiterator<D>::operator++() noexcept{
    ptr = increment();
    return *this;
}

template<typename D>
AVLiterator<D> AVLiterator<D>::operator++(int) noexcept{
    AVLiterator<D> temp = *this; 
    ptr = increment();
    return temp;
}

template<typename D>
bool AVLiterator<D>::operator!=(const AVLiterator<D>& other) const noexcept{ return ptr != other.ptr; }

template<typename D>
bool AVLiterator<D>::operator==(const AVLiterator<D>& other) const noexcept{ return ptr == other.ptr; }

template<typename D>
D* AVLiterator<D>::operator->(){ 
    if(!ptr) throw std::runtime_error("Null iterator");
    return &(ptr->K); 
}

template<typename D>
const D* AVLiterator<D>::operator->() const{ 
    if(!ptr) throw std::runtime_error("Null iterator");
    return &(ptr->K); 
}


template<typename D>
std::ostream& operator<<(std::ostream& out, const AVLTREE<D>& AVL){  AVL.view(); return out;  }
