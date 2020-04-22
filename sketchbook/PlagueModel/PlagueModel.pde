int nPeople = 400;

enum HealthStatus
{
  UNEXPOSED,
  INFECTED,
  ACQUIRED_IMMUNITY,
  DEAD
}

static class stats
{
  static int NoUnexposed = 400;
  static int NoInfected = 0;
  static int NoImmune = 0;
  static int NoDead = 0;
}

Person[] people = new Person[nPeople];
DataDisplay dataDisplay = new DataDisplay();   

void setup()
{
  size(1280, 720);
  noStroke();

  for (int i = 0; i < nPeople; i++)
    people[i] = new Person((int)random(width), (int)random(height), (int)random(-5,5), (int)random(-5,5), HealthStatus.UNEXPOSED);

  people[13].status = HealthStatus.INFECTED;
}

void draw()
{
  background(32);

  // clear stats
  stats.NoUnexposed = 0;
  stats.NoInfected = 0;
  stats.NoImmune = 0;
  stats.NoDead = 0;

  for (Person p : people)
  {
    p.updateStatus();
    p.move();
    p.collide();
    p.display();
    
    // collate stats
    switch (p.status)
    {
      case UNEXPOSED:
        stats.NoUnexposed++;
      break;
      case INFECTED:
        stats.NoInfected++;
      break;
      case ACQUIRED_IMMUNITY:
        stats.NoImmune++;
      break;
      case DEAD:
        stats.NoDead++;
      break;
    }
  }
  PrintStatisitcs();
  dataDisplay.PlotPoints();
  dataDisplay.DrawGraph();
}

void PrintStatisitcs()
{
  fill(0,0,0,200);
  rect(10, 10, 300, 170);
  textSize(24);

  textAlign(LEFT);
  fill(10, 165, 242);
  text("Total susceptible:", 20,  40);
  fill(242,37,10);
  text("Total infected:", 20,  70);
  fill(110,242,10);
  text("Total immune:", 20, 100);
  fill(220,242,236);
  text("Total deceased:", 20, 130);
  fill(220,242,236);
  text("Sample size:", 20, 170);

  textAlign(RIGHT);
  text(stats.NoUnexposed, 300,  40);
  text(stats.NoInfected, 300,  70);
  text(stats.NoImmune, 300, 100);
  text(stats.NoDead, 300, 130);
  text(nPeople, 300, 170);
}

class Person
{  
  private int xPos;    
  private int yPos;    
  private int xVec;    
  private int yVec;    
  private HealthStatus status;
  private int millisecondInfected; 
  
  public Person(int xPosInit, int yPosInit, int xVector, int yVector, HealthStatus statusInit)
  {
    xPos = xPosInit;    
    yPos = yPosInit;    
    xVec = xVector;    
    yVec = yVector;  
    status = statusInit;
    millisecondInfected = 0;
  }

  void move()
  {
    if (xPos < 0 || xPos > width) 
      xVec *= -1;        

    if (yPos < 0 || yPos > height)
      yVec *= -1;        

    if (status != HealthStatus.DEAD)
    {
      xPos += xVec;
      yPos += yVec;
    }
  }
  
  void display()
  {
    switch (status)
    {
      case UNEXPOSED:
      fill(10, 165, 242);
        break;
      case INFECTED:
        fill(242,37,10);
        break;
      case ACQUIRED_IMMUNITY:
        fill(110,242,10);
        break;
      case DEAD:
        fill(220,242,236);
        break;
    }
    ellipse(xPos, yPos, 5, 20);
  }

  void collide()
  {
    int dx = 0;
    int dy = 0;
    
    int distanceSquared = 0;
    
    for (Person p : people)
    {
      dx = xPos - p.xPos;   
      dy = yPos - p.yPos;
      distanceSquared = dx * dx + dy * dy;
      
      if (distanceSquared < 20)
      {
        if (status == HealthStatus.INFECTED && p.status == HealthStatus.UNEXPOSED)
        {
          p.status = HealthStatus.INFECTED;
          p.millisecondInfected = millis();
        }
        else if (status == HealthStatus.UNEXPOSED && p.status == HealthStatus.INFECTED)
        {
          status = HealthStatus.INFECTED;
          millisecondInfected = millis();
        }
      }
    }
  }

  void updateStatus()
  {
    if (millis() - millisecondInfected > 5000 && status == HealthStatus.INFECTED)
    {
       if ((int)random(1000) < 6)
         status = HealthStatus.DEAD;  
       else 
         status = HealthStatus.ACQUIRED_IMMUNITY;
    }
  }
}

class DataDisplay
{
  private int x;
  private int datapoint;
  private float[] xlist;
  private float[] Unexposed;
  private float[] Infected;
  private float[] Immune;
  private float[] Dead;

  DataDisplay()
  {
    x = 10;
    datapoint = 0;
    xlist = new float[991];
    Unexposed = new float[991];
    Infected = new float[991];
    Immune = new float[991];
    Dead = new float[991];
  }

  void PlotPoints()
  {
    float fx = map(x++, 10, 1000, 10, 300);
    
    if (fx <= 300)
    {
      xlist[datapoint] = fx;   
      Unexposed[datapoint] = map(stats.NoUnexposed, 0, 400, 310, 200);
      Infected[datapoint] = map(stats.NoInfected, 0, 400, 310, 200);
      Immune[datapoint] = map(stats.NoImmune, 0, 400, 310, 200);
      Dead[datapoint] = map(stats.NoDead, 0, 400, 310, 200);    
  
      datapoint++;
    }
  }

  void DrawGraph()
  {
    fill(0,0,0,200);
    rect(10, 190, 300, 135);
    
    strokeWeight(2);
  
    for (int i = 0; i < datapoint; i++)
    {      
      stroke(10, 165, 242);
      point(xlist[i], Unexposed[i]);
    
      stroke(242,37,10);
      point(xlist[i], Infected[i]);
  
      stroke(110,242,10);
      point(xlist[i], Immune[i]);

      stroke(220,242,236);
      point(xlist[i], Dead[i]);
    }
    noStroke();
  }
}
