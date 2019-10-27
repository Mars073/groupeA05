#ifndef RESSOURCESMANAGER_H
#define RESSOURCESMANAGER_H

#include <map>
#include <string>
using std::map;
using std::string;

template<class T>
class RessourcesManager
{
    private:
        //static map<string, T*> store;
    public:
        virtual bool load(string, string) = 0;
        virtual T* get(string) const = 0;
};

#endif // RESSOURCESMANAGER_H
