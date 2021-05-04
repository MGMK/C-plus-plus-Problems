#include <bits/stdc++.h>

using namespace std;
class Stack{
public:
    queue<int>q;
    void push(int element);
    void pop();
    int top();

};
void Stack::push(int element){
    int Size = q.size();
    q.push(element);
    for(int i = 0 ; i < Size ;i++){
        q.push(q.front());  /// add the front element in
        q.pop();    /// to delete last element in stack .
    }
}
void Stack::pop()
{
    if (q.empty())
        cout << "Elements Not Found .\n";
    else
        q.pop();
}

int Stack::top()
{
    if (q.empty()) return -1;
    else return q.front();
}
int main()
{
    Stack object;
    object.push(1);
    object.push(2);
    cout << "The Top Element : "<< object.top() << endl;
    object.pop();
    object.push(3);
    object.pop();
    cout << "The Top Element : "<< object.top() << endl;
    return 0;
}
