#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

#include <gdsl_stack>
#include <gdsl_queue>
#include"GDSL/include/NonLinear/Tree/Types.hpp"

// #include "Linear/Stack.hpp"
// #include "Linear/Queue/SimpleQueue.hpp"
// #include "NonLinear/Tree/Types.hpp"


template<typename D>
struct BSTnode{ D K; BSTnode<D>** LINK; };


template<typename D>
class BSTiterator { 
    BSTnode<D>* ptr, *ROOT, *last;
    STACK<BSTnode<D>*> S;
    QUEUE<BSTnode<D>*> Q;
    
public:
    MODE M;
    BSTiterator(MODE mode, size_t capacity, BSTnode<D>* p = nullptr);
	
    BSTnode<D>* increment();
    BSTnode<D>* incrementBFS();
    BSTnode<D>* incrementDFS();
    BSTnode<D>* incrementIN();
    BSTnode<D>* incrementR_IN();
    BSTnode<D>* incrementPRE();
    BSTnode<D>* incrementPOST();
	
    D& operator*();
    const D& operator*() const;
	
    BSTiterator& operator++() noexcept;
    BSTiterator operator++(int) noexcept;
	
    bool operator!=(const BSTiterator& other) const noexcept;
    bool operator==(const BSTiterator& other) const noexcept;
	
    D* operator->();
    const D* operator->() const;
};


template<typename D>
class BSTREE{
protected:
    size_t elem=0;
    unsigned int LC: 2;
    BSTnode<D>* ROOT=nullptr;
    BSTnode<D>* create(D item, BSTnode<D>* parent=nullptr);
    void print_Key_L_C_R(const BSTnode<D>* tmp) const;
    bool deleting(BSTnode<D>*& del, BSTnode<D>* tmp);
    bool freelink(BSTnode<D>*& root);
    size_t addlink(BSTnode<D>*& root, const BSTnode<D>*& other);

    BSTnode<D>* pointer(std::ptrdiff_t index, MODE mode=MODE::DEF) const;
    BSTnode<D>* pointerBFS(size_t index, bool order=true) const;
    BSTnode<D>* pointerDFS(size_t index, bool order=true) const;
    BSTnode<D>* pointerIN(BSTnode<D>* root, size_t index, size_t& count) const;
    BSTnode<D>* pointerR_IN(BSTnode<D>* root, size_t index, size_t& count) const;
    BSTnode<D>* pointerPRE(BSTnode<D>* root, size_t index, size_t& count) const;
    BSTnode<D>* pointerPOST(BSTnode<D>* root, size_t index, size_t& count) const;

public:
    MODE M=MODE::IN;
    BSTREE(bool l=false);
    BSTREE(const BSTREE<D>& other);
    BSTREE(BSTREE<D>&& other) noexcept;
    BSTREE& operator=(const BSTREE& other);
    BSTREE& operator=(BSTREE&& other) noexcept;
    ~BSTREE();

    const D& operator[](const std::ptrdiff_t index) const;
    size_t size() const { return elem; }
    bool insert(D item);
    void insert_array(D arr[], size_t SIZE);
    void insert_array_(D arr[], size_t LOW, size_t HIGH);
    bool search(D item);
    bool remove(D item);
    bool remove_index(std::ptrdiff_t index, MODE mode=MODE::DEF);
    void clear();
    bool add(const BSTREE<D>& root);
    void view(MODE mode=MODE::DEF) const;
    void viewDFS(bool order=true) const;
    void viewBFS(bool order=true) const;
    void viewIN() const;
    void viewR_IN() const;
    void viewPRE() const;
    void viewPOST() const;
	
    BSTiterator<D> begin() noexcept;
    BSTiterator<D> begin() const noexcept;
    BSTiterator<D> end() noexcept;
    BSTiterator<D> end() const noexcept;
};


#include "GDSL/src/NonLinear/Tree/BinarySearchTree.tpp"
// #include "src/NonLinear/Tree/BinarySearchTree.tpp"

#endif