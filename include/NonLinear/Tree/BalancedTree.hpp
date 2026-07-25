#ifndef BALANCED_TREE
#define BALANCED_TREE

#include <iostream>
#include <cstdint>

#include <gdsl_stack>
#include <gdsl_queue>

// #include "Linear/Stack.hpp"
// #include "Linear/Queue/SimpleQueue.hpp"

enum class NTYPE : char { LF='l', RT='r', IM='m' };


template<typename D>
struct BTnode{
    unsigned short K=0;
    BTnode<D>* P=nullptr; 
    D* KEY; 
    BTnode<D>** LINK;
    BTnode(unsigned short order, char* base);
};


template<typename D>
class BTREE{
protected:
    size_t N=0;
    unsigned short O;
    size_t node=0;
    BTnode<D>* ROOT=nullptr;
	
    BTnode<D>* create();
    void print_BTnode(BTnode<D>* ptr, bool f=false);
    void split(BTnode<D>* curr, D item, BTnode<D>* child);
    void borrowLeftSibling(NTYPE NT, BTnode<D>* left, BTnode<D>* parent, BTnode<D>* node, unsigned short l, unsigned short i=0);
    void borrowRightSibling(NTYPE NT, BTnode<D>* node, BTnode<D>* parent, BTnode<D>* right, unsigned short l, unsigned short i=0);
    void mergeLeftSibling(NTYPE NT, BTnode<D>* left, BTnode<D>* parent, BTnode<D>* node, unsigned short l, unsigned short i=0);
    void mergeRightSibling(NTYPE NT, BTnode<D>* node, BTnode<D>* parent, BTnode<D>* right, unsigned short l, unsigned short i=0);
    void inorderPredecessor(BTnode<D>* pred, BTnode<D>* node, unsigned short i, bool gape=false);
    void inorderSuccessor(BTnode<D>* node, BTnode<D>* succ, unsigned short i);
    void mergeLeftRight(BTnode<D>* left, BTnode<D>* node, BTnode<D>* right, unsigned short i);
    unsigned short link(BTnode<D>* node, BTnode<D>* parent);
    void fillMinimum(BTnode<D>* node, BTnode<D>* parent);
    void deletecase(NTYPE NT, BTnode<D>* node, unsigned short i, unsigned short l=65535);
	
public:
    BTREE(unsigned short order);
    ~BTREE();
	
	size_t size() const { return N; }
    void viewBFS(bool f=false);
    void viewDFS(bool f=false);
    bool search(D item);
    bool insert(D item);
    bool remove(D item);
};


#include "GDSL/src/NonLinear/Tree/BalancedTree.tpp"
// #include "src/NonLinear/Tree/BalancedTree.tpp"

#endif