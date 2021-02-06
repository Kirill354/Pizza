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
    virtual void Prepare() = 0;
    virtual void Bake() = 0;
    virtual void Cut() = 0;
    virtual void Packaging() = 0;
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
};


int main()
{
    Peperoni a;
    a.Prepare();
    a.GetPrice();
 
    return 0;
}