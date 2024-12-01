package seu.assignment.scenario2;

class ShangHai implements Hotline {
	@Override
	public void negotiate(Participant a, Participant b) {
		System.out.println("------------ShangHai: communicating");
		a.act();
		b.act();
	}
}