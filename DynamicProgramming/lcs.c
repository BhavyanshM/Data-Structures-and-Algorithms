#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cols = 0;
int rows = 0;
char* A;
char* B;

// char* getNextString(FILE* fp, char* input);
int lcs(char* X, char* Y, char* LCS);
void construct(int dp[rows][cols], int i, int j);
void reset(int* a, int* b, int n);
// char* getNextString(FILE* fp, char* input){
// 	char result[2000];
// 	fscanf(fp, "%s\n", result);
// 	printf("%d\n", (int)strlen(result));
// 	input = result;
// 	return input;
// }


int lcs(char* X, char* Y, char* LCS){
	A = X;
	B = Y;
	int i = 0, j = 0;
	int lenX = strlen(X);
	int lenY = strlen(Y);
	rows = lenX;
	cols = lenY;
	int dp[lenX+1][lenY+1];
	for(i = 0; i<=lenX; i++)
		for(j = 0; j<=lenY; j++)dp[i][j] = 0;

	//printf("%s , %s\n", X, Y);

	

	for(i = 1; i<=lenX; i++){
		for(j = 1; j<=lenY; j++){
			if(X[i-1]==Y[j-1]){
				// printf("%c \n" , X[i-1]);
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				if(dp[i-1][j] >= dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = dp[i][j-1];
				}
			}
			// printf("%d ", dp[i][j]);

		}
		// printf("\n");
	}
	// printf("\n");

	//for (i = 1; i < lenX+1; i++){
		// printf("\t");
	//	for (j = 1; j < lenY+1; j++){
	//		printf("%d ", dp[i][j]);
	//	}
	//	printf("\n");
	//}printf("\n\n");

	printf("Length of LCS: %d\nLCS: ", dp[lenX][lenY]);
	construct(dp, lenX, lenY);
	return dp[lenX][lenY];
}

void construct(int dp[rows+1][cols+1], int i, int j){
	//printf("construct(dp, %d,%d):%s, %s\n", i,j ,A,B);
	if(dp[i][j]==0){
		//printf("Done\n");
		return;		
	}
	if(A[i-1]==B[j-1]){
		construct(dp, i-1, j-1);
		printf("%c", B[j-1]);
	}else if(dp[i-1][j] >= dp[i][j-1]){
		construct(dp, i-1, j);
	}else{
		construct(dp, i, j-1);
	}
}

int opt_lcs(char* X, char* Y){
	int i = 0, j = 0;

        int lenX = strlen(X);
        int lenY = strlen(Y);

        rows = lenX;
        cols = lenY;

		int* dp1 = malloc(sizeof(int)*lenY+1);
		int* dp2 = malloc(sizeof(int)*lenY+1);

       	int dp[lenX+1][lenY+1];

        for(j = 0; j<=lenY; j++)dp1[j] = 0;
        for(j = 0; j<=lenY; j++)dp2[j] = 0;

        for(i = 1; i<=lenX; i++){
                for(j = 1; j<=lenY; j++){
                        if(i%2==0){
                        	if(X[i-1]==Y[j-1]){
	                                // printf("%c \n" , X[i-1]);
	                                dp1[j] = dp2[j-1] + 1;
	                        }else{
	                                if(dp2[j] >= dp1[j-1]){
	                                        dp1[j] = dp2[j];
	                                }else{
	                                        dp1[j] = dp1[j-1];
	                                }
	                        }
	                        //printf("%d ", dp[i][j]);
                        }else{
                        	if(X[i-1]==Y[j-1]){
                                // printf("%c \n" , X[i-1]);
                               		dp2[j] = dp1[j-1] + 1;
	                        }else{
	                                if(dp1[j] >= dp2[j-1]){
	                                        dp2[j] = dp1[j];
	                                }else{
	                                        dp2[j] = dp2[j-1];
	                                }
	                        }
                        //printf("%d ", dp[i][j]);
                        }
                }



     //            if(i%2==0){
     //            	int i = 0;
					// printf("dp1: ");
					// for(i = 1; i<=lenY; i++){
					// 	printf("%d ", dp1[i]);
					// }printf("\n");
     //            }else{
     //            	int i = 0;
					// printf("dp2: ");
					// for(i = 1; i<=lenY; i++){
					// 	printf("%d ", dp2[i]);
					// }printf("\n");
     //            }   



                        
                // reset(dp1, dp2, lenY+1);
		}	
		if(lenX%2==0)return dp1[lenY];
		if(lenX%2==1)return dp2[lenY];
}

void reset(int* a, int* b, int n){
	int i = 0;
	printf("dp1: ");
	for(i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\ndp2: ");
	for(i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}
