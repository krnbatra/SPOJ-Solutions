import java.util.*;
import java.lang.*;
import java.math.BigInteger;
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int d = s.nextInt();
		while(n!=0 || d!= 0){
			System.out.println(BigInteger.valueOf(n).pow(d));
			n = s.nextInt();
			d = s.nextInt();
		}
	}
}