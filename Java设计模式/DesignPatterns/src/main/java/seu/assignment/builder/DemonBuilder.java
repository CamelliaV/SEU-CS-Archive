package seu.assignment.builder;

/**
 * @ClassName: DemonBuilder
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:51:53
 * @Input:
 * @Output:
 */
class DemonBuilder extends AbstractCharacterBuilder {
	@Override
	protected void buildGender() {
		this.character.setGender("Male(Demon)");
	}

	@Override
	protected void buildFace() {
		this.character.setFace("Furious(Demon)");
	}

	@Override
	protected void buildSuit() {
		this.character.setSuit("Dominator(Demon)");
	}

	@Override
	protected void buildHairstyle() {
		this.character.setHairstyle("ShortHair(Demon)");
	}
}