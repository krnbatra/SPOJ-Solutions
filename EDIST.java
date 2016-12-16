import java.util.*;
import java.lang.*;

class Main
{
	public static int editDistanceDPBottomToTop(String s, String t){

		int[][] output = new int[s.length()+1][t.length()+1];

		for(int i = 0; i <= s.length(); i++){
			output[i][0] = i;
		}

		for(int j = 0; j <= t.length(); j++){
			output[0][j] = j;
		}

		for(int i = 1; i <= s.length(); i++){
			for(int j = 1; j <= t.length(); j++){
				if(s.charAt(s.length()-i) == t.charAt(t.length()-j))
					output[i][j] = output[i-1][j-1];
				else
					output[i][j] =  Math.min(1+output[i-1][j], Math.min(1+output[i][j-1], 1+output[i-1][j-1]));
			}
		}
		return output[s.length()][t.length()];
	}


	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		s.nextLine();
		while(t > 0){
			String input1 = s.nextLine();
			String input2 = s.nextLine();
			System.out.println(editDistanceDPBottomToTop(input1, input2));
			t--;
		}
	}
}