import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t > 0){
			long numOfLevels = s.nextInt();
			
			long numOfCards = ((numOfLevels*(numOfLevels-1))/2 + (numOfLevels*(numOfLevels+1))) % 1000007;
			System.out.println(numOfCards);
			
			t--;
		}
	}

}