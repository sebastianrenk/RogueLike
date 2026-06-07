#include <vector>
#include <iostream>

std::vector<std::string> map {
    "##########",
    "#........#",
    "#........#",
    "#........#",
    "##########"
};

int main() {

    int playerX{};
    int playerY{};

    for (int y{0}; y < map.size(); ++y) {
        for (int x{0}; x < map.at(y).size(); ++x) {
            if (x == playerX && y == playerY)
                std::cout << "@";
            else
                std::cout << map.at(y).at(x);
        }
        std::cout << '\n';
    }

    return 0;
}