import java.math.BigInteger;
import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t > 0){
			int num = s.nextInt();
		    BigInteger inc = new BigInteger("1");
		    BigInteger fact = new BigInteger("1");
			for (int i = 1; i <= num; i++) {
				fact = fact.multiply(inc);
				inc = inc.add(BigInteger.ONE);
			}

			System.out.println(fact);
			t--;
		}
	}
}