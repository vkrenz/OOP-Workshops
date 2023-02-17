# Workshop #5: Member and Helper operators
V 1.0 ("Coefficient" changed to "Multiple") 
## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- overload binary member operators
- create and define type conversion operators
- create and define helper operators (without using the friendship of a C++ class)
- reuse member operators
- describe what you have learned in completing this workshop.

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

# LAB (part 1) (50%)

Your task for part one of this workshop is to complete the code of a class that represents an **Egg Carton**. 

Develop your Egg Carton class in the **"EggCarton"** module provided in the workshop.

The **EggCarton** class encapsulates the size of the carton (i.e. the number of eggs it can hold), the number of eggs in the carton and whether the eggs are **jumbo** size or **regular**.
## constant values 
The following **constant** values are defined in the header file.
```C++
   const int RegularEggWieght = 50;
   const int JumboEggWieght = 75;
```
These weights are in Grams. (1000 Grams is one Kilo)

## the constructor
```C++
EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false)
```
The Egg Carton can be instantiated using its **size**, **the number of eggs** and **if the eggs are jumbo size**. 

By default, the size of the carton is **6**, the number of eggs is **0**, and the eggs are, **not jumbo size**. 

When created the following validation is done on the arguments of the constructor:
- **size** must be a multiple of 6
- **size** must be between 6 and 36 (inclusively) 
- **the number of eggs** should be between 0 and the **size** of the Carton (inclusively) 

If the values do not match the above criteria, the Carton is considered broken and unusable. This is done by calling the **"setBroken()"** private method that sets the **size** and number of eggs in the carton to **-1**.

## `ostream& display(ostream& ostr = cout) const`
displays the Carton on the screen using the **ostr** argument and the following private method:

```C++
ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
  int cartonWidth = size == 6 ? 3 : 6;
  for(int i = 0; i < size; i++) {
     ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
     ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
  }
  return ostr;
}
```

The Carton is displayed only if it is not broken (see `operator bool()` overload), otherwise the message: `"Broken Egg Carton!"<<endl` is displayed.

In the end, the **ostr** reference is returned. 

## `istream& read(istream& istr = cin)`
Reads comma-separated values from **istr** to set the **attributes** of **the Egg Carton** and then returns the **istr** reference as follows:

- read a **character** from **istr**, if it is a lower-case `J` set the **jumbo flag** to **true**, otherwise set it to **false**
- **ignore** the next character.
- read an integer into the **size** of the Carton
- **ignore** the next character
- read another **integer** into **the number of eggs**
- perform the same validation on the attributes as the **constructor** and if it fails, set the Carton to broken and unusable. 

## Type Conversion Operator overloads
### Boolean conversion.
```C++
operator bool() const;
```
This **constant conversion** returns **true** if the **size** of the Carton is **greater than zero** (i.e. Returns true if the Carton is not broken) otherwise, it will return **false**.
### Integer conversion
```C++
operator int() const;
```
This **constant conversion** returns the **number of eggs** if the Carton is not broken (use boolean conversion) otherwise, it will return **-1**
### Double Conversion
```C++
operator double() const;
```
This **constant conversion** returns the **total weight** of the eggs using the **constant weight values** defined in the header file in **Kilos**.

If the Carton is broken this conversion returns **-1.0**.

## Unary Operator overloads:

### prefix `operator--` 
If the Carton is **not broken** and the **number of eggs** is more than **zero**, it will reduce it by one. 

In the end, it returns the reference of the **current EggCarton object**.
### prefix `operator++` 
If the Carton is **not broken** it will add one to the **number of eggs**. If the **number of eggs** exceeds the **size** of the carton, the Carton will be considered **broken and unusable**.

In the end, return the reference of the **current EggCarton object**.
### postfix `operator--`
**Creates a local copy** of the current state of the EggCarton object, calls the prefix `operator--` and returns the local copy **by value**.
### postfix `operator++`
**Creates a local copy** of the current EggCarton object, calls the prefix `operator++` and returns the local copy **by value**.

## Binary Member Operators
### `EggCarton& operator=(int value)`
Sets the number of eggs to **the integer value** and If the **number of eggs** exceeds the **size**, it will set the Carton to **broken**. 
Returns a reference to the **current object** at the end.
### `EggCarton& operator+=(int value)`
Add **the value** to the **number of eggs** if the Carton is not broken. 
If the **number of eggs** exceeds the **size**, it will set the Carton to broken. 
Returns a reference to the current object at the end.
### `EggCarton& operator+=(EggCarton& right)`
If the Carton is not broken it will **move** the eggs from the **right** Carton to the empty spots of the **current Carton** as much as it can. If there is not enough space in the current Carton, the rest of the eggs are left in **the right one**. 

> For example, if the current Carton has 3 empty spots and there are 7 eggs in the right Carton after this operator runs, the current Carton will be full and the right Carton will have 4 eggs in it.

In the end, return a reference to the current object.

### `bool operator==(const EggCarton& right) const`
Return **true** if the **difference** between the **weight of the current** Carton and the **weight of the right** Carton is between -0.001  and 0.001 kilos otherwise, return **false**.

## Helper Binary Operator Overload
### `int operator+(int left, const EggCarton& right)`
If the right operand is not broken it will return the sum of **"left"** and the number of eggs in the **"right"**. Otherwise, it will return the value of the **left** only.

### `ostream& operator<<(ostream& ostr, const EggCarton& right)`

displays the EggCarton and returns **ostr**;

### `istream& operator>>(istream& istr, EggCarton& right)`

Reads the specs from the console into the **right** Carton and returns **istr**.

## Tester program:

[main.cpp](lab/main.cpp)

## Execution Sample

[correct_output.txt](lab/correct_output.txt)

### Files to submit:  
```Text
EggCarton.cpp
EggCarton.h
main.cpp
```

### Data Entry

Follow the instruction in the tester program.

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

## DIY (50%)

Your task for part two of this workshop is to create a class module to represent a **Bus**. 

Develop your module int files `Bus.h`  and `Bus.cpp`

The Bus class encapsulates **the number of seats** and **the number of passengers** in a **bus**.

## global constant value 
The **price of a bus ticket** is **$125.34** and will not change throughout the program. 

## the constructor
A **Bus** can be instantiated using the **number of seats** and the **number of passengers** on board. 

By default, a bus has **20 seats** and **no passengers**. 

When created the following validation is done on the arguments of the constructor:
- **number of seats** must be a multiple of **2**
- **number of seats** must be between **10** and **40** (inclusively) 
- the **number of passengers** should be between **0** and the **number of seats**.

If the values do not match the above criteria, the bus is considered **out of service**. 

## Displaying a bus on the screen.
A **bus** can be drawn on the screen by getting **inserted** into the **cout** object and under the drawing, on a new line the **total fare for the bus**, based on the **number of passengers** and **price of one ticket** must be displayed. 

For example, a **Bus** with **12** seats and **7** passengers should be displayed as follows:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

If the Bus is not in service the following message should be displayed instead:
```text
Out of service!
```

Use the following function in your **display** routine as a **private member** of **Bus class** to draw the bus on the screen. 

```C++
voiddrawBus(int seats, int noOfPassengers, ostream& ostr) const {
  int i, p;
  ostr.fill('_');
  ostr.width((seats / 2) * 3 + 4);
  ostr << "_";
  ostr << endl << "| ";
  for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
  ostr << "|_\\_" << endl;
  ostr << "| ";
  ostr.fill(' ');
  ostr.width(((seats / 2) * 3 - 14) / 2);
  ostr << " " << "Seneca College";
  ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
  ostr << " " << "    )" << endl;
  ostr << "`---OO";
  ostr.fill('-');
  ostr.width((seats / 2) * 3 - 5);
  ostr << "-" << "O---'" << endl;
}
```
> you may modify this code as long as the output is not changed.


## Reading the specs. of a bus from the console:
The specifications of a bus can be **read** from the **console** by **extracting** a Bus object from **istream** (**cin**).

Extraction should be done as follows

- read an **integer** into the **number of seats**
- **ignore** the next character.
- read **an integer** into the **number of passengers**. 
- perform the same validation on the attributes as the constructor and if it fails, set the bus to **out of service**.

## Type Conversion Operator overloads
### Boolean conversion.
This read-only conversion returns true if the number of seats is greater than zero. (i.e. Returns true if the bus is **in service**)
### Integer conversion
This read-only conversion returns the number of passengers if the Bus is in service otherwise, it will return -1
### Double Conversion
This read-only conversion returns the total fare of the bus for the trip using the number of passengers on the bus and the price of a ticket.

If the Bus is out of service this conversion returns **-1.0**.

## Unary Operator overloads:
### prefix `operator--` 
If the bus is out of service or empty, this operator returns false. Otherwise, it will reduce the number of passengers by one and returns true;

### prefix `operator++` 
If the bus is out of service or full, this operator returns false. Otherwise, it will increase the number of passengers by one and returns true;

### postfix `operator--`
Works exactly like the prefix operator--
### postfix `operator++`
Works exactly like the prefix opeator++

## Binary Member Operators
### Assigning A bus object to an integer value.

Sets the number of passengers of a bus by assigning it to the integer value and If the number of passengers exceeds the number of seats, the bus will be **out of service**.

Returns a reference to the current object at the end.
```C++
Bus B(12,0);
cout << (B = 7); 
```
will print the following:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

### Adding an integer to a Bus object using **+=** operator

Adds the integer value to the number of passengers if the bus is in service. 
If the number of passengers exceeds the number of seats, the bus will go **out of service**.

Returns a reference to the current object at the end.

```C++
Bus B(10,2);
cout << (B += 5); 
```
Will print the following:
```text
______________________
| [2][2][2][1][ ][ ]|_\_
|   Seneca College      )
`---OO-------------O---'
Total Fare Price: 877.38
```

### Adding a bus object to another bus object using += operator.

If both busses are in service it will move the passengers from one bus (right) to another (left). If there is not enough seat in the left bus, the rest of the passengers remain in the right bus.

In the end, a reference to the left bus is returned.

```C++
  Bus A(10, 2);
  Bus B(20, 12);
  cout << A << B;
  cout << (A += B) << B;
```
Will print the following:
```text
___________________
| [2][ ][ ][ ][ ]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 250.68
__________________________________
| [2][2][2][2][2][2][ ][ ][ ][ ]|_\_
|         Seneca College            )
`---OO-------------------------O---'
Total Fare Price: 1504.08
___________________
| [2][2][2][2][2]|_\_
|  Seneca College     )
`---OO----------O---'
Total Fare Price: 1253.40
__________________________________
| [2][2][ ][ ][ ][ ][ ][ ][ ][ ]|_\_
|         Seneca College            )
`---OO-------------------------O---'
Total Fare Price: 501.36
```

### Comparing two buses using the **==** operator.

If both buses are in service and the numbers of passengers are the same, this operator returns true, otherwise, it will return false.

```C++
Bus A(10,5);
Bus B(20,5);
if (A == B) cout << "Same number of passnegers" << endl; 
```



## Helper Binary Operator Overload
### sum of an integer number (at left) and a bus (at right) 
If the bus is in service, this operation should return the sum of the number and the number of passengers on the bus. 
Otherwise, the integer number is returned as if the number of passengers on the bus was 0.

```C++
Bus A(10,5),B(5,50);
int I = 3 + A;  // I will be 8 
I = 10 + B; // I will be 10
```

## Tester Program

[main.cpp](DIY/main.cpp)

## Sample output

[correct_output.txt](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```Text
reflect.txt 
Bus.cpp
Bus.h
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

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty
