using namespace std;

#ifndef SALES_H
#define SALES_H
class Sales
{
private:
    int ProductId;
    int Amount;

    static int ValidateId(int id);
    static int ValidateAmount(int amount);
public:
    int GetProductId() const;

    int GetAmount() const;
    void SetAmount(int amount);

    Sales(int id , int amount);
};

#endif