

#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal(){
        double total=0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }


};

class ShoppingCartPrinter{
    private:
    ShoppingCart*cart;

    public:
    ShoppingCartPrinter(ShoppingCart*cart){
        this->cart=cart;
    }

    void printInvoice(){
        cout<<"Shoppinig Cart Invoice"<<endl;
        for (auto p:cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};


