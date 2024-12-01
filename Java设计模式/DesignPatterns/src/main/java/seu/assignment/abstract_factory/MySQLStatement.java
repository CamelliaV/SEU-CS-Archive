package seu.assignment.abstract_factory;

/**
 * @ClassName: MySQLStatement
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:33:36
 * @Input:
 * @Output:
 */
class MySQLStatement implements Statement {
	@Override
	public void execute() {
		System.out.println("-------------MySQL Execution!");
	}
}