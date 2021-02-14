public class Robot 
{    
    public void start()
    {
        System.Console.Write("\n\n\tRobot started\n");
    }
    
    public virtual void work() 
    {
        System.Console.Write("\t\tAwaiting instructions\n");
    }
    
    public void stop() 
    {
        System.Console.Write("\tRobot stopped\n");
    }    
}