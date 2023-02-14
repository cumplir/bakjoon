
import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in); 
		int T=sc.nextInt();
		while(T!=0) {
			int cnt = 0;
			String OX = sc.next();
			int score = 0;
			for(int j = 0; j < OX.length(); j++) { 
				
				if(OX.substring(j, j + 1).contains ("O")) { 
					cnt += 1; 
					score += cnt; 
				}
				else { 
					cnt = 0;
				}
				
				
			}
			System.out.println(score);
			T--;
		}
		
	}
}
