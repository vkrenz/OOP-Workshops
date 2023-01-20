/**
 * Modular Example
 * Transaction.cpp
*/

#include <iostream> /** for cout, cin*/
#include "Transaction.h" /** for Transaction */

using namespace std;

/**
 * @brief Prompts for and accepts Transaction data
 */
void enter(struct Transaction* tr) {
    cout << "Enter the account number : ";
    cin >> tr->acct;
    cout << "Enter the account type ('d' debit, 'c' credit) : ";
    cin >> tr->type;
    cout << "Enter the account amount : ";
    cin >> tr->amount;
}

/**
 * @brief Displays the Transaction Data
 */
void display(const struct Transaction* tr) {
    cout << "Account: " << tr->acct;
    cout << (tr->type == 'd' ? " Debit $" : " Credit $") << tr->amount;
    cout << endl;
}