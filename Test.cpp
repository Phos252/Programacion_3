#include <iostream>

using namespace std;

class punto{
private:
    int x = 0;
    int y = 0;
public:
    punto(int _x, int _y): x(_x),y(_y){}

    //Sobrecarga <<
    friend ostream& operator<<(ostream& os, const punto& p){
        os<<"Cordenada X: "<<p.x<<"\n"<<"Coordenada Y: "<<p.y<<"\n";
        return os;
    }

    punto* operator+(const punto &other) const{
        return new punto(x+other.x,y+other.y);
    }
};

int main(){
    cout<<"Hola mundo!"<<endl;
    cout<<"El mundo... Puede ser enganado."<<endl;

    auto* p1 = new punto(2,5);
    auto* p2 = new punto(3,5);
    auto* p3 = *p1+*p2;
    cout << "Punto 1:"<<endl;
    cout << *p1;
    cout << "Punto 2:"<<endl;
    cout << *p2;
    cout << "Punto 3:"<<endl;
    cout << *p3;
    delete p1;
    delete p2;
    delete p3;

    return 0;
}