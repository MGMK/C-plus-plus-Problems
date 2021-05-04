#include <iostream>
using namespace std;
const int capacity=100;
class queuee
{
public:
    int front=-1;
    int rear=-1; //queue is empty
    queuee();
    ~queuee();
    int top();
    int arr[capacity];
    void push(int value);
    void pop();
    bool is__empty();
    bool is__full();
    int size_element();
};
queuee::queuee()
{

}
queuee::~queuee()
{

}
bool queuee:: is__empty()
{
    if(front==-1 && rear==-1)
    {
        return true;
    }
    else
        return false;
}
bool queuee::is__full()
{
    if(rear==capacity-1)
    {
        return true;
    }
    else
        return false;
}
void queuee::push(int value)
{
    if(is__full())
    {
        return ;// exit to this function and can not add element in the queue
    }
    else if(is__empty())
    {
        front=0 ;
        rear=0;
    }
    else
    {
        rear++;
    }
    arr[rear]=value;
}
void queuee::pop()
{
    if(is__empty())
    {
        return ; //exit this function and no element in the queue
    }
    else if (front ==rear)
    {
        front=rear=-1; // special case  queue is empty
    }
    else
    {
        front++;
    }
}
int queuee::top()
{
    return arr[0];
}

int main()
{
    queuee ob;
    ob.push(17);
    ob.push(10);
    ob.push(12);
    ob.push(50);
    ob.push(15);
    ob.push(66);
    ob.push(99);
    for(int i=0; i<7; i++)
    {
        cout<<ob.arr[i]<<"  ";

    }
    ob.pop();
    cout<<endl;
    cout<<ob.top();
    cout<<endl;
// cout<<ob.size_element();

    return 0;
}
