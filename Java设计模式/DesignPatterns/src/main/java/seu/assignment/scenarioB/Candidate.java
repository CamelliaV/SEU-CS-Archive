package seu.assignment.scenarioB;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.RequiredArgsConstructor;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName: Candidate
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:08:43
 * @Input:
 * @Output:
 */
@Data
class Candidate {
	private String capacity; // same with rank + student
	private String identity;
	private String id;
	private List<Offer> offerList;

	public Candidate(String capacity, String identity, String id, List<Offer> offerList) {
		this.capacity = capacity;
		this.identity = identity;
		this.id = id;
		this.offerList = offerList == null ? new ArrayList<Offer>() : offerList;
	}

	public Candidate(Candidate candidate, String capacity) {
		this.identity = candidate.identity;
		this.id = candidate.id;
		this.offerList = candidate.offerList == null ? new ArrayList<Offer>() : candidate.offerList;
		this.capacity = capacity;
	}

	public void applyForJob(Company company) {
		company.recruit(this);
	}

}