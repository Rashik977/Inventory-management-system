#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int productID;
    std::string productName;
    std::string category;
    double price;
    int stockLevel;
    int reorderThreshold;

public:
    Product(int id, const std::string &name, const std::string &cat, double pr, int stock, int threshold)
        : productID(id), productName(name), category(cat), price(pr), stockLevel(stock), reorderThreshold(threshold) {}

    int getID() const { return productID; }
    std::string getName() const { return productName; }
    std::string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getStockLevel() const { return stockLevel; }
    int getReorderThreshold() const { return reorderThreshold; }

    void updateStock(int sold) { stockLevel -= sold; }
    bool needsRestocking() const { return stockLevel < reorderThreshold; }
};

#endif
