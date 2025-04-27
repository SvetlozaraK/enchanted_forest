#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Function to display intro
void displayIntro() {
    cout << "Welcome to the Enchanted Forest Quest!" << endl;
    cout << "You are a brave adventurer seeking the lost Crystal of Light." << endl;
    cout << "Beware: the forest is full of monsters and magic!" << endl;
    cout << "Good luck, hero!" << endl << endl;
}

// Function to randomize encounters
string randomEncounter() {
    vector<string> encounters = {
        "a wild goblin appears!",
        "you find a sparkling healing fountain!",
        "a sneaky thief tries to steal your gold!",
        "you discover a hidden treasure chest!",
        "a giant spider descends from the trees!",
        "a friendly fairy offers you a blessing!"
    };
    return encounters[rand() % encounters.size()];
}
// Function to fight monster
bool fightMonster() {
    int playerHealth = 20;
    int monsterHealth = rand() % 15 + 10; // 10-25
    cout << "Battle Start!" << endl;

    while (playerHealth > 0 && monsterHealth > 0) {
        int playerAttack = rand() % 8 + 1; // 1-8
        int monsterAttack = rand() % 6 + 1; // 1-6
        monsterHealth -= playerAttack;
        playerHealth -= monsterAttack;

        cout << "You hit the monster for " << playerAttack << " damage." << endl;
        cout << "The monster hits you for " << monsterAttack << " damage." << endl;
        cout << "Your health: " << playerHealth << " | Monster health: " << monsterHealth << endl << endl;
    }

    if (playerHealth > 0) {
        cout << "You defeated the monster!" << endl;
        return true;
    } else {
        cout << "You have been defeated..." << endl;
        return false;
    }
}

// Main game loop
int main() {
    srand(time(0)); // Random seed
    displayIntro();

    string playerName;
    cout << "Enter your hero's name: ";
    getline(cin, playerName);

    int health = 30;
    int steps = 0;
    bool hasCrystal = false;

    cout << endl << "Your journey begins, " << playerName << "!" << endl;

    while (health > 0 && !hasCrystal) {
        cout << endl << "Choose an action:" << endl;
        cout << "1. Walk forward" << endl;
        cout << "2. Check health" << endl;
        cout << "3. Quit game" << endl;
        cout << "Enter choice (1-3): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            steps++;
            cout << endl << "You move deeper into the forest..." << endl;
            string encounter = randomEncounter();
            cout << "Suddenly, " <<
            encounter << endl;

            if (encounter.find("goblin") != string::npos || encounter.find("spider") != string::npos) {
                cout << "Prepare to fight!" << endl;
                if (!fightMonster()) {
                    break; // player died
                }
            } else if (encounter.find("healing fountain") != string::npos) {
                int heal = rand() % 10 + 5;
                health += heal;
                cout << "You healed for " << heal << " points! Current health: " << health << endl;
            } else if (encounter.find("thief") != string::npos) {
                cout << "The thief stole some of your health!" << endl;
                int damage = rand() % 5 + 3;
                health -= damage;
                cout << "You lost " << damage << " health. Current health: " << health << endl;
            } else if (encounter.find("treasure chest") != string::npos) {
                cout << "Inside the chest, you found the Crystal of Light!" << endl;
                hasCrystal = true;
                break;
            } else if (encounter.find("fairy") != string::npos) {
                cout << "The fairy blesses you! Maximum health increased!" << endl;
                health += 10;
            }
        } else if (choice == 2) {
            cout << "Your current health: " << health << endl;
        } else if (choice == 3) {
            cout << "You have chosen to leave the forest. Farewell, " << playerName << "!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again!" << endl;
        }
    }

    // Ending
    if (hasCrystal) {
        cout << endl << "Congratulations, " << playerName << "!" << endl;
        cout << "You have found the Crystal of Light and completed your quest!" << endl;
    } else if (health <= 0) {
        cout << endl << "Your journey has ended in the Enchanted Forest..." << endl;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
