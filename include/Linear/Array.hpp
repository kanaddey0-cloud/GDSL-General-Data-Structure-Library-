#ifndef ARRAY_CONTIGUOUS 
#define ARRAY_CONTIGUOUS 

#include <iostream>

#include <cmath>
#include <cstdlib>


enum class GROWTH : char {
    GINS='l', GDEL='m', GSRC='o'
};

enum class SORT : char {
    BUBBLE='A', SELECTION='B', INSERTION='C', MERGE='D', QUICK='E',
    HEAP='F', SHELL='G', ODDEVEN='H', CYCLE='I', COUNTING='J',
    RADIX='K', BUCKET='L', INTRO='M', TIM='N',
    PDQ='O', DUAL_PIVOT='P', EXTERNAL_MERGE='Q',
    K_WAY_MERGE='R', BITONIC='S'
};


template<typename D>
class ARRAYreverse_iterator{ 
    D* ptr;
	
public:
    ARRAYreverse_iterator(D* p = nullptr);

    D& operator*();
    const D& operator*() const;

    ARRAYreverse_iterator<D>& operator++() noexcept;
    ARRAYreverse_iterator<D> operator++(int) noexcept;

    ARRAYreverse_iterator<D>& operator--() noexcept;
    ARRAYreverse_iterator<D> operator--(int) noexcept;

    bool operator!=(const ARRAYreverse_iterator<D>& other) const noexcept;
    bool operator==(const ARRAYreverse_iterator<D>& other) const noexcept;
    bool operator<(const ARRAYreverse_iterator& other) const noexcept;
    bool operator<=(const ARRAYreverse_iterator& other) const noexcept;
    bool operator>(const ARRAYreverse_iterator& other) const noexcept;
    bool operator>=(const ARRAYreverse_iterator& other) const noexcept;

    D* operator->();
    const D* operator->() const;
};



template<typename D>
class ARRAYiterator{ 
    D* ptr;
	
public:
    ARRAYiterator(D* p = nullptr);

    D& operator*();
    const D& operator*() const;

    ARRAYiterator<D>& operator++() noexcept;
    ARRAYiterator<D> operator++(int) noexcept;

    ARRAYiterator<D>& operator--() noexcept;
    ARRAYiterator<D> operator--(int) noexcept;

    bool operator!=(const ARRAYiterator<D>& other) const noexcept;
    bool operator==(const ARRAYiterator<D>& other) const noexcept;
    bool operator<(const ARRAYiterator& other) const noexcept;
    bool operator<=(const ARRAYiterator& other) const noexcept;
    bool operator>(const ARRAYiterator& other) const noexcept;
    bool operator>=(const ARRAYiterator& other) const noexcept;

    D* operator->();
    const D* operator->() const;
}; 


template<typename D>
class ARRAY {
protected:
    size_t Gsrc=0, Gins=0, Gdel=0;
    size_t C=2, S=0;
	bool sd=false;
    D *DATA=nullptr;

    void mergeSort(size_t left, size_t right, D* temp, bool ascend);
    void merge(size_t left, size_t mid, size_t right, D* temp, bool ascend);
    void quickSort(size_t low, size_t high, bool ascend);
    size_t partition(size_t low, size_t high, bool ascend);
    size_t medianOfThree(size_t low, size_t high, bool ascend);
    void heapify(size_t n, size_t root, bool ascend);
    void countingSort(size_t exp, bool ascend);
    void bucketInsertion(D* bucket, size_t n, bool ascend);
    void introSort(size_t low, size_t high, size_t depth, bool ascend);
    size_t introPartition(size_t low, size_t high, bool ascend);
    void timMerge(size_t left, size_t mid, size_t right, bool ascend);
    void timInsertion(size_t left, size_t right, bool ascend);
    void patternDefeatingQuickSort(size_t low, size_t high, size_t depth, bool ascend);
    size_t pdqPartition(size_t low, size_t high, bool ascend);
    bool isRangeSorted(size_t low, size_t high, bool ascend);
    void dualPivotQuickSort(size_t low, size_t high, bool ascend);
    void dualPivotPartition(size_t low, size_t high, size_t& leftPivot, size_t& rightPivot, bool ascend);
    void kWayMergeSort(size_t left, size_t right, size_t k, bool ascend);
    void kWayMerge(size_t left, size_t right, size_t k, bool ascend);
    void bitonicSort(size_t low, size_t count, bool ascend);
    void bitonicMerge(size_t low, size_t count, bool ascend);

    void growth(GROWTH G);
	
public:
    ARRAY(std::initializer_list<D> init);
    ARRAY(size_t len=2);
    ARRAY(const ARRAY& other);
    ARRAY(ARRAY&& other) noexcept;
    ~ARRAY();

    bool insert(D val, long int index=-1);
    size_t drop(D val, bool dup=true);
    D remove(long int index=-1);
    size_t size() const noexcept;
    size_t capacity(size_t len=0) noexcept;
    bool length(long int len, bool f=true);
    size_t resize(bool f);
    void view(bool forward=true) const noexcept;
    void reverse() noexcept;
	
    ARRAY& operator=(const ARRAY& other);
    ARRAY& operator=(ARRAY&& other) noexcept;
    D& operator[](std::ptrdiff_t index);
    const D& operator[](std::ptrdiff_t index) const;

    bool operator==(const ARRAY& other) const noexcept;
    bool operator!=(const ARRAY& other) const noexcept;
    bool operator<(const ARRAY& other) const noexcept;
    bool operator<=(const ARRAY& other) const noexcept;
    bool operator>(const ARRAY& other) const noexcept;
    bool operator>=(const ARRAY& other) const noexcept;

    bool search_linear(const D& value, size_t &index) noexcept;
    bool search_binary(const D& value, size_t &index) noexcept;

    void sort(SORT S, bool ascend=true);
    void sort_bubble(bool ascend=true);
    void sort_selection(bool ascend=true);
    void sort_insertion(bool ascend=true);
    void sort_merge(bool ascend=true);
    void sort_quick(bool ascend=true);
    void sort_heap(bool ascend=true);
    void sort_shell(bool ascend=true);
    void sort_oddeven(bool ascend=true);
    void sort_cycle(bool ascend=true);
    void sort_counting(bool ascend=true);
    void sort_radix(bool ascend=true);
    void sort_bucket(bool ascend=true);
    void sort_intro(bool ascend=true);
    void sort_tim(bool ascend=true);
    void sort_pattern_defeating_quicksort(bool ascend=true);
    void sort_dual_pivot_quicksort(bool ascend=true);
    void sort_external_merge_sort(bool ascend=true);
    void sort_k_way_merge_sort(bool ascend=true);
    void sort_bitonic_sort(bool ascend=true);
	
    ARRAYiterator<D> begin() noexcept;
    ARRAYiterator<D> end() noexcept;
    ARRAYiterator<D> begin() const noexcept;
    ARRAYiterator<D> end() const noexcept;

    ARRAYreverse_iterator<D> rbegin() noexcept;
    ARRAYreverse_iterator<D> rend() noexcept;
    ARRAYreverse_iterator<D> rbegin() const noexcept;
    ARRAYreverse_iterator<D> rend() const noexcept;
};


#include "GDSL/src/Linear/Array.tpp"
// #include "src/Linear/Array.tpp"

# endif