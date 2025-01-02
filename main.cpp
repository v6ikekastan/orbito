#include "Funktionen.h"
#include "Spielfeldfunktionen.h"
#include "Fehleingaben.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Spiel Orbito

using namespace std;

string spielfeldarray[fg][fg]{
    {"00", "01", "02", "03"},
    {"10", "11", "12", "13"},
    {"20", "21", "22", "23"},
    {"30", "31", "32", "33"}
};


int main(){
srand(time(0));
cout << highscoreAbrufen() << endl;
highscoreEintragen(highscoreAbrufen() + 1);


string spieler1;
string spieler2;
cout << "Name von Spieler 1 eingeben: ";
checkEingabe(spieler1); //Funktion wird aufgerufen
cout << "Name von Spieler 2 eingeben: ";
checkEingabe(spieler2); //Funktion wird aufgerufen
if (spieler2 == "Computer" || spieler2 == "computer"){
    cout << "test" << endl;

} else {
    cout << "Wilkommen " << spieler1 << " und " << spieler2 << endl; //LAURA dachte das w鋜e ganz nett :)
}
    
//Spielfeld:
cout << "Startspielfeld:" << endl;
spielfelderstellen(spielfeldarray);

for (int i = 0; i < 8; i++){

    spielzug1(spielfeldarray, spieler1);
    spielfelderstellen(spielfeldarray);
    spielfeldrotierenUhr(spielfeldarray);
    spielzug2(spielfeldarray, spieler2);
    spielfelderstellen(spielfeldarray);
    spielfeldrotierenUhr(spielfeldarray);
    if (checksieg(spielfeldarray) == true){
        break;
    }
}




return 0;
}

