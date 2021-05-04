
#include <bits/stdc++.h>

using namespace std;
struct s{
    string item;
    int priority;
};
class que{
    public:
        que(){
            Size = 0;
            items = new vector<s>(Size);
        }
        que(unsigned int a){
            Size = a;
            items = new vector<s>(Size);
        }
        ~que(){
            delete items;
        }
        void enqueue(string x,int p,int a){
            (*items)[a].item = x;
            (*items)[a].priority = p;
        }
        string dequeue(){
            int p = (*items)[0].priority;
            string word = (*items)[0].item;
            int index=0;
            for(int i=1;i<items->size();i++){
                if((*items)[i].priority < p){
                    p = (*items)[i].priority;
                    word = (*items)[i].item;
                    index = i;
                }
            }
            items->erase(items->begin()+index);
            return word;
        }
        vector<s> *getitems(){
            return items;
        }
    private:
        unsigned int Size;
        vector<s> *items;
};

int main()
{
    string x;
    int p;
    que q(5);
    for(int i=0;i<5;i++){
        cout<<"Enter word: "; cin>>x;
        cout<<"Enter priority: "; cin>>p;
        q.enqueue(x,p,i);
    }
    cout<<q.dequeue()<<"  ";
    cout<<q.dequeue();

    return 0;
}
