#include <string>
#include "classes/store/Cart.h"
#include "classes/domain/user/User.h"

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public User
{
private :
    Cart cart;
public :
    Customer(int id);

    Cart & GetCart();
};

#endif 