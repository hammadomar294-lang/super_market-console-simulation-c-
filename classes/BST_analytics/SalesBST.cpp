#include "classes/BST_analytics/SalesBST.h"


#pragma region helpers

bool SalesBST::IsEmpty() const
{
    return Root == nullptr;
}

void SalesBST::Insert(int id, int amount)
{
    Node *temp = new Node{id,amount};
    if (IsEmpty())
    { 
        Root = temp;
        return;
    }
    Node * current = Root;
    Node * prev = Root;
    while (current != nullptr)
    {
        prev = current;
        if (amount > current->Amount)
            current = current->right;

        else 
            current = current->left;
    }
    
    if (amount > prev->Amount)
        prev->right = temp;

    else 
        prev->left = temp;
    
}

void SalesBST::Clear(Node *current) // with recursion
{
    //  base
    if (current == nullptr)
        return;

    Clear(current->left); // go far left until left -> null 
    Clear(current->right); // step after going far left which will go far right until right -> null
    delete current; // then delete node after those to steps which both resulted in return so they got completed
}

#pragma endregion

SalesBST::~SalesBST()
{
    Clear(Root);
}
