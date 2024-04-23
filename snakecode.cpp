#include <iostream>
#include <map>
#include <cstdlib>

std::map<int, int> snakes;
std::map<int, int> ladder;

int playgame(int x) {
    auto it = snakes.find(x);
    if (it != snakes.end()) {
        return it->second;
    } else {
        auto it1 = ladder.find(x);
        if (it1 != ladder.end()) {
            return it1->second;
        } else {
            return x;
        }
    }
}

int rollDie() {
    return rand() % 6 + 1;
}

int main() {
    snakes[17] = 7;
    snakes[32] = 20;
    snakes[54] = 34;
    snakes[62] = 19;
    snakes[98] = 79;

    ladder[12] = 80;
    ladder[15] = 28;
    ladder[63] = 99;
    ladder[55] = 68;
    ladder[78] = 90;

    int playercount = 0, computercount = 0;
    std::cout << "WELCOME" << std::endl;
    while (playercount < 100 && computercount < 100) {
        int roll;
        std::cout << "Enter a number between 1 to 6" << std::endl;
        std::cin >> roll;
        if(roll>6)
        {
            roll = roll%6;
        }
        playercount = playgame(playercount + roll);
        std::cout << "playercount"<<playercount << std::endl;
        if (playercount == 100) {
            std::cout << "HURRAY PLAYER1 WINS" << std::endl;
            break;
        }
        std::cout << "enter a number between 1 to 6" << std::endl;
        int roll1 = rollDie();
        std::cout << roll1 << "\n";
        computercount = playgame(computercount + roll1);
        std::cout << "computercount"<<computercount << std::endl;
        if (computercount == 100) {
            std::cout << "computer wins" << std::endl;
            break;
        }
    }

    return 0;
}
