#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 

string findMinimumAfterRemoval(string inputStr, int numRem)
{
    int size = inputStr.size();
    stack<char> digitStack;
    for (char digit : inputStr) {
        while (!digitStack.empty() && numRem > 0
               && digitStack.top() > digit) {
            digitStack.pop();
            numRem -= 1;
        }
 
        if (!digitStack.empty() || digit != '0')
            digitStack.push(digit);
    }

    while (!digitStack.empty() && numRem--)
    {
        digitStack.pop();
    }
    if (digitStack.empty())
    {
        return "0";
    }

    while (!digitStack.empty()) {
        inputStr[size - 1] = digitStack.top();
        digitStack.pop();
        size -= 1;
    }
    return inputStr.substr(size);
}
 
int main()
{ 
    
   string numStr;
   cin >> numStr;
   int remDigits;
   cin >> remDigits;
   string result = findMinimumAfterRemoval(numStr, remDigits);
   cout << result << endl;


}
