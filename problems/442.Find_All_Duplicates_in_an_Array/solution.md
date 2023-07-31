# 💭 Intuition
Solving this problem is pretty easy. Although achieving that within linear time complexity and constant space, with the ridiculous constraint makes it especially tricky.
1. 🥉 **Sorting the array :** <br/>
    Totally not optimal. It does have constant extra space but the time complexity is $O(NlogN)$ here. This is not good at all.
2. 🥈 **Using a hashmap :** <br/>
    Better approach, it follows the $O(N)$ time complexity, but the auxilary space also goes up to $O(N)$. Good, but not what you're looking for.

3. ❌ **Bit Mask :** <br/>
    > 1 <= n <= $10^5$ <br/>
    > 1 <= nums $_i$ <= n

    It is a powerful technique in the world of problem solving. It does not increase the time complexity, also takes constant space. However, there are certain conditions when you apply it. `n` has to be really small in that case.
If the constraints are $<=32$, you can use an `uint`, or you can go as high to 64 using `unsigned long long`. But the constraints here are way bigger than that, so it is impossible.
4. 🥇 **USING THE INPUT ARRAY AS THE HASHMAP :** <br/>
Think about it, in the hashmap solution we only needed a boolean array. 
    - Where we could set it from false to true when a number appears. <br/>
    `hash[nums[i]] = true;`
    - Later when we encounter the same number, `if(hash[nums]==true)` we append it to `ans`. <br/>
    Since every number appears at max twice only, no need to do further changes in `hash`. <br/>

    If you notice closely, the input array has elements from 1 to n (not necessarily distinct). And all elements are non negative.
   <br/>
THEN WHAT'S STOPPING US FROM USING IT AS THE HASHMAP? **NOTHING!**
    - The elements are from 1 to N. And we can use indexes from 0 to N-1. How convinient... 
    - On each iteration we have to mark the element as visited. And it has to be unique to identify. But how? <br/>
    Remember, all elements in the array is $>0$. We can mark it negative, which would imply that index+1 element has already appeared.
    - Take a look at the Approach to understand it better.

<hr/>

# 📝 Approach
#### The trick of this problem is to use the `nums` array to keep track of visited elements.
- To check if current element `nums[i]` has been visited before, we will check whether the element on index `abs(nums[i])-1` is negative or not.
- If `nums[abs(nums[i])-1]` is negative, then `abs(nums[i])` is previously visited. Push it into `ans` if that's the case.
- Since `nums[i]` is visited now, toggle the sign of `nums[abs(nums[i])-1]`.
    `nums[pos] = -nums[pos]` | where `pos = abs(nums[i]) - 1`

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(N)$

- 📦 Space complexity: $O(1)$

<hr/>

# ⌨️ Code
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int pos = abs(nums[i])-1; // use input array as the hashmap
            if(nums[pos] < 0) // appeared before    
                ans.push_back(pos+1); // push into ans 
            nums[pos] = -nums[pos]; // mark the index
        }
        return ans;
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Find All Duplicates in an Array`](https://leetcode.com/problems/find-all-duplicates-in-an-array)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $29/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  
