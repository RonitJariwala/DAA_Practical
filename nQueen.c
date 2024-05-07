#include<stdio.h> 
#include<math.h> 

int x[20], c=0;

// Function to check if it's safe to place a queen at position (k, i)
int place(int k, int i) {
    int j;
    for(j=1; j<=k-1; j++) {
        // Checking if queens in previous rows or diagonals threaten the current position
        if((x[j]==i) || abs(x[j]-i)==abs(j-k))
            return 0; // Not safe to place queen at position (k, i)
    }
    return 1; // Safe to place queen at position (k, i)
}

// Function to print the current arrangement of queens on the chessboard
void print(int n) {
    int i,j;
    printf("\n");
    for(i=1; i<=n; ++i) {
        printf("\t%d",i); // Print column numbers at the top
    }
    printf("\n");
    for(i=1; i<=n; i++) {
        printf("%d",i); // Print row number
        for(j=1; j<=n; ++j) {
            if(x[j]==i)
                printf("\tQ"); // Queen placed at this position
            else
                printf("\t*"); // Empty cell
        }
        printf("\n");
    }
}

// Main function to solve N-Queens problem using backtracking
void nqueen(int k,int n) {
    int i,j;
    for(i=1; i<=n; i++) {
        if(place(k,i)==1) { // Check if it's safe to place queen at position (k, i)
            x[k]=i; // Place queen at position (k, i)
            if(k==n) { // If all queens are placed, print the solution
                c++;
                printf("\nSolution %d \n",c);
                print(n);
            }
            else { // Recursively try placing queens in the next row
                nqueen(k+1,n);
            }
        }
    }
}

int main() {
    int k=1, n; 
    printf("Enter number of queens: "); 
    scanf("%d",&n); // Input the number of queens
    nqueen(k,n); // Solve N-Queens problem
    return 0;
}
