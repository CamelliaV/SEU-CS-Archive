package seu.assignment.simple_factory;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * @ClassName: Nuwa
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 21:08:32
 * @Input:
 * @Output:
 */
class Nuwa {
	private static final Nuwa instance = new Nuwa();

	public Person create(String code, String name) {
		Person person = null;
		if (Objects.equals(code, "M")) {
			System.out.println("---------------Create Man: " + name);
			person = new Man(name);
		} else if (Objects.equals(code, "W")) {
			System.out.println("---------------Create Woman: " + name);
			person = new Woman(name);
		} else if (Objects.equals(code, "R")) {
			System.out.println("---------------Create Robot: " + name);
			person = new Robot(name);
		} else {
			System.out.println("----- Error Create!!! -----");
		}
		return person;
	}

	public static Nuwa getInstance() {
		return instance;
	}

	public static void main(String[] args) {
		Nuwa nuwa = Nuwa.getInstance();
		List<Person> people = new ArrayList<>();
		people.add(nuwa.create("M", "William"));
		people.add(nuwa.create("W", "Cayena"));
		people.add(nuwa.create("W", "Camelia"));
		people.add(nuwa.create("R", "Atori"));
		people.forEach(Person::stateMe);
	}
}