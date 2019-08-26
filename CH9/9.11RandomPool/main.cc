///randomPool

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>

using namespace std;

class RandomPool{
public:
    RandomPool():size(0){};
    unordered_map<string, int> keyIndexMap;
    unordered_map<int, string> indexKeyMap;
    int size;
    void insert(string key){
        if(keyIndexMap.find(key) != keyIndexMap.end()){
            return;
        }
        ++size;
        keyIndexMap.insert(make_pair(key, size));
        indexKeyMap.insert(make_pair(size, key));
    }

    void remove(string key){
        if(keyIndexMap.find(key) == keyIndexMap.end()){
            return;
        }
        string lastKey = indexKeyMap[size];
        int keyIndex = keyIndexMap[key];
        keyIndexMap[lastKey] = keyIndex;
        keyIndexMap.erase(key);
        indexKeyMap.erase(size);
        --size;
    }

    string getRandom(){
        int tmp = rand()%size + 1;
        return indexKeyMap[tmp];
    }
};

int main(){
    RandomPool rp;
    rp.insert("A");
    rp.insert("B");
    string ret = rp.getRandom();
    cout<<ret<<endl;
    rp.remove("A");
    ret = rp.getRandom();
    cout<<ret<<endl;
}