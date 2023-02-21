import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in); 
		int N = sc.nextInt(); 
		int M = sc.nextInt(); 
		int [][]A = new int [N][M]; 
		int [][]B = new int[N][M]; 
		int [][]C = new int [N][M];

		for(int k = 0; k < N; k++) { 
			for(int h = 0; h < M; h++) { 
				A[k][h] = sc.nextInt();
				//System.out.println(A[k][h]);
			}
		}
		for(int k = 0; k < N; k++) { 
			for(int h = 0; h < M; h++) { 
				B[k][h] = sc.nextInt();
				//System.out.println(B[k][h]);
			}
		}

		for(int i = 0; i < N; i++) {
			for(int j =0 ; j < M; j++) { 
				C[i][j] = A[i][j] + B[i][j];
				System.out.print(C[i][j]+" ");
			}
			System.out.println();
		}
		
		
	}
}
