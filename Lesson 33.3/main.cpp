#include <iostream>
#include <vector>
#include <exception>

class InvalidIndex: public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid index";
    }
};

class NullValues: public std::exception {
public:
    const char* what() const noexcept override {
        return "Registry empty";
    }
};

template <typename Tkey, typename Tval>
class Regisrty {
private:

    struct Elems {
        Tkey key;
        Tval value;
        Elems() : key(Tkey()), value(Tval()) {};
    };

    std::vector<Elems> registry;

public:
    Regisrty() {}

    Regisrty(const Tkey& k, const Tval& v) {
        this->add(k, v);
    };

    Elems add(const Tkey& key, const Tval& val) {
        Elems group;
        group.key = key;
        group.value = val;

        registry.push_back(group);
        return registry.back();
    }

    void remove(const Tkey& key) {

        int i = 0;
        bool founded = false;
        for (auto& group : registry) {
            if (group.key == key) {
                founded = true;
                break;
            }
            i+=1;
        }

        if (founded)
            registry.erase(registry.begin() + i);
    }

    void print() {
        for (auto& group : registry)
            std::cout << group.key << ": " << group.value << std::endl;
    }

    Tval find(Tkey key) {
        for (auto& group : registry)
            if (group.key == key)
                return group.value;

        //throw InvalidIndex();
        return Tval();
    }

    Tval& operator[](const Tkey& key) {
        if (this->registry.empty())
            throw NullValues();

        for (auto& elems : registry) {
            if (elems.key == key) {
                return elems.value;
            }

        }

        add(key, Tval());
        return registry.back().value;
    }

    int length() {
        return registry.size();
    }

    ~Regisrty() {

    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;

    Regisrty<std::string, int> reg;
    reg.add("abc", 123);
    reg.add("def", 456);
    reg.print();

    std::cout << "Founded: " << reg.find("abc") << std::endl;
    std::cout << "Founded: " << reg.find("54") << std::endl;


    reg.remove("abc");

    reg["val"] =  78;
    reg.print();

    std::cout << reg["abc"] << " " << reg["val"] << std::endl;

    return 0;
}
