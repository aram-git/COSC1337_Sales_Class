/* Ch11 #7 Corporate Sales.
A corporation has six divisions, each responsible for sales to different geographic locations.
Design a DivSales class that keeps sales data for a division, with the following members:
- An array with 4 element for holding 4 quarters of sales figures for the division
- A private static variable for holding the total corporate sales for all divisions for the entire year.
- A member function that takes 4 arguments, each assumed to be the sales for a quarter.
The value of the arguments should be copied into the array that holds the sales data.
The total of the 4 arguments should be added to the static variable that holds the total yearly corporate sales.
- A function that takes an integer argument within the range of 0 to 3. 
THe argument is to be used as a subscript into the division quarterly sales array. 
The function should return the value of the array element with that subscript.

Write a program that creates and array of 6 DivSales objects.
The program should ask the user to enter the sales for 4 quarters for each division. 
After the data is entered, the program should display a table showing the division sales for each quarter.
The program should then display the total corporate sales for the year. 
*/

//START
#include <iostream>
#include <string>

//CLASS FOR SALES DATA
class DivSales {
private:
    double quarter[4]; // Array to hold sales figures for four quarters
    static double totalCorporateSales; // Static variable to hold total corporate sales for the entire year

//FUNCTION TO SET SALES FOR EACH QUARTER AND UPDATE TOTAL CORPORATE SALES
public:
    void setQuarterlySales(double q1, double q2, double q3, double q4) {
        quarter[0] = q1;
        quarter[1] = q2;
        quarter[2] = q3;
        quarter[3] = q4;
        totalCorporateSales += (q1 + q2 + q3 + q4); //?updates total corporate sales
    }
//FUNCTION TO RETURN THE SALES FIGURE FOR A SPECIFIC QUARTER
    double getQuarterlySales(int quarterNum) const {
        return quarter[quarterNum];
    }
//STATIC FUNCTION RETURNS THE TOTAL CORPORATE SALES
    static double getTotalCorporateSales() {
        return totalCorporateSales;
    }
};
//INTITIALIZAES STATIC MEMBER VARIABLE
double DivSales::totalCorporateSales = 0.0; 

//MAIN
int main() {
    std::cout << "*PROGRAM FOR QUARTERLY SALES OF 6 REGIONAL DIVISIONS* \n";
    const int NUM_DIVISIONS = 6; //NUMBER OF DIVISIONS
    DivSales divisions[NUM_DIVISIONS]; //ARRAY OF DivSales OBJECTS

//LOOP TO INPUT SALES FOR EACH DIVISION
    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        double q1, q2, q3, q4;
        std::cout << "Enter sales for Division " << i + 1 << " for quarter 1: ";
        std::cin >> q1;
        std::cout << "Enter sales for Division " << i + 1 << " for quarter 2: ";
        std::cin >> q2;
        std::cout << "Enter sales for Division " << i + 1 << " for quarter 3: ";
        std::cin >> q3;
        std::cout << "Enter sales for Division " << i + 1 << " for quarter 4: ";
        std::cin >> q4;
        divisions[i].setQuarterlySales(q1, q2, q3, q4); //SETS SALES FPR THE CURRENT DIVISION
    }

    //TABLE TO DISPLAY DIVISION SALES
    std::cout << "\n********* Division Sales for Each Quarter *********\n";
    std::cout << "Division\tQ1\tQ2\tQ3\tQ4\n";
    std::cout << "---------------------------------------------------\n";
    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        std::cout << "Division " << i + 1 << ":\t";
        for (int j = 0; j < 4; ++j) {
            std::cout << divisions[i].getQuarterlySales(j) << "\t"; //PRINTS SALES FOR EACH QUARTER
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------------------\n";

    //DISPLAYS TOTAL SALES
    std::cout << "\nTotal Corporate Sales for the Year: $" << DivSales::getTotalCorporateSales() << std::endl;

    return 0;
}
//END