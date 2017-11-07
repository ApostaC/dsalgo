import java.math.BigInteger;
import java.util.*;

public class decToBin{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		BigInteger b=new BigInteger(s);
		System.out.println(b.toString(2));	
	}
}
