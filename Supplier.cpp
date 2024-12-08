#include "Supplier.h"
#include "Organization.h"

void LocalSupplier::subscribeToOrganization(Organization *org)
{
    org->addSupplier(this);
}

void GlobalSupplier::subscribeToOrganization(Organization *org)
{
    org->addSupplier(this);
}
