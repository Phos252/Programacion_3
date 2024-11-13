#include <vector>
#include <thread>
#include <iostream>
#include <mutex>
#include <future>
#include <random>
#include <type_traits>
// Ejercicio 1
/*  Desarrollar una función incrementar_total que retorne el valor de una
    variable total que es el resultado de la ejecución de n hilos, la
    función debe contar con el parámetro n para definir la cantidad de
    hilos que se van a ejecutar en la función y el parámetro inc que
    servirá para que cada hilo incremente el valor de la variable total,
    ejecutar una función adicional que llame a la función incrementar_total
    y que imprima el resultado de su llamada. */

int incremetar_total_nc(int n, int inc){
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += inc;
    }
    return total;
}

std::mutex mtx;

//Similar a la clase lock_guard
class guardian_de_lock{
    std::mutex& mtx;
public:
    explicit guardian_de_lock(std::mutex& mtx): mtx(mtx) {mtx.lock();}
    ~guardian_de_lock() {mtx.unlock();}
};

void task_inc(int inc, int& total){
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //mtx.lock();
    //total += inc;
    //mtx.unlock();

    //std::lock_guard lg(mtx); // equivalente a mtx.lock() y sin necesidad de unlock;
    //total += inc

    std::unique_lock ul(mtx);
    total += inc;
    ul.unlock();
}

int incremetar_total(int n, int inc){
    int total = 0;
    std::vector<std::thread> vhilos(n);
    //vhilos.reserve(n);
//    for (int i = 0; i < n; ++i) {
//        vhilos.emplace_back(task_inc, inc, std::ref(total));
//    }
    for (auto& item: vhilos) {
      item = std::thread(task_inc, inc, std::ref(total));
    }

    for (auto& item:vhilos){
        item.join();
    }
    return total;
}

int incremetar_total_atomico(int n, int inc){
    std::atomic<int> total = 0;
    std::vector<std::thread> vhilos(n);
    for (auto& item: vhilos) {
        item = std::thread([inc,&total](){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            total += inc;
        });
    }

    for (auto& item:vhilos){
        item.join();
    }
    return total;
}

void ejemplo(){
    std::cout << incremetar_total_nc(100,1) << std::endl;
    std::cout << incremetar_total(100,1) << std::endl;

    int m = 100;
    for (int i = 0; i < m; ++i) {
        std::cout << incremetar_total(100,1) << " ";
    }

    std::cout<< std::endl;

    for (int i = 0; i < m; ++i) {
        std::cout << incremetar_total_atomico(100,1) << " ";
    }
}

//  Considere la clase Client que represente a un cliente de un banco y que
//  tiene al saldo como atributo (double), un constructor por default, un
//  constructor por parámetros que permita definir el saldo inicial, los
//  métodos depositar y retirar que actualicen el saldo acorde con la
//  operación y la sobrecargar del operador << que permita imprimir el saldo.
//  3. Desarrollar un programa que genere un objeto del tipo Client y realice
//  nd depósitos de valor d de forma concurrente, de igual modo realice nr
//  retiros de valor r de forma concurrente, finalmente utilizando el
//  operador << imprimir el saldo final del cliente.

class Client{
    double saldo = 0;
public:
    Client() = default;
    explicit Client(double _saldo): saldo(_saldo){}
    void depositar(double amount) { saldo += amount;}
    void withdraw(double amount) { saldo -= amount;}
};

//   4/11/24
template<typename T>
std::vector<T> generate(int n, T start, T stop){
    std::vector<T> v(n);
    std::random_device rd;
    if constexpr (std::is_same_v<T, int>){
        std::uniform_int_distribution<T> udis(start, stop);
        for (auto& item: v) item = udis(rd);
    }
    else if constexpr (std::is_same_v<T, double>){
        std::uniform_real_distribution<T> udis(start, stop);
        for (auto& item: v) item = udis(rd);
    }
    return v;
}


int main(){
    auto v1= generate(10, 1, 20);
    auto v2= generate(10, 8.5, 1.5);
    return 0;
}