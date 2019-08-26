///翻转字符串
#include <string.h>

#include <iostream>

using namespace std;

void rotate(char *s, int left, int right){
    int i = left, j = right;
    while(i < j){
        swap(s[i++], s[j--]);
    }
}

void rotateWord(char *s){
    int len = strlen(s);
    rotate(s, 0, len - 1);
    string str(s);
    int pos = str.find(' ');
    int left = 0, right;
    while(pos != string::npos){
        right = pos - 1;
        rotate(s, left, right);
        left = str.find_first_not_of(' ', pos + 1);
        pos = str.find(' ', left);
    }

    if(left != string::npos){
        rotate(s, left, len - 1);
    }
}

///把字符串的左半区移到右边，右半区移动到左边
void rotateWord2(char *s, int size){
    int len = strlen(s);
    rotate(s, 0, len - 1);
    rotate(s, len - size, len - 1);
    rotate(s, 0, len - size - 1);
}

int main(){
    char s[] = "ABCDE";
    //rotateWord(s);
    rotateWord2(s, 3);
    cout<<s<<endl;

}