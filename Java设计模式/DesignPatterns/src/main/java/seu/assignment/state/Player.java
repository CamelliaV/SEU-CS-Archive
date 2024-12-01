package seu.assignment.state;

/**
 * @ClassName: Player
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/8 15:33:52
 * @Input:
 * @Output:
 */
class Player implements Level {

	private Level level = new Primary();

	private Integer score = 0;

	private Boolean isDouble = false;

	public void update() {
		if (score == 0) {
			level = new Primary();
		} else if (score == 1) {
			level = new Secondary();
		} else if (score == 2) {
			level = new Professional();
		} else if (score == 3) {
			level = new Final();
		} else {
			level = new Final();
		}
	}

	public void win() {
		System.out.println("---------------Game Win");
		if (isDouble) {
			score += 2;
			isDouble = false;
			update();
			return;
		}
		score += 1;
		update();
	}

	public void lose() {
		System.out.println("---------------Game Lose");
		isDouble = false;
		score = score > 0 ? score - 1 : 0;
		update();
	}

	@Override
	public void play() {
		level.play();
	}

	@Override
	public boolean doubleScore() {
		if (level.doubleScore()) {
			isDouble = true;
		}
		return isDouble;
	}

	@Override
	public void changeCards() {
		level.changeCards();
	}

	@Override
	public void peekCards() {
		level.peekCards();
	}

	public static void main(String[] args) {
		Player player = new Player();

		// ------- for primary -------

		player.play();
		player.doubleScore();
		player.changeCards();
		player.peekCards();

		player.win();

		// ------- for secondary -------


		player.play();
		player.doubleScore();
		player.changeCards();
		player.peekCards();

		player.win();

		// ------- for final -------

		player.play();
		player.doubleScore();
		player.changeCards();
		player.peekCards();

		player.lose();

		// ------- for professional -------

		player.play();
		player.doubleScore();
		player.changeCards();
		player.peekCards();

		player.lose();
	}
}