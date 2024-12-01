package seu.assignment.memento;

/**
 * @ClassName: Player
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 14:52:46
 * @Input:
 * @Output:
 */
class Player {
   private String sceneState;

   public void setSceneState(String sceneState) {
      System.out.println("------------Player: Scene State Altered From: " + this.sceneState + " to " + sceneState + " -----------");
      this.sceneState = sceneState;
   }
   public void restoreSceneState(SavePoint savePoint) {
      System.out.println("------------Player: Scene State Restored From: " + this.sceneState + " to " + savePoint.getSceneState() + " -----------");
      this.sceneState = savePoint.getSceneState();
   }
   public SavePoint saveSceneState() {
      System.out.println("------------Player: Scene State Saved!-----------");
      return new SavePoint(this.sceneState);
   }
   class SavePoint {
      private final String sceneState;

      private SavePoint(String sceneState) {
         this.sceneState = sceneState;
      }

      public String getSceneState() {
         return sceneState;
      }

   }
}