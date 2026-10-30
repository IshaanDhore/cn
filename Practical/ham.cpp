#include <iostream>
using namespace std;

int main() {
    // Array of size 8 so we can use 1-based indexing (1 to 7) for simplicity
    int data[8]; 

    // 1. Enter 4 bits of the bank transaction data
    cout << "Enter 4 data bits separated by space (e.g., 1 0 1 1): ";
    // Data bits go into positions 3, 5, 6, and 7
    cin >> data[3] >> data[5] >> data[6] >> data[7];

    // 2. Calculate Parity Bits using XOR (^) for Even Parity
    data[1] = data[3] ^ data[5] ^ data[7];
    data[2] = data[3] ^ data[6] ^ data[7];
    data[4] = data[5] ^ data[6] ^ data[7];

    cout << "Encoded Data for transmission: ";
    for (int i = 1; i <= 7; i++) cout << data[i] << " ";
    cout << "\n\n";

    // 3. Introduce a Transmission Error
    int errPos;
    cout << "Enter position to introduce an error (1-7): ";
    cin >> errPos;
    
    // Flip the bit at the chosen position (1 becomes 0, 0 becomes 1)
    data[errPos] = data[errPos] ^ 1; 
    
    cout << "Received Data (with error): ";
    for (int i = 1; i <= 7; i++) cout << data[i] << " ";
    cout << "\n\n";

    // 4. Detect the Error Location
    int c1 = data[1] ^ data[3] ^ data[5] ^ data[7];
    int c2 = data[2] ^ data[3] ^ data[6] ^ data[7];
    int c3 = data[4] ^ data[5] ^ data[6] ^ data[7];

    // Calculate binary to decimal (c3 is 4s place, c2 is 2s place, c1 is 1s place)
    int errorIndex = c3 * 4 + c2 * 2 + c1 * 1;

    // 5. Correct the Error
    if (errorIndex == 0) {
        cout << "No error detected.\n";
    } else {
        cout << ">> Error detected at position: " << errorIndex << "\n";
        
        // Fix it by flipping the corrupted bit back
        data[errorIndex] = data[errorIndex] ^ 1; 
        
        cout << ">> Corrected Data: ";
        for (int i = 1; i <= 7; i++) cout << data[i] << " ";
        cout << "\n";
    }

    return 0;
}