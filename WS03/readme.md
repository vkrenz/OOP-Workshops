# Workshop #3: Member Functions and Privacy


In this workshop, you will use member functions and privacy to complete your work.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to use member functions to query the state of an object
- to use member functions to change the state of an object
- to describe to your instructor what you have learned in completing this workshop

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

## Constants

```C++
const int MAX_TOPIC_LENGTH
```
Provided for you in the department.h. It represents the maximum number of characters in a project's topic.

## Struct Project

This struct is provided for you in department.h. It represents a project which a department can work on. A project will have a topic represented by a C string that can hold a max of 25 characters. A project also has double that represents its cost.

Your task for part one of workshop 3 is to create a class called "Department" that encapsulates a Project. (in Department.h and Department.cpp).

## Attributes
The Department class must keep the following information:

- **The departments' name:** that is held dynamically in a C string.  (`char *`)
- **The departments' projects:** that is held dynamically by a Project pointer.  (`Project *`)
- **Number of Current Projects**: that are all held in an integer. (`int`)
- **Budget of the Department**: that is held in a double (`double`). Should have an initial value of 15345.99.

## Public methods
The Department class has the following Public functions:

```C++
void updateName(const char* newname)
```
If the provided name is valid (exists and is not empty), this function will set the name of the department. If the department is already set, it will deallocate the name. It will create enough memory for the name of the department to match the new name and then copies the data of the new name. If the new name is not valid, the department's current name will not change.

```C++
void updateBudget(double change)
```
This function will update the budget of the department by adding a new change to it.

```C++
bool addProject(Project& newproject)
```
This function will add a new project to the department as long as the total cost does not exceed the allocated budget. If the new project cost in addition to the total cost of the current project does not exceed the budget this function will add the new project to the department list of projects by doing the following steps:

- if there are no projects currently in progress:
  - creates a new Project and saves the data inside it
- if there are projects currently in progress:
  - allocates a temp array of projects with new size = old size + 1.
  - copy all projects from the old array to the new one
  - add new data to the last position of the temp array
  - wipe out the old array
  - increase the number of the project by one
  - allocate projects with the new size
  - copy all projects from the temp array to projects
  - wipe out the temp array
- This function will eventually return true if a project was added to the department, and false otherwise.

```C++
void createDepartment(const char* newname, 
                      Project& newproject, 
                      double change);
```
This function will use functions updateName, addProject and updateBudget to set the name of the department, add a project to it and update its budget.

```C++
Project* fetchProjects() const
```
This function will return the list of projects a department is currently working on.

```C++
int fetchNumProjects() const;
```
This function will return the number of projects a department is currently working on.

```C++
double fetchBudget() const
```
This function will return the current budget of a department.

```C++
char* Department::fetchName() const
```
This function will return the name of a department.

```C++
double totalexpenses()
```
This function will calculate and return the expenses of a department. The total expenses of a department is the total cost of all its current projects.

```C++
double remainingBudget()
```
This function will calculate and return the remaining budget of a department by subtracting the total expenses from the budget.

```C++
void clearDepartment()
```
This function will clear all the dynamic memory allocation in a department.

## Helper Functions
These functions are fully provided for you, make sure you review them and understand how they work:

```C++
 void display(const Project& project)
```
This function will Display the details of a project.

```C++
 void display(const Department& department)
```
This function will Display the details of a department.

## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File	main.cpp
// Version 1.0
// Date		October 7, 2022
// Author	Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Department.h"
using namespace std;
using namespace sdds;

int main() {

	Project testProject = { "Base",551.55 };

	Project myprojects[5] = { {"Synergy", 5041.55},
							  {"Mecha", 2925.99},
							  {"Chroma", 3995.45},
							  {"Force", 6988.45},
							  {"Oculus", 7441.22}
	};

	Department SDDS{};

	//Test1
	cout << "**********Create Department TEST START**********" << endl;
	SDDS.createDepartment("School of Software development", testProject, 1);
	display(SDDS);
	cout << "**********Create Department TEST END**********" << endl;

	//Test2
	cout << endl << "**********Update Name TEST Start**********" << endl;
	SDDS.updateName("School of Software development and design");
	display(SDDS);
	cout << "**********Update Name TEST END**********" << endl;

	//Test3
	cout << endl << "**********Update Budget TEST Start**********" << endl;
	SDDS.updateBudget(5555.99);
	display(SDDS);
	cout << "**********Update Budget TEST END**********" << endl;

	//Test4
	cout << endl << "**********Expenses and Remaining Budget TEST Start**********" << endl;
	cout << "Our current total Expenses are: " << SDDS.totalexpenses() << endl;
	cout << "Our remaining budget is: " << SDDS.remainingBudget() << endl;
	cout << "**********Expenses and Remaining Budget TEST END**********" << endl;

	//Test5
	cout << endl << "**********Add Project TEST START**********" << endl;
	for (int i = 0; i < 5 && SDDS.addProject(myprojects[i]); i++);
	display(SDDS);
	cout << "**********Add Project TEST END**********" << endl;
	
	SDDS.clearDepartment();
	return 0;
}
```

## Execution Sample

```text
**********Create Department TEST START**********

Department School of Software development details:

Budget: 15347 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on: 

Project Base will cost a total of 551.55 C$.

**********Create Department TEST END**********



**********Update Name TEST Start**********

Department School of Software development and design details:

Budget: 15347 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on: 

Project Base will cost a total of 551.55 C$.

**********Update Name TEST END**********



**********Update Budget TEST Start**********

Department School of Software development and design details:

Budget: 20903 and the number of projects in progress is: 1

Below are the details of the projects we are currently working on: 

Project Base will cost a total of 551.55 C$.

**********Update Budget TEST END**********



**********Expenses and Remaining Budget TEST Start**********

Our current total Expenses are: 551.55

Our remaining budget is: 20351.4

**********Expenses and Remaining Budget TEST END**********



**********Add Project TEST START**********

Department School of Software development and design details:

Budget: 20903 and the number of projects in progress is: 5

Below are the details of the projects we are currently working on: 

Project Base will cost a total of 551.55 C$.

Project Synergy will cost a total of 5041.55 C$.

Project Mecha will cost a total of 2925.99 C$.

Project Chroma will cost a total of 3995.45 C$.

Project Force will cost a total of 6988.45 C$.

**********Add Project TEST END**********
```

## LAB Submission (part 1)

### Files to submit:  

```Text
Department.cpp
Department.h
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

Follow the instructions of the tester.

### Submission Process:

To test and demonstrate the execution of your program use the same data as shown in the [LAB Execution example](#LAB-Execution-example).

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
>Except for the mandatory sections of DIY, all the other parts can be changed by students if they find it necessary as long as the program produces an output that exactly matches the required output.  Please note that you can (and probably should) add more member functions to make the DIY part work.

Your task for this part is to create a program that provides a class called **Store**. This class can be instantiated by store name and the number of toys that can be added. 

Then the **Toy**s will be added one at a time to the **Store** by toy name, SKU number, price and toy age. A toy can be searched by its SKU number to find out if it is on sale or not. 
 
The **Stores Toy list** then can be displayed as follows, listing all the toys' names, their SKU numbers, age and price. Price varies and depends on if toys are on sale or not. 

## Sample List
``` Text
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
                    	   SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       20.79   On Sale
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       72.79   On Sale
Toy[6] :Lego             88224596    10       52.79   On Sale

```
## Implementation 
Implement this program in two modules (i.e., classes):

**Store** and **Toys**

## Store Module

define the following constant in the **Store** header file:
```
MAX_NUM_TOYS; //define it to 10. The maximum number of toys that could be added. 
MAX_SNAME; // define it to 31. The maximum length of a store name 
```
The Store class should have the following member variables:

- char m_sName;// Store name, up to MAX_SNAME size
- int m_noOfToys;//No of toys;
- int m_addToys;//no of toys added
- Toys m_toy;// statically array of toys with size MAX_NUM_TOYS

The followings are the mandatory public member functions:
- void setStore(const char* sName, int no); 

  This will set the store name and the number of toys that could be added to the store. For invalid value, it will set the values to an empty state.
- void setToys(const char* tname, int sku, double price,int age);

  This will add the toys one at a time to the m_toy array and will keep track of the number of toys added. Toys will be added until num of added toys is less than m_noOfToys
- void display()const;

  If a Store object is valid
  
     a) prints "\*" with width 60 and fill with "\*", then print **m_sName** and a new line. 
     
     b) prints "\*" with width 60 and fill with "\*", then prints "list of the toys" and a new line.
     
     c) prints "SKU" with width 30 and fill with empty spaces
     
     d) prints "Age" with width 10 and fill with empty spaces
     
     e) prints "Price" with width 11 and fill with empty spaces
     
     f) prints "Sale" with width 10 and fill with empty spaces then a new line
     
     g) prints all the toys information. For details see the sample output.
    
2) otherwise prints, "Invalid Store" then a new line.

- void find(int sku);

  This method will go through the arrays of toys. It will match the received SKU number with the stored toys' SKU number to find out if the toys are on sale or not. If the number matches then it will pass **true** to the appropriate **Toys** method. After that, it will call the **calSale()** of the toys class to know the sale value. 
- void setEmpty();

  set the store to an empty state

## Toys Module

define the following constant in the **Toys** header file:
```
MAX_TNAME; // define it to 31. The maximum length of a Toy name 
```
The Toy class should have the following member variables:

- char m_tname;// toy name, up to MAX_TNAME size
- int m_sku; //SKU number, maximum 8 digits long
- double m_price;//toy price
- int m_age;//toy according to age group
- bool m_onSale;// keep track, if toys are on sale or not

The followings are the mandatory public member functions:
- void addToys(const char* tname, int sku, double price,int age);

  After checking the validity, this method will set the received values to the appropriate data members. Otherwise will be set to an empty state. 
- void isSale(bool sale);

  It will assign the received value to the data member m_onSale.
- void calSale();

  It will decrease the toys price to 20% then the original price. 
- void display()const;

  If a Toy object is valid
  
     a) prints **m_tname** with width 15, left justified and filled with empty spaces.
     
     b)  prints **m_sku** with width 10
     
     c) prints **m_age** with width 6
     
     d) prints **m_price** with width 12 and after the decimal point 2     
        digits.
	
    e) If the toy is on sale it will print "On Sale" with width 10. Otherwise, print empty spaces with width 8.
 
2) otherwise prints, "Invalid Toy".

## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 3 Part2: Member Functions and Privacy
// File main.cpp
// Version 1.0
// Author Nargis Khan
// Description
// Tests Store module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include<iostream>
#include<cstring>
#include"Store.h"
using namespace std;
using namespace sdds;

int main() {

	Store s;
	cout << "Printing invalid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 2);
	s.setToys(nullptr, 20304576,12.50,2); 
	s.setToys("Car",203045,11.50,12);
	s.display();
	
	cout << endl << "Printing valid list of Toys" << endl;
	s.setStore("****Children`s Dream store****", 6);
	s.setToys("Racing Car",11223344, 40.99, 8);
	s.setToys("Teddy Bear", 33772346,25.99, 6); 
	s.setToys("Airplane", 44453466,60.99,16);
	s.setToys("Doll", 55887896,45.99, 5);
	s.setToys("Drone", 99221388, 90.99, 18);
	s.setToys("Lego", 88224596, 65.99, 10);
	s.display();

	cout << endl << "Searching for toys and printing the list with sale price" << endl;
	s.find(33772346);
	s.find(99221388);
	s.find(88224596);
	s.display();
}
```
## Execution Sample 
```C++
Printing invalid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
                           SKU       Age      Price      Sale
Toy[1] :Invalid Toy
Toy[2] :Invalid Toy

Printing valid list of Toys
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
                           SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       25.99
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       90.99
Toy[6] :Lego             88224596    10       65.99

Searching for toys and printing the list with sale price
************************************************************
****Children`s Dream store****
************************************************************
list of the toys
                           SKU       Age      Price      Sale
Toy[1] :Racing Car       11223344     8       40.99
Toy[2] :Teddy Bear       33772346     6       20.79   On Sale
Toy[3] :Airplane         44453466    16       60.99
Toy[4] :Doll             55887896     5       45.99
Toy[5] :Drone            99221388    18       72.79   On Sale
Toy[6] :Lego             88224596    10       52.79   On Sale
```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```Text
reflect.txt 
Store.cpp
Store.h
Toys.cpp
Toys.h
main.cpp
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

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty

