#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
vector<T> operator^(const vector<T>& a, const vector<T>& b){
    auto result = move(a);
    for(const auto& item: b) a.push_back(item);
    return result;
}

int square(int num){
    return num * num;
}

template<typename T, typename FunctionType>
void apply(std::vector<T>& v, FunctionType fun){
    for (auto& item: v) item = fun(item);
}


int main(){

    return 0;
}