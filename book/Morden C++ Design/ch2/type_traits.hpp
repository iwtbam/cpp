#ifndef IWTBAM_TYPE_TRAITS_H
#define IWTBAM_TYPE_TRAITS_H


namespace iwtbam
{


template<bool, typename T, typename U>
struct select
{
    using value_type = T;
};

template<typename T, typename U>
struct select<false,T,U>
{
    using value_type = U;
};

template<typename T, typename U>
class conversion
{
    using true_type = char;
    using false_type = int;
    static true_type test(U);
    static false_type test(...);
    static T makeT();

public:
    enum { exists = sizeof(test(makeT())) == sizeof(true_type)};
    enum { exists2Way = exists && conversion<U, T>::exists};
    enum { sameType = false };
};

template<typename T>
class conversion<T, T>
{
public:
    enum { exists = 1, exists2Way = 1, sameType = 1 };
};


#define SUPERSUBCLASS(T, U)                       \
    (conversion<const T*, const U*>::exists &&    \
    !conversion<const T*, const void*>::sameType)


#define SUPERSUBCLASS_STRICT(T, U)                \
    (SUPERSUBCLASS(T, U) &&                       \
    conversion<const T, const U>::sameType)     



class NullType;

struct EmptyType {}; 

// type_traits

template<typename T>
struct pointer_traits
{
    enum { value  = false };
    using type = NullType;
};

template<typename T>
struct pointer_traits<T*>
{
    enum { value = true };
    using type = T;
};


template<typename T>
struct const_traits
{
    enum { value = false };
    using type = T;
};

template<typename T>
struct const_traits<const T>
{
    enum { value =  true };
    using type = T;
};

template<typename>
struct is_member_function_pointer
{
    enum {value = false};    
};


template<typename T, typename U>
struct is_member_function_pointer<T U::*>
{
    enum {value = true };
};



}

#endif //IWTBAM_TYPE_TRAITS_H