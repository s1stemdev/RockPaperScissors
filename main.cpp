#include <iostream>
#include <random>

using namespace std;

string variants[3] = { "rock", "paper", "scissors" };

random_device dev;
uniform_int_distribution<int> dist(0, 2);

string get_result(string player, string computer) {

    if(player == computer) return "Draw";
    if(player == variants[2] && computer == variants[1]) return "You win!";
    if(player == variants[1] && computer == variants[0]) return "You win!";
    if(player == variants[0] && computer == variants[2]) return "You win!";

    else return "You lose!";
}

int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
        cout << "Your move! (rock, paper, scissors) ''cancel'' to exit: ";

        string player_move;
        cin >> player_move;

        if(player_move == "cancel") return 1;

        string computer_move = variants[dist(dev)];
        cout << computer_move << endl;

        cout << get_result(player_move, computer_move) << endl << endl;
    }
    return 0;
}

