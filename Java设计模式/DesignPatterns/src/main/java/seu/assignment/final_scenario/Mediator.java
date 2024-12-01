package seu.assignment.final_scenario;

public interface Mediator {

   void setCustomer(Colleague colleague);
   void setMall(Colleague colleague);
   void handleRequest(String message, Colleague colleague);
}