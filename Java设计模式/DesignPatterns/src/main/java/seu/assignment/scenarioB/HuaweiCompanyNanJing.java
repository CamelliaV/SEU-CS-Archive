package seu.assignment.scenarioB;

import java.util.Objects;

/**
 * @ClassName: HuaweiCompanyNanJing
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:12:45
 * @Input:
 * @Output:
 */
class HuaweiCompanyNanJing extends HuaweiCompany {
	public HuaweiCompanyNanJing() {
		this.interview = new FirstInterview();
	}
	@Override
	protected String judgeRank(Candidate candidate) {
		if (Objects.equals(candidate.getCapacity(), "junior")) {
			return "excellent";
		} else if (Objects.equals(candidate.getCapacity(), "beginner")) {
			return "pass";
		} else {
			return "dismissed";
		}
	}
}