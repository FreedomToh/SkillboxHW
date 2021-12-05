#include <exception>
#include <iostream>
#include <map>
#include <exception>

class CountLessZero: public std::exception {
public:
    const char* what() const noexcept override{
        return "value should be more zen zero";
    }
};

class NoExistsKey: public std::exception {
public:
    const char* what() const noexcept override{
        return "non-existent key";
    }
};

class NotEnough: public std::exception {
public:
    const char* what() const noexcept override{
        return "not enough goods";
    }
};


template<typename Tkey>
void populateDb(std::map<Tkey, int>& db) {
    while (true) {
        Tkey articul;
        int count = 0;

        std::cout << "{articul} {count} or -1 -1 for end:" << std::endl;
        std::cin >> articul >> count;

        if (articul == "-1" || count == -1)
            break;

        db[articul] += count;
        std::cin.clear();
    }
}

template<typename Tkey>
void addToShopList (std::map<Tkey, int>& db,
                    std::map<Tkey, int>& shList,
                    Tkey key, int count) {

    (count <= 0) ? throw CountLessZero() : "";
    (!db.contains(key)) ? throw NoExistsKey() : "";
    (db[key] < count) ? throw NotEnough() : "";

    db[key] -= count;
    shList[key] += count;
}

template<typename Tkey>
void remFrShopList (std::map<Tkey, int>& db,
                    std::map<Tkey, int>& shList,
                    Tkey key, int count) {

    (count <= 0) ? throw CountLessZero() : "";
    (!db.contains(key) || !shList.contains(key)) ? throw NoExistsKey() : "";
    (shList[key] < count) ? throw NotEnough() : "";

    shList[key] -= count;
    db[key] += count;
}

template<typename Tkey>
void populateShopList(std::map<Tkey, int>& db,
                      std::map<Tkey, int>& shList) {
    std::cout << "Manage your shoplist with:"<< std::endl;
    while (true) {
        std::string command;
        Tkey articul;
        int count = 0;

        std::cout << "{add|remove} {articul} {count} or -1 -1 -1 for end"<< std::endl;
        std::cin >> command >> articul >> count;

        if (articul == "-1" || count == -1 || command == "-1")
            break;

        if (command == "add") {
            try {
                addToShopList(db, shList, articul, count);
            } catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        else if (command == "remove") {
            try {
                remFrShopList(db, shList, articul, count);
            } catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }

        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}



int main(int argc, char **argv) {
    std::cout << "internet shop!" << std::endl;

    std::map<std::string, int> shopDb;
    populateDb(shopDb);

    std::cout << "Goods:" << std::endl;
    for (auto it : shopDb) {
        std::cout << it.first << ": "<< it.second << std::endl;
    }

    std::map<std::string, int> shopList;
    populateShopList(shopDb, shopList);

    return 0;
}