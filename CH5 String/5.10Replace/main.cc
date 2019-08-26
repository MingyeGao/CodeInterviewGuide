///字符串的调整与替换
#include <iostream>
#include <cstring>

using namespace std;

void replace(char *s){
    int i = 0;
    int spaceNum = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ') spaceNum++;
        ++i;
    }

    int j = i + 2*spaceNum - 1;

    i--;
    while(i != j){
        if(s[i] == ' '){
            s[j--] = '0';
            s[j--] = '2';
            s[j] = '%';
        }
        else{
            s[j] = s[i];
        }
        j--;
        i--;
    }
}

void replace2(char *s){
    int num = 0;
    int i = 0;
    for(; s[i] != '\0'; ++i){
        if(s[i] == '*') ++num;
    }

    i--;
    int j = i;
    int length = i + 1;
    while(j >= num ){
        if(s[i] == '*'){
            --i;
        }
        else{
            s[j--] = s[i--];
        }
    }

    for(; j >= 0; --j){
        s[j] = '*';
    }
}

int main(){
    char s[1024];
    bzero(s, 1024);
    char a[] = "hello world ";
    memcpy(s, a, strlen(a));
    replace(s);
    cout<<s<<endl;
    char s2[] = "12**345";
    replace2(s2);
    cout<<s2<<endl;
}