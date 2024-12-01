package seu.assignment.scenarioB;

import java.util.Objects;
import java.util.Random;

public abstract class ProxyCompany implements Company {
	private HuaweiCompany huawei;
	public Offer recruit(Candidate candidate) {
		String rank = judgeRank(candidate);
		Candidate portrait = null;
		if (Objects.equals(rank, "Perfect")) {
			portrait = new Candidate(candidate, "senior");
		} else if (Objects.equals(rank, "Excellent")) {
			portrait = new Candidate(candidate, "junior");
		} else if (Objects.equals(rank, "Pass")) {
			portrait = new Candidate(candidate, "beginner");
		} else {
			return null;
		}
		return huawei.recruit(portrait);
	}

	// public abstract String judgeRank();
	public String judgeRank(Candidate candidate) {
		Random random = new Random();
		int result = random.nextInt() % 2;
		if (Objects.equals(candidate.getCapacity(), "junior")) {
			if (result == 1) {
				return "Perfect";
			} else {
				return "Excellent";
			}
		} else if (Objects.equals(candidate.getCapacity(), "beginner")){
			return "Pass";
		} else {
			return null;
		}
	}
}
