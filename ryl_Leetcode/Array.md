## 26. Remove Duplicates from Sorted Array

**题目描述：**给定一个排序数组，移除数组中重复的元素，空间复杂度要求为O(1)

**解题思路：**引入一个标记变量，该标记变量用来记录数组中最终保留下的最新的元素的位置。该变量初始化为0位置，从1位置开始遍历整个数组。当array[i]!=array[index]时，index和i一起往后移动，需要注意的是array[i]的值应该是index+1位置上面的值，因为i在index的前面（这也是最后返回的时候是index+1，而不是index的原因）。如果相等，只移动i。只移动i相当于把重复的元素给略过了。

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())  return 0; 
        
        int index = 0;
        for (int i = 1; i<nums.size(); i++)
        {
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1; 
    }
};
```

## 80. Remove Duplicates from Sorted Array II 

**题目描述：**与Remove Duplicates from Sorted Array基本是一样的，只不过这里允许最多重复的数字为2

**结题思路：**结题思路也与I很相似，只不过这里需要在I的基础上在引入一个变量来记录重读的次数。这里最多允许有两个重复，言下之意就是在代码实现的时候最多只允许跳过一次重复的数。这里可以继续扩展到最多允许3个或者n个重复数字，在代码实现的时候就是允许跳过n-1次重复的数字，在这之后只能如果还出现重复的数字，那么就应该将循环变量往后面移动，将多余的重复的数字去掉。

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        int len = nums.size();
        int count = 1;
        int index = 0;
        for (int i=1; i<len; i++)
        {
            if(nums[index] == nums[i] && count<2)
            {
                count++;
                nums[++index] = nums[i];
            }
            else if(nums[index] != nums[i])
            {
                count = 1;
                nums[++index] = nums[i];
            }
        }
        
        return index+1;
    }
};
```

## 33.Search in Rotated Sorted Array

**题目描述：**

![1568647249065](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568647249065.png)

**解题思路：**

首先题目中给出的是一个升序序列并且没有重复数字，然后一某一个基准元素进行旋转，旋转之后被分成了两端但是每一段上还是递增的。我们知道当序列是有序的时候一般会使用二分查找的方法去找元素，这样速度比较快，并且时间复杂度是O(logn)。但是对于这种不是完全有序的序列如何进行查找呢？首先我们会发现一个规律，当旋转之后的序列如果中间值小于最右边的值，则中间值右边的部分肯定是递增的，如果中间值大于最后面的值，说明中间值的左半部分肯定是递增的，下面举个例子：

原始数组：[1, 2, 4, 5, 7, 9 ]

旋转后的数组：[5, 7, 9, 1, 2, 4] (此时中间值大于最右边值)

旋转后的数组：[7, 9, 1, 2, 4, 5] (此时中间值小于最右边值)

基于这种发现，我们可以用二分查找的方法解决这个问题.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        // 通过上面的初始值可以知道，while循环的条件需要取等号，搜索区间为：[l,r]
        while( l<=r )
        {
            // >>1表示的是除以2
            int mid = l + ((r - l)>>1);
            if(nums[mid] == target) return mid;
            // nums[mid] < nums[r] 说明mid左边的元素是升序的
            if(nums[mid] < nums[r])  
            {   
                //但是还需要进一步确定target是否在右边这个范围内，如果在的话就直接使用二分查找缩小范围
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;    
                }
                else  // 当target不在左边的升序序列中时，mid往反方向进行缩减
                {
                    r = mid - 1;
                }
            }
            else 
            {
                if (target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        
        return -1;
    }
};
```

## 81. Search in Rotated Sorted Array II

**题目描述：**

![1568647868415](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568647868415.png)

**解题思路：**

该题再30题的基础上去掉了没有重复元素的约束，其实我们可以发现当有重复元素，但是旋转的时候没有在重复元素中间进行旋转的话，相当于重复的元素没有散开还是连在一起也可以认为是升序的，此时用30题中的方法（中间值小于最右边的值，则右半段是递增的，中间值小于最右边的值则左半段是递增的，此时没有重复数字所以没有等于的情况）仍然可以通过。那么如果在重复数字中间进行旋转会出现什么情况呢？下面通过一个例子进行说明：

原始数组：[1 1 1 1 1 5]

旋转后的数组：[1 5 1 1 1 1]

旋转后的数组：[1 1 1 1 5 1]

上面是随便举的例子，当数组在重复数字中间进行旋转，可能有上述的两种结果（当然还有其他的很多种结果），但是我们会发现当出现这种情况，只有一种现象出现，那就是中间的值等于最右边的值，此时上述两种情况都能说明这件事情，并且通过上述的这两种情况我们会发现此时我们无法判断数组在哪一边是递增的（二分查找只能对有序序列进行查找）。此时我们相比于30题时多了一种判断，那就是如果中间值等于右边值的时候的处理方法。既然当中间值等于最右边值的时候我们无法进行判断，我们可以让右边的位置往前面移动一个，直到不相等的时候，此时右半段就是递增的，可以用二分搜索进行查找。

注意：由于第30题，用的是将中间值与最右边值进行比较，所以这里也采用这种比较的方法，也可以将中间的值与最左边的值进行比较，具体的操作就基本相反了。

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while( l<=r )
        {
            int mid = l + ((r-l)>>2);
            
            if(nums[mid] == target) return true;
            
            if(nums[mid] < nums[r])
            {
                
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1; 
                }
            }
            else if(nums[mid] > nums[r])
            {
                if(target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else  //此时中间值等于最右边值
            {
                r--;
            }
        }
        return false;
    }
};
```



## 128. Longest Consecutive Sequence

题目描述：

![1568772449859](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568772449859.png)

解题思路：

![1568771179332](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568771179332.png)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> h;
        for(int num : nums)
        {
            if(h.count(num)) continue; //去除重复的数
            
            // 查找num的左右两边是否有邻居，有的话返回邻居的连续序列长度，没有的话返回0
            auto it_l = h.find(num - 1);
            auto it_r = h.find(num + 1);
            int l = it_l != h.end() ? it_l->second : 0;
            int r = it_r != h.end() ? it_r->second : 0;
            
            //左右都有元素，相当于一个桥，将桥的两边的长度+1 
            if (l>0 && r>0)
            {
                h[num] = h[num - l] = h[num + r] = l + r + 1;
            }
            else if(l>0)  // 左边有邻居，将最左边的边界的连续序列长度加1
            {
                h[num] = h[num - l] = l + 1;
            }
            else if(r>0)  // 右边有邻居， 将最右边的边界的连续序列长度加1
            {
                h[num] = h[num + r] = r + 1;
            }
            else  // 左右都没有邻居，那么它本身连续序列长度就是1
            {
                h[num] = 1;
            }  
        }
        
        //遍历hash table
        int ans = 0;
        for (const auto& kv : h)
        {
            ans = max(ans, kv.second);
        }
        return ans;
    }
};

```

代码优化：

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> h;
        int ans = 0;
        for(int num : nums)
        {
            // 去重
            if(h.count(num)) continue;
            
            // 查找左右边界
            auto it_l = h.find(num - 1);
            auto it_r = h.find(num + 1);
            
            int l = it_l != h.end() ? it_l->second : 0;
            int r = it_r != h.end() ? it_r->second : 0;
            int t = l + r + 1;
            
            h[num] = h[num - l] = h[num + r] = t;
           
            ans = max(ans, t);
        }
        
        return ans;
    }
};
```



**解法2：但是会超时，可以学习思想**

![1568772957752](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568772957752.png)



```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums)
        {
            if(!h.count(num-1))
            {
                int l = 0;
                while(h.count(num++)) ++l;
                ans = max(ans, l);
            }
        }
        
        return ans;
    }
};
```

## 1.Two sum

**题目描述：**

![1568775187311](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568775187311.png)

**解题思路：**

使用一个hash table，直接查找target-nums[i]是否在hash table中，如果在说明原始数组中存在两个数相加等于target，如果不在，则将nums[i]添加到hash table 中，但是需要注意的是使用数组的值作为key, 数组的索引作为value。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        for(int i=0; i<nums.size(); i++)
        {
            if (h.count(target - nums[i]))
            {
                return {h[target-nums[i]], i};
            }
            h[nums[i]] = i;
        }
        return {};
    }
};
```

## 15. 3Sum

题目描述：

![1568902975995](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568902975995.png)

解题思路：

因为最终返回的是所有的满足三个数和等于零的三元组，而不是对应的下标，所以首先对数组进行排序，然后充分利用排序后数组的性质，去遍历整个数组，在遍历的同时再使用左右两个指针分别指向当前遍历元素的下一个元素，以及数组的最后一个元素，通过判断这三个元素的和的大小来将前后两个指针进行移动进而逼近目标值0.但是由于不能出现重复的，所以在遍历整个数组的时候，遇到相同的数字应该跳过（因为数组已经有序了所以只要相同的跳过，后面也就不会在遇到了）。

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i=0; i<n-2; i++)  //注意数组后面的空余
        {
            if (nums[i]>0) break;
            if (i>0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1;
            int r = n-1;
            while(l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ret.push_back({nums[i], nums[l++], nums[r--]});
                    while(l < r && nums[l] == nums[l-1]) ++l;
                    while(l < r && nums[r] == nums[r+1]) --r;
                }
                else if(nums[i] + nums[l] +nums[r] < 0) ++l;
                else --r;
            }
        }
        return ret;
    }
};

```



## 16. 3Sum Close

题目描述：

![1568903387937](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568903387937.png)

解题思路：

    1. 首先分析题目是要返回满足条件的数组的值的集合，而不是其索引，所以这里可以对原数组进行排序
    2. 可以三个指针，一个用来遍历整个数组，另外两个分别位于排序后数组的最前端和最后端
    3. 计算三个指针所对应的值的和，如果和等于target，即是最近的，直接返回就行，因为题目中说了只有唯一解
    3. 如果和大于target， 首先判断这次的sum与target的距离是不是比上一次的更接近，如果是的话就把这次的记录下来，否则
        根据情况将两个指针进行推移
    4. 指针推移的准则是：在每一次外层遍历中（即对于i的遍历），如果sum>target，通过调节另外另个指针来缩小差距，此时应该
        将二层循环中指向较大值那边的指针往中间移动，反之是将指向较小值的指针往中间移动
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int gap = INT_MAX;
        int ret;
        const int n = nums.size();
        for (int i=0; i<n-2; i++)
        {
            int l = i+1;
            int r = n-1;
            
            while( l<r )
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                //每次遍历都要记录当前的和与target的距离，如果更小则更新最近的sum，否则保留上一次的sum
                int diff = abs(sum-target);
                if (diff<gap)
                {
                    gap = diff;
                    ret = sum;
                }
                
                if (sum>target) --r;
                else ++l;
            }
        }
        
        return ret;
    }
};

```

## 18. 4Sum

**题目描述：**

![1568983293018](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568983293018.png)

**解题思路：**

这题的解题思路和前面的3Sum，3Sum close很相似，也是先对数组进行排序，然后使用两个头尾指针进行逼近。

但是为了提高算法的效率，需要对一些特殊情况进行判断。

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        const int n = nums.size();
        for(int i=0; i<n-3; ++i)
        {
            if (i !=0 && nums[i] == nums[i-1]) continue;
            //最大的都比目标值小，或者最小的都比目标值大，直接退出循环
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            
            for(int j = i+1; j<n-2; ++j)
            {
                int l = j+1;
                int r = n-1;
                
                if (j != i+1 && nums[j] == nums[j-1]) continue;
                    
                while(l<r)
                {
                    if(nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while(l<r && nums[l] == nums[l-1]) l++;
                        while(l<r && nums[r] == nums[r+1]) r--;
                    }
                    else if(nums[i] + nums[j] + nums[l] + nums[r] > target)
                        while(l<--r && nums[r] == nums[r+1]);
                    else
                        while(++l<r && nums[l] == nums[l-1]);
                }
                
            }
        }
        return ret;
    }
};
```



## 27. Remove Element

**题目描述：**

![1568983633770](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1568983633770.png)

解题思路：

这道题与26. Remove Duplicate from Sorted Array有点点类似，26题是对已经有序的数组删除重复元素，采用的方法是引入一个从零开始的变量作为数组最新元素的索引，如果遇到相等的值，循环变量加1跳过知道遇到不相等的值，引入的变量和循环变量同时往后面移动。这道题是给定一个要删除的数，直接在原地删除，同样可以使用一个索引来作为数组中更新最新的元素，然后遍历数组，如果当前数组的值与目标值不相等，则索引值和遍历数组的值一起往后移动，否则只移动遍历数组的那个量。

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {return 0;}
        // 直接定义一个索引，在原数组上进行修改
        int ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[ret++] = nums[i]; //如果与目标值不相等，把值放在该数组新的索引上，然后++
            }
        }
        return ret;
    }
};
```



## 31. Next-Permutation

**题目描述：**

![1569248500777](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569248500777.png)

**解题思路：**

题目的大概意思就是，给定一个多位的数值，让你使用序列中的数字，重新排列成比原始数值大的所有值中最小的那一个数值叫做下一个排列。

可以从数字的最低位（个位），从后往前遍历到第一个不满足升序的数字，将它的下标记为i,在从所有的数字中找出比nums[i]大的元素中最小的那一个，将其下标记为j,然后将nums[i],和nums[j]进行交换，在将i后面的所有元素逆转。这样就是一个满足要求的下一个排列。

刚开始不好理解，多想想就好了。

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        
        //找到第一个不满足升序的元素索引
        while(i>=0 && nums[i+1] <= nums[i]) i--;
        
        //第i个元素后面找比nums[i]大但是最小的那个元素的索引
        if(i>=0)
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }

        reverse(begin(nums) + i + 1, end(nums));
    }
};

```

## 60. Permutation Sequence

**题目描述：**

![1569248902119](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569248902119.png)

**解题思路：**

写这题首先需要对31.Next Permutation理解了才能理解这里的第K个排列。就是说给定一个数字n,形成了一个1~n的序列[1,2,3,...,n]作为初始的序列，然后求这个序列的第k个排列（想一想next permutation）

最简单的一种做法就是使用next permutation k-1次就得到了结果，因为C++ 中自带了next_permutation 这个函数，并且效率比自己写的高，所以直接使用自带的函数来完成。

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret = "";
        for(int i=0; i<n; i++) ret += i + '1';
        while(--k)
        {
            next_permutation(ret.begin(), ret.end());
        }
        
        return ret;
    }
};
```

更高效的思路下次有空在补上。

## 36. Valid Suduku

题目描述：

![1569335040747](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569335040747.png)

解题思路：

要想检查整个数独是否有效，只需要按照有效数独的三个定义进行检查判定即可。即每一行每一列并且中间的3x3的格子中的元素都在1-9之间并且不能重复。这里使用C++中的set作为数据结构，set的insert操作可以返回元素是否插入成功。

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //判断行和列
        for(int i=0; i<9; i++)
        {
            set<char> r, c;
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.' && !r.insert(board[i][j]).second)
                    return false;
                if(board[j][i] != '.' && !c.insert(board[j][i]).second)
                    return false;
            }
        }
        //判断3x3的格子
        for(int p=0; p<3; p++)
        {
            for(int q=0; q<3; q++)
            {
                set<char> box;
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        int x = p*3 + i;
                        int y = q*3 + j;
                        if(board[y][x] != '.' && !box.insert(board[y][x]).second)
                            return false;
                    }
                }
                
            }
        }
        return true;
    }
};
```

## 42. Trap Rain Water

题目描述：

![1569336158359](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569336158359.png)

解题思路：

下面这个链接给出了求解这个问题的三种方法。

https://www.cnblogs.com/logosg/p/7979690.html

这里使用第一种方法，效率比较低。

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        for(int i=1; i<size-1; i++)
        {
            int max_right = 0;
            int max_left = 0;
            for(int j=i; j>=0; j--)
            {
                max_left = max(max_left, height[j]);
            }
            
            for(int j=i; j<size; j++)
            {
                max_right = max(max_right, height[j]);
            }
            
            ans += min(max_left, max_right) - height[i];
        }
        
        return ans;
    }
};
```

## 48. Rotate Image

题目描述：

![1569405528714](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569405528714.png)

解题思路：

题目的意思是将一个矩阵顺时针旋转90度。也就是第一行变成了最后一列，第二行变成倒数第二列，以此类推。矩阵的转置是第一行变成第一列，第二行变成第二列，一次类推。所以我们可以先把矩阵进行转置之后再将每一行的元素进行reverse。

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```



## 66. Plus one

题目描述：

![1569405384754](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569405384754.png)

解题思路：

题目的意思就是将一个数组看做一个整数，然后返回加1之后的数组。这里主要需要注意的就是加1之后可能会使得整个数组变长。

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int c = 1;
        while(n>=0)
        {
            digits[n] += c;
            c = digits[n] / 10;
            digits[n] = digits[n] % 10;
            n--;
        }
        
        //需要考虑可能一直有进位，导致最后数组增加了一个元素
        if (c>0) digits.insert(digits.begin() , c);
        
        return digits;
    }
};

```

## 89. Gray code

题目描述：

![1569462690949](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569462690949.png)

解题思路：

格雷码其实是一种特殊的二进制编码方式，并且从二进制码转换到格雷码是有一定的规律的：保留二进制码的最高位为格雷码的最高位，然后格雷码的次高位为二进制码的最高位与次高位的异或，一次类推。

![1569462800054](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569462800054.png)

所以可以根据这种性质直接将一个数进行格雷编码。

题目中给出了编码的总位数，所以这里需要注意的是，如果是从二进制转换到格雷码这种方式进行求解，迭代的次数是$2^n$也就相当于是二进制的位数。

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        // 异或运算符是从低位到高位进行异或计算
        vector<int> ret;
        for(int i=0; i<pow(2, n); i++)
        {
            ret.push_back(i^(i>>1));
        }
        return ret;
    }
};
```

## 70. Climbing Stairs

题目描述：

![1569462378885](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569462378885.png)

解题思路：

题目的大概意思就是，爬楼梯只有两种爬法，要么每次爬一个step要么每次爬两个step，然后给出需要爬的楼梯的总的step，求解总共有多少中爬楼梯的方法。

这道题是经典的简单的动态规划的题目。递归的思想是自定向下，而动态规划的思想是自底向上，每次都是用前面保存的结果来进行计算，相比于递归少做了很多次重复的计算。动态规划解题的主要步骤就是找到动态转移方程，然后利用动态转移方程，自底向上求解问题。

```cpp
class Solution {
public:
    int climbStairs(int n) {
        // f[i] = climbStairs(i)
        vector<int> f(n+1);
        f[0] = 1;
        f[1] = 1; 
        for(int i=2; i<=n; i++)
        {
            f[i] = f[i-1] + f[i-2];
        }

        return f[n];
    }
};
```

## 55. Jump Game

题目描述：

![1569599150504](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1569599150504.png)

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0];
        const int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(far < i) break;
            far = max(far, i+nums[i]);
        }

        return far >= (n-1);
    }
};
```

## 73. Sets metrix zeroes

题目描述：

![1570026865908](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570026865908.png)

![1570026898875](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570026898875.png)

解题思路：

1. 最简单的方法就是变量整个数组中的每个元素，当该元素为零时，将其对应的行和列置零，新建两个数组来标记哪些行需要进行置零。

空间复杂度：O(m+n)

时间复杂度：O(n^2)

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                //注意：下面是使用|=，这里如果使用=的话可能会造成，前面出现过0，置零后，后面出现非零，又被置成非零了。
                row[i] |= (matrix[i][j] == 0);
                col[j] |= (matrix[i][j] == 0);
            }

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(row[i]  || col[j]) matrix[i][j] = 0;

    }
};
```

2. 上述是最简单粗暴的方法，但是题目中说到如何使用常数级的空间复杂度去解决这个问题。该如何使用常数集的空间复杂度呢？一种可行的办法：将数组的第一行和第一列用来存储中间的1：m行，1：n列中哪些需要置零，这样的话首先就应该判断第一行和第一列是否需要进行置零，不然第一行和第一列的值会被替换了

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool row0 = false;
        bool col0 = false;

        for(int j=0; j<n; j++)
            row0 |= (matrix[0][j] == 0);
        for(int i=0; i<m; i++)
            col0 |= (matrix[i][0] == 0);

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;      

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        if(row0)
            for(int j=0; j<n; j++) matrix[0][j] = 0;
        if(col0)
            for(int i=0; i<m; i++) matrix[i][0] = 0;  
        
    }
};
```

## 134. Gas station

题目描述：

![1570152191907](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570152191907.png)



解题思路：

1. 遍历每一个加油站点，看是否可以走到出发点。这里有可能中途就过不去，比如在某个站点时，剩余的油量不足以到达下一个站点，此时就没有必要继续试走了，直接换下一个站点。但是这种方法的效率特别低。此外这里使用了循环计数的方法，与数据结构中数组实现的栈是同样的思路

2. 从第一种解法可以看出时间复杂度是O(n^2)，第二种解法的思路是，不去试探某一个站点直到走到终点，因为这种做法不可避免时间复杂度是O(n**2)，而是在一次遍历中计算从开始站点（假设的可能作为开始站点）到某个站点的当前所有剩余的总油量以及从站点0到当前站点的总油量累加起来，如果在这个过程中出现，到达某个站点时的当前总油量小于零说明，从假设的开始站点无法到达该站点，那么从开始站点到当前站点的所有站点都无法作为开始站点，所以将下一个站点重新作为开始站点重新累加当前油量，直到遍历完所有的站点。最后判断总的油量剩余是不是不小于零，如果不小于零说明问题一定有解，这个解就是前面遍历的时候满足偶从那个起始站点到最后一个站点的油量都不小于零。这种做法避免了每次都去试探可能的站点一直走到开始点的那个复杂的过程。

暴力破解：

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        
        for (int i = 0; i < n; i++)
        {
            int remain = gas[i];
            int j = i;
            // 判断当前的油量是否可以到达下一个加油站
            while( (remain - cost[j]) >= 0 )
            {
                // 因为道路是环装的，所以需要进行循环计数
                remain = remain - cost[j] + gas[(j+1) % n];
                j = (j+1) % n;
                if( i==j ) return i;
            }
        }
        return -1;
    }
};
```

![1570152999262](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570152999262.png)

对于暴力解法的优化,几乎没有提升

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        vector<bool> start(n, false);
        int total = 0;
        int cost_t = 0;

        for(int i = 0; i < n; i++)
        {
            if (gas[i] - cost[i] >= 0) start[i] = true;

            total += gas[i];
            cost_t += cost[i];
        }
        // if (cost_t > total) return -1;

        for (int i = 0; (i < n) && (cost_t <= total); i++)
        {
            if (start[i])
            {
                int remain = gas[i];
                int j = i;
                // 判断当前的油量是否可以到达下一个加油站
                while( (remain - cost[j]) >= 0 )
                {
                    // 因为道路是环装的，所以需要进行循环计数
                    remain = remain - cost[j] + gas[(j+1) % n];
                    j = (j+1) % n;
                    if( i==j ) return i;
                }
            }
        }
        return -1;
    }
};
```

![1570153778735](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570153778735.png)

解法2代码：

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int total_overage = 0, overage = 0, start = 0;

        for(int i=0; i<n; i++)
        {
            total_overage += (gas[i] - cost[i]);
            overage += (gas[i] - cost[i]);

            if (overage < 0)
            {
                start = i+1;
                overage = 0;
            }
        }

        return (total_overage < 0) ? -1 : start;
    }
};
```



## 135. Candy

题目描述：

![1570157402292](C:\Users\ryLuo\AppData\Roaming\Typora\typora-user-images\1570157402292.png)

解题思路：

首先定义一个与ratings一样大的数组，并且将里面的值都初始化为1，因为题目中说明每个人至少有一个糖果。然后从数组的左边遍历到右边，如果右边的ratings值比右边的大，则将右边的值在左边值的基础上加1，然后从数组的右边遍历到左边，如果左边的值大于右边的值，那么左边的糖果数量应该大于右边的糖果数量，但是由于之前已经进行了一次从左边到右边的遍历，肯能已经满足了左边大于右边，此时是不需要再加的。所以这里需要取左边这个值与右边这个较小值加一之后的较大者。

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> ans(n, 1);
        for(int i=1; i<n; i++)
            if(ratings[i] > ratings[i-1]) ans[i] = ans[i-1] + 1;
        for(int i=n-2; i>=0; i--)
            if(ratings[i] > ratings[i+1]) ans[i] = max(ans[i], ans[i+1] + 1);

        return accumulate(begin(ans), end(ans), 0);
    }
};
```

这里使用到了C++ 标准库中的accumulate函数，第一个参数是起始位置，第二个参数是终止位置，第三个参数是累加时的初始值。