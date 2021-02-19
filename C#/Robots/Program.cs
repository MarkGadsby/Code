using System;

namespace TestStart
{
    class Program
    {
        static void Main(string[] args)
        {
            Robot[] myRobots = new Robot[8];
        
            myRobots[0] = new WasteDisposalRobot();
            myRobots[1] = new HealthCareRobot();
            myRobots[2] = new EntertainmentRobot();
            myRobots[3] = new Robot();
            myRobots[4] = new Robot();
            myRobots[5] = new Robot();
            myRobots[6] = new HealthCareRobot();
            myRobots[7] = new WasteDisposalRobot();
            
            for (int i = 0; i < myRobots.Length; i++)            
            {
                myRobots[i].start();
                myRobots[i].work();
                myRobots[i].stop();
            }       
        }
    }
}