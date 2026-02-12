#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int efficientJanitor(vector<float> weights){
    sort(weights.begin(), weights.end());

    int left = 0;
    int right = weights.size() - 1;
    int bags = 0;
    
    while(left <= right){
        if(left == right){
            bags++;
            break;
        }
        
        if(weights[left] + weights[right] <= 3.0){
            left++;
            right--;
        }else{
            right--;
        }
        bags++;
    }
    return bags;
    
}

int main(){
    vector<float> weights = {1.01,1.99,2.5,1.5,1.01};

    cout<< " Minimum bags needed: " << efficientJanitor(weights) << endl;
    return 0;
}