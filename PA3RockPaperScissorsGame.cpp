/***************************************************
* Alex Hennessy                                                
* CSCI 113 - 01 Programming with C++               
* Spring 2017, 02/20/2017                                 
* Programming Assignment 3: Rock, Paper, & Scissors Game        
***************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

    // Global Constants 
        const int ROCK = 0, PAPER = 1, SCISSORS = 2;
        const int COMPUTER = 0, PLAYER = 1, TIE = 2;

    // Function Prototypes
        int playerInput();
        int computerInput();
        int chooseWinner(int, int);
        void displayResults(int, int, int);
    
    //Random number generator
        unsigned seed;

    //integers
        int user, machine, resultPlayer, resultComputer, resultWin;

    //FUNCTION main
        int main()
        {
            int computer, player, winner;
            
            // INTRODUCTION/MENU:
            cout << "\nWelcome to the Rock, Paper, Scissors Game\n"
                << "-----------------------------------------\n";
            
            //User Input
            player = playerInput();
            
            //Computer Input
            computer = computerInput();
            
            //Winner value
            winner = chooseWinner(player, computer);
            
            //Output results
            displayResults(player, computer, winner);
            
            return  0;
         }
         
/***************************************************************************************
        FUNCTION playerInput
        
        The purpose of this function is to solicit user input in selecting Rock, Scissors or Paper
        No parameters are sent to the function. 
        The function returns the user's input as an integerin the form of one of the pre-defined constants.
		
***************************************************************************************/
        
        int playerInput()
        {
            // FUNCTION SPECIFICATION:                
            // 1. PLAYER INPUTS ROCK, PAPER, SCISSORS VALUE
            // 2. LOOP USED TO VALIDATE USER INPUT
			
                cout << "Please choose between Rock (0), Paper (1), or Scissors (2): ";
                cin >> user; //User's Input
            
                while (user < 0 || user > 2) // runs loop whenever operNum is NOT between 0 - 2.
                    {

                        cout << "\n\nOops! Wrong value was entered. Please choose: Rock (0) or Paper(1) or Scissors(2): "; // Error statment, lets user re-enter input.
                        cin >> user; //User's Choice
                    }
            
            // 3. DISPLAY PLAYER'S CHOICE CHOICE AS ROCK PAPER SCISSORS
            // 4. RETURNS INTEGER VALUE OF ROCK, PAPER, SCISSORS CHOSEN BY PLAYER
			
                if (user == 0)
                    {
                        resultPlayer = ROCK;
                    }

                else if(user == 1)
                    {
                        resultPlayer = PAPER;
                    }

                else
                    {
                        resultPlayer = SCISSORS;
                    }
        
            return resultPlayer; // Possible Values: ROCK(0) or PAPER(1) or SCISSORS(2)
        }

/***************************************************************************************
        FUNCTION computerInput
        
        The purpose of this function is to generate random input in the form of Rock, Scissors or Paper
        No parameters are sent to the function.
        The function returns the commputer's selection in the form of one of the pre-defined constants.  
		
 ***************************************************************************************/
        
        int computerInput()
        {
            // CRITERIA:
            // 1. COMPUTER RANDOMLY GENERATES ROCK, PAPER, SCISSORS VALUE
			
                seed = time(NULL);
                srand(seed);
                machine = rand() % 3;

            // 2. DISPLAY COMPUTER'S CHOICE AS ROCK PAPER SCISSORS
            // 3. RETURNS INTEGER VALUE OF ROCK, PAPER, SCISSORS CHOSEN BY COMPUTER
			
                if(machine == 0)
                    {
                        resultComputer = ROCK;
                    }
                
                else if(machine == 1)
                    {
                        resultComputer = PAPER;
                    }
                
                else
                    {
                        resultComputer = SCISSORS;
                    }
        
            return resultComputer; // Possible Values: ROCK(0) or PAPER(1) or SCISSORS(2)
        }

/****************************************************************************************************************
    FUNCTION chooseWinner
        
    The purpose of this function is to compare the values generated by User and Computer and return a constant indicating winner or tie.
    Parameters for user selection and random computer selection are sent to the function.
    The function returns the winner in the form of one of the pre-defined constants.
	
****************************************************************************************************************/
        
        int chooseWinner(int player, int computer)
        {
            // CRITERIA:
            // 1. COMPARE PLAYER AND COMPUTER SELECTIONS USING RULES FOR ROCK PAPER SCISSOR
            // 2. RETURNS Integer COMPUTER, PLAYER, OR TIE.
			
                 if ((player == PAPER && computer == ROCK) || (player == SCISSORS && computer == PAPER) || (player == ROCK && computer == SCISSORS))
                    {
                        resultWin = PLAYER;
                    }
                else if((player == ROCK && computer == PAPER) || (player== PAPER && computer == SCISSORS) || (player == SCISSORS && computer == ROCK))
                    {
                        resultWin = COMPUTER;
                    }
                else
                    {
                        resultWin = TIE;
                    }
                
            return resultWin; // Possible Values: COMPUTER=0, PLAYER=1, TIE=2;
        }

/**********************************************************************************************************
    FUNCTION displayResults
    
    The purpose of this function is to display the selections of the user, computer, and the winner

    Parameters for user selection, random computer selection, and winner are sent to the function in the form of integer constants. 
    The function does not return a value.
        
**********************************************************************************************************/
        
    void displayResults(int player, int computer, int winner)
        {
        // CRITERIA - Feel free to incorporate text-based graphics
            // 1. Display player's choice
			
                if (player == ROCK)
                    {
                        cout << "\n\nYou have chosen ROCK!" << endl;
                    }

                else if(player == PAPER)
                    {
                        cout << "\n\nYou have chosen PAPER!" << endl;
                    }

                else
                    {
                        cout << "\n\nYou have chosen SCISSORS!" << endl;
                    }


            // 2. Display the computer's choice
			
                if(computer == ROCK)
                    {
                        cout << "The Computer has chosen ROCK!" << endl;
                    }
                
                else if(computer == PAPER)
                    {
                        cout << "The Computer has chosen PAPER!" << endl;
                    }
                
                else
                    {
                        cout << "The Computer has chosen SCISSORS!" << endl;
                    }

            // 3. Display winner/tie
			
                if (winner == PLAYER)
                    {
                            cout << "\nTHE RESULT: You Win!!!" << endl;
                    }
        
            else if (winner == COMPUTER)
                    {
                            cout << "\nTHE RESULT: The COMPUTER WINS!!!" << endl;
                    }
        
                else
                    {
                            cout << "\nTHE RESULT: It's a TIE!!!" << endl;
                    }
        }