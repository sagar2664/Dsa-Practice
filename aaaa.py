#include <iostream>
#include <string>
#include <algorithm>

int min_steps_to_open_lock(const std::string& dial, const std::string& passcode) {
    int total_steps = 0;
    int current_index = 0;
    int dial_length = dial.length();
    
    for (char char_in_passcode : passcode) {
        int target_index = dial.find(char_in_passcode);
        
        // Calculate the minimum rotation steps
        int clockwise_steps = (target_index - current_index + dial_length) % dial_length;
        int counterclockwise_steps = (current_index - target_index + dial_length) % dial_length;
        int rotation_steps = std::min(clockwise_steps, counterclockwise_steps);
        
        // Add the rotation steps and the press step
        total_steps += rotation_steps + 1;
        
        // Update the current index to the target index
        current_index = target_index;
    }
    
    return total_steps;
}

int main() {
    std::string dial = "HELLOW";
    std::string passcode = "HO";
    
    std::cout << min_steps_to_open_lock(dial, passcode) << std::endl; // Output: 4
    
    return 0;
}
