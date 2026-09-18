#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <stdexcept>


template<typename D>
struct LISTnode{ D K; LISTnode<D> *P; }; 


template<typename D>
class LISTiterator { 
    LISTnode<D>* ptr; 
public:
    LISTiterator(LISTnode<D>* p = nullptr);
	
    D& operator*();
    const D& operator*() const;
	
    LISTiterator& operator++() noexcept;
    LISTiterator operator++(int) noexcept;
	
    bool operator!=(const LISTiterator& other) const noexcept;
    bool operator==(const LISTiterator& other) const noexcept;
	bool operator<(const LISTiterator<D>& other) const noexcept;
	bool operator<=(const LISTiterator<D>& other) const noexcept;
	bool operator>(const LISTiterator<D>& other) const noexcept;
	bool operator>=(const LISTiterator<D>& other) const noexcept;
	
    D* operator->();
    const D* operator->() const;
};


template<typename D>
class LIST{
protected:
    size_t elem; 
    LISTnode<D>* H, *T;
	
    LISTnode<D>* pointer(std::ptrdiff_t index) const;
    void rotate(LISTnode<D>*& head, LISTnode<D>*& tail);
    size_t clear(LISTnode<D>*& p);
    size_t clearupto(LISTnode<D>*& head, LISTnode<D>*& tail);

    LISTnode<D>* mergeSort(LISTnode<D>* head);
    LISTnode<D>* merge(LISTnode<D>* left, LISTnode<D>* right);
    LISTnode<D>* middle(LISTnode<D>* head);

public:
    LIST(std::initializer_list<D> init);
    LIST();
    LIST(const LIST<D>& other);
    LIST(LIST<D>&& other) noexcept;
    ~LIST();

    size_t size() const { return elem; }
    bool insert(D val, std::ptrdiff_t index = -1);
    size_t drop(D val);
    D remove(std::ptrdiff_t index);
    size_t update(D prev, D curr, bool in = false);
    D modify(D curr, std::ptrdiff_t index);
    bool add(const LIST<D>& next);
    const D& value(std::ptrdiff_t index) const;
    size_t index(D value) const;
    void reverse();
    void view(bool v = false) const;
    void sort();

    D& operator[](const std::ptrdiff_t index);
    const D& operator[](const std::ptrdiff_t index) const;
    LIST<D>& operator=(const LIST<D>& other);
    LIST<D>& operator=(LIST<D>&& other) noexcept;

    bool operator==(const LIST<D>& other) const noexcept;
    bool operator!=(const LIST<D>& other) const noexcept;
    bool operator<(const LIST<D>& other) const noexcept;
    bool operator<=(const LIST<D>& other) const noexcept;
    bool operator>(const LIST<D>& other) const noexcept;
    bool operator>=(const LIST<D>& other) const noexcept;

    LISTiterator<D> begin() noexcept;
    LISTiterator<D> end() noexcept;
    LISTiterator<D> begin() const noexcept;
    LISTiterator<D> end() const noexcept;
};


#include "GDSL/src/Linear/List/SinglyList.tpp"
// #include "src/Linear/List/SinglyList.tpp"

# endif