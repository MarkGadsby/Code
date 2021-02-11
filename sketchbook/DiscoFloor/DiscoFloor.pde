final int COLS = 6;
final int ROWS = 6;
final int COLOURSETS = 2;

int []squareOFFColours = {0xFF400000, 0xFF404000, 0xFF004000, 0xFF004040, 0xFF000040, 0xFF400040}; 
int []squareONColours = {0xFFFF0000, 0xFFFFFF00, 0xFF00FF00, 0xFF00FFFF, 0xFF0000FF, 0xFFFF00FF}; 

int [][][]discoSquares = new int[COLS][ROWS][COLOURSETS]; // Col, Row, Colour Sets

int colSetSwitch;

void setup() 
{
  size(700, 600);
  
  frameRate(2);

  for (int i = 0; i < COLS; i++)
  {
    for (int j = 0; j < ROWS; j++)
    {
      discoSquares[i][j][0] = squareOFFColours[(i + (j * COLS)) % 6]; 
      discoSquares[i][j][1] = squareONColours[(i + (j * COLS)) % 6]; 
    }
  }  
  colSetSwitch = 0;
}

void draw() 
{
  background(0xFFFFFFFF);
  colSetSwitch++;
 
  for (int i = 0; i < COLS; i++)
  {
    for (int j = 0; j < ROWS; j++)
    {
      fill(discoSquares[i][j][0]);
      rect(i*100, j*100, 100, 100, 10);       //<>//
    }
  }
  
  for (int i = 0; i < COLS; i++)
  {
    for (int j = 0; j < ROWS; j++)
    {
      if (i == colSetSwitch % 6)
      {
        fill(discoSquares[i][j][1]);
        rect(i*100, j*100, 100, 100, 10);
      }
    }
  }

}
