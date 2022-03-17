// Elo rating system

#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

enum game_result
{
    WIN,
    DRAW,
    LOSE,
};

typedef pair<double, string> Player;

class List_manager
{
private:
    vector<Player> list;

    Player &search(string name)
    {
    }

    void sort_list()
    {

        ranges::sort(list);
    }

    void calculate(Player &player, Player &opponent, double game_result)
    {
        double winlate = 1 / (pow(10, (player.first - opponent.first) / 400) + 1);

        player.first = player.first + k * (game_result - winlate);
    }

public:
    int k;

    void add_player(string name)
    {
        list.push_back(Player{0, name});
    }

    void add_game_result(string first, string second, game_result is_first_won)
    {
        switch (is_first_won)
        {
        case WIN:
            calculate(search(first), search(second), 1);
            calculate(search(second), search(first), 0);
            break;
        case DRAW:
            calculate(search(first), search(second), 0.5);
            calculate(search(second), search(first), 0.5);
            break;
        case LOSE:
            calculate(search(first), search(second), 0);
            calculate(search(second), search(second), 1);
            break;
        }
    }

    void show()
    {
        std::cout << "=======PLAYER RANKING LIST=======\n";
        for (auto player : list)
        {
            cout << player.second << ": " << player.first << "\n";
        }
        cout << endl;
    }
};

int main()
{
    List_manager list;
    list.k = 20;
    list.add_player("GU");
    list.add_player("CU");

    int input;
    while (true)
    {
        list.show();
        cin >> input;
    }
}
