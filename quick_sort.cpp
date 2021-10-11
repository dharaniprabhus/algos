#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& cont){
    for(auto val: cont){
        cout << val << " ";
    }
    cout << "\n";
}

int partition(vector<int>& data,int start,int end){
    int pivot_elem = data[end];
    int ri = end-1;
    while(start < ri){
        if(data[start] > pivot_elem){
            swap(data[start],data[ri--]);
        }else{
            start++;
        }
    }
    swap(data[ri+1],data[end]);
    // cout << "pi : " << ri << " " << start << "\n";
    print(data);
    return start;
}

void quick_sort(vector<int>& data, int start, int end){
    if (start >= end)return;
    int pi = partition(data,start,end);
    quick_sort(data,start,pi-1);
    quick_sort(data,pi+1,end);
}

int main(){
    vector<int> data{20,4,6,2,8};
    quick_sort(data,0,data.size()-1);
    print(data);
    return 0;
}
