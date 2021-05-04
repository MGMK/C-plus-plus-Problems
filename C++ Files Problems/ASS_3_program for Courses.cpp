#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>

using namespace std;


class SimpleIndex
{
    int next, S_next, I_next;     /// next free slot in PrimaryIndexArray , SecondIndexArray , InvertedListIndexArray .
    int headerSize;
    struct course
    {
        char CourseID[6];
        char CourseName[21];
        char CourseInstructorName[21];
        char CourseWeeks[6];
    };
    struct IndexRecord
    {
        char PK[21];
        int offset;
    };

    struct InvertedList
    {
        int Offset_1;
        char I_PK[21];
        int Offset_2;
    };

    const static int indexSize = 100;
    IndexRecord PrimaryIndexArray[indexSize];
    IndexRecord SecondIndexArray[indexSize];
    InvertedList InvertedListIndexArray[indexSize];

    char dataFilePath[50] = "dataFile.txt";
    char indexFilePath[50] = "PrimaryIndexFile.txt";
    char SecondFilePath[50] = "SecondIndexFile.txt";
    char Invertedlistpath[50] = "InvertedListFile.txt";

public:
    SimpleIndex();
    void AddCourse();

/// //////////////////////////////////////////////////////////////////

    void PrintCourse_ID(char PK[]);
    void PrintCourse_Name(char PK[]);
    void printIndex();

/// //////////////////////////////////////////////////////////////////

    void DeleteCourse_ID(char PK[]);
    void DeleteCourse_Name(char PK[]);

/// //////////////////////////////////////////////////////////////////

    void UpdataCourse_ID();
    void UpdataCourse_Name();

    /// //////////////////////////////////////////////////////////////////

    int IndexBinarySearch(char key[]);
    int IndexBinarySearch_Name(char key[]);
    void PrimarySortIndex();
    void SecondSortIndex();

/// //////////////////////////////////////////////////////////////////

    void saveIndex();
    void loadIndex();
    void ReconstructIndex();
    void ChangeIndexState(bool state);
    bool getIndexState();
    bool exists(char name[20]);

};

SimpleIndex::SimpleIndex()
{
    next = 0;
    S_next = 0 ;
    headerSize = 1;
}

void SimpleIndex::AddCourse()
{
    ChangeIndexState(true);
    ofstream fout;
    fout.open(dataFilePath, ios::app | ios::out | ios::binary);

    course c;
    cout << "\nEnter ID: ";
    cin.getline(c.CourseID, 5);
    cout << "\nEnter Name: ";
    cin.getline(c.CourseName, 9);
    cout << "\nEnter I_Name: ";
    cin.getline(c.CourseInstructorName, 9);
    cout << "\nEnter Weeks: ";
    cin.getline(c.CourseWeeks, 3);

    char buffer[200];
    strcpy(buffer, c.CourseID);
    strcat(buffer, "|");
    strcat(buffer, c.CourseName);
    strcat(buffer, "|");
    strcat(buffer, c.CourseInstructorName);
    strcat(buffer, "|");
    strcat(buffer, c.CourseWeeks);
    strcat(buffer, "|");

    short len = strlen(buffer);

    fout.seekp(0, ios::end);
    int addess = fout.tellp();
    fout.write((char*)&len, sizeof(len));
    fout.write(buffer, len);
    fout << endl;
    IndexRecord temp;
    strcpy(temp.PK, c.CourseID);
    temp.offset = addess;
    PrimaryIndexArray[next] = temp;
    next++;
    int result_of_search = IndexBinarySearch_Name(c.CourseInstructorName);

    /// not in secondary index so add it in secondary & inverted index

    if(result_of_search == -1)
    {
        ///add to inverted list array
        InvertedListIndexArray[I_next].Offset_1 = I_next;
        strcpy(InvertedListIndexArray[I_next].I_PK, c.CourseID);
        InvertedListIndexArray[I_next].Offset_2 = -1;


        strcpy(SecondIndexArray[S_next].PK, c.CourseInstructorName);

        SecondIndexArray[S_next].offset = I_next;


        S_next++;
        I_next++;

    }
    else
        cout << "Test Test .\n";

    PrimarySortIndex();
    SecondSortIndex();

    fout.close();
}
/// ///////////////////////////////////////////////////////////////////

void SimpleIndex::PrintCourse_ID(char PK[])
{
    ifstream fin;
    fin.open(dataFilePath, ios::in);
    int address = IndexBinarySearch(PK);
    if (address == -1)
    {
        cout << "\nThis Course not exists.";
        return;
    }
    short len;
    course c;
    fin.seekg(PrimaryIndexArray[address].offset, ios::beg);
    fin.read((char*)&len, sizeof(len));

    char *buffer = new char[len];

    fin.read(buffer, len);
    istringstream stream(buffer);
    stream.getline(c.CourseID, 5, '|');
    stream.getline(c.CourseName, 20, '|');
    stream.getline(c.CourseInstructorName, 20, '|');
    stream.getline(c.CourseWeeks, 5, '|');

    cout << endl << " Course ID: " << c.CourseID << " Course Name: " << c.CourseName << " Course Instruct Name: " << c.CourseInstructorName;
    cout << " Course Weeks: " << c.CourseWeeks;
    fin.close();
    delete [] buffer;

}
void SimpleIndex::PrintCourse_Name(char PK[])
{
    int position= IndexBinarySearch_Name(PK);

    for(int i =position; i<I_next; i++)
    {
        if(InvertedListIndexArray[i].Offset_2 != -1)
        {
            PrintCourse_ID(InvertedListIndexArray[i].I_PK);
            i=InvertedListIndexArray[i].Offset_2;
            i--;
        }
        else
        {
            PrintCourse_ID(InvertedListIndexArray[i].I_PK);
            break;
        }
    }
}
void SimpleIndex::printIndex()
{
    ofstream fout(indexFilePath, ios::trunc);
    for (int i = 0; i<next; i++)
    {
        IndexRecord temp = PrimaryIndexArray[i];
        fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }

    ofstream S_fout(SecondFilePath, ios::trunc);
    for (int i = 0; i<S_next; i++)
    {
        IndexRecord temp = SecondIndexArray[i];
        S_fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }

    ofstream I_fout(Invertedlistpath, ios::trunc);
    for (int i = 0; i<I_next; i++)
    {
        InvertedList temp = InvertedListIndexArray[i];
        I_fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }
    fout.close();
    S_fout.close();
    I_fout.close();
}
/// ////////////////////////////////////////////////////////////////////////////////////////////

void SimpleIndex::DeleteCourse_ID(char PK[])
{
    ChangeIndexState(true);

    fstream fout(dataFilePath, ios::out | ios::in);
    fout.seekp(0, ios::end);
    int header = fout.tellp();

    int address = IndexBinarySearch(PK);
    if (address == -1)
    {
        cout << "\nCourse not found.";
        return;
    }

    fout.seekp(PrimaryIndexArray[address].offset + 2, ios::beg);
    fout << '*';

    //shift up to delete from index
    for (int i = address; i<next - 1; i++)
        PrimaryIndexArray[i] = PrimaryIndexArray[i + 1];

    next--;

    fout.close();

}

void SimpleIndex::DeleteCourse_Name(char PK[])
{
    ChangeIndexState(true);

    int address = IndexBinarySearch_Name(PK);
    SecondIndexArray[address].offset = -1;
    for(int i = address ; i<I_next; i++)
    {
        if(InvertedListIndexArray[i].Offset_2 != -1)
        {
            DeleteCourse_ID(InvertedListIndexArray[i].I_PK);
            InvertedListIndexArray[i].I_PK[0]='*';
            i = InvertedListIndexArray[i].Offset_2;
            i--;
        }
        else
        {
            DeleteCourse_ID(InvertedListIndexArray[i].I_PK);
            break;
        }
    }
}
/// //////////////////////////////////////////////////////////////////////////////

void SimpleIndex::UpdataCourse_ID()
{
    cout << "UpData By ID Function .\n";
    char PK[21];
    cout << "Enter ID :";
    cin.getline(PK, 20);
    AddCourse();
    DeleteCourse_ID(PK);
}
void SimpleIndex::UpdataCourse_Name()
{
    cout << "UpData By Name Function .\n";
    char PK[21];
    cout << "Enter Name :";
    cin.getline(PK, 20);
    AddCourse();
    DeleteCourse_Name(PK);
}

/// ////////////////////////////////////////////////////////////////////////////////

int SimpleIndex::IndexBinarySearch(char key[])
{

    int size = next;
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (strcmp(PrimaryIndexArray[middle].PK, key) == 0)
            return middle;
        else if (atoi(PrimaryIndexArray[middle].PK)<atoi(key))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

int SimpleIndex::IndexBinarySearch_Name(char key[])
{

    int size = S_next;
    int low = 0, high = size - 1;
    while (low <= high)
    {

        int middle = (low + high) / 2;
        if (strcmp(SecondIndexArray[middle].PK, key) == 0)
        {
            return middle;
        }
        else if (atoi(SecondIndexArray[middle].PK)<atoi(key))
        {
            low = middle + 1;
        }
        else
            high = middle - 1;

    }

    return -1;
}
/// ////////////////////////////////////////////////////////////////////////////////


void SimpleIndex::PrimarySortIndex()
{
    int len = next - 1;
    IndexRecord temp;
    for (int i = 0; i<len; i++)
        for (int j = 0; j<len - i; j++)
        {
            if (atoi(PrimaryIndexArray[j].PK)>atoi(PrimaryIndexArray[j + 1].PK))
            {
                temp = PrimaryIndexArray[j];
                PrimaryIndexArray[j] = PrimaryIndexArray[j + 1];
                PrimaryIndexArray[j + 1] = temp;
            }
        }
}
void SimpleIndex::SecondSortIndex()
{
    int len = S_next - 1;
    IndexRecord temp;
    for (int i = 0; i<len; i++)
        for (int j = 0; j<len - i; j++)
        {
            if (atoi(SecondIndexArray[j].PK)>atoi(SecondIndexArray[j + 1].PK))
            {
                temp = SecondIndexArray[j];
                SecondIndexArray[j] = SecondIndexArray[j + 1];
                SecondIndexArray[j + 1] = temp;
            }
        }
}
/// /////////////////////////////////////////////////////////////////////////////////

void SimpleIndex::saveIndex()
{
    ofstream fout(indexFilePath, ios::trunc);
    for (int i = 0; i<next; i++)
    {
        IndexRecord temp = PrimaryIndexArray[i];
        fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }

    ofstream S_fout(SecondFilePath, ios::trunc);
    for (int i = 0; i<S_next; i++)
    {
        IndexRecord temp = SecondIndexArray[i];
        S_fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }

    ofstream I_fout(Invertedlistpath, ios::trunc);
    for (int i = 0; i<I_next; i++)
    {
        InvertedList temp = InvertedListIndexArray[i];
        I_fout.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
    }
    fout.close();
    S_fout.close();
    I_fout.close();
    ChangeIndexState(false);
}


void SimpleIndex::loadIndex()
{
    if(!exists(dataFilePath))
    {
        next = 0;
        ofstream fout;
        fout.open(dataFilePath, ios::out);
        fout << 0;
        fout.close();
    }

    else if (!getIndexState())
    {
        ifstream fin(indexFilePath);
        next = 0;
        while(true)
        {
            IndexRecord temp;
            fin.read((char*)&temp, sizeof(temp));
            if (fin.eof())
                break;
            PrimaryIndexArray[next] = temp;
            next++;
        }
        fin.close();

        ifstream S_fin(SecondFilePath);
        S_next = 0;
        while(true)
        {
            IndexRecord temp;
            S_fin.read((char*)&temp, sizeof(temp));
            if (S_fin.eof())
                break;
            SecondIndexArray[S_next] = temp;
            S_next++;
        }
        S_fin.close();

        ifstream I_fin(Invertedlistpath);
        S_next = 0;
        while(true)
        {
            InvertedList temp;
            S_fin.read((char*)&temp, sizeof(temp));
            if (S_fin.eof())
                break;
            InvertedListIndexArray[I_next] = temp;
            I_next++;
        }
        I_fin.close();

    }
    else
        ReconstructIndex();
}


void SimpleIndex::ReconstructIndex()
{
    ifstream fin;
    fin.open("dataFile.txt", ios::in );
    next = 0;
    fin.seekg(headerSize, ios::beg); //skip header
    char *buffer;
    while (true)
    {
        IndexRecord temp;
        int offset = fin.tellg();
        short len;
        fin.read((char*)&len, sizeof(len));
        if (fin.eof())
            break;
        buffer = new char[len];
        fin.read(buffer, len);
        if (buffer[0] == '*')
            continue;
        istringstream strbuf(buffer);
        strbuf.getline(temp.PK, 5, '|');
        temp.offset = offset;
        PrimaryIndexArray[next] = temp;
        next++;
    }
    fin.close();
    delete []buffer;
    PrimarySortIndex();
}


void SimpleIndex::ChangeIndexState(bool state)
{
    fstream fout(dataFilePath, ios::out | ios::in);
    fout.seekp(0, ios::beg);
    fout << state;
    fout.close();
}


bool SimpleIndex::getIndexState()
{
    bool state;
    ifstream fout(dataFilePath);
    fout.seekg(0, ios::beg);
    fout >> state;
    fout.close();
    return state;
}

bool SimpleIndex::exists(char name[20] )
{
    ifstream f(name);
    if (f.fail())
    {
        return false;
    }
    else
    {
        f.close();
        return true;
    }
}
/// /////////////////////////////////////////////////////////////////////////////


int main()
{

    SimpleIndex i;
    // i.loadIndex();
    cout << "\n\n       **************************************** Add Course **************************************************\n";
    for (int n = 0; n < 5; n++)
        i.AddCourse();

    cout << "\n\n       **************************************** Print By ID **************************************************\n";
    for (int n = 0; n < 5; n++)
    {
        char PK[6];
        cout << "\nenter PK you want to display \n";
        cin.getline(PK,5);
        i.PrintCourse_ID(PK);
    }
    cout << "\n\n        **************************************** Print By Name **************************************************\n";
    for (int n = 0; n < 5; n++)
    {
        char PK[6];
        cout << "\nenter PK you want to display \n";
        cin.getline(PK,5);
        i.PrintCourse_Name(PK);
    }
    cout << "\n\n        **************************************** Delete By ID **************************************************\n";
    cout << "\nenter PK to delete  \n";
    char PK[6];
    cin.getline(PK,5);
    i.DeleteCourse_ID(PK);
    cout << "\n\n        **************************************** Delete By Name **************************************************\n";
    cout << "\nenter I_Name to delete  \n";
    char name[6];
    cin.getline(name,5);
    i.DeleteCourse_Name(name);
    cout << "\n\n        **************************************** UpData By ID **************************************************\n";
    i.UpdataCourse_ID();
    cout << "\n\n        **************************************** UpData By Name **************************************************\n";
    i.UpdataCourse_Name();

    cout << "\n\n        **************************************** Print By ID **************************************************\n";
    for (int n = 0; n < 3; n++)
    {
        char PK[6];
        cout << "\nenter PK you want to display \n";
        cin.getline(PK,5);
        i.PrintCourse_ID(PK);
    }
    cout << "\n\n        **************************************** Print By Name **************************************************\n";
    for (int n = 0; n < 3; n++)
    {
        char PK[6];
        cout << "\nenter PK you want to display \n";
        cin.getline(PK,5);
        i.PrintCourse_Name(PK);
    }
    i.printIndex();
    i.saveIndex();

}
