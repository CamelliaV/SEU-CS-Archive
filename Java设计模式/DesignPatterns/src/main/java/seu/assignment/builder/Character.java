package seu.assignment.builder;

/**
 * @ClassName: Character
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/3 21:51:29
 * @Input:
 * @Output:
 */
class Character {
	private String gender;
	private String face;
	private String suit;
	private String hairstyle;

	public void showInfo() {
		System.out.println("------------Character info: ---------------");
		System.out.println("------------Gender: " + this.gender);
		System.out.println("------------Face: " + this.face);
		System.out.println("------------Suit: " + this.suit);
		System.out.println("------------Hairstyle: " + this.hairstyle);
		System.out.println("------------End info: ---------------");
		System.out.println();
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getFace() {
		return face;
	}

	public void setFace(String face) {
		this.face = face;
	}

	public String getSuit() {
		return suit;
	}

	public void setSuit(String suit) {
		this.suit = suit;
	}

	public String getHairstyle() {
		return hairstyle;
	}

	public void setHairstyle(String hairstyle) {
		this.hairstyle = hairstyle;
	}
}