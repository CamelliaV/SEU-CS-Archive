package seu.assignment.simple_factory;

/**
 * @ClassName: Woman
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 21:08:43
 * @Input:
 * @Output:
 */
class Woman implements Person {

	private final PersonState state = new PersonState();

	public Woman(String name) {
		state.setName(name);
		state.setIdentity("Woman");
	}

	@Override
	public void stateMe() {
		state.stateMe();
	}
}