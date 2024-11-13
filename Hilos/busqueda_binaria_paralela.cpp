#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <iterator>
#include <thread>

void print (const auto rem, const auto& v){
    std::cout << rem;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
};

//Tomado de CPP reference
void ejemplo_uso_merge_2_vectores(){
    // fill the vectors with random numbers
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);

    std::vector<int> v1(10), v2(10);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));

    print("Originally:\nv1: ", v1);
    print("v2: ", v2);

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    print("After sorting:\nv1: ", v1);
    print("v2: ", v2);

    // merge
    std::vector<int> dst(v1.size()+v2.size());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v1.begin());

    print("After merging:\ndst: ", dst);
}

template<typename Iterator> //random iterator complejidad algoritmica constante
void mergesort(Iterator left, Iterator right){
    if(std::distance(left, right) <= 1) return;
    auto mid = next(left, std::distance(left,right)/2); //que hace next?
    mergesort(left, mid);
    mergesort(right,mid);

    std::inplace_merge(left, mid, right);
}

template<typename Iterator> //random iterator complejidad algoritmica constante
void mergesort_par(Iterator left, Iterator right, int depth = -1){
    if (depth == -1) depth = std::log2(std::distance(left, right));

    if(std::distance(left, right) <= 1) return;
    auto mid = next(left, std::distance(left,right)/2); //que hace next?

    if(depth > 0){
        std::thread left_thread(mergesort_par, left, mid, depth -1);
        std::thread right_thread(mergesort_par, left, mid, depth -1);

        left_thread.join();
        right_thread.join();
    }

    mergesort(left, mid);
    mergesort(right,mid);

    std::inplace_merge(left, mid, right);
}

void ejemplo_merge_sort(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std:: uniform_int_distribution<> dis(1,50);
    std::vector<int> v1(30);
    std::generate(v1.begin(),v1.end(),[&mt, &dis] {return dis(mt); });

    std::generate(v1.begin(),v1.end(), [&mt, &dis])
}

//deep = log_2(nh) // regla para utilizar hilos

int main()
{

}


