#ifndef PART2_LIST_H
#define PART2_LIST_H

//~~~~~~~~~~~~~~~~~~~~~~ List Data Structure ~~~~~~~~~~~~~~~~~~~~~~~~~~

// Template Metaprogramming - Variadic Templates
template<typename... Types>
struct List;

// Base case: empty list
template<>
struct List<> {
    // compile-time size of the list
    static constexpr int size = 0;
};

// recursive: non-empty list
template <typename T, typename ... Types>
struct List<T, Types...> {
    typedef T head;
    typedef List<Types...> next;
    static constexpr int size = 1 + next::size;
};

// ~~~~~~~~~~~~~~~~~~~~~~ Helper Data Structures ~~~~~~~~~~~~~~~~~~~~~~~~~~


/* PrependList */
template<typename T, typename ListType>
struct PrependList;

//specialization
template<typename T, typename... Types>
struct PrependList<T, List<Types...>> {
    typedef List<T, Types...> list;
};


/* GetAtIndex */
template <int N, typename ListType>
struct GetAtIndex;

// N=0
template <typename T, typename... Types>
struct GetAtIndex<0, List<T, Types...>> {
    typedef T value;
};

// N>0
template <int N, typename T, typename... Types>
struct GetAtIndex<N, List<T, Types...>> {
    typedef typename GetAtIndex<N - 1, List<Types...>>::value value;
};


/* SetAtIndex */
template <int N, typename AType, typename ListType>
struct SetAtIndex;

// N=0
template <typename AType, typename T, typename... Types>
struct SetAtIndex<0, AType, List<T, Types...>> {
    // replace head with AType
    typedef List<AType, Types...> list;
};

// N>0
template <int N, typename AType, typename T, typename... Types>
struct SetAtIndex<N, AType, List<T, Types...>> {
    // TODO: ADD assert to check N > 0 !!
    typedef typename PrependList<T, typename SetAtIndex<N - 1, AType, List<Types...>>::list>::list list;
};

#endif //PART2_LIST_H