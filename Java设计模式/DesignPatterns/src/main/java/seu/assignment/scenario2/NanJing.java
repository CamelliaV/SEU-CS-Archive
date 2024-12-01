package seu.assignment.scenario2;

class NanJing implements Hotline {
	@Override
	public void negotiate(Participant a, Participant b) {
		System.out.println("------------NanJing: communicating");
		a.act();
		b.act();
	}
}