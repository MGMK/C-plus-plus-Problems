// Purpose: create files and solve Discrete Math Tool .

#include <iostream>
#include<algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <errno.h>


using namespace std;

// Team functions
void new_data_set();
void load_data();
void display_data_sets();


// Team Pones Functions
void new_data_set_team_pones();
int load_data_team_pones_1();
void load_data_team_pones();
void display_data_sets_team_pones();
void files_team_pones(int arr3[],int &count1,int arr4[],int &count2,int arr5[],int &count3,int arraydata[],int &c);
int files_team_pones_1(int arr3[],int &count1,int arr4[],int &count2);


void dataunion();
void intersection();
void difference();

void dataunion_pones();
void intersection_pones();
void difference_pones();


void diffrance_function_2();
void cartesian_product_of_A_and_B();
void power_set_function();

void difference_between_three_sets_2();
void cartesian_product_of_A_and_B_and_c();
void power_set_function_between_three_sets();

void disjiont();
void Equality();
void subset();

void disjiont_pones();
void Equality_pones();
void subset_pones();



int main()
{
    cout << "Ahlan ya user ya habibi \nwhat do you like to do ?\n";
    cout <<"\n1- if you want Question code.\n2- if you want code pones.\n3- To End The All program.";

    while (true)
    {
        string code_pones ;
        cout <<endl<<endl<<"Enter your choise please :";
        cin >> code_pones;

        if ( code_pones == "1")
        {
            cout << "\nAhlan ya user ya habibi \nwhat do you like to do ?\n1- Enter a new data set \n2- Load two data sets \n3-Display data sets \n";
            cout << "4-Union Between Two Sets (A U B)  \n5-Intersection of_A and B Function. \n6- Diffrance Between To Sets (A - B)\n";
            cout << "7-Diffrance Between Two Sets (B - A)  \n8-Cartesian Of Two Sets (A x B) \n9- To find power of Set (A . A) \n";
            cout << "10-To Check The Sets Are Disjoint Or No.\n11- To Check The Sets Are Equal Or No. \n12- To Check The Sets Are Have Power supset Or No.\n13-To End";


            while (true)
            {

                string input ;
                cout << "\nEnter your code choise :";
                cin >> input;


                if ( input == "1")
                {
                    new_data_set_team_pones();
                    cin.clear();
                    new_data_set_team_pones();
                    cin.clear();
                }
                else if (input == "2")
                {
                    load_data_team_pones_1();
                    cout << "\nthe two data set are loaded";
                }
                else if (input == "3")
                {
                    display_data_sets_team_pones();
                    cin.clear();
                    display_data_sets_team_pones();
                    cin.clear();
                }

                else if (input == "4")
                {
                    dataunion();
                }
                else if ( input == "5")
                {
                    intersection();
                }
                else if ( input == "6")
                {
                    difference();
                }


                else if (input == "7")
                {
                    diffrance_function_2();
                }
                else if ( input == "8")
                {
                    cartesian_product_of_A_and_B();
                }
                else if ( input == "9")
                {
                    power_set_function();
                }
                else if ( input == "10")
                {
                    disjiont();
                }
                else if ( input == "11")
                {
                    Equality();
                }
                else if ( input == "12")
                {
                    subset();
                }
                else if ( input == "13")
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }


        else if ( code_pones == "2")
        {
            cout <<"1- if you want to create three sets . \n2- if you want to load data from three sets . ";
            cout << "\n3- if you want to display data from three sets .\n4- if you want data union between three sets (A U B U C).";
            cout << "\n5- if you want Intersection between three sets .\n6- if you want difference between three sets (A - B - C) . ";
            cout << "\n7- if you want difference between three sets (B - A - C) .\n8- if you want Cartesian product between three sets (A x B x C) .";
            cout << "\n9- if you want power between three sets (A . A . A) .\n10- To Check disjoint between three sets.";
            cout << "\n11- To Check Equal between three sets.\n12- To Check Subset between three sets.\n13- To End .";

            while ( true)
            {
                string input ;
                cout <<"\n\nEnter your pones choise :";
                cin >> input;
                if ( input == "1")
                {
                    cin.clear();
                    new_data_set_team_pones();
                    cout<<endl;
                    cin.clear();
                    new_data_set_team_pones();
                    cout<<endl;
                    cin.clear();
                    new_data_set_team_pones();
                    cout<<endl;
                    cin.clear();
                    cin.ignore();
                    main();
                }
                else if ( input == "2")
                {
                    cin.clear();
                    load_data_team_pones();
                    cin.clear();
                    cin.ignore();
                    cout<<endl;
                    cout <<"\nThe Data Of Three Sets are Loaded .\n\n";
                    main();
                }
                else if ( input == "3")
                {
                    cin.ignore();
                    cin.clear();
                    display_data_sets_team_pones();
                    cout<<endl;
                    cin.clear();
                    display_data_sets_team_pones();
                    cout<<endl;
                    cin.clear();
                    display_data_sets_team_pones();
                    cout<<endl;
                    cin.ignore();
                    cin.clear();
                    main();
                }
                else if ( input == "4")
                {
                    cin.clear();
                    dataunion_pones();
                    cin.clear();
                    cout<<endl;
                    cin.ignore();
                    main();
                }
                else if ( input == "5")
                {
                    cin.clear();
                    intersection_pones();
                    cin.clear();
                    cout<<endl;
                    cin.ignore();
                    main();

                }
                else if ( input == "6")
                {
                    cin.clear();
                    difference_pones();
                    cin.clear();
                    cout<<endl;
                    cin.ignore();
                    main();

                }
                else if ( input == "7")
                {
                    difference_between_three_sets_2();
                }

                else if ( input == "8")
                {
                    cartesian_product_of_A_and_B_and_c();
                }

                else if ( input == "9")
                {
                    power_set_function_between_three_sets();
                }
                else if ( input == "10")
                {
                    disjiont_pones();
                }
                else if ( input == "11")
                {
                    Equality_pones();
                }
                else if ( input == "12")
                {
                    subset_pones();
                }
                else if ( input == "13")
                {
                    break;
                }
                else
                {
                    continue;
                }

            }

        }
        else if ( code_pones == "3")
        {
            break;
        }
        else
        {
            continue;
        }
    }


    return 0;
}


void new_data_set_team_pones()
{
    char filename[50];
    cout << "\nEnter your name of file please for example (filename.txt) :";
    cin >> filename;
    ofstream myfile_1;
    cout <<"\nEnter element if data :";
    cout << "\npress (ctrl + z) to quit the program .\n";
    myfile_1.open(filename);
    int counter=0 ;
    int array_1[30] ;
    if ( myfile_1.is_open())
    {
        while (cin >> array_1[counter])
        {
            myfile_1 << array_1[counter] << "  ";
            ++counter;
        }
    }
    else
    {
        cout << strerror(errno) << endl;
    }

}
int load_data_team_pones_1()
{
    int counter1=0 ;
    int counter2=0 ;
    int counter3=0 ;
    int array3[30] ;
    int array4[30] ;
    int dataarray[60] ;
    files_team_pones_1(array3,counter1,array4,counter2);

    return 0;
}

void load_data_team_pones()
{
    int counter1=0 ;
    int counter2=0 ;
    int counter3=0 ;
    int counter4=0 ;
    int array3[30] ;
    int array4[30] ;
    int array5[30] ;
    int dataarray[60] ;
    files_team_pones(array3,counter1,array4,counter2,array5,counter3,dataarray,counter4);

}


void display_data_sets_team_pones()
{
    char filename_2[255] ;
    cout << "\nEnter name of the file : ";
    cin >> filename_2;
    ifstream myfile;
    myfile.open(filename_2);
    int counter = 0;
    int array1[30];
    if (myfile.is_open())
    {
        while (myfile >> array1[counter])
        {
            cout << array1[counter] << "  ";
            ++counter;
        }
    }
    else
        cout << strerror(errno) << endl;
}



///first function :-
int files_team_pones_1(int arr3[],int &count1,int arr4[],int &count2)
{
    count1=0;
    count2=0;

    cout <<"enter name of first file : "<<endl;
    char file_name3[255];
    cin.ignore();
    cin.getline(file_name3,255,'\n');
    ifstream file3(file_name3,ios::in);
    if (file3.is_open())
    {
        while (file3 >> arr3[count1])
        {
            count1++;
        }

    }

    else
    {
        cout << strerror(errno) << endl;
    }
    file3.close();
///second file :-
    cin.ignore();
    char file_name4[255];
    cout <<"enter name of second file : "<<endl;
    cin.getline(file_name4,255,'\n');

    ifstream file4(file_name4,ios::in);
    if (file4.is_open())
    {

        while (file4 >> arr4[count2])
        {
            count2++;
        }

    }

    else
    {
        cout << strerror(errno) << endl;
    }


    file4.close();
    return 0;
}



void files_team_pones(int arr3[],int &count1,int arr4[],int &count2,int arr5[],int &count3,int arraydata[],int &c)
{
    count1=0;
    count2=0;
    count3=0;
    c=0;

    cout <<"enter name of first file : "<<endl;
    char file_name3[255];
    cin.ignore();
    cin.getline(file_name3,255,'\n');
    ifstream file3(file_name3,ios::in);
    if (file3.is_open())
    {
        while (file3 >> arr3[count1])
        {
            count1++;
        }

    }

    else
    {
        cout << strerror(errno) << endl;
    }
    file3.close();
///second file :-
    cin.ignore();
    char file_name4[255];
    cout <<"enter name of second file : "<<endl;
    cin.getline(file_name4,255,'\n');

    ifstream file4(file_name4,ios::in);
    if (file4.is_open())
    {

        while (file4 >> arr4[count2])
        {
            count2++;
        }

    }

    else
    {
        cout << strerror(errno) << endl;
    }


    file4.close();

///file 3 :

    cin.ignore();
    cout <<"enter name of third file : "<<endl;
    char file_name5[255];

    cin.getline(file_name5,255,'\n');
    ifstream file5(file_name5,ios::in);
    if (file5.is_open())
    {
        while (file5 >> arr5[count3])
        {
            count3++;
        }

    }

    else
    {
        cout << strerror(errno) << endl;
    }
    file5.close();

/// load all arrays in one array


    for (c; c<count1; ++c)
    {
        arraydata[c]=arr3[c];
    }
    for (int i=0; i<count2; ++i)
    {
        arraydata[c++]=arr4[i];
    }
    for (int z=0; z<count3; ++z)
    {
        arraydata[c++]=arr5[z];
    }

}








///////// Start Abd El Hamed Functions
void dataunion()
{
    cout <<endl<< "Enter the name of the first file : ";
    char nof[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>nof[i];
        if (nof[i-1]=='x')
        {
            if (nof[i]=='t')
            {
                nof[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(nof,ios::in);
    if (file1.is_open())
    {
        int counter1=0, i=0;
        int array1[50] ;
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
        //*****************************************************************************************


        cout <<endl<< "Enter the name of the second file : ";
        char nof2[30];
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>nof2[i];
            if (nof2[i-1]=='x')
            {
                if (nof2[i]=='t')
                {
                    nof2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file2;
        file2.open(nof2,ios::in);
        if (file2.is_open())
        {
            int counter2=0, i=0;
            int array2[50] ;
            while (file2 >> array2[counter2])
            {
                ++counter2;
            }
            for (int i=0; i<counter2; ++i)cout<<array2[i]<<" ";
            for (int i=0; i<counter1; ++i)
            {
                for (int z=0; z<counter1; ++z)
                {
                    if (array1[i]!=array2[z])
                    {
                        if (z==counter1-1)cout<<array1[i]<<" ";
                    }
                    else break;

                }
            }
            file2.close();
        }

        else
        {
            cout << strerror(errno) << endl;
        }

    }
}


void intersection()
{
    cout <<endl<< "Enter the name of the first file : ";
    char nof[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>nof[i];
        if (nof[i-1]=='x')
        {
            if (nof[i]=='t')
            {
                nof[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(nof,ios::in);
    if (file1.is_open())
    {
        int counter1=0, i=0;
        int array1[50] ;
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
        //*****************************************************************************************


        cout <<endl<< "Enter the name of the second file : ";
        char nof2[30];
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>nof2[i];
            if (nof2[i-1]=='x')
            {
                if (nof2[i]=='t')
                {
                    nof2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file2;
        file2.open(nof2,ios::in);
        if (file2.is_open())
        {
            int counter2=0, i=0;
            int array2[50] ;
            while (file2 >> array2[counter2])
            {
                ++counter2;
            }
            for (int i=0; i<counter1; ++i)
            {
                for (int z=0; z<counter1; ++z)
                {
                    if (array1[i]==array2[z])
                    {
                        cout<<array1[i]<<" ";
                    }

                }
            }
            file2.close();
        }

        else
        {
            cout << strerror(errno) << endl;
        }

    }
}


void difference()
{
    cout <<endl<< "Enter the name of the first file : ";
    char nof[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>nof[i];
        if (nof[i-1]=='x')
        {
            if (nof[i]=='t')
            {
                nof[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(nof,ios::in);
    if (file1.is_open())
    {
        int counter1=0, i=0;
        int array1[50] ;
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
        //*****************************************************************************************


        cout <<endl<< "Enter the name of the second file : ";
        char nof2[30];
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>nof2[i];
            if (nof2[i-1]=='x')
            {
                if (nof2[i]=='t')
                {
                    nof2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file2;
        file2.open(nof2,ios::in);
        int counter2=0;
        int array2[50] ;
        while (file2 >> array2[counter2])
        {
            ++counter2;
        }

        for (int i=0; i<counter1; ++i)
        {
            for (int z=0; z<counter2; ++z)
            {
                if (array1[i] != array2[z])
                {
                    if (z==counter2-1)cout<<array1[i]<<" ";
                }
                if (array1[i] == array2[z])
                {
                    break;
                }
            }
        }
        file2.close();
    }

    else
    {
        cout << strerror(errno) << endl;
    }

}

//  function pones 1 from abd el hamed
///data union fn :-

void dataunion_pones()
{
    int counter1=0 ;
    int counter2=0 ;
    int counter3=0;
    int counter4=0;

    int array3[30] ;
    int array4[30] ;
    int array5[30] ;
    int dataarray[60];

    files_team_pones(array3,counter1,array4,counter2,array5,counter3,dataarray,counter4);
    cout<<endl;

    for (int i=0; i<counter4 ; ++i)
    {
        for (int z=i+1 ; z<counter4; ++z)
            if (dataarray[i]==dataarray[z])
            {
                dataarray[z]=777;
            }
    }
    for (int i=0; i<counter4 ; ++i)
    {
        if (dataarray[i]!=777)
            cout<<dataarray[i]<<" ";
    }

}
/// for loop to print the union of the two arrays


//  function pones 2 from abd el hamed
/// intersection fn :-

void intersection_pones()
{

    int counter1=0 ;
    int counter2=0 ;
    int counter3=0;
    int counter4=0;

    int array3[30] ;
    int array4[30] ;
    int array5[30] ;
    int dataarray[60];

    files_team_pones(array3,counter1,array4,counter2,array5,counter3,dataarray,counter4);
    cout<<endl;

    for (int i=0; i<counter4 ; ++i)
    {
        int x=0;
        for (int z=i+1 ; z<counter4; ++z)
        {
            if (dataarray[i]==dataarray[z])
            {
                x++;
                if (x == 2)
                {
                    cout<<dataarray[i]<<" " ;
                }
            }
        }
    }
}

//  function pones 3 from abd el hamed
///difference fn :-

void difference_pones()
{

    int counter1=0 ;
    int counter2=0 ;
    int counter3=0;
    int counter4=0;

    int array3[30] ;
    int array4[30] ;
    int array5[30] ;
    int dataarray[60];

    files_team_pones(array3,counter1,array4,counter2,array5,counter3,dataarray,counter4);
    cout<<endl;

    for (int i=0; i<counter1 ; ++i)
    {
        int x=0;
        for (int z=i+1 ; z<counter4; ++z)
        {
            if (dataarray[i]==dataarray[z])
            {
                x++;

            }
            else if (z==counter4-1 && x==0)
                cout<<dataarray[i]<<" " ;
        }


    }
}




///////// Start Mohamed Hamdy Functions
void diffrance_function_2()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >> filename;
    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the second file : ";
        cin >> filename_2;
        ifstream file_2;
        file_2.open(filename_2);
        if (file_2.is_open())
        {
            int counter2=0, i=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            for ( int i = 0 ; i < counter2 ; ++i)
            {
                for ( int j = 0 ; j <  counter1 ; ++j)
                {

                    if (array_2[i] == array_1[j]   )
                    {
                        break;
                    }
                    if ( array_2[i] != array_1[j])
                    {
                        if ( j == (counter1-1))
                        {
                            cout << array_2[i] <<"  ";

                            break;
                        }

                    }


                }



            }
        }

    }
}
void cartesian_product_of_A_and_B()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >> filename;
    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the second file : ";
        cin >> filename_2;
        ifstream file_2;
        file_2.open(filename_2);
        if (file_2.is_open())
        {
            int counter2=0, i=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            cout << "{"<<endl<<endl;
            for(int j = 0 ; j < counter1 ; j++)
            {
                for ( int k = 0 ; k < counter2 ; k++)
                {
                    cout <<"{" << array_1[j] <<" , " << array_2[k] << "} ";
                    if ( k < counter2-1)
                        cout << " , ";
                }
                cout << endl;
            }
            cout <<endl << "}";

        }
    }
}
void power_set_function()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >> filename;
    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }


        cout << "{"<<endl;
        cout << "  ";
        cout << "{}" <<" ";
        for ( int j = 0 ; j < counter1; j++)
        {
            cout <<"{"<< array_1[j]<<"}"<<" ";         ////////// to print element of set {1} , {2} , {3}
        }

        if ( counter1 == 0 )              ////////////////// Case one
        {
            cout << endl << "}";
        }

        if (counter1 > 0   )            ////////////////////// Case two
        {

            for ( int i = 0 ; i < counter1; i++) // A. A = {1,2,3},    P(A) = {?,{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}
            {

                for ( int k = i+1; k < counter1; k++)
                {
                    cout <<"{"<<array_1[i]<<" , " << array_1[k]<<"}" <<" "; ///////////////// To print element  {1,2},{1,3},{2,3}
                }
            }
            cout << endl;

            /////////////////////////////////////////////////////////////////////// {1 , 2 , 3} {1 , 2 , 4} {1 , 2 , 5}
            for ( int k = 0 ; k < counter1 ; k++)
            {
                for (int l = k+1 ; l < counter1; l++)
                {
                    for ( int d = l+1 ; d < counter1 ; d++)
                    {
                        cout << "{" << array_1[k] << " , "<< array_1[l] << " , " << array_1[d]<<"}"<<" ";
                    }
                    cout <<endl;
                }
            }
            cout << "{" ;

            for (int j = 0 ; j < counter1; j++)
            {
                if (counter1 > 3 )     /////////// because when size == 3 it will repeat {1,2,3}
                {
                    cout <<array_1[j] ;
                    if ( j < counter1-1)      // for {1,2,3} and  don,t print { 1, 2 ,3 (,)}
                        cout << " , ";
                }
            }

            if ( counter1 > 3 )    //// it will print thing not it not have mean so i do this condition and it work if size of set > 3 only
            {
                cout << "}";
                cout <<"\n}";

            }

        }

    }
}

/////////////////////////////// mohamed hamdy pones

////// Mohamed Hamdy Function pones 1
void difference_between_three_sets_2()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >>filename;

    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the first file : ";
        cin >>filename_2;

        ifstream file_2;
        file_2.open(filename_2);
        if (file_2.is_open())
        {
            int counter2=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            char filename_3[30];
            cout <<endl<< "Enter the name of the first file : ";
            cin >>filename_3;

            ifstream file_3;
            file_3.open(filename_3);
            if (file_3.is_open())
            {
                int counter3=0;
                int array_3[40] ;
                while (file_3 >> array_3[counter3])
                {
                    ++counter3;
                }
                sort ( array_1,array_1+counter1);
                sort ( array_2,array_2+counter2);
                sort ( array_3,array_3+counter3);

                ///////////////////////////////////////////////////////////
                for ( int i = 0 ; i < counter2 ; i++)
                {
                    for ( int j = 0 ; j < counter1 ; j++)
                    {
                        for ( int k = 0 ; k < counter3 ; k++)
                        {
                            if ( array_2[i] != array_1[k])
                            {
                                if ( array_2[i] != array_3[i] )
                                    cout << array_2[i] <<"  ";
                                else
                                    break;
                            }
                            else
                                break;
                            break;
                        }
                        break;
                    }
                }

            }

        }
    }
}
////// Mohamed Hamdy Function pones 2
void cartesian_product_of_A_and_B_and_c()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >>filename;

    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the first file : ";
        cin >>filename_2;

        ifstream file_2;
        file_2.open(filename_2);
        if (file_2.is_open())
        {
            int counter2=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            char filename_3[30];
            cout <<endl<< "Enter the name of the first file : ";
            cin >>filename_3;

            ifstream file_3;
            file_3.open(filename_3);
            if (file_3.is_open())
            {
                int counter3=0;
                int array_3[40] ;
                while (file_3 >> array_3[counter3])
                {
                    ++counter3;
                }


                cout <<"{"<<endl;
                for  ( int i = 0 ; i < counter1 ; i++)   // to  find { 1 , 2 , 3}
                {
                    for ( int j = 0 ; j < counter2 ; j++)
                    {
                        for ( int k = 0 ; k < counter3 ; k++)
                        {
                            cout <<"{"<<array_1[i] << " , "<<array_2[j] << " , "<< array_3[k]<<"}";
                        }
                        cout << endl;
                    }
                }
                cout << endl << "}";
            }
        }
    }
}
////// Mohamed Hamdy Function pones 3
void power_set_function_between_three_sets()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin >>filename;

    ifstream file_1;
    file_1.open(filename);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }


        cout <<"{"<<endl << "{}" <<" ";

        ////////////////////////////////// To print element  {1},{2},{3}
        for ( int d = 0 ; d < counter1 ; d++)
        {
            cout << "{"<<array_1[d] <<"}"<< " ";
        }
        cout <<endl;


        /////////////////////////////// {1 , 2 , 3} {1 , 2 , 4} {1 , 2 , 5}
        for  ( int i = 0 ; i < counter1 ; i++)
        {
            for ( int j = 0 ; j < counter1 ; j++)
            {
                for ( int k = 0 ; k < counter1 ; k++)
                {
                    cout <<"{"<<array_1[i] << " , "<<array_1[j] << " , "<< array_1[k]<<"}" << " ";
                }
                cout << endl;
            }
        }
        cout << "{";
        for ( int i = 0 ; i < counter1 ; i++)   // {1 , 2 , 3 , 4 , 5}
        {
            cout <<array_1[i]<<" ";
        }
        cout <<"}";
        cout << endl << "}";
    }

}
////////////////////////MOhamed ALI function

void disjiont()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>filename[i];
        if (filename[i-1]=='x'  || filename[i] == 's')
        {
            if (filename[i]=='t' || filename[i] == 'v')
            {
                filename[i+1]=NULL;
                break;
            }
        }
    }

    fstream file_1;
    file_1.open(filename,ios::in);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the second file : ";
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>filename_2[i];
            if (filename_2[i-1]=='x' || filename_2[i] == 's')
            {
                if (filename_2[i]=='t' || filename_2[i] == 'v')
                {
                    filename_2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file_2;
        file_2.open(filename_2,ios::in);
        if (file_2.is_open())
        {
            int counter2=0, i=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            sort(array_1,array_1+counter1);
            sort(array_2,array_2+counter2);

            string x ;
            for (int i = 0; i < counter1; i++)
            {
                for(int j = i; j < counter2; j++)
                {
                    if (array_1[i] != array_2[j])
                    {
                        x = "sets are disjoint .";
                        if ( i == counter1 && j == counter2)
                            cout<<endl << x << endl;
                    }
                    else
                        x = "sets are not disjoint";
                    cout << endl << x << endl;
                    i = counter1 ;
                    break;
                }

            }
        }
    }
}

void Equality()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>filename[i];
        if (filename[i-1]=='x'  || filename[i] == 's')
        {
            if (filename[i]=='t' || filename[i] == 'v')
            {
                filename[i+1]=NULL;
                break;
            }
        }
    }

    fstream file_1;
    file_1.open(filename,ios::in);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the second file : ";
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>filename_2[i];
            if (filename_2[i-1]=='x' || filename_2[i] == 's')
            {
                if (filename_2[i]=='t' || filename_2[i] == 'v')
                {
                    filename_2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file_2;
        file_2.open(filename_2,ios::in);
        if (file_2.is_open())
        {
            int counter2=0, i=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            sort(array_1,array_1+counter1);
            sort(array_2,array_2+counter2);



////////////////////////////////////////////////////////////////////////////
            string test ;
            if(counter1==counter2)
            {
                for (int i = 0; i < counter1; i++)
                {
                    for ( int j = i ; j < counter2 ; j++)
                    {
                        test = "sets are equal . ";
                        if (array_1[i] == array_2[i])
                        {
                            if (i == counter1-1 && j == counter2-1)
                                cout << endl << test << endl;
                            break;
                        }

                        else
                        {
                            test = "sets are not equel .";
                            cout << endl << test <<endl;
                            i = counter1;
                            break;
                        }
                    }
                }

            }
            else
            {
                cout << "\nnot equal length";
                cout << " so sets are not equal .\n";
            }
        }
    }
}

void subset()
{
    char filename[30];
    cout <<endl<< "Enter the name of the first file : ";
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>filename[i];
        if (filename[i-1]=='x'  || filename[i] == 's')
        {
            if (filename[i]=='t' || filename[i] == 'v')
            {
                filename[i+1]=NULL;
                break;
            }
        }
    }

    fstream file_1;
    file_1.open(filename,ios::in);
    if (file_1.is_open())
    {
        int counter1=0;
        int array_1[40] ;
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
        char filename_2[30];
        cout <<endl<< "Enter the name of the second file : ";
        cin.ignore();
        for (int i=0; i<30; ++i)
        {
            cin>>filename_2[i];
            if (filename_2[i-1]=='x' || filename_2[i] == 's')
            {
                if (filename_2[i]=='t' || filename_2[i] == 'v')
                {
                    filename_2[i+1]=NULL;
                    break;
                }
            }
        }

        fstream file_2;
        file_2.open(filename_2,ios::in);
        if (file_2.is_open())
        {
            int counter2=0, i=0;
            int array_2[40] ;
            while (file_2 >> array_2[counter2])
            {
                ++counter2;
            }

            sort(array_1,array_1+counter1);
            sort(array_2,array_2+counter2);


////////////////////////////////////////////////////////////////////////////

            if(counter1 == counter2)
            {
                cout<<"\n sets have the same size\n";
            }
            else if(counter1 < counter2)
            {
                int c=0;
                for (int i = 0; i < counter1; i++)
                {
                    for(int j=0; j<counter2; j++)
                    {
                        if(array_1[i]==array_2[j])
                        {
                            c++;
                            break;
                        }
                        if(c == counter1)
                        {
                            cout<<"\n set1 is a proper subset of set2\n";
                        }
                    }

                }
                if(c != counter1)
                {
                    cout<<"\n set1 is not a proper subset of set2\n";
                }
            }
            else if(counter1 > counter2)
            {
                int c=0;
                for (int j = 0; j < counter2; j++)
                {
                    for(int i=0; i<counter1; i++)
                    {
                        if(array_2[j]==array_1[i])
                        {
                            c++;
                            break;
                        }
                    }
                    if(c == counter2)
                    {
                        cout<<"\n set2 is a proper subset of set1\n";
                    }
                }
                if(c != counter2)
                {
                    cout<<"\n set2 is not a proper subset of set1\n";
                }
            }
        }
    }
}



/////////////////////////////////////////// pones function

void disjiont_pones()
{
    cout <<endl<< "Enter the name of the first file : ";
    char arr_1[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_1[i];
        if (arr_1[i-1]=='x')
        {
            if (arr_1[i]=='t')
            {
                arr_1[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(arr_1,ios::in);
    int array1[50] ;
    int counter1=0;
    if (file1.is_open())
    {
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
    }
    //*****************************************************************************************


    cout <<endl<< "Enter the name of the second file : ";
    char arr_2[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_2[i];
        if (arr_2[i-1]=='x')
        {
            if (arr_2[i]=='t')
            {
                arr_2[i+1]=NULL;
                break;
            }
        }
    }

    fstream file2;
    file2.open(arr_2,ios::in);
    int counter2=0;
    int array2[50] ;
    while (file2 >> array2[counter2])
    {
        ++counter2;
    }

    cout <<endl<< "Enter the name of the Third file : ";
    char arr_3[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_3[i];
        if (arr_3[i-1]=='x')
        {
            if (arr_3[i]=='t')
            {
                arr_3[i+1]=NULL;
                break;
            }
        }
    }

    fstream file3;
    file3.open(arr_3,ios::in);
    int counter3=0;
    int array3[50] ;
    while (file3 >> array3[counter3])
    {
        ++counter3;
    }
    sort(array1,array1+counter1);
    sort(array2,array2+counter2);
    sort(array3,array3+counter3) ;
    int check = 0;

    for (int i = 0; i < counter1; i++)
    {
        for(int j = 0; j < counter2; j++)
        {
            for(int k=0; k<counter3; k++)
            {
                if (arr_1[i] == arr_2[j] && arr_1[i] == arr_3[k] && arr_2[j] == arr_3[k])
                {
                    if (i==counter1-1){
                    cout << "\n set1 , set2 and set3 are joint\n";
                    check = 1 ;
                }
                }else {
                    cout<<"\n set1 , set2 and set3 are disjoint\n";
                     check = 1 ;
                }

                if (check == 1) break ;
            }
            if (check == 1) break ;
        }
        if (check == 1) break ;
    }

}
//  function pones 3 from moahmed ali
void Equality_pones()
{

    cout <<endl<< "Enter the name of the first file : ";
    char arr_1[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_1[i];
        if (arr_1[i-1]=='x')
        {
            if (arr_1[i]=='t')
            {
                arr_1[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(arr_1,ios::in);
    int counter1=0;
    int array1[50] ;
    if (file1.is_open())
    {
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
    }
    //*****************************************************************************************


    cout <<endl<< "Enter the name of the second file : ";
    char arr_2[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_2[i];
        if (arr_2[i-1]=='x')
        {
            if (arr_2[i]=='t')
            {
                arr_2[i+1]=NULL;
                break;
            }
        }
    }

    fstream file2;
    file2.open(arr_2,ios::in);
    int counter2=0;
    int array2[50] ;
    while (file2 >> array2[counter2])
    {
        ++counter2;
    }
    cout <<endl<< "Enter the name of the Third file : ";
    char arr_3[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_3[i];
        if (arr_3[i-1]=='x')
        {
            if (arr_3[i]=='t')
            {
                arr_3[i+1]=NULL;
                break;
            }
        }
    }

    fstream file3;
    file3.open(arr_3,ios::in);
    int counter3=0;
    int array3[50] ;
    while (file3 >> array3[counter3])
    {
        ++counter3;
    }
    sort(array1,array1+counter1);
    sort(array2,array2+counter2);
    sort(array3,array3+counter3);

    if (counter1 == counter2 && counter1 == counter3 && counter2 == counter3)
    {
        for (int i = 0; i < counter1; i++)
        {
            if (array1[i] != array2[i] && array1[i] != array3[i])
            {
                cout << "\n set1 , set2 and set3 are not equal\n";
                break;
            }
        }
        cout<<"\n set1 , set2 and set3 are equal\n";
    }
    else
        cout<<"\n sets has not equal size"<<endl;

}

//  function pones 3 from mohamed ali
void subset_pones()
{

    cout <<endl<< "Enter the name of the first file : ";
    char arr_1[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_1[i];
        if (arr_1[i-1]=='x')
        {
            if (arr_1[i]=='t')
            {
                arr_1[i+1]=NULL;
                break;
            }
        }
    }
    fstream file1;
    file1.open(arr_1,ios::in);
    int counter1=0;
    int array1[50] ;
    if (file1.is_open())
    {
        while (file1 >> array1[counter1])
        {
            ++counter1;
        }
    }
    //*****************************************************************************************


    cout <<endl<< "Enter the name of the second file : ";
    char arr_2[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_2[i];
        if (arr_2[i-1]=='x')
        {
            if (arr_2[i]=='t')
            {
                arr_2[i+1]=NULL;
                break;
            }
        }
    }

    fstream file2;
    file2.open(arr_2,ios::in);
    int counter2=0;
    int array2[50] ;
    while (file2 >> array2[counter2])
    {
        ++counter2;
    }

    cout <<endl<< "Enter the name of the Third file : ";
    char arr_3[30];
    cin.ignore();
    for (int i=0; i<30; ++i)
    {
        cin>>arr_3[i];
        if (arr_3[i-1]=='x')
        {
            if (arr_3[i]=='t')
            {
                arr_3[i+1]=NULL;
                break;
            }
        }
    }
    fstream file3;
    file3.open(arr_3,ios::in);
    int counter3=0;
    int array3[50] ;
    while (file3 >> array3[counter3])
    {
        ++counter3;
    }
    sort(array1,array1+counter1);
    sort(array2,array2+counter2);
    sort(array3,array3+counter3);

    if (counter1 == counter2 && counter1 == counter3 && counter2 == counter3)
    {
        cout<<"\n sets have the same size\n";
    }
    else
    {
        if(counter1 < counter2)
        {
            int c=0;
            for (int j = 0; j < counter2; j++)
            {
                for(int i=0; i<counter1; i++)
                {
                    if(array1[i]==array2[j])
                    {
                        c++;
                    }
                }
            }
            if(c==counter1)
            {
                cout<<"\n set1 is a proper subset of set2\n";
            }
            else
            {
                cout<<"\n set1 is not a proper subset of set2\n";
            }
            if(counter1 > counter2)
            {
                int c=0;
                for (int j = 0; j < counter2; j++)
                {
                    for(int i=0; i<counter1; i++)
                    {
                        if(array1[i]==array2[j])
                        {
                            c++;
                        }
                    }
                }
                if(c==counter2)
                {
                    cout<<"\n set2 is a proper subset of set1\n";
                }
                else
                {
                    cout<<"\n set2 is not a proper subset of set1\n";
                }
            }
            if(counter1 < counter3)
            {
                int c=0;
                for (int i = 0; i < counter1; i++)
                {
                    for(int j = 0; j < counter3; j++)
                    {
                        if (array1[i] == array3[j])
                        {
                            c++;
                        }
                    }
                }
                if(c==counter1)
                {
                    cout<<"\n set1 is a proper subset of set3\n";
                }
                else
                {
                    cout<<"\n set1 is not a proper subset of set3\n";
                }
            }
            if(counter1>counter3)
            {
                int c=0;
                for (int j = 0; j < counter3; j++)
                {
                    for(int i=0; i<counter1; i++)
                    {
                        if(array3[j]==array1[i])
                        {
                            c++;
                        }
                    }
                }
                if(c==counter3)
                {
                    cout<<"\n set3 is a proper subset of set1\n";
                }
                else
                {
                    cout<<"\n set3 is not a proper subset of set1\n";
                }
            }
            if(counter2<counter3)
            {
                int c=0;
                for (int i = 0; i < counter2; i++)
                {
                    for(int j=0; j<counter3; j++)
                    {
                        if (array3[j]==array2[i])
                        {
                            c++;
                        }
                    }

                }
                if(c==counter2)
                {
                    cout<<"\n set2 is a proper subset of set3\n";
                }
                else
                {
                    cout<<"\n set2 is not a proper subset of set3\n";
                }
            }
            else if(counter2>counter3)
            {
                int c=0;
                for (int j = 0; j < counter3; j++)
                {
                    for(int i=0; i<counter2; i++)
                    {
                        if(array3[j]==array2[i])
                        {
                            c++;
                        }
                    }
                }
                if(c==counter3)
                {
                    cout<<"\n set3 is a proper subset of set2\n";
                }
                else
                {
                    cout<<"\n set3 is not a proper subset of set2\n";
                }
            }
        }
    }
}
