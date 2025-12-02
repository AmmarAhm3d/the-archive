#include <iostream>
using namespace std;

// to compile and run, then delete the executable
// g++ lecc12.cpp -o lecc12 && ./lecc12 && rm lecc12
// this is a simple message passing algorithm, simulating a ring network
// the output is reproducable and deterministic

/*The code is simulating a ring communication pattern among `p` nodes (in this case, `p` is 8). 
Each node is assigned a unique ID from 0 to `p-1` (0 to 7). 
Each node communicates with two other nodes: the one on its left and the one on its right. 
The IDs of the left and right nodes are calculated using modulo arithmetic to create a wrap-around effect.

The outer loop (`for (int node = 0; node < p; node++)`) iterates over each node. 
For each node, it calculates the IDs of the left and right nodes:

- `left = (node - 1) % p;` calculates the ID of the left node. 
However, because C++'s modulo operation can yield a negative result, when `node` is 0, `left` becomes -1. 
This is why you see "received msg from -1" in the output.
- `right = (node + 1) % p;` calculates the ID of the right node. 
This operation always yields a positive result, so there are no issues here.

The inner loop (`for (int i = 1; i < p; i++)`) simulates each node sending and receiving a message. 
However, the loop variable `i` is used instead of `node` in the print statements, which is why the node sending and receiving messages 
starts from 1 instead of 0.

The output shows each node (from 1 to 7, due to the use of `i` instead of `node`) 
sending a message to the right node and receiving a message from the left node, 
for each node in the ring (from 0 to 7). The right node's ID increases with each iteration of the outer loop, 
while the left node's ID is always one less than the current node's ID (or -1 when the current node is 0).*/
int main()
{
	int p = 8;
	int X;
	int left, right;
	X = 0;
	string msg, res = "";
	for (int node = 0; node < p; node++)
	{
		left = (node - 1) % p;
		right = (node + 1) % p;
		res += node;
		msg = res;
		for (int i = 1; i < p; i++)
		{
			cout << "node " << i << " sent msg to " << right << endl;
			cout << " node " << i << " received msg from " << left << endl;
			res += msg;
		}
		//cout << "res a each node " << res << endl;
	}
	return 0;
}