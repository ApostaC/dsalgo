import java.util.Scanner;
import java.math.BigInteger;

public class xuelietongji{
	public static BigInteger fac(int n)
	{
		if(n<=1) return BigInteger(1);
		else return fac(n-1).multiply(BigInteger(n));
	}
	public static BigInteger pailie(int m,int n)
	{
		BigInteger nn=fac(n);
		BigInteger mm=fac(m);
		BigInteger nm=fac(n-m);
		BigInteger mu=mm.multiply(nm);
		return nn.divide(mu);
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
	}
}
