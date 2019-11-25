#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include <map>
#include <string>
using std::map;
using std::string;

/**
 * Generic interface for the storage of different resources.
 *
 * @tparam T the time of resources stored in the map
 */
template<class T>
class ResourcesManager
{
    protected:
        static map<string, T*> store; //!< Resources storage
    public:
        virtual bool load(string, string) = 0;  //!<
        virtual T* get(string) const = 0;
        static string str_tolower(string str)
        {
            for (string::size_type i = 0; i < str.length(); ++i)
                str[i] = std::tolower(str[i]);
            return str;
        }
};

#endif // RESOURCESMANAGER_H
