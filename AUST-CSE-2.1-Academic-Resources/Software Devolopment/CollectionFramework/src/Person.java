
public class Person implements Comparable<Person> {
	private String name;
	private int age;
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	Person(String name, int age){
		this.name=name;
		this.age=age;
	}
	
	public String toString(){
		return name+", "+age;
	}

	@Override
	public int compareTo(Person o) {
		// TODO Auto-generated method stub
		//return name.compareTo(o.name);
		int len1 = name.length();
		int len2 = o.name.length();
		
		if(len1>len2){
			return 1;
		}else if(len1<len2){
			return -1;
		}else{
			return 0;
		}
	}

}
