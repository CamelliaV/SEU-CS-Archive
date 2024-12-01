package seu.assignment.state;

/**
 * @ClassName: Professional
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 15:34:33
 * @Input:
 * @Output:
 */
class Professional implements Level {
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
		System.out.println("---------------!!!!Not Allowed");
	}
}