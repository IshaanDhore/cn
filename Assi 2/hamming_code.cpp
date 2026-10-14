#include <iostream>

using namespace std;

// Function to generate the Hamming Code using pointer arithmetic
void generateHammingCode(int* data, int* hamming) {
    // Place data bits at non-power-of-2 positions: 3, 5, 6, 7
    *(hamming + 3) = *(data + 0);
    *(hamming + 5) = *(data + 1);
    *(hamming + 6) = *(data + 2);
    *(hamming + 7) = *(data + 3);

    // Calculate parity bits using XOR for Even Parity
    *(hamming + 1) = *(hamming + 3) ^ *(hamming + 5) ^ *(hamming + 7);
    *(hamming + 2) = *(hamming + 3) ^ *(hamming + 6) ^ *(hamming + 7);
    *(hamming + 4) = *(hamming + 5) ^ *(hamming + 6) ^ *(hamming + 7);
}

// Function to detect and correct single-bit errors
void detectAndCorrectError(int* received) {
    // Calculate syndrome bits
    int c1 = *(received + 1) ^ *(received + 3) ^ *(received + 5) ^ *(received + 7);
    int c2 = *(received + 2) ^ *(received + 3) ^ *(received + 6) ^ *(received + 7);
    int c4 = *(received + 4) ^ *(received + 5) ^ *(received + 6) ^ *(received + 7);

    // Calculate error position
    int errorPosition = c4 * 4 + c2 * 2 + c1 * 1;

    if (errorPosition == 0) {
        cout << "\n[Status] No error detected in the received data.\n";
    } else {
        cout << "\n[Status] Error detected at position " << errorPosition << ".\n";
        
        // Correct the error by flipping the bit using pointer arithmetic
        *(received + errorPosition) = *(received + errorPosition) == 0 ? 1 : 0;
        
        cout << "[Status] Error automatically corrected.\n";
    }
}

int main() {
    int data[4];
    // Array size 8 used to allow 1-based indexing (index 0 is ignored)
    int hamming[8] = {0}; 
    
    cout << "--- Hamming Code (7,4) Sender ---\n";
    cout << "Enter 4 data bits one by one (space separated): ";
    for (int i = 0; i < 4; i++) {
        cin >> *(data + i);
    }

    generateHammingCode(data, hamming);

    cout << "Transmitted Hamming Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << *(hamming + i) << " ";
    }
    cout << "\n\n";

    // --- Simulating Receiver ---
    int received[8];
    cout << "--- Hamming Code (7,4) Receiver ---\n";
    cout << "Enter the 7 received bits one by one (introduce an error to test): ";
    for (int i = 1; i <= 7; i++) {
        cin >> *(received + i);
    }

    detectAndCorrectError(received);

    cout << "Corrected / Validated Hamming Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << *(received + i) << " ";
    }
    cout << "\n";

    return 0;
}