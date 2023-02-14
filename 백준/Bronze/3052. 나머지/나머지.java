import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in); 
		int[] arr = new int[42]; 
		
		for(int i = 0; i < 10; i++ ) { 
			int num = sc.nextInt(); 
			int res = num % 42; 
			arr[res] = 1; 
		}
		int cnt = 0;
		for(int j = 0; j < 42; j++) { 
			if(arr[j] ==1) { 
				cnt += 1;
				
			}
		}
		System.out.println(cnt);
	}
}