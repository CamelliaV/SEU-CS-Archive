package seu.assignment.bridge;

/**
 * @ClassName: MacintoshVersion
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:04:33
 * @Input:
 * @Output:
 */
class MacintoshVersion extends OperatingSystemVersion {
	@Override
	public void play(String filename) {
		this.videoFile.decode("Macintosh", filename);

	}
}