// Name: Brice Burdick
// Date Created: April 5th, 2018
// Description: This is the test file to introduce the player and test interaction with the gameboard.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
void Draw_Board(std::vector<std::vector<char>> bd);
string Get_Row(std::vector<std::vector<char>> bd, int row);
int Get_Number_From_Input(string str, int i);


int main() {
       //ask player for file
    //cout << "What file would you like to read the board from?: " << endl;
    //
    //If player gives the wrong file, then ask for the file again
    
    //reads from board file
    //ifstream file;
    //file.open("board.h");
    
    
    
    // introducing the player and explaining the application
    //cout << "Hello new players and Welcome to Battleships!" << endl;
    //cout << "The main purpose of this is to test out the player's interaction and to make sure that the board can be read from a file." << endl;
    
    // initialization of the board
    std::vector<std::vector<char>> board;
    // declares board size
    int board_size = 10;

    // A vector that is character type for points
    //std::vector<std::vector<char>> graph_points;
    
    // creates a character vector and pushes it to the board vector
    for (int x = 0; x < board_size; x++){
        //Initilization for creating the 2d array
        std::vector<char> char_vec;
        for (int y = 0; y < board_size; y++){
            char_vec.push_back('o');
        }
        board.push_back(char_vec);
    }
    
    //How to change individual points on board
    //y value 1st, then x value
    //bd[y][x]
    //Example:      bd[0][3] = 'h';
    
    //Draw_Board(board);
    while(true){
        int column;
        int row;
        string input;
        cout << "Where do you want to attack?" << endl;
        cin >> input;
        
        
        int y = Get_Number_From_Input(input, 0);
        int x = Get_Number_From_Input(input, 1);
        
        if(x == -1 || y == -1 || input.length() > 2){
            cout << "Invalid position, please try again." << endl;
        }else{
            board[y][x] = 'h';
        }
        Draw_Board(board);
    //Ask which specific position they want to hit
    //Be able to detect if the player has chosen an invalid position and to retype input
    //If player gave a position that they've used then run turn
    //If player gave invalid row or column then ask for new input
    //If player enters extra characters after row and column then give error message
    // while(file runs){
    //cout << "Which position would you like to attack?: " << endl;
    //cin >> row >> column; 
    // if(position is invalid){
    // cout << "Invalid position, please try again.";
    // else if (position is invalid){
        //cout << "Extra characters were dectected"
   // }else{
       // cout << input
       //if (player miss){
           //cout << "You missed"
       //}else{
           //cout << "You got a Hit"
       //}
   //}
    
    //display board after picking a position to attack
    
    //if player wins then give message that they won
    
    }
   
    
 
    
    
    
    
    
    return 0;
}
// Takes in a vector of a vector of characters called bd
void Draw_Board(std::vector<std::vector<char>> bd){
    cout << "_ 0 1 2 3 4 5 6 7 8 9" << endl;
    cout <<"A" << Get_Row(bd, 0) << endl;
    cout <<"B" << Get_Row(bd, 1) << endl;
    cout <<"C" << Get_Row(bd, 2) << endl;
    cout <<"D" << Get_Row(bd, 3) <<  endl;
    cout <<"E" << Get_Row(bd, 4) <<  endl;
    cout <<"F" << Get_Row(bd, 5) <<  endl;
    cout <<"G" << Get_Row(bd, 6) <<  endl;
    cout <<"H" << Get_Row(bd, 7) <<  endl;
    cout <<"I" << Get_Row(bd, 8) <<  endl;
    cout <<"J" << Get_Row(bd, 9) <<  endl;
}

//Function to obtain the correct row from the board.
//Function will return the information at THAT row passed in.
string Get_Row(std::vector<std::vector<char>> bd, int row){
    string build_str = "";
        for (int column_index = 0; column_index < bd[row].size(); column_index++){
            build_str += " ";
            build_str += bd[row][column_index];
        }
    
    return build_str;
}

int Get_Number_From_Input(string str, int i){
    char str_char = str[i];
    int return_value = -1;
    if(str_char == '0'){
        return_value = 0;
    }else 
    if(str_char == '1'){
        return_value = 1;
    }else 
    if(str_char == '2'){
        return_value = 2;
    }else 
    if(str_char == '3'){
        return_value = 3;
    }else 
    if(str_char == '4'){
        return_value = 4;
    }else 
    if(str_char == '5'){
        return_value = 5;
    }else 
    if(str_char == '6'){
        return_value = 6;
    }else 
    if(str_char == '7'){
        return_value = 7;
    }else 
    if(str_char == '8'){
        return_value = 8;
    }else 
    if(str_char == '9'){
        return_value = 9;
    }else 
    // checking for characters
     if(str_char == 'a' || str_char == 'A'){
        return_value = 0;
    }else 
    if(str_char == 'b' || str_char == 'B'){
        return_value = 1;
    }else 
    if(str_char == 'c' || str_char == 'C'){
        return_value = 2;
    }else 
    if(str_char == 'd' || str_char == 'D'){
        return_value = 3;
    }else 
    if(str_char == 'e' || str_char == 'E'){
        return_value = 4;
    }else 
    if(str_char == 'f' || str_char == 'F'){
        return_value = 5;
    }else 
    if(str_char == 'g' || str_char == 'G'){
        return_value = 6;
    }else 
    if(str_char == 'h' || str_char == 'H'){
        return_value = 7;
    }else 
    if(str_char == 'i' || str_char == 'I'){
        return_value = 8;
    }else 
    if(str_char == 'j' || str_char == 'J'){
        return_value = 9;
    }
    return return_value;
    
}