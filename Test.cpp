#include <iostream>

using namespace std;

class punto{
private:
    int x = 0;
    int y = 0;
public:
    punto(int _x, int _y): x(_x),y(_y){}

    //Sobrecarga
    friend ostream& operator<<(ostream& os, const punto& p){
        os<<"Cordenada X: "<<p.x<<"\n"<<"Coordenada Y: "<<p.y<<"\n";
        return os;
    }
};

int main(){
    cout<<"Hola mundo!"<<endl;
    cout<<"El mundo... Puede ser enganado."<<endl;

    auto* p1 = new punto(2,5);
    cout << *p1;
    delete p1;

    return 0;
}