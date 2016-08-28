import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int numOfCandies = s.nextInt();
		while(numOfCandies != -1){
			long sum = 0;
			int res = 0;
			int[] input = new int[numOfCandies];
			for(int i = 0; i < numOfCandies; i++){
				input[i] = s.nextInt();
				sum += input[i];
			}
			
			if(sum % numOfCandies != 0){
				System.out.println("-1");
			}
			else{
				int numOfCandiesWithEach = (int)sum / numOfCandies;
				for(int i = 0; i < numOfCandies; i++){
					if(input[i] < numOfCandiesWithEach){
						res += numOfCandiesWithEach-input[i];
					}
				}
				System.out.println(res);
			}
			
			
			numOfCandies = s.nextInt();
			
			
		}
		
		
	}
}