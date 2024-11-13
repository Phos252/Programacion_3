#include <iostream>

template <int a, int b>
auto sumar(){
    return a + b;
}

template <typename  T, int sz>
auto get_size(T (&)[sz]){
    return sz;
}

template <typename T, int sz1, int sz2>
auto sumarizar(T (&a)[sz1], T (&b)[sz2]){
    T result = 0;
    for (int i = 0; i < sz1; ++i)
        result += a[i];
    for (int i = 0; i < sz2, ++i)
        result += b[i];
    return result;
}

template <typename T, int ...sz>
auto sumarizar_2(T (&a)[sz]...){
    return (...+sunarizar(a));
}

int main(){
    int arr[] = {10,20,30};
    std::cout << (sizeof(arr)/sizeof(int)) << std::endl;
    std::cout << get_size(arr) << std::endl;
}