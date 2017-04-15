/*************************************************************
Alex Hennessy                                                
CSCI 113 - 01 Programming with C++               
Spring 2017, 03/27/2017                                 
Programming Assignment 4: Password Complexity Verification       
*************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int  MINIMUM_LENGTH = 7;
bool complexPassword(string);

int main()
{
   //Declared a string:
    string password;
    
   //Output:
    cout << "Enter your new password: ";
    
   //Get input from user.
    cin >> password;
    
    //If the password does not meet the criteria.
    while (!complexPassword(password))
    {
        //Outputs Statement:
        cout << "\n\nPassword complexity required: \n"
             << "\tMINIMUM length of " << MINIMUM_LENGTH <<" characters &\n"
             << "\tTHREE of the following Four characteristics:\n"
             << "\t\t1. Upper case character\n\t\t2. Lower case character\n\t\t"
             << "3. Numeric character\n\t\t4. Non-alphanumeric character\n";
        cout << "Enter your new password: ";
        
        // Get input from user.
        cin >> password;
    }
    
    // if conditions for password are met, display message.
    cout << "\n\nThe password entered meets complexity requirements.\n\n";

    return 0;
}


/*************************************************************************************************************************
 * Function complexPassword() verifies the complexity of a password
 * and returns boolean TRUE if complex and FALSE if not
 * Complexity consists of:
 * 1. Minimum length use constant MINIMUM_LENGTH
 * 2. 3 of the 4 following: upper case character, lower case character, numeric character, or non-alphanumeric character
*************************************************************************************************************************/

bool complexPassword(string password)
    {
        //booleans for complexity verifications:
        bool  checkLength = false, //Length Test
              checkUpper = false, //Uppercase Test
              checkLower = false, //Lowercase Test
              checkDigit = false, //Number Test
              checkAlpha = false; //Non-alphanumeric Test
    
                for (int verify = 0; password[verify]; ++verify)
                {
                //Checking to see if the password is greater than or equal to 7
                    if(password.length() >= MINIMUM_LENGTH)
                    {
                        checkLength = true;
                    }
                    
                //Checking to see if the password has at least 1 Uppercase character
                    if (isupper(password[verify]))
                    {
                        checkUpper = true;
                    }
                    
                //Cheking to see if the password has at least 1 Lowercase character
                    if (islower(password[verify]))
                    {
                        checkLower = true;
                    }    
                
                //Checking to see if the password has at least 1 digit/numeric character
                    if (isdigit(password[verify]))
                    {
                        checkDigit = true;
                    }    
                
                //Checking to see if the password has at least 1 non-alphanumeric character
                    if (isalpha(password[verify]))
                    {
                        checkAlpha = true;
                    }    
                }
               
            //Returns TRUE for one of the follwing combinations:
            if (checkLength && checkUpper && checkLower && checkDigit && checkAlpha) //All conditions are met
            {
                return true;
            }
            
            else if (checkLength && checkUpper && checkLower && checkDigit) //Length, uppercase, lowercase, and numeric charcters are met
            {
                return true;
            }
            
            else if (checkLength && checkUpper && checkLower && checkAlpha) //Length, uppercase, lowercase, and non-alphanumeric charcters are met
            {    
                return true;
            }
            
            else if (checkLength && checkUpper && checkDigit && checkAlpha) //Length, uppercase, numeric, and numeric charcters are met
            {
                return true;
            }
            
            else if (checkLength && checkLower && checkDigit && checkAlpha) //Length, lowercase, numeric, and numeric charcters are met
            {
                return true;
            }
            
            //Returns FALSE if it does NOT meet one of the following above combinations
            else
            {
                return false;
            }
    
        return 1;
        }