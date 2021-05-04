#include <bits/stdc++.h>

using namespace std;
template <class T>
class searcher{
    public:
        searcher(){
            loadData();
        }
        ~searcher(){
            delete []time;
            delete []comparisons;
        }
        void loadData(){
            ifstream file;
            file.open("file1.txt");
            string word;
            if(file.fail())
                cout<<"Faild to open file"<<endl;
            else
                while(file>>word){
                    words.push_back(word);
            }
            sort(words.begin(),words.end());
        }ي
        int binarysearch(vector<T> v,int start,int End,T key,int &n){
            if(start <= End){
                int mid = (start + End) /2;
                if(v[mid] == key){
                    n++;
                    return mid ;
                }
                else if(v[mid] < key){
                    n++;
                    return binarysearch(v , mid+1 , End , key,n);
                }
                else{
                    n++;
                    return binarysearch(v , start , mid-1 , key,n);
                }
            }
            return -1;
        }
        vector<T> f(){
            return words;
        }
        int testPerformance(vector<T> v,vector<T> v2){
            time = new double[100];
            comparisons = new int[100];
            int random;
            int compNum=0;
            double sec;
            clock_t start,End;
            int Test;
            unsigned seed=chrono::steady_clock::now().time_since_epoch().count();
            default_random_engine gen(seed);
            cout<<"Enter test choice"
                <<"\n1-->>>existing words"
                <<"\n2-->>>non existing words\n";
            cin>>Test;
            if(Test == 1){
                uniform_int_distribution<int> dist(0,v.size()-1);
                for(int i=0;i<100;i++){
                    random =dist(gen);
                    start = clock();
                    cout<<binarysearch(v,0,v.size()-1,v[random],compNum)<<"--->>"<<v[random]<<endl;
                    End = clock();
                    sec= End-start;
                    sec = sec/CLOCKS_PER_SEC;
                    time[i]=sec;
                    comparisons[i]=compNum;
                    compNum=0;
                }
            }
            else if(Test == 2){
                uniform_int_distribution<int> dist(0,v2.size()-1);
                for(int i=0;i<100;i++){
                    random =dist(gen);
                    start = clock();
                    cout<<binarysearch(v,0,v.size()-1,v2[random],compNum)<<"--->>"<<v2[random]<<endl;
                    End = clock();
                    sec= End-start;
                    sec = sec/CLOCKS_PER_SEC;
                    time[i]=sec;
                    comparisons[i]=compNum;
                    compNum=0;
                }
            }
        }
        double *gettime(){
            return time;
        }
        int *getcomp(){
            return comparisons;
        }
    private:
        vector<T> words;
        double *time;
        int *comparisons;
};
void storedata(double* t,int* c);
int main()
{
    vector<string> words;
    searcher<string> s;
    string str="abconxyz";
    unsigned seed=chrono::steady_clock::now().time_since_epoch().count();
    for(int i=0;i<100;i++){
        shuffle(str.begin(),str.end(),default_random_engine(seed));
        words.push_back(str);
    }
    cout<<"size is "<<s.f().size()<<endl;
    s.testPerformance(s.f(),words);
    double *t;
    int *c;
    t=s.gettime();
    c=s.getcomp();
    double sum_t=0;
    int sum_c=0;
    for(int i=0;i<100;i++){
        sum_t+=*(t+i);
        sum_c+=*(c+i);
    }
    cout<<"The average time is: "<<sum_t/100.0<<endl;
    cout<<"The average number of comparisons is: "<<sum_c/100<<endl;
    storedata(t,c);

    return 0;
}
void storedata(double* t,int* c){
    ofstream infile;
    infile.open("data.csv",ios::out);
    if(infile.fail()){
        cout<<"Failed to open file"<<endl;
    }
    else{
        for(int i=0;i<100;i++){
            infile<<*(t+i)<<','<<*(c+i)<<endl;
        }
    }
    infile.close();
}
