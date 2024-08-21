#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Player {
public:
    string playerName;
    int amount;
    Player(const string& name, int initialAmount) : playerName(name), amount(initialAmount) {}
    void displayBalance() const {
        cout << "\n\nYour current balance is $ " << amount << "\n";
    }
    bool hasEnoughMoney(int bettingAmount) const {
        return bettingAmount <= amount;
    }
    void deductAmount(int bettingAmount) {
        amount -= bettingAmount;
    }
    void addAmount(int winningAmount) {
        amount += winningAmount;
    }
    bool hasMoney() const {
        return amount > 0;
    }
    void savePlayerData() const {
        ofstream file("player_data.txt");
        if (file.is_open()) {
            file << playerName << " " << amount << "\n";
            file.close();
            cout << "Player data saved successfully.\n";
        } else {
            cout << "Unable to save player data.\n";
        }
    }

    // Function to load player data from a file
    void loadPlayerData() {
        ifstream file("player_data.txt");
        if (file.is_open()) {
            file >> playerName >> amount;
            file.close();
            cout << "Player data loaded successfully.\n";
        } else {
            cout << "Unable to load player data. Starting with default values.\n";
        }
    }
    ~Player() {
        savePlayerData();
        cout << playerName << " is leaving the game." << endl;
    }
};
class CasinoGame {
public:
    static void drawLine(int n, char symbol) {
        for (int i = 0; i < n; i++)
            cout << symbol;
        cout << "\n";
    }
    static void rules() {
        system("cls");
        cout << "\n\n";
        drawLine(80, '-');
        cout << "\t\tRULES OF THE GAME\n";
        drawLine(80, '-');
        cout << "\t1. Choose any number between 1 to 10\n";
        cout << "\t2. If you win, you will get 10 times the money you bet\n";
        cout << "\t3. If you bet on the wrong number, you will lose your betting amount\n\n";
        drawLine(80, '-');
    }
    static int generateRandomNumber() {
        return rand() % 10 + 1;
    }
    static char playAgain() {
        char choice;
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
        return choice;
    }
    static void displayFinalMessage(int amount) {
        cout << "\n\n\n";
        cout << "\n  ==================================================================================================\n";
	    cout << "\t\t     Thanks for playing the game. Your balance amount is $ " << amount ;
	    cout << "\n  ==================================================================================================\n";
    }
        
    static void playGame(Player& player) {
        int bettingAmount;
        int guess;
        int dice;
        char choice;
        do {
            system("cls");
            rules();
            player.displayBalance();
            do {
                cout << player.playerName << ", enter money to bet: $";
                cin >> bettingAmount;
                if (!player.hasEnoughMoney(bettingAmount))
                    cout << "Your betting amount is more than your current balance\n"
                         << "\nRe-enter data\n ";
            } while (!player.hasEnoughMoney(bettingAmount));
            do {
                cout << "Guess your number to bet between 1 to 10: ";
                cin >> guess;
                if (guess <= 0 || guess > 10)
                    cout << "Please check the number!! should be between 1 to 10\n"
                         << "\nRe-enter data\n ";
            } while (guess <= 0 || guess > 10);
            dice = generateRandomNumber();
            if (dice == guess) {
                cout << "\n\nGood Luck!! You won $ " << bettingAmount * 10;
                player.addAmount(bettingAmount * 10);
            } else {
                cout << "Bad Luck this time!! You lost $ " << bettingAmount << "\n";
                player.deductAmount(bettingAmount);
            }
            cout << "\nThe winning number was: " << dice << "\n";
            cout << "\n" << player.playerName << ", You have $ " << player.amount << "\n";
            if (!player.hasMoney()) {
                cout << "You have no money to play ";
                break;
            }
            choice = playAgain();
        } while (choice == 'Y' || choice == 'y');
    }
};
int main() {
    cout << "\n  ==================================================================================================";
	cout << "\n\t\t    CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	cout << "\n\t\t  CC          A  A      SS             III     NN N   NN   OO      OO    ";
	cout << "\n\t\t CC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
	cout << "\n\t\t  CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
	cout << "\n\t\t    CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
	cout << "\n  ==================================================================================================\n";
	
    string playerName;
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
    int initialAmount;
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> initialAmount;
    Player player(playerName, initialAmount);
    player.loadPlayerData(); 
    CasinoGame::playGame(player);
    CasinoGame::displayFinalMessage(player.amount);

    return 0;
}
