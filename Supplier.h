#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <iostream>

class Organization; // Forward declaration

class Supplier
{
protected:
    std::string name;

public:
    Supplier(const std::string &name) : name(name) {}
    virtual ~Supplier() = default;

    virtual void notifyRestock(int productID, int quantity) = 0;
    virtual void subscribeToOrganization(Organization *org) = 0;
};

class LocalSupplier : public Supplier
{
public:
    LocalSupplier(const std::string &name) : Supplier(name) {}

    void notifyRestock(int productID, int quantity) override
    {
        std::cout << "Local Supplier " << name
                  << " notified: Restock Product ID " << productID
                  << " with quantity " << quantity << ".\n";
    }

    void subscribeToOrganization(Organization *org) override;
};

class GlobalSupplier : public Supplier
{
public:
    GlobalSupplier(const std::string &name) : Supplier(name) {}

    void notifyRestock(int productID, int quantity) override
    {
        std::cout << "Global Supplier " << name
                  << " notified: Restock Product ID " << productID
                  << " with quantity " << quantity << ".\n";
    }

    void subscribeToOrganization(Organization *org) override;
};

#endif
