#include <vector>
#include <iostream>

using namespace std;

int qsort(vector<int>& data, int l,int r){
    int pivot = data[r];
    int end = r--;
    while(l<r){
        if (data[l] > pivot){
            swap(data[l],data[r--]);
        }else{
            l++;
        }
    }
    swap(data[r+1],data[end]);
    return r+1;
}

void sort(vector<int>& data,int l, int r){
    if (l>=r)return;
    int pi = qsort(data,l,r);
    sort(data,l,pi-1);
    sort(data,pi+1,r);
}

int main(){
    vector<int> temp{6,4,2,5,1,3};
    sort(temp,0,temp.size()-1);
    for(auto v: temp)cout << v << " ";
    cout << "\n";
}
