import java.math.BigInteger;
import java.util.Scanner;

class A{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- > 0){
			BigInteger a = s.nextBigInteger();
			BigInteger b = s.nextBigInteger();
			System.out.println(a.modPow(b, BigInteger.TEN));
		}
	}
}