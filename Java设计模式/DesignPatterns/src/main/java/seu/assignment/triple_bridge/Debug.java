package seu.assignment.triple_bridge;

/**
 * @ClassName: Debug
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:56:16
 * @Input:
 * @Output:
 */
class Debug extends Logger {
	@Override
	public void log(String message) {
		System.out.println("Debug: ------------------------");
		System.out.println("Message: -> " + message);
		language.code();
		os.systemCalls();
		System.out.println("------------------------------");
		System.out.println();
	}
}