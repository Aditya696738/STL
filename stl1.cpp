// APPLE store management system.........
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <set>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
// structure for products
struct APPLE_Store{
    std::string Product_ID;
    std::string Product_Name;
    std::string Product_Category;
};
//structure for orders
struct APPLE_Orders{
    int Order_ID;
    std::string Product_ID;
    int quantity;
    std::string Customer_ID;
    time_t Order_Date;
};
int main(){
    std::vector<APPLE_Store> appleStore = {
        {"BHGHTW3313" , "MacBook-Air" , "MacBook"},
        {"IUIWF2144" , "MacBook-Pro" , "MacBook"},
        {"CBIBI2314" , "iMac" , "Desktop"},
        {"BJBW21441" , "Mac-Studio" , "Computer"},
        {"BIDBWI327" , "Iphone", "Mobile"}
    };
    std::deque<std::string> recent_Customer = {"C001","C002","C003","C004","C005"};
    recent_Customer.push_back("C006");
    recent_Customer.push_back("C007");
    std::list <APPLE_Orders>Order_History;
    Order_History.push_back({121,"BHGHTW3313",2,"C001",time(0)});
    Order_History.push_back({1242,"IUIWF2144",2,"C002",time(0)});
    Order_History.push_back({1421,"CBIBI2314",1,"C003",time(0)});
    Order_History.push_back({521,"BJBW21441",3,"C004",time(0)});
    Order_History.push_back({1263,"BIDBWI327",10,"C005",time(0)});
    std::set<std::string>Product_Category;

    for(const auto & Products : appleStore){
        Product_Category.insert(Products.Product_Category);
    }
    //map--these are use binary search tree and stored a data in shorted way.
    std::map <int,int>Product_Stock = {{121,10},{1242,30},{1421,21},{521,69},{1263,40}};
    std::multimap<std::string,APPLE_Orders>Customer_Orders;
    for(const auto & order:Order_History){
        Customer_Orders.insert({order.Customer_ID,order});
    }
    //unordered_map -- these are use hash table
    std::unordered_map<std::string , std::string>Customer_Data = {{"C001","Aditya"},{"C002","bob"},{"C003","alice"},{"C004","chinku"},{"C005","pinku"}};

    std::unordered_set<std::string>Unique_Product_ID;
    for(const auto & Products :appleStore){
        Unique_Product_ID.insert(Products.Product_ID);
    }

    //print out all the products
    std::cout << "Name of Products Which are availabe on our store \n";
    for(const auto & Products:appleStore){
        std::cout<<"Name: " << Products.Product_Name << " " << "ID: " << Products.Product_ID << " "<<"Product Category: " << Products.Product_Category << "\n";
    }

    //print all customer
    std::cout << "Recent Customers:\n";
    for (const auto &customer : recent_Customer) {
        std::cout << customer << "\n";
    }

    // Print out order history (only showing Order_ID and Customer_ID for brevity)
    std::cout << "Order History of Products:\n";
    for (const auto &order : Order_History) {
        std::cout << "Order ID: " << order.Order_ID << "Product ID: " << order.Product_ID << ", Quantity: " << order.quantity << ", Customer: " << order.Customer_ID << "\n";
    }
    // Print out unique product categories
    std::cout << "Unique Product Categories:\n";
    for (const auto &category : Product_Category) {
        std::cout << category << "\n";
    }
    return 0;
}  