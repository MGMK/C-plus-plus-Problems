#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

///Developed by Mahmoud Magdy & Mohamed hamdy

struct book{
    char ISBN[6];
    char title[30];
    char authorname[30];
    char price[11];
    char year[11];
    char pages[11];
};
istream& operator>>(istream& in,book& b);
void addbook(fstream& out,book& b);
void print(fstream& in);
void printall(fstream& in);
int recordsNum(fstream& in);
void update();
void delet();
int main()
{
    fstream file;
    file.open("file.txt",ios::in | ios::out);
    string option;
    cout<<"1-insert book.\n"
        <<"2-update record.\n"
        <<"3-delete record.\n"
        <<"4-print book by title.\n"
        <<"5-print all books.\n";
    cin>>option;
    if(option=="1"){
        cin.ignore();
        book b1,b2;
        cin>>b1;
        addbook(file,b1);
        cin>>b2;
        addbook(file,b2);
    }
    else if(option=="2"){
        cin.ignore();
        file.close();
        update();
    }
    else if(option=="3"){
        cin.ignore();
        file.close();
        delet();
    }
    else if(option=="4"){
        cin.ignore();
        print(file);
    }
    else if(option=="5"){
        cin.ignore();
        printall(file);
    }
    file.close();
    return 0;
}
istream& operator>>(istream& in,book& b){
    cout<<"Enter ISBN:";
    in.getline(b.ISBN,6);
    cout<<"\nEnter title:";
    in.getline(b.title,30);
    cout<<"\nEnter author name:";
    in.getline(b.authorname,30);
    cout<<"\nEnter price:";
    in.getline(b.price,11);
    cout<<"\nEnter year:";
    in.getline(b.year,11);
    cout<<"\nEnter number of pages:";
    in.getline(b.pages,11);
    cout<<endl;
    return in;
}
ostream& operator<<(ostream& os,book& b){
    os<<b.ISBN<<"|"<<b.title<<"|"<<b.authorname<<"|"<<b.price<<"|"<<b.year<<"|"<<b.pages<<endl;
    return os;
}
void addbook(fstream& out,book& b){
    char buffer[200];
    strcpy(buffer,b.ISBN);strcat(buffer,"|");
    strcat(buffer,b.title);strcat(buffer,"|");
    strcat(buffer,b.authorname);strcat(buffer,"|");
    strcat(buffer,b.price);strcat(buffer,"|");
    strcat(buffer,b.year);strcat(buffer,"|");
    strcat(buffer,b.pages);strcat(buffer,"|\n");
    short length = strlen(buffer);
    //out.write((char*)&length,sizeof(length));
    out.write(buffer,length);
}
void printall(fstream& in){
    char*buffer;
    in.seekg(0,ios::end);
    long Size = in.tellg();
    in.seekg(0);
    buffer = new char[Size];
    in.read(buffer,Size);
    cout<<buffer<<endl;
    delete []buffer;
}
int recordsNum(fstream& in){
    int num=0;
    string x;
    while(getline(in,x)){
        num++;
    }
    in.clear();
    in.seekg(0);
    return num;
}
void print(fstream& in){
    char title[30];
    cout<<"Enter the title of the book:";
    cin>>title;
    string a;
    book b;
    while(getline(in,a)){
        istringstream iss(a);
        iss.getline(b.ISBN,6,'|');
        iss.getline(b.title,30,'|');
        iss.getline(b.authorname,30,'|');
        iss.getline(b.price,11,'|');
        iss.getline(b.year,11,'|');
        iss.getline(b.pages,11,'|');
        if(strlen(b.title)==strlen(title)){
            for(int i=0;i<strlen(title);i++){
                if(title[i]!=b.title[i])
                    break;
                else if(title[i]==b.title[i] && i==strlen(title)-1){
                    cout<<b<<endl;
                    return;
                }
            }
        }
    }
}
void update(){
    char ISBN[6];
    char title[30];
    char authorname[30];
    char price[11];
    char year[11];
    char pages[11];
    fstream file;
    file.open("file.txt",ios::in);
    fstream temp;
    temp.open("temp.txt",ios::out);
    char ISBN1[6];
    cout<<"Enter ISBN:";
    cin>>ISBN1;
    string x;
    book b;
    while(getline(file,x) && !file.fail()){
        istringstream ss(x);
        ss.getline(ISBN,6,'|');
        ss.getline(title,30,'|');
        ss.getline(authorname,30,'|');
        ss.getline(price,11,'|');
        ss.getline(year,11,'|');
        ss.getline(pages,11,'|');
        if(!strcmp(ISBN1,ISBN)){
            cin.ignore();
            cin>>b;
            temp<<b.ISBN<<'|'<<b.title<<'|'<<b.authorname<<'|'<<b.price<<'|'<<b.year<<'|'<<b.pages<<'|'<<endl;;
        }
        else{
            temp<<ISBN<<'|'<<title<<'|'<<authorname<<'|'<<price<<'|'<<year<<'|'<<pages<<'|'<<endl;
        }
    }
    file.close();
    temp.close();
    remove("file.txt");
    rename("temp.txt","file.txt");
}
void delet(){
    char ISBN[6];
    char title[30];
    char authorname[30];
    char price[11];
    char year[11];
    char pages[11];
    fstream file;
    file.open("file.txt",ios::in);
    fstream temp;
    temp.open("temp.txt",ios::out);
    char ISBN1[6];
    cout<<"Enter ISBN:";
    cin>>ISBN1;
    string x;
    while(getline(file,x) && !file.fail()){
        istringstream ss(x);
        ss.getline(ISBN,6,'|');
        ss.getline(title,30,'|');
        ss.getline(authorname,30,'|');
        ss.getline(price,11,'|');
        ss.getline(year,11,'|');
        ss.getline(pages,11,'|');
        if(strcmp(ISBN1,ISBN)){
            temp<<ISBN<<'|'<<title<<'|'<<authorname<<'|'<<price<<'|'<<year<<'|'<<pages<<'|'<<endl;
        }
    }
    file.close();
    temp.close();
    remove("file.txt");
    rename("temp.txt","file.txt");
}
