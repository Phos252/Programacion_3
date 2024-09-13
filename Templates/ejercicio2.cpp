//1. Funciones
//2. Template especializados
//3. Template generico
//4. SFINAE (sustitation fail is not an error)


#include <iostream>
template<typename T>
auto fun_1(T* a, T* b){
    std::cout << __PRETTY_FUNCTION__ <<std::endl;
}

bool compare() {return true;}
bool compare(int) {return true;}

template <typename T, typename ...Ts>
bool compare(T first, T second, Ts ... other_params){
    return (first == second) && compare(other_params...);
}

void ejemplo(){
    std::cout << std::boolalpha << compare(1,1,2,2,3,3,4,4);
}

template <typename T, typename ...Ts>
auto sum_product(T first, T second, Ts ...rest){
    return first * second + sum_product(rest...);
}

int main(){
    ejemplo();
}