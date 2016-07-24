#pragma once
#include<type_traits>

template<typename T>
void template_select_sort(T arr[], size_t num)
{
    size_t cur;
    for(size_t i=0;i<num;++i) {
        cur = i;
        for (size_t j = i; j < num; ++j) {
            if(arr[j] < arr[cur]) {
                cur = j;
            }
        }
        std::swap(arr[i], arr[cur]);
    }
}
template<typename T>
class template_queue
{
public:
    T pop();
    void push(T);
    template_queue();
private:
    T* arr;
    size_t b,e,cap;
};
template<typename T>
template_queue<T>::template_queue() : b(0), e(0)
{
    cap = 4;
    arr = new T[cap];
}
template<typename T>
T template_queue<T>::pop()
{
    assert(e - b > 0);
    return arr[b++];
}
template<typename T>
void template_queue<T>::push(T a)
{
    if (e == cap) {
        T* newarr = new T[cap * 2];
        for (size_t i = b; i != e; ++i) {
            std::swap(newarr[i - b], arr[i]);
        }
        arr = newarr;
        e = e - b;
        b = 0;
    }
    arr[e++] = a;
}
template<typename T>
T template_min(T a, T b)
{
    return (std::less<>()(a , b)) ? a : b;
}
template<typename T>
class template_Array
{
    T* data;
    size_t size;
public:
    template_Array(size_t size) : data(new T[size]), size(size)
    {
        assert(size > 0);
    }

    T& operator[](size_t index)
    {
        index %= size;
        return data[index];
    }

    bool has(const T& obj)
    {
        for (size_t i = 0; i != size; ++i){
            if (obj == data[i])return true;
        }
        return false;
    }

    auto sum()->decltype(std::declval<T>() + std::declval<T>())
    {
        if (size == 1)return data[0];
        auto res = data[0] + data[1];
        for (size_t i = 2; i != size; ++i) {
            res = res + data[i];
        }
        return res;
    }
};
template<typename T>
class template_Sorted_LinkedList
{
public:
    struct Node
    {
        T data;
        Node* next = nullptr;
    };
private:
    Node head;
    void dispose()
    {
        Node* cur = &head;
        Node* nxt;
        if (cur->next) {
            cur = cur->next;
            do {
                nxt = cur->next;
                delete cur;
                cur = nxt;
            } while (nxt);
        }
    }
public:
    template_Sorted_LinkedList(){}
    template_Sorted_LinkedList(const template_Sorted_LinkedList& x)
    {
        Node* cur = &head;
        Node const* xur = &(x.head);

        while (xur->next) {
            cur->next = new Node;
            cur->next->data = xur->next->data;
            xur = xur->next;
            cur = cur->next;
        }
    }
    ~template_Sorted_LinkedList()
    {
        dispose();
    }
    template_Sorted_LinkedList& operator=(const template_Sorted_LinkedList& x)
    {
        dispose();
        Node* cur = &head;
        Node* xur = &(x.head);

        while (xur->next) {
            cur->next = new Node;
            cur->next->data = xur->data;
            xur = xur->next;
            cur = cur->next;
        }
        return *this;
    }
    void insert(const T& t)
    {
        Node* cur=&head;
        while(cur->next) {
            if(t < cur->next->data) {
                Node* nxt = cur->next;
                cur->next = new Node;
                cur->next->data = t;
                cur->next->next = nxt;
                return;
            }
            cur = cur->next;
        }
        cur->next = new Node;
        cur->next->data = t;
    }
    T& at(size_t x)
    {
        Node* cur = &head;
        for(size_t i=0;i!=x;++i) {
            if (!cur->next)throw std::out_of_range("");
            cur = cur->next;
        }
        return cur->next->data;
    }
    void remove(size_t x)
    {
        Node* cur = &head;
        for (size_t i = 0; i != x ; ++i) {
            if (!cur->next)throw std::out_of_range("");
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
};

template <class ForwardIt>
void template_quick_sort(ForwardIt it1, ForwardIt it2)
{
    if (it2 - it1 <= 1)return;
    if (it2 - it1 > 1)
    {
        auto its = it2 - 1;
        auto it = partition(it1, its, [its](auto a) {return (a < *its); });
        std::swap(*it, *its);
        template_quick_sort(it1, it);
        template_quick_sort(it + 1, it2);
    }
}


struct filter_test
{
    filter_test(){}
    filter_test(const filter_test&) = delete;
    filter_test operator=(const filter_test&) = delete;
    bool operator<(const int i) const
    {
        return i < 10;
    }
};

struct unary_predicate_test
{
    int val;
    unary_predicate_test(int val):val(val){}
    bool operator()(const int i) const { return i > val; }
};


struct val_test
{
    int i;
    val_test(int i):i(i) {}
    val_test(const val_test&) = delete;
    val_test(val_test&& a) {
        i = a.i;
        a.i = -10000000;
    };
    val_test operator=(const val_test&) = delete;
    void operator=(val_test&& a) {
        i = a.i;
        a.i = -10000000;
    };
    val_test&& operator+(const val_test& a) const
    {
        return val_test(i+a.i);
    }
};

template<typename filter_T, typename T, typename BinaryPredicate, typename BinaryOperation
    , typename = void
>
struct funtor_filtered_fold_impl{};

template<typename filter_T, typename T, typename BinaryPredicate, typename BinaryOperation>
struct funtor_filtered_fold_impl<filter_T, T, BinaryPredicate, BinaryOperation
    , std::enable_if_t<std::is_same<bool, std::result_of_t<BinaryPredicate(filter_T, T)> >::value>
>
{
    T& val;
    filter_T& filter;
    BinaryPredicate pred;
    BinaryOperation op;
    funtor_filtered_fold_impl(filter_T&& filter, T&& inV, BinaryPredicate pred, BinaryOperation op) :
        val(inV), filter(filter), pred(pred), op(op) {}
    void operator()(T& a) {
        if (std::invoke(pred, filter, a)) {
            val = std::invoke(op, val, a);
        }
    }
};

template<typename Void, typename T, typename Predicate, typename BinaryOperation>
struct funtor_filtered_fold_impl<Void, T, Predicate, BinaryOperation
    , std::enable_if_t<std::is_same<bool, std::result_of_t<Predicate(T)> >::value>
>
{
    T& val;
    Predicate pred;
    BinaryOperation op;
    funtor_filtered_fold_impl(T&& inV, Predicate pred, BinaryOperation op) :
        val(inV),  pred(pred), op(op) {}
    void operator()(T& a) {
        if (std::invoke(pred, a)) {
            val = std::invoke(op, val, a);
        }
    }
};

template< typename T
        , typename Predicate
        , typename BinaryOperation = std::plus<>
        , typename                 = std::enable_if_t<std::is_same<bool, std::result_of_t<Predicate(T)> >::value>
>
auto funtor_filtered_fold( T&& inV
                         , Predicate pred
                         , BinaryOperation op    = std::plus<>()
    )
{
    return funtor_filtered_fold_impl<void, T, decltype(pred), decltype(op)>(
        std::forward<T>(inV),
        std::forward<Predicate>(pred),
        std::forward<BinaryOperation>(op)
        );
}

template< typename filter_T
        , typename T               = filter_T
        , typename BinaryPredicate = std::less<>
        , typename BinaryOperation = std::plus<>
        , typename                 = std::enable_if_t<std::is_same<bool, std::result_of_t<BinaryPredicate(filter_T, T)> >::value>
>
auto funtor_filtered_fold( filter_T&& filter
                         , T&& inV              = T()
                         , BinaryPredicate pred = std::less<>()
                         , BinaryOperation op   = std::plus<>())
{
    return funtor_filtered_fold_impl<filter_T, T, decltype(pred), decltype(op) >(
        std::forward<filter_T>(filter),
        std::forward<T>(inV),
        std::forward<BinaryPredicate>(pred),
        std::forward<BinaryOperation>(op)
        );
}
