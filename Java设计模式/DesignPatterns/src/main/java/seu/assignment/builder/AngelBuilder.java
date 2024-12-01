package seu.assignment.builder;

/**
 * @ClassName: AngelBuilder
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:51:44
 * @Input:
 * @Output:
 */
class AngelBuilder extends AbstractCharacterBuilder {
	@Override
	protected void buildGender() {
		this.character.setGender("Female(Angel)");
	}

	@Override
	protected void buildFace() {
		this.character.setFace("Cute(Angel)");
	}

	@Override
	protected void buildSuit() {
		this.character.setSuit("Goddess(Angel)");
	}

	@Override
	protected void buildHairstyle() {
		this.character.setHairstyle("WavyHair(Angel)");
	}
}