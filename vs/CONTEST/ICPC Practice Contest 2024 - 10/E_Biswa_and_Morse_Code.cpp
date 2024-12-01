#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

// Define the standard Morse Code for letters and digits
unordered_map<char, string> STANDARD_MORSE = {
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
    {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
    {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
    {'y', "-.--"}, {'z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}
};

// A function to count the frequency of each character in the given answers
unordered_map<char, int> get_frequencies(const vector<string>& answers) {
    unordered_map<char, int> frequencies;
    
    // Process each answer
    for (const string& answer : answers) {
        for (char ch : answer) {
            ch = tolower(ch); // Convert to lowercase for case-insensitive comparison
            if (isalnum(ch)) {
                frequencies[ch]++;
            }
        }
    }
    return frequencies;
}

// A custom comparison function for the priority queue (min-heap)
struct CompareNode {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) {
        return a.first > b.first; // Min-heap based on frequency
    }
};

// Build the most efficient Morse codes based on frequencies using a Huffman-like approach
unordered_map<char, string> build_efficient_morse_codes(const unordered_map<char, int>& frequencies) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, CompareNode> min_heap;
    
    // Initialize the heap with frequency of each character
    for (const auto& entry : frequencies) {
        min_heap.push({entry.second, entry.first});
    }
    
    // Create a map for the new Morse codes
    unordered_map<char, string> char_to_code;
    
    // Build the tree (Huffman Tree logic)
    while (min_heap.size() > 1) {
        // Pop the two least frequent nodes
        auto left = min_heap.top(); min_heap.pop();
        auto right = min_heap.top(); min_heap.pop();
        
        // Merge them into a new internal node with combined frequency
        int combined_freq = left.first + right.first;
        char new_char = '\0'; // Internal node, no character associated
        
        // Add the two nodes back to the priority queue with new combined frequency
        min_heap.push({combined_freq, new_char});
        
        // Assign the new Morse codes to the left and right characters
        for (const auto& node : {left, right}) {
            if (node.second != '\0') { // Only assign Morse code to actual characters
                char_to_code[node.second] = (node.second == left.second) ? "." + char_to_code[node.second] : "-" + char_to_code[node.second];
            }
        }
    }

    return char_to_code;
}

void generate_efficient_morse_codes(const vector<string>& answers) {
    // Get the frequency of each character
    unordered_map<char, int> frequencies = get_frequencies(answers);
    
    // Build efficient Morse codes
    unordered_map<char, string> efficient_codes = build_efficient_morse_codes(frequencies);
    
    // Output the Morse codes for characters A-Z and 0-9
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (frequencies.find(ch) != frequencies.end()) { // Only output for characters that appear in the answer
            cout << (char)toupper(ch) << " " << efficient_codes[ch] << endl;
        }
    }
    for (char ch = '0'; ch <= '9'; ++ch) {
        if (frequencies.find(ch) != frequencies.end()) { // Only output for characters that appear in the answer
            cout << ch << " " << efficient_codes[ch] << endl;
        }
    }
}

int main() {
    int N;  // Number of answers
    cin >> N;
    cin.ignore(); // To ignore the newline character after N
    
    vector<string> answers(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, answers[i]);
    }
    
    // Generate the most efficient Morse codes
    generate_efficient_morse_codes(answers);
    
    return 0;
}
