#include "Organization.h"
#include "Supplier.h"
#include "Product.h"

int main()
{
    Organization org;

    // Create some products
    Product product1 = Product(101, "Laptop", "Electronics", 1000, 10, 5);
    Product product2 = Product(102, "Smartphone", "Electronics", 500, 10, 5);

    // Add products
    org.addProduct(&product1);
    org.addProduct(&product2);

    // Create suppliers
    LocalSupplier local = LocalSupplier("Daraz");
    GlobalSupplier global = GlobalSupplier("Amazon");

    // Subscribe suppliers to organization
    local.subscribeToOrganization(&org);
    global.subscribeToOrganization(&org);

    // simulate a sale
    product1.updateStock(6);

    // Search for a product
    org.searchProduct("Lap");

    // Generate inventory report
    org.generateReport();

    return 0;
}
