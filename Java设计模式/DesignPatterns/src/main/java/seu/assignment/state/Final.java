package seu.assignment.state;

/**
 * @ClassName: Final
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 15:34:40
 * @Input:
 * @Output:
 */
class Final implements Level {
	@Override
	public void play() {
		System.out.println("---------------Play Game");
	}

	@Override
	public boolean doubleScore() {
		System.out.println("---------------Double Scores");
		return true;
	}

	@Override
	public void changeCards() {
		System.out.println("---------------Change Cards");
	}

	@Override
	public void peekCards() {
		System.out.println("---------------Peek Cards");
	}
}