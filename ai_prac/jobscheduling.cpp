#include<bits/stdc++.h>
using namespace std;


struct Job{
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}




void jobScheduling(vector<Job>& arr, int n){
    sort(arr.begin(), arr.end(), compare);
    vector<bool>slot(10, false);
    vector<char>result(10);

    for(int i = 0; i < n; i++){
        for(int j = min(n, arr[i].deadline) -1; j >= 0; j--){
            if(!slot[j]){
                slot[j] = true;
                result[j] = arr[i].id;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(slot[i]){
            cout << result[i] << " ";
        }
    }
}



int main(){
    vector<Job>arr = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = 5;
    jobScheduling(arr, n);
}