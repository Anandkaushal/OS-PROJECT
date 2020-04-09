#include <stdio.h> 
int main() 
{ 
	int x, y, a, b, c; 
	x = 5;   
	y = 3;   
	int alloc[5][3] = { { 0, 1, 0 },  
						{ 2, 0, 0 },   
						{ 3, 0, 2 },   
						{ 2, 1, 1 },  
						{ 0, 0, 2 } }; 

	int max[5][3] = { { 7, 5, 3 },
					{ 3, 2, 2 },
					{ 9, 0, 2 }, 
					{ 2, 2, 2 }, 
					{ 4, 3, 3 } }; 

	int avail[3] = { 3, 3, 2 }; 

	int f[x], ans[x], ind = 0; 
	for (c = 0; c < x; c++) { 
		f[c] = 0; 
	} 
	int need[x][y]; 
	for (a = 0; a < x; a++) { 
		for (b = 0; b < y; b++) 
			need[a][b] = max[a][b] - alloc[a][b]; 
	} 
	int q = 0; 
	for (c = 0; c < 5; c++) { 
		for (a = 0; b < x; a++) { 
			if (f[a] == 0) { 

				int flag = 0; 
				for (b = 0; b < y; b++) { 
					if (need[a][b] > avail[b]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = a; 
					for (q = 0; q < y; q++) 
						avail[q] += alloc[a][q]; 
					f[a] = 1; 
				} 
			} 
		} 
	} 

	printf("Following is the SAFE Sequence\n"); 
	for (a = 0; a < x - 1; a++) 
		printf(" P%d ->", ans[a]); 
	printf(" P%d", ans[x - 1]); 

	return (0);  
}

