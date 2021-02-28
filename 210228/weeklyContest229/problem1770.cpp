// Maximum Score from Performing Multiplication Operationsclass Solution {
public:
    int dp[1010][1010];
    int dp_solution(vector<int>& nums, vector<int>& m, int m_idx, int front_idx, int back_idx){
      int &ret = dp[m_idx][front_idx];
      if(m_idx == m.size()) return 0;
      if(ret != -1) return ret;
      ret = max(dp_solution(nums, m, m_idx+1, front_idx+1, back_idx) + m[m_idx] * nums[front_idx], dp_solution(nums, m, m_idx+1, front_idx, back_idx-1)+ m[m_idx] * nums[back_idx]);
      return ret;
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
      // 0 => 
      memset(dp, -1,sizeof(dp));
      int maximum_score = dp_solution(nums, multipliers, 0, 0, nums.size()-1);

      return maximum_score;
    }
};