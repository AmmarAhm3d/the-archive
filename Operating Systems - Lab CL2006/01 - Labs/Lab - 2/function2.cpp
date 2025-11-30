#include "header.h"
using namespace std;

bool issorted(int n, int a[]) {
	for(int i=1;i<n;i++) {
		if(a[i]<a[i-1]) return false;
	}
	return true;
}