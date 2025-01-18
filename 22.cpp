#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string swapSubstring(std::string str) {
    int firstSpecial = -1;
    int lastSpecial = -1;

    // Find the position of the first and last non-alphabet characters
    for (int i = 0; i < str.size(); i++) {
        if (!isalpha(str[i])) {
            if (firstSpecial == -1) {
                firstSpecial = i;
            }
            lastSpecial = i;
        }
    }

    // If two distinct special characters are found, reverse the substring between them
    if (firstSpecial != -1 && lastSpecial != -1 && firstSpecial < lastSpecial) {
        std::reverse(str.begin() + firstSpecial + 1, str.begin() + lastSpecial);
    }

    return str;
}

int main() {
    std::string str = "code.sagar@goal.free";
    std::string result = swapSubstring(str);
    std::cout << "Modified string: " << result << std::endl;

    return 0;
}
