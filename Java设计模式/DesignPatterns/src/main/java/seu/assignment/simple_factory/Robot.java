package seu.assignment.simple_factory;

/**
 * @ClassName: Robot
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 21:08:50
 * @Input:
 * @Output:
 */
class Robot implements Person {

	private final PersonState state = new PersonState();

	public Robot(String name) {
		state.setName(name);
		state.setIdentity("Robot");
	}

	@Override
	public void stateMe() {
		state.stateMe();
	}
}