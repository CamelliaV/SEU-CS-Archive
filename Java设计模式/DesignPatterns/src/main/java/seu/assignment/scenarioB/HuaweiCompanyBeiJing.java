package seu.assignment.scenarioB;

import java.util.Objects;

/**
 * @ClassName: HuaweiCompanyBeiJing
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:12:32
 * @Input:
 * @Output:
 */
class HuaweiCompanyBeiJing extends HuaweiCompany {
	public HuaweiCompanyBeiJing() {
		this.interview = new FirstInterview();
	}
	@Override
	protected String judgeRank(Candidate candidate) {
		if (Objects.equals(candidate.getCapacity(), "junior")) {
			return "pass";
		} else {
			return "dismissed";
		}
	}
}