//Fisal Ikhmayes
// 02/05/23
//Project 2 cs-210


#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

class Calculations {
public:
	void inputVariables();
	void outputWithoutMon();
	void outputWithMon();


private:
		//Declare variables for input
		float m_inititalInvestment, m_monthlyDeposit, m_annualInterest, m_years, m_months;
		//declare variables for storing data
		float m_totalAmount;
		//declare variables for storying data.
		float m_intitialAmount, m_totalInterestYear;
		// used for input to continue program,
		char m_anyKey;



};

#endif /* CALCULATIONS_H_ */

