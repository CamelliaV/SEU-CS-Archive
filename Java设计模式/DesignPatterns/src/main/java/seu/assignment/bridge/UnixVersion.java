package seu.assignment.bridge;

/**
 * @ClassName: UnixVersion
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:04:23
 * @Input:
 * @Output:
 */
class UnixVersion extends OperatingSystemVersion {
	@Override
	public void play(String filename) {
		this.videoFile.decode("Unix", filename);

	}
}