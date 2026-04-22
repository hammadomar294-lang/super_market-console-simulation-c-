#include <vector>
#include <string>
#include "classes/domain/CartItem.h"
#include <stack>

using namespace std;

#ifndef CART_H
#define CART_H
class Cart
{
private:
    struct Action
    {
        CartItem Item;
        bool Operation;

        Action(const CartItem &item , bool operation)
        {
            Item = item;
            Operation = operation;
        }
    };
    vector<CartItem> CartItemVector;
    stack<Action> Undo;   
    stack<Action> Redo;
    
    

public:

    Action MakeAction(const CartItem &item , bool operation);

    void AddProduct(const Product &product , int amount);
                        //number of product when they are displayed
    bool RemoveProduct(int product_number);

    void UndoLastItem();
    void RedoLastItem();

    double GetTotalPrice();

    const vector<CartItem>& GetItemsVector() const;
};
#endif
