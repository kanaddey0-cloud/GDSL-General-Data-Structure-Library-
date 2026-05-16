#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include "Linear/Stack.hpp"
#include "Linear/Queue/SimpleQueue.hpp"
#include "NonLinear/Tree/Mode.hpp"


template<typename D>
struct BSTnode{ D K; BSTnode<D>** LINK; };

template<typename D>
class BSTiterator { 
    BSTnode<D>* ptr, *ROOT, *last;
    STACK<BSTnode<D>*> S;
    QUEUE<BSTnode<D>*> Q;
public:
    MODE M;
    BSTiterator(MODE mode, BSTnode<D>* p = nullptr);
    BSTnode<D>* increment();
    BSTnode<D>* incrementBFS();
    BSTnode<D>* incrementDFS();
    BSTnode<D>* incrementIN();
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
    unsigned long int elem=0;
    unsigned int LC: 2;
    BSTnode<D>* ROOT=nullptr;
    BSTnode<D>* create(D item, BSTnode<D>* parent=nullptr);
    void print_Key_L_C_R(const BSTnode<D>* tmp) const;
    bool deleting(BSTnode<D>*& del, BSTnode<D>* tmp);
    bool freelink(BSTnode<D>*& root);
    unsigned long int addlink(BSTnode<D>*& root, const BSTnode<D>*& other);
    BSTnode<D>* pointer(long int index, MODE mode=MODE::DEF) const;
    BSTnode<D>* pointerBFS(const unsigned long int index, bool order=false) const;
    BSTnode<D>* pointerDFS(const unsigned long int index, bool order=false) const;
    BSTnode<D>* pointerIN(BSTnode<D>* root, const unsigned long int index, unsigned long int& count) const;
    BSTnode<D>* pointerPRE(BSTnode<D>* root, const unsigned long int index, unsigned long int& count) const;
    BSTnode<D>* pointerPOST(BSTnode<D>* root, const unsigned long int index, unsigned long int& count) const;
public:
    MODE M=MODE::IN;
    BSTREE(bool l=false);
    BSTREE(const BSTREE<D>& other);
    BSTREE(BSTREE<D>&& other) noexcept;
    BSTREE& operator=(const BSTREE& other);
    BSTREE& operator=(BSTREE&& other) noexcept;
    D& operator[](const long int index);
    const D& operator[](const long int index) const;
    long int size() const { return elem; }
    bool insert(D item);
    void insert_array(D arr[], size_t SIZE);
    void insert_index(D arr[], size_t LOW, size_t HIGH);
    bool search(D item);
    bool remove(D item);
    bool add(const BSTREE<D>& root);
    void view(MODE mode=MODE::DEF) const;
    void viewDFS(bool order=false) const;
    void viewBFS(bool order=false) const;
    void viewIN(const BSTnode<D>* root) const;
    void viewPRE(const BSTnode<D>* root) const;
    void viewPOST(const BSTnode<D>* root) const;
    BSTiterator<D> begin() noexcept;
    BSTiterator<D> begin() const noexcept;
    BSTiterator<D> end() noexcept;
    BSTiterator<D> end() const noexcept;
    ~BSTREE();
};

#include "src/NonLinear/Tree/BinarySearchTree.tpp"

#endif