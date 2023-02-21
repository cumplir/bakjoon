import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		int max = -1; 
		int maxy = 0; 
		int maxx = 0;
		Scanner sc = new Scanner (System.in); 
		int [][]N = new int [10][10]; 
		for( int i = 1; i < 10; i++) { 
			for( int j = 1; j < 10;j++) { 
			  N[i][j] = sc.nextInt();  
			}
		}
		for(int k = 1; k < 10; k++) { 
			for(int h = 1; h < 10; h++) { 
				if(N[k][h] > max) { 
					max = N[k][h];
					maxy = k; 
					maxx = h;
				}
			}
		}
		System.out.println(max); 
		System.out.println(maxy+" "+maxx);
		
		
		
	}
}
