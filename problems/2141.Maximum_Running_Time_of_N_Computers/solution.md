# 💭 Intuition
Constraints are allowing the algorithm to be $O(NlogN)$, which helps use to find the answer using _binary search_. The answer is between 1 to _total energy of batteries divided by number of computers_. <br/>
For a chosen amount of time, we check if we can extract enough energy from batteries, such that it can run `n` computers for enough time.

<hr/>

# 📝 Approach
- `mn` is the starting point, and `mx` is the ending point of search.
    - `mn = 1`, because there is always enough batteries to run `n` computers for atleast 1 minute.
    - `mx = totalRuntime / n`, considering the best case where least energy is lost.
- `mn` is current answer, the loop is running to find a higher runtime. So we will run the loop until there is chance to make the answer higher (`mn < mx`).
- We will take `ceil` value of average of `mn` and `mx` as `mid`. Because We want to make next answer (`mid`) greater than current answer (`mn`). Otherwise the loop would stuck in infinite repeatations.
- `canRun` function checks if `n` computers can be run for `mid` minutes with `batteries`. If returned value is true then we set `mn = mid` and continue the search further.
- Otherwise set `mx = mid-1`, since it is now confirmed that `n` computers can't run for more than `mid-1` minutes.
- Return `mn` after the loop breaks.

#### `canRun` function :
- takes `batteries`_(energy of every battery)_, `computers`_(total number of computers)_ and `time`_(runtime of computers)_ as parameters.
- two local variables :
    - `energyRequired`: total energy `n` computers will need to run for `time` minutes. $[energyRequired = n * time]$
    - `energyAvailable`: maximum energy `batteries` can supply for `time` minutes. $[energyAvailable = \sum_{i=0}^{b-1}min(batteries_i,time)|where,b=batteries.size()]$
- Returns `true` if `energyRequired` is within `energyAvailable`, else returns `false`.

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(NlogN)$

- 📦 Space complexity: $O(1)$

<hr/>

# ⌨️ Code
```cpp
class Solution {
private:
    // checks if computers can run this long
    bool canRun(vector<int>& batteries, int computers, long long time) {
        long long energyRequired = time*computers;
        long long energyAvailable = 0;
        for(const int& battery : batteries) 
            energyAvailable += min((long long)battery, time);
        return energyRequired <= energyAvailable;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long mn = 1; // n <= batteries.size() && batteries[i] > 0
        long long mx = accumulate(batteries.begin(), batteries.end(), 0ll)/n;
        while(mn < mx) {
            long long mid = mn + (mx-mn+1)/2; // add 1 to avoid inf loop
            if(canRun(batteries, n, mid)) mn = mid; // improved ans
            else mx = mid-1; // can't run for mid minutes
        }   return mn; 
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Maximum Running Time of N Computers`](https://leetcode.com/problems/maximum-running-time-of-n-computers)
- :vertical_traffic_light: **Difficulty :** hard 
- :calendar: **Date :** $27/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  
