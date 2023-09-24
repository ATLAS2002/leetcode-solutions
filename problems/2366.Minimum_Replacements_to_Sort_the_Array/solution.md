# 💭 Intuition
1. Our objective is to split the elements in `div` parts, such that required operations are minimum. 
2. Splitting an element only decreases it, so we don't need to split the last element.
3. Hence we can loop from end of the array to the start.
4. One thing we need to keep in mind is while splitting an element, we must make sure the difference between them is as little as possible.
5. That way we can allow the previous element to be comparatively largest and therefore decrease the overall operations.
 
Check out the **Example** section for detailed explanation.
<hr/>

# 📝 Approach
- Run a loop *backwards* because we have to divide the elements based in the element that appears after it.
- Skip ahead if current element is already *smaller or equals* to next element.
- Since the parts have to be either equal or smaller than next element, we can divide `nums[i]` with `nums[i+1]`, and the ceil value `div` would be the number of parts we will be breaking `nums[i]` into.
- Add the extra parts `div-1` to the `ans`.
- Now change the current element to `nums[i]/div`, because we want the leftmost part to be large enough to minimize overall answer.
<hr>

# 👨🏻‍🏫 Example
- **Case 1:** `if(nums[i] % nums[i+1] == 0)`
```
nums = [3,12,4]
// Adjustment has to be made in nums[1]
// We need to break it into k pieces such that,
// 3 <= nums[1] <= ... <= nums[k+1] <= 4 

// Since we can break it evenly
// 3, 4, 4, 4, 4 --> it is a valid answer
```
- **Case 2:** `nums[i] %= nums[i+1]` *approach*
```
nums = [4,23,9]
// Though we can't break it evenly,
// We can try splitting like before

// To minimize the operations done, we can split like this 
// 4, 5, 9, 9, 9 --> this is a valid answer
```
- **Case 3:** `nums[i] /= div` *approach*
```
nums = [5,20,8]
// lets try splitting like before
// 5, 4, 8, 8, 8 

// oh wait! now we have to break nums[0]
// 1, 4, 4, 8, 8, 8 --> sorted, not the best answer

// seems like the number of operations has increased
// can't we do better? Yes we sure can.

// try to keep the difference between the parts minimum
// 5, 6, 7, 7, 8 --> valid answer
```
<!-- Describe your approach to solving the problem. -->
<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(N)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- 📦 Space complexity: $O(1)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
<hr/>

# ⌨️ Code
```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        for(int i=nums.size()-2; i>=0; i--) {
            if(nums[i] <= nums[i+1]) continue;
            int div = (nums[i] + nums[i+1] - 1) / nums[i+1];
            ans += div-1;
            nums[i] /= div;
        }   return ans;
    }
};
```