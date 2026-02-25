#include <iostream>
#include <string>
using namespace std;

class Restaurant;
class Customer;

class Order{
private:
    int orderId;
    string customerName, restaurantName, foodName;
public:
    static int orderCounter;

    Order(string c, string r, string f) : customerName(c), restaurantName(r), foodName(f){
        orderCounter++;
        orderId = 1000 + orderCounter;
    }

    string getFood(){
        return foodName;
    }

    void show(){
        cout << "Order #" << orderId << ": " << foodName 
             << " for " << customerName 
             << " from " << restaurantName << endl;
    }
};

class Restaurant{
private:
    string restaurantTitle;
public:
    Restaurant(string r) : restaurantTitle(r){
    }

    void takeOrder(Order *o){
        cout << restaurantTitle << " making: " << o->getFood() << endl;
    }

    string getRestaurantTitle(){
        return restaurantTitle;
    }
};

class Customer{
private:
    string customerTitle;
public:
    Customer(string c) : customerTitle(c){
    }

    string getCustomerTitle(){
        return customerTitle;
    }

    Order placeOrder(Restaurant *r, string food){
        cout << customerTitle << " placed order at " << r->getRestaurantTitle() << endl;
        return Order(customerTitle, r->getRestaurantTitle(), food);
    }
};

int Order::orderCounter = 0;

int main(){
    Customer c1("Alice"), c2("Bob");
    Restaurant r1("Pizza Heaven"), r2("Taco Fiesta");

    cout << "=== PLACING ORDERS ===" << endl;
    Order o1 = c1.placeOrder(&r1, "Pepperoni Pizza");
    Order o2 = c2.placeOrder(&r2, "Burrito");

    cout << endl;
    cout << "=== ORDER DETAILS ===" << endl;
    o1.show();
    o2.show();

    cout << endl;
    cout << "=== RESTAURANT STATUS ===" << endl;
    r1.takeOrder(&o1);
    r2.takeOrder(&o2);

    cout << endl;
    cout << "=== AFTER ORDERS ARE GONE ===" << endl;
    cout << "Customer still exists: " << c1.getCustomerTitle() << endl;
    cout << "Restaurant still exists: " << r2.getRestaurantTitle() << endl;

    return 0;
}
