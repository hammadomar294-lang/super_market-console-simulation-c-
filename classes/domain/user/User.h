#include <string>
#include <stdexcept>
using namespace std;

#ifndef USER_H
#define USER_H
class User
{
private:
    int Id;

public:
    User(int id)
    {
        if (id < 0) 
            throw invalid_argument("invalid id");
        Id = id;
    }   
    int GetId() const
    {
        return Id; 
    }
    virtual ~User() = default;
};
#endif

