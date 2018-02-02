// Name: Brice Burdick
// Date Created: January 30th, 2018
// Description: This program is to open a text file that has credit card numbers on it. When the file is opened, it will check
// that the numbers given would match the credit card providers: Visa, Discover, MasterCard and American Express. If the numbers
// that are being checked don't work, then it will reject the card.
// Part A of Luhn Algorithm


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


// Declaring Check Bin function
bool Check_Bin(double card_Number);


int main(){
    double card_Number;
// Takes input from a file
    ifstream file;
    file.open("CreditCardNumbers.txt");
    // if the file opened 
    if (file.good())
    {
        // then it will take card number and check number to see if the number is accepted or not
        while (file >> card_Number){
            cout << fixed;
            cout << "Card Number :: " << card_Number << endl;
            if(Check_Bin(card_Number)){
                cout << "Card accepted" << endl;
            }else{
                cout << "Unknown card type - Card rejected" << endl;
            }
        }
    } else {
        cout << "No file to open" << endl;
        return 0;
    }
   
    return 0;
}

// Check Bin Function for each card
bool Check_Bin(double card_Number){
    // variable for card number
    double card_Copy = card_Number;

// Section for American Express card
    //American Express
    // Sets up condition to move decimal over x amount of places (13)
    for (int i = 0; i < 13; i++){
        // sliding decimal over one place
        card_Copy /= 10;
    }
    // checking to see if card matches the company's BIN number
    if ((int)card_Copy == 34 || (int)card_Copy == 37){
        return true;
    }



// Section for Discover card
    //Discover
    card_Copy = card_Number;
    // This condition moves decimal over x amount of places (10)
    for (int i = 0; i < 10; i++){
        card_Copy /= 10;
    }
    // If the card number is within range of these two numbers then its true and matches
    if ((int)card_Copy <= 622925 && (int)card_Copy >= 622126){
        return true;
    }
    for (int i = 0; i < 2; i++){
        card_Copy /= 10;
    }
    if ((int)card_Copy == 6011){
        return true;
    }
    for (int i = 0; i < 1; i++){
        card_Copy /= 10;
    }
    // If the card number is within range of these two numbers then its true and matches
    if ((int)card_Copy <= 649 && (int)card_Copy >= 644){
        return true;
    }
    for (int i = 0; i < 1; i++){
        card_Copy /= 10;
    }
    // if Bin number is equal to 65 then it's true
    if ((int)card_Copy == 65){
        return true;
    }



// Section for Master Card
    //Master Card
    card_Copy = card_Number;
    // This condition moves decimal over 14 places
    for (int i = 0; i < 14; i++){
        card_Copy /= 10;
    }
    if ((int)card_Copy <= 55 && (int)card_Copy >= 51){
        return true;
    }



// Section for Visa card
    //Visa
    card_Copy = card_Number;
    // This condition moves decimal over 12 places
    for (int i = 0; i < 12; i++){
        card_Copy /= 10;
    }
    for (int i = 0; i < 4; i++){
        if ((int)card_Copy == 4){
            return true;
        }

        card_Copy /= 10;
    }




    return false;
}