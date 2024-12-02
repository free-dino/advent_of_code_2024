#include<bits/stdc++.h>
using namespace std;

void total_distance(vector<int> &list1, vector<int> &list2) {
    int sum = 0;
    for(int i=0; i<list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }
    cout<<sum<<endl;
}

void similarity_score(const vector<int> &list1, const vector<int> &list2) {
    unordered_map<int, int> freq;
    for (int num : list2) {
        freq[num]++;
    }
    int ans = 0;
    for (int num : list1) {
        ans += num * freq[num];
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> list1, list2;
    int x, y;
    while(cin>>x>>y) {
        list1.push_back(x);
        list2.push_back(y);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    total_distance(list1, list2);
    similarity_score(list1, list2);
}