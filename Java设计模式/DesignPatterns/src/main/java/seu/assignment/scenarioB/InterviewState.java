package seu.assignment.scenarioB;

/**
 * @ClassName: InterviewState
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/24 18:13:08
 * @Input:
 * @Output:
 */
abstract class InterviewState {
   private InterviewState state;
   private int stage; // 1 2 3 4

   // protected abstract boolean judge();
   private boolean judge(int seed) {
	   return seed >= stage;
   }
   public InterviewState continueProcess(int seed) {
	   if (this.judge(seed)) {
		   if (state == null) {
			   return this;
		   }
		   return state.continueProcess(seed);
	   }
	   return this;
   }
   public int getStage() {
	   return this.stage;
   };
}