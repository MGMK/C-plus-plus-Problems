#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

///Developed by Mahmoud Magdy & Mohamed hamdy

struct book
{
    char ISBN[6];
    char title[30];
    char authorname[30];
    char price[5];
    char year[5];
    char pagesNum[5];
};
ostream& operator<<(ostream& out,book& b);
void addbook();
int searchbook(ifstream& f);
void readbook(ifstream& f);
void deleteBook();
void deleterecord();
void update();
void printbook();
int main()
{
    //addbook();
    //addbook();
    //deleterecord();
    //deleteBook();
    //update();
    ifstream infile("file.txt");
   // cout<<searchbook(file)<<endl;
    // deleteBook();

    readbook(infile);

    infile.close();
    return 0;
}
ostream& operator<<(ostream& out,book& b)
{
    out<<b.ISBN<<" "<<b.title<<" "<<b.authorname<<" "<<b.price<<" "<<b.year<<" "<<b.pagesNum;
    return out;
}
void addbook()
{
    ifstream infile("file.txt");
    short av_list=searchbook(infile);
    infile.close();
    ofstream outfile("file.txt",ios::out|ios::app);
    cout<<"Available list is: "<<av_list<<endl<<endl;
    outfile.seekp(0,ios::beg);
   // outfile.write((char*)&av_list,sizeof(av_list));
    book b,new_b;
    cin>>new_b.ISBN;
    cin>>new_b.title;
    cin>>new_b.authorname;
    cin>>new_b.price;
    cin>>new_b.year;
    cin>>new_b.pagesNum;
    while(!outfile.fail())
    {
       if(av_list!=-1)
        {
            outfile.seekp(av_list*sizeof(new_b),ios::beg);
            outfile.write((char*)&new_b,sizeof(new_b));
            break;
        }
        else
        {
            outfile.write((char*)&new_b,sizeof(new_b));
            break;
        }
    }
    outfile.clear();
    outfile.close();
}
int searchbook(ifstream& f)
{
   // f.seekg(2l,ios::beg);
    book b;
    int counter =-1;
    char del = '*';
    bool deleted=false;
    while(f.good())
    {
        f.read((char*)&b,sizeof(b));
        counter++;
        if(del==b.ISBN[0]){
            f.seekg(0,ios::beg);
            return counter;
        }
    }
    f.seekg(0,ios::beg);
    if(deleted==false)
        counter=-1;
    return counter;
}

void readbook(ifstream& f)
{
    f.seekg(0,ios::beg);
    short av_list;
    char c;
   // f.read((char*)&av_list,sizeof(av_list));
    //cout<<"The available list is: "<<av_list<<endl;
    book b;
    while(f.good())
    {
        f.read((char*)&b,sizeof(b));
        cout<<b<<endl;
    }

    f.clear();
}
void deleteBook()
{
    ifstream infile("file.txt",ios::in);
    char ISBN[6];
    char del='*';
    cout<<"Enter ISBN:";
    cin>>ISBN;
    int counter =-1;
    bool exist = false;
    book b;
    while(infile.good()){
        infile.read((char*)&b,sizeof(b));
        counter++;
        if(!strcmp(ISBN,b.ISBN)){
            exist = true;
            //cout<<b<<endl;
            break;
        }
    }
    infile.close();
    ofstream outfile("file.txt",ios::out|ios::app);
    if(exist==true){
        outfile.seekp(counter*sizeof(b),ios::beg);
       // outfile<<del;
        outfile.write((char*)&del,sizeof(del));
    }
    outfile.close();
}
void deleterecord(){

   // short av_list;
    fstream file;
    file.open("file.txt",ios::in);
   // file.read((char*)&av_list,sizeof(av_list));
    fstream temp;
    temp.open("temp.txt",ios::out);
   // temp.write((char*)&av_list,sizeof(av_list));
    char ISBN1[6];
    cout<<"Enter ISBN:";
    cin>>ISBN1;
    book b;
    while(file.good()){
        file.read((char*)&b,sizeof(b));
        if(strcmp(ISBN1,b.ISBN)){
            temp.write((char*)&b,sizeof(b));
        }
    }
    file.close();
    temp.close();
    remove("file.txt");
    rename("temp.txt","file.txt");
}
void update(){
    fstream file;
    file.open("file.txt",ios::in);
    fstream temp;
    temp.open("temp.txt",ios::out);
    char ISBN1[6];
    cout<<"Enter ISBN:";
    cin>>ISBN1;
    book b,new_b;
    while(file.good()){
        file.read((char*)&b,sizeof(b));
        if(!strcmp(ISBN1,b.ISBN)){
            cin.ignore();
            cin>>new_b.ISBN>>new_b.title>>new_b.authorname>>new_b.price>>new_b.title>>new_b.pagesNum;
            temp.write((char*)&new_b,sizeof(new_b));
        }
        else{
            temp.write((char*)&b,sizeof(b));
        }
    }
    file.close();
    temp.close();
    remove("file.txt");
    rename("temp.txt","file.txt");
}
void printbook(){
    ifstream outfile("file.txt",ios::out);
    char title[30];
    cout<<"Enter title: ";
    cin>>title;
    book b;
    while(outfile.good()){
        outfile.read((char*)&b,sizeof(b));
        if(!strcmp(title,b.title)){
            cout<<b<<endl;
            break;
        }
    }
}
/*istream& operator>>(istream& in,book& b)
{
    cout << "\n Enter ISBN: "; in.getline(b.ISBN, 6);
    cout << "\n Enter Title: "; in.getline(b.title, 30);
    cout << "\n Enter Author Name: "; 	in.getline(b.authorname, 30);
    cout << "\n Enter Price: "; 	in.getline(b.price, 5);
    cout << "\n Enter Year: "; 	in.getline(b.year, 5);
    cout << "\n Enter Number Of Pages : ";	in.getline(b.pages, 5);

    return in;
}
ostream& operator<<(ostream& os,book& b)
{
    os<<b.ISBN<<b.title<<b.authorname<<b.price<<b.year<<b.pages<<endl;
    return os;
}


void addbook(fstream& out ,book& b)
{
    char buffer[50];
    strcpy(buffer, b.ISBN);
    strcat(buffer, b.title);
    strcat(buffer, b.authorname);
    strcat(buffer, b.price);
    strcat(buffer, b.year);
    strcat(buffer, b.pages);

    short length = strlen(buffer);
    for(int i = strlen(buffer) ; i < 50 ; i++){
        buffer[i] = ' ';
    }
    for(int i = 0 ; i < 50 ; i++){
        cout << buffer[i];
    }
    int rrn = search_fun();
    if(search_fun() == 0){
        out.seekp( 0 , ios::beg);
        out.write(buffer, 50);
    }
    else if(search_fun() == -1){
        out.seekp( (1 * 50) , ios::beg);
        out<< endl;
        out.write(buffer, 50);
    }
    else if(search_fun() == 1){
        out.seekp(0 , ios::end);
        out << endl;
        out.write(buffer, 50);

    }

    else{
        out.seekp( (rrn * 50) , ios::beg);
        out<< endl;
        out.write(buffer, 50);

    }
}

int search_fun()
{
    fstream search_file;
    int offset;
    string line;
    char* char_search = "*"; // test variable to char_search in file
    // open file to char_search
    search_file.open("file.txt");
    if(search_file.is_open())
    {
        int rrn = 0;
        int counter;
        while(!search_file.eof())
        {
            for(; getline(search_file, line); rrn++)
            {
                if (line.find(char_search) != string::npos)
                {
                    if(rrn == 1)
                        return -1;
                    else
                         return rrn;
                }

            }

        }
    }
    search_file.close();
}*/
