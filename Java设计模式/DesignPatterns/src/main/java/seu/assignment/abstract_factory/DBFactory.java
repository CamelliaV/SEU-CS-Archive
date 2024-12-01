package seu.assignment.abstract_factory;

public interface DBFactory {
	Connection createConnection();
	Statement createStatement();
}
