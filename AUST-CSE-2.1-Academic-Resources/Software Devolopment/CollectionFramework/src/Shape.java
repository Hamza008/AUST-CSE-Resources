
public class Shape {
	private String name, color;
	private int height, width, radius;
	
	public Shape(String name, String color, int height, int width, int radius) {
		this.name = name;
		this.color = color;
		this.height = height;
		this.width = width;
		this.radius = radius;
	}
	
	public String getName() {
		return name;
	}
	public String getColor() {
		return color;
	}
	public int getHeight() {
		return height;
	}
	public int getWidth() {
		return width;
	}
	public int getRadius() {
		return radius;
	}

	@Override
	public String toString() {
		return "Shape [name=" + name + ", color=" + color + ", height="
				+ height + ", width=" + width + ", radius=" + radius + "]";
	}
	
	
	
}
