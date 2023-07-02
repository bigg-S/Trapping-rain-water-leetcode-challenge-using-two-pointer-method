#include <vector>
#include <iostream>

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if (n <= 2)
            return 0;
        int water = 0;
        int left = 0;
        int right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];

        while (left < right) 
        {
            if (height[left] < height[right]) 
            {
                if (height[left] > leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                if (height[right] > rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

int main()
{
    Solution soln;

    std::vector<int> vec = { 4,2,3 };
    std::cout<<soln.trap(vec);
    return 0;
}

