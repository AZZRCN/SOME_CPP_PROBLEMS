#ifndef AZZR_EXTRA_TRAIT
#define AZZR_EXTRA_TRAIT
#include "type_trait.cpp"
// 我尼玛怎么知道这是怎么工作的
// CCC
//向光荣的MSVC看齐！
//FROM MSVC

template<bool _Val>
using bool_constant = integral_constant<bool, _Val>;
template <bool _First_value, class _First, class... _Rest>
struct _Disjunction { // handle true trait or last trait
    using type = _First;
};

template <class _False, class _Next, class... _Rest>
struct _Disjunction<false, _False, _Next, _Rest...> { // first trait is false, try the next trait
    using type = typename _Disjunction<static_cast<bool>(_Next::value), _Next, _Rest...>::type;
};

template <class... _Traits>
struct disjunction : false_type {}; // If _Traits is empty, false_type

template <class _First, class... _Rest>
struct disjunction<_First, _Rest...> : _Disjunction<static_cast<bool>(_First::value), _First, _Rest...>::type {
    // the first true trait in _Traits, or the last trait if none are true
};

template <class... _Traits>
constexpr bool disjunction_v = disjunction<_Traits...>::value;

template <class _Ty, class... _Types>
constexpr bool _Is_any_of_v = // true if and only if _Ty is in _Types
#if _HAS_CXX17
    (is_same_v<_Ty, _Types> || ...);
#else // ^^^ _HAS_CXX17 / !_HAS_CXX17 vvv
    disjunction_v<is_same<_Ty, _Types>...>;
#endif // ^^^ !_HAS_CXX17 ^^^
template <class _Ty>
constexpr bool is_integral_v = _Is_any_of_v<remove_cv_t<_Ty>, bool, char, signed char, unsigned char, wchar_t,
#ifdef __cpp_char8_t
    char8_t,
#endif // defined(__cpp_char8_t)
    char16_t, char32_t, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long>;

template <class _Ty>
struct is_integral_MSVC : bool_constant<is_integral_v<_Ty>> {};

template <class _Ty>
constexpr bool is_floating_point_v = _Is_any_of_v<remove_cv_t<_Ty>, float, double, long double>;

template <class _Ty>
struct is_floating_point_MSVC : bool_constant<is_floating_point_v<_Ty>> {};

template <class _Ty>
constexpr bool is_arithmetic_v = // determine whether _Ty is an arithmetic type
    is_integral_v<_Ty> || is_floating_point_v<_Ty>;

template <class _Ty>
struct is_arithmetic_MSVC : bool_constant<is_arithmetic_v<_Ty>> {};





























//MADE BY AZZR
template<typename, typename>
constexpr bool is_same_v = false;
template<typename _Tp>
constexpr bool is_same_v<_Tp,_Tp> = true;
    // not
template<bool _Cond> bool no;
template<> bool no<true> = false;
template<> bool no<false> = true;

// and
template<bool _Cond1, bool _Cond2> bool _and = false;
template<> bool _and<true, true> = true;

// or
template<bool _Cond1, bool _Cond2> bool _or = false;
template<> bool _or<true, true> = true;
template<> bool _or<true, false> = true;
template<> bool _or<false, true> = true;

// xor
template<bool _Cond1, bool _Cond2> bool _xor = false;
template<> bool _xor<true, false> = true;
template<> bool _xor<false, true> = true;

// if
template<bool _Cond, bool _Then, bool _Else> bool _if = _Else;
template<> bool _if<true, true, false> = true;
template<> bool _if<true, false, false> = false;
template<> bool _if<true, true, true> = true;
template<> bool _if<true, false, true> = false;

// if_same
template<typename _T1, typename _T2> bool _if_same = false;
template<typename _T> bool _if_same<_T, _T> = true;

// is_same
template<typename _T1, typename _T2> bool _is_same = _if_same<_T1, _T2>;

// is_not_same
template<typename _T1, typename _T2> bool _is_not_same = no<_if_same<_T1, _T2>>;

// isn't zero
template<int _A> int isnt_zero = (int)((bool)(_A));

// min
template<int _A, int _B> int _min = (_A < _B) ? _A : _B;

// max
template<int _A, int _B> int _max = (_A > _B) ? _A : _B;

// add
template<int _A, int _B> int _add = _A + _B;

// sub
template<int _A, int _B> int _sub = _A - _B;

// mul
template<int _A, int _B> int _mul = _A * _B;

// div
template<int _A, int _B> int _div = _A / _B;

// mod
template<int _A, int _B> int _mod = _A % _B;

// ceil_div
template<int _A, int _B> int ceil_div = (_div<_A,_B>)+(isnt_zero<_mod<_A,_B>>);

// equal
template<int _A, int _B> bool _equal = (_A == _B);

// not_equal
template<int _A, int _B> bool _not_equal = (_A != _B);

// greater
template<int _A, int _B> bool _greater = (_A > _B);

// less
template<int _A, int _B> bool _less = (_A < _B);

// greater_equal
template<int _A, int _B> bool _greater_equal = (_A >= _B);

// less_equal
template<int _A, int _B> bool _less_equal = (_A <= _B);
template <class _Ty>
struct type_container{
    using type = _Ty;
};
template <class _Ty>
struct type_container<type_container<_Ty>>{
    using type = _Ty;
};
template<typename t>
struct remove_refs__ : type_container<t>{};
template<typename t>
struct remove_refs__<t&> : remove_refs__<t>{};
template<typename t>
struct remove_refs__<t&&> : remove_refs__<t>{};
template<typename t>
struct remove_const__ : type_container<t>{};
template<typename t>
struct remove_const__<const t> : remove_const__<t>{};
template<typename t>
struct remove_arr__ : type_container<t> {};
template<typename t, size_t N>
struct remove_arr__<t[N]> : remove_arr__<t> {};



template<typename t>
struct remove_all : 
type_container<
typename remove_const__<
typename remove_arr__<
typename remove_refs__<
t
>::type
>::type
>::type
>
{};



//TYPE_CONTAINER
template<typename t>
struct remove_refs__<type_container<t>> : remove_refs__<t>{};
template<typename t>
struct remove_const__<type_container<t>> : remove_const__<t>{};
template<typename t>
struct remove_arr__<type_container<t>> : remove_arr__<t> {};
template<typename t>
struct remove_all<type_container<t>> : remove_all<t> {};
//TYPE->VAL
template<typename t>
using remove_refs___v = typename remove_refs__<t>::type;
template<typename t>
using remove_const___v = typename remove_const__<t>::type;
template<typename t>
using remove_arr___v = typename remove_arr__<t>::type;
template<typename t>
using remove_all_v = typename remove_all<t>::type;
//REWRITE OF REMOVE_ALL
template<typename t>
struct remove_all__ : 
type_container<
remove_const___v<
remove_arr___v<
remove_refs___v<t>
>
>
>
{};
template<typename t>
using remove_all___v = typename remove_all__<t>::type;
#endif