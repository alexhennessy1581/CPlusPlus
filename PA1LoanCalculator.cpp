/*****************************************
|	Alex Hennessy                        						|
|	CSCI 113 - 01 Programming with C++   			|
|	Spring 2017, 02/07/2017             					|
|	Programming Asn 1 - Loan Calculator  			|
*****************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() 
{
//-----------------------------------------------------------------User Input----------------------------------------------------------------------//
	
	float amountBorrowed, monthlyInterest, numberPayments;
		// amountBorrowed = amount borrowed, monthlyInterest = monthly interest rate, 
		// & numberPayments = number of payments.
	
		//explaing to user what to enter & how.
	cout << "Enter Amount Borrowed, Monthly Intrest Rate, and Number of Payments. \n";
	cout << "Seprate each value with a space: ";
	cin >> amountBorrowed >> monthlyInterest >> numberPayments;
		// user enters the values for amountBorrowed, monthlyInterest, & numberPayments.
		
	cout << endl; //Space
	cout << endl; //Space
	
//------------------------------------------------------------Monthly Payment-----------------------------------------------------------------//
	
	float P, PV, r, n;
		// P = Payment, PV = Present  Value, r = rate per period, & n= number of periods.
	
		// getting the int for PV, r, & n for Monlthy Payment Formula
	PV = amountBorrowed;
	r = monthlyInterest;
	n = numberPayments;
	
		//Monthly Payment Formula
	P = (r * PV) / (1 - pow(1+r,-n));
	
//---------------------------------------------------------------Other Formulas--------------------------------------------------------------//
	
		//Monthly Inrest Rate into a %
	float intRatepercent;
	intRatepercent = monthlyInterest * 100;
		// intRatepercent = Intrest Rate Percent.
	
		//new floats
	float interestPaid, amountPaidback;
		// interestPaid = intrest Paid, & amountPaidback = Amount Paid Back
	
		//Interest Paid
	interestPaid = (P * n) - amountBorrowed;
		// interestPaid = interest paid
	
			//Amount Paid Back Formula
	amountPaidback = amountBorrowed + interestPaid;
		// amountPaidback = amount paid back
	
		
//----------------------------------------------------------------------Output-----------------------------------------------------------------//
	
	cout << "Loan Amount:			$" << setw(15) << fixed << setprecision(2)<< right << amountBorrowed << endl;
	cout << "Mountly Interest Rate:"<< setw(26) << fixed << setprecision(2)<< right << intRatepercent << "%" << endl;
	cout << "Number of Payments:"<< setw(29) << fixed << setprecision(0)<< right << n << endl;
	cout << "Mounthly Payment:		$" << setw(15) << fixed << setprecision(2)<< right << P << endl;
	cout << "Amount Paid Back:		$" << setw(15) << fixed << setprecision(2)<< right << amountPaidback << endl;
	cout << "Intrest Paid:			$" << setw(15) << fixed << setprecision(2)<< right << interestPaid << endl;
	
	return 0;
	
} //end of code