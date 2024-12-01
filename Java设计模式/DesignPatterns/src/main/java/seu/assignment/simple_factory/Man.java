package seu.assignment.simple_factory;

/**
 * @ClassName: Man
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 21:08:38
 * @Input:
 * @Output:
 */
class Man implements Person {

	private final PersonState state = new PersonState();

	public Man(String name) {
		state.setName(name);
		state.setIdentity("Man");
	}

	@Override
	public void stateMe() {
		state.stateMe();
	}
}