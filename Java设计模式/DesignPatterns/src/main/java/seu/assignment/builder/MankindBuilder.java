package seu.assignment.builder;

/**
 * @ClassName: MankindBuilder
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:52:01
 * @Input:
 * @Output:
 */
class MankindBuilder extends AbstractCharacterBuilder {
	@Override
	protected void buildGender() {
		this.character.setGender("Female(Mankind)");
	}

	@Override
	protected void buildFace() {
		this.character.setFace("Expressionless(Mankind)");
	}

	@Override
	protected void buildSuit() {
		this.character.setSuit("Monarch(Mankind)");
	}

	@Override
	protected void buildHairstyle() {
		this.character.setHairstyle("CurlyHair(Mankind)");
	}
}