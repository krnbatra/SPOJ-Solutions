import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		long t = s.nextLong();
		
		while(t > 0){
			long k =s.nextLong();
			long res = 250*(k-1) + 192;
			System.out.println(res);
			t--;
		}
	}
}