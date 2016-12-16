import java.util.*;
import java.lang.*;
import java.math.BigInteger;
class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- > 0){
			BigInteger n = s.nextBigInteger();
			BigInteger m = s.nextBigInteger();
			System.out.println(m.multiply(n));
		}

	}
}