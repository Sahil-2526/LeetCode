class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        long long ans = 1;
        multiset<int> negs;
        bool torch = false;
        int zeroCount = 0;

        for (int x : nums) {
            if (x > 0) {
                ans *= x;
                torch = true;
            }
            else if (x < 0) {
                negs.insert(x);
            }
            else {
                zeroCount++;
            }
        }

        if (negs.size() % 2 == 1) {
            negs.erase(prev(negs.end())); 
        }

        long long answer = 1;
        bool flash = false;

        for (int x : negs) {
            answer *= x;
            flash = true;
        }

        if (torch && flash) return ans * answer;
        if (torch) return ans;
        if (flash) return answer;

        return (zeroCount > 0 ? 0 : nums[0]);
    }
};

// first we will multiply  all positive numbers greater than equal to 1 and store it in ans 
// if alteast one one value is multiplied torch = true
// then we will store negative number in a multiset ans
// we will check if zero is there or not and count it
// if number of negative is odd then we will remove the largest negative number from multiset
// then we will multiply all negative number and store it in answer
// if atleat one added then flash = true  
// if torch and flash is true then we will return ans*answer
// if torch is true then we will return ans
// if flash is true then we will return answer
// if zero is there then we will return 0 else we will return the only element in nums ( as it is the only element and it is negative )