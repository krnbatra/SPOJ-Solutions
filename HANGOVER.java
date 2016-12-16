import java.util.*;
import java.lang.*;

class Main
{
public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		double t = s.nextDouble();
		while(t != 0.0){
			double sum = 0;
			for(int i = 2; ; i++){
				sum+=1.0/i;
				if(sum >= t){
					System.out.println(i-1+" card(s)");
					break;
				}
			}
			t = s.nextDouble();
		}
	}
}