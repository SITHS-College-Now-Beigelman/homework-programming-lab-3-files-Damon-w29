// Damon Wu
// 10/15/2024
// HW 3 

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main(){
    // allows taking in info from a doc
    ifstream infile;

    // takes info from doc "moni" like Mr.Krabs
    infile.open("moni.txt");

    char request;      // the request on whether to continue or not. 
    double start;      // starting money.
    int numtrans;      // number of transactions.
    double amttrans;   // the value of each transaction.
    double total;      // value used to determine current value .
    char type;         // the type of transcation.

    // takes in the total then prints a statements that prints the total
    infile >> total;
    cout << "Your current total is $" << total << ". \n";

    // a for loop that determines the number of transactions
for (numtrans = 0; numtrans <= 6; numtrans++){

    // takes the type of file and amount of each transactions
    infile >> type >> amttrans;
    switch (type) // reads the type
    {
        case 'W': // if the type is "W", then reduce from the total the amount, after, break the cycle and loop it.
                cout << "Withdrawing $" << amttrans << "\n";
                total -= amttrans;
         break;
        case 'D': // if they type is "D, then increase the current total by the amount, break the cycle then loop it."
                cout << "Depositing $" << amttrans << "\n";
                total += amttrans; 
         break;
        default:
            break;
    }
    // after determining the case and figuring out what happens, print out the new amount, then go back to the start of determining the case. 
    cout << "$" << total << endl;
}
// after all numbers of transactions is calculated, print the remaining total, then end the code. 
cout << "Your remainding total is $" << total << "\n";
return 0;

    /*
    Your current total is $5000.  
    Withdrawing $200
    $4800
    Withdrawing $800
    $4000
    Withdrawing $40
    $3960
    Depositing $90
    $4050
    Depositing $100
    $4150
    Depositing $1000
    $5150
    Withdrawing $20
    $5130
    Your remainding total is $5130
    */
}