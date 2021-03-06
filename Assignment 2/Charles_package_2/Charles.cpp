#include "Robot.h"
/*
	Karel is a framework for manipulating with Karel the robot.
	Karel is a subclass of ROBOT from the library Robot.
	Last Modified:	September 16 2006, by Pieter Koopman, RU Nijmegen
	With some additions: September 12 2007, by Ger Paulussen & Peter Achten
	More additions: August 21 2013, by Peter Achten
*/


// =========================================================================

// make_church creates a Church-like shape of walls
void make_church ()
{
    const int lane   = 2 + rand () % (WereldHoogte / 5) ;
    const int street = 2 + rand () % (WereldBreedte / 5) ;
    const int width  = 3 + rand () % (WereldBreedte / 2) ;
    const int height = 2 + rand () % (WereldHoogte / 3) ;
    place_rectangle (street,lane,width,height) ;
    place_rectangle (street + 2,lane + height, 2 + width / 3, 2 + height / 3) ;
    place_walls (street + 3 + width / 6,lane + height + height / 3 + 3,4,false) ;
    place_walls (street + 2 + width / 6,lane + height + height / 3 + 5,2,true) ;
    create_ball (street, WereldHoogte - 2) ;
}


// here starts the part with code to be completed by the students

// Name / student number / study student 1 :
// Name / student number / study student 2 :

// give one or more comment lines about what will happen in this function
void follow_path ()
{
    // give your own code completion
}

// give one or more comment lines about what will happen in this function
void hansl_and_gretl ()
{
	make_path_with_balls() ;
	follow_path () ;
}

// give one or more comment lines about what will happen in this function
// note that you are allowed to add formal parameters to fill_cave_with_balls if that is necessary for your solution
void fill_cave_with_balls ()
{
    // give your own code completion
}

// give one or more comment lines about what will happen in this function
void cave ()
{
	// if necessary for your solution, you are allowed to give actual parameters to fill_cave_with_balls
	fill_cave_with_balls () ;
	fill_cave_with_balls () ;
}

// give one or more comment lines about what will happen in this function
void start_cave ()
{
    make_cave () ;
    cave () ;
}

// give one or more comment lines about what will happen in this function
void rondje_om_de_kerk ()
{
    make_church () ;
    // give your own code completion

}

// For testing purposes, you can define your own function here:

/*
SITUATIES

- in_front_of_wall
    -on_ball
    -north?

*/

void test ()
{
    while (!in_front_of_wall())
    {
        step();
        turn_right();

    while (!in_front_of_wall())
    {
        put_ball();
        step();
    }
    if (in_front_of_wall())
    {
        put_ball();
        turn_left();
        turn_left();

        while (!in_front_of_wall())
        {
            step();
        }
        if (in_front_of_wall()){
            turn_right();
            return test();
        }
    }

    }
}
void begin()
{
  step();
  turn_right();
}
void putitdown()
{
  put_ball();
  step();
}

void ass_2()
{
  if (!in_front_of_wall())
  {
    put_ball();
    ass_2();
  }

  if (in_front_of_wall())
  {
    put_ball();
    turn_left();
    step();
    if (!on_ball())
    {
      turn_left();
      putitdown();
    }
    if (on_ball())
    {
      turn_left();
      turn_left();
      step();
      step();
      turn_right();
      putitdown();
    }
  }
}
void mainfunction()
{
  begin();
  ass_2();
}
void Hansel1()
{
  // niet voor een muur
  if (!in_front_of_wall())
  {
    //en op een bal
    if (on_ball())
    {
      //loop naar voren en check opnieuw
      step();
      Hansel1();
    }
    //niet op een bal
    if (!on_ball())
    {
      //start checking2
      turn_right();
      turn_right();
      step();
      turn_left();
      step();
      if (on_ball())
      {
        Hansel1();
      }
      if (!on_ball())
      {
        turn_right();
        turn_right();
        step();
        step();
        if (!on_ball())
        {
          turn_right();
        }
        if (on_ball())
        {
          Hansel1();
        }
      }
    }
  }
  //wel voor een muur
  else
  {
    turn_left();
    Hansel1();
  }
}

}
void nieuwe_bal_zoeken ()
{
    //1e poging
    turn_left();

    if (!in_front_of_wall())
    {
        step();

        if (!on_ball())
        {
        turn_left();
        turn_left();
        step();

        }
        else
        {
            stop();
        }

    }

    else
    {
        turn_left();
        turn_left();
        step();

        if (!on_ball())
        {
        turn_left();
        turn_left();
        step();

        }
        else
        {
            stop();
        }


    }
}


void Opdracht1 ()
{
        // enter your Charles code here
    if (on_ball())
    {
        if (in_front_of_wall())
        {

            nieuwe_bal_zoeken();
            Opdracht1();
        }
        else
        {

            step();
            Opdracht1();
        }

    }

    while (!on_ball())
    {
        turn_left();
        turn_left();
        step();
        nieuwe_bal_zoeken();
        Opdracht1();
    }
}
void enter_cave()
{
  step();
  turn_right();
}
void djensen()
{
  turn_right();
  djensen();
}
void bottom_rows()
{
  //while we are not in front of a top wall (we are going up)
  while (!in_front_of_wall())
  {
    //just place a ball and keep on stepping
    put_ball();
    step();
  }
  //if we hit the top wall
  if (in_front_of_wall())
  {
    //do a 180
    put_ball();
    turn_left();

    turn_left();
    //get back the same way we came
    while (!in_front_of_wall())
    {
      step();
    }
    //check if we are at the bottom wall
    if (in_front_of_wall())
    {

      //we are at the bottom wall
      //prepare for next row
      turn_right();
      step();
      if (in_front_of_wall())
      {
        //we are there
        djensen();
      }
      else
      {
        turn_right();
        bottom_rows();
      }
      
    }
  }
}
void caveman()
{
    //while not in front of a wall
    while (!in_front_of_wall())
    {
      //place a ball and step until charles hits a wall
      put_ball();
      step();
    }
    //then if in front of the bottom wall, place final ball and head back
    if (in_front_of_wall())
    {
      //place final, do a 180
      put_ball();
      turn_left();
      turn_left();
      //go up again in the same row
      while (!in_front_of_wall())
      {
        step();
      }
      //then if we hit the top wall
      if (in_front_of_wall())
      {
        //go to the next row
        turn_right();
        step();
        //if we find a wall here, we are at the right wall
        if (in_front_of_wall())
        {
          turn_right();
          while (!in_front_of_wall())
          {
            //travel until he hits the bottom wall
            step();
          }
          if (in_front_of_wall())
          {
            //we are at the bottom wall
            turn_right();
            step();
            turn_right();
            //go through row up
            bottom_rows();
          }

        }
        turn_right();
        caveman();
      }
    }
}

void execution()
{
  enter_cave();
  caveman();
}

// end of part with code to be completed by students
// =========================================================================


void quick  () { rest(    1); };
void normal () { rest(dInit); };
void slow   () { rest(  250); };
void very_slow  () { rest( 1000); };

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    Menu charles_menu ((char*)"Charles") ;
    charles_menu.add ((char*)"Clean", reset)
                .add ((char*)"Stop",  stop) ;

	Menu a1_menu ((char*)"Assignment 2");
	a1_menu.add ((char*)"Hansl and Gretl", hansl_and_gretl )
		   .add ((char*)"Cave", start_cave )
		   .add ((char*)"Bonus: rondje om de kerk...", rondje_om_de_kerk )
	       .add ((char*)"Test a function",test)
	       .add ((char*)"Opdracht 1",Opdracht1);

	Menu sn_menu ((char*)"Velocity");
	sn_menu.add ((char*)"Quick", quick)
		   .add ((char*)"Normal",normal)
		   .add ((char*)"Slow",slow)
		   .add ((char*)"Very slow",very_slow);

	try
	{
		karelsWereld().Run (charles_menu,WINARGS(hInstance, hPrevInstance, szCmdLine, iCmdShow));
	}
	catch (IllegaleActie dezeIllegaleActie )
	{
		dezeIllegaleActie.report ();
	}
	catch (...)
	{
		makeAlert ("Something went terribly wrong!");
	}

	return 0;
}
