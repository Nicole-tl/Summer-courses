package nt222gp_assign4.polygons;

public interface RegularPolygon {
	// Abstract methods
	int getNumSides(); 		// getNumSides returns number of sides for a regular polygon
	
	int getSideLength();	// getSideLength returns length of a side in a regular polygon
	
	// Default methods
	// getPerimeter returns perimeter of a regular polygon.
	public default int getPerimeter() {
		return getNumSides() * getSideLength();
	}
	
	// getInteriorAngle that returns measure of the interior angle of a regular polygon in degrees.
	public default int InteriorAngle() {
		return (getNumSides()-2)*180;
	}
	
	// Static methods
	// totalSides returns a sum of the number of sides of all the RegularPolygons passed as an array.
	public static int totalSides(RegularPolygon[] arr) {
		int sum = 0;
		for (int i = 0; i<= arr.length-1; i++) {
			sum = sum + arr[i].getNumSides();
		}
		return sum;	
	}
	
}
