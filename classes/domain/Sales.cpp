#include "classes/domain/Sales.h"
#include <stdexcept>
#include "Sales.h"

using namespace std;

int Sales::ValidateId(int id)
{
    if (id <= 0) throw invalid_argument("cant enter value below 0");
    return id;
}

int Sales::ValidateAmount(int amount)
{
    if (amount <= 0) throw invalid_argument("cant enter value below 0");
    return amount;
}

int Sales::GetProductId() const
{
    return ProductId;
}

int Sales::GetAmount() const
{
    return Amount;
}

void Sales::SetAmount(int amount)
{
    Amount = ValidateAmount(amount);
}

Sales::Sales(int id, int amount) : ProductId(ValidateId(id)) , Amount(ValidateAmount(amount))
{}
