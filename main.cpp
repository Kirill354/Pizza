#include <iostream>
#include <string>
#include <vector>
using namespace std;


 
class Pizza{
private:
    string type;
    string dough;
    string sauce;
    float price;
public:
    Pizza(){}
    //Pizza(string m_type="0", string m_dough="0", string m_sauce="0", float m_price=0) : 
    //    type{m_type}, dough{m_dough}, sauce{m_sauce}, price{m_price} {}
    
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
private:
    float price = 1000;
    string type = "Peperoni";
public:
    Peperoni(){}
    //Peperoni(string m_type="0", string m_dough="0", string m_sauce="0", float m_price=0) : 
    //   Pizza(m_type, m_dough, m_sauce, m_price) {}
    
    void GetPrice() override{
        cout <<"Price of " << type << " = " << price << endl;
    }

    int ReturnPrice() override {
        return price;
    }

    void Prepare(){
        cout << type << " is prepared " << endl;
    }
};

class Four_Cheese : public Pizza {
private:
    float price = 900;
    string type = "Four_Cheese";
public:
    Four_Cheese(){}
    //Four_Cheese(string m_type="0", string m_dough="0", string m_sauce="0", float m_price=0) : 
    //    Pizza(m_type, m_dough, m_sauce, m_price) {}
    
    void GetPrice() override{
        cout <<"Price of " << type << " = " << price << endl;
    }
    int ReturnPrice() override {
        return price;
    }
};

class BBQ : public Pizza {
private:
    float price = 950;
    string type = "BBQ";
public:
    BBQ(){}
    //BBQ(string m_type="0", string m_dough="0", string m_sauce="0", float m_price=0) : 
    //   Pizza(m_type, m_dough, m_sauce, m_price) {}
    
    void GetPrice() override{
        cout <<"Price of " << type << " = " << price << endl;
    }
    int ReturnPrice() override {
        return price;
    }
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
    //Peperoni a;
    //a.Prepare();
    //a.GetPrice();

    Order();

 
    return 0;
}