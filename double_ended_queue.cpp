#include <iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<climits>

using namespace std;

int segment(int x, vector<int> space){
    deque<int> q;
    int max_of_mins = INT_MIN;
    for(int i = 0; i < space.size(); i++){
        if(!q.empty() && q.front() <=i-x){
            q.pop_front();
        }

        while (!q.empty() && space[q.back()] >= space[i]){
            q.pop_back();
        }

        q.push_back(i);

        if(i >= x-1){
            max_of_mins = max(max_of_mins, space[q.front()]);
        }
        if (i >= x - 1) {
    int current_min = space[q.front()];
    cout << "Window ending at " << i << ": Min is " << current_min << endl;
    max_of_mins = max(max_of_mins, current_min);
}
    }

    return max_of_mins;

}

int main(){
    int x = 2;
    vector<int> space = {8,2,4,6};

    cout<< "Result: " << segment(x, space) << endl;
    return 0;
}