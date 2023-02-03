/** 
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Victor Krenzel
Seneca Email: vkrenzel@myseneca.ca
Student Id: 102446176
Date: 02/01/2023
*/

#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    
    // Reads a CString into the str pointer up to len characters.
    // ** This function is already implemented and is provided in the Customer module **
    void read(char* str, int len);

    // Sets Customer data members to an empty state
    void EmptyRecord(Customers &c);

    // Sets CustomersRecord data members to an empty state
    void EmptyRecord(CustomersRecord &cr);

    /** Requests to enter "user name: " and then reads a CString into the name of the Customer reference.
    If the user enters a value of the user name, then it will read the likes_count, retweets_count, replies_count, 
    and share_videos of the Customer and returns true. Otherwise, if the CString for the name is empty after entry, 
    the function returns false. */
    bool read(Customers& rec);

    // Adds a Customer to the dynamically allocated memory of customers in CustomersRecord
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);

    /** 
    Prints the Customer information as follows:
    - user name
    - comma and space ", "
    - likes
    - comma and space ", "
    - re-tweets
    - comma and space ", "
    - replies
    - comma and space ", "
    - share videos (y/n)
    - new line "\n "
    */
    void display(const Customers& c_rec);

    // It prints a row number with a period before each user name. Then, it prints all the customers' records.
    void display(const CustomersRecord& t_rec);

    /** 
    
    CORRECT OUTPUT: 

    ---------  Customers records entry ------------------

    Enter customer information (to exit, press Enter):
     Enter User name: zebaism
     Enter likes_count: 595
     Enter retweets_count: 234
     Enter replies_count: 27
     Enter share videos (y/n): n

    Enter customer information (to exit, press Enter):
     Enter User name: rohanv
     Enter likes_count: 12
     Enter retweets_count: 0
     Enter replies_count: 1
     Enter share videos (y/n): n

    Enter customer information (to exit, press Enter):
     Enter User name: frank
     Enter likes_count: 15
     Enter retweets_count: 2
     Enter replies_count: 0
     Enter share videos (y/n): n

    Enter customer information (to exit, press Enter):
     Enter User name: desibrah
     Enter likes_count: 39
     Enter retweets_count: 19
     Enter replies_count: 2
     Enter share videos (y/n): y

    Enter customer information (to exit, press Enter):
     Enter User name: sheetut
     Enter likes_count: 1
     Enter retweets_count: 0
     Enter replies_count: 3
     Enter share videos (y/n): y

    Enter customer information (to exit, press Enter):
     Enter User name:
    ---------------------------------------------------------
                    Users' tweets report
     user name, likes, re-tweets, replies, share videos (y/n)
    ---------------------------------------------------------
    1. zebaism, 595, 234, 27, n

    2. rohanv, 12, 0, 1, n

    3. frank, 15, 2, 0, n

    4. desibrah, 39, 19, 2, y

    5. sheetut, 1, 0, 3, y

    ---------------------------------------------------------
                Report was successfully created
    Dynamically allocated memory was successfully deallocated
    ---------------------------------------------------------

    
    */
              
}

#endif 
