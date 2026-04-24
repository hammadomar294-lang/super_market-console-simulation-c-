#include <string>
#include "classes/domain/user/customer.h"
#include "customer.h"

Customer::Customer(int id) : User(id)
{
}

Cart &Customer::GetCart() 
{
    return cart;
}
