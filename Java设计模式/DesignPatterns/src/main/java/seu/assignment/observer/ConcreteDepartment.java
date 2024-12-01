package seu.assignment.observer;

/**
 * @ClassName: ConcreteDepartment
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 22:00:15
 * @Input:
 * @Output:
 */
class ConcreteDepartment extends Department {
	private String departmentName;


	@Override
	public void changeName(String name) {
		if (name.equals(departmentName)) {
			return;
		}
		this.departmentName = name;
		observers.forEach(item -> item.respond(departmentName));
	}
}