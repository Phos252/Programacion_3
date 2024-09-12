#include <iostream>
#include <vector>
#include <iostream>
#include <random>

using namespace std;

template<typename T>
std::ostream & operator<<(std::ostream  & imprime, const std::vector<T> vec){
    for(const auto& item: vec){
        imprime << item << " ";
    }
    return imprime;
}

template<typename T>
vector<T> operator^(const vector<T>& a, const vector<T>& b){
    auto result = move(a);
    for(const auto& item: b) a.push_back(item);
    return result;
}

int square(int num){
    return num * num;
}

template<typename T>
T incrementar(T x){
    return x + 10;
}

template<typename T, typename FunctionType>
void apply(std::vector<T>& v, FunctionType fun){
    for (auto& item: v) item = fun(item); //callback (llamado posterior)
}

template<typename T, typename Callable>
vector<T> filter(const std::vector<T> v, Callable fun){
    vector<T> vecfiltered;
    for (const auto& item: v){
        if (fun(item)){
            vecfiltered.push_back(item);
        }
    }
    return vecfiltered;
}

//Acceder a los valores usando tuplas
template <typename ... PackageTypes> //Ts
void fun_1(PackageTypes ...PackageParams){ //Params
    std::cout << __PRETTY_FUNCTION__  << std::endl;
    std::tuple<PackageTypes...> t1{PackageParams...};
    std::cout << std::get<0>(t1);
    std::cout << std::get<1>(t1);
}

//Acceder a los valores usando Folding expression
template <typename ...PackageTypes>
void show(PackageTypes ...params){
    ((std::cout << params), ...);
}

bool es_par(int x){
    return x % 2 == 0;
}

void ejemplo_1(){
    std::vector<double> v {10, 20, 30};
    apply(v, incrementar<double>);
    //apply(v, incrementar<typename std::vector>); // completar
}

void ejemplo_3(){
    std::vector<int> v(20);
    std::random_device rd;
    std::uniform_int_distribution<int> dis(1,50);
    for(auto& item: v) item = dis(rd);
    std::cout << v;

    vector<int> v2 = filter(v, es_par);
    cout << "\n" << v2;
}

void ejemplo_4(){
    fun_1(1, "");
    fun_1(1, "", 2.5, 4.5f);
    fun_1(1, "", true);
}

int main(){
    ejemplo_4();

    return 0;
}