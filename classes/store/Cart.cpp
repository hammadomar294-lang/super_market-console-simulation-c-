#include "classes/store/Cart.h"
#include <string>
#include "Cart.h"


using namespace std;

Action Cart::MakeAction(const CartItem &item, bool operation)
{
    Action action{item,operation};
    return action;
}

void Cart::AddProduct(const Product &product, int amount)
{
    CartItem item{product , amount};
    Action action = MakeAction(item , true);

    CartItemVector.push_back(item);
    Undo.push(action);

    
}
bool Cart::RemoveProduct(int product_number)
{
    if (product_number <= 0 || product_number >= CartItemVector.size()) return false;

    CartItem item = CartItemVector[product_number - 1];
    Action action{item,false};

    CartItemVector.erase(CartItemVector.begin() + product_number - 1);
    Undo.push(action);

    

    return true;
}

void Cart::UndoLastItem()
{
    if (Undo.empty())
        return;
    Action action = Undo.top();
    Undo.pop();
    // true
    if (action.Operation)
        {if (!CartItemVector.empty()) {CartItemVector.pop_back();}}
    else 
        CartItemVector.push_back(action.Item);

    Redo.push(action);
    
}

void Cart::RedoLastItem()
{
    if (Redo.empty())
        return;
    Action action = Redo.top();
    Redo.pop();

    if (action.Operation)
        CartItemVector.push_back(action.Item);
    else
        if (!CartItemVector.empty()) CartItemVector.pop_back();
    
    Undo.push(action);
}
