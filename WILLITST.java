import java.util.*;
import java.lang.*;

class Main
{	public static boolean powerOfTwo(long n){
		int power = 0;
		long temp = (long)Math.pow(2, power);
		while(temp < n){
			power++;
			temp = (long)Math.pow(2, power);
		}
		if(temp==n)
			return true;
		else
			return false;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		long n = s.nextLong();
		if(powerOfTwo(n)){
			System.out.println("TAK");
		}
		else{
			System.out.println("NIE");
		}
	}
}