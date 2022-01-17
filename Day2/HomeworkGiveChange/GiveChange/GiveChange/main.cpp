//
//  main.cpp
//  GiveChange
//
//  Created by Polina Lyubavina on 8/24/21.
//

#include <iostream>

// Homework: Vending Machine, Part 1 & Part 2 combined

int main()
{
    int junkFoodCost; // The price of snack or junk food in wending machine
    int centsCustomerPaid; // How much customer inserted into wending machine in cents
    
    std::cout << "Tell me how much your snack costs " << std::endl;
    std::cin >> junkFoodCost;
    
    if (junkFoodCost <= 0 ) { // Checks that snack cost is not negative
        std::cout << "Error: cents value entered cannot be negative. Please try again.\n";
        return 1;
    }
    
    std::cout << "Tell me how much you paid " << std::endl;
    std::cin >> centsCustomerPaid;

    if (centsCustomerPaid <= 0 ) { // Checks for coins total entered to be positive
        std::cout << "Error: cents value entered cannot be negative. Please try again.\n";
        return 1;
    }
    else if (centsCustomerPaid < junkFoodCost) { // Checks for insufficient funds
        std::cout << "Insufficient funds. Come back when you got more $$\n";
        return 1;
    }
    
    int giveBackChange = centsCustomerPaid - junkFoodCost; // change to give customer back
    std::cout << "Your change is " << giveBackChange << std::endl;
    
    int numOfQuarters = giveBackChange / 25; // how many quarters are contained in customer's change
    if (numOfQuarters > 2) {
        numOfQuarters = 2;
    }
    giveBackChange = giveBackChange - (numOfQuarters * 25);
    
    int numOfDimes = giveBackChange / 10; // how many dimes are contained in customer's change
    if (numOfDimes > 2) {
        numOfDimes = 2;
    }
    giveBackChange = giveBackChange - (numOfDimes * 10);
    
    int numOfNickels = giveBackChange / 5; // how many nickels are contained in customer's change
    if (numOfNickels > 2) {
        numOfNickels = 2;
    }
    giveBackChange = giveBackChange - (numOfNickels * 5);
    
    int numOfPennies = giveBackChange ; // how many pennies are contained in customer's change
    if (numOfPennies > 2) {
        std::cout << "Unable to return change, out of coins!\n";
        return 1;
    }
    
    std::cout << "Quarters: " << numOfQuarters << std::endl;
    std::cout << "Dimes: " << numOfDimes << std::endl;
    std::cout << "Nickels: " << numOfNickels << std::endl;
    std::cout << "Pennies: " << numOfPennies << std::endl;

}
