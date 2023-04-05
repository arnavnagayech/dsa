
// single array
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size(); 
        vector<int> nge(n, -1);
        stack<int> st; 
        
        for(int i = n-1;i>=0;i--) 
        {
            while(!st.empty() && st.top() <= nums[i]) 
            {
                st.pop(); 
            }
            
            if(i<n) 
            {
                if(!st.empty()) 
                    nge[i] = st.top(); 
            }
            st.push(nums[i]);
        }
        return nge; 
    }
};