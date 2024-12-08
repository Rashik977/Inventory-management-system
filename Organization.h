#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "Product.h"
#include "Supplier.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Organization
{
private:
    std::vector<Product *> products;
    std::vector<Supplier *> suppliers;

public:
    void addProduct(Product *product);
    void removeProduct(int productID);
    void searchProduct(int productID);
    void searchProduct(const std::string &productName);
    void generateReport();
    void addSupplier(Supplier *supplier);
    void notifySuppliers(int productID, int quantity);
};

#endif
