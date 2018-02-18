// Name: Brice Burdick
// Date Created: February 11, 2018
// Description: This program is to open two input data files which test to see if credit card gets denied or not based on 
// Part B of Luhn Algorithm


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

// Class for CreditCards
class Customer_Info {
    //FORMAT:
    //          CreditNumber FirstName Last Name Type - CurrentBalance
    public:
    Customer_Info(double card_number, string first_name, string last_name, string card_type, int current_balance){
    m_credit_card_number = card_number;
    m_name_first = first_name;
    m_name_last = last_name;
    m_card_type = card_type;
    m_current_balance = current_balance;
    // this would calculate the rebate amount and total purchases
    }
    void print(){
        std::cout << fixed;
        std::cout << m_credit_card_number << ", " << m_name_first << " " << m_name_last <<  ", " << m_card_type <<  ", " <<m_current_balance << std::endl;
    }
    
    private:
    double m_credit_card_number;
    string m_name_first;
    string m_name_last;
    string m_card_type;
    int m_current_balance;
};

// Class for Transaction Data
class Transaction_Data {
    //FORMAT:
    //          CardNumber:00/00/0000:transactNumber:Vendor
    public:
    Transaction_Data(double credit_card_number, string date, double transaction_number, int vendor, int purchase_amount){
        
        //Seperated the date santax into strings
        int string_array_pos = 0;
        string new_string = "";
        while (date[string_array_pos] != '/'){
            new_string += date[string_array_pos];
            string_array_pos++;
        }
        string_array_pos++;
        stringstream convert_to_day(new_string);
        convert_to_day >> m_date_day;
        
        new_string = "";
        while (date[string_array_pos] != '/'){
            new_string += date[string_array_pos];
            string_array_pos++;
        }
        string_array_pos++;
        stringstream convert_to_month(new_string);
        convert_to_month >> m_date_month;
        
        new_string = "";
        while (string_array_pos < 10){
            new_string += date[string_array_pos];
            string_array_pos++;
        }
        string_array_pos++;
        stringstream convert_to_year(new_string);
        convert_to_year >> m_date_year;
        
        
        
        m_credit_card_number = credit_card_number;
        //m_date_day = date_day;
        //m_date_month = date_month;
        //m_date_year = date_year;
        m_transaction_number = transaction_number;
        m_vendor = vendor;
        m_purchase_amount = purchase_amount;
    }
    
    void print(){
        std::cout << fixed;
        std::cout << m_credit_card_number << ", " << m_date_day << "/" << m_date_month << "/" << m_date_year << ", " << m_transaction_number << ", " << m_vendor 
        << m_purchase_amount << std::endl;
    }
    
    private:
    double m_credit_card_number;
    
    int m_date_day;
    int m_date_month;
    int m_date_year;
    
    double m_transaction_number;
    int m_vendor;
    int m_purchase_amount;
};



// Subclass of class credit cards specifically for gold cards
/*class Gold: public CreditCard {
    public:
    // Sets credit line to 3,000
    // Card will be blocked if limit is reached
    // rebate of 1% of total monthly purchase given to account
    private:
    
}
// Subclass of class credit cards specifically for platinum cards
class Platinum: public CreditCard {
    public:
    // Sets credit line to 5,000
    // Overdraft of 1,000 warning message is issued through account summary
    // Rebate of 2% of total monthly purchase given to account
    private:
    
}
// Subclass of class credit cards specifically for corporate cards
class Corporate: public CreditCard {
    public:
    // Sets credit line to 10,000
    // Overdraft of 5,000 warning message is issued through account summary
    // Rebate of 5% of total monthly purchase given to account
    private:
    
}
*/
using namespace std;

int main(){
    //create 2 array, one for the Customer objects, and the other for the transaction objects
    Customer_Info* customer_info_array[100];
    Transaction_Data* customer_transactions_array[100];


    // takes input from files
    ifstream file_credit_card;
    file_credit_card.open("credit_card_info.txt");
    
    
    //Create customer values
    double credit_card_number;
    string first_name;
    string last_name;
    string card_type;
    int current_balance;
    int current_index = 0;
    while (file_credit_card >> credit_card_number){
        file_credit_card >> first_name;
        file_credit_card >> last_name;
        file_credit_card >> card_type;
        file_credit_card >> current_balance;
        
        //Create the Object
        Customer_Info* new_customer_object = new Customer_Info(credit_card_number, first_name, last_name, card_type, current_balance);

        
        //Store the object into the array
        customer_info_array[current_index] = new_customer_object;
        
        //customer_info_array[current_index]->print();
        
        current_index++;
        //cout << current_index << endl;
    }
    
    file_credit_card.close();
    
    
    
    ifstream file_transactions;
    file_transactions.open("transaction.txt");
    
    string date;
    double transaction_number;
    int vendor;
    int purchase_amount;
    current_index = 0;
    while (file_transactions >> credit_card_number){
        file_transactions >> date;
        file_transactions >> transaction_number;
        file_transactions >> vendor;
        file_transactions >> purchase_amount;
        
        //Create the Object
        Transaction_Data* new_transaction_object = new Transaction_Data(credit_card_number, date, transaction_number, vendor, purchase_amount);

        
        //Store the object into the array
        customer_transactions_array[current_index] = new_transaction_object;
        
        //customer_transactions_array[current_index]->print();
        
        current_index++;
        
        
        //This will get the return information from the function in the public section of the class
        //customer_info_array[current_index]->public_function();
    }
    file_transactions.close();
    /*  1) Is the credit card transaction valid? --> the algorithm that is used to check the creditcard type maybe?
     *  2) Checks the current card balance
     *  3) Checks the credit limit
     *
     *  These steps will determine if the transaction will be approved or denied (if 1 is valid, 2 > 0, 3 if the credit limit isn't reached
     
     *  Compute the total purchase made on the card
     *  Compute the rebate amount
     
     OUTPUT (Visual information):
        INVALID CARD:
            The list of transactions that were denied + the reason for being denied
        VALID CARD:
            Monthly bill + summary of purchase
            Total credit card bill
            If overdrawn (The overdraft)
                Rebate value for going over value
     */
    
    // Output function
    // Show transaction
    return 0;
}
