#include "LargestRectangle.hpp"
#include <stack>

using namespace LargestRectangleSolution;

// give you list int represent for height of each rectangle, width of rectangle is 1, return the largest rectangle area
int LargestRectangleSolution::Solution::largestRectangleArea(std::vector<int> &heights)
{
    int maxArea = 0;       // Initialize maxArea to 0
    std::stack<int> st; // Create an empty st to store the indices of the heights

    for (int i = 0; i <= heights.size(); i++)
    {
        // Get the current height. If we have reached the end of the heights, set it to 0
        int h = (i == heights.size() ? 0 : heights[i]);

        // If the st is empty or the current height is greater than or equal to the height at the index stored at the top of the st
        if (st.empty() || h >= heights[st.top()])
        {
            st.push(i); // Push the index of the current height onto the st
        }
        else
        {
            // Pop the index from the st and calculate the area of the rectangle using the popped index as the right boundary
            int tp = st.top();
            st.pop();
            int area = heights[tp] * (st.empty() ? i : i - 1 - st.top());
            maxArea = std::max(maxArea, area); // Update maxArea if the calculated area is greater than the current maxArea

            i--; // Decrement i to stay at the current index in the next iteration
        }
    }

    return maxArea; // Return the largest rectangle area
}

void LargestRectangleSolution::Run()
{
    auto sln = new Solution();

    std::vector t1 = {2,1,5,6,2,3};
    
    int res = sln->largestRectangleArea(t1);

}