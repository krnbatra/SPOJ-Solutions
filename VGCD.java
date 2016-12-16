import java.math.BigInteger;
import java.util.Scanner;

class A{
	public static void main(String[] args) {
//		final InputReader in = new InputReader(System.in);
//		final OutputWriter out = new OutputWriter(System.out);
		Scanner s = new Scanner(System.in);
		//SolveA sol = new SolveA();
		int t = s.nextInt();
		while(t-- > 0){
			BigInteger a = s.nextBigInteger();
			BigInteger b = s.nextBigInteger();
			System.out.println(a.gcd(b));
		}
//		out.flush();
//		out.close();
	}
}
//class SolveA{
//	void solve(InputReader in, OutputWriter out, Scanner s){
//		
//	}
//}