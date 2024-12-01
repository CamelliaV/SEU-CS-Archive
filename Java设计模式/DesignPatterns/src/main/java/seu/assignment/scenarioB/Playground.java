package seu.assignment.scenarioB;

/**
 * @ClassName: Playground
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/12/1 17:45:33
 * @Input:
 * @Output:
 */
class Playground {
   public static void main(String[] args) {
      Company huaweiNanJing = new HuaweiCompanyNanJing();
      Company huaweiBeiJing = new HuaweiCompanyBeiJing();
      Company amazon = new AmazonCompany();
      Company google = new GoogleCompany();

      Candidate camelia = new Candidate("senior", "", "1", null);
      Candidate cayena = new Candidate("senior", "", "2", null);
      Candidate evelyn = new Candidate("junior", "", "3", null);
      Candidate eileen = new Candidate("beginner", "", "4", null);
      Candidate catherine = new Candidate("student", "", "5", null);
      Candidate diana = new Candidate("", "", "6", null);
      Candidate venus = new Candidate("", "", "7", null);
      Candidate jupiter = new Candidate("", "", "8", null);
      Candidate flora = new Candidate("", "", "9", null);
   }
}