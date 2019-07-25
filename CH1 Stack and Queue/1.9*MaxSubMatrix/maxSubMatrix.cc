#include <iostream>
#include <stack>
#include <vector>
#include <initializer_list>

using namespace std;

int maxRecFromBottom(vector<int> &height);

int maxSubMatrix(vector<vector<int> > &input){
    if(input.size() == 0) return 0;
    int rows = input.size();
    int columns = input[0].size();
    if(columns == 0) return 0;
    vector<int> height(columns, 0);
    int maxSize = 0;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(input[i][j] == 1){
                ++height[j];
            }     
            else{
                height[j] = 0;
            }
        }

        int thisMaxSize = maxRecFromBottom(height);
        if(thisMaxSize > maxSize) maxSize = thisMaxSize;
    }

    return maxSize;
}

int maxRecFromBottom(vector<int> &height){
    if(height.size() == 0) return 0;

    stack<int> s;
    int maxSize = 0;
    height.push_back(0);
    for(int i = 0; i < height.size(); ++i){
        while(!s.empty() && height[s.top()] >= height[i]){
            if(height[s.top()] == height[i]) s.pop();
            else{
                int k = s.top();
                s.pop();
                int j;
                j = s.empty()?-1:s.top();
                int thisMaxSize = ((i - 1) - (j + 1) + 1) * height[k];
                if(thisMaxSize > maxSize) maxSize = thisMaxSize;
            }
        }
        s.push(i);
    }

    return maxSize;
}

int main(){
    vector<vector<int> > input{
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0}
    };

    int ret = maxSubMatrix(input);
    cout<<ret<<endl;
}