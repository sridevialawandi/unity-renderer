#include <bits/stdc++.h> 
using namespace std; 
int gcd(int a, int b){ 
	if (b==0) 
	return a; 
	return gcd(b, a%b); 
} 
int pour(int fromCap, int toCap, int d){ 
	int from = fromCap; 
	int to = 0; 
	int step = 1; 
	while (from != d && to != d){ 
		int temp = min(from, toCap - to); 
		to += temp; 
		from -= temp; 
		step++; 
		if (from == d || to == d) 
			break; 
		if (from == 0){ 
			from = fromCap; 
			step++; 
		} 
		if (to == toCap){ 
			to = 0; 
			step++; 
		} 
	} 
	return step; 
} 
int minSteps(int m, int n, int d){ 
	if (m > n) 
		swap(m, n); 
	if (d > n) 
		return -1; 
	if ((d % gcd(n,m)) != 0) 
		return -1; 
	return min(pour(n,m,d), 
			pour(m,n,d)); 
}  
int main(){ 
	int n = 5, m = 7, d = 3; 

	printf("Minimum number of steps required is %d", 
		minSteps(m, n, d)); 

	return 0; 
} 

