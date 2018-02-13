public class vector {

	int x;
	int y;

	public vector(int x, int y){
		this.x = x;
		this.y = y;
	}

	public vector getVector(point a, point b) {
		return new vector(a.x-b.x, a.y-b.y);
	}

	public int cross_product(vector a, vector b) {
	return (a.x*b.y)-(a.y*b.x);
	}

	public boolean isInTriangle(point a, point b, point c, point p) {
		vector ab = getVector(b,a);
		vector bc = getVector(c,b);
		vector ca = getVector(a,c);
		vector ap = getVector(p,a);
		vector bp = getVector(p,b);
		vector cp = getVector(p,c);
		return ((cross_product(ab, ap) > 0) && (cross_product(bc, bp) > 0) && (cross_product(ca, cp) > 0)) || 
				((cross_product(ab, ap) < 0) && (cross_product(bc, bp) < 0) && (cross_product(ca, cp) < 0));
	
	}
}
