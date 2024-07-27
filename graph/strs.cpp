#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

std::string generateRandomString() {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int len = sizeof(letters) - 1;
    char randStr[2];
    randStr[0] = letters[rand() % len];
    randStr[1] = '\0';
    return std::string(randStr);
}

std::string generateRandomPattern() {
    std::string str1 = generateRandomString();
    std::string str2 = generateRandomString();
    std::string operators[] = {"==", "!="};
    return str1 + operators[rand() % 2] + str2;
}

std::vector<std::string> generatePatterns(int count) {
    std::vector<std::string> patterns;
    for (int i = 0; i < count; ++i) {
        patterns.push_back(generateRandomPattern());
    }
    return patterns;
}

int main() {
    std::srand(std::time(0));
    std::vector<std::string> patterns = generatePatterns(100000);

    for (const auto& pattern : patterns) {
        std::cout << "\"" << pattern << "\"" << ",";
    }
    cout << endl;

    return 0;
}
