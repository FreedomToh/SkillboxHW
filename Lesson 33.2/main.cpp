#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <exception>

enum fishStatus {
    NONE = 0,
    FISH = 1,
    BOOT = 2,
    CAUGHT_FISH = 3,
};

class FishCaught: public std::exception {
public:
    const char* what() const noexcept override {
        return "Fish caught!";
    }
};

class BootCaught: public std::exception {
public:
    const char* what() const noexcept override
    {
        return "Boot caught. You lose :(";
    }
};

class ErrorValue: public std::exception {
public:
    const char* what() const noexcept override
    {
        return "error value";
    }
};


int showPool(std::vector<std::vector<int>>& pool) {
    int fishCount = 0;
    for (const auto& row : pool) {
        for (auto val : row) {
            if (val == CAUGHT_FISH)
                std::cout << "$" << " ";
            else
                std::cout << "*" << " ";
                //std::cout << val << " ";

            if (val == FISH) fishCount ++;
        }
        std::cout << std::endl;
    }

    return fishCount;
}

void generatePool(std::vector<std::vector<int>>& pool, int rowCnt, int colCnt) {
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> fishGen(NONE, FISH);
    std::uniform_int_distribution<> bootsGen(0, 8);

    for (int row = 0; row < rowCnt; row++) {
        std::vector<int> rows;
        for (int col = 0; col < colCnt; col++) {
            int val = fishGen(gen);
            rows.push_back(val);
        }
        pool.push_back(rows);
    }

    // generate boots
    int bootsCnt = 0;
    while (bootsCnt < 3) {
        int col = bootsGen(gen);
        int row = bootsGen(gen);
        if (!pool[row][col]) {
            pool[row][col] = BOOT;
            bootsCnt++;
        }
    }

}

void fishing(std::vector<std::vector<int>>& pool, int row, int col) {
    row--;
    col--;
    if (row < 0 || col < 0) throw ErrorValue();
    if (row > pool.size() || col > pool[row].size()) throw ErrorValue();
    if (pool[row][col] == FISH) {
        pool[row][col] = CAUGHT_FISH;
        throw FishCaught();
    }
    if (pool[row][col] == BOOT) throw BootCaught();
}

int main() {
    std::cout << "Fishing!" << std::endl;

    std::vector<std::vector<int>> pool;
    generatePool(pool, 9, 9);

    std::cout << "Start fishing!" << std::endl;
    showPool(pool);

    int tryCount = 0;
    while (true) {

        std::cout << "Select row (1 - 9) and col (1 - 9)" << std::endl;
        int col, row;
        std::cin >> row >> col;

        try {
            tryCount ++;
            fishing(pool, row, col);
        }
        catch (FishCaught& ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "It took you "<< tryCount <<" attempts" << std::endl;
            break;
        }
        catch (BootCaught& ex) {
            std::cout << ex.what() << std::endl;
            break;
        }
        catch (ErrorValue& ex) {
            std::cout << ex.what() << std::endl;
        }
    }


    return 0;
}
