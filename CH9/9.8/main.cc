///带有setAll功能的Hash表
#include <iostream>
#include <unordered_map>

using namespace std;

class SetAllHash{
public:
    SetAllHash():timeStamp(0){}
    typedef pair<int, int> TimeStampElement;
    unordered_map<int, TimeStampElement> hashTable;
    int timeStamp;
    int setAllValue;
    void put(int key, int val){
        TimeStampElement element = make_pair(val, timeStamp);
        hashTable[key] = element;
        timeStamp++;
    }

    int get(int key){
        if(hashTable.find(key) == hashTable.end()){
            cout<<"no such key"<<endl;
            return -1;
        }

        auto element = hashTable[key];
        if(element.second < timeStamp){
            return setAllValue;
        }
        else{
            return element.first;
        }
    }

    bool containsKey(int key){
        if(hashTable.find(key) == hashTable.end()){
            return false;
        }
        else{
            return true;
        }
    }

    void setAll(int val){
        timeStamp++;
        setAllValue = val;
    }
};

int main(){
    
}