///猫狗队列

#include <assert.h>

#include <cstdio>
#include <queue>
#include <string>

using namespace std;

class Pet{
public:
    Pet(){};
    Pet& operator=(const Pet &p){
        type = p.type;
        return *this;
    }
    Pet(string s, string n):type(s), name(n){};
    string type;
    string name;
};


class PetWithTimestamp{
public:
    PetWithTimestamp(Pet *p, int i):pet(p), count(i){};
    Pet *pet;
    int count;
};

class PetQueue{
public:
    PetQueue():count(0){};
    bool isEmpty(){
        return dogQueue.empty() && catQueue.empty();
    }
    bool isDogEmpty(){
        return dogQueue.empty();
    }
    bool isCatEmpty(){
        return catQueue.empty();
    }
    Pet popDog(){
        assert(!dogQueue.empty());
        Pet ret = *dogQueue.front()->pet;
        dogQueue.pop();
        return ret;
    }
    Pet popCat(){
        assert(!catQueue.empty());
        Pet ret = *catQueue.front()->pet;
        catQueue.pop();
        return ret;
    }
    Pet popPet(){
        assert(!catQueue.empty());
        Pet ret;
        PetWithTimestamp *catFront = catQueue.front();
        PetWithTimestamp *dogFront = dogQueue.front();
        if(catFront->count < dogFront->count){
            ret = *catFront->pet;
            catQueue.pop();
        }
        else{
            ret = *dogFront->pet;
            dogQueue.pop();
        }
        return ret;

    }
    void pushPet(Pet *p){
        PetWithTimestamp *newEntry = new PetWithTimestamp(p, count++);
        if(p->type == "cat"){
            catQueue.push(newEntry);
        }
        else if(p->type == "dog"){
            dogQueue.push(newEntry);
        }
    }

    queue<PetWithTimestamp*> dogQueue;
    queue<PetWithTimestamp*> catQueue;
    int count;
};

int main(){
    Pet *cat1 = new Pet("cat", "xiaohua");
    Pet *cat2 = new Pet("cat", "xiaohei");
    Pet *cat3 = new Pet("cat", "mimi");
    Pet *dog1 = new Pet("dog", "ahuang");
    Pet *dog2 = new Pet("dog", "wangcai");

    PetQueue q;
    q.pushPet(cat1);
    q.pushPet(dog1);
    q.pushPet(cat2);
    q.pushPet(dog2);
    q.pushPet(cat3);

    Pet ret = q.popDog();
    assert(ret.name == dog1->name);

}