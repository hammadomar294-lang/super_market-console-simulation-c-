#include "classes/domain/Sales.h"
#include "classes/persistence/PersistenceData.h"
#include <vector>
#include <unordered_map>
using namespace std;

#ifndef SALESBST_H
#define SALESBST_H

class SalesBST
{
private:
    struct Node
    {
        int ProductId;
        int Amount;

        Node * right;
        Node * left;

        static int ValidateId(int id)
        {
            if (id < 0)
                throw runtime_error("can't enter value < 0");
            return id;
        }
        static int ValidateAmount(int amount)
        {
            if (amount < 0)
                throw runtime_error("can't enter value < 0");
            return amount;
        }

        Node(int product_id, int amount) : ProductId(ValidateId(product_id)), Amount(ValidateAmount(amount))
        {}

    };

    Node * Root;

    void Insert(int id , int amount);
    void Clear(Node * current);
public:
    void BuildTree(const unordered_map<int , int> & sales);

    vector <int> GetAscendingIds() const;
    vector <int> GetDescendingIds() const;
    vector <int> GetNthMostSoldIds(int n) const;

    int GetMostSoldId() const;
    int GetLeastSoldId() const;
    
    bool IsEmpty() const;

    ~SalesBST();
};

#endif