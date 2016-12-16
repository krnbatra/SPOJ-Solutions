import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t > 0){
			int n = s.nextInt();
			int power = 0;
			while(Math.pow(5, power) <= n){
				power++;
			}
			int count = 0;
			for(int i = 1; i <= power; i++){
				count+=n/Math.pow(5, i);
			}
			System.out.println(count);
			t--;
		}	
	}
}