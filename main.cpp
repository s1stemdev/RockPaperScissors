#include <iostream>
#include <random>

using namespace std;

string variants[3] = { "камень", "бумага", "ножницы" };

random_device dev;
uniform_int_distribution<int> dist(0, 2);

string get_result(string player, string computer) {

    if(player == computer) return "Ничья";
    if(player == variants[2] && computer == variants[1]) return "Вы выиграли!";
    if(player == variants[1] && computer == variants[0]) return "Вы выиграли!";
    if(player == variants[0] && computer == variants[2]) return "Вы выиграли!";

    else return "Вы проиграли!";
}

int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
        cout << "Ваш ход! (камень, бумага, ножницы) ''выход'' для выхода: ";

        string player_move;
        cin >> player_move;

        if(player_move == "выход") return 1;

        string computer_move = variants[dist(dev)];
        cout << computer_move << endl;

        cout << get_result(player_move, computer_move) << endl << endl;
    }
    return 0;
}

