//template template parameters
//与书有出入,有bug

#include <iostream>
#include <string>

template<typename... Args> struct typelist{};

template<> struct typelist<>{};

template<int v>
struct Int2Type
{
    enum {value = v};
};

template<int i, typename T> struct at;

template<int i, typename T, typename... Args>
struct at<i, typelist<T, Args...>>:
    at<i-1, typelist<Args...>>
    {};

template<typename T, typename... Args>
struct at<0, typelist<T, Args...>>
{
    using type = T;
};

template<int i>
struct at<i, typelist<>>
{
    using type = typelist<>;
    static_assert(i>0,  "index out of range");
};

template<class typelist, template <class> class Unit>
class GenScatterHierarchy;

template<class T1, class... T2, template<class> class Unit>
class GenScatterHierarchy<typelist<T1, T2...>, Unit>:
    public GenScatterHierarchy<T1, Unit>,
    public GenScatterHierarchy<typelist<T2...>, Unit>
{};


template<class T, template<class> class Unit>
class GenScatterHierarchy<typelist<T>, Unit>:
    public GenScatterHierarchy<T, Unit>
{};

template<class AtomicType, template<class> class Unit>
class GenScatterHierarchy:public Unit<AtomicType>
{};


template<class Head, class... Tail, template<class> class Unit>
Unit<Head>& FieldHelper(GenScatterHierarchy<typelist<Head, Tail...>, Unit>& obj, Int2Type<0>)
{
    GenScatterHierarchy<Head,Unit>& leftBase = obj;
    return leftBase;
} 

template<int i, class Head, class... Tail, template<class> class Unit>
Unit<typename at<i, typelist<Head, Tail...>>::type>&
    FieldHelper(
        GenScatterHierarchy<typelist<Head, Tail...>, Unit>& obj,
        Int2Type<i>
    )
{
    GenScatterHierarchy<typelist<Tail...>, Unit>& rightBase = obj;
    return FieldHelper(rightBase, Int2Type<i-1>());
}


template <int i, class TList, template <class> class Unit>
Unit<typename at<i, TList>::type>&
    Field(GenScatterHierarchy<TList,Unit>& obj)
{
    return FieldHelper(obj,Int2Type<i>());
}

template<class T>
struct Holder
{
    T _v;
};

using Point3D = GenScatterHierarchy<typelist<int, double, char>, Holder>;

int main()
{
    Point3D p1;
    Field<0>(p1)._v = 1;
    Field<1>(p1)._v = 2;
    Field<2>(p1)._v = 3;
    auto v = Field<2>(p1)._v;
    std::cout<< v << std::endl;
    std::cout<< sizeof(p1) << std::endl;
    return 0;
}