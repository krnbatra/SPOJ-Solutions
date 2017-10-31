import java.util.*;
import java.lang.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan=new Scanner(System.in);
    int cases=scan.nextInt();
    for(int i=0;i<cases;i++)
    {
        int a=scan.nextInt();
        int b=scan.nextInt();
        int ans=0;
        for(;a>0;a/=10)
        {
            int temp=a%10;
             ans=ans*10+temp;
        }
        a=ans;
        ans=0;
        for(;b>0;b/=10)
        {
            int temp=b%10;
             ans=ans*10+temp;
        }
        b=ans;
        int answer=a+b;
        ans=0;
        for(;answer>0;answer/=10)
        {
            int temp=answer%10;
             ans=ans*10+temp;
        }
        answer=ans;
        String pu="";
                pu+=answer;
        pu.replaceFirst("^0+(?!$)", "");
        System.out.println(pu);
        
        
    }
    
	}
}