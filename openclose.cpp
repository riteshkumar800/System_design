

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

// class ShoppingCartStorage{
//     private:
//     ShoppingCart*cart;

//     public:
//     ShoppingCartStorage(ShoppingCart*cart){
//         this->cart=cart;

//     }

//     void SaveToSQLDatabase(){
//         cout<<"saving to SQL DB..."<<endl;

//     }
//     void SaveToMongoDB(){
//         cout<<"saving  to  Mongo DB..."<<endl;

//     }
//     void SaveToFile(){
//         cout<<"saving to File DB..."<<endl;

//     }




// };

class Persistence{
    private:
    ShoppingCart*cart;
    
    public:
    virtual void save(ShoppingCart*cart)=0;
};

class SQLPersistence:public Persistence{
    public:
    void save(ShoppingCart*cart) override{
        cout<<"Saving to SQL DB....."<<endl;
    }

    
};
class MongoPersistence:public Persistence{
    public:
    void save(ShoppingCart*cart) override{
        cout<<"Saving to Mongo DB....."<<endl;
    }

    
};

class FilePersistence:public Persistence{
    public:
    void save(ShoppingCart*cart) override{
        cout<<"Saving to File DB....."<<endl;
    }


};

int main(){
    ShoppingCart*cart =new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter*printer=new ShoppingCartPrinter(cart);
    printer->printInvoice();

    // ShoppingCartStorage* db=new ShoppingCartStorage(cart);
    // db->SaveToSQLDatabase();
    Persistence* db=new SQLPersistence();
    Persistence* mongo=new MongoPersistence();
    Persistence* file=new FilePersistence();

    db->save(cart);
    mongo->save(cart);
    file->save(cart);




    return 0;



}





