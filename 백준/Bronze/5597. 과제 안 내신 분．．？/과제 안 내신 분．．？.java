import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in); 
		int[] IsSub = new int[31];
		
		for(int i = 1; i <= 28; i++ ) { 
			int num = sc.nextInt();
			 IsSub[num] = 1;
			 
		}
		for(int j = 1; j <= 30; j++) { 
			if(IsSub[j] != 1) { 
				System.out.println(j);
			}
		}
	}
}