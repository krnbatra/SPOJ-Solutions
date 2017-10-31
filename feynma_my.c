import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	 Scanner scan=new Scanner(System.in);
    int n=scan.nextInt();
    while(n!=0){
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=i*i;
        }
        n=scan.nextInt();
        System.out.println(ans);
        
    }	
	}
}