#include<iostream>
#include<vector>
std::vector<int> mergeSort(int a[],int b[], int m, int n);
int main(){
    int a[]={2,8,15,18};
    int b[] = {5,9,12,17};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    std::vector<int> result = mergeSort(a,b,m,n);
    for(int x : result){
        std::cout << x << " ";
    }
    return 0;
}

std::vector<int> mergeSort(int a[],int b[], int m, int n){
    std::vector<int> c;
    int i = 0;
    int j = 0;
    while(i<m && j<n){
        if(a[i] < b[j]){
            c.push_back(a[i++]);
        }
        else{
            c.push_back(b[j++]);
        }
    }
    while(i<m){
        c.push_back(a[i++]);
    }
    while(j<n){
        c.push_back(b[j++]);
    }
    
    return c;
}

