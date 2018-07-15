#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    Solution() = default;
    ~Solution() = default;


    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> result;
        for(auto iter = nums.begin(); iter != nums.end(); ++ iter){
            for(auto it = iter + 1; it != nums.end(); ++ it){
                if(*iter + *it == target){
                    result.push_back(int(0 + iter - nums.begin()));
                    result.push_back(int(0 + it - nums.begin()));
                    return result;
                }
            }
        }
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int current_flag = 0;
        int current_val = l1->val + l2->val + current_flag;
        current_val = current_val > 10 ? current_val % 10 : current_val;
        ListNode* result = new ListNode(current_val);
        ListNode* rt_result = result;
        current_flag = current_val > 10 ? 1 : 0;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 == nullptr)
                current_val = l2->val + current_flag;
            else if(l2 == nullptr)
                current_val = l1->val + current_flag;
            else
                current_val = l1->val + l2->val + current_flag;
            current_val = current_val > 10 ? current_val % 10 : current_val;
            current_flag = current_val > 10 ? 1 : 0;
            ListNode* next_result = new ListNode(current_val);
            result->next = next_result;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(current_flag == 1){
            ListNode* next_result = new ListNode(1);
            result->next = next_result;
        }
        return rt_result;
    }


    int lenOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        map<char, int> m;
        int n = s.length();
        int maxLength = 0;
        int pre = 0;
        for(int i=0; i<n; i++ ){
            map<char, int>::iterator iter=m.find(s[i]);
            if(iter!=m.end()){
                pre = max(pre, (m[s[i]]+1));
            }
            maxLength = max(maxLength, i-pre+1);
            m[s[i]]=i;
        }
        return maxLength;
    }
    int mySqrt(int x) {
        double currentResult = 1;
        double previousResult = 1;
        while(true) {
            currentResult = 0.5 * (currentResult + x / currentResult);
            if(currentResult <= previousResult && currentResult >= previousResult - 1)
                return int(currentResult);
            previousResult = currentResult;
        }
    }


    bool isPerfectSquare(int num) {
        bool isPSquare = false;
        double currentResult = 1;
        double previousResult = 1;
        int square = 1;
        while(true) {
            currentResult = 0.5 * (currentResult + num / currentResult);
            if (currentResult <= previousResult && currentResult >= previousResult - 1) {
                square = int(currentResult);
                break;
            }
            previousResult = currentResult;
        }
        if(square * square == num)
            isPSquare = true;
        return isPSquare;
    }


    bool judgeSquareSum(int c) {
        if(c < 0) return false;
        int sqt = int(sqrt(c));
        vector<int> result;
        if(sqt * sqt == c)
            return true;
        for(int i = 0; i <= sqt; ++ i)
            result.push_back(i * i);
        for(int i = sqt; i >= sqt / 2; -- i){
            for(auto it = result.begin(); it != result.end(); it ++){
                if(*it == c - result[i])
                    return true;
            }
        }
        return false;
    }


    int flipLights(int n, int m) {
        if(n == 1){
            if(m == 0)
                return 1;
            return 2;
        }
        if(n == 2)
            switch(m){
                case 0:
                    return 1;
                case 1:
                    return 3;
                case 2:
                    return 4;
                default:
                    return 4;
            }
        if(n >= 3)
            switch(m){
                case 0:
                    return 1;
                case 1:
                    return 4;
                case 2:
                    return 7;
                case 3:
                    return 8;
                default:
                    return 8;
            }
    }


    int reverse(int x) {
        int power = 0;
        vector<int> num;
        while(abs(x) >= 10){
            power ++;
            num.push_back(x % 10);
            x = x / 10;
        }
        num.push_back(x);
        int result = 0;
        if(power > 10)
            return 0;
        for(auto it = num.begin(); it != num.end(); ++it){
            if(result > 214748364 || (result == 214748364 && *it >= 7)){
                return 0;
            }
            else if(result < -214748364 || (result == -214748364 && *it <= -8)){
                return 0;
            }
            result = result * 10 + *it;
        }
        return result;
    }
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }

    bool detectCapitalUse(string word) {
        unsigned long size = word.size();
        unsigned long count = 0;
        for(unsigned long i = 0; i < size; ++i){
            if(word[i] <= 'Z') ++ count;
        }
        return count ==0 || count == size || (count == 1 && word[0] <= 'Z');
    }

    int maxArea(vector<int>& height) {
        int maxA = 0;
        int h = 0;
        int a = 0;
        auto it = height.begin();
        auto iter = height.end() - 1;
        while(iter > it){
            h = *iter < *it ? *iter : *it;
            a = h * (iter - it);
            maxA = maxA > a ? maxA : a;
            if(*iter > *it)
                it ++;
            else
                iter --;
        }
        return maxA;
    }

    string intToRoman(int num) {
        string ret = "";
        int th = num / 1000;
        while(th > 0){
            ret += "M";
            th --;
        }
        num = num % 1000;
        int hu = num / 100;
        if(hu < 4)
            while(hu > 0){
                ret += "C";
                hu --;
            }
        else if(hu == 4)
            ret += "CD";
        else if(hu == 9)
            ret += "CM";
        else{
            ret += "D";
            while(hu > 5){
                ret += "C";
                hu --;
            }
        }

        num = num % 100;
        int te = num / 10;
        if(te < 4)
            while(te > 0){
                ret += "X";
                te --;
            }
        else if(te == 4)
            ret += "XL";
        else if(te == 9)
            ret += "XC";
        else{
            ret += "L";
            while(te > 5){
                ret += "X";
                te --;
            }
        }

        int ett = num % 10;
        if(ett < 4)
            while(ett > 0){
                ret += "I";
                ett --;
            }
        else if(ett == 4)
            ret += "IV";
        else if(ett == 9)
            ret += "IX";
        else{
            ret += "V";
            while(ett > 5){
                ret += "I";
                ett --;
            }
        }
        return ret;
    }

    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++ i){
            if(s[i] == 'M'){
                ret += 1000;
                continue;
            }
            if(s[i] == 'D'){
                ret += 500;
                continue;
            }
            if(s[i] == 'C'){
                if(i < s.length() - 1){
                    if(s[i + 1] == 'M'){
                        ret += 900;
                        ++i;
                        continue;
                    }
                    else if(s[i + 1] == 'D'){
                        ret += 400;
                        ++i;
                        continue;
                    }
                }
                ret += 100;
                continue;
            }
            if(s[i] == 'L'){
                ret += 50;
                continue;
            }
            if(s[i] == 'X'){
                if(i < s.length() - 1){
                    if(s[i + 1] == 'C'){
                        ret += 90;
                        ++i;
                        continue;
                    }
                    else if(s[i + 1] == 'L'){
                        ret += 40;
                        ++i;
                        continue;
                    }
                }
                ret += 10;
                continue;
            }
            if(s[i] == 'V'){
                ret += 5;
                continue;
            }
            if(s[i] == 'I'){
                if(i < s.length() - 1){
                    if(s[i + 1] == 'X'){
                        ret += 9;
                        ++i;
                        continue;
                    }
                    else if(s[i + 1] == 'V'){
                        ret += 4;
                        ++i;
                        continue;
                    }
                }
                ret += 1;
                continue;
            }
        }
        return ret;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int diff = 2147483647;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            int flag = target - nums[i];
            while(j < k){
                if(nums[j] + nums[k] > flag){
                    if(nums[j] + nums[k] - flag < diff){
                        diff = nums[j] + nums[k] - flag;
                        ret = nums[i] + nums[j] + nums[k];
                    }
                    -- k;
                }
                else if(nums[j] + nums[k] < flag){
                    if(flag - nums[j] - nums[k] < diff){
                        diff = flag - nums[j] - nums[k];
                        ret = nums[i] + nums[j] + nums[k];
                    }
                    ++ j;
                }
                else
                    return nums[i] + nums[j] + nums[k];
            }
        }
        return ret;
    }

    int maxSubArray(vector<int>& nums) {
        int ret = 0;
        int max = -2147483648;
        int sum = 0;
        int flag = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] > 0)
                flag = 1;
            if(nums[i] > max)
                max = nums[i];
            sum += nums[i];
            if(sum > ret)
                ret = sum;
            else if(sum < 0)
                sum = 0;
        }
        if(flag)
            return ret;
        else
            return max;
    }

    int uniquePaths(int m, int n) {
        int M = m + n - 2;
        int N = m > n ? m - 1 : n - 1;
        double scale = 1;
        for(int i = M; i > N; -- i){
            scale *= i;
            scale /= (i - N);
        }
        return round(scale);
    }
};

int main() {
    Solution solution;
    string s = "PAYPALISHIRING";
    string c = solution.convert(s, 3);
    cout << c << endl;
    return 0;
}