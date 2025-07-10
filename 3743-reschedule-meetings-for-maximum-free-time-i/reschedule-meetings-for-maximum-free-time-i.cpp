class Solution 
{
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        vector<int> gaps(n + 1);

        // Step 1: Compute gaps
        gaps[0] = startTime[0]; // gap before first meeting
        for (int i = 1; i < n; ++i) 
        {
            // gap between meetings
            gaps[i] = startTime[i] - endTime[i - 1]; 
        }
        
        // gap after last meeting
        gaps[n] = eventTime - endTime[n - 1]; 

        // Step 2: Sliding window to find max sum of k + 1 gaps
        int maxFree = 0;
        int windowSum = 0;
        
        for (int i = 0; i <= n; ++i) 
        {
            windowSum += gaps[i];
            if (i >= k) 
            {
                maxFree = max(maxFree, windowSum);
                windowSum -= gaps[i - k]; // slide the window
            }
        }

        return maxFree;
    }
};