class Solution {
public:
    void helper(vector<int>& temp,vector<vector<int>>& answer,vector<int>& candidates,int target,int start){
        if(target==0){
            answer.push_back(temp);
            return;
        }
        for(int i=start;i<candidates.size();++i){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;

            temp.push_back(candidates[i]);
            helper(temp,answer,candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(temp,answer,candidates,target,0);
        return answer;
    }
};