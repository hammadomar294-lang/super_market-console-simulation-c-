#include "PersistenceData.h"
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

pair<string, string> PersistenceData::LoadManagerData()
{
    ifstream file("data/manager.txt");

    if (!file.is_open())
    {
        throw runtime_error("manager.txt couldn't be opened");
    }

    pair<string, string> p;
    if (!(file >> p.first >> p.second))
    {
        throw runtime_error("manager.txt format invalid");
    }
    file.close();
    return p;
}