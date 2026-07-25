#ifndef ADELSON_VELSKY_LANDIS_TREE
#define ADELSON_VELSKY_LANDIS_TREE

#include <iostream>

#include <gdsl_stack>
#include <gdsl_queue>
#include"GDSL/include/NonLinear/Tree/Mode.hpp"

// #include "Linear/Stack.hpp"
// #include "Linear/Queue/SimpleQueue.hpp"
// #include "NonLinear/Tree/Mode.hpp"


template<typename D>
struct AVLnode{ int H: 8; D K; AVLnode<D>* LINK[2]; };


template<typename D>
class AVLiterator { 
    AVLnode<D>* ptr, *ROOT, *last;
    STACK<AVLnode<D>*> S;
    QUEUE<AVLnode<D>*> Q;
	
public:
    MODE M;
    AVLiterator(MODE mode, AVLnode<D>* p = nullptr);
	
    AVLnode<D>* increment();
    AVLnode<D>* incrementBFS();
    AVLnode<D>* incrementDFS();
    AVLnode<D>* incrementIN();
    AVLnode<D>* incrementPRE();
    AVLnode<D>* incrementPOST();
	
    D& operator*();
    const D& operator*() const;
	
    AVLiterator& operator++() noexcept;
    AVLiterator operator++(int) noexcept;
	
    bool operator!=(const AVLiterator& other) const noexcept;
    bool operator==(const AVLiterator& other) const noexcept;
	
    D* operator->();
    const D* operator->() const;
};


template<typename D>
class AVLTREE{
protected:
    unsigned long int elem=0;
    AVLnode<D>* ROOT=nullptr, *AVL=nullptr;
    bool f0=false;
	
    AVLnode<D>* create(D item);
    void print_Key_L_C_R(const AVLnode<D>* tmp) const;
    bool insert_(D item, AVLnode<D>* root);
    bool remove_(D item, AVLnode<D>* root);
    D deleting(AVLnode<D>* point, bool f1, bool f2=false);
    bool freelink(AVLnode<D>*& root);
    unsigned long int addlink(AVLnode<D>*& root, const AVLnode<D>*& other);
	char subH(AVLnode<D>* sub) const noexcept;
    char balanceH(char leftH, char rightH) const noexcept;
    AVLnode<D>* balance(AVLnode<D>* AVL);
	
    AVLnode<D>* pointer(long int index, MODE mode=MODE::DEF) const;
    AVLnode<D>* pointerBFS(const unsigned long int index, bool order=false) const;
    AVLnode<D>* pointerDFS(const unsigned long int index, bool order=false) const;
    AVLnode<D>* pointerIN(AVLnode<D>* root, const unsigned long int index, unsigned long int& count) const;
    AVLnode<D>* pointerPRE(AVLnode<D>* root, const unsigned long int index, unsigned long int& count) const;
    AVLnode<D>* pointerPOST(AVLnode<D>* root, const unsigned long int index, unsigned long int& count) const;
	
public:
    MODE M=MODE::IN;
    AVLTREE()=default;
    AVLTREE(const AVLTREE<D>& other);
    AVLTREE(AVLTREE<D>&& other) noexcept;
    ~AVLTREE();

    AVLTREE& operator=(const AVLTREE& other);
    AVLTREE& operator=(AVLTREE&& other) noexcept;
    const D& operator[](const long int index) const;
	
    long int size() const { return elem; }
    bool search(D item);
    void insert(D item);
    bool remove(D item);
    bool remove_index(long int index, MODE mode=MODE::DEF);
	void clear();
    bool add(const AVLTREE<D>& root);
    void view(MODE mode=MODE::DEF) const;
    void viewDFS(bool order=false) const;
    void viewBFS(bool order=false) const;
    void viewIN(const AVLnode<D>* root) const;
    void viewPRE(const AVLnode<D>* root) const;
    void viewPOST(const AVLnode<D>* root) const;
	
    AVLiterator<D> begin() noexcept;
    AVLiterator<D> begin() const noexcept;
    AVLiterator<D> end() noexcept;
    AVLiterator<D> end() const noexcept;
};


#include "GDSL/src/NonLinear/Tree/AdelsonVelskyLandisTree.tpp"
// #include "src/NonLinear/Tree/AdelsonVelskyLandisTree.tpp"

#endif