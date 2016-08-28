import java.math.BigInteger;
import java.util.Scanner;

class CodechefPractice{

	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- > 0){
			BigInteger n = s.nextBigInteger();
			BigInteger k = s.nextBigInteger();
			BigInteger m = s.nextBigInteger();
			BigInteger time = BigInteger.ZERO;
			BigInteger temp = n;
			if(temp.compareTo(m) > 0){
				System.out.println(0);
			}else{
				while(temp.compareTo(m)<=0){
					temp = temp.multiply(k);
					time = time.add(BigInteger.ONE);
				}
				System.out.println(time.subtract(BigInteger.ONE));
			}
		}


	}

}
