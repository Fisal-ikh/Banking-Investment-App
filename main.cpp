//Fisal Ikhmayes
// 02/05/23
//Project 2 cs-210

#include "Calculations.h"
#include <iostream>
using namespace std;



int main() {
   Calculations investment1;
    int exitCheck;
    while (true){
        investment1.inputVariables(); //calls the function
        investment1.outputWithoutMon(); // calls the function
        investment1.outputWithMon();

        std::cout << std::string(55, '=') << std::endl;
        std::cout << "Would you like to exit the program or try different values?" << std::endl;
        std::cout << "Enter 1 to exit || 2 to continue." << std::endl;
        while (true) {
            cin >> exitCheck;
            if (exitCheck == 1 || exitCheck == 2) {
                break;
            }
            cout << "Invalid input, only 1 or 2 is allowed." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (exitCheck == 1) {
            std::cout << "Program exited." << std::endl;
            break;
        }
    }
    return 0;
}
