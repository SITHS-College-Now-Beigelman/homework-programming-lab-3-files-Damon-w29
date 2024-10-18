// Damon Wu
// 10/15/2024
// HW 3 pt 2 

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main(){
    ifstream infile;
    ofstream offile;

    infile.open("moni.txt");
    offile.open("statements.txt");

    char request;      // the request on whether to continue or not. 
    double start;      // starting money.
    int numtrans;      // number of transactions.
    double amttrans;   // the value of each transaction.
    double total;      // value used to determine current value .
    char type;         // the type of transcation.

    // money amounts 
    double dtotal = 0;
    double wtotal = 0;

    if (!infile){
        cout << "Cant read data, terminating sequence \n";
        return 1;
    }

    offile.open ("statements.txt");
    offile << fixed << showpoint << setprecision(2);

    infile >> total;
    cout << "Your current total is $" << total << ". \n";
    while (infile){

        infile >> type >> amttrans;
        switch (type) // reads the type
    {
        case 'W': // if the type is "W", then reduce from the total the amount, after, break the cycle and loop it.
                cout << "Withdrawing $" << amttrans << "\n";
                total -= amttrans;
                wtotal += amttrans + wtotal;
         break;
        case 'D': // if they type is "D, then increase the current total by the amount, break the cycle then loop it."
                cout << "Depositing $" << amttrans << "\n";
                total += amttrans; 
                dtotal += amttrans + dtotal;
         break;
        default:
            break;
    }
    // after determining the case and figuring out what happens, print out the new amount, then go back to the start of determining the case. 
    cout << "$" << total << endl;
    }
    offile << endl;
    cout << "Type" << setw(15) << "Amount" << setw(15) << "Balance \n";
    cout << type << setw(15) << amttrans << setw(15) << total << "\n";

    

return 0;
}