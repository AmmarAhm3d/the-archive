#include <iostream>
#include<math.h>
using namespace std;

// to compile and run, then delete the executable
// g++ lec11.cpp -o lec11 && ./lec11 && rm lec11
// what is going on in the code?
// we are implementing a simple butterfly algorithm, or a simple message passing algorithm
// the output is reproducable and deterministic

int computeDestination(int node, int mask) {
    return (node ^ mask); 
}

int main() {
    int num_nodes = 8; 
    int d = 3;         

    int X = 123;
    int mask = 7;


    for (int node = 0; node < num_nodes; ++node) {

        for (int i = d - 1; i >= 0; i--) {
            int x = pow(2, i);
            mask = mask ^ x;
            if ((node & mask) == 0)
            {
                if ((node & x) == 0)
                {
                    int dest = computeDestination(node, x);
                    cout << "Node " << node << " sent message " << X << " to node " << dest << endl;
                }
                else
                {
                    int source = computeDestination(node, x);
                    cout << "Node " << node << " received message " << X << " from node " << source << endl;
                }
            }
        }
    }

    return 0;
}