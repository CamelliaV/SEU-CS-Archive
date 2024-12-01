package seu.assignment.bridge;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName: Client
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/10/4 20:12:27
 * @Input:
 * @Output:
 */
class Client {
	public static void main(String[] args) {
		List<VideoFile> videoList = new ArrayList<>();
		VideoFile aviFile = new AVIFile();
		VideoFile flvFile = new FLVFile();
		VideoFile mpegFile = new MPEGFile();
		VideoFile rmvbFile = new RMVBFile();
		VideoFile wmvFile = new WMVFile();

		videoList.add(aviFile);
		videoList.add(flvFile);
		videoList.add(mpegFile);
		videoList.add(rmvbFile);
		videoList.add(wmvFile);

		List<OperatingSystemVersion> osList = new ArrayList<>();
		OperatingSystemVersion linuxVersion = new LinuxVersion();
		OperatingSystemVersion macintoshVersion = new MacintoshVersion();
		OperatingSystemVersion windowsVersion = new WindowsVersion();
		OperatingSystemVersion unixVersion = new UnixVersion();

		osList.add(linuxVersion);
		osList.add(macintoshVersion);
		osList.add(windowsVersion);
		osList.add(unixVersion);

		for (OperatingSystemVersion os : osList) {
			for (VideoFile video : videoList) {
				os.setVideoFile(video);
				os.play("Camelia");
			}
		}

	}
}