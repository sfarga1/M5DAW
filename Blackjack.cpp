#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// constante que delimita el max de cada palo
const int MAXCARDS = 13;
string nameSuit;

// Palo aleatorio y palos en total random
int randomSuit, randomCard;
const int totalSuits = 4;
// Definición del array                                      //10  J   Q   K
int cards[totalSuits][MAXCARDS] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                   {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}};

// Definición de los puntos de los dos jugadores
int playerTotalPoints = 0, croupierTotalPoints = 0;

// Nueva carta que se entrega
int newCard;

// decision 1 u 11 y valor de la carta
int decisionAce, aceCardValue;

//turno de la partida
int turn = 1;

void mainMenu()
{
    cout << "///////////////////////////////////////////////////";
    cout << "\n-------------------- BLACKJACK --------------------\n";
    cout << "///////////////////////////////////////////////////\n\n\n\n";
    cout << "Game made by MARC MARQUES and SERGI FARGA\n\n\n\n";

    cout << "Press any key to continue";
    cin.get();
    system("cls");

    cout << "//////////////////////////////////////////////////////";
    cout << "\n-------------------- INTRODUCTION --------------------\n";
    cout << "//////////////////////////////////////////////////////\n\n\n\n";
    cout << "Welcome to the Blackjack game developed by Marc and Sergi, the awesome team from 1 DAW (monlau).\n\n";
    cout << "This Blackjack is a card game that consists of a match between the player and a Croupier.\n\n";
    cout << "There is only one deck with four suits, each one containing a total of 13 cards.\n\n";
    cout << "Out of those 13 cards, the first one is an Ace. If you get an Ace, you get to choose between a value of 1 or 11 points.\n\n";
    cout << "2 to 10 are normal cards, which add to the total score the numerical equivalent of the specific number of the card.\n\n";
    cout << "For example, if you get a 3 of hearts you get 3 points added to your total points.\n\n";
    cout << "11 to 13 are J, Q and K respectively. All of them add 10 points to the total score.\n\n";
    cout << "In the first turn, the player gets 2 cards and the croupier 1. In the other turns both get only 1 card.\n\n";
    cout << "In order to win, you need to get to number 21, no more no less.\n\nIf you get a total score higher than 21, you lose.\n\n";
    cout << "If the croupier gets a score of 21 before you, you lose.\n\n";
    cout << "The opposite is also true. If the croupier surpases a score of 21 before you do, you win.\n\nIf you get a score of 21 beofre the croupier does, you win.\n\n";
    cout << "If both the player and the croupier get a score higher than 21 in the same turn, the croupier wins.\n\n";
    cout << "A draw may occur if both the player and the croupier end a turn with 21 points, though it is a rare scenario.\n\n\n\n";

    cout << "Press any key to continue";
    cin.get();
    system("cls");
}

void randomizedArrays()
{
    int cont = 4;
    do
    {
        randomSuit = rand() % 4;
        randomCard = rand() % MAXCARDS;
        //if (cont > 0) {//esto es para forzar que salgan ases al principio para comprobar bug
        //    randomCard = 0; //en el bug, me toca as de a y suma bien, luego as de b y suma bien, luego no muestra turno del croupier y me vuelve a tocar a mi, y a veces en este punto deja de sumar bien, locura
        //    cont--;
        //}
        ////cout << "randomSuit " << randomSuit << "\n randomCard " << randomCard << "\n";
        ////cout << "newCard = " << cards[randomSuit][randomCard] << "\n";
        ////cout << "newCardAce = " << cards[randomSuit][0] << "\n";
        
    } while (cards[randomSuit][randomCard] == 0);

    switch (randomSuit)
    {
    case 0:
        newCard = cards[randomSuit][randomCard]; // valor de la carta en la posición que toque
        cards[randomSuit][randomCard] = 0;
        break;
    case 1:
        newCard = cards[randomSuit][randomCard]; // valor de la carta en la posición que toque
        cards[randomSuit][randomCard] = 0;
        break;
    case 2:
        newCard = cards[randomSuit][randomCard]; // valor de la carta en la posición que toque
        cards[randomSuit][randomCard] = 0;
        break;
    case 3:
        newCard = cards[randomSuit][randomCard]; // valor de la carta en la posición que toque
        cards[randomSuit][randomCard] = 0;
        break;
    }
    //return newCard; // ESTA FUNCION DEVUELVE EL VALOR DE LA CARTA Y ELIMINA DE LA BARAJA EL VALOR DEL PALO CORRESPONDIENTE
}

string showSuit()
{
    string suits[] = { "diamonds", "clubs", "hearts", "spades" };
    string nameSuit = suits[randomSuit];
    return nameSuit;
}

string showAceJQK()
{
    string nameAceJQK;

    if (cards[randomSuit][randomCard] == cards[randomSuit][0])
    {
        nameAceJQK = "Ace";
    }
    else if (cards[randomSuit][randomCard] == cards[randomSuit][10])
    {
        newCard -= 1;
        nameAceJQK = "J";
    }
    else if (cards[randomSuit][randomCard] == cards[randomSuit][11])
    {
        newCard -= 2;
        nameAceJQK = "Q";
    }
    else if (cards[randomSuit][randomCard] == cards[randomSuit][12])
    {
        newCard -= 3;
        nameAceJQK = "K";
    }

    return nameAceJQK;
}

bool isAceJQK()
{
    if (newCard == 1 || newCard == 11 || newCard == 12 || newCard == 13)
    {
        return true;
    }
    else
        return false;
}

bool isAce()
{
    if (newCard == 1)
    {
        return true;
    }
    else
        return false;
}

int decisionWhenAce()
{
    cout << "Player total points: " << playerTotalPoints << endl << endl;
    cout << "Croupier total points: " << croupierTotalPoints << endl << endl;//prueba
    cout << "What value do you prefer for your Ace?\n[1] - 1\n[2] - 11\n";
    cin >> decisionAce;

    switch (decisionAce)
    {
    case 1:
        aceCardValue = 1;
        cout << "\nYour ace got a value of " << aceCardValue << endl << endl;
        break;
    case 2:
        aceCardValue = 11;
        cout << "\nYour ace got a value of " << aceCardValue << endl << endl;
    }
    return aceCardValue;
}

int croupierAceDecision()
{
    if (croupierTotalPoints + 11 <= 21)
    {
        aceCardValue = 11;
        cout << "\nCropier's ace got a value of " << aceCardValue << endl << endl;
    }
    else
    {
        aceCardValue = 1;
        cout << "\nCropier's ace got a value of " << aceCardValue << endl << endl;
    }
    return aceCardValue;
}

void gameStart()//al coger el usuario la segunda carta as, al croupier se le suman siempre 11 puntos y se salta su primer turno
{
    //system("cls");
    // Primeras dos cartas Player
    cout << "TURN " << turn << endl << endl << endl << endl;
    turn++;
    // Player start
    for (int i = 0; i < 2; i++)
    {
        randomizedArrays();

        if (isAceJQK())
        {
            cout << "You got a " << showAceJQK() << " of " << showSuit() << "\n\n";
        }
        else
        {
            cout << "You got a " << newCard << " of " << showSuit() << "\n\n";
        }

        if (isAce())
        {
            decisionWhenAce();
            playerTotalPoints += aceCardValue;
        }
        else
        {
            playerTotalPoints += newCard;
        }
    }
    cout << "Player total points: " << playerTotalPoints << endl << endl;//puedo simplificar en funcion
    cout << "Croupier total points: " << croupierTotalPoints << endl << endl;//prueba
    // Croupier start
    randomizedArrays();

    if (isAceJQK())
    {
        //cout << "test" << endl;
        cout << "Croupier got a " << showAceJQK() << " of " << showSuit() << "\n\n";
    }
    else
    {
        cout << "Croupier got a " << newCard << " of " << showSuit() << "\n\n";
    }

    if (isAce())//Creo que el error está aquí. En el segundo turno el croupier detecta un as y le asigna siempre un 11
    {
        croupierAceDecision();
        croupierTotalPoints += aceCardValue;
    }
    else
    {
        croupierTotalPoints += newCard;
    }

    cout << "Player total points: " << playerTotalPoints << endl << endl;
    cout << "Croupier total points: " << croupierTotalPoints << endl << endl;

    // Enter press before both next turn
    cout << "Press enter for next turn...";
    // cin.ignore();
    cin.get();
    //system("cls");
}

void gameLoop()
{
    while (playerTotalPoints < 21 && croupierTotalPoints < 21)
    {
        // Player turn
        randomizedArrays();
        cout << "\n\nTURN " << turn << endl << endl << endl << endl;
        turn++;
        if (isAceJQK())
        {
            cout << "You got a " << showAceJQK() << " of " << showSuit() << "\n\n";
        }
        else
        {
            cout << "You got a " << newCard << " of " << showSuit() << "\n\n";
        }

        if (isAce())
        {
            decisionWhenAce();
            playerTotalPoints += aceCardValue;
        }
        else
        {
            playerTotalPoints += newCard;
        }
        cout << "Player total points: " << playerTotalPoints << endl << endl;
        cout << "Croupier total points: " << croupierTotalPoints << endl << endl;//prueba

        // Croupier turn
        randomizedArrays();

        if (isAceJQK())
        {
            cout << "Croupier got a " << showAceJQK() << " of " << showSuit() << "\n\n";
        }
        else
        {
            cout << "Croupier got a " << newCard << " of " << showSuit() << "\n\n";
        }

        if (isAce())
        {
            croupierAceDecision();
            croupierTotalPoints += aceCardValue;
        }
        else
        {
            croupierTotalPoints += newCard;
        }

        cout << "Player total points: " << playerTotalPoints << endl << endl;
        cout << "Croupier total points: " << croupierTotalPoints << endl << endl;

        // Enter press before both next turn
        cout << "Press enter for next turn...";
        // cin.ignore();
        cin.get();
        //system("cls");
    }
}

void gameEnd() {

    cout << "\n\nThe game has ended.\n\nYou got " << playerTotalPoints << " points, and the Croupier got " << croupierTotalPoints << endl << endl;

    if (playerTotalPoints == 21 && (croupierTotalPoints != 21))
    {
        cout << "Congratulations, you won the game!!!" << endl << endl;
    }
    else if ((playerTotalPoints == 21) && (croupierTotalPoints == 21))
    {
        cout << "Seems like both you and the Croupier got the same points." << endl << endl;
    }
    else if ((playerTotalPoints <= 21) && (croupierTotalPoints > 21))
    {
        cout << "Congratulations, you won the game!!!" << endl << endl;
    }
    else {
        cout << "The Croupier won the game. You lost." << endl << endl;
    }
}

int main()
{
    srand(time(NULL));
    mainMenu();
    gameStart();
    gameLoop();
    gameEnd();
}