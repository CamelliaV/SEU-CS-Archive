package seu.assignment.scenario2;

class SuNing {

	private Hotline hotlineA = new NanJing();
	private Hotline hotlineB = new ShangHai();

	public void contactNanJing(Participant a, Participant b) {
		hotlineA.negotiate(a, b);
	}

	public void contactShangHai(Participant a, Participant b) {
		hotlineB.negotiate(a, b);
	}
}