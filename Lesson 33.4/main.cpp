#include <iostream>
#include <vector>

template<typename T>
T average(std::vector<T> vec) {

    T sum = 0;
    for (const T elem : vec)
        sum+=elem;

    std::cout << sum << " " << vec.size() << std::endl;
    return (sum / vec.size());
}


template<typename T>
void createVec(std::vector<T>& vec) {

    while (true) {
        std::cout << "Enter value: " << std::endl;
        T val = T();

        std::cin >> val;
        if (std::cin.fail()) break;

        vec.push_back(val);

        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}



int main() {
    std::cout << "Function for calculating the arithmetic mean" << std::endl;

    std::vector<double> vec;
    createVec(vec);
    std::cout << "average: " << average(vec) << std::endl;


    return 0;
}
