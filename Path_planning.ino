void designLayout()
{
  //  x=0;
  //  for (int i=0;i<150;i++)
  //    layout[i][i]=0;
}

void initialize()
{
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 14; j++)
      if (i == 0 || i == 7 || j == 0 || j == 13)
        layout[i][j] = true;
      else
        layout[i][j] = false;
  x = 1;
  y = 1;
  currentDirection = 0;
}

void mainPathMovement()
{
  

}

void roomMovement(int x1,int y1, int x2, int y2)
{
//  Goto(x1,y1);

  for ( int i=x;i<
  
}



bool Goto(int x,int y)
{
  
}


void updateDirection(int degree)
{
  currentDirection += degree;
  currentDirection = (currentDirection < 0) ? currentDirection + 360 : (currentDirection >= 360) ? currentDirection % 360 : currentDirection;
  //  if (currentDirection + degree >= 0)
  //    if (currentDirection + degree < 360)
  //      currentDirection += degree;
  //    else
  //      currentDirection += degree - 360;
  //  else
  //    currentDirection =
}
