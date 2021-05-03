<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#General">General C++ Problems</a>
      <ul>
        <li><a href="#problem_1">problem 1 solve Discrete Math Tool and store result in files</a></li>
      </ul>
      <ul>
        <li><a href="#problem_2">problem 2 GrayScale and RGB Images Filters</a></li>
      </ul>
      <ul>
        <li><a href="#problem_3">problem 3 Security Algorithms</a></li>
      </ul>
    </li>
    <li>
      <a href="#OOP">C++ OOP Problems</a>
      <ul>
        <li><a href="#problem_4">problem 4 Matrix Operations</a></li>
      </ul>
      <ul>
        <li><a href="#problem_5">problem 5 vending machine simulator</a></li>
      </ul>
      <ul>
        <li><a href="#problem_6">problem 6 BigDecmal Operations</a></li>
      </ul>
    </li>
  </ol>
  
</details>



<!-- General C++ Problems -->
## General
there is decription file for each problem, it explain details of each problem expain what problem should take as input and there is examples to test functions so check it before test code.

### problem_1
<h3>create files and solve Discrete Math Tool</h3>
problem Decription:
Discrete Math Tool The team will develop a tool for performing discrete math operations.  
Develop a program that takes allows the user to enter data sets and store each one in a separate file. A set is an unordered collection of objects. The objects in a set are called the elements, or members of the set. Here, a set consists of an arbitrary number of integer values. A number exists once in the set. The program allows the user to load two data sets of integers in order to perform discrete math operations on them. Program should do the task and return to the same menu again until the user selects exist. 

* 1-  Enter a new data set // Enter a set of integer values and file name to store them 
* 2-  Load two data sets   // Take two file names and load the data in sets A and B 
* 3-  Display data sets // Displays the current data sets A and B   
* E- End

<h4>Problem functions that implemented in the program:</h4>

* Union of A, B // Calculate and display the union
* Intersection of A, B // Calculate and display the intersection 
* A - B  // Calculate and display A – B (items in A not in B) 
* B - A  // Calculate and display B - A (items in B not in A)
* Cartesian product of A and B   
* Power set of A // Set of all subsets of A. A = {1,2,3},   // P(A) = {Faye,{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}  
* Check if A and B are disjoint  // No item is in A and B at the same time
* Check if A and B are equal   // A and B have exactly the same items 
* Check if a set is a proper subset of other  

<br>Problem Team Members :<br>
Mohamed Hamdy Mohamed - [@LinkedIn](https://www.linkedin.com/in/mohamed-hamdy-0155b2173/) - LinkedIn<br>
Mohamed Abd El Hamid - [@LinkedIn](https://www.linkedin.com/in/muhammed-abdelhamid-85a3811b2/) - LinkedIn<br>
Mohamed Ali Farouk - [@LinkedIn](https://www.linkedin.com/in/mohamed-ali-b42320185/) - LinkedIn

<hr>

### problem_2
<h3>GrayScale and RGB Images Filters</h3>
problem Decription:
In this program, you will develop an image processing tool that can apply different filters (changes) to a given gray (and colored) bit map image of size 256 x 256.

<h4>Filters Names that implemented in the program:</h4>
1-	Black and White Image.<br>
2-	Invert Image.<br>
3-	Merge Images.<br>
4-	Flip Image.<br>
5-	Rotate Image.<br>
6-	Darken and Lighten Image.<br>
7-	Detect Image Edges.<br>
8-	Enlarge Image.<br>
9-	Shrink Image.<br>


<br>Problem Team Members :<br>
Mohamed Hamdy Mohamed - [@LinkedIn](https://www.linkedin.com/in/mohamed-hamdy-0155b2173/) - LinkedIn<br>
Mohamed Abd El Hamid - [@LinkedIn](https://www.linkedin.com/in/muhammed-abdelhamid-85a3811b2/) - LinkedIn<br>
Mohamed Ali Farouk - [@LinkedIn](https://www.linkedin.com/in/mohamed-ali-b42320185/) - LinkedIn

<hr>

### problem_3
<h3>Security Algorithms</h3>
problem Decription:
In this program, you will develop an image processing tool that can apply different filters (changes) to a given gray (and colored) bit map image of size 256 x 256.

<h4>Security Ciphers Names that implemented in the program:</h4>
1-  Affine Cipher.<br>
2-	Caesar Cipher.<br>
3-	Atbash Cipher.<br>
4-	ROT13 Cipher.<br>
5-	Baconian Cipher.<br>
6-	Simple Substitution Cipher.<br>
7-	Polybius Square Cipher.<br>
8-	Morse Code.<br>
9-	XOR Cipher.<br>
10-	Rail-fence Cipher.<br>

<br>Problem Team Members :<br>
Mohamed Hamdy Mohamed - [@LinkedIn](https://www.linkedin.com/in/mohamed-hamdy-0155b2173/) - LinkedIn<br>
Mohamed Abd El Hamid - [@LinkedIn](https://www.linkedin.com/in/muhammed-abdelhamid-85a3811b2/) - LinkedIn<br>
Mohamed Ali Farouk - [@LinkedIn](https://www.linkedin.com/in/mohamed-ali-b42320185/) - LinkedIn

<hr>

### problem_4
<h3>Matrix Operations</h3>
problem Decription:
Using structures, 2-D arrays, functions and overloading, the team will develop a set of functions for matrix manipulation. A matrix is represented by the following structure:

<br>  

<h4>Problem Functions that implemented in the program:</h4>
1- matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions<br> 
2- matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions <br>
3- matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2 <br>
4- matrix operator+  (matrix mat1, int scalar);  // Add a scalar <br>
5- matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar<br> 
6- matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar<br>

7- matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return new matrix with the sum <br>
8- matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new matrix with difference <br>
9- matrix operator+= (matrix& mat, int scalar);   // change mat & return new  <br>
10- matrix operator-= (matrix& mat, int scalar);   // change mat & return new  <br>
11- void   operator++ (matrix& mat);    // Add 1 to each element ++mat <br>
12- void   operator-- (matrix& mat);     // Sub 1 from each element --mat <br>
13- istream& operator>> (istream& in, matrix& mat);  // Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123 and return istream to allow cascading input <br>


14- ostream& operator<< (ostream& out, matrix mat); // Print matrix  as follows (2 x 3)   4  6    8 and return ostream to cascade printing 9 12   123 <br>
15- bool   operator== (matrix mat1, matrix mat2); // True if identical <br>
16- bool   operator!= (matrix mat1, matrix mat2);  // True if not same <br>
17- bool   isSquare   (matrix mat);  // True if square matrix <br>
18- bool   isSymetric (matrix mat);  // True if square and symmetric<br> 
19- bool   isIdentity (matrix mat);  // True if square and identity  <br>
20- matrix transpose(matrix mat);    // Return new matrix with the transpose<br> 


### problem_5
<h3>vending machine simulator</h3>
problem Decription:
vending machine simulator for drinks and candy, which is the machine in which the money is placed, and one of the things that you sell is requested, then the required and the rest of the money is brought down to the buyer and it works as follows:
 
<br>  

<h4>Prgram Requirments that implemented in the program:</h4>
1- When you start the program, it starts with defualt values for the quality of sweets and drinks in it, as well as with automatic values ​​for the amount of money available in it in terms of categories of cash and currencies and their number.
<br> 
2- The machine carries 10 different types and of each type it carries ten units, and it has a specific unit price of 
 <br>
3-The machine has one type of user and they are the buyers
 <br>
4- The buyer places coins or banknotes in denominations of half a pound, one pound, five pounds, ten pounds, and twenty pounds.
<br>
5- Then the buyer presses the number of the type he wants, and if he has put in enough money, the machine will spend the required item for him and spend the rest of the amount paid to him in the largest available cash denomination. The rest of him has a half-pound coin.
<br> 
6- If the required type is present, it is disbursed and the rest of the money will be spent
<br>

7- If the required type is not available, the machine appears a message informing the user that the required type is not available and asking him to either choose another type or get the money back
<br>
8- If the buyer wants to cancel the transaction after entering the money, he enters the option 0 and the money is returned to him
<br>
9- If all types are finished and all the goods are consumed in the machine, it stops accepting money and choices from buyers
<br>

<hr>

### problem_6
<h3>BigDecmal Operations</h3>
problem Decription:
in this problem we will do some operations like sum and substraction and cin and count oprators overloading for the big decimal number  
<br>  

<h4>Problem Functions that implemented in program:</h4>
1- operator+ (BigDecimalInt another_BigDecimalInt) // make sum oprator for two bigdecimal numbers
<br> 
2- operator- (BigDecimalInt another_BigDecimalInt) // make sum oprator for two bigdecimal numbers 
 <br>
3-ostream&operator<<(ostream &out,BigDecimalInt another) // make print or cout oprator for result 
<br>

<br>Problem Team Members :<br>
Mohamed Hamdy Mohamed - [@LinkedIn](https://www.linkedin.com/in/mohamed-hamdy-0155b2173/) - LinkedIn<br>
Mohamed Abd El Hamid - [@LinkedIn](https://www.linkedin.com/in/muhammed-abdelhamid-85a3811b2/) - LinkedIn<br>
Mohamed Ali Farouk - [@LinkedIn](https://www.linkedin.com/in/mohamed-ali-b42320185/) - LinkedIn

<hr>
### problem_7
<h3>DNA_RNA_Protein program</h3>
problem Decription:
it's complete program that helps biologists manage and analyze their sequence data while storing it in a computer. The biological data can be divided into 3 types of sequences: DNA, RNA, and Protein. A DNA sequence can be of type (promoter, motif, tail, noncoding). Each DNA sequence consists of 2 strands, each strand is a string that is formed by the following 4 characters (nucleotides): A,C,G,T and each strand has its own direction (like 2-way street). ACAAGG, CGATACAG, TTACGCCAT, and GACCCCTA are examples of single DNA strands so we create this program to convert DNA sequence to RNA sequence which is then converted to a Protein sequence.
<br>  


<br>Problem Team Members :<br>
Mohamed Hamdy Mohamed - [@LinkedIn](https://www.linkedin.com/in/mohamed-hamdy-0155b2173/) - LinkedIn<br>
Mohamed Abd El Hamid - [@LinkedIn](https://www.linkedin.com/in/muhammed-abdelhamid-85a3811b2/) - LinkedIn<br>
Mohamed Ali Farouk - [@LinkedIn](https://www.linkedin.com/in/mohamed-ali-b42320185/) - LinkedIn

<hr>




 
