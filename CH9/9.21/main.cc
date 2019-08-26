///数字的英文表达和中文表达

#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <climits>


using namespace std;

vector<wstring> ChineseCharactor({L"零",L"一",L"二", L"三", L"四", L"五", L"六", L"七", L"八", L"九"});


wstring toChineseCore(int n, wstring s){
    assert(n >= 0 && n < 10000);
    wstring ret;
    int bit[4];
    int lastbit = 0;
    int current = 1000;
    int remain = n;
    bool lastIsZero = false;
    bool frontNoZero = false;

    for(int i = 0; i < 4; ++i){
        bit[i] = remain / current;
        remain = remain - bit[i] * current;
        current /= 10;
    }
    
    if(bit[0]) {
        ret += ChineseCharactor[bit[0]] + L"千";
        frontNoZero = true;
    }
    else{
        lastIsZero = true;
    }

    if(bit[1]){
        ret += ChineseCharactor[bit[1]] + L"百";
        frontNoZero = true; 
        lastIsZero = false;
    }
    else{
        lastIsZero = true;
    }

    if(bit[2]){
        if(frontNoZero && lastIsZero){
            ret += L"零";
        }
        ret += ChineseCharactor[bit[2]] + L"十";
        frontNoZero = true; 
        lastIsZero = false;
    }
    else{
        lastIsZero = true;
    }

    if(bit[3]){
        if(frontNoZero && lastIsZero){
            ret += L"零";
        }
        ret += ChineseCharactor[bit[3]];
    }
    
    if(ret.size()){
        ret += s;
    }
    return ret;

}

wstring toChinese(int N){
    if(N == 0){
        return L"零";
    }
    
    int remain = N;
    int num0to9999 = N % 10000;

    remain -= num0to9999;
    int num10000to99999999 = (remain)/10000 % 10000;
    remain -= num10000to99999999 * 10000;
    int num100000000toAbove = remain/100000000%10000;
    wstring ret;

    if(N < 0){
        num0to9999 = -num0to9999;
        num10000to99999999 = -num10000to99999999;
        num100000000toAbove = -num100000000toAbove;
    }
    ret += toChineseCore(num100000000toAbove, wstring(L"亿"));
    ret += toChineseCore(num10000to99999999, wstring(L"万"));
    ret += toChineseCore(num0to9999, wstring(L""));

    if(N < 0){
        ret = L"负" + ret;
    }
    return ret;
}

vector<string> EnglishCharacter({"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
, "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"});

vector<string> EnglishDecimal({"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"});

string toEnglishCore(int N, string level){
    string ret;
    assert(N >= 0 && N < 1000);
    vector<int> bit(3);
    int remain = N;
    int current = 100;
    bit[0] = N/100;
    if(bit[0]){
        ret += EnglishCharacter[bit[0]] + " hundred ";
    }

    remain = N - bit[0]*100;
    if(remain > 0 && remain < 20){
        ret += EnglishCharacter[remain];
    }
    else if(remain >= 20){
        bit[1] = remain/10;
        ret += EnglishDecimal[bit[1] - 2];
        bit[2] = remain%10;
        if(bit[2]){
            ret += " ";
            ret += EnglishCharacter[bit[2]];
        }
    }

    if(ret.size()){
        ret += " ";
        ret += level + ", ";
    }
    //ret += level;
    return ret;

}

string toEnglish(int N){
    if(N == 0){
        return string("zero");
    }
    int remain = N;
    int num0to999 = N % 1000;
    remain -= num0to999;
    int num1000to999999 = remain/1000 % 1000;
    remain -= num1000to999999*1000;
    int num1000000to999999999 = remain/1000000 % 1000;
    remain -= num1000000to999999999*1000000;
    int numAbove = remain/1000000000 % 1000;
    if(N < 0){
        num0to999 = -num0to999;
        num1000to999999 = -num1000to999999;
        num1000000to999999999 = -num1000000to999999999;
        numAbove = -numAbove;
    }

    string ret;
    ret += toEnglishCore(numAbove, "billion");
    ret += toEnglishCore(num1000000to999999999, "million");
    ret += toEnglishCore(num1000to999999, "thousand");
    ret += toEnglishCore(num0to999, "");
   
    
    
    return ret;
}

int main(){
    
    // wstring ret = toChinese(INT_MIN);
    // locale::global(locale(""));
    // wcout.imbue(locale(""));
    // wcout<<ret<<endl;
    string ret = toEnglish(INT_MAX);
    cout<<ret<<endl;
}