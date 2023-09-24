# 💭 Intuition
First we need to determine whether we can get to the office at all. Even if we are going at maximum possible speed, we have to wait atleast an hour to get next train. If there are `n` trains, `hour` must be greater than `n-1`, otherwise we cannot reach office at time and `return -1`.
> Tests are generated such that the answer will not exceed $10^7$

We can use _binary search_ to efficiently find minimum speed to reach office in time. The range will be from $1$ to $10^7$. Choose a speed, if we can reach office by time then try to minimize current speed, else continue the search in higher range.

<hr/>

# 📝 Approach
- Check if `hour` is lesser than or equals to `n-1`, in that case return -1. <br/>
    Else we are sure there is a valid answer to be found.
- Starting range of speed is `mn`$=1$, maximum is `mx`$=10^7$. <br/>
    Now, `mx` is the speed which can get us to office in `hour` time.
- Next part is to find a smaller value for `mx`, which is lesser speed and will send us within `hour` time. <br/>
    So we run the loop until there is no better answer to be found (`mn < mx`).
- Take average of `mn` and `mx`, that is the `speed` we are checking for. 
- `timeRequired` function returns the time it will take to travel. 
- If `time` is not greater than `hour`, then `speed` is a valid answer till now and we set `mx = speed`. After that we search for better answer.
- If `time` is greater than `hour`, that means current speed is slow so we set `mn = speed+1`.
- After the loop breaks, which is triggered when search is over (`mn >= mx`). <br/>
    We return the minimum speed to reach within `hour` time, that is `mx`.

#### `timeRequired` function : 
- takes these are parameters :
    - `dist`: array that represents distance from each train  
    - `speed`: that is a double variable which is current speed of all trains. 
- stores the time required to reach in a local variable `time`.
- `time` = time to reach `n`-th train + time taken from `n`-th train <br/>
    = sum of `ceil` values of first `n-1` distance/`speed` + distance travelled by `n`-th train / `speed` <br/>
= $$\sum_{i=0} ^{n-2} \lceil\frac{dist_i}{speed}\rceil + \frac{dist_{n-1}}{speed}$$
- returns the local variable `time`.

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(NlogN)$

- 📦 Space complexity: $O(1)$

<hr/>

# ⌨️ Code

```cpp
class Solution {
private:
    // returns required time to reach office at a certain speed
    double timeRequired(vector<int>& dist, int speed) {
        int n = dist.size();
        double time = 0;
        for(int i=0; i<n-1; i++) 
            time += ceil(dist[i]*1.0/speed); // n-1 trains
        time += (dist[n-1]*1.0/speed); // last train
        return time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n-1) return -1; // n-1 hours is minimum requirement
        int mn = 1, mx = 1e7;
        while(mn < mx) {
            int speed = mn + (mx-mn)/2;
            double time = timeRequired(dist, speed); // time = distance / speed
            if(time <= hour) mx = speed; // acceptable
            else mn = speed+1; // slow speed
        }   return mx;
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Minimum Speed to Arrive on Time`](https://leetcode.com/problems/minimum-speed-to-arrive-on-time)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $26/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  
