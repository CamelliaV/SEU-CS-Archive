package seu.assignment.template;

import java.util.HashMap;
import java.util.Random;

/**
 * @ClassName: DataBase
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/4 17:15:18
 * @Input:
 * @Output:
 */
class DataBase {
	private static final HashMap<String, AbstractAccount> users = new HashMap<>();
	public static String register(String type, Double balance) {
		String account = "";
		Random random = new Random();
		for (int i = 0; i < 9; i++) {
			account += random.nextInt(10);
		}
		if (type == "SavingAccount") {
			System.out.println("----------------Create SavingAccount");
			users.put(account, new SavingAccount(type, balance));
		} else if (type == "CurrentAccount") {
			System.out.println("----------------Create CurrentAccount");
			users.put(account, new CurrentAccount(type, balance));
		}
		else {
			System.out.println("-----------------Error registering");
			return null;
		}

		return account;
	}
	public static void showInfo(String account) {
		AbstractAccount user = users.get(account);
		if (user == null) {
			System.out.println("----------------No such user");
			return;
		}
		System.out.println("----------------User Info: ----------------");
		System.out.println("----------------Type: " + user.getType());
		System.out.println("----------------Type: " + user.getBalance());
		System.out.println("----------------Type: " + user.countSum());
		System.out.println("----------------End Info: ----------------");
		System.out.println();
	}

	public static void main(String[] args) {
		final String savingAccount = "SavingAccount";
		final String currentAccount = "CurrentAccount";
		String accountSaving = DataBase.register(savingAccount, 1000.0);
		String accountCurrent = DataBase.register(currentAccount, 1000.0);
		DataBase.showInfo(accountSaving);
		DataBase.showInfo(accountCurrent);
	}
}