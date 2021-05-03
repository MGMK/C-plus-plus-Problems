// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohamed abdelhamid      20170241
//          mohamed hamdy mohamed   20170227
//          mohamed ali farouk      20170249
// Date:    13 Abril 2018
// Version: 2.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void loadImage (unsigned char image[SIZE][SIZE]);
void saveImage ();
int doSomethingForImage ();
void Filter_2();
void Filter_3();
void Filter_5();
void Filter_6();
void Filter_8();
void Filter_a();
void Filter_b();


int main()
{
    cout << "hello user , "<<endl;
    cout << "Please enter file name of the image to process: " <<endl;
    loadImage (image1) ;
    doSomethingForImage();
    return 0;
}

//_______________
void loadImage (unsigned char image[SIZE][SIZE])
{
    char imageFileName[100];

    // Get gray scale image file name
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_______________
void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}
void Filter_2()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image3[i][j]=255-image1[i][j];

        }
    }
}
void Filter_3()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image3[i][j]=(image1[i][j] + image2[i][j])/2;
        }
    }
}
void Filter_5()
{
    char z ;
    cout << "\n 1- To Rotate image 90 degree .\n 2- To Rotate image 180 degree .\n 3- To Rotate image 270 degree .";
    cout << "\n\n>>>";
    cin >> z ;
    if ( z == '1')
    {
        int z = 0 ;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3[j][SIZE - i]=image1[i][j];
            }
        }
    }
    else if ( z == '2')
    {
        int z = 0 ;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3[i][j]=image1[SIZE - z][SIZE - j];
            }
            z++;
        }
    }

    else if ( z == '3')
    {
        int z = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3[SIZE - j][i]=image1[i][j];
            }
        }

    }


}
void Filter_6()
{
    char z ;
    cout << "1- If you want Dark Image .\n2- If you want light Image .";
    cout <<"\n>>>";
    cin >> z;
    if ( z == '1')
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                image3[i][j] = image1[i][j] /2;
            }
        }
    }
    else if ( z == '2')
    {

        for ( int i = 0 ; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE ; j++)
            {
                if ((image1[i][j] + 50 ) <= 255)
                    image3[i][j] = image1[i][j] +(50);
            }

        }

    }

}

void Filter_8()
{
    char z ;
    cout << "1- if you want quarters one .\n2- if you want quarters two .\n3- if you want quarters three .\n4- if you want quarters four .";
    cin >> z ;
    if ( z == '1')
    {
        int rows = 0, cols = 0 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image3[i][j] =image1[rows][cols];
                image3[i+1][j] =image1[rows][cols];
                image3[i][j+1] =image1[rows][cols];
                image3[i+1][j+1] =image1[rows][cols];
                cols++;
            }
            rows++;
            cols=0;
        }
    }
    else if (z == '2')
    {
        int rows = 0, cols = SIZE/2 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image3[i][j] =image1[rows][cols];
                image3[i+1][j] =image1[rows][cols];
                image3[i][j+1] =image1[rows][cols];
                image3[i+1][j+1] =image1[rows][cols];
                cols++;
            }
            rows++;
            cols=SIZE/2;
        }
    }
    else if(z == '3')
    {
        int rows = SIZE/2, cols = 0 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image3[i][j] =image1[rows][cols];
                image3[i+1][j] =image1[rows][cols];
                image3[i][j+1] =image1[rows][cols];
                image3[i+1][j+1] =image1[rows][cols];
                cols++;
            }
            rows++;
            cols=0;
        }
    }
    else if (z == '4')
    {
        int rows = SIZE/2, cols = SIZE/2 ;
        for ( int i = 0 ; i <SIZE ; i+=2)
        {
            for ( int j = 0 ; j< SIZE ; j+=2)
            {
                image3[i][j] =image1[rows][cols];
                image3[i+1][j] =image1[rows][cols];
                image3[i][j+1] =image1[rows][cols];
                image3[i+1][j+1] =image1[rows][cols];
                cols++;
            }
            rows++;
            cols=SIZE/2;
        }
    }
}


void Filter_9()
{
    char z ;
    cout << "1- if you want 1/2 from original image .\n2- if you want 1/3 from original image .\n3- if you want 1/4 from original image .";
    cout <<"\n>>>";
    cin >> z;
    if ( z == '1')
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image3[i/2][j/2]=image1[i][j];
            }
        }
    }
    else if ( z == '2' )
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image3[i/3][j/3] = image1[i][j];
            }
        }
    }
    else if ( z == '3' )
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image3[i/4][j/4] = image1[i][j];
            }
        }
    }
}
void Filter_a()
{
    char z ;
    cout << "1- Repeat Upper 1/2 from image .\n2- Repeat lower 1/2 from image ."
         << "\n3- Repeat left 1/2 from image .\n4- Repeat Right 1/2 from image ."
         <<"\n>>>";
    cin >> z ;
    if ( z == '1')
    {
        for ( int i = 0 ; i < SIZE / 2 ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image3[i][j] = image1[i][j];
                image3[SIZE - i][j] = image1[i][j];
            }
        }
    }
    else if ( z == '2')
    {
        for ( int i = SIZE / 2 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < SIZE ; j++)
            {
                image3[i][j] = image1[i][j];
                image3[SIZE - i][j] = image1[i][j];
            }
        }
    }
    else if ( z == '3')
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = 0 ; j < (SIZE / 2)+1 ; j++)
            {
                image3[i][j] = image1[i][j];
                image3[i][SIZE - j] = image1[i][j];
            }
        }
    }
    else if ( z == '4')
    {
        for ( int i = 0 ; i < SIZE ; i++)
        {
            for ( int j = SIZE / 2 ; j < SIZE ; j++)
            {
                image3[i][j] = image1[i][j];
                image3[i][SIZE - j] = image1[i][j];
            }
        }
    }


}



void Filter_b()
{
    int z = 4;
    int numbers[z];
    cout <<  "Your Choice Please :";
    for ( int i = 0 ; i < z ; i++)
    {
        cin >> numbers[i];
    }


    for ( int i = 0 ; i < z ; i++)
    {
        if ( numbers[i] == 1)
        {
            int rows = 0, cols = 0 ;
            for ( int i = 0 ; i <SIZE ; i++)
            {
                for ( int j = 0 ; j< SIZE ; j++)
                {
                    image3[i][j] =image1[rows][cols];
                    image3[i+1][j] =image1[rows][cols];
                    image3[i][j+1] =image1[rows][cols];
                    image3[i+1][j+1] =image1[rows][cols];
                    cols++;
                }
                rows++;
                cols=0;
            }
        }
        else if (numbers[i] == 2)
        {
            int rows = 0, cols = SIZE/2 ;
            for ( int i = 0 ; i <SIZE ; i++)
            {
                for ( int j = SIZE/2 ; j< SIZE ; j++)
                {
                    image3[i][j] =image1[rows][cols];
                    image3[i+1][j] =image1[rows][cols];
                    image3[i][j+1] =image1[rows][cols];
                    image3[i+1][j+1] =image1[rows][cols];
                    cols++;
                }
                rows++;
                cols=SIZE/2;
            }
        }
        else if(numbers[i] == 3)
        {
            int rows = SIZE/2, cols = 0 ;
            for ( int i = SIZE/2; i <SIZE ; i++)
            {
                for ( int j = 0 ; j< SIZE ; j++)
                {
                    image3[i][j] =image1[rows][cols];
                    image3[i+1][j] =image1[rows][cols];
                    image3[i][j+1] =image1[rows][cols];
                    image3[i+1][j+1] =image1[rows][cols];
                    cols++;
                }
                rows++;
                cols=0;
            }
        }
        else if (numbers[i] == 4)
        {
            int rows = SIZE/2, cols = SIZE/2 ;
            for ( int i = SIZE/2 ; i <SIZE ; i++)
            {
                for ( int j = SIZE/2 ; j< SIZE ; j++)
                {
                    image3[i][j] =image1[rows][cols];
                    image3[i+1][j] =image1[rows][cols];
                    image3[i][j+1] =image1[rows][cols];
                    image3[i+1][j+1] =image1[rows][cols];
                    cols++;
                }
                rows++;
                cols=SIZE/2;
            }
        }

    }

}
//_______________
int doSomethingForImage()
{

    cout << "please select filter to apply : \n" ;
    cout << "\n 1- Black & White filter \n 2- Invert Filter \n 3- Merge Filter \n 4- Flip Image \n 5- Rotate Image \n 6- Darken and Lighten Image \n 7- Detect Image Edges \n 8- Enlarge Image \n 9- Shrink Image  \n a- filter a \n b- filter b \n c- filter c \n s- Save the image to a file \n 0- Exit \n ";
    string x ;
    cin >> x ;
    if (x=="1")
    {
        int sum = 0, avg;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                sum += image1[i][j];
            }
        }
        avg = sum/(SIZE*SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                if(image1[i][j] > avg)
                    image3[i][j] = 255;
                else
                    image3 [i][j] = 0;
            }
        }

        doSomethingForImage();
    }
    else if ( x == "2")
    {
        Filter_2();
        doSomethingForImage();
    }
    else if (x=="3")
    {
        cout<<"\n Please enter name of image file to merge with : " ;
        loadImage (image2) ;
        Filter_3();
        doSomethingForImage();
    }
    else if (x=="4")
    {
        cout << " press (h) to flip horizontally , (v) to flip vertically " ;
        string y = "";
        cin.ignore();
        cin >> y ;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image2[i][j]=image1[i][j];
            }
        }
        if (y=="v")
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j< SIZE; j++)
                {
                    if (i<SIZE/2)
                        image3[i][j]=image1[255-i][255-j] ;

                    else
                        image3[i][j]=image2[255-i][255-j];
                }
            }
        }
        else if (y=="h")
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j< SIZE; j++)
                {
                    if (j<SIZE/2)
                        image3[j][i]=image1[j][255-i] ;

                    else
                        image3[j][i]=image2[j][255-i];
                }
            }
        }
        doSomethingForImage();
    }
    else if (x=="5")
    {
        Filter_5();
        doSomethingForImage();

    }
    else if (x=="6")
    {
        Filter_6();
        doSomethingForImage();
    }
    else if (x=="7")
    {
        int sum = 0, avg;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                sum += image1[i][j];
            }
        }
        avg = sum/(SIZE*SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                if(image1[i][j] > avg)
                    image1[i][j] = 255;
                else
                    image1 [i][j] = 0;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                if (image1[i-1][j] != image1[i+1][j] || image1[i][j-1] != image1[i][j+1] )
                    image3[i][j]=0;
                else
                    image3[i][j]=255;

            }
        }
        doSomethingForImage();
    }
    else if (x=="8")
    {

        Filter_8();
        doSomethingForImage();
    }
    else if (x=="9")
    {

        Filter_9();
        doSomethingForImage();
    }
    else if (x=="a")
    {
        Filter_a();
        doSomethingForImage();
    }
    else if (x=="b")
    {
        Filter_b();
        doSomethingForImage();
    }
    else if (x=="c")
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3[i][j][0]=( image1[i-1][j-1][0]-image1[i-1][j][0]-image1[i-1][j+1][0]-image1[1][j-1][0]-image1[i][j][0]-image1[i][j+1][0]-image1[i+1][j-1][0]-image1[i+1][j][0]-image1[i+1][j+1][0])/ 9;
                    image3[i][j][0]=( image1[i-1][j-1][0]-image1[i-1][j][0]-image1[i-1][j+1][0]-image1[1][j-1][0]-image1[i][j][0]-image1[i][j+1][0]-image1[i+1][j-1][0]-image1[i+1][j][0]-image1[i+1][j+1][0])/ 9;

            }

        }
        for(int i=0 ; i < SIZE ; i++)
        {
            for(int j=0 ; j < SIZE ; j++)
            {
                image3[i][j][0] = 255 + image1[i][j][0];
                image3[i][j][1] = 255 + image1[i][j][1];
                image3[i][j][2] = 255 + image1[i][j][2];
            }
        }
//            for (int j = 0; j< SIZE; j++)
//            {
//                image3[i][j]=( image1[i-1][j-1]-image1[i-1][j]-image1[i-1][j+1]-image1[1][j-1]-image1[i][j]-image1[i][j+1]-image1[i+1][j-1]-image1[i+1][j]-image1[i+1][j+1])/ 9;
//            }
//            for (int i = 0; i < SIZE; i++)
//            {
//                for (int j = 0; j< SIZE; j++)
//                {
//                    image3[i][j]=255+image1[i][j];
//
//                }
//            }
    }
    doSomethingForImage();

}
else if (x=="s")
{
    saveImage();
    main();
}
else if (x=="0")
{
    return 0 ;
}
}
