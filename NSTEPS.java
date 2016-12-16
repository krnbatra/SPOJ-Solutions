import java.util.*;
import java.lang.*;

class Main
{


	public static void find(int x, int y){
		if(x == y){
			if(x % 2 ==0){
				System.out.println(2*x);
				return;
			}
			else{
				System.out.println(2*x-1);
				return;
			}
		}
		else if(y == x-2){
			if(x%2==0){
				System.out.println(x+y);
				return;
			}
			else{
				System.out.println(x+y-1);
			}
		}
		else
		{
			System.out.println("No Number");
			return;
		}
	}
	
	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		int t = s.nextInt();
		while(t > 0){
			int x = s.nextInt();
			int y = s.nextInt();
			find(x, y);
			t--;
		}

	}

}