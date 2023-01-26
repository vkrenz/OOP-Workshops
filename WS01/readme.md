# Workshop #1: Modules   
 - (V1.1) DIY sort is changed to be sorted on stno (ascending) instead of GPA<br >
    > If you have already successfully submitted the DIY using GPA sort, you do not need to resubmit your work; the first submission is valid

In process of doing your first workshop, in the ***lab*** (part 1) you are to sub-divide a program into modules, compile each module separately and construct an executable from the results of each compilation. In ***DIY*** (part 2) you are to write a modular program based on your knowledge of ipc144 subject and what you learnt up to now in C++. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:
- organize source code into modules, using header and implementation files;
- compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- describe to your instructor what you have learned in completing this workshop.

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit you work up to 2 days after due date with 30% penalty for each day. After that the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.


# LAB (50%)
***50 top movies of all times "genre" search*** is a program that searches through 50 movies records that are saved in a file, based on the users inquiry on the genre of the movie.

For example if the user enters *Comedy*, the program lists all the movies with *Comedy* in their list of genres.

## LAB Execution example

```text
Welcome to 50 top movies of all times "genre" search.

Enter the movie genre to start the search: Anim<ENTER>
1- Finding Nemo [2003], G, duration: 100 minutes, Rating: 8.1/10
    (Animation, Adventure, Comedy)
Do another search? (Y)es: y<ENTER>

Enter the movie genre to start the search: Comedy<ENTER>
1- Life Is Beautiful [1997], PG, duration: 116 minutes, Rating: 8.6/10
    (Comedy, Drama, Romance)
2- The Intouchables [2011], 14A, duration: 112 minutes, Rating: 8.5/10
    (Biography, Comedy, Drama)
3- My Sassy Girl [2001], PG, duration: 137 minutes, Rating: 8/10
    (Comedy, Drama, Romance)
4- Back to the Future [1985], PG, duration: 116 minutes, Rating: 8.5/10
    (Adventure, Comedy, Sci-Fi)
5- Finding Nemo [2003], G, duration: 100 minutes, Rating: 8.1/10
    (Animation, Adventure, Comedy)
Do another search? (Y)es: n<ENTER>

Goodbye!
```


## Step 1: *Test the Program*

### On Visual Studio
- Open Visual studio 2019 and create an Empty C++ Windows Console Project:<br />
![Empty Project](images/emptyproj.png)
- In VS, (if not open already) open Solution Explorer (click on View/Solution Explorer) and then add w1p1.cpp file to your project:<br />
-Right click on **“Source Files”**<br />
-Select **“Add/Existing Item”**<br />
-Select **w1p1.cpp** from the file browser<br />
-Click on **“Ok”**
- Now you can run the program by selecting **“Debug/Start Without Debugging”** or pressing the **“Ctr-F5”** button. 
### On Linux, in your Matrix account
- Connect to Seneca with [Global Protect VPN](https://inside.senecacollege.ca/its/services/vpn/studentvpn.html)
- Upload **w1p1.cpp** and **movies.dat** to your matrix account (Ideally to a designated directory for your workshop solutions). Then, enter the following command to compile the source file and create an executable called ws:
```bash
g++ w1p1.cpp -Wall -std=c++11 -o ws<ENTER>

-Wall: display all warnings
-std=c++11: compile using C++11 standards
-o ws:  name the executable ws
```
- Type the following to run and test the execution:
```bash
ws<ENTER>
```
## Step 2: Create the Modules
### On Windows, using Visual Studio (VS)
In solution explorer, add three new modules to your project:
- 50Best; A module to hold the main() function and its relative functions. (see below)
- File; A module to hold the functions and global variables related to File processing.
- Movie; A module to hold movie functions and global variables which have no direct relation to the File analysis in the program.

The **50Best** module has an implementation (.cpp) file but no header file. The **File** and **Movie** modules have both implementation (.cpp) and header (.h) files:

- Add **File.h** and **Movie.h** to the “Header Files” directory (right click on “Header Files” and select “Add/New Item” and add a header file)<br />
Make sure you add the compilation safeguards and also have all the C++ code in **File** and **Movie** modules in a namespace called “sdds”.
> **Important**: Note that, you are not allowed to use the “using” statement in a header file.<br />
For example, in a header file you are not allowed to write:
```C++
using namespace std; // not allowed in a ".h" file
```
- **compilation safeguards** refer to a technique to guard against multiple inclusion of header files. It does so by applying macros that check against a defined name:
```C++
#ifndef NAMESPACE_HEADERFILENAME_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define NAMESPACE_HEADERFILENAME_H

// Your header file content goes here

#endif
```
If the name isn’t yet defined, the **#ifndef** will allow the code to proceed onward to then define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.<br />
Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).<br />
Additionally, here is an instructional video showing how the compiler works and why you need these safeguards in all of your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.<br />
[Compilation Safegards](https://www.youtube.com/watch?v=EGak2R7QdHo): https://www.youtube.com/watch?v=EGak2R7QdHo

-Add **50Best.cpp**, **File.cpp** and **Movie.cpp** to the “Source Files” directory (right click on “Source Files” and select “Add/New Item” and add a C++ file)<br />

**50Best.cpp** Module should have only these include and namespace statements: 
```C++
#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;
```
and contain only the following functions:  
```Text
flushkeys
yes
main
```
- Separate the rest of the functions in **w1p1.cpp** and copy them into FILE and Movie modules as described below. Copy the body of the functions into the cpp files and the prototype into the header files. Note that the global variables must be in the cpp files to be kept invisible to other modules, but the structure difinitions must be kept in the header file to be visible to all the other modules using it<br />  
### Movie module
Contains the ***Movie*** Structure, the ***movies*** global array of **Movies** and the following functions:
```Text
loadMovies;
hasGenre;
displayMovie;
displayMoviesWithGenre;
```
### File Module
Contains the ***fptr*** FILE pointer as global variable and following functions
```Text
openFile
closeFile
readTitle
readYear
readMovieRating
readDuration
readGenres
readConsumerRating
```
To test that you have done this correctly, you can compile each module separately, by right clicking on **50Best.cpp**, **File.cpp** and **Movie.cpp** separately and select compile from the menu. If the compilation is successful, most likely you have done it correctly.

The equivalent of this on matrix is to add -c to the compile command:
```Bash
g++ File.cpp –Wall -std=c++11 –c<ENTER>
```
This example will only compile File.cpp and will not create an executable.

Now remove w1p1.cpp from the project. You can do this by right clicking on the filename in solution explorer and selecting remove in the menu (make sure you do not delete this file but only remove it).
Compile and run the project (as you did before in Step 1) and make sure everything works.

On Linux, in your matrix account, upload the five files from earlier (**File.cpp, File.h, Movie.cpp, Movie.h** and **50Best.cpp**) and **movies.dat** to your matrix account and compile the source code using the following command.
```Bash
g++ File.cpp Movie.cpp 50Best.cpp -Wall -std=c++11 -o ws<ENTER>
```
Run the program like before with the **movies.dat** file and make sure that everything still works properly. 

## LAB Submission (part 1)

To test and demonstrate execution of your program use the same data as shown in the [LAB Execution example](#LAB-Execution-example) .

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

# DIY (50%)

Having the following:

- A comma-separated file of student records and their GPA (maximum of 100 records) with the following format:<br />

    Student Name, Student number, GPA

    Sample:
    ```text
    Abraham Simpson,324543,3.9
    Agnes Skinner,470546,4.0
    Akira Kurosawa,411928,2.1   
    Alice Glick,459608,3.3
    ```
- A header file containing a structure for the GPA record of a student under the name "GPA.h":

    ```c++
    /***********************************************************************
    // OOP244 Workshop 1 p2: GPA header file
    //
    // File  GPA.h
    // Version 1.0
    // Date  winter 2023
    // Author Fardad Soleimanloo
    //
    //
    // Revision History
    // -----------------------------------------------------------
    // Name            Date            Reason
    /////////////////////////////////////////////////////////////////
    ***********************************************************************/
    #ifndef SDDS_GPA_H
    #define SDDS_GPA_H

    struct GPA {
        char name[116];
        double gpa;
        int stno;
    };

    #endif // !SDDS_GPA_H
    ```

Write a command line program that receives an operation and a GPA value and performs the following queries on the records of the data file.

## command line format:
```text
? [operation][GPA Value]
``` 
Examples:
```text
? <3.6 [ENTER]  list all the GPA records less than 3.6 
? >3.9 [ENTER]  list all the GPA records more than 3.9
? ~3.0 [ENTER]  list all values close to 3.0 with 0.05 precision (between 2.95 and 3.05)
? !  End query
```

Your program should work under a function called gpaQuery.
### gpaQuery
```c++
bool gpaQuery(const char* filename);
```
This function returns false if the filename can not be opened for reading, otherwise, it will return true.

**gpaQuery** runs as follows:

### Data entry:
```text
@2.2
~3.7
~3.8
<2.0
>3.8
~3.9
!
```
### V1.1 
> sort the output based on student number (stno) in ascending order instead of GPA

Using the above data The function should work as follows:  

```text

Enter GPA query...
? @2.2
Syntax error: ? [Op][value]<ENTER>
Op: [>,<,~,!]
value: GPA value

? ~3.7
[1] 231018: 3.7 (Ruth Powers)
[2] 234272: 3.7 (Comic Book Guy)
[3] 362030: 3.7 (Chazz Busby)
[4] 544294: 3.7 (Sea Captain)
? ~3.8
[1] 217994: 3.8 (Selma Bouvier)
? <2.0
[1] 134681: 1.8 (Wise Guy)
[2] 194002: 1.8 (Squeaky-Voiced Teen)
[3] 262592: 1.7 (Barney Gumble)
[4] 383513: 1.7 (Gil Gunderson)
[5] 394769: 1.9 (Troy McClure)
[6] 434336: 1.7 (Seymour Skinner)
[7] 533451: 1.8 (Judge Roy Snyder)
[8] 568727: 1.7 (Kent Brockman)
[9] 584416: 1.7 (Brandine Spuckler)
[10] 667331: 1.9 (Jessica Lovejoy)
[11] 677806: 1.7 (Wendell Borton)
[12] 686009: 1.8 (Helen Lovejoy)
[13] 695606: 1.6 (Kirk Van Houten)
[14] 753102: 1.8 (Bart Simpson)
[15] 877842: 1.6 (Edna Krabappel)
[16] 950955: 1.8 (Snake Jailbird)
? >3.8
[1] 155387: 3.9 (Baby Gerald)
[2] 242653: 3.9 (Bernice Hibbert)
[3] 249669: 4.0 (Ling Bouvier)
[4] 290816: 4.0 (Apu Nahasapeemapetilon)
[5] 324543: 3.9 (Abraham Simpson)
[6] 470546: 4.0 (Agnes Skinner)
[7] 570423: 4.0 (Lindsey Naegle)
[8] 736389: 4.0 (Disco Stu)
[9] 829982: 3.9 (Dolph Starbeam)
[10] 901832: 4.0 (Krusty The Clown)
? ~3.9
[1] 155387: 3.9 (Baby Gerald)
[2] 242653: 3.9 (Bernice Hibbert)
[3] 324543: 3.9 (Abraham Simpson)
[4] 829982: 3.9 (Dolph Starbeam)
? !
Exit the program? (Y)es/(N)o: y
Goodbye!
```

### Modules
Implement your program in three modules:
- GPAlist: (must contain the **gpaQuery** function)
- File: hold file-related functions
- UI: holding User interaction functions.


### Tester program
```c++
/***********************************************************************
// OOP244 Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "GPAlist.h"
using namespace sdds;
int main() {
	if(gpaQuery("std.csv")) {
		std::cout << "This should have failed!" << std::endl;
	}
	else {
		std::cout << "failed!, this is the correct exectution" << std::endl;
	}
	if(!gpaQuery("students.csv")) {
		std::cout << "This should have worked, fix the problem!" << std::endl;
	}
	printf("Goodbye!");
	return 0;
}
```
### Expected output using the "Data Entry" values:

[correct_output.txt](DIY/correct_output.txt)


## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
main.cpp
GPA.h
GPAlist.cpp
GPAlist.h
File.cpp
File.h
UI.h
UI.cpp
```

### Data Entry

??? explain what data  will be used for submission and testing

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

