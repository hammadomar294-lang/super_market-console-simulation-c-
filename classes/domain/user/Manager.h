#include <string>
#include <stdexcept>
#include "classes/domain/user/User.h"
#include "classes/domain/Product.h"
#include "classes/domain/Category.h"
#include "classes/store/Store.h"
using namespace std;

#ifndef MANAGER_H
#define MANAGER_H
class Manager : public User
{
private:
    string Password;
    string Name;
    
    static int validateID(int id);
    static string validateName(const string& name);
    static string validatePassword(const string& password);
public:
    Manager(int id ,const string &name,const string &password);
    string GetName() const;  
};
#endif

