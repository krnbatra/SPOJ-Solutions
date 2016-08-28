import java.math.BigInteger;
import java.util.Scanner;

class CodeMonk{

	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner  s = new Scanner(System.in);
		int t = s.nextInt();
		
		while(t-- > 0){
			s.nextLine();
			int students = s.nextInt();
			long[] candies = new long[students];
			for(int i = 0; i < students; i++){
				candies[i] = s.nextLong();
			}
			BigInteger sum = BigInteger.ZERO;
			for(int i = 0; i < students; i++){
				sum=sum.add(BigInteger.valueOf(candies[i]));
			}
			if(sum.mod(BigInteger.valueOf((long)students))==BigInteger.ZERO){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}


	}
}