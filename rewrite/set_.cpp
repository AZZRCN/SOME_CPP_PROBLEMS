#include ".\alloctor.cpp"
template<typename ty,typename alloc = alloctor<ty>>
class set_{
    alloc data;
};