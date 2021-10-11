#include <iostream>
#include <vector>

using namespace std;
// 1 4 6 2
void bubble_sort(vector<int>& data){
    for(int i = 0; i<data.size(); ++i){
        bool swapped = false;
        for(int j =1; j<data.size()-i; ++j){
            if (data[j-1] > data[j]){
                swap(data[j-1],data[j]);
                swapped = true;
            }
        }
        if (!swapped)return;
    }
}
void print(const vector<int>& cont){
    for(auto val: cont){
        cout << val << " ";
    }
    cout << "\n";
}


int main(){
    vector<int> data{20,4,6,2,8};
    bubble_sort(data);
    print(data);
    return 0;
}
