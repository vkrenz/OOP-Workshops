# Workshop #2: Dynamic Memory
* Version v1.1 (content of `correct_output.txt`  corrected)
* Version v1.2 (DIY main.cpp V1.1, Reordered user's tweets report title)<br />
  `correct_output.txt` updated to match the change

In this workshop, you will use *references* to modify content of variables in other scopes, overload functions and allocate memory at run-time and deallocate that memory when it is no longer required. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- allocate and deallocate dynamic memory for an array
- overload functions
- create and use references


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

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# Part 1 - LAB (50%)


***Customers ' main report*** is a program that reads records of behavioral profiles of using Android applications of a number of Customers from a file and holds these records in a dynamically allocated array of **Customers**. (Each record holds the app's identifier (Package_name), The user's identifier (user_id), spent time in hours (timeinhours) , day of the year (dayofyear), spent foreground Wi-Fi network connection time(ms)(Fwifitime), and day of week (dayofweek), spent foreground cellular network connection time(ms) (Fctime), in a .csv file format.)
After loading all the information into a dynamic array of **Customers**, the program will groups the records based on the user_id in ascending order

## LAB Execution example

```text
Records were retrieved successfully
Data records were grouped by the user id successfully
User id, timeinhours, Fctime, Fwifitime, Package Name
.....................................................
0,1.49325,369926,5005762,com.tencent.mm
0,1.35947,172756,4721320,com.tencent.mm
0,1.66986,1221,6010276,com.UCMobile
5,1.60287,5722288,48042,com.sina.weibo
5,1.92426,260011,6667309,com.tencent.mm
5,1.47877,2089902,3233672,com.UCMobile
9,1.02618,288007,3406229,com.digiplex.game
9,1.23554,59991,4387945,com.tencent.mm
9,12.9425,2190642,44402341,com.tencent.mm
9,1.21251,2544077,1820967,com.tencent.qqmusic
.....................................................

Data was successfully printed
Dynamically allocated memory was successfully deallocated
```

This program is partially developed, and you can find all the files in the lab directory. Your task is to complete the code as stated in the comments in the source code.

## The Code

The structure holding the customers' records is designed as follows:

```C++
   struct Customers {
        char* Package_Name;
        int user_id;
        double timeinhours;
        int dayofyear;
        int Fwifitime;
        int Fctime;
        char dayofweek;
    };
```
In addition to holding the customer records in an dynamically allocated array of **Customer**s, each Package's name is also held in a dynamically allocated Cstring in the **Customer** structure. 

  
## Data file  
Here is a sample of the data csv file in the following format:<br />
```Text
dayofweek, user_id, timeinhours, dayofyear, Fwifitime, Fctime, Package_Name<NEWLINE>
```
```Text
T	2	0.030551111	121	1989	 107995	  com.android.chrome
F	0	1.669860278	122	6010276	 1221	  com.UCMobile
F	5	1.478770556	122	3233672	 2089902  com.UCMobile
S	0	0.721798889	124	248535	 2349941  com.UCMobile
S	8	0.098520556	124	354674	 0	  com.uu.uunavi
S	2	0.087850556	124	0	 316262	  com.zhihu.android
M	3	0.107762222	125	0	 387944	  cn.coupon.kfc
M	8	6.175799722	125	20623140 1609739  com.android.chrome
```

### The Program Modules 
There are three modules in the program:  
**Tools**, **Package** and **main**

#### Tools Module 
The following three functions are already implemented in the **Tools** module:  
1. **openFile_r**
Opens the data file for reading  
2. **closefile**
Closes the data file
3. **noOfTraces**
Returns an integer that is the number of records in the opened and read file; use this function in the **Package** module to determine the size of the dynamic array of customers.

#### Your coding tasks in the Tools module:
Implement 4 **overloads** of a function called **read**
1. **read** function for the Package name:<br />
When success, returns a Cstring argument to send back the name of the Package.
Use the following fscanf function to read the name of the Package from the file.  
```C
fscanf(fp, "%60[^\n]\n", ......
```
2. **read** function for the user_id, dayofyear, Fwifitime and Fctime  :<br />
When success, returns a reference argument to an integer to pass back the user id, dayofyear,Fwifitime and Fctime.
Use the following fscanf function to read the user_id, dayofyear, Fwifitime and Fctime from the file and return true if it returns 1.  
```C
fscanf(fp, "%d,".......
```
3. **read** function for the timeinhours:<br />
When success, returns a reference argument to a doubler number to pass back the timeinhours.
Use the following fscanf function to read the timeinhours from the file.  
```C
fscanf(fp, "%lf,",......
```
4. **read** function for the dayofweek:<br />
When success, returns a reference argument to a char to pass back the dayofweek.
Use the following fscanf function to read the dayofweek from the file.  
```C
fscanf(fp, "%[^ \t\n\r\v\f,]%*c",......
```

#### Package Module 
The Package Module has two global variables:<br />
```C
1. int no_of_traces;
```
**no_of_traces** should hold the number of records read from the file and thus it should be used later to allocate the dynamic array of Customers.
```C
2. Customers* users;
```
This **Customers** pointer should point to the dynamic array of users. 
#### Functions

The following function is already implemented in the **Package** module:  
 **grouptTraces()** 
This function groups the records in the dynamic array of users based on the user_id in ascending order.

#### Complete the implementation of the following two functions:
1. **loadTraces** 
This overload of the **loadTraces** function returns a **bool** and receives a **Customers** reference.<br />
In a local array of 50 characters, it will try to read the Package name from the file. If successful it will find the actual length of the Package name using the **strlen** function and then add one to the length (for null termination) and allocate the same amount of characters in the name of the **Customers** reference. 
Then it will copy the read name (from the local character array) into the newly allocated name of the **Customers** reference using **strcpy**.<br />
If all the reads were successful, it will return true, otherwise false.

1. **loadTraces** 
This overload of the **loadTraces** function loads all the users records into the Customers array and returns a bool for success and has no arguments.<br />
First open the data file.<br />
Then set the number of users to the number of records in the file and then allocate a dynamic array of users pointed by the global **Customers** pointer; **"users"** to the number of the records in the file. <br />
Then load the users one by one from the file into the dynamic array of users.<br />
If the number of read records does not match the number of records, display the following error message and return false.
```text
Error reading the records, Check the data file.
```
Otherwise return true.

#### Implement the following two functions:
1. **display**
This function does not receive or return anything. <br />
This function displays customer records one by one (each record in a new row) based on the following condition: (timeinhours > 1.0 and dayofweek == 'F'). <br />
See the sample output.

2. **deallocateMemory**
This function does not return or receive anything.<br />
In a loop go through all the elements of the users array and deallocate the dynamic Package_Name of each user. Then deallocate the whole users array.

### main Module. 
Please do not modify the main Module.

## PART 1 Submission (lab)

### Files to submit:  
```Text
main.cpp
Package.h
Package.cpp
Tools.h
Tools.cpp
....
```
#### Custom code submission
If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

No data entry 

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


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1_sss for part one and **u**p2_sss for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX_sss
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

# DIY (50%) 

Twitter is a social media site whose primary purpose is to connect people and allow them to share their thoughts with a big audience. Complete a program that receives tweets information for an unknown number of users.
This information includes user_name, likes_count, retweets_count, replies_count, and share_videos (Y/N) on Twitter. At the end of the entry process, the user presses enter instead of entering the user name to end the program. This will end the program and display all the tweets' reports for the entered users. 

## Tester Program (main.cpp)
This module is fully provided. Please do not change any of its code. Review it and make sure you understand how the functions that you have developed are being used.

## Implementation  
This application is implemented in three modules:
- main Module (fully provided)
- Tools Module (fully provided)
- Customer Module (implement)

Your task is to complete the implementation of the Customer module to provide the functions needed in the main module.

***You may freely use or copy any logic or code needed from the LAB section***

### Structs to be used:

```C++
    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets report.
        int noOfRecords;
    };
```

### Required functions (mandatory)
Implement 2 **overloads** of a function called **EmptyRecord**

1. void EmptyRecord(...........);
Sets Customer data members to an empty state


2.  void EmptyRecord(...........);
Sets CustomersRecord data members to an empty state

Implement the follwoing five functions
```
1. bool read(Customers& rec);
```
Requests to enter `"user name: "` and then reads a CString into the name of **the Customer** reference. 
If the user enters a value of the user name, then it will read the likes_count, retweets_count, replies_count, and share_videos of **the Customer** and returns true. Otherwise, if the CString for the name is empty after entry, the function returns false.

```
2. void read(char* str, int len);
```
Reads a CString into the ```str``` pointer up to **len** characters.

This function is already implemented and is provided in the Customer module

```
3. void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
```
Adds **a Customer** to the dynamically allocated memory of customers in **CustomersRecord**

```
4. void display(const Customers& c_rec);
```
Prints the Customer information as follows: 
- user name
- comma and space `", "`
- likes 
- comma and space `", "`
- re-tweets
- comma and space `", "`
- replies
- comma and space `", "`
- share videos (y/n)
- new line `"\n "`

```C++
5. void display(const CustomersRecord& t_rec)
```
It prints a row number with a period before each user name. Then, it prints all the customers' records. 


## Execution Sample

[`correct_output.txt`](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
main.cpp (please do not modify this file).
Customer.cpp
Customer.h
Tools.cpp
Tools.h

.... 
```

### Data Entry
```text
zebaism
595
234
27
n
rohanv
12
0
1
n
frank
15
2
0
n
desibrah
39
19
2
y
sheetut
1
0
3
y
<ENTER>
```


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


#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

