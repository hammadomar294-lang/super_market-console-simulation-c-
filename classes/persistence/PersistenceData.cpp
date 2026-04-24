#include "PersistenceData.h"
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

unordered_map<int, Category> PersistenceData::MakeCategoryMap(const vector<Category> &categories)
{
    unordered_map<int, Category> category_map;
    for (const auto & category : categories)
    {
        category_map[category.GetCategoryId()] = category;
    }
    return category_map;
}

const Category & PersistenceData::FindCategory(const unordered_map<int, Category> &map , int category_id)
{
    auto it = map.find(category_id);

    if (it == map.end())
        throw runtime_error("category wasn't found");

    return it->second;
}

pair<string, string> PersistenceData::LoadManagerData()
{
    ifstream file("data/manager.txt");

    if (!file.is_open())
        throw runtime_error("manager.txt couldn't be opened");

    pair<string, string> p;
    if (!(file >> p.first >> p.second))
    {
        throw runtime_error("manager.txt format invalid");
    }
    file.close();
    return p;
}

vector<Product> PersistenceData::LoadProducts(const vector<Category> & categories)
{   
    ifstream file("data/products.txt");
    if(!file.is_open())
        throw runtime_error("products.txt couldn't be opened");

    vector<Product> products;

    auto category_map = MakeCategoryMap(categories);

    int product_id , quantity , category_id;
    double price;
    string name;

    ProductMaxId = 0;

    while(file>> product_id >> name >> price >> quantity >> category_id)
    {
        Product product{product_id,name,price,quantity,FindCategory(category_map,category_id)};
        products.push_back(product);
        if (product_id > ProductMaxId)
            ProductMaxId = product_id;
    }
    file.close();

    Product::SyncProductId(ProductMaxId);
    return products;
}

vector<Category> PersistenceData::LoadCategories()
{
    ifstream file("data/categories.txt");
    if(!file.is_open())
        throw runtime_error("categories.txt couldn't be opened");

    vector<Category> categories;

    int id , tax , max_amount , least_amount;
    string name;

    CategoryMaxId = 0;

    while(file>>id>>name>>tax>>max_amount>>least_amount)
    {
        Category category{id,name,tax,max_amount,least_amount};
        categories.push_back(category);
        if (id > CategoryMaxId)
            CategoryMaxId = id;
    }
    Category::SyncCategoryId(CategoryMaxId); // to make the system ready to make new categories
    file.close();
    return categories;
}

void PersistenceData::SaveCategories(const vector<Category> &categories)
{
    ofstream file("data/categories.txt");
    if (!file.is_open())
        throw runtime_error("categories.txt couldn't be opened");
    
    for (const auto & category : categories)
    {
        file<<category.GetCategoryId()<<" " <<category.GetCategoryName() << " " <<category.GetTax() << " " <<
             category.GetMaxAmount() << " " << category.GetLeastAmount() << "\n";
    }
    file.close();
}

unordered_map<int , int> PersistenceData::LoadSales()
{
    ifstream file("data/sales.txt");
    if (!file.is_open())
        throw runtime_error("sales.txt couldn't be opened");

    int product_id , amount;
    unordered_map<int , int> sales;

    while (file>>product_id>>amount)
    {
        Sales sale{product_id,amount};
        sales[product_id] = amount;
    }
    file.close();
    return sales;
}

void PersistenceData::SaveSales(const unordered_map<int , int> &sales)
{
    ofstream file("data/sales.txt");
    if (!file.is_open())
        throw runtime_error("sales.txt couldn't be opened");
    
    for(const auto & sale : sales)
    {
        file<<sale.first<< " " << sale.second() <<"\n";
    }
    file.close();
}
