
// twice(f,x) = f(f(x))

namespace iwtbam
{

template<class F, class X>
struct twice
{
    using once = typename F::template apply<X>::type;
    using type = typename F::template apply<once>::type;
};

// template<class F, class X>
// struct twice:
//     F::template apply<
//            typename F::template apply<X>::type
//         >
//     {}

}