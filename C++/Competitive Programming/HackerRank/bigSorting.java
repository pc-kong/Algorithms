import java.math.BigInteger;
import java.util.*;
import java.*;

class migue implements Comparator<String> {
    public int compare(String x, String y) {
        if (x.length() == y.length()) {
            return x.compareTo(y);
        }

        return x.length() - y.length();
    }
}

public class bigSorting {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String entrada = "";
		int n = 0;
		n = sc.nextInt();
		String[] numeros = new String[n];
		for(int i = 0; i < n; i++){
			entrada = sc.next();
			numeros[i] = entrada;
		}
		Arrays.sort(numeros, new migue());
		for(int i = 0; i < n; i ++){
			System.out.println(numeros[i]);
		}

	}
}