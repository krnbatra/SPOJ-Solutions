import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int a = s.nextInt();
		
		int b = s.nextInt();
		
		int c = s.nextInt();
		
		
		while(a != 0 || b!= 0 || c != 0){
			
			if(2*b == a+c){
				System.out.println("AP " + (2*c - b) );
			}
			
			else
				System.out.println("GP " + (c * (c/b)) );
			
			a = s.nextInt();
			
			b = s.nextInt();
			
			c = s.nextInt();
			
		}
		

	}
}