
import java.io.*;
import java.util.*;


class SecondImmutable {
	public static void main(String[] args){
		InputReader in = new InputReader(System.in);
		OutputWriter out = new OutputWriter(System.out);
		//Scanner s = new Scanner(System.in);
		int n = in.readInt();
		int[] friendId = new int[n];
		HashMap<Integer, Boolean> map = new HashMap<>();
		for(int i = 0;i < n; i++){
			friendId[i] = in.readInt();
			int ff = in.readInt();
			for(int j =1;j <= ff; j++){
				int fid = in.readInt();
				map.put(fid, true);
			}
		}
		for(int i = 0;i < n; i++){
			if(map.containsKey(friendId[i])){
				map.put(friendId[i], false);
			}
		}
		int count = 0;
		Set<Integer> set = map.keySet();
		Iterator<Integer> itr = set.iterator();
		for(int i= 0;i < map.size(); i++){
			if(map.get(itr.next())==true)
				count++;
		}
		out.printLine(count);
		out.flush();
		out.close();
	}
}
class InputReader
{
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

class OutputWriter
{
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