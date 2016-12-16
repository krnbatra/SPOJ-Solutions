import java.math.BigInteger;
import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int i = 1;
		while(i <= 10){

			BigInteger total = s.nextBigInteger();
			
			BigInteger extra = s.nextBigInteger();
			BigInteger factor = new BigInteger("2");
			
			BigInteger numOfApplesWithKlaudia;
			
			BigInteger numOfApplesWithNatalia;
			
			
			numOfApplesWithKlaudia = total.add(extra).divide(factor);
			
			numOfApplesWithNatalia = total.subtract(numOfApplesWithKlaudia);
			
			System.out.println(numOfApplesWithKlaudia);
			
			System.out.println(numOfApplesWithNatalia);
			
			
			i++;

		}

	}
}