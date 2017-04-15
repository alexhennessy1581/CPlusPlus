/*****************************************
Alex Hennessy                        						
CSCI 113 - 01 Programming with C++   			
Spring 2017, 02/20/2017             					
Programming Assignment 2: The Math Tutor			
*****************************************/
#include <iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	//Declaring variables
		int operNum, randNum1, randNum2, solution, remainder;
		int numOne, numTwo;
		char operMath;
		
	//ASCII characters
		char line = 196; 
		char divide = 246;
		
	//Random number generator
		unsigned seed;

		// 1st Menu of Math Tutor
			cout << "-----------------------" << endl;
			cout << " Welcome to Math Tutor" << endl;
			cout << "-----------------------" << endl;
			cout << "Enter level of difficulty (1, 2, 3, or 4): ";
			cin >> operNum; //user's input
			
		//Error checking loop for OperNum
			while (operNum < 1 || operNum > 4) // runs loop whenever operNum is NOT between 1 - 4.
			{
				
				cout << "\nOops! Wrong thing was entered. Please enter a vaild difficulty: "; // Error statment, lets user re-enter input.
				cin >> operNum; // user's input
				
			}
			
				//Determing how large the intergers will be
					switch(operNum)
					{
						
						case 1: //one digit values
							numOne=1;
							numTwo=9;
						break;
						
						case 2: //two digit values
							numOne=10;
							numTwo=99;
						break;
						
						case 3: //three digit values
							numOne=100;
							numTwo=999;
						break;
						
						case 4: //four digit values	
							numOne=1000;
							numTwo=9999;
						break;
						
					}
				
			//Math operations, and do-while loop
				do
				{
					//2nd Menu of Math Tutor
						cout << "\n\t\t" <<"A" << "\t\t" << "Adittion\n";
						cout << "\t\t"<< "S" << "\t\t" << "Subtraction\n";
						cout << "\t\t"<< "M" << "\t\t" << "Multiplication\n";
						cout << "\t\t"<< "D" << "\t\t" << "Division\n";
						cout << "\t\t"<< "Q" << "\t\t" << "Quit (to end program)\n";
						cout<<"\nSelect from the choices above: ";
						cin >> operMath; //user's input
						
				// Switch for the menu's options based on operMath that was chosen.
					switch (operMath)
					{
						
					//Addition Math Problem
						case 'A':
						case 'a':
						//Graps random number from the computer's time and calculates what the random number is.
							seed = time(0);
							srand(seed);
							randNum1= 1 + rand() * numOne % numTwo; //1st random number
							randNum2= 1 + rand() * numOne % numTwo; //2nd random number
						//Ouput statement
							cout<< "\n\t\t   " << randNum1 << endl;
							cout<< "\t\t+  " << randNum2 << "\t" << endl;
							cout<< "\t\t" << line << line << line << line << line;
						//Pause statements
							cin.ignore();
							cin.get();
						//Calculation
							solution = randNum1 + randNum2;
						//Outputs the answer of calculation
							cout << "\n\t\t   " << solution << endl;
						break;
					
					//Subtraction Math Problem
						case 'S':
						case 's':
						//Graps random number from the computer's time and calculates what the random number is.
							seed = time(0);
							srand(seed);
							randNum1= 1 + rand() * numOne % numTwo; //1st random number
							randNum2= 1 + rand() * numOne % numTwo; //2nd random number
						//Ouput statement
							cout<< "\n\t\t   " << randNum1 << endl;
							cout<< "\t\t-  " << randNum2 << "\t" << endl;
							cout<< "\t\t" << line << line << line << line << line;
						//Pause statement
							cin.ignore();
							cin.get();
						//Calculation
							solution = randNum1 - randNum2;
						//Outputs the answer of calculation
							cout << "\n\t\t   " << solution << endl;
						break;
					
					//Multiply Math Problem
						case 'M':
						case 'm':
						//Graps random number from the computer's time and calculates what the random number is.
							seed = time(0);
							srand(seed);
							randNum1= 1 + rand() * numOne % numTwo; //1st random number
							randNum2= 1 + rand() * numOne % numTwo; //2nd random number
						//Ouput statement
							cout<< "\n\t\t   " << randNum1 << endl;
							cout<< "\t\tx  " << randNum2 << "\t" <<endl;
							cout<< "\t\t" << line << line << line << line << line;
						//Pause statements
							cin.ignore();
							cin.get();
						//Calculation
							solution = randNum1 * randNum2;
						//Outputs the answer to calculation
							cout << "\n\t\t   " << solution << endl;
						break;
					
					//Division Math Problem
						case 'D':
						case 'd':
						//Graps random number from the computer's time and calculates what the random number is.
							seed = time(0);
							srand(seed);
							randNum1= 1 + rand() * numOne % numTwo; //1st random number
							randNum2= 1 + rand() * numOne % numTwo; //2nd random number
						//Ouput statement
							cout<< "\n\t\t   " << randNum1 <<endl;
							cout<< "\t\t " << divide << " " << randNum2 << "\t"<<endl;
							cout<< "\t\t" << line << line << line << line << line;
						//Pause statements	
							cin.ignore();
							cin.get();
							//Calculates remainder of division problem
								remainder = randNum1 % randNum2;
									
									if(remainder == 0) //Prints out this statement if remainder is zero, and only zero.
									{
										//Calculation
											solution = randNum1 / randNum2;
										//Outputs the answer to calculation
											cout << "\n\t\t    " << solution << endl;
									}
									
									else //Prints out this stement if remainder is anything BUT zero.
									{
										//Calculation
											solution = randNum1 / randNum2;
										//Outputs the canswer to calculation
											cout << "\n\t\t    " << solution << " R " << remainder << endl;
									}
						break;
					
					//Quiting the program
						case 'Q':
						case 'q':
						//Output statement
							cout << "Thank you for using Math Tutor! Goodbye!\n";
						break;
						
					}
					
				}while(operMath != 'Q' && operMath != 'q'); // quits Do loop when 'Q' or 'q' is entered
				
		 return 0;
}