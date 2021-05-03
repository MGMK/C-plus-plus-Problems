#include <iostream>

using namespace std;

int main()
{
   cout<<"choose your encrypt/decrypt number "<<endl<<"0 to choose Affine cipher "<<endl<<"1 to choose Caesar cipher "<<endl;
   cout<<"2 to choose Atbash cipher "<<endl<<"3 to choose ROT13 cipher "<<endl<<"4 to choose baconian cipher "<<endl;
   cout<<"5 to choose simple substitution "<<endl<<"6 to choose polybius cipher "<<endl<<"7 to choose Morse code "<<endl;
   cout<<"8 to choose XOR cipher "<<endl<<"9 to choose Rail-fence cipher "<<endl;
   int x ;
   cin >> x;
   switch(x)
    {
    case 0:

        ///////////

        break;
    case 1:

        ///////////

        break;
    case 2:

        ////////////

        break;
    case 3:

        /////////////

        break;
    case 4:

        /////////////

        break;
    case 5:

        ////////////

        break;
    case 6:

        /////////////

        break;
    case 7:

        //////////////

        break;
    case 8:

        ///////////////


        break;
    case 9:

        //////////////


        break;
    default:

        cout<<"Invalid Input"<<endl;
        main();
    }


    return 0;
}
