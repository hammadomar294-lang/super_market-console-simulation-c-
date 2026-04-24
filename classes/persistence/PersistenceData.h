#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "classes/domain/Category.h"
#include "classes/domain/Product.h"
#include "classes/domain/Sales.h"
using namespace std;

#ifndef PERSISTENCE_H
#define PERSISTENCE_H
class PersistenceData
{
private :
    static int CategoryMaxId = 0;
    static int ProductMaxId = 0;
    static unordered_map<int , Category> MakeCategoryMap(const vector<Category> & categories);
    static Category FindCategory(const unordered_map<int , Category> & map , int category_id);
public:
               //Name   Password
    static pair<string , string> LoadManagerData();

    // TODO: load and save products
    static vector<Product>  LoadProducts(const vector<Category> & categories);
    static void SaveProducts(const vector<Product> & products);

    // TODO: load and save categories
    static vector<Category> LoadCategories();
    static void SaveCategories(const vector<Category> & categories);

    // TODO: load and save history order
    static unordered_map<int , int> LoadSales();
    static void SaveSales(const unordered_map<int , int> & sales);
}; 

#endif
