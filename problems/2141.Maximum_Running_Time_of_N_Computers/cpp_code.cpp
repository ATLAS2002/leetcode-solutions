class Solution {
private:
    bool canRun(vector<int>& batteries, int computers, long long time) {
        long long energyRequired = time*computers;
        long long energyAvailable = 0;
        for(const int& battery : batteries) 
            energyAvailable += min((long long)battery, time);
        return energyRequired <= energyAvailable;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long mn = 1; 
        long long mx = accumulate(batteries.begin(), batteries.end(), 0ll)/n;
        while(mn < mx) {
            long long mid = mn + (mx-mn+1)/2; 
            if(canRun(batteries, n, mid)) mn = mid; 
            else mx = mid-1; 
        }   return mn; 
    }
};