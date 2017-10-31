import java.util.*;
import java.lang.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main
{
static int min(int a,int b,int c)
	{
		int mini;
		if(a>b)
		{
			mini=b;
			if(b>c)
				return c;
			else 
				return b;
			
		}
		else
		{
			if(a>c)
				return c;
			else
				return a;
		}
		
	}

	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new  BufferedReader(new InputStreamReader(System.in));
		int test =Integer.parseInt(br.readLine());
		for(int i=0;i<test;i++)
		{
			String first=br.readLine();
			String second =br.readLine();
			int matrix[][]=new int [2001][2001];
			for(int j=0;j<second.length()+1;j++)
			{
				for(int k=0;k<first.length()+1;k++)
					matrix[j][k]=0;
			}
			matrix[0][0]=0;
			for(int j=0;j<second.length()+1;j++)
			{
				for(int k=0;k<first.length()+1;k++)
				{
					if(j==0)
					{
						matrix[j][k]=k;
						continue;
					}
					if(k==0)
					{
						matrix[j][k]=j;
						continue;
					}
					
					if(first.charAt(k-1)==second.charAt(j-1))
						matrix[j][k]=matrix[j-1][k-1];
					else
					{
						matrix[j][k]=1+min(matrix[j-1][k],matrix[j-1][k-1],matrix[j][k-1]);
					}
				}
				
			}
			System.out.println(matrix[second.length()][first.length()]);
			
		}
			
		
	}
}
