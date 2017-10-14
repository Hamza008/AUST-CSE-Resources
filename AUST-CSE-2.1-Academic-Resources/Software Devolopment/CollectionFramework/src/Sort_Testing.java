import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


public class Sort_Testing {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		List<Shape> list = new ArrayList<Shape>();
		
		addElements(list);
		showElements(list);
		System.out.println();
		
		Collections.sort(list, new Comparator<Shape>(){
			public int compare(Shape o1, Shape o2) {
				if(o1.getHeight() > o2.getHeight()){
					return 1;
				}else if(o1.getHeight() < o2.getHeight()){
					return -1;
				}
				return 0;
			}
		});	
		showElements(list);
		System.out.println();
		
		Collections.sort(list, new Comparator<Shape>(){
			public int compare(Shape o1, Shape o2) {
				return o1.getName().compareTo(o2.getName());
			}
		});	
		showElements(list);
	}
	
	private static void addElements(Collection<Shape> col){
		col.add(new Shape("Triangle", "Blue", 19, 20, 4));
		col.add(new Shape("Rectangle", "Red", 15, 40, 2));
		col.add(new Shape("Square", "Yellow", 19, 34, 5));
		col.add(new Shape("Oval", "White", 34, 74, 5));
		col.add(new Shape("Square", "Green", 14, 77, 2));
		col.add(new Shape("Circle", "Purple", 35, 46, 1));
	}
	
	private static void showElements(Collection<Shape> col){
		for (Shape e : col){
			System.out.println(e);
		}
	}

}
