package seu.assignment.scenarioB;

import lombok.AllArgsConstructor;
import lombok.Data;

/**
 * @ClassName: Offer
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:08:53
 * @Input:
 * @Output:
 */
@Data
@AllArgsConstructor
class Offer {
	private String companyName;
	private String rank; // "beginner" "junior" "senior"
	private String price; // "NR" "SP" "SSP"

}