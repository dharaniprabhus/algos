#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& cont){
    for(auto val: cont){
        cout << val << " ";
    }
    cout << "\n";
}

vector<int> merge_sort(const vector<int>& data, int start,int end){
    if (start > end)return vector<int>();
    else if (start == end) return vector<int>(1,data[start]);
    else{
        int mid = start + (end-start)/2;
        auto left = merge_sort(data,start,mid);
        auto right = merge_sort(data,mid+1,end);
        vector<int> res(left.size() + right.size());
        int left_pos = 0;
        int right_pos = 0;
        int write_pos = 0;
        int cnt = 0;
        while(cnt < res.size()){
            if (left_pos < left.size() &&
                    right_pos < right.size()){
                if (left[left_pos] < right[right_pos]){
                    res[write_pos++] = left[left_pos++];
                }else{
                    res[write_pos++] = right[right_pos++];
                }
            }else if (left_pos >= left.size()){
                res[write_pos++] = right[right_pos++];
            }else{
                res[write_pos++] = left[left_pos++];
            }
            cnt++;
        }
        return res;
    }
}

int main(){
    vector<int> data{20,4,6,2,8};
    data = merge_sort(data, 0,data.size()-1);
    print(data);
    return 0;
}
