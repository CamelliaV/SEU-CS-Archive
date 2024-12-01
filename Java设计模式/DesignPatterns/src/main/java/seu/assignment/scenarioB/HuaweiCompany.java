package seu.assignment.scenarioB;

import java.util.Map;
import java.util.Objects;
import java.util.Random;

/**
 * @ClassName: HuaweiCompany
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:09:55
 * @Input:
 * @Output:
 */
abstract class HuaweiCompany implements Company {
	Map<String, Memento> pool;
	InterviewState interview;

	public Offer recruit(Candidate candidate) {
		Offer offer = null;
		if (candidate == null) {
			return null;
		}
		if (isInPool(candidate.getId())) {
			return pool.get(candidate.getId()).getState();
		}
		if (Objects.equals(candidate.getCapacity(), "student")) {
			return studentChannel(candidate);
		}
		if (Objects.equals(candidate.getCapacity(), "senior")) {
			offer = new Offer("Huawei Company", "senior", "SSP");
			addToPool(candidate.getId(), new Memento(offer));
			return offer;
		}
		else {
			String result = judgeRank(candidate);
			if (Objects.equals(result, "excellent")) {
				offer = new Offer("Huawei Company", "junior", "SP");
			} else if (Objects.equals(result, "pass")) {
				offer = new Offer("Huawei Company", "beginner", "NR");
			} else { // not competent for the job
			}
			return offer;
		}
	}

	private boolean isInPool(String id) {
		return pool.containsKey(id);
	}

	private void addToPool(String id, Memento memento) {
		pool.put(id, memento);
	}

	protected abstract String judgeRank(Candidate candidate);
	private Offer studentChannel(Candidate candidate) {
		if (!Objects.equals(candidate.getCapacity(), "student")) {
			return null;
		}
		Random r = new Random();
		int result = r.nextInt() % 5;
		InterviewState state = this.interview.continueProcess(result);
		if (state.getStage() == 4) {
			return new Offer("Huawei Company", "beginner", "SSP");
		} else if (state.getStage() == 3) {
			return new Offer("Huawei Company", "beginner", "SP");
		} else {
			return null;
		}
	}
}