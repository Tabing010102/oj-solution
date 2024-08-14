#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int n, m;

int main() {
	if (m <= 6 && n > (int)(pow(2, m) + 1e-5) - 1) { printf("0\n"); exit(0); }
	
	return 0;
}
