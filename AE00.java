import java.util.*;
import java.lang.*;

class Main
{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int count= 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= Math.sqrt(i); j++){
				if(i%j==0){
					count++;
				}
			}
		}
		System.out.println(count);
	}
}