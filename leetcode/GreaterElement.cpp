#include "GreaterElement.hpp"
#include <stack>
#include <iostream>
#include <map>


using namespace std;

vector<int> MonotonicStack::ConvertArrayToIncrease(vector<int>& arr)
{
    stack<int> stackContainer;
    
    vector<int> result;

    for(int i=0;i<arr.size();i++){

        while (!stackContainer.empty() && arr[stackContainer.top()] >  arr[i])
        {
            stackContainer.pop();
        }

        stackContainer.push(i);
    }

    while(!stackContainer.empty()){
        result.insert(result.begin(), stackContainer.top());
        stackContainer.pop();
    }

    return result;
}

void MonotonicStack::printNGE(vector<int>& arr)
{
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < arr.size(); i++) {

        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find
        next greater for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

vector<int> MonotonicStack::dailyTemperatures(vector<int>& temperatures){

    vector<int> ids;
    stack<int> stackTrace;

    stackTrace.push(0);

    for(int i=1;i<temperatures.size();i++){
        if(stackTrace.empty()){
            stackTrace.push(i);
            continue;
        }

        while (!stackTrace.empty() && temperatures[stackTrace.top()] > temperatures[i])
        {
            ids.insert(ids.end(), stackTrace.top());
            stackTrace.pop();
        }

        stackTrace.push(i);
    }

    while(!stackTrace.empty()){
        ids.insert(ids.end(), stackTrace.top());
    }

    return ids;
}


void RunMonotonicStack(){
    auto sln = new MonotonicStack();

    std::vector<int> nums{73,74,75,71,69,72,76}; // creates a 2-element vector holding {1, 2}

    auto result = sln->dailyTemperatures(nums);

    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    } 

}