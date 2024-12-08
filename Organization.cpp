#include "Organization.h"

void Organization::addProduct(Product *product)
{
    products.push_back(product);
}

void Organization::removeProduct(int productID)
{
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [productID](Product *p)
                                  { return p->getID() == productID; }),
                   products.end());
}

void Organization::searchProduct(int productID)
{
    auto it = std::find_if(products.begin(), products.end(),
                           [productID](Product *p)
                           { return p->getID() == productID; });
    if (it != products.end())
    {
        std::cout << "Product found: " << (*it)->getName() << "\n";
    }
    else
    {
        std::cout << "Product not found.\n";
    }
}

void Organization::searchProduct(const std::string &productName)
{
    auto it = std::find_if(products.begin(), products.end(),
                           [productName](Product *p)
                           { return p->getName().find(productName) != std::string::npos; });
    if (it != products.end())
    {
        std::cout << "Product found: " << (*it)->getName() << "\n";
    }
    else
    {
        std::cout << "Product not found.\n";
    }
}

void Organization::generateReport()
{
    std::cout << "Inventory Report:\n";
    for (Product *p : products)
    {
        std::cout << p->getName() << " - Stock: " << p->getStockLevel() << "\n";
        if (p->needsRestocking())
        {
            std::cout << "  Needs restocking: " << p->getReorderThreshold() - p->getStockLevel() << " units\n";
            notifySuppliers(p->getID(), p->getReorderThreshold() - p->getStockLevel());
        }
    }
}

void Organization::addSupplier(Supplier *supplier)
{
    suppliers.push_back(supplier);
}

void Organization::notifySuppliers(int productID, int quantity)
{
    for (Supplier *supplier : suppliers)
    {
        supplier->notifyRestock(productID, quantity);
    }
}
