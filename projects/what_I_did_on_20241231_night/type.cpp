template <class _Ty>
struct type_container{
    using type = _Ty;
};

template <class _Ty>
struct type_container<type_container<_Ty>>{
    using type = _Ty;
};

template<typename t>
struct arr2p : type_container<t>{};

template<typename t>
struct arr2p<t[]> : arr2p<t*>{};

template<typename t, size_t N>
struct arr2p<t[N]> : arr2p<t*>{};

template<typename t, size_t N>
struct arr2p<t(&)[N]> : arr2p<t*>{};