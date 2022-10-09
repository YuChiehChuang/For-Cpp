//question:https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
//看無 已放棄
bool compare(pair<int, int> a, pair<int, int> b){  //pair
    return (a.second == b.second)? a.first < b.first:a.second < b.second;
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {  //vector
        vector<pair<int, int>> ans;  //vector, pair
        vector<int> res;  //vector

        for( int i=0;i<mat.size();i++){ 
            ans.push_back(make_pair(-1,0));  //push_back, make_pair
            for( int j=0;j<mat[i].size(); j++){
                ans[i].first=i;
                if(mat[i][j] == 1) {
                    ans[i].second++;
                }
            }
        }
  
        sort(ans.begin(), ans.end(), compare);  //.begin(), .end()
        
        int n=0;
        while(n<k){
            res.push_back(ans[n].first);  //push_back
            n++;
        }
        return res;
    }
};