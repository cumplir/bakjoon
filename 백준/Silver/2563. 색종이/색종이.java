
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int count = 0;
		int [][]M = new int[101][101];
		for(int i = 1; i <= N; i++) { 
			int x = sc.nextInt();
			int y = sc.nextInt();
			for(int k = y; k < y + 10; k++) { 
				for(int h = x; h < x + 10; h++) { 
					M[k][h] = 1;
				}
			}
		}
		for(int numy = 1; numy < 101; numy++) { 
			for(int numx = 1; numx < 101; numx++) { 
				if(M[numy][numx] == 1) { 
					count += 1;
				}
			}
		}
        System.out.println(count);
		
		
	}	
}