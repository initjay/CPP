// Program that creates two gladiators which battle
// until one is defeated.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
// gladiator stats
struct Gladiator {
  string name;
  int maxHealth,
      currentHealth,
      evasion,
      critical,
      minDamage,
      damRange;
};

void assignMaxHealth(Gladiator &);
void assignEvasion(Gladiator &);
void assignCrit(Gladiator &);
void assignMinDamage(Gladiator &);
void assignDamageRange(Gladiator &);
Gladiator createGladiator(string a);
void showStats(Gladiator &);
void takeTurn(Gladiator, Gladiator &);
int menu();

const int ARR_HEALTH[3] = {150,200,250}; // gloabl array of health types;
const int ARR_EVASIONANDCRIT[3] = {5, 10, 15}; // global array of evasion and crit types;

int main() {
  // setting seed to current unix time for randomness
  unsigned seed = time(0);
  srand(seed);
  string userName, opponentName;
  // hold user choice for future menu, starting with creation of gladiators
  int menuChoice = 2;
  // initialize to no so while loop runs
  char choice = 'n';
  // create gladiators
  Gladiator gladiator1, gladiator2;
  // turn counter
  int currentTurn;
  // intro
  cout << "\nPrepare to host a gladiator battle!\n";
  // get past cin.ignore
  cout << "Press enter to continue.\n";

  while(menuChoice != 3){
    switch(menuChoice){
      case 1:
        // reset health
        gladiator1.currentHealth = gladiator1.maxHealth;
        gladiator2.currentHealth = gladiator2.maxHealth;
        // initialize turn counter
        currentTurn = 1;
        // clear keyboard buffer
        cin.ignore();
        // loop to continually run battle until one gladiator dies
        while(gladiator1.currentHealth > 0 && gladiator2.currentHealth > 0){
          // display turn num to user
          cout << "\nTurn # " << currentTurn << endl;
          cout << "Press enter to continue.";
          cin.get();
          // attack turn
          takeTurn(gladiator1, gladiator2);
          // end loop if gladiator2 is defeated
          if(gladiator2.currentHealth <= 0){
            continue;
          }
          // attack turn
          takeTurn(gladiator2, gladiator1);
          currentTurn++;
        }
        // display the victor
        if(gladiator1.currentHealth <= 0){
          cout << endl << gladiator1.name
               << " was defeated!\n"
               << gladiator2.name << " is the winner!\n";
        }
        else {
          cout << endl << gladiator2.name
               << " was defeated!\n"
               << gladiator1.name << " is the winner!\n";
        }
        // get users choice again
        menuChoice = menu();
        break;

      case 2:
        // clear keyboard buffer
        cin.ignore();
        // initialize to no so while loop runs
        choice = 'n';
        // get gladiator name from user
        cout << "\nChoose a name for your Gladiator.\n";
        getline(cin, userName);
        // create and display gladiator
        while(toupper(choice) == 'N'){

          gladiator1 = createGladiator(userName);
          showStats(gladiator1);
          // create new gladiator if user chooses to
          cout << "\nDo you wish to continue with this Gladiator? "
               << "Y or N: ";
          cin >> choice;
        }
        // clear keyboard buffer
        cin.ignore();
        // reset choice
        choice = 'n';
        // get opponent gladiator name from user
        cout << "\nChoose a name for your opponent.\n";
        getline(cin, opponentName);
        // create and display gladiator
        while(toupper(choice) == 'N'){

          gladiator2 = createGladiator(opponentName);
          showStats(gladiator2);
          // create new gladiator if user chooses to
          cout << "\nDo you wish to continue with this Gladiator? "
               << "Y or N: ";
          cin >> choice;
        }
        // initialize turn counter
        currentTurn = 1;
        // clear keyboard buffer
        cin.ignore();
        // loop to continually run battle until one gladiator dies
        while(gladiator1.currentHealth > 0 && gladiator2.currentHealth > 0){
          // display turn num to user
          cout << "\nTurn # " << currentTurn << endl;
          cout << "Press enter to continue.";
          cin.get();
          // attack turn
          takeTurn(gladiator1, gladiator2);
          // end loop if gladiator2 is defeated
          if(gladiator2.currentHealth <= 0){
            continue;
          }
          // attack turn
          takeTurn(gladiator2, gladiator1);
          currentTurn++;
        }
        // display the victor
        if(gladiator1.currentHealth <= 0){
          cout << endl << gladiator1.name
               << " was defeated!\n"
               << gladiator2.name << " is the winner!\n";
        }
        else {
          cout << endl << gladiator2.name
               << " was defeated!\n"
               << gladiator1.name << " is the winner!\n";
        }
        // get users choice again
        menuChoice = menu();
        break;

      default: cout << "\nPlease enter a choice 1 - 4:";
               menuChoice = menu();
    }
  }
  cout << "\nGame Over.\n";

  return 0;
}

void assignMaxHealth(Gladiator &glad) {
  int healthIndex = rand() % 3;
  glad.maxHealth = ARR_HEALTH[healthIndex];
  glad.currentHealth = glad.maxHealth;
}

void assignEvasion(Gladiator &glad) {
  int evasionIndex = rand() % 3;
  glad.evasion = ARR_EVASIONANDCRIT[evasionIndex];
}

void assignCrit(Gladiator &glad){
  int critIndex = rand() % 3;
  glad.critical = ARR_EVASIONANDCRIT[critIndex];
}

void assignMinDamage(Gladiator &glad){
  glad.minDamage = rand() % 7 + 8; // sets range from 8 to 14
}

void assignDamageRange(Gladiator &glad){
  glad.damRange = rand() % 7 + 16; // sets range from 16 - 22
}

Gladiator createGladiator(string a)
{
  Gladiator tempG;
  tempG.name = a;
  assignMaxHealth(tempG);
  assignEvasion(tempG);
  assignCrit(tempG);
  assignMinDamage(tempG);
  assignDamageRange(tempG);
  return tempG;
}

void showStats(Gladiator &tempG){
  cout << endl << "Name: " << tempG.name << endl
       << "Max Health: " << tempG.maxHealth << endl
       << "Current Health: " << tempG.currentHealth << endl
       << "Evasion: " << tempG.evasion << endl
       << "Critical: " << tempG.critical << endl
       << "Minimum Damage: " << tempG.minDamage << endl
       << "Damage Range: " << tempG.damRange << endl
       << "Total Damage Range is: "
       << tempG.minDamage << '-'
       << tempG.minDamage + tempG.damRange
       << endl;
}

void takeTurn(Gladiator attack, Gladiator& defense){
  //display attacker's and defender's current health
  cout << endl << attack.name << " current health is: "
       << attack.currentHealth << endl
       << defense.name << " current health is: "
       << defense.currentHealth << endl << endl
       << attack.name << " will attack "
       << defense.name << "!\n";

  // hold current turns stats
  int turnCrit, turnEvade, turnDamage;
  // calculate turn's damage, crit, and evasion
  turnCrit = (rand() % 100) + 1;
  turnEvade = (rand() % 100) + 1;
  turnDamage = (rand() % (attack.damRange + 1)) + attack.minDamage;
  // apply crit
  if (turnCrit <= attack.critical){
    turnDamage *= 2;
  }
  // if evade, exit turn
  if (turnEvade <= defense.evasion) {
    cout << defense.name << " DODGED "
         << attack.name << " attack of: " << turnDamage
         << "!\n";
    return; // exits function
  }
  if (turnCrit <= attack.critical){
    cout << "\nCRITICAL HIT!!\n";
  }
  // if not evaded apply damage
  defense.currentHealth -= turnDamage;
  cout << defense.name << " took " << turnDamage
       << " damage from " << attack.name << "!\n";
}

int menu(){
  int choice;

  cout << "\nWould you like another fight?\n"
       << "1. Rematch with the same fighters.\n"
       << "2. Rematch with new fighters.\n"
       << "3. Exit.\n";
  cin >> choice;
  return choice;
}
