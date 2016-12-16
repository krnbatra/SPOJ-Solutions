import java.util.*;
import java.lang.*;

class Main
{
public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t != 0){
			int[] input = new int[t];
			for(int i= 0; i < t; i++){
				input[i] = s.nextInt();
			}
			int i;
			for( i = 1; i <= t/2; i++){
				if(i != input[input[i-1]-1]){
					System.out.println("not ambiguous");
					break;
				}
			}
			if(i>t/2)
				System.out.println("ambiguous");
			t = s.nextInt();
		}
	}
}