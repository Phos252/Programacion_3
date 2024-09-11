#include <iostream>

using namespace std;

template <class T>
struct Point {
    T x;
    T y;
};

template <typename T>
T square(T num){
    return num * num;
}

template <class T>
T fun_1(){
    return 10 + 20;
}

int main(){
    int a = 5;

    //Instanciación por deducción
    auto x = square(a);
    auto y = square(10.5);
    //auto x = func_1(); //la deducción solo funciona cuando el template tiene parametros

    //Instanciación Explicita
    auto z = square<float>(10);
    auto var1 = fun_1<int>();

    return 0;
}