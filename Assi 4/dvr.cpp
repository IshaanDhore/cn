#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of routers: ";
    cin >> n;

    int cost[10][10], dist[10][10];

    cout << "Enter cost matrix (type 999 for no link):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j]; 
        }
    }

    for (int step = 0; step < n - 1; step++) { 
        for (int i = 0; i < n; i++) {          
            for (int j = 0; j < n; j++) {     
                for (int k = 0; k < n; k++) { 
                    
                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                    }
                    
                }
            }
        }
    }

    cout << "\nFinal Distance Vectors (Routing Tables):\n";
    for (int i = 0; i < n; i++) {
        cout << "Router " << i << ": ";
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}