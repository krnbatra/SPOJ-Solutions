import java.io.*;
import java.util.*;

class A{
	 static int[] sieve(int n){
		int[] primes = new int[n+1];
		//initially i am going to assume all numbers are prime.
		for(int i = 0;i < primes.length; i++){
			primes[i] = 0;
		}
		primes[0] = 1;
		primes[1] = 1;
		//if primes[i] is 0 it denotes the number is prime else composite.
		for(int i = 2; i <= n; i++){		//for optimised version use i*i <= n.. then the time complexity will be O(sqrt(n)log(logn))
			if(primes[i]==0){
				primes[i] = i;
				if((i*(long)1*i) <= n){			//checking whether i*i has not exceeded n.
					for(int k = 2*i;k <= n; k+=i){	//remember although starting from i*i will be faster but it can result in overflow if the value of max_prime is large start from 2*i not i*i. 
						if(primes[k]==0)
							primes[k] = i;
					}
				}
			}
		}
		return primes;
	}
	public static void main(String[] args) {
		final InputReader in = new InputReader(System.in);
		final OutputWriter out = new OutputWriter(System.out);
		int t = in.readInt();
		SolveA sol = new SolveA();
		int[] primes = sieve(10000001);
		long[] res = new long[10000001];
		res[0] = 0;
		res[1] = 0;
		for(int i = 2;i < res.length; i++){
			res[i] = res[i-1]+(long)primes[i];
		}
		while(t-- > 0){
			sol.solve(in, out, res);
		}
		out.flush();
		out.close();
	}
}
class SolveA{
	
	void solve(InputReader in, OutputWriter out, long[] res){
		int n = in.readInt();
		out.printLine(res[n]);
	}
}
class InputReader{
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream)
	{
		this.stream = stream;
	}

	public int read()
	{
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars)
		{
			curChar = 0;
			try
			{
				numChars = stream.read(buf);
			} catch (IOException e)
			{
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-')
		{
			sgn = -1;
			c = read();
		}
		int res = 0;
		do
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString()
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do
		{
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}
	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	public boolean isSpaceChar(int c)
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next()
	{
		return readString();
	}

	public interface SpaceCharFilter
	{
		public boolean isSpaceChar(int ch);
	}
}
class OutputWriter {
	private  PrintWriter writer;
	public OutputWriter(OutputStream outputStream)
	{
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
	public OutputWriter(Writer writer)
	{
		this.writer = new PrintWriter(writer);
	}
	public void print(Object... objects)
	{
		for (int i = 0; i < objects.length; i++)
		{
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	public void printLine(Object... objects)
	{
		print(objects);
		writer.println();
	}
	public void close()
	{
		writer.close();
	}

	public void flush()
	{
		writer.flush();
	}
} 

