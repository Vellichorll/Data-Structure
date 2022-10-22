#include <bits/stdc++.h>
using namespace std;
bool isValid(string expr)
{
    stack<char> check;
    unordered_map<char, int> pairs = {{'(', 1}, {')', -1}, {'[', 2},{']', -2}, {'{', 3}, {'}', -3}};
    for(int i = 0; i < expr.size(); i++)
    {
        if(pairs.count(expr[i]))    // 检查括号
        {
            int value = pairs[expr[i]];
            if(value > 0)           // 左括号直接入栈
            {
                check.push(expr[i]);
            }
            else                    //检查右括号是否能与左括号匹配
            {
                if(!check.empty() && value == -pairs[check.top()]) check.pop();
                else return false;
            }
        }
    }
    // 完成表达式的读取后检查左括号栈还存在剩余元素，若存在，则不匹配
    return check.empty()? true : false;
}

int main()
{
    string expr;
    while(getline(cin, expr))
    {
        cout << (isValid(expr)? "Yes" : "No") << endl;
    }


}
