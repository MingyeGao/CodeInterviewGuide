///判断一个点是否落在矩形内部

#include <iostream>
#include <cmath>

///临边各平行于x轴，y轴的情况
bool isInside(double x1, double y1,///最左边的点
              double x2, double y2,///最上边的点
              double x3, double y3,///最下边的点
              double x4, double y4,///最右边的点
              double x, double y){
    
    if(x <= x1 && x >= x4 && y >= y3 && y <= y2){
        return true;
    }
    else{
        return false;
    }
}

bool isInsideCommon(double x1, double y1,///最左边的点
                    double x2, double y2,///最上边的点
                    double x3, double y3,///最下边的点
                    double x4, double y4,///最右边的点
                    double x, double y){

    if(y1 == y2){
        return isInside(x1, y1, x2, y2, x3, y3, x4, y4, x, y);
    }

    double l = y4 - y3;
    double k = x4 - x3;
    double s = sqrt(l * l + k * k);
    double cos = k/s;
    double sin = l/s;

    double x1R = x1 * cos + y1 * sin;
    double y1R = y1 * cos - x1 * sin;
    double x2R = x2 * cos + y2 * sin;
    double y2R = y2 * cos - x2 * sin;
    double x3R = x3 * cos + y3 * sin;
    double y3R = y3 * cos - x3 * sin;
    double x4R = x4 * cos + y4 * sin;
    double y4R = y4 * cos - x4 * sin;
    double xR = x * cos + y * sin;
    double yR = y * cos - x * sin;
    
    return isInside(x1R, y1R, x2R, y2R, x3R, y3R, x4R, y4R, xR, yR);
}

int main(){
    
}