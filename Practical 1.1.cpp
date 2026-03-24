#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;

public:
    Wallet() {
        walletID = 0;
        userName = "";
        balance = 0.0;
    }

    void createWallet() {
        cout << "Enter Wallet ID: ";
        cin >> walletID;
        cout << "Enter User Name: ";
        cin >> userName;
        cout << "Enter Initial Balance: Rs.";
        cin >> balance;
    }

    int getID() {
        return walletID;
    }

    void loadMoney() {
        double amount;
        cout << "Enter amount to load: Rs.";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount. Please enter a positive value.\n";
            return;
        }
        balance += amount;
        cout << "Rs." << amount << " loaded successfully into " << userName << "'s wallet.\n";
    }
    void transferMoney(Wallet &receiver) {
        double amount;
        cout << "Enter amount to transfer: Rs.";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return;
        }
        if (balance < amount) {
            cout << "Insufficient balance! Transfer failed.\n";
            return;
        }
        balance -= amount;
        receiver.balance += amount;
        cout << "Rs." << amount << " transferred from " << userName
             << " to " << receiver.userName << " successfully.\n";
    }

    void displayDetails() {
        cout << "\n--- Wallet Details ---\n";
        cout << "Wallet ID : " << walletID << "\n";
        cout << "User Name : " << userName << "\n";
        cout << "Balance   : Rs." << balance << "\n";
        cout << "----------------------\n";
    }
};

int main() {
    Wallet w1, w2;
    int choice;
    cout << "=== Create Wallet 1 ===\n";
    w1.createWallet();

    cout << "\n=== Create Wallet 2 ===\n";
    w2.createWallet();

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Load Money\n";
        cout << "2. Transfer Money\n";
        cout << "3. Display Wallet Details\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                cout << "Enter Wallet ID to load money (" << w1.getID() << " or " << w2.getID() << "): ";
                cin >> id;
                if (id == w1.getID())
                    w1.loadMoney();
                else if (id == w2.getID())
                    w2.loadMoney();
                else
                    cout << "Wallet not found!\n";
                break;
            }
            case 2: {
                int fromID;
                cout << "Enter Sender Wallet ID: ";
                cin >> fromID;
                if (fromID == w1.getID())
                    w1.transferMoney(w2);
                else if (fromID == w2.getID())
                    w2.transferMoney(w1);
                else
                    cout << "Wallet not found!\n";
                break;
            }
            case 3: {
                int id;
                cout << "Enter Wallet ID to display (" << w1.getID() << " or " << w2.getID() << "): ";
                cin >> id;
                if (id == w1.getID())
                    w1.displayDetails();
                else if (id == w2.getID())
                    w2.displayDetails();
                else
                    cout << "Wallet not found!\n";
                break;
            }
            case 4:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
