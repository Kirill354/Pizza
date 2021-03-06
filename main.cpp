#include <iostream>
#include <string>
#include <vector>
using namespace std;


 
class Pizza{
private:
    string type;
    string dough;
    string sauce;
    const float price;
public:
    
    Pizza( string m_type, float m_price): price(m_price), type(m_type) {

    }
    virtual void GetPrice() {
        cout <<"Price of " << type << " = " << price << endl;
    }
    virtual int ReturnPrice() {
        return price;
    }
    /*
    virtual void Prepare() = 0;
    virtual void Bake() = 0;
    virtual void Cut() = 0;
    virtual void Packaging() = 0;
    */
};

class Peperoni : public Pizza {

public:

    Peperoni(): Pizza("Peperoni" , 1000){};
    
};

class Four_Cheese : public Pizza {

public:

    Four_Cheese(): Pizza("Four_cheese" , 900){};

};

class BBQ : public Pizza {
public:

    BBQ(): Pizza("BBQ" , 950){};
    
};

void menu(){
    cout << "Hello, dear guest! What do u prefer? " << endl;

    cout << "\n--OUR ASSORTMENT--" << endl << endl;
    cout << "#1 Peperoni    - Price is 1000$" << endl;
    cout << "#2 Four_Cheese - Price is 900$" << endl;
    cout << "#3 BBQ         - Price is 950$" << endl;
    cout << "\n--THE END--" << endl << endl;

    cout << "to add peperoni to the order    - enter 1" << endl;
    cout << "to add four_cheese to the order - enter 2" << endl;
    cout << "to add BBQ to the order         - enter 3" << endl;
    cout << "to leave our menu               - enter 0" << endl;
}

void Purchases(vector <Pizza*> &vect) {

    char c;

    do {

        cout <<'\n';
        menu();
        cin >> c;

        switch(c){

            case '0':
                break;

            case '1':
                vect.push_back(new Peperoni);
                break;

            case '2':
                vect.push_back(new Four_Cheese);
                break;

            case '3':
                vect.push_back(new BBQ);
                break;

            default:
                cout << " incorrect number " << endl;
                break;
        }
    }
    while (c != '0');

    int summ = 0;
    cout << '\n';
    for (auto a : vect){
        a->GetPrice();
        summ += a->ReturnPrice();
    }
    cout << "Total order's cost = " << summ << endl;
    cout << "Do you agree with your order? 1-agree; 2-disagree" << endl;
}

void Order(){
    vector <Pizza*> vect;
    //vect.clear();
    Purchases(vect);

    int consent = 0;

    while (consent != 1){

        cin >> consent;

        if (consent == 1){
            // тут будет функция приготовления пицц
            /*
            void Prepare();
            void Bake();
            void Cut();
            void Packaging();
            */
           cout << "END" << endl;
           break;
        }
        else{
            Purchases(vect);
        }
        
    }

}

int main()
{
    Order();
    return 0;
}