package seu.assignment.memento;

import java.util.ArrayList;

/**
 * @ClassName: GameManager
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 15:17:59
 * @Input:
 * @Output:
 */
class GameManager {
   private static ArrayList<Player.SavePoint> savePoint = new ArrayList<>();

   public static void main(String[] args) {
      Player player = new Player();
      player.setSceneState("Level1");
      player.setSceneState("Level2");
      savePoint.add(player.saveSceneState());
      player.setSceneState("Level3");
      player.restoreSceneState(savePoint.get(0));
      player.setSceneState("Level3");
      player.setSceneState("Level4");
      savePoint.add(player.saveSceneState());
      player.setSceneState("Level5");
      player.restoreSceneState(savePoint.get(1));

   }
}