// #include<iostream>
// #include<cmath>
// using namespace std;

// int main(){
//     int prefix = 24;
//     int requiredsubnet = 2;

//     int borrowedbits = ceil(log2(requiredsubnet));

//     int newprefix = prefix + borrowedbits;

//     int hostbits = 32 - newprefix;

//     int usablehost = pow(2,hostbits) - 2;
//     int totalhost = pow(2,hostbits);
//     int octet = 256 - totalhost;

//     cout<<"Subnetting"<<endl;
//     cout<<"Borrowed bits "<<borrowedbits<<endl;
//     cout<<"New CIDR prefix /"<<newprefix<<endl;
//     cout<<"Subnet mask = 255.255.255."<<octet<<endl;
//     cout<<"Usable Hosts "<<usablehost<<endl;

//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int data[8];

//     cout<<"Enter 4 data bit in spaces"<<endl;
//     cin>>data[3]>>data[5]>>data[6]>>data[7];

//     data[1] = data[3]^data[5]^data[7];
//     data[2] = data[3]^data[6]^data[7];
//     data[4] = data[5]^data[6]^data[7];

//     cout<<"Encoded data for transmission"<<endl;
//     for(int i=1;i<=7;i++){
//         cout<<data[i]<<" ";
//     }

//     int error;
//     cout<<"Enter error at any position(1-7) :";
//     cin>>error;

//     data[error] = data[error] ^ 1;

//     cout<<"Recieved data with error ";
//     for(int i=1;i<=7;i++){
//         cout<<data[i]<<" ";
//     }
//     cout<<"\n";

//     int c1 = data[1]^data[3]^data[5]^data[7];
//     int c2 = data[2]^data[3]^data[6]^data[7];
//     int c4 = data[4]^data[5]^data[6]^data[7];

//     int error_index = c4*4 + c2*2 + c1*1;

//     if(error_index == 0){
//         cout<<"No error found";
//     }
//     else{
//         cout<<"Error found at position: "<<error_index<<endl;
//         data[error_index] = data[error_index] ^ 1;
//         cout<<"Corrected Data :";
//         for(int i=1;i<=7;i++){
//         cout<<data[i]<<" ";
//     }
//     }

//     return 0;
// }

#include<iostream>
using namespace std;

int main(){
    int cost[10][10],dist[10][10],i,j,k,n;

    cout<<"Enter no. of routers"<<endl;
    cin >> n;
    
    cout<<"Enter cost matrix(use 999 for no link)"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>cost[i][j];
            dist[i][j] = cost[i][j];
        }
    }

    for(k=0;k<n;k++){
         for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
         }
    }

    cout<<"The shortest path between routers"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dist[i][j] >= 999){
                cout<<"INF \t";
            }
            else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    return 0;
}

