package nt222gp_assign4.polygons;

public class RegularPolygonMain {
	public static void main(String[] args) {
		// Create an instance of each class
		EquilateralTriangle tri = new EquilateralTriangle(2);
		Square sq = new Square(4);
		
		// Use the getNumSides methods (abstract methods)
		System.out.println("The triangle has " + tri.getNumSides() + " sides.");
		System.out.println("The square has " + sq.getNumSides() + " sides.");
		
		// Use the getSideLength methods (abstract methods)
		System.out.println("The side-length of the triangle is: " + tri.getSideLength());
		System.out.println("The side-length of the square is: " + sq.getSideLength());
		
		// Use the getPerimeter and InteriorAngle methods (default methods)
		System.out.println("The perimeter of the triangle is: " + tri.getPerimeter());
		System.out.println("The interior angle of the trianlge is: " + tri.InteriorAngle());
		
		// Create an array of the objects and try the static method, totalSides.
		RegularPolygon[] arr = new RegularPolygon[] { tri, sq };
		System.out.println("The total sides of the array is: " + RegularPolygon.totalSides(arr));
			
	}
}
