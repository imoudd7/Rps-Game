#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enScore {
    PlayerVictory = 1, PcVictory = 2, Draw = 3
};
enum enTools {
    Stone = 1, Paper = 2, Scissors = 3
};


int RandomNumber(int from, int to) {
    int RandNum = rand() % (to - from + 1) + from;
    return RandNum;
}
int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
}

int RoundsCounter() {
    return ReadPositiveNumber("How Many Rounds 1 to 10 ? ");
}
void PrintHeader(int rounds) {
    cout << "Playing " << rounds << " rounds:" << endl;
}

enTools ComputerChoice() {
    int Choice = RandomNumber(1, 3);

    if (Choice == 1) {
        return enTools::Stone;
    }
    else if (Choice == 2) {
        return enTools::Paper;
    }
    else {
        return enTools::Scissors;
    }
}
void PrintComputerChoice(enTools choice) {
    if (choice == enTools::Stone) {
        cout << "Computer Choice: Stone" << endl;
    }
    else if (choice == enTools::Paper) {
        cout << "Computer Choice: Paper" << endl;
    }
    else {
        cout << "Computer Choice: Scissors" << endl;
    }
}

enTools PlayerChoice() {
    int x;

    do {
        cout << "Your Choice: [1]: Stone, [2] Paper, [3] Scissors ?" << endl;
        cin >> x;
    } while (x < 1 || x > 3);

    if (x == 1) {
        return enTools::Stone;
    }
    else if (x == 2) {
        return enTools::Paper;
    }
    else {
        return enTools::Scissors;
    }
}
void PrintPlayerChoice(enTools choice) {
    if (choice == enTools::Stone) {
        cout << "Player Choice: Stone" << endl;
    }
    else if (choice == enTools::Paper) {
        cout << "Player Choice: Paper" << endl;
    }
    else {
        cout << "Player Choice: Scissors" << endl;
    }
}

enScore CompareTheChoices(enTools playerChoice, enTools computerChoice) {
    if (playerChoice == computerChoice) {
        return enScore::Draw;
    }
    else if ((playerChoice == enTools::Stone && computerChoice == enTools::Scissors) ||
        (playerChoice == enTools::Paper && computerChoice == enTools::Stone) ||
        (playerChoice == enTools::Scissors && computerChoice == enTools::Paper)) {
        return enScore::PlayerVictory;
    }
    else {
        return enScore::PcVictory;
    }
}
void PrintScore(enScore result) {
    if (result == enScore::PlayerVictory) {
        cout << system("color 20") << "Round Winner: [Player1]" << endl;
    }
    else if (result == enScore::PcVictory) {
        cout << system("color 40") << " \a Round Winner: [Computer]" << endl;
    }
    else {
        cout << system("color E0") << "Round Winner: [No Winner]" << endl;
    }
}

struct stCounters
{
    int PlayerWon = 0;
    int PcWon = 0;
    int Draw = 0;
};

void FinalWinner(stCounters Counters)
{
    if (Counters.PlayerWon > Counters.PcWon)
    {
        cout << "\t\tFinal Winner: Player" << endl;
    }
    else if (Counters.PlayerWon < Counters.PcWon)
    {
        cout << "\t\tFinal Winner: Copmuter" << endl;
    }
    else if (Counters.PlayerWon == Counters.PcWon)
    {
        cout << "\t\tFinal Winner: No Winner" << endl;
    }
}

void GameResult(int rounds, stCounters Counters)
{


    cout << "\t\t___________________________________________________________________________" << endl << endl;
    cout << "\t\t\t\t\t\t G A M E   O V E R \t\t\t\t" << endl;
    cout << "\t\t___________________________________________________________________________" << endl << endl;
    cout << "\t\t______________________________[Game Results]_______________________________" << endl << endl;


    int Count = 0;
    for (int i = 1; i <= rounds; i++)
    {
        Count++;
    }
    cout << "\t\tGame Rounds: " << Count << endl;
    cout << "\t\tPlayer Won: " << Counters.PlayerWon << endl;
    cout << "\t\tCopmuter Won: " << Counters.PcWon << endl;
    cout << "\t\tDraw times: " << Counters.Draw << endl;
    FinalWinner(Counters);
    cout << "\t\t___________________________________________________________________________" << endl << endl;
}

void PlayRounds(int rounds)
{
    stCounters Count = {};

    for (int i = 1; i <= rounds; i++) {
        cout << "____________________Round[" << i << "]____________________" << endl << endl;

        enTools playerChoice = PlayerChoice();
        enTools computerChoice = ComputerChoice();

        PrintPlayerChoice(playerChoice);
        PrintComputerChoice(computerChoice);

        enScore roundResult = CompareTheChoices(playerChoice, computerChoice);
        PrintScore(roundResult);

        cout << "________________________________________________" << endl << endl;

        if (roundResult == enScore::PlayerVictory)
        {
            Count.PlayerWon++;
        }
        else if (roundResult == enScore::PcVictory)
        {
            Count.PcWon++;
        }
        else
        {
            Count.Draw++;
        }
    }

    GameResult(rounds, Count);
}


int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    int rounds = RoundsCounter();
    PrintHeader(rounds);
    PlayRounds(rounds);

    return 0;
}