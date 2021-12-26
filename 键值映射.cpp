#include"global.h"

class MapSum {
public:
    MapSum() {

    }

    void insert(string key, int val) {

        int temp = val;
        if (KeyMap.find(key) != KeyMap.end()) //ÖØ¸´µÄ
        {
            temp = val - KeyMap[key];
        }
        KeyMap[key] = val;
        for (int i = 1; i <= key.size(); i++)
        {
            prefixmap[key.substr(0, i)] += temp;
        }
    }

    int sum(string prefix) {
        return prefixmap[prefix];
    }
    map<string, int> KeyMap;
    map<string, int>prefixmap;
};


int main()
{
    MapSum a;
    a.insert("apple", 3);
    a.sum("apple");
}