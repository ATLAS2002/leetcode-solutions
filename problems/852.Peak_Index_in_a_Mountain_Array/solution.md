# :thought_balloon: Intuition
We can only achieve $O(logN)$ complexity by implementing _binary search_. 
#### What we know :
- Peak element **always exists**.
- Left side of peak element is a **non-empty increasing** sequence.
- Right side of peak element is a **non-empty decreasing** sequence.

So the peak element must lie between 2nd and 2nd last element of `arr`. Left and right neighbours must be smaller than peak element.

<hr/>

# :pencil: Approach
We can start the search from index `1` to `n-2`. 
Then we find the `mid` index, where `mid = (start + end) / 2`.
#### The `mid` element can be ...
- ***Greater than both `mid-1` and `mid+1` element*** :
    In that case, `mid` element will be peak element so return it.
- ***Greater than `mid-1` but lesser than `mid+1`***:
    Which means it is a part of **increasing sequence**, that tells us peak element is ahead of `mid` element. So we increase `start` to `mid+1`.
- ***Lesser than `mid-1` but greater than `mid+1`***:
    `mid` element is part of **decreasing sequence**. Which implies peak element is before this, so we decrease `end` to `mid-1`.

<hr/>

# :bar_chart: Complexity
- :hourglass_flowing_sand: Time complexity: $O(logN)$

- :package: Space complexity: $O(1)$

<hr/>

# :keyboard: Code
```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size()-2;
        while(start<=end){
            int mid = start + (end-start)/2; // this way we can avoid overflows
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1])
                return mid; // peak element found
            else if(arr[mid]>arr[mid-1])
                start = mid+1; // peak element ahead
            else 
                end = mid-1; // peak element behind
        } 
        return -1; // you can return any value, since the code won't execute this far
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Peak Index in a Mountain Array`](https://leetcode.com/problems/peak-index-in-a-mountain-array)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $25/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  
