package seu.assignment.observer;

/**
 * @ClassName: Teacher
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 21:53:47
 * @Input:
 * @Output:
 */
class Teacher implements Consignee {
	private String name;
	private String department;

	public Teacher() {};
	public Teacher(String name) {
		this.name = name;
	}
	@Override
	public void respond(String departmentName) {
		this.department = departmentName;
		System.out.println("Teacher: " + name + " -> Department: " + department + " ! ---------");
	}
}