# ifndef SINGLY_LINKED_LIST
# define SINGLY_LINKED_LIST

#include <iostream>
#include <stdexcept>

template<typename D>
struct node{ D K; node<D> *P; }; 

template<typename D>
class iterator { 
    node<D>* ptr; 
public:
    iterator(node<D>* p = nullptr);
    D& operator*();
    const D& operator*() const;
    iterator& operator++() noexcept;
    iterator operator++(int) noexcept;
    bool operator!=(const iterator& other) const noexcept;
    bool operator==(const iterator& other) const noexcept;
    D* operator->();
    const D* operator->() const;
};

template<typename D>
class LIST{
protected:
    long int elem; 
    node<D>* H, *T;
    node<D>* pointer(long int index) const;
    void rotate(node<D>*& head, node<D>*& tail);
    long int clear(node<D>*& p);
    long int clearupto(node<D>*& head, node<D>*& tail);
public:
    LIST();
    LIST(const LIST<D>& other);
    LIST(LIST<D>&& other) noexcept;
    D& operator[](const long int index);
    const D& operator[](const long int index) const;
    LIST<D>& operator=(const LIST<D>& other);
    LIST<D>& operator=(LIST<D>&& other) noexcept;
    long int size() const { return elem; }
    bool insert(D val, long int index=-1);
    long int drop(D val);
    D remove(long int index);
    long int update(D prev, D curr, bool in=false);
    D modify(D curr, long int index);
    bool add(const LIST<D>& next);
    const D& value(long int index) const;
    long int index(D value) const;
    void reverse();
    void view(bool v=true) const;
    iterator<D> begin() noexcept;
    iterator<D> begin() const noexcept;
    iterator<D> end() noexcept;
    iterator<D> end() const noexcept;
    ~LIST();
};

#include "src/Linear/List/SinglyList.tpp"

# endif