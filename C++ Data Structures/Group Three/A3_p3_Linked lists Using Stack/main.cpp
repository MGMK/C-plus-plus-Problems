#include <iostream>
#include<stack>
using namespace std;
template<class T>
class stack_class
{
private:
    int size_stack,top;
    T *s_ptr;
public:
    stack_class(int s);
    stack_class();
    ~stack_class();
    void push(T value);
    void pop();
    bool is_full();
    T type_top();
}; // default constructor
template<class T>
stack_class<T>::stack_class()
{
    s_ptr=0;
    size_stack=0;
}
// constructor type
template<class T>
stack_class<T>::stack_class(int s)
{
    size_stack=s;
    top=-1;
    s_ptr=new T(s);
}
// DE constructor
template<class T>
stack_class<T>::~stack_class()
{

}
template<class T>
void stack_class<T>::push( T value)
{
    if(!is_full())
    {
        s_ptr[++top]=value;
        cout<<value<<endl;
    }
}
template<class T>
void stack_class<T>::pop()
{
    if(!is_full())
    {
        s_ptr[top--];
    }
}
template<class T>
bool stack_class<T>::is_full()
{
    if(top==size_stack-1)
    {
        return true;
    }
    else
        return false;
}
template<class T>
T stack_class<T>::type_top()
{

}
}
int main()
{
    stack_class<int>s(5);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(6);
    s.push(7);
     for(int i=0; i<5; i++)
    {
        s.push(i);

    }
    s.type_top();

    return 0;
}
