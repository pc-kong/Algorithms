import java.util.*;

public class isInTriangle{
	
	public static void main(String[] args) {
		point a = new point(0,0);
		point b = new point(4,0);
		point c = new point(2,2);
		point p = new point(2,3);
		vector v = new vector(0,0);
		System.out.println(v.isInTriangle(a,b,c,p));
	}
}
