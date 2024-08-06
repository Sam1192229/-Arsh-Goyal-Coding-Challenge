class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();

        // pse
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        int maxarea = 0;
        for (int i = 0; i < nums.size(); i++) {

            int including = nums[i] * (nse[i] - pse[i] - 1);
            maxarea = max(maxarea, including);
        }
        return maxarea;
    }
};