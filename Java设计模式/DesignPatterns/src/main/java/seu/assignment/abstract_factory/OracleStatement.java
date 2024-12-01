package seu.assignment.abstract_factory;

/**
 * @ClassName: OracleStatement
 * @Description: java类描述
 * @Author: 11609
 * @Date: 2022/11/10 16:33:24
 * @Input:
 * @Output:
 */
class OracleStatement implements Statement {
	@Override
	public void execute() {
		System.out.println("-------------Oracle Executed!");
	}
}