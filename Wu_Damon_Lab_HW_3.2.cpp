// Damon Wu 
// 10/18/2024
// Hw 3 pt 2

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main(){
    ifstream infile;
    ofstream offile;

    infile.open("moni.txt");
    if (!infile){
        cout << "Can't read data, terminating sequence \n";
        return 1;
    }

    offile.open ("statements.txt");
    offile << fixed << showpoint << setprecision(2);

    char request;      // the request on whether to continue or not
    double start;      // starting money
    int numtrans;      // number of transactions
    double amttrans;   // the value of each transaction
    double total;      // value used to determine current value
    char type;         // the type of transaction

    // money amounts 
    double dtotal = 0;
    double wtotal = 0;

    infile >> total;
    cout << "Your current total is $" << total << ". \n";
    offile << "Starting Balance: $" << total << "\n\n";

    // Print headers for the table
    offile << "Type" << setw(15) << "Amount" << setw(15) << "Balance \n";
    offile << "------------------------------------------\n";

    while (infile >> type >> amttrans){  // process each transaction

        switch (type) {
            case 'W': // Withdrawal
                cout << "Withdrawing $" << amttrans << "\n";
                total -= amttrans;
                wtotal += amttrans;
                break;

            case 'D': // Deposit
                cout << "Depositing $" << amttrans << "\n";
                total += amttrans;
                dtotal += amttrans;
                break;

            default:
                cout << "Unknown transaction type, skipping...\n";
                break;
        }

        // Output to console and file
        cout << "$" << total << endl;
        offile << type << setw(15) << amttrans << setw(15) << total << "\n";
    }

    // After processing all transactions, print the total deposits and withdrawals
    offile << "\nTotal Deposited: $" << dtotal << "\n";
    offile << "Total Withdrawn: $" << wtotal << "\n";
    offile << "Final Balance: $" << total << "\n";

    infile.close();
    offile.close();

    return 0;
}