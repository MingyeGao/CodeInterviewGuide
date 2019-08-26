///判断一个点是否在三角形内侧
#include <iostream>
#include <cmath>

using namespace std;

///使用海伦公式，通过面积判断

double getLength(double x1, double y1, double x2, double y2){
    double x = x1 - x2;
    double y = y1 - y2;
    return sqrt(x * x + y * y);
}

double getSize(double x1, double y1, double x2, double y2, double x3, double y3){
    double l1 = getLength(x1, y1, x2, y2);
    double l2 = getLength(x1, y1, x3, y3);
    double l3 = getLength(x2, y2, x3, y3);
    double l = (l1 + l2 + l3)/2;

    return l * (l - l1) * (l - l2) * (l - l3); 
}

bool isInTriangle1(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y){
    double s1 = getSize(x1, y1, x2, y2, x, y);
    double s2 = getSize(x1, y1, x3, y3, x, y);
    double s3 = getSize(x3, y3, x2, y2, x, y);
    double s = getSize(x1, y1, x2, y2, x3, y3);
    if(abs(s1 + s2 + s3 - s) < 0.1){
        return true;
    }
    else{
        return false;
    }
}

double crossProduct(double x1, double y1, double x2, double y2){
    return x1 * y2 - x2 * y1;
}

bool isInTriangel2(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y){
    if(crossProduct(x3 - x1, y3 - y1, x2 - x1, y2 - y1) >= 0){
        swap(x2, x3);
        swap(y2, y3);
    }

    if(crossProduct(x2 - x1, y2 - y1, x - x1, y - y1) < 0){
        return false;
    }

    if(crossProduct(x3 - x2, y3 - y2, x - x2, y - y2) < 0){
        return false;
    }

    if(crossProduct(x1 - x3, y1 - y3, x - x3, y - y3) < 0){
        return false;
    }

    return true;
}

int main(){
    bool ret = isInTriangel2(1, 1, 2, 2, 1, 2, 1.1, 1.1);
    if(ret){
        cout<<"true"<<endl;
    }
}