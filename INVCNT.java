import java.io.*;
import java.util.*;

class A{
	public static void main(String[] args) {
		final InputReader in = new InputReader(System.in);
		final OutputWriter out = new OutputWriter(System.out);
		SolveA sol = new SolveA();
		int t = in.readInt();
		while(t-- > 0){
			sol.solve(in, out);
		}
		out.flush();
		out.close();
	}
}
class SolveA{
	long merge(int[] arr1, int[] arr2, int[] arr3){
		int i = 0;
		int j = 0;
		int k = 0;
		long countInv = 0;
		while(i < arr1.length && j < arr2.length){
			if(arr1[i] <= arr2[j]){
				arr3[k] = arr1[i];
				i++;
			}else{
				arr3[k] = arr2[j];
				countInv+=(long)arr1.length-i;
				j++;
			}
			k++;
		}
		while(i < arr1.length){
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		while(j < arr2.length){
			arr3[k] = arr2[j];
			j++;
			k++;
		}
		return countInv;
	}
	long mergeAndCountInv(int[] arr){
		if(arr.length<=1)
			return (long)0;
		int[] left = new int[arr.length/2];
		int[] right = new int[arr.length-left.length];
		for(int i = 0;i < left.length; i++){
			left[i] = arr[i];
		}
		for(int k = 0;k < right.length; k++){
			right[k] = arr[left.length+k];
		}
		long leftInv = mergeAndCountInv(left);
		long rightInv = mergeAndCountInv(right);
		long mergeInv = merge(left, right, arr);
		return leftInv+rightInv+mergeInv;
	}
	void solve(InputReader in, OutputWriter out){
		final int n = in.readInt();
		final int[] arr = new int[n];
		for(int i = 0;i < n; i++){
			arr[i] = in.readInt();
		}
		long count = mergeAndCountInv(arr);
		out.printLine(count);
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

