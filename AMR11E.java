import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.util.ArrayList;

class A{
	static ArrayList<Integer> sieve(int n){
		char[] primes = new char[n+1];
		ArrayList<Integer> prime = new ArrayList<>();
		for(int i = 0;i < primes.length; i++){
			primes[i] = 0;
		}
		primes[0] = 1;
		primes[1] = 1;
		for(int i = 2; i <= n; i++){		
			if(primes[i]==0){
				for(int k = 2*i;k <= n; k+=i){	
					primes[k]++;
				}
			}
		}
		for(int i = 2; i <= n; i++){		
			if(primes[i]>=3){
				prime.add(i);
			}
		}
		return prime;
	}
	public static void main(String[] args) {
		final InputReader in = new InputReader(System.in);
		final OutputWriter out = new OutputWriter(System.out);
		ArrayList<Integer> primes = sieve(1000000);
		SolveA sol = new SolveA();
		int t = in.readInt();
		while(t-- > 0){
			sol.solve(in, out, primes);
		}
		out.flush();
		out.close();
	}
}
class SolveA{

	void solve(InputReader in, OutputWriter out, ArrayList<Integer> primes){
		int n = in.readInt();
		out.printLine(primes.get(n-1));
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

