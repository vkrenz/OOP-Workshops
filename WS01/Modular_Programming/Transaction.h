/**
 * Modular Example
 * Transaction.h
*/

struct Transaction {
    int acct; /** Account Number */
    char type; /** Credit 'c' or Debit 'd' */
    double amount; /** Transaction amount */
};

void enter(struct Transaction* tr);
void display(const struct Transaction* tr);