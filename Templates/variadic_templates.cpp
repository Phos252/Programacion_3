template<typename ...Ts>
auto productos(Ts ...args){
    return (... * args);
}

template<typename T>
bool es_par(T a) {return a % 2 == 0;}

template<typename ...Ts>
auto son_todos_pares(Ts ...args) {
    //return (... )
    return (es_par(args) && ...);
}