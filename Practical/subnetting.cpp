#include <iostream>
#include <cmath> // For pow() and log2()
using namespace std;

int main() {
    int originalPrefix = 24; // /24 network
    int requiredSubnets = 2; // Divide into 2 subnets

    // 1. Calculate how many bits we need to borrow to make 2 subnets
    // log2(2) = 1 bit borrowed
    int borrowedBits = ceil(log2(requiredSubnets)); 
    
     // 2. Calculate the new CIDR prefix (/24 + 1 = /25)
    int newPrefix = originalPrefix + borrowedBits;

    // 3. Calculate how many bits are left for hosts (IPv4 has 32 bits total)
    // 32 - 25 = 7 bits left for hosts
    int hostBits = 32 - newPrefix;

    // 4. Calculate usable hosts ( 2^hostBits - 2 )
    // We subtract 2 for the Network ID and Broadcast Address
    int usableHosts = pow(2, hostBits) - 2;

    // 5. Calculate the last octet of the subnet mask
    // A cool networking trick: Last octet = 256 - (total hosts including network/broadcast)
    int totalHosts = pow(2, hostBits);
    int lastOctetMask = 256 - totalHosts;

    // Print Results
    cout << "--- Subnetting 192.168.1.0/24 into 2 Subnets ---\n\n";
    cout << "Borrowed Bits: " << borrowedBits << "\n";
    cout << "New CIDR Prefix: /" << newPrefix << "\n";
    cout << "Subnet Mask: 255.255.255." << lastOctetMask << "\n";
    cout << "Usable Hosts per Subnet: " << usableHosts << "\n";

    return 0;
}