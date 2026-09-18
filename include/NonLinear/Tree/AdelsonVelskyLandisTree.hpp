#ifndef ADELSON_VELSKY_LANDIS_TREE
#define ADELSON_VELSKY_LANDIS_TREE

#include <iostream>

#include <gdsl_stack>
#include <gdsl_queue>
#include"GDSL/include/NonLinear/Tree/Types.hpp"

// #include "Linear/Stack.hpp"
// #include "Linear/Queue/SimpleQueue.hpp"
// #include "NonLinear/Tree/Types.hpp"


template<typename D>
struct AVLnode{ int H: 8; D K; AVLnode<D>* LINK[2]; };


template<typename D>
class AVLiterator { 
    AVLnode<D>* ptr, *ROOT, *last;
    STACK<AVLnode<D>*> S;
    QUEUE<AVLnode<D>*> Q;

public:
    MODE M;
    AVLiterator(MODE mode, size_t capacity, AVLnode<D>* p = nullptr);
	
    AVLnode<D>* increment();
    AVLnode<D>* incrementBFS();
    AVLnode<D>* incrementDFS();
    AVLnode<D>* incrementIN();
    AVLnode<D>* incrementR_IN();
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
    size_t elem=0;
    AVLnode<D>* ROOT=nullptr, *AVL=nullptr;
    bool f0=false;
	
    AVLnode<D>* create(D item);
    void print_Key_L_C_R(const AVLnode<D>* tmp) const;
    bool insert_(D item, AVLnode<D>* root);
    bool remove_(D item, AVLnode<D>* root);
    D deleting(AVLnode<D>* point, bool f1, bool f2=false);
    bool freelink(AVLnode<D>*& root);
    size_t addlink(AVLnode<D>*& root, const AVLnode<D>*& other);
	
	char subH(AVLnode<D>* sub) const noexcept;
    char balanceH(char leftH, char rightH) const noexcept;
    AVLnode<D>* balance(AVLnode<D>* AVL);
	
    void _viewPOST(const AVLnode<D>* root) const;
    AVLnode<D>* pointer(std::ptrdiff_t index, MODE mode=MODE::DEF) const;
    AVLnode<D>* pointerBFS(const size_t index, bool order=true) const;
    AVLnode<D>* pointerDFS(const size_t index, bool order=true) const;
    AVLnode<D>* pointerIN(AVLnode<D>* root, const size_t index, size_t& count) const;
    AVLnode<D>* pointerR_IN(AVLnode<D>* root, const size_t index, size_t& count) const;
    AVLnode<D>* pointerPRE(AVLnode<D>* root, const size_t index, size_t& count) const;
    AVLnode<D>* pointerPOST(AVLnode<D>* root, const size_t index, size_t& count) const;
	
public:
    MODE M=MODE::IN;
    AVLTREE()=default;
    AVLTREE(const AVLTREE<D>& other);
    AVLTREE(AVLTREE<D>&& other) noexcept;
    ~AVLTREE();

    AVLTREE& operator=(const AVLTREE& other);
    AVLTREE& operator=(AVLTREE&& other) noexcept;
    const D& operator[](const std::ptrdiff_t index) const;
	
    long int size() const { return elem; }
    bool search(D item);
    void insert(D item);
    bool remove(D item);
    bool remove_index(std::ptrdiff_t index, MODE mode=MODE::DEF);
	void clear();
    bool add(const AVLTREE<D>& root);
    void view(MODE mode=MODE::DEF) const;
    void viewDFS(bool order=true) const;
    void viewBFS(bool order=true) const;
    void viewIN() const;
    void viewR_IN() const;
    void viewPRE() const;
    void viewPOST() const;
	
    AVLiterator<D> begin() noexcept;
    AVLiterator<D> begin() const noexcept;
    AVLiterator<D> end() noexcept;
    AVLiterator<D> end() const noexcept;
};


#include "GDSL/src/NonLinear/Tree/AdelsonVelskyLandisTree.tpp"
// #include "src/NonLinear/Tree/AdelsonVelskyLandisTree.tpp"

#endif