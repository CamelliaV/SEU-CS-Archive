package seu.assignment.builder;

/**
 * @ClassName: GameManager
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:51:37
 * @Input:
 * @Output:
 */
class GameManager {
	public static Character buildCharacter(AbstractCharacterBuilder builder) {
		return builder.synthesizeCharacter();
	}

	public static void main(String[] args) {
		Character angel = GameManager.buildCharacter(new AngelBuilder());
		Character demon = GameManager.buildCharacter(new DemonBuilder());
		Character mankind = GameManager.buildCharacter(new MankindBuilder());
		angel.showInfo();
		demon.showInfo();
		mankind.showInfo();
	}
}