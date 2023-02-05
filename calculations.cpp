//Fisal Ikhmayes
// 02/05/23
//Project 2 cs-210


#include "Calculations.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



void Calculations::inputVariables(){
	std::cout << std::string(30, '*') << std::endl;
	std::cout << std::string(10, '*') << "Data Input" << std::string(10, '*') << std::endl;
	//Prompt user for initial investment, check for valid input
	std::cout << "Initial investment: " << std::endl;
	while (true) {
	    if (cin >> m_inititalInvestment && m_inititalInvestment >= 0) {
	        break;
	    }
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << "Invalid input, input must be a positive integer." << endl;
	}

	//Prompt user for monthly deposit, check for valid input
	cout << "Monthly deposit: " << endl;
	while (!(cin >> m_monthlyDeposit) || m_monthlyDeposit < 0) {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << "Invalid input, input must be a positive integer." << endl;
	}

	//Prompt user for annual interest, check for valid input
	std::cout << "Annual Interest" << std::endl;
	while (!(cin >> m_annualInterest) || m_annualInterest < 0) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Invalid input, input must be a positive integer." << endl;
		}

	//Prompt user for number of years, check for valid input
	std::cout << "Number of years: " << std::endl;
	while (!(cin >> m_years) || m_years < 0) {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Invalid input, input must be a positive integer." << endl;
		}
	//Calculate number of months from years
	m_months = m_years * 12;

	//Prompt user for any key, check for valid input
	std::cout << "Press any letter to continue..." << std::endl;
	cin >> m_anyKey;
	while (!isalpha(m_anyKey) || cin.get() != '\n') {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << "Invalid input, input must only be a letter." << endl;
	    cin >> m_anyKey;
	}
	//Set total amount equal to initial investment
	m_totalAmount = m_inititalInvestment;
}



void Calculations::outputWithoutMon() {
	//output and display the header
	std::cout << std::string(5, ' ' ) << "Balance and interest without monthly deposits" << std::string(5, ' ' ) << std::endl;
	std::cout << std::string(55, '=') << std::endl;
	std::cout << std::string(3, ' ' ) << "Year" << std::string(3, ' ' ) << "Year End Balance"
		<< std::string(3, ' ' ) << "Year End Earned Interest" << std::endl;
	std::cout << std::string(55, '-') << std::endl;

	for(int i=0; i<m_years ;i++){
		//Calculate yearly interest withput monthly deposit
		m_intitialAmount = (m_totalAmount) * ((m_annualInterest/100));
		//Calculate year end total
		m_totalAmount = m_totalAmount + m_intitialAmount;
		//outputs the data using 2 decimal points
		std::cout << std::string(5, ' ' ) << i+ 1;
		std::cout << std::string(18, ' ' ) << '$' << setprecision(2) << std::fixed << m_totalAmount;
		std::cout << std::string(20, ' ' ) << '$' << setprecision(2) << std::fixed << m_intitialAmount << std::string(5, ' ');
		std::cout << endl;

	}
	std::cout << " " << std::endl;

	m_totalAmount = m_inititalInvestment;
}

void Calculations::outputWithMon(){
	//outputs and displays the header
	std::cout << std::string(5, ' ' ) << "Balance and interest with monthly deposits" << std::string(5, ' ' ) << std::endl;
	std::cout << std::string(55, '=') << std::endl;
	std::cout << std::string(3, ' ' ) << "Year" << std::string(3, ' ' ) << "Year End Balance"
			<< std::string(3, ' ' ) << "Year End Earned Interest" << std::endl;
	std::cout << std::string(55, '-') << std::endl;


	for(int i=0; i<m_years ;i++){
		//Set yearly interest to zero at the start of the year
		m_totalInterestYear = 0;

	for(int j=0; j<12; j++){
		//Calculate monthly interest
		m_intitialAmount = (m_totalAmount + m_monthlyDeposit) * ((m_annualInterest/100)/12);
		//Calculate month end interest
		m_totalInterestYear = m_totalInterestYear + m_intitialAmount;
		//Calculate month end total
		m_totalAmount = m_totalAmount + m_monthlyDeposit + m_intitialAmount;
	}
	// outputs the data for total and interest with monthly deposit
	std::cout << std::string(5, ' ' ) << i +1;
	std::cout << std::string(18, ' ' ) << '$' << setprecision(2) << std::fixed << m_totalAmount;
	std::cout << std::string(18, ' ' ) << '$' << setprecision(2) << std::fixed << m_totalInterestYear << std::string(5, ' ') << std::endl;

	}

}

